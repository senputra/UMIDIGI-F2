var express = require('express');
var multer = require('multer');
var upload = multer();
var moment = require('moment');

var devMsgs = require('../statics/developerMessages').measurementsMsgs;

var router = express.Router({mergeParams: true});
var profilesDao = require('../dao/profilesDao');
var dao = require('../dao/measurementsDao');
var usersDao = require('../dao/usersDao');
var screeningsDao = require('../dao/screeningsDao');
var csnp = require('simple-statistics').cumulativeStdNormalProbability;
var async = require('async');
var utils = require('../utils/measurementsUtils');
var screeningUtil = require('../utils/screeningsUtils');

var refrenceData = {
  "4to6Male": {systolicAvg: 96.3, systolicStdev: 11.2, diastolicAvg: 57.3, diastolicStdev: 12.1},
  "7to12Male": {systolicAvg: 105.0, systolicStdev: 11.9, diastolicAvg: 65.2, diastolicStdev: 11.9},
  "13to18Male": {systolicAvg: 117.7, systolicStdev: 12.9, diastolicAvg: 69.9, diastolicStdev: 12.2},
  "19to44Male": {systolicAvg: 121.2, systolicStdev: 13.3, diastolicAvg: 78.3, diastolicStdev: 12.3},
  "45to64Male": {systolicAvg: 131.1, systolicStdev: 20.2, diastolicAvg: 84.4, diastolicStdev: 12.7},
  "65upMale": {systolicAvg: 137.8, systolicStdev: 20.2, diastolicAvg: 79.0, diastolicStdev: 12.6},
  "4to6Female": {systolicAvg: 94.0, systolicStdev: 9.9, diastolicAvg: 56.7, diastolicStdev: 10.6},
  "7to12Female": {systolicAvg: 104.8, systolicStdev: 12.1, diastolicAvg: 64.3, diastolicStdev: 11.5},
  "13to18Female": {systolicAvg: 109.6, systolicStdev: 10.6, diastolicAvg: 68.7, diastolicStdev: 11.3},
  "19to44Female": {systolicAvg: 110.7, systolicStdev: 12.9, diastolicAvg: 71.8, diastolicStdev: 11.9},
  "45to64Female": {systolicAvg: 128.0, systolicStdev: 19.7, diastolicAvg: 81.1, diastolicStdev: 11.2},
  "65upFemale": {systolicAvg: 145, systolicStdev: 23.2, diastolicAvg: 79.6, diastolicStdev: 14.2}
}

var table = {
  M: Array(130),
  F: Array(130)
};

table.M.fill(refrenceData["4to6Male"], 4, 7);
table.M.fill(refrenceData["7to12Male"], 7, 13);
table.M.fill(refrenceData["13to18Male"], 13, 19);
table.M.fill(refrenceData["19to44Male"], 19, 45);
table.M.fill(refrenceData["45to64Male"], 45, 65);
table.M.fill(refrenceData["65upMale"], 65, 130);

table.F.fill(refrenceData["4to6Female"], 4, 7);
table.F.fill(refrenceData["7to12Female"], 7, 13);
table.F.fill(refrenceData["13to18Female"], 13, 19);
table.F.fill(refrenceData["19to44Female"], 19, 45);
table.F.fill(refrenceData["45to64Female"], 45, 65);
table.F.fill(refrenceData["65upFemale"], 65, 130);

router.put('/:measurementId/gzdata', upload.single('rawdata'), function(req, res, next) {
  if(typeof req.params.measurementId === 'undefined' || Number.isNaN(parseInt(req.params.measurementId))) {
    return next({status:400, message: 'apiMisuse', devMessage: devMsgs['put/:measurementId/data']['invalid_mid']});
  }
  dao.updateMeasurementGzData(req.user.userId, req.params.measurementId, req.file.buffer, function(err, result) {
    if(err) {
      return next(err);
    }
    if(result.rowCount === 0) {
      return next({status: 404, message: 'apiMisuse', devMessage: devMsgs['put/:measurementId/data']['not_found']});
    }
    if(result.rowCount !== 1) {
      return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['put/:measurementId/data']['duplicated']});
    }
    return screeningUtil.getScreeningResultGz(req.file.buffer, function(err, output) {
      if(err) {
        return next(err);
      }
      return screeningsDao.createScreenings(req.user.userId, req.params.profileId, req.params.measurementId, output.confidenceLevel, output.riskLevel, output.riskProbability, function(err, createScreeningsResult) {
        if(err) {
          return next(err);
        }
        var responseBody = {
          message: "Success"
        };
        if(req.user.isPaidUser) {
          if(output.riskLevel > 2) {
            output.riskLevel = 2;
          }
          responseBody.riskLevel = output.riskLevel;
          responseBody.riskProbability = output.riskProbability;
          responseBody.confidenceLevel = output.confidenceLevel;
          responseBody.risklevel = output.riskLevel;
          responseBody.riskprobability = output.riskProbability;
          responseBody.confidencelevel = output.confidenceLevel;
        }
        return res.status(200).send(responseBody).end();
      });
    });
  });
});

