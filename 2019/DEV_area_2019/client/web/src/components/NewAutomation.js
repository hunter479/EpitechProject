import React from 'react';
// import InputLabel from '@material-ui/core/InputLabel';
import { connect } from 'react-redux';
import { contentState } from './Grid';
import FirstStep from "./steps/FirstStep"
import SecondStep from "./steps/SecondStep"
import ThirdStep from "./steps/ThirdStep"
import Stepper from './steps/stepsNavigation/Stepper';
import { makeStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import StepsButtons from "./steps/stepsNavigation/StepsButtons"

function NewAutomation(props) {

    // console.log("Props", props);
    const useStyles = makeStyles(theme => ({
        parent: {
            textAlign: "center",
            width: "70%",
            margin: "auto",
            marginBottom: "100px"
        },
        children: {
            margin: "auto"
        },
        card: {
            border: "3px solid #e7e7e7",
        },
        buttons: {
            paddingTop: "14px",
            paddingBot: "14px"
        }
    }));

    const classes = useStyles();

    const renderSwitch = (step) => {
        switch (step.display) {
            case contentState.NEW_AUTOMATION.FIRST_STEP:
                return <FirstStep></FirstStep>
            case contentState.NEW_AUTOMATION.SECOND_STEP:
                return <SecondStep></SecondStep>;
            case contentState.NEW_AUTOMATION.THIRD_STEP:
                return <ThirdStep></ThirdStep>
            default:
                return <FirstStep></FirstStep>
        }
    }

    return (
        <div>
            <div className={classes.parent}>
                <Card className={classes.card} variant="outlined">
                    <Stepper></Stepper>
                    <div className={classes.children}>
                        {renderSwitch(props)}
                    </div>
                    <StepsButtons></StepsButtons>
                </Card>
            </div>
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

export default connect(mapStateToProps)(NewAutomation);