var client = require('../dao/index');
var jwtCustomerId = require('../configs/env')().screeningCustomerId;
var crypto = require('crypto');
var async = require('async');

async.waterfall([
  function(callback) {
    client.query('SELECT userid, profileid FROM hc.profiles', function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result.rows);
    });
  },
  function(rows, callback) {
    async.each(rows, function(row, callback) {
      var hash = crypto.createHash('sha256');
      hash.update(jwtCustomerId + row.userid);
      var uniqueid = hash.digest('base64').replace(/\//g, '_');
      client.query('UPDATE hc.profiles SET uniqueid = $1 WHERE profileid = $2', [uniqueid, row.profileid], function(err, result){
        if(err) {
          return callback(err);
        }
        return callback();
      });
    }, function(err) {
      if(err) {
        return callback(err);
      }
      return callback();
    });
  },
], function(err) {
  if(err) {
    return console.log(err);
  }
  return console.log('Done');
});
