import React from 'react';
import { ScrollView, StyleSheet, View, Text, Image, RefreshControl, NativeModules, Alert } from 'react-native';
import { Card, ListItem, Button, Icon, ThemeProvider } from 'react-native-elements';

import '../global.js';
export default class MyServicesScreen extends React.Component {
  
  state = {
      refreshing: false,
  };
  
  _wait = (timeout) => {
    return new Promise(resolve => {
      setTimeout(resolve, timeout);
    });
  }

  _onRefresh = () => {
    this.setState({refreshing: true});
    this._wait(2000).then(() => {
      this.setState({refreshing: false});
    });
  }

  _deleteEvent = (e) => {
    let filteredArray = global.myServices.filter(item => item !== e);
    global.myServices = filteredArray;
    this.forceUpdate();
  }

  render() {
    return (
      <ScrollView
        style={styles.container}
        refreshControl={
          <RefreshControl
            refreshing={this.state.refreshing}
            onRefresh={this._onRefresh}/>}>

        {global.myServices.map(el => (
          <Card
            title={el.Service1 + " & " + el.Service2}>
            <Text>
              {"Account of " + el.Service1 + " : " + el.Account1}
            </Text>
            <Text>
              {"Account of " + el.Service2 + " : " + el.Account2}
            </Text>
            <Text>
              {"when : " + el.Action1}
            </Text>
            <Text>
              {"do : " + el.Action2}
            </Text>
            <Button
              onPress={() => this._deleteEvent(el)}
              title='DELETE SERVICE' />
          </Card>
        ))}
      </ScrollView>
    );
  }
}

MyServicesScreen.navigationOptions = {
  title: 'MyServices',
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 15,
    backgroundColor: '#fff',
  },
});
