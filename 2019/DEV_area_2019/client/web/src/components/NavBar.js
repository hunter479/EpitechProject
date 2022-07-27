import React from "react";
import { Toolbar, AppBar, IconButton, Grid } from "@material-ui/core";
import { AccountCircle } from '@material-ui/icons';
import DashboardIcon from '@material-ui/icons/Dashboard';
import SettingsIcon from '@material-ui/icons/Settings';
import ExitToAppIcon from '@material-ui/icons/ExitToApp';
import { makeStyles } from '@material-ui/core/styles';
// import history from '../History';
import MenuManager from './StyledMenu';
import { connect } from 'react-redux';
import Dialog from "./Dialog";

const useStyles = makeStyles(theme => ({
    fullWide: {
        width: '100%',
    },
    semiFullWide: {
        width: '93%',
    },
    fonts: {
        fontSize: 12,
    },
    button: {
        color: 'white',
        margin: theme.spacing(1),
    },
    input: {
        display: 'none',
    },
    padding: {
        minHeight: 94,
    },
    marginBot: {
        marginBottom: '30px',
    }
}));

function NavBar(props) {
    var isAuthenticated = true;
    const [anchorEl, setAnchorEl] = React.useState(null);
    // var isAuthenticated = props.isAuthenticated();
    const classes = useStyles();
    const handleClose = () => {
        setAnchorEl(null);
    };
    const handleMenu = event => {
        setAnchorEl(event.currentTarget);
    }
    const login = () => {
        // props.login();
        // isAuthenticated = props.isAuthenticated();
    }

    const logout = () => {
        props.logout();
        isAuthenticated = props.isAuthenticated();
    }

    const Dashboard = () => {
        // history.replace('/dashboard');
    }

    const Settings = () => {
        // history.replace('/settings');
    }

    const backToHome = () => {
    }

    return (
        <React.Fragment>
            <AppBar position="static" className={classes.marginBot}>
                <Toolbar className={classes.padding}>
                    <Grid
                        justify="flex-start"
                        container
                        alignItems="center"
                    >
                        <Grid item onClick={() => backToHome()}>
                            <Dialog value="My services"></Dialog>
                        </Grid>
                    </Grid>

                    <Grid
                        direction="row"
                        justify="flex-end"
                        container 
                        alignItems="center"
                    >
                    {(isAuthenticated) && (
                        <div>
                        <IconButton
                            aria-label="account of current user"
                            aria-controls="menu-appbar"
                            aria-haspopup="true"
                            onClick={handleMenu}
                            color="inherit">
                            <AccountCircle />
                        </IconButton>
                        <MenuManager
                            names={['Settings', 'Log out']}
                            actions={[Settings, logout]}
                            icons={[<SettingsIcon key="settings" fontSize="small" />,
                                    <ExitToAppIcon key="exit" fontSize="small" />]}
                            anchorEl={anchorEl}
                            setAnchorEl={setAnchorEl}
                            handleClose={handleClose}/>
                        </div>
                        )}
                    </Grid>
                </Toolbar>
            </AppBar>
        </React.Fragment>
    );
};

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateAutomation: state.stateAutomation
    };
}

export default connect(mapStateToProps)(NavBar);