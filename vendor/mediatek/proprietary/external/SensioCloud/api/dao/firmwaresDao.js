var client = require('./index');

module.exports = {
  retrieveFirmwares: function(limit, offset, callback) {
    client.query('SELECT id AS "firmwareId", concat(majorversion, \'.\', minorversion) as version FROM hc.firmwares WHERE status = TRUE ORDER BY updatedat DESC LIMIT $1 OFFSET $2', [limit, offset], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveLatestFirmware: function(callback) {
    client.query('SELECT concat(fw.majorversion, \'.\', fw.minorversion) as version, f.filename as filename, f.filepath as filepath FROM hc.firmwarefiles f, (SELECT * FROM hc.firmwares ORDER BY createdat DESC LIMIT 1) fw WHERE fw.id = f.firmwareid', function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveSingleFirmware: function(firmwareId, callback) {
    client.query('SELECT concat(fw.majorversion, \'.\', fw.minorversion) as version, f.filename as filename, f.filepath as filepath FROM hc.firmwarefiles f, hc.firmwares fw WHERE fw.id = $1 and fw.id = f.firmwareid', [firmwareId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },
  retrieveFirmwareData: function(firmwareId, filename, callback) {
    client.query('SELECT d.data FROM hc.firmwaredata d, hc.firmwarefiles f WHERE f.firmwareid = $1 AND f.filename = $2 AND d.firmwarefileid = f.id AND f.status = TRUE AND d.status = TRUE', [firmwareId, filename], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  }
};

