import { createStore } from "redux";
import manageServices from "./reducers";

const myStore = createStore(manageServices, window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__());

export default myStore;