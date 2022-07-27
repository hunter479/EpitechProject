import {ADD, REMOVE} from "./const"
const initialState = {services:[]};

function manageServices(state = initialState, action) {
    switch(action.type) {
        case(ADD):
            state.services.push(action.payload)
            return state
        case(REMOVE):
            var cp = state.services;
            // var index = cp.indexOf(action.payload)
            // cp.filter(item=> item != state.services[action.payload])
            // console.log(cp)
            // const newState = state.filter( val => val !== action.index );
            // console.log("index= ", index)
            // console.log("action.payload= ", action.payload)
            // if (index !== -1) {
                // cp.splice(index, 1)
                // state.services.setState(cp)
            // }
            return state
        default:
            return state
    }
}

export default manageServices