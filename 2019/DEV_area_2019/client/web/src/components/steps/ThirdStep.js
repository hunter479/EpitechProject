import React, { useEffect } from 'react';
import { connect } from 'react-redux';
import FormControl from '@material-ui/core/FormControl';
import Select from '@material-ui/core/Select';
import MenuItem from '@material-ui/core/MenuItem';
import { makeStyles } from '@material-ui/core/styles';
import { getServices } from "../../Request/request";
import GroupFields from "./GroupFields"
import Typography from '@material-ui/core/Typography';

const useStyles = makeStyles(theme => ({
    formControl: {
        maxWidth: 400,
        paddingTop: "30px",
        paddingBottom: "30px",
        display: "flex",
        marginLeft: "auto",
        marginRight: "auto",
    },
    selectEmpty: {
        marginTop: theme.spacing(2),
    },
    text: {
        fontSize: "28px",
        marginBottom: "12px",
        fontWeight: "bold"
    }
}));

function ThirdStep(props) {

    const classes = useStyles();
    const [listServices, setListServices] = React.useState([]);

    const [actionName, setActionName] = React.useState("None");
    const [reactionName, setReactionName] = React.useState("None");

    const [listAction, setListAction] = React.useState([]);
    const [listReaction, setListReaction] = React.useState([]);

    const [currentActionFields, setCurrentActionFields] = React.useState([]);
    const [currentReactionFields, setCurrentReactionFields] = React.useState([]);

    useEffect(() => {
        getServices().then(res => {
            setListServices(res);
        })

    }, []);

    useEffect(() => {
        var newListActions = listServices.filter(elem => {
            // console.log(elem.name === props.stateNewAutomation.secondService);
            return elem.name === props.stateNewAutomation.firstService.name
        });
        if (newListActions[0] !== undefined) {
            // console.log(newListActions[0].actions);
            setListAction(newListActions[0].actions);
        }

        var newListReactions = listServices.filter(elem => {
            // console.log(elem.name === props.stateNewAutomation.secondService);
            return elem.name === props.stateNewAutomation.secondService.name
        });
        if (newListReactions[0] !== undefined) {
            // console.log(newListReactions[0]);
            setListReaction(newListReactions[0].reactions);
        }

    }, [listServices])

    useEffect(() => {
        var item;
        if (actionName !== "None") {
            item = getObjByName(listAction, actionName);
            if (item[0].fields) {
                setCurrentActionFields(item[0].fields);
            }
        } else {
            setCurrentActionFields([]);
        }
        if (reactionName !== "None") {
            item = getObjByName(listReaction, reactionName);
            if (item[0].fields) {
                setCurrentReactionFields(item[0].fields);
            }
        } else {
            setCurrentReactionFields([]);
        }
    }, [actionName, reactionName])

    const getObjByName = (list, name) => {
        var item = list.filter(elem => {
            return elem.name === name
        });
        return [item[0]];
    }

    useEffect(() => {
        if (actionName !== "None" && reactionName !== "None") {
            var actionObj = getObjByName(listAction, actionName);
            var reactionObj = getObjByName(listReaction, reactionName)
            props.dispatch({
                type: "UPDATE_AREA",
                obj: {
                    actionId: actionObj[0].id,
                    reactionId: reactionObj[0].id,
                    actionName: actionName,
                    reactionName: reactionName
                }
            });
            props.dispatch({
                type: "UPDATE_NEXT_BUTTON",
                value: true
            })
        } else {
            props.dispatch({
                type: "UPDATE_NEXT_BUTTON",
                value: false
            })
        }
    })

    const handleAction = event => {
        setActionName(event.target.value);
    }

    const handleReaction = event => {
        setReactionName(event.target.value);
    }

    return (
        <div>
            <FormControl className={classes.formControl}>
                <Typography className={classes.text} color="textPrimary">
                    Choose your action with {props.stateNewAutomation.firstService.name}...
                </Typography>
                <Select
                    labelId="simple-select-label"
                    id="simple-select"
                    value={actionName}
                    onChange={handleAction}
                >
                    <MenuItem value="None">None</MenuItem>
                    {listAction.map(elem => (
                        <MenuItem
                            key={elem.id} 
                            value={elem.name}
                        >
                        <div style={{ overflow: "hidden", textOverflow: "ellipsis" }}>
                            {elem.name}
                        </div>
                        </MenuItem>
                    ))}

                </Select>
                <GroupFields to="action" fields={currentActionFields}></GroupFields>
            </FormControl>

            <FormControl className={classes.formControl}>
                <Typography className={classes.text} color="textPrimary">
                    and your reaction with {props.stateNewAutomation.secondService.name}
                </Typography>
                <Select
                    labelId="simple-select-label"
                    id="simple-select"
                    value={reactionName}
                    onChange={handleReaction}
                >
                    <MenuItem value="None">None</MenuItem>
                    {listReaction.map(elem => (
                        <MenuItem 
                            key={elem.id} 
                            value={elem.name}
                        >
                        <div style={{ overflow: "hidden", textOverflow: "ellipsis" }}>
                            {elem.name}
                        </div>
                        </MenuItem>
                    ))}
                </Select>

                <GroupFields to="reaction" fields={currentReactionFields}></GroupFields>
            </FormControl>

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

export default connect(mapStateToProps)(ThirdStep);