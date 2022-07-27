# ARea

ARea is a Web and mobile application used for service automation.

## Installation

You must install :

```Docker CE
You must install the version of docker community engine version 19.03.6 or more
https://docs.docker.com/install/linux/docker-ce/fedora/
```
```Docker Compose
You must install the version of docker-compose version 1.24.1 or more
https://docs.docker.com/compose/install/
```

You must add this line in your "/etc/hosts"
```"/etc/hosts"
127.0.0.1   www.area.com
```

## Run the app

```bash
docker-compose up
```

```Certificat
You must add this file : "certificate/certs/area-ca.crt" in your browser.
The file is generated once you launched the docker-compose up. The container ca.area will generate it.
Google Chrome: https://support.securly.com/hc/en-us/articles/206081828-How-to-manually-install-the-Securly-SSL-certificate-in-Chrome
Firefox: https://support.securly.com/hc/en-us/articles/360008547993-How-to-Install-Securly-s-SSL-Certificate-in-Firefox-on-Windows
```

```Reset / Remove
In order to reset all the project, you must remove: "sudo rm -rdf certificate/certs".
And use this command: "docker-compose down --rmi local -v"
```

## Docker-compose container

``` Access
serveur : 8080 is the api.
client_web : 8081 is the project itself.
mongo_ui.area : 8083 is the web interface to manage the DataBase.
portainer.area : 9000 is the service to manage all the container in on your machines.
```

## Run the tests

```bash
npm server/tests
```

# ARea API

The REST API of the ARea app is described below.

## Register a user

__Request__

`POST /register/`

```bash
curl --location --request POST 'www.area.com:8080/register' \
--header 'Content-Type: application/x-www-form-urlencoded' \
--data-urlencode 'id=google-oauth2|108508345733224776544' \
--data-urlencode 'username=arthur malardé'
```

__Response__

```bash
status: 200 | user: {
    "id": "google-oauth2|108508345733224776544",
    "username": "arthur malardé",
    "connections": [],
    "automation": [],
}
```

## Get user informations

__Request__ 

`GET /user/:id`

```bash
curl --location --request GET 'https://www.area.com:8080/user/google-oauth2|108508345733224776544'
```

__Response__

```bash
Status: 200 | user: {
	"id": "google-oauth2|108508345733224776544",
	"username": "arthur malardé",
	"connections": [],
	"automation": [],
}
```

## Delete a user

__Request__

`DELETE /user/delete/:id`

```bash
curl --location --request DELETE 'https://www.area.com:8080/user/delete/google-oauth2|108508345733224776544'
```

__Response__

```bash
Status 200 | User google-oauth2|108508345733224776544 deleted succesfully.
```

## Add an automation

__Request__

`POST /user/automation/:id`

```bash
curl --location --request POST 'www.area.com:8080/user/automation/google-oauth2|108508345733224776544' \
--header 'Content-Type: application/x-www-form-urlencoded' \
--data-urlencode 'auto={"automation":{"action":{"id":"","data":"","account":0,"service":"Imgur","trigger":"post_image"},"reaction":{data":"bob","account":0,"service":"Spotify","trigger":"next_track"}}}' \
--data-urlencode 'index=0'
```

__Response__

```bash
Status: 200 | user: {
    "id": "google-oauth2|108508345733224776544",
    "username": "arthur malardé",
    "connections": [],
    "automation": [
        {
            "_id": "5e53c86d2028c5229d65a326",
            "action": {
                "id": "",
                "data": "",
                "account": "0",
                "service": "Imgur",
                "trigger": "post_image"
            },
            "reaction": {
                "data": "bob",
                "account": "0",
                "service": "Spotify",
                "trigger": "next_track"
            }
        }
    ],
}
```

## Delete an automation

__Request__

`DELETE /user/automation/:id`

```bash
curl --location --request DELETE 'www.area.com:8080/user/automation/delete/auth0|5e53c5fe5279a70d0cd16f24?auto_id=0' \
--header 'Content-Type: application/x-www-form-urlencoded'
```

__Response__

```bash
Status: 200 | "Automation 0 has been successfully deleted."
```

## Get a list of available services

__Request__

`GET /service/`

```bash
curl --location --request GET 'www.area.com:8080/service'
```

__Response__

```bash
Status: 200 | list_of_services: [
    {
        "name": "Weather",
        "connection_needed": false,
        "actions": [
            {
                "name": "When the temperature has reach a threshold...",
                "id": "temperatureUpdate",
                "fields": [
                    "Name of the city",
                    "suporinf",
                    "Temperature in celsius"
                ]
            },
        ],
        "reactions": []
    },
    ...
]
```

## Retrieve authentication of a user

__Request__

`POST /connection/add_service/`

For a service giving an __authorization code__, the query should look like that:

```bash
curl --location --request POST 'www.area.com:8080/connection/add_service' \
--header 'Content-Type: application/x-www-form-urlencoded' \
--data-urlencode 'id=google-oauth2|108508345733224776544' \
--data-urlencode 'name=Spotify' \
--data-urlencode 'code=authorization_code_of_the_service'
```

Else if the service give ___no authorization code___ and give an __access_token__ and a __refresh_token__ instead, then the query will be:

```bash
curl --location --request POST 'www.area.com:8080/connection/add_service' \
--header 'Content-Type: application/x-www-form-urlencoded' \
--data-urlencode 'id=google-oauth2|108508345733224776544' \
--data-urlencode 'name=Spotify' \
--data-urlencode 'code=-42' \
--data-urlencode 'access_token=access_token_of_the_service' \
--data-urlencode 'refresh_token=refresh_token_of_the_service' \
--data-urlencode 'username=empty_or_with_username'
```

The code value must be set to __-42__ if the choosen service don't use an authorization code.

__Response__

```bash
Status: 200 | "Connetion added to the list."
```

## Retrieves a user's service connection information

__Request__

`GET /connection/:id/:service`

```bash
curl --location --request GET 'www.area.com:8080/connection/google-oauth2|108508345733224776544/Spotify'
```

__Response__

```bash
{
    "info": [
        {
        	"access_token": "access_token_of_the_service",
        	"refresh_token": "refresh_token_of_the_service",
        	"username": "username_of_the_account"
        }
    ],
    "name": "Spotify"
}
```




## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[Tek4U](https://tek4u.re/)
+
Nicolas AH-LEUNG
