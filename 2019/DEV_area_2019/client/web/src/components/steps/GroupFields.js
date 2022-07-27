import React from 'react';
import Field from "./Field"
import { connect } from 'react-redux';
import { makeStyles } from '@material-ui/core/styles';

const useStyles = makeStyles(theme => ({
    fields: {
        textAlign: "left"
    }
}));

function GroupField(props) {

    const classes = useStyles();

    return (
        <div className={classes.fields}>
            {props.fields.map(elem => (
                <Field key={elem.key} to={props.to} elem={elem}></Field>
            ))}
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

export default connect(mapStateToProps)(GroupField);