var express = require('express');
var router = express.Router();

router.get('/', async (req, res) => {
    all_services = [
        {
            name: "Imgur",
            connection_needed: true,
            actions: [{name: "When a new image is uploaded...", id: "postImage"}, {name: "When a new image has been add to favorites...", id: "favImage"}, {name: "When a new commentary has been posted...", id: "newCom"}],
            reactions: []
        },
        {
            name: "Spotify",
            connection_needed: true,
            actions: [],
            reactions: [{name: "Play the next track on the queue", id: "nextTrack"}, {name: "Pause or play the current track", id: "pauseTrack"}]
        },
        {
            name: "Steam",
            connection_needed: false,
            actions: [{name: "Last time the user has lag off...", id: "lastLogOff", fields: [{key: 'usercode', label: 'code of the user'}]}],
            reactions: []
        },
        {
            name: "Gitlab",
            connection_needed: true,
            actions: [{name: "When a commit has been send on the branch Master...", id: "updateCommit", fields: [{key: 'path', label: "Path to the project (Username/name_of_the_project)"}]}],
            reactions: []
        },
        {
            name: "Weather",
            connection_needed: false,
            actions: [{name: "When the temperature has reach a threshold...", id: "temperatureUpdate", fields: [{key: 'city', label: "Name of the city"}, {key: 'sign', label: "1 mean sup / 0 mean inf"}, {key: 'temp', label: "Temperature in celsius"}]}, {name: "When the speed has reach a threshold...", id: "windSpeed", fields: [{key: 'city', label: "Name of the city"}, {key: 'sign', label: "1 mean sup / 0 mean inf"}, {key: 'wind', label: "Speed of the wind in m/s"}]}],
            reactions: []
        },
        {
            name: "Microsoft",
            connection_needed: true,
            actions: [{name: "When you receive a mail...", id: "newMail"}],
            reactions: []
        },
        {
            name: "Yammer",
            connection_needed: true,
            actions: [],
            reactions: [{name: "Post a message or reply", id: "postMessage", fields: [{key: "groupId", label: "Enter a group id", placeholder: 'Groupe Id'}, {key: "replyId", label: "Enter a message id", placeholder: "Message Id"}, {key: "body", label: "Enter your message", placeholder: "Your message"}]}]
        },
        {
            name: "Facebook",
            connection_needed: true,
            actions: [{name: "The number of friends have changed...", id: "number_of_friends"}, {name: "The user made a new post...", id: "get_last_post_timestamp"}, {name: "When the user has been tagged on a picture...", id: "get_last_tagged_picture"}, {name: "When the user upload a new picture...", id: "get_last_uploaded_picture"}],
            reactions: []
        },
        {
            name: "Intra",
            connection_needed: false,
            actions: [{name: "When a new notification has been received...", id: "newNotif", fields: [{key: 'autologin', label: "Auto login token (auth-...)"}]}, {name: "When a student's credits has been updated...", id: "updateCredits", fields: [{key: "autologin", label: "Auto login token (auth-...)"}, {key: "email", label: "mail of the student"}]}, {name: "When the netsoul's logs are under a certain time", id: "updateNetsoul", fields: [{key: 'autologin', label: "Auto login token (auth-...)"}, {key: 'email', label: "mail of the student"}, {key: 'time', label: "minimum time (in hour)"}]}],
            reactions: []
        },
        {
            name: "Gmail",
            connection_needed: false,
            actions: [],
            reactions: [{name: "Sending a mail to...", id: "sendMail", fields: [{key: 'receiver', label: "Receiver"}, {key: 'content', label: "Text"}]}]
        },
        {
            name: "Twitter",
            connection_needed: true,
            actions: [{name: "Search for new tweets", id: "SearchTweet", fields: [{key: 'query', label: 'Searching string'}]}],
            reactions: [{name: "Post a new tweet", id: "PostStatus", fields: [{key: 'status', label: "Status"}]}, {name: "Retweet a status", id:"Retweet", fields: [{key: 'id', label: "Tweet Id put [°_°] for a surprise"}]}]
        }

    ];
    res.status(200).json(all_services);
});

module.exports = router