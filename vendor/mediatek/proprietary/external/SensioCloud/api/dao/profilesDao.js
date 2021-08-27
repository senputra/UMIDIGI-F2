var async = require('async');
var client = require('./index');

module.exports = {
  deleteProfileByProfileId: function(userId, profileId, callback) {
    client.query('UPDATE hc.profiles SET status = false WHERE userid = $1 AND profileid = $2', [userId, profileId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null);
    });
  },
  getProfileDataIdByProfileId: function(profileId, callback) {
    client.query('SELECT profiledataid FROM hc.profiledata WHERE profileid = $1 AND status = TRUE ORDER BY createdat DESC LIMIT 1', [profileId], function(err, result) {
      if(err) {
        return callback(err);
      }
      if(result.rows.length < 1) {
        return callback({status: 404, message: "profiledataid not found"});
      }
      return callback(null, result.rows[0].profiledataid)
    });
  },
  getProfileById: function(userId, profileId, callback) {
    client.query('SELECT p.profileid, p.name, p.uniqueid, pd.gender, pd.birthday AS birthday_date, ' +
                 'to_char(pd.birthday, \'YYYY/MM/DD\') as birthday, pd.height, pd.weight, pd.weightunit, ' +
                 'EXISTS(SELECT 1 FROM hc.calibrations WHERE profileid = pd.profileid AND status = TRUE) AS calibrated, ' +
                 'pd.drug AS "personalStatus", pd.drugtime AS "takeMedicineTime" ' +
                 'FROM hc.profiles p, hc.profiledata pd ' +
                 'WHERE p.userId = $1 AND p.profileid = $2 AND p.status = TRUE AND pd.status = TRUE AND p.profileid = pd.profileid ' +
                 'ORDER BY p.profileid ASC', [userId, profileId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  },

  updateProfileById: function(userId, profileData, input, callback) {
    client.getClient(function(err, client, done) {
      if(err) {
        return callback(err);
      }
      async.waterfall([
        function(callback) {
          client.query('START TRANSACTION', function(err, result) {
            if(err) {
              return callback(err);
            }
            return callback(null);
          });
        },
        function(callback) {
          if(typeof input.gender === 'undefined' && typeof input.birthday === 'undefined' &&
             typeof input.height === 'undefined' && typeof input.weight === 'undefined' &&
             typeof input.weightunit === 'undefined' && typeof input.drug === 'undefined' &&
             typeof input.drugtime === 'undefined') { //No need to update profile data
            return callback(null, profileData);
          }
          if(typeof input.gender === 'undefined') {
            input.gender = profileData.gender;
          }
          if(typeof input.birthday === 'undefined') {
            input.birthday = profileData.birthday;
          }
          if(typeof input.height === 'undefined') {
            input.height = profileData.height;
          }
          if(typeof input.weight === 'undefined') {
            input.weight = profileData.weight;
          }
          if(typeof input.weightunit === 'undefined') {
            input.weightunit = profileData.weightunit;
          }
          if(typeof input.drug === 'undefined') {
            input.drug = profileData.personalStatus;
          }
          if(typeof input.drugtime === 'undefined') {
            input.drugtime = profileData.takeMedicineTime;
          }
          client.query(
          'INSERT INTO hc.profiledata (profileid, gender, birthday, height, weight, weightunit, drug, drugtime) ' +
          'VALUES ($1, $2, $3, $4, $5, $6, $7, $8) ' +
          'RETURNING profileid, profiledataid, gender, to_char(birthday, \'YYYY/MM/DD\') AS birthday, height, weight, weightunit, EXISTS(SELECT 1 FROM hc.calibrations WHERE profileid = hc.profiledata.profileid AND status = TRUE) as calibrated, drug AS "personalStatus", drugtime AS "takeMedicineTime"',
          [profileData.profileid, input.gender, input.birthday, input.height, input.weight, input.weightunit, input.drug, input.drugtime],
          function(err, secondResult) {
            if(err) {
              return callback(err);
            }
            client.query('UPDATE hc.profiledata SET status = false WHERE profileid = $1 AND profiledataid != $2', [profileData.profileid, secondResult.rows[0].profiledataid], function(err, thirdResult) {
              if(err) {
                return callback(err);
              }
              delete secondResult.rows[0].profiledataid;
              return callback(null, secondResult.rows[0]);
            });
          });
        },
        function(updatedProfileData, callback) {
          if(typeof input.name !== 'string' || input.name === null) { // Profile is not going to be updated
            updatedProfileData.name = profileData.name;
            return callback(null, updatedProfileData);
          }
          var updateAttr = ["name"];
          var updateValue = [input.name];
          return client.query('UPDATE hc.profiles SET name = $1 WHERE userid = $2 AND profileid = $3 RETURNING profileid, name, uniqueid', [input.name, userId, profileData.profileid], function(err, updateResult) {
            if(err) {
              return callback(err);
            }
            updatedProfileData.name = updateResult.rows[0].name;
            updatedProfileData.uniqueid = updateResult.rows[0].uniqueid;
            return callback(null, updatedProfileData);
          });
        }
      ], function(err, result) {
        if(err) {
          console.log(err);
          return client.query('ROLLBACK', function(err1, result) {
            done();
            if(err) {
              console.log(err1);
            }
            return callback(err);
          });
        }
        return client.query('COMMIT', function(err, commitResult) {
          done();
          if(err) {
            return callback(err);
          }
          return callback(null, result);
        });
      });
    });
  },

  createProfile: function(userId, input, callback) {
    client.getClient(function(err, client, done) {
      if(err) {
        return callback(err);
      }
      async.waterfall([
        //start transaction
        function(callback) {
          client.query('START TRANSACTION', function(err, result) {
            if(err) {
              return callback(err);
            }
            return callback(null);
          });
        },
        //insert profiles
        function(callback) {
          client.query('INSERT INTO hc.profiles (name, userid, uniqueid) VALUES ($1, $2, $3) RETURNING profileid, name, uniqueid', [input.name, userId, input.uniqueid], function(err, result) {
            if(err) {
              return callback(err);
            }
            return callback(null, result.rows[0].profileid, result.rows[0].name, result.rows[0].uniqueid);
          });
        },
        //insert profiledata
        function(profileid, name, uniqueid, callback) {
          client.query(
          'INSERT INTO hc.profileData (profileid, gender, birthday, height, weight, weightunit, drug, drugtime) ' +
          'VALUES ($1, $2, $3, $4, $5, $6, $7, $8) ' +
          'RETURNING profileid, gender, to_char(birthday, \'YYYY/MM/DD\') AS birthday, height, weight, false as calibrated, weightunit, drug AS "personalStatus", drugtime AS "takeMedicineTime"',
          [profileid, input.gender, input.birthday, input.height, input.weight, input.weightunit, input.drug, input.drugtime],
          function(err, secondResult) {
            if(err) {
              return callback(err);
            }
            finalResult = secondResult.rows[0];
            finalResult.name = name;
            finalResult.uniqueid = uniqueid;
            return callback(null, finalResult);
          });
        }
      ], function(err, result) {
        if(err) {
          console.log(err);
          return client.query('ROLLBACK', function(err1, result) {
            done();
            if(err1) {
              console.log(err1);
            }
            return callback(err);
          });
        }
        return client.query('COMMIT', function(err, commitResult) {
          done();
          if(err) {
            return callback(err);
          }
          return callback(null, result);
        });
      });
    });
  },

  getProfiles: function(userId, callback) {
    client.query('SELECT p.profileid, p.name, p.uniqueid, pd.gender, to_char(pd.birthday, \'YYYY/MM/DD\') as birthday, pd.height, pd.weight, pd.weightunit, EXISTS(SELECT 1 FROM hc.calibrations WHERE profileid = pd.profileid AND status = TRUE) AS calibrated, pd.drug AS "personalStatus", pd.drugtime AS "takeMedicineTime" ' +
                 'FROM hc.profiles p, hc.profiledata pd ' +
                 'WHERE p.userId = $1 AND p.status = TRUE AND pd.status = TRUE AND p.profileid = pd.profileid ' +
                 'ORDER BY p.name ASC', [userId], function(err, result) {
      if(err) {
        return callback(err);
      }
      return callback(null, result);
    });
  }
};
