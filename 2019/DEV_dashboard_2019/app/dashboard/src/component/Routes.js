import React from 'react';
import { Route, Router } from 'react-router-dom';
import Home from './Home';
import Callback from './services/authentification/Callback';
import Auth from './services/authentification/auth';
import history from './services/authentification/history';

const auth = new Auth();

const handleAuthentication = (nextState, replace) => {
    if (/access_token|id_token|error/.test(nextState.location.hash)) {
        auth.handleAuthentication();
    }
}

const Routes = () => (
    <Router history={history} component={Home}>
    <div>
        <Route exact path="/" render={(props) => <Home auth={auth} {...props} />} />
        <Route path="/home" render={(props) => <Home auth={auth} {...props} />} />
        <Route path="/callback" render={(props) => {
            handleAuthentication(props);
            return <Callback {...props} />
        }}/>
    </div>
    </Router>
);

export default Routes;