import React from 'react';
import { View, StyleSheet, Button } from 'react-native';
export default class Step extends React.PureComponent {
    state = { };
    render() {
        return (
            <View style={styles.root}>
                {this.props.children({
                    onChangeValue: this.props.onChangeValue,
                    values: this.props.values,
                })}
                <View style={styles.buttonWrapper}>
                    <Button
                        title="Prev"
                        disabled={this.props.currentIndex === 0}
                        onPress={this.props.prevStep}
                    />
                    {this.props.isLast ? (
                        <Button
                            title="Submit"
                            disabled={ this.props.disabledNext }
                            onPress={this.props.onSubmit}
                        />
                    ) : (
                        <Button
                            title="Next"
                            disabled={ this.props.disabledNext }
                            onPress={this.props.nextStep}
                        />
                    )}
                </View>
            </View>
        );
    }
}

const styles = StyleSheet.create({
    root: {
        flex: 1,
    },

    buttonWrapper: {
        flexDirection: 'row',
        height: 80,
        alignItems: 'center',
        justifyContent: 'space-around',
    },
});