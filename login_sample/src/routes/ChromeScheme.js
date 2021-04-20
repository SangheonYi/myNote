import React from "react";

class ChromeScheme extends React.Component {
  render() {
    const schme = "scheme=http;package=com.android.chrome;end";
    const redirect =
      "intent://www.naver.com#Intent;";
    console.log(redirect + schme);
    window.location.href = redirect + schme;

    return <h1>should go chrome</h1>;
  }
}

export default ChromeScheme;
