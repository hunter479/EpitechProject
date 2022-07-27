var fetch = require('node-fetch');
var Form = require('form-data');

let getInfos = async function(serviceName, code) {
    let user;

    try {
        let func = require('./connections/' + serviceName + 'Auth.js');
        return (func(code, serviceName))
    } catch (err) {
        console.log('Could not find file:', './connections/' + serviceName + 'Auth.js');
        return (user);
    }
}

module.exports = getInfos;