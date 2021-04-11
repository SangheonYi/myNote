import React from "react";
import {BrowserRouter,Route} from "react-router-dom"
import Pay from "./routes/Pay";
import Home from "./routes/Home";
import Navigation from "./routes/Navigation";
import PayResult from "./routes/PayResult";

function App() {
  return <BrowserRouter>
  <Navigation/>
    <Route path="/" exact={true} component={Home}/>
    <Route path="/Pay" component={Pay}/>
    <Route path="/PayResult" component={PayResult}/>
    </BrowserRouter>;
}
export default App;
