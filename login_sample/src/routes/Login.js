import React from "react"

class Login extends React.Component {
/* 	componentWillMount()
	{
		const redirectUri = "http://localhost:3000/login/"
		window.Kakao.init(jsKey);
		  console.log(window.Kakao.isInitialized());
		fetch('https://jsonplaceholder.typicode.com/posts')
		.then(res => res.json())
		.then(data => console.log(data));
	} */

	render(props) {
	const {search} = props.location;
	console.log(search.split('='));
	return (
	<h2>
	Login page
	</h2>
	);
}

}

export default Login;
