import React from 'react';

import { View, StyleSheet, Alert } from 'react-native';

import MyServicesScreen from '../MyServicesScreen';

import Step from './Step';
import '../../global';
import { getAccounts, addAutomation } from '../../request';

export default class ServiceSelection extends React.PureComponent {
    static Step = Step;

    state = {
        index: 0,
        
        values: {
            ...this.props.initialValues,
        },
        disabledNext: true,
    };

    _actionManager = (name, value) => {
        if (name === "Service1") {
            var actions = [];
            global.offline.map(el => {
                if (el.name === value) {
                    actions = el.actions;
                }
            })
            global.action1 = [];
            global.action1.push("None");
            actions.map(el => {
                global.action1.push(el.name);
            });
        } else {
            var actions = [];
            global.offline.map(el => {
                if (el.name === value) {
                    actions = el.reactions;
                }
            })
            global.action2 = [];
            global.action2.push("None");
            actions.map(el => {
                global.action2.push(el.name);
            });
        }
    };

    _accountManager = (name, value) => {
        if (name === "Service1") {
            global.offline.map(el => {
                if (el.name === value) {
                    global.needAccount1 = !el.connection_needed;
                }
            })
            global.account1 = [];
            global.account1.push("None");
            getAccounts(value).then(res => {
                if (res.info.length === 0 && global.needAccount1 === true) {
                    global.account1.push("");
                }
                res.info.map(el => {
                    global.account1.push(el);
                })
            }).catch(() => {
                global.account1.push("");
            });
        } else {
            global.offline.map(el => {
                if (el.name === value) {
                    global.needAccount2 = !el.connection_needed;
                }
            })
            global.account2 = [];
            global.account2.push("None");
            getAccounts(value).then(res => {
                if (res.info.length === 0 && global.needAccount2 === true)
                global.account2.push("");
                res.info.map(el => {
                    global.account2.push(el);
                })
            }).catch(() => {
                global.account2.push("");
            });
        }
    }

    _nextStep = () => {
        if (this.state.index !== this.props.children.length - 1) {
            this.setState(prevState => ({
                index: prevState.index + 1,
            }))
        }

        this._checkDisabled(this.state.index + 1, 0, "Service1", "Service1", "Service2", this.state.values["Service1"]);
        this._checkDisabled(this.state.index + 1, 1, "Account1", "Account1", "Account2", this.state.values["Account1"]);
        this._checkDisabled(this.state.index + 1, 2, "Action1", "Action1", "Action2", this.state.values["Action1"]);

    };
    
    _prevStep = () => {
        if (this.state.index !== 0) {
            this.setState(prevState => ({
                index: prevState.index - 1,
            }))
        }

        this._checkDisabled(this.state.index - 1, 0, "Service1", "Service1", "Service2", this.state.values["Service1"]);
        this._checkDisabled(this.state.index - 1, 1, "Account1", "Account1", "Account2", this.state.values["Account1"]);
        this._checkDisabled(this.state.index - 1, 2, "Action1", "Action1", "Action2", this.state.values["Action1"]);

    };

    _onChangeValue = (name, value) => {
        this.setState(prevState => ({
            values: {
                ...prevState.values,
                [name]: value,
            },
        }));

        if (value === "None")
            this.setState({ disabledNext: true });
        else {
            this._checkDisabled(this.state.index, 0, name, "Service1", "Service2", value);
            this._checkDisabled(this.state.index, 1, name, "Account1", "Account2", value);
            this._checkDisabled(this.state.index, 2, name, "Action1", "Action2", value);
        }
        if (this.state.index === 0) {
            this._accountManager(name, value);
            this._actionManager(name, value);
        }
        if (name === "Fields2") {
            this.setState(prevState => ({
                values: {
                    ...prevState.values,
                    ["Fields2"]: value,
                },
            }))
        }
    };

    _checkDisabled = (index, cmpIndex, name, cmpName1, cmpName2, value) => {
        if (index === cmpIndex) {
            if (name === cmpName1)
                this.setState( { disabledNext: this._disabledNext(value, this.state.values[cmpName2]) });
            else
                this.setState( { disabledNext: this._disabledNext(value, this.state.values[cmpName1]) });
        }
    }

    _disabledNext = (value1, value2) => {
        if (value1 !== "None" && value2 !== "None")
            return false;
        else
            return true;
    }

    _onSubmit = () => {
        global.myServices.push(this.state.values);
        addAutomation(this.state.values).then();
    };

    render() {
        console.log('values', this.state);
        return (
            <View style={{ flex: 1 }}>
                {React.Children.map(this.props.children, (el, index) => {
                    if (index === this.state.index) {
                        return React.cloneElement(el, {
                            currentIndex: this.state.index,
                            nextStep: this._nextStep,
                            prevStep: this._prevStep,
                            isLast: this.state.index === this.props.children.length - 1,
                            onChangeValue: this._onChangeValue,
                            values: this.state.values,
                            onSubmit: this._onSubmit,
                            disabledNext: this.state.disabledNext,
                        });
                    }
                    return null;
                })}
            </View>
        );
    }
}

const styles = StyleSheet.create({
    container: {
      flex: 1,
      paddingTop: 15,
      backgroundColor: '#fff',
    },
  });