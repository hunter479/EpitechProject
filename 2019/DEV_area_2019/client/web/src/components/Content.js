import React, { Component } from 'react';
import Grid from "../components/Grid";
import { makeStyles } from '@material-ui/core/styles';

const useStyles = makeStyles(theme => ({
    root: {
        width: '100%',
        height: '100%',
        flexGrow: 1,
    },
    paper: {
        padding: theme.spacing(2),
        textAlign: 'center',
        color: theme.palette.text.secondary,
    },
    content: {
        paddingLeft: "24px",
        paddingRight: "24px",
        marginTop: "30px"
    }
}));

export default class Content extends Component {

    componentDidMount() {
        if (!this.props.auth.isAuthenticated()) {
            this.props.auth.login();
        }
    }

    displayApp = () => {
        const classes = useStyles();
        return (
            <div className={classes.content}>
                <Grid />
            </div>
        )
    }

    render() {
        const { isAuthenticated } = this.props.auth;
        return (
        <div>
        {
            isAuthenticated() &&
            <this.displayApp></this.displayApp>
        }
        </div>
        );
    }
}