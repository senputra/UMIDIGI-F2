var express = require('express');
var router = express.Router({mergeParams: true});
var dao = require('../dao/firmwaresDao');

var devMsgs = require('../statics/developerMessages').firmwaresMsgs;

router.get('/', function(req, res, next) {
  var limit = 100;
  var offset = 0;
  if(typeof req.query.limit !== 'undefined' && !isNaN(parseInt(req.query.limit))) {
    limit = parseInt(req.query.limit);
  }
  if(typeof req.query.offset !== 'undefined' && !isNaN(parseInt(req.query.offset))) {
    offset = parseInt(req.query.offset);
  }
  dao.retrieveFirmwares(limit, offset, function(err, result) {
    if(err) {
      return next(err);
    }
    return res.status(200).send({
      "data": result.rows
    });
  });
});

router.get('/:firmwareId', function(req, res, next) {
  if(isNaN(parseInt(req.params.firmwareId)) && req.params.firmwareId !== 'latest') {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/:firmwareId']['firmwareid_nan']});
  }
  if(req.params.firmwareId === 'latest') {
    return dao.retrieveLatestFirmware(function(err, result) {
      if(err) {
        return next(err);
      }
      var responseObj = {
        'version': result.rows[0].version,
        'files': []
      };
      for(var i = 0; i < result.rows.length; i++) {
        responseObj.files[i] = {
          fileName: result.rows[i].filename,
          filePath: result.rows[i].filepath
        };
      }
      return res.status(200).send(responseObj);
    });
  }
  if(typeof req.query.filename === 'undefined') {
    return dao.retrieveSingleFirmware(req.params.firmwareId, function(err, result) {
      if(err) {
        return next(err);
      }
      if(result.rows.length === 0) {
        return next({status: 404, message:'apiMisuse', devMessage: devMsgs['get/:firmwareId']['firmwareid_notfound']});
      }
      var responseObj = {
        'version': result.rows[0].version,
        'files': []
      };
      for(var i = 0; i < result.rows.length; i++) {
        responseObj.files[i] = {
          fileName: result.rows[i].filename,
          filePath: result.rows[i].filepath
        };
      }
      return res.status(200).send(responseObj);
    });
  }
  return dao.retrieveFirmwareData(req.params.firmwareId, req.query.filename, function(err, result) {
    if(err) {
      return next(err);
    }
    if(result.rows.length === 0) {
      console.log(devMsgs);
      return next({status: 404, message:'apiMisuse', devMessage: devMsgs['get/:firmwareId']['firmwareid_filename_notfound']});
    }
    return res.status(200).send(result.rows[0].data);
  });
});

module.exports = router;
