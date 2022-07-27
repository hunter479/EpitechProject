import React from 'react';
import { View, Text, StyleSheet, Picker, Button, Modal, Alert, TextInput } from 'react-native';

import { revoke, authorize } from 'react-native-app-auth';

import * as AppAuth from 'expo-app-auth';

import '../../global.js';
import { AuthSession, Linking } from 'expo';

const oauth2 = {
        "microsoft": "https://login.microsoftonline.com/901cb4ca-b862-4029-9306-e5cd0f6d9f86/oauth2/v2.0/authorize?client_id=971ba623-d09d-40ab-9f46-29ad897dd88d&response_type=code&scope=openid+Mail.Read+offline_access+User.ReadWrite+User.ReadBasic.All",
        "yammer": "https://www.yammer.com/oauth2/authorize?client_id=cl7coSDecOhvh08AkWKg&response_type=code&redirect_url=https://www.area.com:8081/yammer",
        "gitlab": "https://gitlab.com/oauth/authorize?client_id=3dea71e60ed478864d409ca1aee82d5ecd4f4234dc3621d46e15d240beaa9faa&redirect_uri=https://www.area.com:8081/gitlab&response_type=code&scope=api+read_user+read_repository+write_repository+read_registry+openid+profile+email",
        "imgur": "https://api.imgur.com/oauth2/authorize?client_id=a12e84096da979d&response_type=token",
        "spotify": "https://accounts.spotify.com/authorize?client_id=4c9db4d390d54c04ab928d78c19ec1af&response_type=code&redirect_uri=host.exp.exponent&scope=user-read-private%20user-read-email%20user-modify-playback-state",
        "facebook": "https://www.facebook.com/v6.0/dialog/oauth?response_type=token&display=popup&client_id=203866147425781&redirect_uri=https://www.area.com:8081/facebook&auth_type=rerequest&scope=user_hometown%2Cuser_location%2Cuser_likes%2Cuser_photos%2Cuser_status%2Cuser_posts%2Cuser_age_range%2Cpublic_profile%2Cuser_friends%2Cemail%2Cuser_birthday%2Cuser_gender%2Cuser_link%2Cuser_tagged_places%2Cuser_videos",
        "twitter": "https://api.twitter.com/oauth/authorize?oauth_token="
}

export default class SecondStep extends React.PureComponent {
    
    state = {
                value: "",
                modalVisible: false,
                valueFirstAccount: this.props.values["Account1"],
                valueSecondAccount : this.props.values["Account2"]
            };

    _onChangeValueFirstAccount = itemValue => {
        this.props.onChangeValue(this.props.nameFirstAccount, itemValue);
        this.setState({ valueFirstAccount: itemValue });
   };

    _onChangeValueSecondAccount = itemValue => {
        this.props.onChangeValue(this.props.nameSecondAccount, itemValue);
        this.setState({ valueSecondAccount: itemValue });
    };

    _setModalVisible(visible) {
        this.setState({modalVisible: visible});
    };

    _onChangeText = (text) => {
        this.setState({value: text});
        console.log(global.id_token);
    };

    _handlePressAsync = async () => {
        const redirectUrl = AuthSession.getRedirectUrl();
        console.log(redirectUrl);

        if (this.props.values["Service1"] === "Microsoft") {
            let url = oauth2.microsoft + "&redirect_uri=" + redirectUrl;

            const result = await AuthSession.startAsync({
                authUrl: url
            });
            console.log(result);
        }
    };

    render() {
        return (
            <View>
                <Text> Choose {this.props.values["Service1"]} account </Text>
                <Picker
                    selectedValue={ this.state.valueFirstAccount }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValueFirstAccount(itemValue)
                    }
                >
                    {global.account1.map(el => (
                        <Picker.Item label={el} value={el}/>
                    ))}
                </Picker>
                <Button
                    title="ADD ACCOUNT"
                    disabled={global.needAccount1}
                    onPress={this._handlePressAsync}
                />
                <Text> Choose {this.props.values["Service2"]} account </Text>
                <Picker
                    selectedValue={ this.state.valueSecondAccount }
                    onValueChange={ (itemValue, itemIndex) => 
                        this._onChangeValueSecondAccount(itemValue)
                    }
                >
                    {global.account2.map(el => (
                        <Picker.Item label={el} value={el}/>
                    ))}
                </Picker>
                <Button
                    title="ADD ACCOUNT"
                    disabled={global.needAccount2}
                    onPress={this._handlePressAsync}
                /> 
            </View>
        );
    }
}

function toQueryString(params) {
    return (
        '?' +
        Object.entries(params)
        .map(
            ([key, value]) =>
            `${encodeURIComponent(key)}=${encodeURIComponent(value)}`
            )
        .join('&')
    );
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
  