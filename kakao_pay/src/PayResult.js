import React from "react";
import axios from "axios";

class PayResult extends React.Component {
  constructor(props) {
    super(props);
    const { params } = this.state;
    const {
      location: { search },
    } = props;

    params.pg_token = search.split("=")[1];
    console.log(`pg_token: ${params.pg_token}`);
    console.log(`tid: ${this.state.tid}`);
  }

  state = {
    tid: window.localStorage.getItem("tid"),
    params: {
      cid: "TC0ONETIME",
    //   tid: "T1234567890123456789",
      tid: window.localStorage.getItem("tid"),
      partner_order_id: "partner_order_id",
      partner_user_id: "partner_user_id",
      pg_token: "",
    },
  };

  componentDidMount() {
    const { params } = this.state;

	console.log("params:");
	console.log(params);
    axios({
      url: "/v1/payment/approve",
      method: "POST",
      headers: {
        Authorization: "KakaoAK de0e3076b485b703b1f1a4a2419440e6",
        "Content-type": "application/x-www-form-urlencoded;charset=utf-8",
      },
      params,
    }).then((response) => {
      console.log(response);

    //   console.log(next_redirect_pc_url);
    //   console.log(tid);
    //   this.setState({ next_redirect_pc_url, tid });
    });
  }

  render() {
    return (
      <div>
        <h2>Result page</h2>
      </div>
    );
  }
}
export default PayResult;
