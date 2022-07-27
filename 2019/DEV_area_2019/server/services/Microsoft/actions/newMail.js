var fetch = require('node-fetch');
var miscrosoft = require('../Microsoft');
const EventEmitter = require("events").EventEmitter;

class newMail extends miscrosoft(EventEmitter) {
    constructor() {
        super();
    }

    ask(user, auto_index, co_info, co_index) {
        var myHeaders = new fetch.Headers();
        let acToken = co_info.access_token.replace('\n', '');
        console.log((acToken));
        myHeaders.append("Authorization", acToken);
        console.log(myHeaders);
        var requestOptions = {
            method: 'GET',
            headers: myHeaders,
            redirect: 'follow'
        };
        fetch("https://graph.microsoft.com/v1.0/me/messages", requestOptions)
        .then(response => response.text())
        .then(async(result) => {
            var parsed = JSON.parse(result);
            if (!parsed.error) {
                console.log("OK mails");
                if (!parsed || !parsed.value || !parsed.value[0])
                    return false;
                let storedDate = new Date(user.automation[auto_index].action.id);
                let newDate = new Date(parsed.value[0].receivedDateTime);
                console.log('old', storedDate.toString(), 'new', newDate.toString())
                if (user.automation[auto_index].action.id === undefined || user.automation[auto_index].action.id === "" || storedDate.getTime() < newDate.getTime()) {
                    console.log("ADDING OR UPDATING LASTEST MAIL ID");
                    user.automation[auto_index].action.id = parsed.value[0].receivedDateTime;
                    console.log('[MICROSOFT CHECK TOKEN]', user.connection[co_index]);
                    await user.save();
                    this.emit("reaction", user, auto_index, co_info, co_index);
                    return true;
                }
                console.log('No new mails');
                return false;
            } else if (parsed.error) {
                this.gen_new_ref_token(user, auto_index, co_info, co_index);
                return true;
            } else {
                console.log("STATUS: " + parsed.status);
                return false;
            }
        })
        .catch(error => console.log('error', error));
    }
};

module.exports = newMail;