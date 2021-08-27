var pg = require('pg');
var dbConfigs = require('../configs/env')().dbConfigs;
var pool = new pg.Pool(dbConfigs);

module.exports = {
  query: function(text, params, callback) {
    return pool.query(text, params, callback);
  },
  getClient: function(callback) {
    pool.connect(function(err, client, done) {
      callback(err, client, done);
    });
  }
}
