import React from 'react';
import { createAppContainer, createSwitchNavigator } from 'react-navigation';
import { AuthSession } from 'expo'

import TabNavigator from './TabNavigator';
import AuthLoading from '../screens/AuthLoading';
import ServiceSelection from '../screens/ServiceCreatorSteps/ServiceSelection';

export default createAppContainer(
  createSwitchNavigator({
    Auth: AuthLoading,
    Main: TabNavigator,
    ServSelec: ServiceSelection,
  })
);
