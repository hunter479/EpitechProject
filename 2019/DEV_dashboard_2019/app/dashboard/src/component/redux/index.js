import {ADD, REMOVE} from "./const"

function addServiceReducer(payload){
    return {
        type: ADD,
        payload
    }
}

function removeServiceReducer(payload){
    return {
        type: REMOVE,
        payload
    }
}

const mapStateToProps = (state) => {
    return {
        services: state.services
    }
}

const mapDispatchToProps = (dispatch) => {
    return {
        addService: (payload) => {dispatch(addServiceReducer(payload))},
        deleteService: (payload) => {dispatch(removeServiceReducer(payload))}
    }
}

export {
    mapStateToProps,
    mapDispatchToProps
}