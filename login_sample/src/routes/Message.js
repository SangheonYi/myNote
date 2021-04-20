import React from "react";

const content = {
  title: "카카오톡 링크 4.0",
  description: "디폴트 템플릿 FEED",
  image_url:
    "http://k.kakaocdn.net/dn/Q2iNx/btqgeRgV54P/VLdBs9cvyn8BJXB3o7N8UK/kakaolink40_original.png",
  link: {
    mobile_web_url: "https://sangheonyi.github.io/myNote/#/chrome_scheme/",
    web_url: "https://sangheonyi.github.io/myNote/#/chrome_scheme/",
  },
};

const buttons = [
  {
    title: "크롬으로 가라",
    link: {
      mobile_web_url: "https://sangheonyi.github.io/myNote/#/chrome_scheme/",
      web_url: "https://sangheonyi.github.io/myNote/#/chrome_scheme/",
    },
  },
  {
    title: "앱으로 보기",
    link: {
      mobile_web_url: "https://sangheonyi.github.io/myNote/#/chrome_scheme/",
      web_url: "https://sangheonyi.github.io/myNote/#/chrome_scheme/",
    },
  },
];

const sendMSG = (receiver_uuids) => {
  window.Kakao.API.request({
    url: "/v1/api/talk/friends/message/default/send",
    data: {
      receiver_uuids,
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
    success: (response) => {
      console.log(response);
    },
    fail: (error) => {
      console.log(error);
    },
  });
};

const success = (res) => {
  const myFriend = res.elements[0];
  const { uuid } = myFriend;

  console.log("myFriend:");
  console.log(myFriend);
  console.log("uuid:");
  console.log(uuid);

  sendMSG([uuid]);
};

const fail = (err) => {
  console.log("err:");
  console.log(err);
};

class Message extends React.Component {
  state = {
    hasFriend: false,
  };

  render() {
    const { hasFriend } = this.state;
    if (window.Kakao.isInitialized()) getFriends();

    return (
      <div>
        <h1>MSG{hasFriend ? " sent" : " "}</h1>
      </div>
    );
  }
}

/*
 ** 친구 한테 보내기
 */

const getFriends = () => {
  if (window.Kakao.isInitialized())
    window.Kakao.API.request({
      url: "/v1/api/talk/friends",
      success,
      fail,
    });
};

export default Message;
