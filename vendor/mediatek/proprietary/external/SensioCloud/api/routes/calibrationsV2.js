var express = require('express');
var router = express.Router({mergeParams: true});
var profilesDao = require('../dao/profilesDao');
var dao = require('../dao/calibrationsDao');
var async = require('async');

var devMsgs = require('../statics/developerMessages').calibrationsV2Msgs;

/* retrieve calibration values */
router.get('/', function(req, res, next) {
  if(!req.params.profileId) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/']['missing_profileId']});
  }
  dao.retrieveCalibrations(req.user.userId, req.params.profileId, function(err, result) {
    if(err) {
      return next(err);
    }
    if(result.rowCount !== 1) {
      return res.status(200).send({
        "data": []
      });
    }
    if(result.rows[0].data.length === 10) {
      migratedData = [
        result.rows[0].data[0],
        result.rows[0].data[1],
        result.rows[0].data[8],
        result.rows[0].data[9],
        0,
        0,
        result.rows[0].data[2],
        result.rows[0].data[3],
        result.rows[0].data[4],
        result.rows[0].data[5],
        result.rows[0].data[6],
        result.rows[0].data[7],
        0,0,0,0,0,0
      ];
      return res.status(200).send({
        "data": migratedData
      });
    }
    return res.status(200).send({
      "data": result.rows[0].data
    });
  });
});

router.delete('/', function(req, res, next) {
  if(!req.params.profileId) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['delete/']['missing_profileId']});
  }
  dao.deleteCalibrations(req.user.userId, req.params.profileId, function(err, result) {
    if(err) {
      return next(err);
    }
    return res.status(200).send({
      message: 'success', devMessage: devMsgs['delete/']['success']
    }).end();
  });
});

router.post('/', function(req, res, next) {
  if(!req.params.profileId) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['post/']['missing_profileId']});
  }
  if(typeof req.body.data === 'undefined' || req.body.data === null) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['post/']['missing_body']});
  }
  if(req.body.data.length !== 18) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['post/']['incorrect_body']});
  }
  for(var i = 0;i < req.body.data.length; i++) {
    if(typeof req.body.data[i] !== 'number') {
      return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['post/']['contain_NaN']});
    }
  }
  
  dao.createCalibrations(req.user.userId, req.params.profileId, req.body.data, function(err, result) {
    if(err) {
      return next(err);
    }
    return res.status(200).send({message: 'success', devMessage: devMsgs['post/']['success']}).end();
  });
});

module.exports = router;
