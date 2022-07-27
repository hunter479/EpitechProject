global.id_token = "auth0|5e5a8faab3712c0cb68bf775";
global.username = "Otyne";
global.url = "http://10.106.1.237:3000";

global.myServices = [
    {
      Service1: "Action example",
      Service2: "Reaction example",
      Account1: "Account 1",
      Account2: "Account 2",
      Action1: "example",
      Action2: "example",
    },
];

global.services1 = [
  "None",
];

global.services2 = [
  "None",
];

global.needAccount1 = true;
global.needAccount2 = true;

global.account1 = [
  "None",
];

global.account2 = [
  "None",
];

global.action1 = [
  "None",
];

global.action2 = [
  "None",
];

global.fields1 = [];
global.fields2 = [];

global.offline = [
  {
    "actions": [
      {
        "id": "postImage",
        "name": "When a new image is uploaded...",
      },
      {
        "id": "favImage",
        "name": "When a new image has been add to favorites...",
      },
      {
        "id": "newCom",
        "name": "When a new commentary has been posted...",
      },
    ],
    "connection_needed": true,
    "name": "Imgur",
    "reactions": [],
  },
  {
    "actions": [],
    "connection_needed": true,
    "name": "Spotify",
    "reactions": [
      {
        "id": "nextTrack",
        "name": "Play the next track on the queue",
      },
      {
        "id": "pauseTrack",
        "name": "Pause or play the current track",
      },
    ],
  },
  {
    "actions": [
      {
        "fields": [
          {
            "key": "usercode",
            "label": "code of the user",
          },
        ],
        "id": "lastLogOff",
        "name": "Last time the user has lag off...",
      },
    ],
    "connection_needed": false,
    "name": "Steam",
    "reactions": [],
  },
  {
    "actions": [
      {
        "fields": [
          {
            "key": "path",
            "label": "Path to the project (Username/name_of_the_project)",
          },
        ],
        "id": "updateCommit",
        "name": "When a commit has been send on the branch Master...",
      },
    ],
    "connection_needed": true,
    "name": "Gitlab",
    "reactions": [],
  },
  {
    "actions": [
      {
        "fields": [
          {
            "key": "city",
            "label": "Name of the city",
          },
          {
            "key": "sign",
            "label": "1 mean sup / 0 mean inf",
          },
          {
            "key": "temp",
            "label": "Temperature in celsius",
          },
        ],
        "id": "temperatureUpdate",
        "name": "When the temperature has reach a threshold...",
      },
      {
        "fields": [
          {
            "key": "city",
            "label": "Name of the city",
          },
          {
            "key": "sign",
            "label": "1 mean sup / 0 mean inf",
          },
          {
            "key": "wind",
            "label": "Speed of the wind in m/s",
          },
        ],
        "id": "windSpeed",
        "name": "When the speed has reach a threshold...",
      },
    ],
    "connection_needed": false,
    "name": "Weather",
    "reactions": [],
  },
  {
    "actions": [
      {
        "id": "newMail",
        "name": "When you receive a mail...",
      },
    ],
    "connection_needed": true,
    "name": "Microsoft",
    "reactions": [],
  },
  {
    "actions": [],
    "connection_needed": true,
    "name": "Yammer",
    "reactions": [
      {
        "fields": [
          {
            "key": "groupId",
            "label": "Enter a group id",
            "placeholder": "Groupe Id",
          },
          {
            "key": "replyId",
            "label": "Enter a message id",
            "placeholder": "Message Id",
          },
          {
            "key": "body",
            "label": "Enter your message",
            "placeholder": "Your message",
          },
        ],
        "id": "postMessage",
        "name": "Post a message or reply",
      },
    ],
  },
  {
    "actions": [
      {
        "id": "number_of_friends",
        "name": "The number of friends have changed...",
      },
      {
        "id": "get_last_post_timestamp",
        "name": "The user made a new post...",
      },
      {
        "id": "get_last_tagged_picture",
        "name": "When the user has been tagged on a picture...",
      },
      {
        "id": "get_last_uploaded_picture",
        "name": "When the user upload a new picture...",
      },
    ],
    "connection_needed": true,
    "name": "Facebook",
    "reactions": [],
  },
  {
    "actions": [
      {
        "fields": [
          {
            "key": "autologin",
            "label": "Auto login token (auth-...)",
          },
        ],
        "id": "newNotif",
        "name": "When a new notification has been received...",
      },
      {
        "fields": [
          {
            "key": "autologin",
            "label": "Auto login token (auth-...)",
          },
          {
            "key": "email",
            "label": "mail of the student",
          },
        ],
        "id": "updateCredits",
        "name": "When a student's credits has been updated...",
      },
      {
        "fields": [
          {
            "key": "autologin",
            "label": "Auto login token (auth-...)",
          },
          {
            "key": "email",
            "label": "mail of the student",
          },
          {
            "key": "time",
            "label": "minimum time (in hour)",
          },
        ],
        "id": "updateNetsoul",
        "name": "When the netsoul's logs are under a certain time",
      },
    ],
    "connection_needed": false,
    "name": "Intra",
    "reactions": [],
  },
  {
    "actions": [],
    "connection_needed": false,
    "name": "Gmail",
    "reactions": [
      {
        "fields": [
          {
            "key": "receiver",
            "label": "Receiver",
          },
          {
            "key": "content",
            "label": "Text",
          },
        ],
        "id": "sendMail",
        "name": "Sending a mail to...",
      },
    ],
  },
  {
    "actions": [
      {
        "fields": [
          {
            "key": "query",
            "label": "Searching string",
          },
        ],
        "id": "SearchTweet",
        "name": "Search for new tweets",
      },
    ],
    "connection_needed": true,
    "name": "Twitter",
    "reactions": [
      {
        "fields": [
          {
            "key": "status",
            "label": "Status",
          },
        ],
        "id": "PostStatus",
        "name": "Post a new tweet",
      },
      {
        "fields": [
          {
            "key": "id",
            "label": "Tweet Id put [°_°] for a surprise",
          },
        ],
        "id": "Retweet",
        "name": "Retweet a status",
      },
    ],
  },
];