import React from 'react';
import { Route } from 'react-router-dom';
import Callback from '../components/Callback';
import CallbackRedirection from '../components/CallbackRedirection';
import DownloadFile from '../components/DownloadFile'
import Content from '../components/Content';
import queryString from 'query-string'
import { connect } from 'react-redux';
import { getGitlabAccess,
		getMicrosoftAccess,
		getImgurAccess,
		getSpotifyAccess,
		getFacebookAccess,
		getTwitterAccess,
		getYammerAccess
} from "../Request/request"

var Auth = 0;

const handleAuthentication = (nextState, replace) => {
	if (/access_token|id_token|error/.test(nextState.location.hash))
		Auth.handleAuthentication();
}

const handleGitlab = (props) => {
	console.log("handle gitlab", props);
	const values = queryString.parse(props.location.search)
	getGitlabAccess(values.code);
}

const handleSpotify = (props) => {
	const values = queryString.parse(props.location.search)
	console.log("handle gitlab", props);
	getSpotifyAccess(values.code);
}

const handleMicrosoft = (props, storeLike) => {
	const values = queryString.parse(props.location.search);
	console.log("AYAAAAAAAAAAAAA", storeLike);
	getMicrosoftAccess(values.code);
}

const handleImgur = (props) => {
	console.log("handle Imgur", props);
	const values = queryString.parse(props.location.hash)
	console.log(values)
	getImgurAccess(values);
}

const handleFacebook = (props) => {
	console.log("handle facebook", props);
	const values = queryString.parse(props.location.hash)
	console.log(values)
	getFacebookAccess(values);
}

const handleTwitter = (props) => {
	console.log("Handle Twitter", props);
	const values = queryString.parse(props.location.search)
	console.log("here", values);
	getTwitterAccess(values);
}

const handleYammer = (props) => {
	console.log("handle yammer", props);
	const values = queryString.parse(props.location.search)
	console.log("YAMMER VALUES: ", values);
	getYammerAccess(values);
}

const Routes = (auth) => (
	<div>
		<Route exact path="/" render={(props) =>
			<Content auth={auth} {...props} />
		}/>
		<Route exact path="/client.apk" render={(props) => {
			return (<DownloadFile />)
		}}/>
		<Route path="/gitlab" render={(props) => {
			handleGitlab(props);
			return <CallbackRedirection {...props} />
		}}/>
		<Route path="/microsoft" render={(props) => {
			handleMicrosoft(props);
			return <CallbackRedirection {...props} />
		}}/>
		<Route path="/imgur" render={(props) => {
			handleImgur(props);
			return <CallbackRedirection {...props} />
		}}/>
		<Route path="/spotify" render={(props) => {
			handleSpotify(props);
			return <CallbackRedirection {...props} />
		}}/>
		<Route path="/facebook" render={(props) => {
			handleFacebook(props);
			return <CallbackRedirection {...props} />
		}}/>
		<Route path="/twitter" render={(props) => {
			handleTwitter(props);
			return <CallbackRedirection {...props} />
		}}></Route>
		<Route path="/yammer" render={(props) => {
			console.log("PASSING HERE TOO");
			handleYammer(props);
			return <CallbackRedirection {...props} />
		}}/>
		<Route path="/callback" render={(props) => {
			console.log("PROPS:", props);
			Auth = auth;
			handleAuthentication(props);
			return <Callback {...props} />
		}}/>
	</div>
);

function mapStateToProps(state) {
    return {
        gridAutomations: state.gridAutomations,
        display: state.display,
        stateNewAutomation: state.stateNewAutomation,
		isNextEnabled: state.isNextEnabled,
    };
}

export default connect(mapStateToProps)(Routes);