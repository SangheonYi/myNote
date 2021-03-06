import React from "react";
import axios from "axios";
import IsMobile from "./IsMobile";

class PayReady extends React.Component {
  state = {
    next_redirect_pc_url: "",
    tid: "",
    params: {
      cid: "TC0ONETIME",
      partner_order_id: "partner_order_id",
      partner_user_id: "partner_user_id",
      item_name: "초코파이",
      quantity: 1,
      total_amount: 2200,
      vat_amount: 200,
      tax_free_amount: 0,
      approval_url: "http://localhost:3000/payresult",
      fail_url: "http://localhost:3000/payresult",
      cancel_url: "http://localhost:3000/payresult",
    },
  };

  payReady = () => {
    const { params } = this.state;
    console.log("ready");

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
        data: { next_redirect_mobile_url, next_redirect_pc_url, tid },
      } = response;
	  window.localStorage.setItem("tid", tid);
      if (IsMobile) {
        console.log(next_redirect_mobile_url);
        window.location.href = next_redirect_mobile_url;
        }
      else
        window.location.href = next_redirect_pc_url;
    });
  }

  render() {
    console.log("render");
    return (
      <div>
        <h2 onClick={ this.payReady}>Pay page</h2>
      </div>
    );
  }
}
export default PayReady;
