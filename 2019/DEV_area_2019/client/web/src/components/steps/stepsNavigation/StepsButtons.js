import React from 'react';
import Button from '@material-ui/core/Button';
import { makeStyles } from '@material-ui/core/styles';
import { connect } from 'react-redux';
import { addAutomation } from "../../../Request/request";

const useStyles = makeStyles(theme => ({
    groupButtons: {
        paddingTop: "30px",
        paddingBottom: "30px"
    },
    button: {
        marigin: "10px"
    }
}));

function StepsButtons(props) {
    
    const classes = useStyles();
    const [activeStep, setActiveStep] = React.useState(0);

    const handleNext = () => {
        if (activeStep === 2) {
            addAutomation(props).then(res => {
                props.gridAutomations.push({
                    action: {
                        service: props.stateNewAutomation.firstService.name,
                        name: props.stateNewAutomation.action.name
                    },
                    reaction: {
                        service: props.stateNewAutomation.secondService.name,
                        name: props.stateNewAutomation.reaction.name
                    }
                    // firstService: props.stateNewAutomation.firstService.name,
                    // secondService: props.stateNewAutomation.secondService.name,
                    // action: props.stateNewAutomation.action.name,
                    // reaction: props.stateNewAutomation.reaction.name
                })
                props.dispatch({
                    type: "RESET_NEW_AUTOMATION"
                });
                props.dispatch({
                    type: "CHANGE_STATE", 
                    newDisplay: 10
                });
            });
        } else {
            props.dispatch({
                type: "CHANGE_STATE",
                newDisplay: props.display + 1,
            });
            setActiveStep(prevActiveStep => prevActiveStep + 1);
        }

    };

    const handleBack = () => {
        props.dispatch({
            type: "CHANGE_STATE", 
            newDisplay: props.display - 1,
        });

        setActiveStep(prevActiveStep => prevActiveStep - 1);
    };

    return (
        <div className={classes.groupButtons}>
            <Button disabled={activeStep === 0} onClick={handleBack} className={classes.button}>
                Back
            </Button>

            <Button
                disabled={!props.isNextEnabled}
                variant="contained"
                color="primary"
                onClick={handleNext}
                className={classes.button}
                >
                {activeStep === 2 ? 'Finish' : 'Next'}
            </Button>
        </div>
    )

}

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateNewAutomation: state.stateNewAutomation,
        isNextEnabled: state.isNextEnabled,
    };
}

export default connect(mapStateToProps)(StepsButtons);