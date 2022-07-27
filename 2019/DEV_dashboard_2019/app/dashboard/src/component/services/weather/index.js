import WeatherDisp from "./components/WeatherDisp"
import WeatherForm from "./components/WeatherForm"
import {mapStateToProps, mapDispatchToProps} from "../../redux/index"
import {connect} from 'react-redux'
import React, { Fragment } from 'react'
import axios from 'axios';

class WeatherWidget extends React.Component {
    state = {
        id:0,
        temperature: undefined,
        city: undefined,
        country: undefined,
        humidity: undefined,
        description: undefined,
        error: "Please enter the values."
    }
    DelObj() {
        this.props.deleteService(this.state.id)
        this.forceUpdate()
    }
    componentDidMount() {
        this.setState({id: this.props.id})
    }
    API = async(props) => {
        const APIKEY = 'e2c72dd6970f2e095e7251cff714f95e'
        props.preventDefault();
        const city = props.target.elements.city.value;
        const country = props.target.elements.country.value;
        const api_call = await axios.get(`http://api.openweathermap.org/data/2.5/weather?q=${city},${country}&appid=${APIKEY}&units=metric`);
        const data = await api_call.data;
        if (city && country) {
            this.setState ({
                temperature: data.main.temp,
                city: data.name,
                country: data.sys.country,
                humidity: data.main.humidity,
                description: data.weather[0].description,
                error: ""
            });
        } else {
            this.setState ({
                temperature: undefined,
                city: undefined,
                country: undefined,
                humidity: undefined,
                description: undefined,
                error: "Please enter the values."
            });
    }}
    render() {
        return (
            <Fragment>
                <button onClick={() => this.DelObj()}>X</button>
                <WeatherForm api={this.API} />
                <WeatherDisp
                    temperature = {this.state.temperature}
                    city = {this.state.city}
                    country = {this.state.country}
                    humidity = {this.state.humidity}
                    description = {this.state.description}
                    error = {this.state.error}
                />
            </Fragment>
            )
    }
}

export default connect(mapStateToProps, mapDispatchToProps)(WeatherWidget)