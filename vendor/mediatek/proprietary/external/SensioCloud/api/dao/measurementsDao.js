var async = require('async');
var client = require('./index');

module.exports = {
  updateMeasurementGzData: function(userId, measurementId, data, callback) {
    if(typeof userId === 'undefined' || !userId) {
      return callback(new Error('User ID is invalid'));
    }
    if(typeof measurementId === 'undefined' || !measurementId) {
      return callback(new Error('Measurement ID is invalid'));
    }
    if(typeof data === 'undefined' || !data) {
      return callback(new Error('Data is invalid'));
    }
    client.query('UPDATE hc.measurements SET gzdata = $1 WHERE userid = $2 AND measurementid = $3 and status = TRUE', [data, userId, measurementId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  updateMeasurementData: function(userId, measurementId, data, callback) {
    if(typeof userId === 'undefined' || !userId) {
      return callback(new Error('User ID is invalid'));
    }
    if(typeof measurementId === 'undefined' || !measurementId) {
      return callback(new Error('Measurement ID is invalid'));
    }
    if(typeof data === 'undefined' || !data) {
      return callback(new Error('Data is invalid'));
    }
    client.query('UPDATE hc.measurements SET data = $1 WHERE userid = $2 AND measurementid = $3 and status = TRUE', [data, userId, measurementId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  createMeasurement: function(userId, profileId, profileDataId, systolic, diastolic, spo2, heartrate, fatigue, pressure, timestamp, data, callback) {
    client.query("INSERT INTO hc.measurements (userid, profileid, profiledataid, systolic, diastolic, spo2, heartrate, fatigue, pressure, timestamp, data) VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11) RETURNING measurementid", [userId, profileId, profileDataId, systolic, diastolic, spo2, heartrate, fatigue, pressure, new Date(timestamp), data],function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveMeasurementStats: function(userId, profileId, period, columns, callback) {
    if(columns.length === 0) {
      return callback(null, null);
    }
    var statColumns = [];
    for(var i = 0;i < columns.length;i++) {
      statColumns.push('ROUND(AVG(' + columns[i] + '),2) as ' + columns[i] + '_avg');
      statColumns.push('ROUND(STDDEV_SAMP(' + columns[i] + '),2) as ' + columns[i] + '_stdev');
    }
    var sql = 
      'SELECT ' + statColumns.join(',') + ' ' + 
      'FROM hc.measurements ' + 
      'WHERE userId = $1 AND profileId = $2 AND status = TRUE AND timestamp > now() - interval \'' + period + ' day\'';
    client.query(sql, [userId, profileId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveMeasurements: function(userId, profileId, startTime, endTime, columns, limit, offset, order, callback) {
    var sqlColumns = columns.slice();
    sqlColumns.push('timestamp');
    sqlColumns.push('measurementid');
    var orderBy = 'ASC';
    if(order.localeCompare('DESC') === 0) {
      orderBy = 'DESC';
    }
    var sql =
      'SELECT ' + sqlColumns.join(',') + ' ' +
      'FROM hc.measurements ' +
      'WHERE userId = $1 AND profileId = $2 AND status = TRUE AND timestamp >= $3 AND timestamp < $4 ' +
      'ORDER BY timestamp ' + orderBy + ' ' +
      'LIMIT $5 OFFSET $6';
    client.query(sql, [userId, profileId, startTime, endTime, limit, offset], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveMeasurementGzDataById: function(userId, measurementId, callback) {
    var sql = 'SELECT m.gzdata FROM hc.measurements m WHERE userid = $1 AND measurementid = $2 AND status = true';
    client.query(sql, [userId, measurementId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveMeasurementDataById: function(userId, measurementId, callback) {
    var sql = 'SELECT m.data FROM hc.measurements m WHERE userid = $1 AND measurementid = $2 AND status = true';
    client.query(sql, [userId, measurementId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveMeasurementById: function(userId, measurementId, callback) {
    var sql = 'SELECT m.measurementid, m.systolic, m.diastolic, m.spo2, m.heartrate, m.fatigue, m.pressure, EXTRACT (EPOCH FROM m.timestamp)*1000 as timestamp FROM hc.measurements m WHERE userid = $1 AND measurementid = $2 AND status = true';
    client.query(sql, [userId, measurementId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  }
};
