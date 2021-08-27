var moment = require('moment');
var jwt = require('jsonwebtoken');
var screeningAPIEndpoint = require('../configs/env')().screeningAPIEndpoint;
var screeningGzAPIEndpoint = require('../configs/env')().screeningGzAPIEndpoint;
var jwtKey = require('../configs/env')().screeningJwtKey;
var jwtOptions = require('../configs/env')().screeningJwtOptions;
var jwtCustomerId = require('../configs/env')().screeningCustomerId;
var request = require('request');

var getScreeningResultGz = function(data, callback) {
  if(typeof data === 'undefined') {
    return callback(new Error('Data is undefined'));
  }
  var formData = {
    rawdata: {
      value: data,
      options: {
        filename: 'notRealyImportant.txt',
        contentType: 'text/plain'
      }
    }
  };
  request.post({
    url: screeningGzAPIEndpoint,
    headers: {
      'Authorization': 'bearer ' + jwt.sign({
        'customerId': jwtCustomerId
      }, jwtKey, jwtOptions)
    },
    formData: formData
  }, function(err, httpResponse, body) {
    if(err) {
      return callback(err);
    }
    if(httpResponse.statusCode !== 200) {
      return callback(new Error('Screening API HTTP response code ' + httpResponse.statusCode));
    }
    var result = JSON.parse(body);
    if(typeof result.result.riskProbability !== 'undefined' && (result.result.riskProbability > 100 || result.result.riskProbability < 0)) {
      result.result.riskProbability = 0;
    }
    return callback(null, result.result);
  });
};
var getScreeningResult = function(data, callback) {
  if(typeof data === 'undefined') {
    return callback(new Error('Data is undefined'));
  }
  var formData = {
    rawdata: {
      value: data.toString('utf-8'),
      options: {
        filename: 'notRealyImportant.txt',
        contentType: 'text/plain'
      }
    }
  };
  request.post({
    url: screeningAPIEndpoint,
    headers: {
      'Authorization': 'bearer ' + jwt.sign({
        'customerId': jwtCustomerId
      }, jwtKey, jwtOptions)
    },
    formData: formData
  }, function(err, httpResponse, body) {
    if(err) {
      return callback(err);
    }
    if(httpResponse.statusCode !== 200) {
      return callback(new Error('Screening API HTTP response code ' + httpResponse.statusCode));
    }
    var result = JSON.parse(body);
    if(typeof result.result.riskProbability !== 'undefined' && (result.result.riskProbability > 100 || result.result.riskProbability < 0)) {
      result.result.riskProbability = 0;
    }
    return callback(null, result.result);
  });
};

module.exports = {
  getScreeningResult: getScreeningResult,
  getScreeningResultGz: getScreeningResultGz
};
