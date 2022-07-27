import React, { Component } from 'react';
import Dashboard from './Dashboard'
import LoginPage from './services/authentification/LoginPage'

class Home extends Component {
  login = () => {
    this.props.auth.login();
  }
  logout = () => {
    this.props.auth.logout();
  }
  render() {
    const { isAuthenticated } = this.props.auth;
    return (
        <div>
          {
            isAuthenticated() && <Dashboard logout={this.logout}/>
          }{
            !isAuthenticated() && <LoginPage login={this.login}></LoginPage>
          }
        </div>
    );}
}

  export default Home;