var fetch = require('node-fetch');
var form = require('form-data');
var yammer = require('../Yammer');
const EventEmitter = require("events").EventEmitter;

data = {
    replyId: Number,
    groupId: Number,
    body: String,

}

class PostMessage extends yammer(EventEmitter) {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();
        let acToken = co_info.access_token.replace('\n', '');
        myHeaders.append("Authorization", "Bearer " + acToken);
        let data = JSON.parse(user.automation[auto_index].reaction.data);
        console.log(data);
        let body = new form();
        body.append('body', data.body);
        (data.groupId) ? body.append('group_id', data.groupId) : body.append("reply_id", data.replyId);
        let requestOptions = {
            method: 'POST',
            headers: myHeaders,
            body: body,
            redirect: 'follow'
        };
        console.log('DATA', user.automation[auto_index].reaction.data);
        fetch("https://www.yammer.com/api/v1/messages.json", requestOptions)
        .then(response => response.text())
        .then(async(res) => {
            var parsed = JSON.parse(res);
            console.log(parsed);
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = PostMessage;