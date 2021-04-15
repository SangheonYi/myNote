import React from "react";
import {BrowserRouter,Route} from "react-router-dom"
import Messege from "./routes/Messege";
import Home from "./routes/Home";
import Navigation from "./routes/Navigation";

function App() {
  return <BrowserRouter>
  <Navigation/>
    <Route path="/" exact={true} component={Home}/>
    <Route path="/Messege" component={Messege}/>
    </BrowserRouter>;
}
export default App;
