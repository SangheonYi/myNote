import React from "react";
import GetUser from "./GetUser";

class Home extends React.Component {
  state = {
    loginResult: false
  };

  componentDidMount() {
    const scope = "profile, age_range, birthday";
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
  }

  render() {
    const { loginResult } = this.state;
    const jsKey = "a337783bc70075abaeb0f047a09ced63";

    if (!window.Kakao.isInitialized()) {
      window.Kakao.init(jsKey);
      console.log(window.Kakao.isInitialized());
    }
    return (
      <div>
        <h1>{loginResult ? <GetUser/>: "not yet"}</h1>
      </div>
    );
  }
}

export default Home;
