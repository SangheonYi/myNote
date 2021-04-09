import React from "react"

function Login(props) {
	const {search} = props.location;
	console.log(search.split('='));

	return (
	<h2>
	Login page
	</h2>
	);
}

export default Login;
