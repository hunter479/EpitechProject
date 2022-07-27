var fetch = require('node-fetch');
var Facebook = require('./Facebook_class');
const EventEmitter = require("events").EventEmitter;

class number_of_friends extends Facebook(EventEmitter) {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        fetch("https://graph.facebook.com/v6.0/me/friends?access_token=" + co_info.refresh_token)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            if (parsed.error) {
                this.gen_new_ref_token(user, auto_index, co_info, co_index);
                return true;
            await user.save();
        } else {
                user.automation[auto_index].action.id = parsed.summary.total_count;
                await user.save();
                this.emit("reaction", user, auto_index, co_info, co_index);
                return false;
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = number_of_friends;