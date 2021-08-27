var path = require('path');
module.exports = function() {
  var envConfigs;
  envConfigs = require(path.join(__dirname, 'configs.json'));
  return envConfigs;
} 
