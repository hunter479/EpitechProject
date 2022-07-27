import React, { Component } from "react";
import { MDBIcon, MDBNavbar, MDBNavbarBrand, MDBNavbarNav, MDBNavItem, MDBNavLink, MDBNavbarToggler, MDBCollapse } from "mdbreact";
import { BrowserRouter as Router } from 'react-router-dom';
import { connect } from 'react-redux';
import Dialog from "./Dialog";

class NavbarPage extends Component {

    constructor(props) {
        super(props);
    }

    state = {
        isOpen: false
    };

    toggleCollapse = () => {
        this.setState({ isOpen: !this.state.isOpen });
    }

    render() {

        const logout = () => {
            this.props.logout();
        }

        return (
            <Router>
                <MDBNavbar color="#0277bd light-blue darken-3" dark expand="md">
                    <MDBNavbarBrand>
                        <strong className="white-text">ARea</strong>
                    </MDBNavbarBrand>
                    <MDBNavbarToggler onClick={this.toggleCollapse} />
                    <MDBCollapse id="navbarCollapse3" isOpen={this.state.isOpen} navbar>
                    <MDBNavbarNav left>
                        <Dialog value="Home"></Dialog>
                    </MDBNavbarNav>
                        <MDBNavbarNav right>
                            <MDBNavItem>
                                <MDBNavLink to="#!" onClick={logout}>
                                    <MDBIcon icon="sign-in-alt" />
                                </MDBNavLink>
                            </MDBNavItem>
                        </MDBNavbarNav>
                    </MDBCollapse>
                </MDBNavbar>
            </Router>
        )
    }
}

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateAutomation: state.stateAutomation
    };
}

export default connect(mapStateToProps)(NavbarPage);