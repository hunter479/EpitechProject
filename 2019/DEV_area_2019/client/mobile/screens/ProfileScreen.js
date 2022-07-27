import React from 'react';
import { ScrollView, StyleSheet, Text, TextInput, Button } from 'react-native';

import { AuthSession } from 'expo';

import '../global.js'

export default class ProfileScreen extends React.Component {

  state = {
    value: global.id_token,
    url: global.url,
  }

  _onChangeText = (text) => {
    this.setState({value: text});
    global.id_token = text;
    console.log(global.id_token);
  }

  _onChangeUrl = (text) => {
    this.setState({url: text});
    global.url = text;
    console.log(global.url);
  }

  render() {
    return (
      <ScrollView style={styles.container}>
        <Text>Auth0 id token :</Text>
        <TextInput
          style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
          onChangeText={text => this._onChangeText(text)}
          value={this.state.value}
        />
        <Text>Server URL :</Text>
        <TextInput
          style={{ height: 40, borderColor: 'gray', borderWidth: 1 }}
          onChangeText={text => this._onChangeUrl(text)}
          value={this.state.url}
        />
        <Button
          title="Log Out"
          onPress={()=>
            this.props.navigation.navigate('Auth')
          }
        />
        <Text>{AuthSession.getRedirectUrl()}</Text>
    </ScrollView>
    );
  }
}

ProfileScreen.navigationOptions = {
  title: 'Profile',
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 15,
    backgroundColor: '#fff',
  },
});
