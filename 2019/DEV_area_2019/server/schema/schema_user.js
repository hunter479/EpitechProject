var mongoose = require('mongoose');

const schema = mongoose.Schema({
    id: {
        type: String,
        unique: true
    },
    connections: [{
        name: String, // Name of the service
        info: [{
            access_token: String,
            refresh_token: String,
            username: String
        }]
    }],
    automation: [{
        action: {
            id: String,
            data: String,
            account: String,
            service: String, //type of the service
            trigger: String,
            name: String,
        },
        reaction: {
            data: String,
            account: String,
            service: String,
            trigger: String,
            name: String
        }
    }],
    username: {
        type: String,
        unique: true
    },
});

module.exports = mongoose.model('users', schema);