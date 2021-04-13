import React from "react";
import PayReady from "./PayReady";
import PayResult from "./PayResult";
import {BrowserRouter,Route} from "react-router-dom";

class App extends React.Component {
  render() {
    return (
      <BrowserRouter>
    <Route path="/" exact={true} component={PayReady}/>
    <Route path="/payresult" component={PayResult}/>
    </BrowserRouter>
    );
  }
}
export default App;
