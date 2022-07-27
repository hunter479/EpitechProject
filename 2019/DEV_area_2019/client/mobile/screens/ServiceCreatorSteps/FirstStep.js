import React from 'react';
import { View, Text, StyleSheet, Picker } from 'react-native';

import '../../global.js';

export default class FirstStep extends React.PureComponent {

    _onChangeValueFirstService = itemValue => {
        this.props.onChangeValue(this.props.nameFirstService, itemValue);
        this.setState({ valueFirstService: itemValue });
    };

    _onChangeValueSecondService = itemValue => {
        this.props.onChangeValue(this.props.nameSecondService, itemValue);
        this.setState({ valueSecondService: itemValue });
    };

    state = { valueFirstService: this.props.values["Service1"],
              valueSecondService : this.props.values["Service2"]
            };

    render() {
        return (
            <View>
                <Text> Connect this... </Text>
                <Picker
                    selectedValue={ this.state.valueFirstService }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValueFirstService(itemValue)
                    }
                >
                    {global.services1.map(el => (
                        <Picker.Item label={el} value={el}/>
                    ))}
                </Picker>
                <Text> with this ! </Text>
                <Picker
                    selectedValue={ this.state.valueSecondService }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValueSecondService(itemValue)
                    }
                >
                    {global.services2.map(el => (
                        <Picker.Item label={el} value={el}/>
                    ))}
                </Picker>
 
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
});
  