import React from 'react';
import { Platform } from 'react-native';
import { createStackNavigator } from 'react-navigation-stack';
import { createBottomTabNavigator } from 'react-navigation-tabs';

import TabBarIcon from '../components/TabBarIcon';
import MyServicesScreen from '../screens/MyServicesScreen';
import NewServiceScreen from '../screens/NewServiceScreen';
import ProfileScreen from '../screens/ProfileScreen';

const config = Platform.select({
  web: { headerMode: 'screen' },
  default: {},
});

const MyServicesStack = createStackNavigator(
  {
    MyServices: MyServicesScreen,
  },
  config
);

MyServicesStack.navigationOptions = {
  tabBarLabel: 'My Services',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon
      focused={focused}
      name={
        Platform.OS === 'ios'
          ? `ios-home${focused ? '' : '-outline'}`
          : 'md-home'
      }
    />
  ),
};

MyServicesStack.path = '';

const NewServiceStack = createStackNavigator(
  {
    NewService: NewServiceScreen,
  },
  config
);

NewServiceStack.navigationOptions = {
  tabBarLabel: 'New Service',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon focused={focused} name={Platform.OS === 'ios' ? 'ios-add-circle' : 'md-add-circle'} />
  ),
};

NewServiceStack.path = '';

const ProfileStack = createStackNavigator(
  {
    'Profile': ProfileScreen,
  },
  config
);

ProfileStack.navigationOptions = {
  tabBarLabel: 'Profile',
  tabBarIcon: ({ focused }) => (
    <TabBarIcon focused={focused} name={Platform.OS === 'ios' ? 'ios-person' : 'md-person'} />
  ),
};

ProfileStack.path = '';

const tabNavigator = createBottomTabNavigator({
  MyServicesStack,
  NewServiceStack,
  ProfileStack,
});

tabNavigator.path = '';

export default tabNavigator;
