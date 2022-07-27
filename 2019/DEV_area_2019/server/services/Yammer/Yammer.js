var fetch = require('node-fetch');
var FormData = require('form-data');

let yammer = function (superClass) {
    return class Yammer extends superClass {
    
        ask(user, auto_index, co_info, co_index) {
            throw new Error('You need to implements ask method to your class');
        }
    };
}

module.exports = yammer;