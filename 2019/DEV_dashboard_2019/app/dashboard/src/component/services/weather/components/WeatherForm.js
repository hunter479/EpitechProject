import React from "react";

const WeatherForm = props => (
	<form onSubmit={props.api}>
		<input type="text" name="city" placeholder="City..."/>
		<input type="text" name="country" placeholder="Country..."/>
		<button>Get Weather</button>
	</form>
);

export default WeatherForm;