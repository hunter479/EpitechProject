import React from 'react';
import { ScrollView, StyleSheet, View, Text, Button } from 'react-native';

import ServiceSelection from './ServiceCreatorSteps/ServiceSelection'
import FirstStep from './ServiceCreatorSteps/FirstStep'
import SecondStep from './ServiceCreatorSteps/SecondStep'
import FinalStep from './ServiceCreatorSteps/FinalStep'
export default class NewServiceScreen extends React.Component {
    render() {
        return (
            <ScrollView style={styles.container}>
                 <ServiceSelection
                    initialValues={{
                        Service1: 'None',
                        Service2: 'None',
                        Account1: 'None',
                        Account2: 'None',
                        Action1: 'None',
                        ActionName1: '',
                        Action2: 'None',
                        ActionName2: '',
                        Fields1: [],
                        Fields2: [],
                    }}
                >
                <ServiceSelection.Step key='FirstStep'>
                    {({ onChangeValue, values, canNext }) => (
                        <View style={styles.container}>
                            <FirstStep
                                onChangeValue={onChangeValue}
                                values={values}
                                nameFirstService={"Service1"}
                                nameSecondService={"Service2"}
                            ></FirstStep>
                        </View>
                    )}
                </ServiceSelection.Step>

                <ServiceSelection.Step key='SecondStep'>
                    {({ onChangeValue, values }) => (
                        <View style={styles.container}>
                            <SecondStep
                                onChangeValue={onChangeValue}
                                values={values}
                                nameFirstAccount={"Account1"}
                                nameSecondAccount={"Account2"}
                            ></SecondStep>
                        </View>
                    )}
                </ServiceSelection.Step>

                <ServiceSelection.Step key='ThirdStep'>
                    {({ onChangeValue, values }) => (
                        <View style={styles.container}>
                            <FinalStep
                                onChangeValue={onChangeValue}
                                values={values}
                                nameFirstAction={"Action1"}
                                nameSecondAction={"Action2"}
                            ></FinalStep>
                        </View>
                    )}
                </ServiceSelection.Step>
                </ServiceSelection>
            </ScrollView>
        );
    }
}

NewServiceScreen.navigationOptions = {
  title: 'New Service',
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    paddingTop: 15,
    backgroundColor: '#fff',
  },
});
