import React from 'react';
import { ScrollView, StyleSheet, Text, Button, View } from 'react-native';
import { Header } from 'react-native-elements';

import { AuthSession } from 'expo';
import jwtDecode from 'jwt-decode';
import { getUserAutomations, addNewUser, getServices } from '../request';

import axios from 'axios';
import '../global.js';

const auth0Domain = 'https://dev-6yzqhmdk.eu.auth0.com';
const auth0ClientId = '5T2Ud0sZTyFtckxwMZzBJ8YG5HiMLaVm';

const client = axios.create({
    url: 'https://10.106.1.237:8080/about.json',
    responseType: 'json'
});
export default class AuthLoading extends React.Component {

    _handleResponse = (response) => {
        if (response.error) {
            Alert('Authentication error', response.error_description || 'something went wrong');
            return;
        }

        const jwtToken = response.id_token;
        const decoded = jwtDecode(jwtToken);

        getUserAutomations().then(res => {
            res.automation.map(el => {
                console.log(el.action);
                let array = [];
                array.Service1 = el.action.service;
                array.Service2 = el.reaction.service;
                array.Account1 = el.action.account;
                array.Account2 = el.reaction.account;
                array.Action1 = el.action.trigger;
                array.Action2 = el.reaction.trigger;
                global.myServices.push(array);
            });
        });

        addNewUser().then();
        getServices().then(res => {
            global.offline = res;
            global.services1 = [];
            global.services1.push("None");
            global.services2 = [];
            global.services2.push("None");
            res.map(el => {
                if (el.actions.length !== 0) {
                    global.services1.push(el.name);
                } if (el.reactions.length !== 0) {
                    global.services2.push(el.name);
                }
            })
        }).catch(() => {
            global.services1 = [];
            global.services1.push("None");
            global.services2 = [];
            global.services2.push("None");
            global.offline.map(el => {
                if (el.actions.length !== 0) {
                    global.services1.push(el.name);
                } if (el.reactions.length !== 0) {
                    global.services2.push(el.name);
                }
            })
        });

        this.props.navigation.navigate("Main");
    };

    _handlePressAsync = async () => {

        const redirectUrl = AuthSession.getRedirectUrl();
        console.log(redirectUrl);
        let authUrl =
            `${auth0Domain}/authorize` +
            toQueryString({
            client_id: auth0ClientId,
            response_type: 'id_token',
            scope: 'openid profile',
            nonce: 'nonce',
            redirect_uri: redirectUrl,
        });

        const result = await AuthSession.startAsync({
            authUrl: authUrl
        });

        if (result.type === 'success') {
            this._handleResponse(result.params);
        }
    };

    _handleAnonymous = () => {
        global.services1 = [];
        global.services1.push("None");
        global.services2 = [];
        global.services2.push("None");
        global.offline.map(el => {
            if (el.actions.length !== 0) {
                global.services1.push(el.name);
            } if (el.reactions.length !== 0) {
                global.services2.push(el.name);
            }
        })
        this.props.navigation.navigate('Main');
    };

    render() {
        return (
            <ScrollView>
            <Header
                centerComponent={{ text: 'AREA', style: { color: '#000' } }}
                containerStyle={{
                    backgroundColor: '#FFFFFF',
                    justifyContent: 'space-around',
                }}
            />
            <Button
                title="Log In"
                onPress={this._handlePressAsync}
            />
            <View>
            <Button
                title="Log In Anonymously"
                onPress={this._handleAnonymous}
                />
            </View>
            </ScrollView>
        );
    }
};

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
    container: {
        flex: 1,
        alignItems: 'center',
        justifyContent: 'center',
    },
});