router.put('/:measurementId/data', upload.single('rawdata'), function(req, res, next) {
  if(typeof req.params.measurementId === 'undefined' || Number.isNaN(parseInt(req.params.measurementId))) {
    return next({status:400, message: 'apiMisuse', devMessage: devMsgs['put/:measurementId/data']['invalid_mid']});
  }
  dao.updateMeasurementData(req.user.userId, req.params.measurementId, req.file.buffer, function(err, result) {
    if(err) {
      return next(err);
    }
    if(result.rowCount === 0) {
      return next({status: 404, message: 'apiMisuse', devMessage: devMsgs['put/:measurementId/data']['not_found']});
    }
    if(result.rowCount !== 1) {
      return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['put/:measurementId/data']['duplicated']});
    }
    return screeningUtil.getScreeningResult(req.file.buffer, function(err, output) {
      if(err) {
        return next(err);
      }
      return screeningsDao.createScreenings(req.user.userId, req.params.profileId, req.params.measurementId, output.confidenceLevel, output.riskLevel, output.riskProbability, function(err, createScreeningsResult) {
        if(err) {
          return next(err);
        }
        var responseBody = {
          message: "Success"
        };
        if(req.user.isPaidUser) {
          if(output.riskLevel > 2) {
            output.riskLevel = 2;
          }
          responseBody.riskLevel = output.riskLevel;
          responseBody.riskProbability = output.riskProbability;
          responseBody.confidenceLevel = output.confidenceLevel;
          responseBody.risklevel = output.riskLevel;
          responseBody.riskprobability = output.riskProbability;
          responseBody.confidencelevel = output.confidenceLevel;
        }
        return res.status(200).send(responseBody).end();
      });
    });
  });
});

