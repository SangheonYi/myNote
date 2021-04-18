import React from "react";
import GetUser from "./GetUser";
import Message from "./Message";

class Home extends React.Component {
  state = {
    loginResult: false,
    msgRequest: false,
  };

  sendMSG = () => {
    if (this.state.loginResult && window.Kakao.isInitialized())
      this.setState({ loginResult: true, msgRequest: true });
  };

  klogin = () => {
    const scope = "profile, age_range, birthday, talk_message, friends";
    const home = this;
    let loginResult = false;

    window.Kakao.Auth.login({
      scope,
      success: function (response) {
        window.Kakao.Auth.setAccessToken(response.access_token);
        loginResult = true;
        home.setState({ loginResult });
      },
      fail: function (error) {
        console.log(error);
      },
    });
  };

  render() {
    const { loginResult, msgRequest } = this.state;
    const jsKey = "a337783bc70075abaeb0f047a09ced63";

    if (!window.Kakao.isInitialized()) {
      window.Kakao.init(jsKey);
      console.log(window.Kakao.isInitialized());
    }
    return (
      <div>
        <h1>{loginResult ? <GetUser /> : "not yet"}</h1>
        <button onClick={this.klogin}>login</button>
        <button onClick={this.sendMSG}>Message</button>
        {msgRequest ? <Message /> : "didn't send message"}
      </div>
    );
  }
}

export default Home;
