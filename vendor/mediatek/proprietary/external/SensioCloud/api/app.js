var express = require('express');
var path = require('path');
var logger = require('morgan');
var bodyParser = require('body-parser');
var moment = require('moment');
var profiles = require('./routes/profiles');
var firmwares = require('./routes/firmwares');
var envConfigs = require('./configs/env');
var usersDao = require('./dao/usersDao');

var passport = require('passport');
var JwtStrategy = require('passport-jwt').Strategy;
var ExtractJwt = require('passport-jwt').ExtractJwt;

const devMsgs = require('./statics/developerMessages').appMsgs;

const i18next = require('i18next');
const i18nextMiddleware = require('i18next-express-middleware');
const Backend = require('i18next-node-fs-backend');

var jwtOptions = envConfigs().jwtConfigs;
jwtOptions.jwtFromRequest = ExtractJwt.fromAuthHeaderAsBearerToken();

passport.use(new JwtStrategy(jwtOptions, function(jwt_payload, done) {
  usersDao.findUserByAuthId(jwt_payload.id, function(err, user) {
    if(err) {
      return done(err, false);
    }
    if(user) {
      console.log('verify function user:' + user);
      if(jwt_payload.isPaidUser) {
        user.isPaidUser = true;
      } else {
        user.isPaidUser = false;
      }
      return done(null, user);
    } else {
      usersDao.createGuestUser(jwt_payload.id, function(err, result) {
        if(err) {
          return done(err);
        }
        console.log('created guest user for authid: ' + jwt_payload.id + ' as ' + result);
        return done(null, result);
      });
    }
  });
}));

var app = express();

i18next
.use(Backend)
.use(i18nextMiddleware.LanguageDetector)
.init({
  backend: {
    loadPath: __dirname + '/locales/{{lng}}/{{ns}}.json',
    addPath: __dirname + '/locales/{{lng}}/{{ns}}.missing.json'
  },
  fallbackLng: 'en',
  preload: ['en', 'zh-CN', 'zh-TW'],
  saveMissing: false
});

app.use(i18nextMiddleware.handle(i18next));

app.use(logger('dev'));
app.use(bodyParser.json({limit: '100mb'}));
app.use(passport.initialize());

app.get('/', function(req, res, next) {
  res.status(200).end();
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

app.use('/profiles', passport.authenticate('jwt', {session: false}), profiles);
app.use('/firmwares', passport.authenticate('jwt', {session: false}), firmwares);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next({status: 404, message: 'apiMisuse', devMessage: devMsgs['not_found']});
});

app.use(function(err, req, res, next) {
  devMsg = err.devMessage || devMsgs['error'];
  msg = err.message || 'err';
  console.log(err);
  res.status(err.status || 500).send({'message': req.t(msg), 'devMessage': devMsg}).end();
});


var server = app.listen(envConfigs().appPort, function(){
  var host = server.address().address;
  var port = server.address().port;
  console.log(moment().format('YYYY-MM-DD H:mm:ss') + ' [server starts]');
  console.log('app listening at http://%s:%s', host, port);
});

module.exports = app;
