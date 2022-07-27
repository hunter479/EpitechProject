import React, { Component } from 'react';
import { makeStyles } from '@material-ui/core/styles';
import Grid from '@material-ui/core/Grid';
import GridItem from './GridItem';
import { connect } from 'react-redux';
import { getUserAutomations } from '../Request/request';
import Automation from './Automation'
import NewAutomation from './NewAutomation'

const useStyles = makeStyles(theme => ({
    root: {
        flexGrow: 1,
        minWidth: 275,
    },
    paper: {
        padding: theme.spacing(2),
        textAlign: 'center',
        color: theme.palette.text.secondary,
    },
    cards: {
        border: "3px solid #e7e7e7",
        borderRadius: "4px",
        minHeight: "200px",
    },
    card: {
        display: "grid",
        flexGrow: 1,
        minWidth: 275,
    },
    img: {
        width: "100%",
        height: "200px"
    }
}));

export const contentState = {
    GRID: 10,
    AUTOMATION: 20,
    NEW_AUTOMATION: {
        FIRST_STEP: 0,
        SECOND_STEP: 1,
        THIRD_STEP: 2
    }
}

class MyGrid extends Component {

    constructor(props) {
        super(props);
        getUserAutomations().then(res => {
            console.log("ICI", res);
            this.props.dispatch({
                type: "GET_USER_AUTOMATIONS",
                automations: res.automation
            })
        });
    }

    addAutomation() {
        this.props.dispatch({ type: "CHANGE_STATE", newDisplay: contentState.NEW_AUTOMATION.FIRST_STEP});
    }

    displayGrid = () => {
        const classes = useStyles();


        if (!this.props.gridAutomations) {
            return;
        } else {
            var index = 0;
            // console.log("not empty", this.props.gridAutomations);
            var listElements = this.props.gridAutomations.map((elem) => {
                // console.log("grid: ", elem);
                let i = index;
                index = index + 1;
                return (
                    <Grid key={i} item xs={3}>
                        <GridItem key={elem._id} index={i} elem={elem}></GridItem>
                    </Grid>
                )
            })
        }
        
        return (
            <div className={classes.card}>
                <Grid container spacing={3}>
                    <>
                    {listElements}
                    <Grid item xs={3} onClick={() => this.addAutomation()}>
                        <span className="block-example border border-white">
                            <img height={"200px"} className="rounded-circle" alt="100x100" src="https://image.flaticon.com/icons/svg/148/148790.svg" />
                        </span>
                    </Grid>
                    </>
                </Grid>
            </div>
        );
    }

    render() {
        let content = <this.displayGrid></this.displayGrid>;

        switch (this.props.display) {
            case contentState.GRID:
                return content = <this.displayGrid></this.displayGrid>
            case contentState.AUTOMATION:
                return content = <Automation></Automation>
            case contentState.NEW_AUTOMATION.FIRST_STEP:
            case contentState.NEW_AUTOMATION.SECOND_STEP:
            case contentState.NEW_AUTOMATION.THIRD_STEP:
                return content = <NewAutomation></NewAutomation>
            default:
                console.log("default case");
        }

        return (
            <div className="SIIISI">
                {content}
            </div>
        )
    }
}

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateAutomation: state.stateAutomation,
        isNextEnabled: state.isNextEnabled,
		test: state.test
    };
}

export default connect(mapStateToProps)(MyGrid);