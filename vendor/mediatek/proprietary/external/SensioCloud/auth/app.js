var express = require('express');
var logger = require('morgan');
var bodyParser = require('body-parser');
var moment = require('moment');
var envConfigs = require('./configs/env');
var jwt = require('jsonwebtoken');
var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;
var JwtStrategy = require('passport-jwt').Strategy;
var ExtractJwt = require('passport-jwt').ExtractJwt;
var passportAuth = require('./passportAuth');
var usersDao = require('./dao/usersDao');

var jwtStrategyOptions = envConfigs().jwtStrategyOptions;
jwtStrategyOptions.jwtFromRequest = ExtractJwt.fromAuthHeaderAsBearerToken();
passport.use(new LocalStrategy(passportAuth.verifyIdentity));
passport.use(new JwtStrategy(jwtStrategyOptions, function(jwt_payload, done) {
  usersDao.getUserByUserId(jwt_payload.id, function(err, user) {
    if(err) {
      return done(err, false);
    }
    if(user) {
      return done(null, user);
    } else {
      return done(null, false);
    }
  });
}));

var app = express();

app.use(logger('dev'));
app.use(bodyParser.json());

app.use(passport.initialize());

app.get('/guest', function(req, res, next) {
  var now = moment().unix().toString();
  var guestUsername = '6381 Guest ' + now;
  var guestPassword = '6381 Guest Password ' + now;
  usersDao.createUser(guestUsername, guestPassword, function(err, userInfo) {
    if(err) {
      return next(err);
    }
    if(!userInfo.userId) { return res.status(500).end(); };
    return res.status(200).send({
      accessToken: jwt.sign(
        {'id': userInfo.userId, 'isPaidUser': userInfo.ispaiduser}, envConfigs().accessTokenSecretOrKey, envConfigs().accessTokenJwtOptions),
      refreshToken: jwt.sign(
        {'id': userInfo.userId}, envConfigs().refreshTokenSecretOrKey, envConfigs().refreshTokenJwtOptions),
      screeningsPermission: userInfo.ispaiduser
    });
  });
});

app.get('/refresh', passport.authenticate('jwt', {session: false}), function(req, res, next) {
  return res.status(200).send({
    accessToken: jwt.sign(
      {'id': req.user.userId, 'isPaidUser': req.user.ispaiduser}, envConfigs().accessTokenSecretOrKey, envConfigs().accessTokenJwtOptions),
    refreshToken: jwt.sign(
      {'id': req.user.userId}, envConfigs().refreshTokenSecretOrKey, envConfigs().refreshTokenJwtOptions),
    screeningsPermission: req.user.ispaiduser
  });
});

var validateRequest = function(requestBody, callback) {
  return callback(null, true);
}

app.post('/downgrade', passport.authenticate('jwt', {session: false}), function(req, res, next) {
  return validateRequest(req.body, function(err, result) {
    if(err) {
      return next(err);
    }
    if(!result) {
      return next({status: 403, message: 'Cannot validate request'});
    }
    return usersDao.setIsPaidUser(req.user.userId, false, function(err, userInfo) {
      if(err) {
        return next(err);
      }
      return res.status(200).send({
        accessToken: jwt.sign(
          {'id': userInfo.userId, 'isPaidUser': userInfo.ispaiduser}, envConfigs().accessTokenSecretOrKey, envConfigs().accessTokenJwtOptions),
        refreshToken: jwt.sign(
          {'id': userInfo.userId}, envConfigs().refreshTokenSecretOrKey, envConfigs().refreshTokenJwtOptions),
        screeningsPermission: userInfo.ispaiduser
      });
    });
  });
});

app.post('/upgrade', passport.authenticate('jwt', {session: false}), function(req, res, next) {
  return validateRequest(req.body, function(err, result) {
    if(err) {
      return next(err);
    }
    if(!result) {
      return next({status: 403, message: 'Cannot validate request'});
    }
    return usersDao.setIsPaidUser(req.user.userId, true, function(err, userInfo) {
      if(err) {
        return next(err);
      }
      return res.status(200).send({
        accessToken: jwt.sign(
          {'id': userInfo.userId, 'isPaidUser': userInfo.ispaiduser}, envConfigs().accessTokenSecretOrKey, envConfigs().accessTokenJwtOptions),
        refreshToken: jwt.sign(
          {'id': userInfo.userId}, envConfigs().refreshTokenSecretOrKey, envConfigs().refreshTokenJwtOptions),
        screeningsPermission: userInfo.ispaiduser
      });
    });
  });
});

