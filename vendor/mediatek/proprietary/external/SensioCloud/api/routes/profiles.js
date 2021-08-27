var express = require('express');
var crypto = require('crypto');
var dao = require('../dao/profilesDao');
var measurements = require('./measurements');
var calibrations = require('./calibrations');
var calibrationsV2 = require('./calibrationsV2');
var screenings = require('./screenings');
var router = express.Router();
var async = require('async');

var jwtCustomerId = require('../configs/env')().screeningCustomerId;

router.use('/:profileId/measurements', measurements);
router.use('/:profileId/calibrations', calibrations);
router.use('/:profileId/calibrationsV2', calibrationsV2);
router.use('/:profileId/screenings', screenings);

var devMsgs = require('../statics/developerMessages').profilesMsgs;

router.post('/', function(req, res, next) {
  if (typeof req.body.name === 'undefined' || req.body.name === null ||
      typeof req.body.gender === 'undefined' || req.body.gender === null ||
      typeof req.body.birthday === 'undefined' || req.body.birthday === null ||
      typeof req.body.height === 'undefined' || req.body.height === null ||
      typeof req.body.weight === 'undefined' || req.body.weight === null //  ||
//      typeof req.body.personalStatus === 'undefined' || req.body.personalStatus === null // ||
//      typeof req.body.weightunit === 'undefined' || req.body.weightunit === null
     ) {
    return next({status: 400, message: 'missingInfo', devMessage: devMsgs['post/']['missing_parameter']});
  }
  var input = req.body;
  
  if(typeof req.body.personalStatus === 'undefined' || req.body.personalStatus === null) {
    input.personalStatus = 'none';
  }

  input.gender = input.gender.toLowerCase();
  input.drug = input.personalStatus.toLowerCase();
  input.drugtime = input.takeMedicineTime;

  if(input.gender.localeCompare("male") !== 0 && input.gender.localeCompare("female") !== 0) {
    return next({status: 400, message: 'missingInfo', devMessage: devMsgs['post/']['invalid_gender']});
  }
  if(input.drug.localeCompare("none") !== 0 && input.drug.localeCompare("hypertension") !== 0 && input.drug.localeCompare("hypotension") !== 0) {
    return next({status: 400, message: 'missingInfo', devMessage: devMsgs['post/']['invalid_drug']});
  }

  var birthdaySplit = input.birthday.split('/');
  if(birthdaySplit.length !== 3 || isNaN(parseInt(birthdaySplit[0])) || isNaN(parseInt(birthdaySplit[1])) || isNaN(parseInt(birthdaySplit[2]))) {
    return next({status: 400, message: 'missingInfo', devMessage: devMsgs['post/']['invalid_bday']});
  }

  if(isNaN(parseInt(input.weight)) || isNaN(parseInt(input.height))) {
    return next({status: 400, message: 'missingInfo', devMessage: devMsgs['post/']['invalid_weight_height']});
  }

  if(req.body.weightunit) {
    if(req.body.weightunit.localeCompare('kg') !== 0 &&
       req.body.weightunit.localeCompare('jin') !== 0 &&
       req.body.weightunit.localeCompare('lb') !== 0) {
      return next({status: 400, message: 'missingInfo', devMessage: devMsgs['post/']['invalid_weight_unit']});
    }
  } else {
    input.weightunit = 'kg';
  }

  if(typeof req.body.drugtime !== 'undefined') {
    if(req.body.drugtime !== null) {
      var drugtime = parseInt(req.body.drugtime);
      if(isNaN(drugtime) || drugtime < 0 || drugtime > 23) {
        return next({status: 400, message: 'missingInfo', devMessage: devMsgs['post/']['invalid_drugtime']});
      }
    }
  }
  //DK-845 Add uniqueid by EM
  var hash = crypto.createHash('sha256');
  hash.update(jwtCustomerId + req.user.userId);
  input.uniqueid = hash.digest('base64').replace(/\//g, '_'); // slash cannot be used in filename

  dao.getProfiles(req.user.userId, function(err, result) {
    result = result.rows;
    if(err) {
      return next(err);
    }
    if(result.length > 0) {
      return res.status(400).send({message: 'apiMisuse', devMessage: devMsgs['post/']['profile_exists']});
    }
    dao.createProfile(req.user.userId, input, function(error, result) {
      if (error) {
        return next({status: 500, message: 'err', devMessage: devMsgs['post/']['create_error']});
      }
      return res.status(200).send(result).end();
    });
  });
});

router.get('/', function(req, res, next) {
  // user get all 'visible' categories in the form of an array of categories.
  dao.getProfiles(req.user.userId, function(err, result) {
    result = result.rows;
    if (err) {
      return next(err);
    }
    return res.status(200).send({"data": result}).end();
  });
});


router.get('/:profileId', function(req, res, next) {
  dao.getProfileById(req.user.userId, req.params.profileId, function(err, result) {
    if (err) {
      if (err.message === 'unauthorized') {
        return next({status: 403, message: 'unauthorized', devMessage: devMsgs['get/:profileId']['unauthorized']});
      } else {
        return next(err);
      }
    }
    if(result.rows.length === 0) {
      return next({status: 404, message: 'apiMisuse', devMessage: devMsgs['get/:profileId']['not_found']});
    }
    delete result.rows[0].birthday_date;
    return res.status(200).send(result.rows[0]).end();
  });
}); 

router.delete('/:profileId', function(req, res, next) {
  if (typeof req.params.profileId === 'undefined' || !req.params.profileId) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['delete/:profileId']['missing_pid']});   
  }
  dao.deleteProfileByProfileId(req.user.userId, req.params.profileId, function(err, result) {
    if(err) {
      return next(err);
    }
    return res.status(200).end();
  });
});

