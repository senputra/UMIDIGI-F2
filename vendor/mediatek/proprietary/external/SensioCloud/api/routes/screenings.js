var express = require('express');
var router = express.Router({mergeParams: true});
var dao = require('../dao/screeningsDao');

var devMsgs = require('../statics/developerMessages').screeningsMsgs;

router.get('/', function(req, res, next) {
  if(!req.user.isPaidUser) {
    return next({status: 403, message: 'screeningPermissionDenied', devMessage: devMsgs['get/']['permission_deinied']});
  }
  if(typeof req.params.profileId === 'undefined' || req.params.profileId === null || isNaN(parseInt(req.params.profileId))) {
    return next({status: 400, message: 'apiMisuse', devMessage: devMsgs['get/']['invalid_pid']});
  }
  var limit = 100;
  var offset = 0;
  if(typeof req.query.limit !== 'undefined' && !isNaN(parseInt(req.query.limit))) {
    limit = parseInt(req.query.limit);
  }
  if(typeof req.query.offset !== 'undefined' && !isNaN(parseInt(req.query.offset))) {
    offset = parseInt(req.query.offset);
  }
  dao.retrieveScreenings(req.user.userId, req.params.profileId, limit, offset, function(err, result) {
    if(err) {
      return next(err);
    }
    for(var i = 0; i < result.rows.length; i++) {
      if(result.rows[i].risklevel > 2) {
        result.rows[i].risklevel = 2;
      }
    }
    return res.status(200).send({
      "data": result.rows
    });
  });
});

module.exports = router;
