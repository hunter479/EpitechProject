import React from 'react';
import Button from '@material-ui/core/Button';
import Dialog from '@material-ui/core/Dialog';
import DialogActions from '@material-ui/core/DialogActions';
import DialogContent from '@material-ui/core/DialogContent';
import DialogContentText from '@material-ui/core/DialogContentText';
import DialogTitle from '@material-ui/core/DialogTitle';
import { connect } from 'react-redux';
import { contentState } from './Grid';
import { MDBNavItem, MDBNavLink } from "mdbreact";

function AlertDialog(props) {

    const [open, setOpen] = React.useState(false);
    const handleClickOpen = () => {
        if (props.display === contentState.NEW_AUTOMATION.FIRST_STEP ||
            props.display === contentState.NEW_AUTOMATION.SECOND_STEP ||
            props.display === contentState.NEW_AUTOMATION.THIRD_STEP) {
            setOpen(true);
        } else {
            props.dispatch({
                type: "CHANGE_STATE",
                newDisplay: contentState.GRID
            });
        }
    };

    const handleAgree = () => {
        props.dispatch({ 
            type: "CHANGE_STATE", 
            newDisplay: contentState.GRID
        });

        props.dispatch({
            type: "UPDATE_SERVICES",
            services: {
                firstService: "None",
                secondService: "None"
            }
        });

        props.dispatch({
            type: "UPDATE_ACCOUNT",
            accounts: {
                firstAccount: "None",
                secondAccount: "None"
            }
        });

        setOpen(false);
    }

    const handleClose = () => {
        setOpen(false);
    };

    return (
        <div>
            <MDBNavItem>
                <MDBNavLink to="#!" onClick={handleClickOpen}> Home </MDBNavLink>
            </MDBNavItem>
            <Dialog
                open={open}
                onClose={handleClose}
                aria-labelledby="alert-dialog-title"
                aria-describedby="alert-dialog-description"
                >
                <DialogTitle id="alert-dialog-title">{"Are you sure ?"}</DialogTitle>
                <DialogContent>
                    <DialogContentText id="alert-dialog-description">
                        You will lose all changes.
                    </DialogContentText>
                </DialogContent>
                <DialogActions>
                    <Button onClick={handleClose} color="primary">
                        Disagree
                    </Button>
                    <Button onClick={handleAgree} color="primary" autoFocus>
                        Agree
                    </Button>
                </DialogActions>
            </Dialog>
        </div>
    );
}

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateNewAutomation: state.stateNewAutomation
    };
}

export default connect(mapStateToProps)(AlertDialog);