router.put('/:profileId', function(req, res, next) {
  if (typeof req.params.profileId === 'undefined' || !req.params.profileId) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['put/:profileId']['missing_pid']});
  }
  if (typeof req.body === 'undefined' || !req.body) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['put/:profileId']['no_body']});
  }
  if (req.body.gender) {
    req.body.gender = req.body.gender.toLowerCase();
    if(req.body.gender.localeCompare('male') !== 0 && req.body.gender.localeCompare('female') !== 0) {
      return next({status: 400, message: 'missingInfo', devMessage: devMsgs['put/:profileId']['invalid_gender']});
    }
  }
  if(req.body.personalStatus) {
    req.body.drug = req.body.personalStatus.toLowerCase();
    if(req.body.drug.localeCompare("none") !== 0 && 
       req.body.drug.localeCompare("hypertension") !== 0 && 
       req.body.drug.localeCompare("hypotension") !== 0) {
      return next({status: 400, message: 'missingInfo', devMessage: devMsgs['put/:profileId']['invalid_drug']});
    }
  }

  if(typeof req.body.takeMedicineTime !== 'undefined') {
    if(req.body.takeMedicineTime === null) {
      req.body.drugtime = null;
    } else {
      var drugtime = parseInt(req.body.takeMedicineTime);
      if(isNaN(drugtime) || drugtime < 0 || drugtime > 23) {
        return next({status: 400, message: 'missingInfo', devMessage: devMsgs['put/:profileId']['invalid_drugtime']});
      }
      req.body.drugtime = drugtime;
    }
  }

  async.waterfall([
    function(callback) {
      dao.getProfileById(req.user.userId, req.params.profileId, function(err, result) {
        result = result.rows;
        if(err) {
          return callback(err);
        }
        if(result.length !== 1) {
          return callback({status: 404, message: 'apiMisuse', devMessage: devMsgs['put/:profileId']['not_found']});
        }
        delete result[0].birthday_date;
        return callback(null, result[0]);
      });
    }, function(profileData, callback) {
      var input = req.body;
      dao.updateProfileById(req.user.userId, profileData, input, function(err, result) {
        if (err) {
         return callback(err);
        }
        return callback(null, result);
      });
    }], function(error, result) { 
    if (error) {
      return next(error);
    }
    return res.status(200).send(result).end();
  });
});

module.exports = router;

