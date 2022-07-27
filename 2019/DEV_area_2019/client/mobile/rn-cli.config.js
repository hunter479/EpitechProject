const path = require('path');

module.exports = {
  
  // For React Native version 0.57
   projectRoot: path.resolve(__dirname),
  // tell the builder to also look in the shared directory for imports
  
  // // Prior to React Native verision 0.57
  // getProjectRoots() {
  //   return [
  //     __dirname,
  //     path.join(__dirname, 'node_modules'),
  //     // tell the builder to also look in the shared directory for imports
  //     path.join(__dirname, '../shared'),
  //   ];
  // }
};