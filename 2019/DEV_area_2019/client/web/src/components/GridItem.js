import React from 'react';

import { makeStyles } from '@material-ui/core/styles';
import Card from '@material-ui/core/Card';
import CardContent from '@material-ui/core/CardContent';
import Icon from '@material-ui/core/Icon';
import * as LogoPaths from "../config.js"
import ArrowRightIcon from '@material-ui/icons/ArrowRight';
import { connect } from 'react-redux';
import Typography from '@material-ui/core/Typography';
import { IconButton } from '@material-ui/core';
import DeleteIcon from '@material-ui/icons/Delete';
import { deleteAutomation } from "../Request/request";

const useStyles = makeStyles(theme => ({
    cards: {
        border: "3px solid #e7e7e7",
        borderRadius: "4px",
        minHeight: "200px",
        position: "relative",
    },
    largeIcon: {
        width: "40px",
        height: "40px",
    },
    header: {
        padding: "0 0 0 0"
    },
    content: {
        fontSize: "16px",
        marginTop: "15px",
        fontFamily: "Roboto"
    },
    wrapper: {
        position: "relative",
        display: "inline-block"
    },
    deleteIcon: {
        position: "absolute",
        top: "0",
        right: "0",
        cursor: "pointer"
    },
}));

function GridItem(props) {

    const classes = useStyles();

    const del = () => {
        deleteAutomation(props.index).then(() => {
            props.dispatch({
                type: "DELETE_AUTOATION",
                grid: props.gridAutomations.splice(props.index, 1)
            })
            window.location = "/";
        });
    }

    return (
        <Card key={props.key} className={classes.cards} variant="outlined">
                <CardContent>

                    <Icon>
                        <img src={LogoPaths[props.elem.action.service]} alt={props.elem.action.service} height={50} width={50}/>
                    </Icon>
                    <Icon>
                        <ArrowRightIcon className={classes.largeIcon}></ArrowRightIcon>
                    </Icon>
                    <Icon>
                        <img src={LogoPaths[props.elem.reaction.service]} alt={props.elem.reaction.service} height={50} width={50}/>
                    </Icon>

                    <IconButton onClick={del} className={classes.deleteIcon} aria-label="delete">
                        <DeleteIcon />
                    </IconButton>
                    

                    <Typography className={classes.content} color="textPrimary">
                        {props.elem.action.name}
                    </Typography>
                    <Typography className={classes.content} color="textPrimary">
                        {props.elem.reaction.name}
                    </Typography>
                </CardContent>
                {/* </div> */}
            </Card>
        // <Paper >{this.props.id}</Paper>
    )
}

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateAutomation: state.stateAutomation,
        isNextEnabled: state.isNextEnabled,
    };
}

export default connect(mapStateToProps)(GridItem);