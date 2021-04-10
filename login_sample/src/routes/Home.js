import React from "react";
import axios from "axios";

class Home extends React.Component {
	constructor(props) {
        super(props);
        this.state = {
        }
    }

  render() {
  const jsKey = "a337783bc70075abaeb0f047a09ced63"
  const redirectUri = "http://localhost:3000/login/"
  window.Kakao.init(jsKey);
	console.log(window.Kakao.isInitialized());
  window.Kakao.Auth.authorize({ redirectUri });

    return (
      <div>
        <h1>Hellow here is Home</h1>
		<button>
    {window.Kakao.isInitialized().toString()}
		</button>
      </div>
    );
  }
}

export default Home;
