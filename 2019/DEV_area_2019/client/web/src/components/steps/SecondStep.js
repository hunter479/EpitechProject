import React, { useEffect } from 'react';
import { connect } from 'react-redux';
import FormControl from '@material-ui/core/FormControl';
import Select from '@material-ui/core/Select';
import Button from '@material-ui/core/Button';
import MenuItem from '@material-ui/core/MenuItem';
import { makeStyles } from '@material-ui/core/styles';
import { getAccounts, prepareTwitterAccess } from "../../Request/request";
import oauth2 from "../../oauth2"
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
    buttons: {
        marginTop: "20px"
    },
    text: {
        fontSize: "28px",
        marginBottom: "12px",
        fontWeight: "bold"
    }
}));

function SecondStep(props) {

    const classes = useStyles();
    const [firstAccount, setFirstAccount] = React.useState(props.stateNewAutomation.firstAccount);
    const [secondAccount, setSecondAccount] = React.useState(props.stateNewAutomation.secondAccount);
    const [firstListAccounts, setFirstListAccounts] = React.useState([]);
    const [secondListAccounts, setSecondListAccounts] = React.useState([]);

    var isFirstConnectionNeeded = props.stateNewAutomation.firstService.isConnectionNeeded;
    var isSecondConnectionNeeded = props.stateNewAutomation.secondService.isConnectionNeeded;

    const updateAccounts = () => {
        getAccounts(props.stateNewAutomation.firstService.name).then(res => {
            setFirstListAccounts(res.info);
        })

        getAccounts(props.stateNewAutomation.secondService.name).then(res => {
            setSecondListAccounts(res.info);
        })
    }

    useEffect(() => {
        updateAccounts();
        localStorage.setItem("isRedirectionOver", "false");
    }, [])

    const setNext = (bool) => {
        props.dispatch({
            type: "UPDATE_NEXT_BUTTON",
            value: bool
        })
    }

    useEffect(() => {
        // console.log(firstListAccounts, secondListAccounts);
        if (firstAccount !== "None" && secondAccount !== "None") {
            props.dispatch({
                type: "UPDATE_ACCOUNT",
                accounts: {
                    firstAccount: firstAccount,
                    secondAccount: secondAccount
                }
            });
            setNext(true);
        } else
            setNext(false);

        if ((firstAccount !== "None" && isSecondConnectionNeeded === false) ||
            (secondAccount !== "None" && isFirstConnectionNeeded === false) ||
            (isFirstConnectionNeeded === false && isSecondConnectionNeeded === false)) {
                props.dispatch({
                    type: "UPDATE_ACCOUNT",
                    accounts: {
                        firstAccount: firstAccount,
                        secondAccount: secondAccount
                    }
                });
            setNext(true);
        }
    });

    const buttonClicked = () => {
        if (localStorage.getItem("isRedirectionOver") === "true") {
            console.log("Update Account");
            updateAccounts();
        }
    }

    const handleFirstAccount = event => {
        setFirstAccount(event.target.value);
    };

    const handleSecondAccount = event => {
        setSecondAccount(event.target.value);
    };

    const addAccountFirstService = () => {
        // console.log(props.stateNewAutomation.firstService);
        switch (props.stateNewAutomation.firstService.name) {
            case "Gitlab":
                window.open(oauth2.gitlab, "_blank");
                break;
            case "Microsoft":
                window.open(oauth2.microsoft, "_blank");
                break;
            case "Imgur":
                window.open(oauth2.imgur, "_blank");
                break;
            case "Spotify":
                window.open(oauth2.spotify, "_blank");
                break;
            case "Facebook":
                window.open(oauth2.facebook, "_blank");
                break;
            case "Twitter":
                prepareTwitterAccess();
                break;
            case "Yammer":
                window.open(oauth2.yammer, "_blank");
                break;
            default:
                break;
        }
    }

    const addAccountSecondService = () => {
        // console.log(props.stateNewAutomation.secondService);
        switch (props.stateNewAutomation.secondService.name) {
            case "Gitlab":
                window.open(oauth2.gitlab, "_blank");
                break;
            case "Microsoft":
                window.open(oauth2.microsoft, "_blank");
                break;
            case "Imgur":
                window.open(oauth2.imgur, "_blank");
                break;
            case "Spotify":
                window.open(oauth2.spotify, "_blank");
                break;
            case "Facebook":
                window.open(oauth2.facebook, "_blank");
                break;
            case "Twitter":
                prepareTwitterAccess();
                break;
            case "Yammer":
                window.open(oauth2.yammer, "_blank");
                break;
            default:
                break;
        }
    }

    return (
        <div>
            <FormControl className={classes.formControl}>
                <Typography className={classes.text} color="textPrimary">
                    Choose {props.stateNewAutomation.firstService.name} account
                </Typography>
                {/* <InputLabel id="demo-simple-select-label"></InputLabel> */}
                <Select
                    labelId="simple-select-label"
                    id="simple-select"
                    value={firstAccount}
                    onChange={handleFirstAccount}
                    onOpen={buttonClicked}
                >
                    <MenuItem key="None" value="None">None</MenuItem>
                    {firstListAccounts.map(elem => (
                        <MenuItem key={elem.username} value={elem.username}>{elem.username}</MenuItem>
                    ))}
                </Select>
                <Button
                    disabled={!isFirstConnectionNeeded}
                    variant="contained"
                    color="primary"
                    onClick={addAccountFirstService}
                    className={classes.buttons}
                    >
                    Add Account
                </Button>
            </FormControl>

            <FormControl className={classes.formControl}>
                <Typography className={classes.text} color="textPrimary">
                    Choose {props.stateNewAutomation.secondService.name} account
                </Typography>
                {/* <InputLabel id="demo-simple-select-label"></InputLabel> */}
                <Select
                    labelId="simple-select-label"
                    id="simple-select"
                    value={secondAccount}
                    onChange={handleSecondAccount}
                    onOpen={buttonClicked}
                >
                    <MenuItem value="None">None</MenuItem>
                    {secondListAccounts.map(elem => (
                        <MenuItem key={elem.username} value={elem.username}>{elem.username}</MenuItem>
                    ))}
                </Select>
                <Button
                    disabled={!isSecondConnectionNeeded}
                    variant="contained"
                    color="primary"
                    onClick={addAccountSecondService}
                    className={classes.buttons}
                    >
                    Add Account
                </Button>
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

export default connect(mapStateToProps)(SecondStep);