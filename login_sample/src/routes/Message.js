import React from "react";

const content = {
  title: "딸기 치즈 케익",
  description: "#케익 #딸기 #삼평동 #카페 #분위기 #소개팅",
  image_url:
    "http://k.kakaocdn.net/dn/Q2iNx/btqgeRgV54P/VLdBs9cvyn8BJXB3o7N8UK/kakaolink40_original.png",
  link: {
    mobile_web_url: "https://developers.kakao.com",
    web_url: "https://developers.kakao.com",
  },
};

const buttons = [
  {
    title: "웹으로 보기",
    link: {
      mobile_web_url: "https://developers.kakao.com",
      web_url: "https://developers.kakao.com",
    },
  },
  {
    title: "앱으로 보기",
    link: {
      mobile_web_url: "https://developers.kakao.com",
      web_url: "https://developers.kakao.com",
    },
  },
]

const success = res => {
  console.log("res:");
  console.log(res);
}

const fail = err => {
  console.log("err:");
  console.log(err);
}

/*
 ** 자기 자신한테 메시지 보내기
 */
class Message extends React.Component {
  render() {
    if (window.Kakao.isInitialized())
      window.Kakao.API.request({
        url: "/v2/api/talk/memo/default/send",
        data: {
          template_object: {
            object_type: "feed",
            content,
            social: {
              like_count: 286,
              comment_count: 45,
              shared_count: 845,
            },
            buttons,
          },
        },
        success,
        fail,
      });

    return (
      <div>
        <h1>MSG</h1>
      </div>
    );
  }
}

/*
 ** 친구 한테 보내기
 */

 class getFriends extends React.Component {
  render() {
    if (window.Kakao.isInitialized())
      window.Kakao.API.request({
        url: '/v1/api/talk/friends',
        success,
        fail
      });

    return (
      <div>
        <h1>MSG</h1>
      </div>
    );
  }
}
export default Message;
