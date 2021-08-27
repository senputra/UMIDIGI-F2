Pre-Screening Algorithm Library Usage Guide

== Function Signature ==

struct screening_result_t mt6381_online_screening(char* filename)

== Function Input ==

The path and filename of the raw 6381 data file

== Function Output ==

struct screening_result_t
{
  int32_t risk_probability;
  int32_t risk_level;
  int32_t confidence_level;
};

== Usage ==

struct screening_result_t screening_result_out;
screening_result_out = mt6381_online_screening(filename);

== Sample Code in Node.JS ==

var ref = require('ref');
var ffi = require('ffi');
var Struct = require('ref-struct');

var getScreeningResult = function(filename, callback) {
  var screening_result_t = Struct({
    'risk_probability': 'int',
    'risk_level': 'int',
    'confidence_level': 'int'
  });
  var onlineScreening = ffi.Library('libmtk_bp_alg'), {
    'mt6381_online_screening': [screening_result_t, ['string']]
  });
  var output = new screening_result_t();
  output = onlineScreening.mt6381_online_screening(filename));
  return callback(null, output);
};
