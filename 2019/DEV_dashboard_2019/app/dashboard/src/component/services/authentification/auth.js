import auth0 from 'auth0-js';
import history from './history';

export default class Auth {
    auth0 = new auth0.WebAuth({
        domain: 'dev-03c86qvs.auth0.com',
        clientID: 'voKo3pjbx4HaKSvTJhK5iILU3skVyon7',
        redirectUri: 'http://localhost:8080/callback',
        audience: 'https://dev-03c86qvs.auth0.com/userinfo',
        responseType: 'token id_token',
        scope: 'openid'
    });
    login = () => {
        this.auth0.authorize();
    }
    handleAuthentication = () => {
        this.auth0.parseHash((err, authResult) => {
            if (authResult && authResult.accessToken && authResult.idToken) {
                this.setSession(authResult);
                history.replace('/home');
            } else if (err) {
                history.replace('/');
                console.log(err);
            }
        });
    }
    setSession = (authResult) => {
        let expiresAt = JSON.stringify((authResult.expiresIn * 1000) + new Date().getTime());
        localStorage.setItem('access_token', authResult.accessToken);
        localStorage.setItem('id_token', authResult.idToken);
        localStorage.setItem('expires_at', expiresAt);
        history.replace('/home');
    }
    logout = () => {
        localStorage.removeItem('access_token');
        localStorage.removeItem('id_token');
        localStorage.removeItem('expires_at');
        history.replace('/');
    }
    isAuthenticated = () => {
        let expiresAt = JSON.parse(localStorage.getItem('expires_at'));
        return new Date().getTime() < expiresAt;
    }
}