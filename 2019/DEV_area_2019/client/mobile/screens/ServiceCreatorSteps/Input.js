import React from 'react';
import { View, Text, StyleSheet, Picker } from 'react-native';

const list = [
    {
        listItem: 'None',
    },
    {
        listItem: 'Github',
    },
    {
        listItem: 'Twitter',
    },
    {
        listItem: 'GMail',
    },
    {
        listItem: 'Intra',
    },
    {
        listItem: 'Spotify',
    },
    {
        listItem: 'Aled',
    },
];

const list2 = [
    {
        listItem: 'None',
    },
    {
        listItem: 'Github',
    },
    {
        listItem: 'Twitter',
    },
    {
        listItem: 'GMail',
    },
    {
        listItem: 'Intra',
    },
    {
        listItem: 'Spotify',
    },
    {
        listItem: 'Alo',
    },
];

export default class Input extends React.PureComponent {

    _onChangeValue1 = itemValue => {
        this.props.onChangeValue(this.props.name1, itemValue);
        this.setState({ value1: itemValue })
    };

    _onChangeValue2 = itemValue => {
        this.props.onChangeValue(this.props.name2, itemValue);
        this.setState({ value2: itemValue })
    };

    state = { value1: this.props.value1,
              value2 : this.props.value2
            };

    render() {
        return (
            <View>
                <Text> STEP 1 : CHOOSE SERVICES </Text>
                <Picker
                    selectedValue={ this.state.value1 }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValue1(itemValue)
                    }
                >
                    {list.map(el => (
                        <Picker.Item label={el.listItem} value={el.listItem}/>
                    ))}
                </Picker>
                <Text> STEP 1 : CHOOSE SERVICES 2 </Text>
                <Picker
                    selectedValue={ this.state.value2 }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValue2(itemValue)
                    }
                >
                    {list.map(el => (
                        <Picker.Item label={el.listItem} value={el.listItem}/>
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
  