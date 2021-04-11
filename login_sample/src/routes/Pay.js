import React from "react";
import { payReady } from "./api";

class Pay extends React.Component {
  constructor(props) {
    super(props);
    console.log("Pay created");
  }

  payReady = async () => {
    // set variables
    const item_name = "초코파이";
    const quantity = 1;
    const total_amount = 2200;
    const vat_amount = 200;
    const tax_free_amount = 0;

    // set redirect_url
    const approval_url = "http://localhost:3000/PayResult/";
    const fail_url = "http://localhost:3000/PayResult/";
    const cancel_url = "http://localhost:3000/PayResult/";

    // set data
    const data = [
      "cid=TC0ONETIME",
      "partner_order_id=partner_order_id",
      "partner_user_id=partner_user_id",
      `item_name=${item_name}`,
      `quantity=${quantity}`,
      `total_amount=${total_amount}`,
      `vat_amount=${vat_amount}`,
      `tax_free_amount=${tax_free_amount}`,
      `approval_url=${approval_url}`,
      `fail_url=${fail_url}`,
      `cancel_url=${cancel_url}`,
    ].join("&"); // encode data (application/x-www-form-urlencoded)

    const config = {
      headers: {
        Authorization: "KakaoAK aff05ca03a8103511ddc9bdd58f88055", // admin key
        "Content-type": "application/x-www-form-urlencoded;charset=utf-8",
      },
      data,
    };
    /* 	  try {
		await axios.get(`https://kapi.kakao.com/v1/payment/ready`,
		config);
	  } catch (err) {
		console.log(err);
	  } */
    console.log("is done?");
  };

  payReadyPrereq = async () => {
    // set variables
    const item_name = "초코파이";
    const quantity = 1;
    const total_amount = 2200;
    const vat_amount = 200;
    const tax_free_amount = 0;

    // set redirect_url
    const approval_url = "http://localhost:3000/PayResult/";
    const fail_url = "http://localhost:3000/PayResult/";
    const cancel_url = "http://localhost:3000/PayResult/";

    // set data
    const params = {
      cid: "TC0ONETIME",
      partner_order_id: "partner_order_id",
      partner_user_id: "partner_user_id",
      item_name,
      quantity,
      total_amount,
      vat_amount,
      tax_free_amount,
      approval_url,
      fail_url,
      cancel_url,
    };

    const response = payReady(params);
    console.log(response);
  };

  render(props) {
    this.payReadyPrereq();
    return <h2>Pay page</h2>;
  }
}

export default Pay;
