import React from "react";
import {BrowserRouter,Route} from "react-router-dom"
import Login from "./routes/Login";
import Home from "./routes/Home";

function App() {
  return <BrowserRouter>
    <Route path="/" exact={true} component={Home}/>
    <Route path="/login" component={Login}/>
    </BrowserRouter>;
}
export default App;