app.post('/register', function(req, res, next) {
  if(typeof req.body.username === 'undefined' || typeof req.body.password === 'undefined') {
    return res.status(400).send({message: 'Please provide username and password'});
  }
  passport.authenticate('jwt', {session: false}, function(err, user, info) {
    console.log(info);
    if (err) { return next(err); }
    if (!user) { //Not a guest user
      return usersDao.createUser(req.body.username, req.body.password, function(err, user) {
        if(err) {
          if(err.sqlState === '23505') { //Unique key violation
            return res.status(400).send({message: 'An user with the given username already exists.'});
          }
          return next(err);
        }
        console.log("Hi, " + user.username + ", you've already successfully logged in.");
        return res.status(200).send({
          accessToken: jwt.sign(
            {'id': user.userId, 'isPaidUser': user.ispaiduser}, envConfigs().accessTokenSecretOrKey, envConfigs().accessTokenJwtOptions),
          refreshToken: jwt.sign(
            {'id': user.userId}, envConfigs().refreshTokenSecretOrKey, envConfigs().refreshTokenJwtOptions),
          screeningsPermission: user.ispaiduser
        });
      });
    } else { //Guest user, update current user instead
      return usersDao.updateUser(user.userId, req.body.username, req.body.password, function(err, user) {
        if(err) {
          if(err.sqlState === '23505') { //Unique key violation
            return res.status(400).send({message: 'An user with the given username already exists.'});
          }
          return next(err);
        }
        console.log("Hi, " + user.username + ", you've already successfully logged in.");
        return res.status(200).send({
          accessToken: jwt.sign(
            {'id': user.userId, 'isPaidUser': user.ispaiduser}, envConfigs().accessTokenSecretOrKey, envConfigs().accessTokenJwtOptions),
          refreshToken: jwt.sign(
            {'id': user.userId}, envConfigs().refreshTokenSecretOrKey, envConfigs().refreshTokenJwtOptions),
          screeningsPermission: user.ispaiduser
        });
      });
    }
  })(req, res, next);
});

app.post('/login', function(req, res, next) {
  console.log(moment().format('YYYY-MM-DD H:mm:ss'));
  passport.authenticate('local', function(err, user, info) {
    console.log(info);
    if (err) { return next(err); }
    if (!user) { var err = new Error('Invalid username/password'); err.status = 401; return next(err); }
    console.log("Hi, " + user.username + ", you've already successfully logged in.");
    return res.status(200).send({
      accessToken: jwt.sign(
        {'id': user.userId, 'isPaidUser': user.ispaiduser}, envConfigs().accessTokenSecretOrKey, envConfigs().accessTokenJwtOptions),
      refreshToken: jwt.sign(
        {'id': user.userId}, envConfigs().refreshTokenSecretOrKey, envConfigs().refreshTokenJwtOptions),
      screeningsPermission: user.ispaiduser
    });
  })(req, res, next);
});

// Show the time when an API is queried
app.use('/', function(req, res, next){
  if (typeof req.user !== 'undefined' && typeof req.user.username !== 'undefined') {
    console.log(moment().format('YYYY-MM-DD H:mm:ss') + ' [' + req.user.username + ']');
  }
  else {
    console.log(moment().format('YYYY-MM-DD H:mm:ss') + ' [user unknown]');
  }
  next();
});

/*
app.post('/logout', function(req, res){
  req.logout();
  console.log('Logged out.');
  res.status(200).end();
});
*/
// 2nd part of passport authentication ends here.

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers
// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500).send({
    "message": err.message
  }).end();
  console.log(err);
});


var server = app.listen(envConfigs().appPort, function(){
  var host = server.address().address;
  var port = server.address().port;
  console.log(moment().format('YYYY-MM-DD H:mm:ss') + ' [server starts]');
  console.log('app listening at http://%s:%s', host, port);
});

module.exports = app;
