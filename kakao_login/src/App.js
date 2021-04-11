import React from "react";

class App extends React.Component {
  state = {
    loginResult: false,
  };

  componentDidMount() {
    const scope = "profile, age_range";
    const home = this;
    let loginResult = false;

    if (window.Kakao.isInitialized())
    window.Kakao.Auth.login({
      scope,
      success: function (response) {
        window.Kakao.Auth.setAccessToken(response.access_token);
        console.log(`is set?: ${window.Kakao.Auth.getAccessToken()}`);
        loginResult = true;
        home.setState({ loginResult });
      },
      fail: function (error) {
        console.log(error);
      },
    });
  };

  render() {
    const { loginResult } = this.state;
    const jsKey = "f803730b31a04aa1ffd90e1fbd5db921";

    if (!window.Kakao.isInitialized()) {
      window.Kakao.init(jsKey);
      console.log(window.Kakao.isInitialized());
    }

    return <h1>kakologin{loginResult ? " success" : " not yet"}</h1>;
  }
}

export default App;
