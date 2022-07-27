var User = require('../schema/schema_user');
var mongoose = require('mongoose');

let no_account = "None";
var testValue;

function do_action(user, index) {
    if (user.automation[index].action.account === no_account) {
        testValue = action.ask(user, index, undefined, -42);
    } else {
        user.connections.forEach(act_co => {
            if (act_co.name === user.automation[index].action.service) {
                var account_number = 0;
                for (account_number = 0; account_number < act_co.info.length && user.automation[index].action.account !== act_co.info[account_number].username; account_number += 1);
                testValue = action.ask(user, index, act_co.info[account_number], account_number);
            }
        })
    }
}

async function automation() {
    allUsers = await User.find();
    allUsers.forEach(user => {
        console.log("USER:", user);
        for (index in user.automation) {
            action = new (require('./' + user.automation[index].action.service + '/actions/' + user.automation[index].action.trigger + '.js'))();
            do_action(user, index);
            try {
                action.on("reaction", function t(user, auto_index, co_info, co_index) {
                if (user.automation[auto_index].reaction.service !== undefined && user.automation[auto_index].reaction.trigger !== undefined) {
                    reaction = new (require('./' + user.automation[auto_index].reaction.service + '/reactions/' + user.automation[auto_index].reaction.trigger))();
                    if (user.automation[auto_index].reaction.account === no_account) {
                        reaction.ask(user, auto_index, undefined, -42);
                    } else {
                        user.connections.forEach(react_co => {
                            if (react_co.name === user.automation[auto_index].reaction.service) {
                                var account_number = 0;
                                for (account_number = 0; account_number < react_co.info.length && user.automation[auto_index].reaction.account !== react_co.info[account_number].username; account_number += 1);
                                reaction.ask(user, auto_index, react_co.info[account_number], account_number);
                            }
                        })
                    }
                }
                })
            } catch (err) {
                console.log("ERROR CATCHED ON EVENTS EMITION.");
            }
        }
    })
}

module.exports = automation;
