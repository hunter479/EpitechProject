import React, { Fragment } from 'react'
import Typography from '@material-ui/core/Typography';
import { makeStyles } from '@material-ui/core/styles';
import CssBaseline from '@material-ui/core/CssBaseline';
import Button from '@material-ui/core/Button';

const useStyles = makeStyles(theme => ({
    title: {
        flexGrow: 1,
    },
    button: {
        margin: theme.spacing(4),
    },
    root: {
        textAlign: 'center',
        paddingTop: theme.spacing.unit * 25,
    },
}));

const LoginPage = props => {
    const loginStyles = useStyles()
    return (
        <div className={loginStyles.root}>
            <CssBaseline />
                <Typography variant="h3">
                    DASHBOARD
            </Typography>
            <Button variant="contained" color="primary" className={loginStyles.button} onClick={props.login}>
                Sign In
            </Button>
        </div>
    )
}

export default LoginPage