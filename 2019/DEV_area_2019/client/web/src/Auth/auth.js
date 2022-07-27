import auth0 from 'auth0-js';
import { addNewUser } from "../Request/request"

export default class Auth {
    // Please use your own credentials here

    auth0 = new auth0.WebAuth({
        domain: "dev-6yzqhmdk.eu.auth0.com",
        clientID: '5T2Ud0sZTyFtckxwMZzBJ8YG5HiMLaVm',
        audience: 'https://dev-6yzqhmdk.eu.auth0.com/userinfo',
        redirectUri: 'https://www.area.com:8081/callback',
        responseType: 'token id_token',
        scope: 'openid profile'
    });

    login = () => {
        this.auth0.authorize();
    }

    getProfile = () => {
        var tmp = localStorage.getItem('profile');
        return JSON.parse(tmp);
    }

    // parses the result after authentication from URL hash
    handleAuthentication = () => {
        this.auth0.parseHash((err, authResult) => {
            if (authResult && authResult.accessToken && authResult.idToken) {
                this.setSession(authResult);
                // window.location = "/";
                console.log("AUTHRESULT1", authResult.idTokenPayload);
                console.log("AUTHRESULT2", authResult.idTokenPayload.email);
                addNewUser(authResult.idTokenPayload);
            } else if (err) {
                window.location = "/";
                console.log("ERROR:", err);
            } else
                console.log("BRUH");
        });
    }

    // Sets user details in localStorage
    setSession = (authResult) => {
        console.log("Set Session", authResult);
        // Set the time that the access token will expire at
        let expiresAt = JSON.stringify((authResult.expiresIn * 1000) + new Date().getTime());
        localStorage.setItem('access_token', authResult.accessToken);
        localStorage.setItem('id_token', authResult.idToken);
        localStorage.setItem('expires_at', expiresAt);
        localStorage.setItem('user_id', authResult.idTokenPayload.sub);
        localStorage.setItem('profile', JSON.stringify(authResult.idTokenPayload));
        console.log(authResult.idTokenPayload);
        // navigate to the home route
        // history.replace('/home');
    }

    // removes user details from localStorage
    logout = () => {
        console.log("Clear Session");
        // Clear access token and ID token from local storage
        localStorage.removeItem('access_token');
        localStorage.removeItem('id_token');
        localStorage.removeItem('expires_at');
        localStorage.removeItem('profile');
        // navigate to the home route
        this.auth0.logout({
            returnTo: 'https://www.area.com:8081',
            clientID: '5T2Ud0sZTyFtckxwMZzBJ8YG5HiMLaVm',
        });
        // history.replace('/');
    }

    // checks if the user is authenticated
    isAuthenticated = () => {
        // Check whether the current time is past the
        // access token's expiry time
        let expiresAt = JSON.parse(localStorage.getItem('expires_at'));
        return new Date().getTime() < expiresAt;
    }

    setMetadata = (obj) => {
        console.log("tmp: ", obj);

        console.log(this.test0.patchUserMetadata(localStorage.getItem('user_id'), obj, function(err, result) {
            if (err)
                console.log(err);
            console.log(result);
        }));
    }
}