router.get('/:measurementId/gzdata', function(req, res, next) {
  if(typeof req.params.measurementId === 'undefined' || Number.isNaN(parseInt(req.params.measurementId))) {
    return next({status:400, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId/data']['invalid_mid']});
  }
  dao.retrieveMeasurementGzDataById(req.user.userId, parseInt(req.params.measurementId), function(err, result) {
    if(err) {
      return next(err);
    }
    if(result.rowCount === 0) {
      return next({status: 404, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId/data']['not_found']});
    }
    if(result.rowCount !== 1) {
      return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId/data']['duplicated']});
    }
    console.log(result.rows[0].data);
    return res.status(200).send(result.rows[0].gzdata).end();
  });
});

router.get('/:measurementId/data', function(req, res, next) {
  if(typeof req.params.measurementId === 'undefined' || Number.isNaN(parseInt(req.params.measurementId))) {
    return next({status:400, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId/data']['invalid_mid']});
  }
  dao.retrieveMeasurementDataById(req.user.userId, parseInt(req.params.measurementId), function(err, result) {
    if(err) {
      return next(err);
    }
    if(result.rowCount === 0) {
      return next({status: 404, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId/data']['not_found']});
    }
    if(result.rowCount !== 1) {
      return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId/data']['duplicated']});
    }
    return res.status(200).send(result.rows[0].data).end();
//    var returnResult = result.rows[0];
//    if(!req.user.isPaidUser) {
//      return res.status(200).send(returnResult);
//    }
//    return screeningsDao.retrieveScreeningByMeasurementId(req.user.userId, req.params.measurementId, function(err, sResult) {
//      if(err) {
//        return next(err);
//      }
//      if(sResult.rowCount === 1) {
//        screeningResult = sResult.rows[0];
//        returnResult.riskLevel = null;
//        returnResult.riskProbability = null;
//        if(screeningResult.confidencelevel > 0) {
//          returnResult.riskLevel = screeningResult.risklevel;
//          returnResult.riskProbability = screeningResult.riskprobability;
//        }
//      }
//      return res.status(200).send(returnResult).end();
//    });
  });
});

router.get('/:measurementId', function(req, res, next) {
  if(typeof req.params.measurementId === 'undefined' || Number.isNaN(parseInt(req.params.measurementId))) {
    return next({status:400, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId']['invalid_mid']});
  }
  dao.retrieveMeasurementById(req.user.userId, parseInt(req.params.measurementId), function(err, result) {
    if(err) {
      return next(err);
    }
    if(result.rowCount === 0) {
      return next({status: 404, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId']['not_found']});
    }
    if(result.rowCount !== 1) {
      return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/:measurementId']['duplicated']});
    }
    var returnResult = result.rows[0];
    if(!req.user.isPaidUser) {
      return res.status(200).send(returnResult);
    }
    return screeningsDao.retrieveScreeningByMeasurementId(req.user.userId, req.params.measurementId, function(err, sResult) {
      if(err) {
        return next(err);
      }
      if(sResult.rowCount === 1) {
        screeningResult = sResult.rows[0];
        returnResult.riskLevel = screeningResult.risklevel;
        if(returnResult.riskLevel > 2) {
          returnResult.riskLevel = 2;
        }
        returnResult.riskProbability = screeningResult.riskprobability;
        returnResult.confidenceLevel = screeningResult.confidencelevel;
      }
      return res.status(200).send(returnResult).end();
    });
  });
});

/* retrieve measurements listing. */
router.get('/', function(req, res, next) {
  if(typeof req.params.profileId === 'undefined' || isNaN(parseInt(req.params.profileId)) ) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/']['invalid_pid']});
  }
  var columnList = ["systolic", "diastolic", "spo2", "heartrate", "fatigue", "pressure"];
  var columns = [];

  //Time range handling
  if(typeof req.query.startTime !== 'undefined' && typeof req.query.endTime !== 'undefined') { //given startTime & endTime
    var startTime = moment(req.query.startTime);
    var endTime = moment(req.query.endTime);
  } else if(req.query.span && typeof req.query.span === 'string') { //given time span
    var startTime = moment();
    var endTime = startTime.clone();
    if(req.query.span.localeCompare('day') === 0) {
      startTime = startTime.subtract(1, 'day');
    } else if(req.query.span.localeCompare('week') === 0) {
      startTime = startTime.subtract(7, 'day');
    } else if(req.query.span.localeCompare('month') === 0) {
      startTime = startTime.subtract(30, 'day');
    } else { //fallback... 1 day?
      startTime = startTime.subtract(1, 'day');
    }
  } else { //nothing given, fallback
    var startTime = moment('1970-01-01');
    var endTime = moment();
  }
  console.log(startTime);
  console.log(endTime);

  if(!startTime.isValid() || !endTime.isValid() === null) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/']['invalid_time']});
  }

  var limit = null;
  var offset = null;
  if(typeof req.query.limit !== 'undefined' && !isNaN(parseInt(req.query.limit))) {
    limit = parseInt(req.query.limit);
  }
  if(typeof req.query.offset !== 'undefined' && !isNaN(parseInt(req.query.offset))) {
    offset = parseInt(req.query.offset);
  }
  if(req.query.columns) {
    var colSplit = req.query.columns.split(',');
    for(var i = 0; i < colSplit.length; i++) {
      if(colSplit[i].localeCompare('all') === 0) {
        columns = columnList;
        break;
      }
      if(columnList.indexOf(colSplit[i]) !== -1) {
        columns.push(colSplit[i]);
      }
    }
  }
  dao.retrieveMeasurements(req.user.userId, req.params.profileId, startTime, endTime, columns, limit, offset, 'DESC', function(err, rawResult) {
    if(err) {
      return next(err);
    }
    dao.retrieveMeasurementStats(req.user.userId, req.params.profileId, 30, columns, function(err, statResult) {
      if(err){
        return next(err);
      }
      var result = {
        "monthlyStats": {
          /*
          "systolic": {},
          "diastolic": {},
          "spo2": {},
          "heartrate": {},
          "fatigue": {},
          "pressure": {}
          */
        },
        "data": []
      };
      for(var j = 0; j < columns.length; j++) {
        result.monthlyStats[columns[j]] = {};
      }
      for(var i = 0;i < rawResult.rowCount;i++) {
        var dataPiece = {
          "measurementid": rawResult.rows[i].measurementid,
          "timestamp": rawResult.rows[i].timestamp.getTime()
        };
        for(var j = 0; j < columns.length; j++) {
          dataPiece[columns[j]] = {
            "value": rawResult.rows[i][columns[j]],
            "status": 0
          }
        }
        result.data.push(dataPiece);
      }
      for(var i = 0; i < result.data.length; i++ ) {
        if(typeof result.data[i].systolic !== 'undefined' && result.data[i].systolic.value > 140) {
          result.data[i].systolic.status = 1;
        }
        if(typeof result.data[i].diastolic !== 'undefined' && result.data[i].diastolic.value > 90) {
          result.data[i].diastolic.status = 1;
        }
        if(typeof result.data[i].spo2 !== 'undefined' && result.data[i].spo2.value < 90) {
          result.data[i].spo2.status = 2;
        }
        if(typeof result.data[i].heartrate !== 'undefined' && result.data[i].heartrate.value > 100) {
          result.data[i].heartrate.status = 1;
        }
        if(typeof result.data[i].fatigue !== 'undefined' && result.data[i].fatigue.value > 65) {
          result.data[i].fatigue.status = 1;
        }
        if(typeof result.data[i].pressure !== 'undefined' && result.data[i].pressure.value > 65) {
          result.data[i].pressure.status = 1;
        }
      }
      if(typeof statResult !== 'undefined' && statResult !== null && statResult.rowCount === 1) {
        if(columns.indexOf('systolic') !== -1) {
          result.monthlyStats.systolic.avg = parseFloat(statResult.rows[0].systolic_avg);
          result.monthlyStats.systolic.stdev = parseFloat(statResult.rows[0].systolic_stdev);
        }
        if(columns.indexOf('diastolic') !== -1) {
          result.monthlyStats.diastolic.avg = parseFloat(statResult.rows[0].diastolic_avg);
          result.monthlyStats.diastolic.stdev = parseFloat(statResult.rows[0].diastolic_stdev);
        }
        if(columns.indexOf('spo2') !== -1) {
          result.monthlyStats.spo2.avg = parseFloat(statResult.rows[0].spo2_avg);
          result.monthlyStats.spo2.stdev = parseFloat(statResult.rows[0].spo2_stdev);
        }
        if(columns.indexOf('heartrate') !== -1) {
          result.monthlyStats.heartrate.avg = parseFloat(statResult.rows[0].heartrate_avg);
          result.monthlyStats.heartrate.stdev = parseFloat(statResult.rows[0].heartrate_stdev);
        }
        if(columns.indexOf('fatigue') !== -1) {
          result.monthlyStats.fatigue.avg = parseFloat(statResult.rows[0].fatigue_avg);
          result.monthlyStats.fatigue.stdev = parseFloat(statResult.rows[0].fatigue_stdev);
        }
        if(columns.indexOf('pressure') !== -1) {
          result.monthlyStats.pressure.avg = parseFloat(statResult.rows[0].pressure_avg);
          result.monthlyStats.pressure.stdev = parseFloat(statResult.rows[0].pressure_stdev);
        }
      }
      return res.status(200).send(result).end();
    });
  });
});

router.post('/', function(req, res, next) {
  if(!(typeof req.body.systolic === 'number' && parseInt(req.body.systolic) !== NaN &&
       typeof req.body.diastolic === 'number' && parseInt(req.body.diastolic) !== NaN &&
       typeof req.body.spo2 === 'number' && parseInt(req.body.spo2) !== NaN &&
       typeof req.body.heartrate === 'number' && parseInt(req.body.heartrate) !== NaN &&
       typeof req.body.fatigue === 'number' && parseInt(req.body.fatigue) !== NaN &&
       typeof req.body.pressure === 'number' && parseInt(req.body.pressure) !== NaN &&
       typeof req.body.timestamp === 'number' && parseInt(req.body.timestamp) !== NaN)
    ) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['post/']['missing_parameter']});
  }

  var systolic = parseInt(req.body.systolic);
  var diastolic = parseInt(req.body.diastolic);
  var spo2 = parseInt(req.body.spo2);
  var heartrate = parseInt(req.body.heartrate);
  var fatigue = parseInt(req.body.fatigue);
  var pressure = parseInt(req.body.pressure);
  var timestamp =  parseInt(req.body.timestamp);

  profilesDao.getProfileDataIdByProfileId(req.params.profileId, function(err, profileDataId) {
    if(err) {
      return next(err);
    }

    profilesDao.getProfileById(req.user.userId, req.params.profileId, function(err, daoResult) {
      daoResult = daoResult.rows;
      if(err) {
        return next(err);
      }
      if(daoResult.length === 0) {
        return next({status: 404, message: 'apiMisuse', devMessage: devMsgs['post/']['not_found']});
      }
      if(daoResult.length > 1) {
        return next(err);
      }
      var ageDiff = Date.now() - daoResult[0].birthday_date.getTime();
      var ageDate = new Date(ageDiff);
      var age = Math.abs(ageDate.getUTCFullYear()-1970);
      var gender = daoResult[0].gender;

      async.waterfall([
        function(callback) {
          dao.createMeasurement(req.user.userId, req.params.profileId, profileDataId, systolic, diastolic, spo2, heartrate, fatigue, pressure, timestamp, req.body.data, function(err, daoResult) {
            if(err) {
              return callback(err);
            }
            if(daoResult.rows.length !== 1) {
              var error = new Error();
              error.status = 500;
              return callback(error);
            }
            var measurementId = daoResult.rows[0].measurementid;
            var result = {
              "measurementid" : measurementId,
              "systolic": {
                "status": 0
              },
              "diastolic": {
                "status": 0
              },
              "spo2": {
                "status": 0
              },
              "heartrate": {
                "status": 0
              },
              "fatigue": {
                "status": 0
              },
              "pressure": {
                "status": 0
              },
              "bloodPressure": {
                "status": 0
              }
            };

            if(systolic > 140) {
              result.systolic.status = 1;
            }
            if(diastolic > 90) {
              result.diastolic.status = 1;
            }
            if(spo2 < 90) {
              result.spo2.status = 2;
            }
            if(heartrate > 100) {
              result.heartrate.status = 1;
            }
            if(fatigue > 65) {
              result.fatigue.status = 1;
            }
            if(pressure > 65) {
              result.pressure.status = 1;
            }
            if(result.systolic.status || result.diastolic.status) {
              result.bloodPressure.status = 1;
            }
            if(age >= 4 && age <= 129) {
              var genderInitial = gender.substring(0,1).toUpperCase();
              result.systolic.percentile = csnp((systolic - table[genderInitial][age].systolicAvg)/table[genderInitial][age].systolicStdev);
              result.diastolic.percentile = csnp((diastolic - table[genderInitial][age].diastolicAvg)/table[genderInitial][age].diastolicStdev);
            }
            return callback(null, result);
          });
        },
        function(result, callback) {
          if(typeof req.body.data === 'undefined') {
            return callback(null, result, null);
          }
          return screeningUtil.getScreeningResult(req.body.data, function(err, output) {
            if(err) {
              return callback(err);
            }
            return callback(null, result, output);
          });
        },
        function(result, output, callback) {
          if(output === null) {
            return callback(null, result);
          }
          return screeningsDao.createScreenings(req.user.userId, req.params.profileId, result.measurementid, output.confidenceLevel, output.riskLevel, output.riskProbability, function(err, createScreeningsResult) {
            if(err) {
              return callback(err);
            }
            if(req.user.isPaidUser) {
              if(output.risk_level > 2) {
                output.risk_level = 2;
              }
              result.riskLevel = output.risk_level;
              result.riskProbability = output.risk_probability;
              result.confidenceLevel = output.confidence_level;
              result.risklevel = output.risk_level;
              result.riskprobability = output.risk_probability;
              result.confidencelevel = output.confidence_level;
            }
            return callback(null, result);
          });
        }
      ], function(err, result) {
        if(err) {
          return next(err);
        }
        return res.status(200).send(result).end();
      });
    });
  });
});

module.exports = router;
