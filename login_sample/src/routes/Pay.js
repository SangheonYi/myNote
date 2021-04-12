import React from "react";
import axios from "axios";

class Pay extends React.Component {
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
      approval_url: "http://localhost:3000/pay/",
      fail_url: "http://localhost:3000/pay/",
      cancel_url: "http://localhost:3000/pay/",
    },
  };
  componentDidMount() {
    const { params } = this.state;
    axios({
      url: "/v1/payment/ready",
      method: "POST",
      headers: {
        Authorization: "KakaoAK aff05ca03a8103511ddc9bdd58f88055",
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
  }

  render() {
    const { next_redirect_pc_url, tid } = this.state;

    return (<div>
      <h2>Pay page</h2>
      <a href={ next_redirect_pc_url }>
        { next_redirect_pc_url }
      </a>
      </div>);
  }
}

export default Pay;
