var Twitter = require('../Twitter');
const EventEmitter = require("events").EventEmitter;

class SearchTweet extends Twitter(EventEmitter) {
    ask(user, auto_index, co_info, co_index) {
        console.log('[TWITTER SeachTweet] SEARCHER TWEET', co_info);
        var data = JSON.parse(user.automation[auto_index].action.data);
        console.log('[TWITTER SeachTweet] data = ', data);
        this.getClient(co_info.access_token, co_info.refresh_token).get('search/tweets.json', {q: data.query}).then( async (tweet) => {
            console.log('[TWITTER SeachTweet] IN THE REQUEST OF SEARCH', user.automation[auto_index].action.id);
            if (tweet) {
                let newId = new Date(tweet.statuses[0].created_at);
                let oldId = new Date(user.automation[auto_index].action.id);
                console.log('[TWITTER SeachTweet] Current comparison new vs old', newId.toString(), oldId.toString());
                if (user.automation[auto_index].action.id === "" || newId.getTime() > oldId.getTime()) {
                    console.log('[TWITTER SeachTweet] new id is ', newId.toString());
                    user.automation[auto_index].action.id = newId.toString();
                    let data = JSON.parse(user.automation[auto_index].reaction.data);
                    console.log('[TWITTER SeachTweet] old reaction\'s data', data);
                    data.interaction = tweet.statuses[0].id_str;
                    console.log('[TWITTER SeachTweet] new reaction\'s data', data);
                    user.automation[auto_index].reaction.data = JSON.stringify(data);
                    await user.save();
                    this.emit('reaction', user, auto_index, co_info, co_index);
                } else {
                    console.log('[TWITTER SeachTweet] No reaction');
                }
            }
        });
        console.log('[TWITTER SeachTweet] Finished');
    }
}

module.exports = SearchTweet