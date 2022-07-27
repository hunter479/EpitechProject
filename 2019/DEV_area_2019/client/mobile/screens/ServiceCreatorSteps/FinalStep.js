import React from 'react';
import { View, Text, StyleSheet, Picker, TextInput, Modal, Button, Alert } from 'react-native';

import '../../global.js'

export default class FinalStep extends React.PureComponent {

    _onChangeValueFirstAction = itemValue => {
        var actions = []
        var itemValueId;

        this.setState({textInput1: []});
        global.fields1 = [];
        global.offline.map(el => {
            if (el.name === this.props.values["Service1"]) {
                actions = el.actions;
            }
        })
        actions.map(el => {
            if (el.name === itemValue) {
                itemValueId = el.id;
                global.fields1 = el.fields;
            }
        })
        if (global.fields1) {
            global.fields1.map(el => {
                let textInput1 = this.state.textInput1;
                textInput1.push(
                    <View>
                        <Text>{el.key + " : " + el.label}</Text>
                        <TextInput
                            style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
                            onChangeText={text => this._onChangeText(1, text, el.key)}
                        />
                    </View>
                );
            this.setState({ textInput1 })
           })
           this.props.onChangeValue("Fields1", global.fields1);
        }
        this.props.onChangeValue("ActionName1", itemValue);
        this.props.onChangeValue(this.props.nameFirstAction, itemValueId);
        this.setState({ valueFirstAction: itemValue });
   };

    _onChangeValueSecondAction = itemValue => {
        var actions = []
        var itemValueId;
        
        this.setState({textInput2: []});
        global.fields2 = []
        global.offline.map(el => {
            if (el.name === this.props.values["Service2"]){
                actions = el.reactions;
            }
        })
        actions.map(el => {
            if (el.name === itemValue) {
                itemValueId = el.id;
                global.fields2 = el.fields;
            }
        })
        if (global.fields2) {
            global.fields2.map(el => {
                let textInput2 = this.state.textInput2;
                textInput2.push(
                    <View>
                        <Text>{el.key + " : " + el.label}</Text>
                        <TextInput
                            style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
                            onChangeText={(text) => this._onChangeText(2, text, el.key)}
                        />
                    </View>
                );
                this.setState({ textInput2 })
            })
            this.props.onChangeValue("Fields2", global.fields2);
        }
        this.props.onChangeValue("ActionName2", itemValue);
        this.props.onChangeValue(this.props.nameSecondAction, itemValueId);
        this.setState({ valueSecondAction: itemValue });
    };

    _onChangeText = (which, text, key) => {
        if (which === 1) {
            global.fields1.map(el => {
                if (el.key === key)
                    el.label = text;
            })
            this.props.onChangeValue("Fields1", global.fields1);
        } else {
            global.fields2.map(el => {
                if (el.key === key)
                    el.label = text;
            })
            this.props.onChangeValue("Fields2", global.fields2);
        }
    }
 
    state = {
                textInput1: [],
                textInput2: [],
                valueFirstAction: this.props.values["Action1"],
                valueSecondAction : this.props.values["Action2"]
            };

    render() {
        return (
            <View>
                <Text> Choose your action with {this.props.values["Service1"]}... </Text>
                <Picker
                    selectedValue={ this.state.valueFirstAction }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValueFirstAction(itemValue)
                    }
                >
                    {global.action1.map(el => (
                        <Picker.Item label={el} value={el}/>
                    ))}
                </Picker>
                <View>
                    {this.state.textInput1.map((value, index) => {
                        return value
                    })}
                </View>
                <Text> and your reaction with {this.props.values["Service2"]} </Text>
                <Picker
                    selectedValue={ this.state.valueSecondAction }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValueSecondAction(itemValue)
                    }
                >
                    {global.action2.map(el => (
                        <Picker.Item label={el} value={el}/>
                    ))}
                </Picker>
                <View>
                    {this.state.textInput2.map((value, index) => {
                        return value
                    })}
                </View>
            </View>
        );
    }
}

const styles = StyleSheet.create({
    root: {
        backgroundColor: '#f4f9f4',
        width: '90%',
        height: 45,
        paddingHorizontal: 16,
        borderRadius: 6
    },
    buttonWrapper: {
        flexDirection: 'row',
        height: 80,
        alignItems: 'center',
        justifyContent: 'space-around',
    },
});
  