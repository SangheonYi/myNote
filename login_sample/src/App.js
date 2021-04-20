import React from "react";
import {HashRouter,Route} from "react-router-dom"
import Message from "./routes/Message";
import Home from "./routes/Home";
import Navigation from "./routes/Navigation";
import ChromeScheme from "./routes/ChromeScheme";

function App() {
  return <HashRouter>
  <Navigation/>
    <Route path="/" exact={true} component={Home}/>
    <Route path="/message" component={Message}/>
    <Route path="/chrome_scheme" component={ChromeScheme}/>
    </HashRouter>;
}
export default App;
