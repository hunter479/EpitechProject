import React, { Fragment } from 'react';
import NavBar from './ui/NavBar'
import { connect } from 'react-redux'
import WidgetFactory from "./factory/WidgetFactory"
import { mapStateToProps, mapDispatchToProps } from "./redux/index"

class Dashboard extends React.Component {
    state = {
        index: 0
    }
    componentDidMount() {
        this.createW = this.createW.bind(this)
    }
    createW(component) {
        this.props.addService(WidgetFactory.build(component, this.state.index))
        this.setState({index: this.state.index + 1})
    }
    render() {
        return (
            <Fragment key={"Dashboard"}>
                <NavBar createW={i => this.createW(i)} logout={this.props.logout}></NavBar>
                <Fragment>{this.props.services.map(item => <li key={item + this.state.index}>{item}</li>)}</Fragment>
            </Fragment>
        )
    }
}

export default connect(mapStateToProps, mapDispatchToProps)(Dashboard)