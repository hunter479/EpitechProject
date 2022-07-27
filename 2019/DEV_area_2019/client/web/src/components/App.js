import React from 'react';
import {
    BrowserRouter as Router,
    } from "react-router-dom";
import Routes from '../Routes/Routes'
import Auth from '../Auth/auth';
import { createStore } from 'redux';
import { contentState } from '../components/Grid'
import { Provider } from 'react-redux';
import { makeStyles } from '@material-ui/core/styles';
import FooterPage from './Footer';
import NavbarPage from './Navbar2';

const auth = new Auth();

const useStyles = makeStyles(theme => ({
    app: {
        position: 'fixed',
        width: '100%',
        height: '100%'
    }
}));

const initialState = {
    gridAutomations: [],
    display: contentState.GRID,
    stateNewAutomation: {
        firstService: {
            name: "None",
            isConnectionNeeded: false
        },
        secondService: {
            name: "None",
            isConnectionNeeded: false
        },
        firstAccount: "None",
        secondAccount: "None",
        action: {
            name: "None",
            id: 0,
        },
        reaction: {
            name: "None",
            id: 0,
        },
        actionField: {},
        reactionField: {}
    },
    isNextEnabled: false
};

function getCleanAutomation() {
    var newAutomation = {
        firstService: {
            name: "None",
            isConnectionNeeded: false
        },
        secondService: {
            name: "None",
            isConnectionNeeded: false
        },
        firstAccount: "None",
        secondAccount: "None",
        action: {
            name: "None",
            id: 0,
        },
        reaction: {
            name: "None",
            id: 0,
        },
        actionField: {},
        reactionField: {}
    };
    return newAutomation;
}

function reducer(currentState = initialState, action) {
    var newAutomation;
    switch (action.type) {
        case "CHANGE_STATE":
            return {
                gridAutomations: currentState.gridAutomations,
                display: action.newDisplay,
                stateNewAutomation: currentState.stateNewAutomation,
            }
        case "UPDATE_SERVICES":
            newAutomation = currentState.stateNewAutomation;
            newAutomation.firstService.name = action.services.firstService;
            newAutomation.secondService.name = action.services.secondService;

            newAutomation.firstService.isConnectionNeeded = action.services.firstConnection;
            newAutomation.secondService.isConnectionNeeded = action.services.secondConnection;

            newAutomation.firstAccount = action.services.firstAccount;
            newAutomation.secondAccount = action.services.secondAccount;
            return {
                gridAutomations: currentState.gridAutomations,
                display: currentState.display,
                stateNewAutomation: newAutomation
            }
        case "UPDATE_ACCOUNT":
            newAutomation = currentState.stateNewAutomation;
            newAutomation.firstAccount = action.accounts.firstAccount;
            newAutomation.secondAccount = action.accounts.secondAccount;
            return {
                gridAutomations: currentState.gridAutomations,
                display: currentState.display,
                stateNewAutomation: newAutomation
            }
        case "UPDATE_AREA":
            newAutomation = currentState.stateNewAutomation;
            newAutomation.action.id = action.obj.actionId;
            newAutomation.reaction.id = action.obj.reactionId;
            newAutomation.action.name = action.obj.actionName;
            newAutomation.reaction.name = action.obj.reactionName;
            return {
                gridAutomations: currentState.gridAutomations,
                display: currentState.display,
                stateNewAutomation: newAutomation
            }
        case "UPDATE_NEXT_BUTTON":
            return {
                gridAutomations: currentState.gridAutomations,
                display: currentState.display,
                stateNewAutomation: currentState.stateNewAutomation,
                isNextEnabled: action.value,
            }
        case "UPDATE_ACTION_FIELD":
            newAutomation = currentState.stateNewAutomation;
            newAutomation.actionField[action.field.key] = action.field.value;
            return {
                gridAutomations: currentState.gridAutomations,
                display: currentState.display,
                stateNewAutomation: newAutomation,
            }
        case "UPDATE_REACTION_FIELD":
            newAutomation = currentState.stateNewAutomation;
            newAutomation.reactionField[action.field.key] = action.field.value;
            return {
                gridAutomations: currentState.gridAutomations,
                display: currentState.display,
                stateNewAutomation: newAutomation
            }
        case "RESET_NEW_AUTOMATION":
            newAutomation = getCleanAutomation();
            return {
                gridAutomations: currentState.gridAutomations,
                display: currentState.display,
                stateNewAutomation: newAutomation,
            }
        case "GET_USER_AUTOMATIONS":
            return {
                gridAutomations: action.automations,
                display: currentState.display,
                stateNewAutomation: currentState.stateNewAutomation
            }
        case "DELETE_AUTOMATION":
            return {
                display: currentState.display,
                gridAutomations: action.grid
            }
    }
    return currentState;
}

const store = createStore(reducer);

export default function App() {
    const classes = useStyles;
    return (
        <Provider store={store}>
            <div className={classes.app}>
                <Router>
                    <div>
                        <NavbarPage {...auth} />
                    </div>
                    <Routes {...auth}/>
                </Router>
            </div>
                <FooterPage />
        </Provider>
    );
}
