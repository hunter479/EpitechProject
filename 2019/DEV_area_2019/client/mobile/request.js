import axios from 'axios'
import './global.js'

    export const addNewUser = async () => {
        const response = await axios.post(
            global.url + "/register",
            { id: global.id_token,
            username: global.username },
            { headers: { 'Content-Type': 'application/json' } }
        ).catch((err) => {
            console.log("CATCHED ERROR:", err);
        })
        window.location = "/";
        console.log(response.data)
    }

    export const getUserAutomations = async () => {
        const response =
            await axios.get(global.url + "/user/" + global.id_token);
        console.log(response);
        return response.data;
    }

    export const getAccounts = async (serviceName) => {
        const response =
            await axios.get(global.url + "/connection/" + global.id_token + "/" + serviceName)
        return (response.data);
    }

    export const getServices = async () => {
        console.log(global.url + "/service");
        const response = await axios.get(global.url + "/service");
        return (response.data);
    }

    export const getImgurAccess = async (values) => {
        const response = await axios.post(
            global.url + "/connection/add_service",
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
            global.url + "/connection/add_service",
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
            global.url + "/connection/add_service",
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
            global.url + "/connection/add_service",
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
            global.url + "/connection/add_service",
            { id: localStorage.getItem("user_id"),
            name: "Facebook",
            access_token: values.access_token
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
                    data: JSON.stringify(props.Fields1),
                    account: props.Account1,
                    service: props.Service1,
                    trigger: props.Action1,
                    name: props.ActionName1,
                },
                reaction: {
                    data: JSON.stringify(props.Fields2),
                    account: props.Account2,
                    service: props.Service2,
                    trigger: props.Action2,
                    name: props.ActionName2
                }
            }
        });
        console.log("la", newAutomation);
        const response = await axios.post(
            global.url + "/user/automation/" + global.id_token,
            {
                auto: newAutomation
            }
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
