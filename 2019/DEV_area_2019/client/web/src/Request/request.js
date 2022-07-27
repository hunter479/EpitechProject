import axios from 'axios'
import queryString from 'query-string'
import oauth2 from "../oauth2"

// export default class Request extends React.Component {
    const url = "https://www.area.com:8080"
    export const addNewUser = async (profile) => {
        const response = await axios.post(
            url + "/register",
            { id: profile.sub,
            username: profile.name },
            { headers: { 'Content-Type': 'application/json' } }
        ).catch((err) => {
            console.log("CATCHED ERROR:", err);
        })
        window.location = "/";
        console.log(response.data)
    }

    export const getUserAutomations = async () => {
        var userId = localStorage.getItem("user_id");
        const response =
            await axios.get(url + "/user/" + userId);
        // console.log(response);
        return response.data;
    }

    export const getAccounts = async (serviceName) => {
        var userId = localStorage.getItem("user_id");
        const response =
            await axios.get(url + "/connection/" + userId + "/" + serviceName)
        // console.log(response.data);
        return (response.data);
    }

    export const getServices = async () => {
        const response =
        await axios.get(url + "/service")
        // console.log("response = ",response);
        return (response.data);
    }

    export const getImgurAccess = async (values) => {
        const response = await axios.post(
            url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
                name: "Imgur",
                code: -42,
                access_token: values.access_token,
                refresh_token: values.refresh_token,
                username: values.account_username
            }
        ).catch(err => {
            window.close();
            console.log(err);
        })
        handleResponse(response);
    }

    export const getSpotifyAccess = async (_code) => {
        const response = await axios.post(
            url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
                name: "Spotify",
                code: _code,
            }
        ).catch(err => {
            window.close();
            console.log(err);
        })
        handleResponse(response);
    }

    export const getGitlabAccess = async (_code) => {
        console.log(localStorage.getItem("user_id"));
        const response = await axios.post(
            url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
            name: "Gitlab",
            code: _code,
            }
        ).catch(err => {
            window.close();
            console.log(err);
        })
        handleResponse(response);
    }

    export const getMicrosoftAccess = async (_code) => {
        const response = await axios.post(
            url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
            name: "Microsoft",
            code: _code,
            }
        ).catch(err => {
            window.close();
            console.log(err);
        })
        handleResponse(response);
    }

    export const getFacebookAccess = async (values) => {
        const response = await axios.post(
            url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
            name: "Facebook",
            code: values.access_token,
            }
        ).catch(err => {
            window.close();
            console.log(err);
        })
        handleResponse(response);
    }

    export const getYammerAccess = async (values) => {
        console.log("YAMMER");
        const response = await axios.post(
            url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
                name: "Yammer",
                code: values.code
            }
        ).catch(err => {
            window.close();
            console.log(err);
        })
        handleResponse(response);
    }

    export const addAutomation = async (props) => {
        console.log(props);
        var newAutomation = JSON.stringify({
            automation: {
                action: {
                    id: "",
                    data: JSON.stringify(props.stateNewAutomation.actionField),
                    account: props.stateNewAutomation.firstAccount,
                    service: props.stateNewAutomation.firstService.name,
                    trigger: props.stateNewAutomation.action.id,
                    name: props.stateNewAutomation.action.name
                },
                reaction: {
                    data: JSON.stringify(props.stateNewAutomation.reactionField),
                    account: props.stateNewAutomation.secondAccount,
                    service: props.stateNewAutomation.secondService.name,
                    trigger: props.stateNewAutomation.reaction.id,
                    name: props.stateNewAutomation.reaction.name
                }
            }
        });
        console.log("la", newAutomation);
        await axios.post(
            url + "/user/automation/" + localStorage.getItem("user_id"),
            {
                auto: newAutomation
            }
        )
    }

    export const deleteAutomation = async (index) => {
        var userId = localStorage.getItem("user_id");
        await axios.delete(
            url + "/user/automation/delete/" + userId + "?auto_id=" + index, 
        )
    }

    const handleResponse = (response) => {
        if (response.status === 201) {
            localStorage.setItem("isRedirectionOver", "true");
            window.close();
        } else if (response.status === 409) {
            window.close();
        }
    }

    export const prepareTwitterAccess = async () => {
        console.log(url);
        await axios.get(
            url + "/connection/twitter",
        ).then(res => {
            const values = queryString.parse(res.data)
            window.open(oauth2.twitter + values.oauth_token);
        })
    }

    export const getTwitterAccess = async (values) => {
        console.log(values.oauth_token + ":" + values.oauth_verifier);
        const response = await axios.post(
            url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
            name: "Twitter",
            code: values.oauth_token + ":" + values.oauth_verifier,
            }
        ).catch(err => {
            window.close();
            console.log(err);
        })
        handleResponse(response);
    }