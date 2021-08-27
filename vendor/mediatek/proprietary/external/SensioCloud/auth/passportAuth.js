var bcrypt = require('bcrypt');
var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;
var dao = require('./dao/usersDao');

function passwordHashMatch(user, password, done) {
  bcrypt.compare(password, user.password, function(err, res) {
    if(err) {
      return done(err);
    }
    if(res) {
      return done(null, user, { message: 'Auth: Welcome, ' + user.username + '.'});
    } else {
      return done(null, false, { message: 'Invalid username/password', status: 401} );
    }
  });
}

function findByUsername(username, cb) {
  dao.getUserByUsername(username, function(error, result) {
    if(error) {
      return cb(error, null);
    }
    return cb(null, result);
  });
}

function findById(id, cb) {
  dao.getUserByUserId(id, function(error, result) {
    if (error) {
      return cb(error, null);
    }
    return cb(null, result);
  });
}

module.exports = {

  verifyIdentity: function(username, password, done) {
      findByUsername(username, function(err, user) {
        if (err) { return done(err); }
        if (!user) { return done(null, false, { message: 'Auth: Unknown user.'}); }
        return passwordHashMatch(user, password, done);
      });
  },

  ensureAuthenticated: function(req, res, next) {
    if (req.isAuthenticated()) { 
      console.log('Auth ensure: 200, -------------------- this way -[->]');
      return next();
    }
    var theName;
    if (typeof req.user !== 'undefined') {
      theName = req.user.username;
    }
    console.log('Auth ensure: 403 with user [' + theName + ']' + ',  X-X-X-X-X API access denied. X-X-X-X-X');
    return res.status(403).end();
  }
};
