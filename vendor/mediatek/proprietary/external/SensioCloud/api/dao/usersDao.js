var client = require('./index');
module.exports = {
  createGuestUser: function(authId, callback) {
    client.query('INSERT INTO hc.users (username, authid) VALUES ($1, $2) RETURNING username, userid as \"userId\"', ['Guest User', authId], function(err, result) {
      if(err) {
        return callback(err, null);
      }
      if(result.rows.length > 0) {
        return callback(null, result.rows[0]);
      } else {
        return callback(null, null);
      }
    });
  },
  findUserByAuthId: function(authId, callback) {
    console.log('jwt id: ' + authId);
    client.query('SELECT userid AS \"userId\", username FROM hc.users WHERE authid = $1 AND status = TRUE', [authId], function(err, result) {
      if(err) {
        return callback(err, null);
      }
      if(result.rows.length > 0) {
        return callback(null, result.rows[0]);
      } else {
        return callback(null, null);
      }
    });
  },
  getUserByUsername: function(username, callback) {
    var sql = 'SELECT userId AS \"userId\", username, password FROM hc.Users WHERE username = $1 AND Users.status = TRUE';
    client.query(sql, [username], function(err, result) {
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
  },
  getUserByUserId: function(userId, callback) {
    var sql = 'SELECT userId AS \"userId\", username, password FROM hc.Users WHERE userId = $1 AND Users.status = TRUE';
    client.query(sql, [userId], function(err, result) {
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
  }
};
