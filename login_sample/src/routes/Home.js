import React from "react"

function Home(props) {
	console.log(props);
	const clientId = "client_id=e854947719be26303e9ccc6beb7e6300";
	const redirectUri = "redirect_uri=http://localhost:3000/login";
	const responseType = "response_type=code";
	const loginRequest = "https://kauth.kakao.com/oauth/authorize";

	return (
		<div>
		<h1>
			Hellow here is Home
		</h1>
		<a href = {`${loginRequest}?${clientId}&${redirectUri}&${responseType}`}>
			login
		</a>
		</div>
	)
}

export default Home;
