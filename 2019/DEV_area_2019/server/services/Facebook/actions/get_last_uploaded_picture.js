var fetch = require('node-fetch');
var Facebook = require('./Facebook_class');
const EventEmitter = require("events").EventEmitter;

class get_last_last_uploaded_picture extends Facebook(EventEmitter) {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        fetch("https://graph.facebook.com/v6.0/me/photos/uploaded?fields=images&access_token=" + co_info.refresh_token)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            if (parsed.error) {
                this.gen_new_ref_token(user, auto_index, co_info, co_index);
                return true;
            } else {
                if (user.automation[auto_index].action.id === undefined || user.automation[auto_index].action.id != parsed.data[0].images[0].source) {
                    user.automation[auto_index].action.id = parsed.data[0].images[0].source;
                    await user.save();
                    this.emit("reaction", user, auto_index, co_info, co_index);
                }
                return false;
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = get_last_last_uploaded_picture;