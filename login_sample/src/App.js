import React from "react";
import {BrowserRouter,Route} from "react-router-dom"
import Message from "./routes/Message";
import Home from "./routes/Home";
import Navigation from "./routes/Navigation";

function App() {
  return <BrowserRouter>
  <Navigation/>
    <Route path="/" exact={true} component={Home}/>
    <Route path="/Message" component={Message}/>
    </BrowserRouter>;
}
export default App;
