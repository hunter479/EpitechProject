import React from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Stepper from '@material-ui/core/Stepper';
import Step from '@material-ui/core/Step';
import StepLabel from '@material-ui/core/StepLabel';
import { connect } from 'react-redux';

const useStyles = makeStyles(theme => ({
    root: {
        paddingLeft: "0px",
        paddingRight: "0px",
        paddingTop: "30px",
        textAlign: "center",
        width: "80%",
        margin: "auto",
        // backgroundColor: grey[300]
    },
    instructions: {
        marginTop: theme.spacing(1),
        marginBottom: theme.spacing(1),
    },
    buttons: {
        paddingTop: "14px",
        paddingBot: "14px"
    },
    label: {
        fontSize: "16px"
    }
}));

function getSteps() {
    return ['Select your services', 'Select your accounts', 'Create your action/reaction'];
}

function HorizontalLinearStepper(props) {
    const classes = useStyles();
    const [activeStep, setActiveStep] = React.useState(0);
    // const [skipped, setSkipped] = React.useState(new Set());
    const steps = getSteps();

    return (
        <div>
            <Stepper className={classes.root} activeStep={props.display}>
                {steps.map((label, index) => {
                    const stepProps = {};
                    const labelProps = {};
                    return (
                        <Step key={label} {...stepProps}>
                            <StepLabel {...labelProps}>
                                {label}
                            </StepLabel>
                        </Step>
                    );
                })}
            </Stepper>
        </div>
    );
}

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateNewAutomation: state.stateNewAutomation,
        isNextEnabled: state.isNextEnabled
    };
}

export default connect(mapStateToProps)(HorizontalLinearStepper);