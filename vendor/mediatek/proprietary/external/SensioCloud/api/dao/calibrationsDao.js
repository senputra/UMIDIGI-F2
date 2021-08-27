var client = require('./index');
module.exports = {
  deleteCalibrations: function(userId, profileId, callback) {
    client.query('UPDATE hc.calibrations SET status = false WHERE userid = $1 AND profileid = $2 AND status = true', [userId, profileId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveCalibrations: function(userId, profileId, callback) {
    client.query('SELECT data FROM hc.calibrations WHERE userid = $1 AND profileid = $2 AND status = true ORDER BY createdat DESC LIMIT 1', [userId, profileId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  createCalibrations: function(userId, profileId, data, callback){
    client.query('INSERT INTO hc.calibrations (userid, profileid, data) VALUES ($1, $2, $3)', [userId, profileId, data], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  }
};
