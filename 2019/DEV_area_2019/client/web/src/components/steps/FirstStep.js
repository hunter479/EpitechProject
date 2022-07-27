import React, { useEffect } from 'react';
import { connect } from 'react-redux';
import FormControl from '@material-ui/core/FormControl';
import Select from '@material-ui/core/Select';
import MenuItem from '@material-ui/core/MenuItem';
import { makeStyles } from '@material-ui/core/styles';
import { getServices } from "../../Request/request";
import Icon from '@material-ui/core/Icon';
import * as LogoPaths from "../../config.js"
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
    icon: {
        marginRight: "12px",
    },
    text: {
        fontSize: "28px",
        marginBottom: "12px",
        fontWeight: "bold"
    },
    textSelect: {
        fontSize: "16px"
    }
}));

function FirstStep(props) {

    const classes = useStyles();
    const [firstService, setFirstService] = React.useState(props.stateNewAutomation.firstService.name);
    const [secondService, setSecondService] = React.useState(props.stateNewAutomation.secondService.name);

    const [listActions, setListActions] = React.useState([]);
    const [listReactions, setListReactions] = React.useState([]);

    const updateServices = () => {
        getServices().then(res => {
            res.map(elem => {
                if (elem.actions.length !== 0)
                    setListActions(listActions => [...listActions, elem])
                if (elem.reactions.length !== 0)
                    setListReactions(listReactions => [...listReactions, elem])
            })
        })
    }

    useEffect(() => {
        updateServices();
    }, []);

    const setConnection = () => {
        var fService = listActions.filter(elem => {
            return elem.name === firstService
        });

        var sService = listReactions.filter(elem => {
            return elem.name === secondService
        });

        var firstBool = false;
        var secondBool = false;

        if (fService[0] !== undefined && sService[0] !== undefined) {
            firstBool = fService[0].connection_needed;
            secondBool = sService[0].connection_needed;
        }
        return [firstBool, secondBool]
    }

    useEffect(() => {
        if (firstService !== "None" && secondService !== "None") {
            var bools = setConnection();
            props.dispatch({
                type: "UPDATE_SERVICES",
                services: {
                    firstService: firstService,
                    secondService: secondService,
                    firstConnection: bools[0],
                    secondConnection: bools[1],
                    firstAccount: "None",
                    secondAccount: "None"
                }
            });
            props.dispatch({
                type: "UPDATE_NEXT_BUTTON",
                value: true
            });
        } else {
            props.dispatch({
                type: "UPDATE_NEXT_BUTTON",
                value: false
            });
        }
    })


    const handleFirstService = event => {
        setFirstService(event.target.value);
        // console.log(listServices);
    };

    const handleSecondService = event => {
        setSecondService(event.target.value);
    };

    return (
        <div>
            <FormControl className={classes.formControl}>
                <Typography className={classes.text} color="textPrimary">Connect this service...</Typography>
                <Select
                    labelId="simple-select-label"
                    id="simple-select"
                    value={firstService}
                    onChange={handleFirstService}
                >
                    {/* <MenuItem value="">None</MenuItem> */}
                    <MenuItem value="None">None</MenuItem>
                    {listActions.map(elem => (
                        <MenuItem key={elem.name} value={elem.name}>
                            <Icon className={classes.icon}>
                                <img style={{verticalAlign: "top"}} src={LogoPaths[elem.name]} alt={elem.name} height={24} width={24}/>
                            </Icon>
                            {/* <Typography color="textPrimary">{elem.name}</Typography> */}
                            {elem.name}
                        </MenuItem>
                    ))}
                </Select>
            </FormControl>

            <FormControl className={classes.formControl}>
                <Typography className={classes.text} color="textPrimary">with this one !</Typography>
                <Select
                    labelId="simple-select-label"
                    id="simple-select"
                    value={secondService}
                    onChange={handleSecondService}
                >
                    {/* <MenuItem value="">None</MenuItem> */}
                    <MenuItem value="None">None</MenuItem>
                    {listReactions.map(elem => (
                        <MenuItem key={elem.name} value={elem.name}>
                            <Icon className={classes.icon}>
                                <img style={{verticalAlign: "top"}} src={LogoPaths[elem.name]} alt={elem.name} height={24} width={24}/>
                            </Icon>
                            {elem.name}
                        </MenuItem>
                    ))}
                </Select>
            </FormControl>

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

export default connect(mapStateToProps)(FirstStep);