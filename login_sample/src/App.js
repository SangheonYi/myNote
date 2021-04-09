import React from "react";
import {HashRouter,Route} from "react-router-dom"
import Login from "./routes/Login";
import Home from "./routes/Home";

function App() {
  return <HashRouter>
    <Route path="/" exact={true} component={Home}/>
    <Route path="/login" component={Login}/>
    </HashRouter>;
}
export default App;
