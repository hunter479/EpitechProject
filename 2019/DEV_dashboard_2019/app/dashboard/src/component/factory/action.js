import { WEATHER, CUTENESS } from "./const"

function CreateWeather() {
    return {
        type: WEATHER
    }
}

function CreateCuteness() {
    return {
        type: CUTENESS
    }
}

export {
    CreateWeather,
    CreateCuteness
}