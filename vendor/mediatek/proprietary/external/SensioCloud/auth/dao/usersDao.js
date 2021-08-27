var pg = require('pg').native;
var bcrypt = require('bcrypt');
var envConfigs = require('../configs/env');
var dbConfigs = new envConfigs().dbConfigs;
var conString = 'postgres://' + dbConfigs.username + ':' + dbConfigs.password + '@' + dbConfigs.host + '/' + dbConfigs.database;
module.exports = {
  setIsPaidUser: function(userId, isPaidUser, callback) {
    pg.connect(conString, function(err, client, done) {
      if(err) {
        return callback(err);
      }
      client.query("UPDATE hc.users SET ispaiduser = $1 WHERE userid = $2 RETURNING userid as \"userId\", ispaiduser", [isPaidUser, userId], function(err, result){
        done();
        if(err) {
          return callback(err);
        }
        return callback(null, result.rows[0]);
      });
    });
  },
  createUser: function(username, password, callback) {
    bcrypt.hash(password, 10, function(err, hash) {
      if(err) {
        return callback(err);
      }
      pg.connect(conString, function(err, client, done) {
        if(err) {
          return callback(err, null);
        }
        client.query('INSERT INTO hc.users (username, password) VALUES ($1, $2) RETURNING userid as \"userId\", username, ispaiduser', [username, hash], function(err, result) {
          done();
          if(err) {
            return callback(err);
          }
          if(result.rows.length !== 1) {
            return callback(null, false);
          }
          return callback(null, result.rows[0]);
        });
      });
    });
  },
  updateUser: function(userId, username, password, callback) {
    bcrypt.hash(password, 10, function(err, hash) {
      if(err) {
        return callback(err);
      }
      pg.connect(conString, function(err, client, done) {
        if(err) {
          return callback(err, null);
        }
        client.query('UPDATE hc.users SET username = $1, password = $2 WHERE userid = $3 RETURNING userid as \"userId\", username, ispaiduser', [username, hash, userId], function(err, result) {
          done();
          if(err) {
            return callback(err);
          }
          if(result.rows.length !== 1) {
            return callback(null, false);
          }
          return callback(null, result.rows[0]);
        });
      });
    });
  },
  getUserByUsername: function(username, callback) {
    var sql = 'SELECT userId AS \"userId\", username, password, ispaiduser FROM hc.Users WHERE username = $1 AND Users.status = TRUE';
    pg.connect(conString, function(err, client, done) {
      if(err) {
        callback(err, null);
        return;
      }
      client.query(sql, [username], function(err, result) {
        done();
        if(err) {
          callback(err, null);
          return;
        }
        if(result.rows.length > 0) {
          callback(null, result.rows[0]);
        } else {
          callback(new Error('The user ' + username + ' does not exist'), null);
        }
      });
    });
  },
  getUserByUserId: function(userId, callback) {
    var sql = 'SELECT userId AS \"userId\", username, password, ispaiduser FROM hc.Users WHERE userId = $1 AND Users.status = TRUE';
    pg.connect(conString, function(err, client, done) {
      if(err) {
        callback(err, null);
        return;
      }
      client.query(sql, [userId], function(err, result) {
        done();
        if(err) {
          callback(err, null);
          return;
        }
        if(result.rows.length > 0) {
          callback(null, result.rows[0]);
        } else {
          callback(new Error('The user ' + userId + ' does not exist', null));
        }
      });
    });
  }
};
