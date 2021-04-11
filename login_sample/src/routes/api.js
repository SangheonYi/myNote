import axios from "axios";

const Kakao = axios.create({
  baseURL: "https://kapi.kakao.com", // 공통 요청 경로를 지정해준다.
  headers: {
    Authorization: "KakaoAK aff05ca03a8103511ddc9bdd58f88055", // 공통으로 요청 할 헤더
    "Content-type": "application/x-www-form-urlencoded;charset=utf-8"
  }
});

// search blog api
export const payReady = params => {
  return Kakao.get("/v1/payment/ready", { params });
};
