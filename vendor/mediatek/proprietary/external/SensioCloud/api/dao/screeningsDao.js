var client = require('./index');

module.exports = {
  retrieveScreeningByMeasurementId: function(userId, measurementId, callback) {
    client.query('SELECT s.confidencelevel AS "confidenceLevel", s.risklevel AS "riskLevel", s.riskprobability AS "riskProbability", s.confidencelevel, s.risklevel, s.riskprobability FROM hc.screenings s WHERE s.userid = $1 AND s.measurementid = $2 AND s.status = TRUE', [userId, measurementId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveScreenings: function(userId, profileId, limit, offset, callback) {
    client.query('SELECT m.measurementid, s.confidencelevel AS "confidenceLevel", s.risklevel AS "riskLevel", s.riskprobability AS "riskProbability", s.confidencelevel, s.risklevel, s.riskprobability, EXTRACT(epoch FROM m.timestamp)*1000 as timestamp FROM hc.screenings s, hc.measurements m WHERE s.userid = $1 AND s.profileid = $2 AND s.status = true AND m.status = true AND s.measurementid = m.measurementid ORDER BY m.timestamp DESC LIMIT $3 OFFSET $4', [userId, profileId, limit, offset], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  createScreenings: function(userId, profileId, measurementId, confidenceLevel, riskLevel, riskProbability, callback){
    client.query('INSERT INTO hc.screenings (userid, profileid, measurementid, confidencelevel, risklevel, riskprobability) VALUES ($1, $2, $3, $4, $5, $6) ON CONFLICT (measurementid) DO UPDATE SET confidencelevel = EXCLUDED.confidencelevel, risklevel = EXCLUDED.risklevel, riskprobability = EXCLUDED.riskprobability', [userId, profileId, measurementId, confidenceLevel, riskLevel, riskProbability], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  }
};

