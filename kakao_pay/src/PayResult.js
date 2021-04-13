import React from "react";
import axios from "axios";

class PayReady extends React.Component {
  state = {
  };

 /*  componentDidMount() {
    const { params } = this.state;
    axios({
      url: "/v1/payment/ready",
      method: "POST",
      headers: {
        Authorization: "KakaoAK de0e3076b485b703b1f1a4a2419440e6",
        "Content-type": "application/x-www-form-urlencoded;charset=utf-8",
      },
      params,
    }).then((response) => {
      const {
        data: { next_redirect_pc_url, tid }
      } = response;

      console.log(next_redirect_pc_url);
      console.log(tid);
      this.setState({ next_redirect_pc_url, tid });
    });
  } */

  render(props) {
	  console.log(props);
    return (<div>
      <h2>Result page</h2>
      </div>);
  }
}
export default PayReady;
