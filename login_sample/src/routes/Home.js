import React from "react";
import axios from "axios";

function getReq() {
  const clientId = "client_id=e854947719be26303e9ccc6beb7e6300";
  const redirectUri = "redirect_uri=http://localhost:3000/login";
  const responseType = "response_type=code";
  const loginRequest = "https://kauth.kakao.com/oauth/authorize";
  const req = `${loginRequest}?${clientId}&${redirectUri}&${responseType}`;
}

class Home extends React.Component {
	constructor(props) {
        super(props);
        this.state = {
        }
    }

  render() {
	const clientId = "client_id=e854947719be26303e9ccc6beb7e6300";
	const redirectUri = "redirect_uri=http://localhost:3000/login/";
	const responseType = "response_type=code";
	const loginRequest = "https://kauth.kakao.com/oauth/authorize";
	const req = `${loginRequest}?${clientId}&${redirectUri}&${responseType}`;

	console.log(this.state);
    return (
      <div>
        <h1 onClick={getReq}>Hellow here is Home</h1>
		<a href={req}>
			login
		</a>
      </div>
    );
  }
}

export default Home;
