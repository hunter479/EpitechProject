import React, { Fragment } from 'react'
import axios from "axios"

class CutenessWidget extends React.Component {
    state = {
        id: 0,
        picture: undefined,
        url: undefined
    }
    componentDidMount() {
        axios.get(`https://aws.random.cat/meow`).then(res => res.data.file).then(
            (result) => {
                this.setState({id: this.props.id, picture: result, url: `https://aws.random.cat/meow`})
            },
            (error) => {
                this.setState({id: this.props.id, picture: "error: api", url: `https://aws.random.cat/meow`})
            }
        )
    }
    callAPI = async(e) => {
        e.preventDefault()
        axios.get(this.state.url).then(res => res.data).then(
            (result) => {
                if (result.hasOwnProperty('file')) {
                    this.setState({id: this.props.id, picture: result.file})
                } else {
                    this.setState({id: this.props.id, picture: result.url})
                }
            },
            (error) => {
                this.setState({id: this.props.id, picture: "error: api"})
            }
        )
    }
    clickDog = (e) => {
        this.setState({url:`https://random.dog/woof.json`})
        this.callAPI(e)
    }
    clickCat = (e) => {
        this.setState({url:`https://aws.random.cat/meow`})
        this.callAPI(e)
    }
    render() {
        return (
            <Fragment>
                <button onClick={this.clickCat}>get Cat</button>
                <button onClick={this.clickDog}>get Dog</button>
                <button onClick={this.callAPI}>New picture</button>
                <img src={this.state.picture} width="400" height="400"></img>
            </Fragment>
        )
    }
}

export default CutenessWidget