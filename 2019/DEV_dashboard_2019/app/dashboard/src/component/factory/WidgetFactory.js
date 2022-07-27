import React from 'react'
import WeatherWidget from "../services/weather/index"
import CutenessWidget from "../services/Cuteness/index"
import { WEATHER, CUTENESS } from "./const"

export default class WidgetFactory {
    static build(action, idComp) {
        switch(action.type) {
            case(WEATHER):
                return (<WeatherWidget key={idComp} id={idComp + action.type}/>)
            case(CUTENESS):
                return (<CutenessWidget key={idComp} id={idComp + action.type}/>)
            default:
                return ({})
        }
    }
}