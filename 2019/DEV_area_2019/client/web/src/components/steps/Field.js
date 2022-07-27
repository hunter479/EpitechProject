import React from 'react';
import TextField from '@material-ui/core/TextField';
import { makeStyles } from '@material-ui/core/styles';
import { connect } from 'react-redux';

const useStyles = makeStyles(theme => ({
    textField: {
        marginLeft: theme.spacing(1),
        marginRight: theme.spacing(1),
        width: 200,
    },
}));

const fieldChange = (props) => event => {
    // console.log(props);
    if (props.to === "reaction") {
        props.dispatch({
            type: "UPDATE_REACTION_FIELD",
            field: {
                key: props.elem.key,
                value: event.target.value
            }
        })
    } else if (props.to === "action") {
        props.dispatch({
            type: "UPDATE_ACTION_FIELD",
            field: {
                key: props.elem.key,
                value: event.target.value
            }
        })
    }
    // console.log(props.stateNewAutomation);
    // console.log(event.target.value);
}

function Field(props) {
    const classes = useStyles();

    return (
        <div>
            <TextField
                required
                id="standard-required"
                label={props.elem.label}
                defaultValue=""
                className={classes.textField}
                margin="normal"
                onChange={fieldChange(props)}
            />
        </div>
    )
}

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateNewAutomation: state.stateNewAutomation,
        isNextEnabled: state.isNextEnabled
    };
}

export default connect(mapStateToProps)(Field);