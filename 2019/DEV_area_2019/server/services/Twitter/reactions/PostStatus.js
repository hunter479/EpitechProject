var Twitter = require('../Twitter');
const EventEmitter = require("events").EventEmitter;

class PostStatus extends Twitter(EventEmitter) {
    ask(user, auto_index, co_info, co_index) {
        const client = this.getClient;
        var data = JSON.parse(user.automation[auto_index].reaction.data);
        console.log('[TWITTER POST] ', data);
        client(co_info.access_token, co_info.refresh_token).post('statuses/update', {status: '[=>] ' +  data.status}).then((err, tweet, response) => {
            if (err) {
                client(co_info.access_token, co_info.refresh_token).post('statuses/update', {status: '[->] ' +  data.status},  function(error, tweet, response) {
                    if (error) console.error(error);
                    console.log('[TWITTER POST] TWEET POSTED', tweet);
                });
            } else {
                console.log('[TWITTER POST] TWEET POSTED', tweet);
            }
        })
    }
}

module.exports = PostStatus;