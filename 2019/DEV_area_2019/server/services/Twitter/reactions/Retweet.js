var Twitter = require('../Twitter');
const EventEmitter = require("events").EventEmitter;

class Retweet extends Twitter(EventEmitter) {
    ask(user, auto_index, co_info, co_index) {
        console.log('[TWITTER RT] IN RETWEET COMP')
        let data = JSON.parse(user.automation[auto_index].reaction.data);
        let id = (data.id === '°_°') ? data.interaction : data.id;
        console.log('[TWITTER RT] id', id);
        this.getClient(co_info.access_token, co_info.refresh_token).post('statuses/retweet/' + id + '.json', '').then( res => {
            if(res) console.log('[TWITTER RT] tweet', res);
            else console.log('[TWITTER RT ERROR]', res);
        });
    }
}

module.exports = Retweet;