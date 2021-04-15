import React from "react";

class Messege extends React.Component {
  render() {
	  console.log(window.Kakao.isInitialized());
	if (window.Kakao.isInitialized())
    window.Kakao.API.request({
      url: "/v2/api/talk/memo/default/send",
      data: {
        template_object: {
          object_type: "feed",
          content: {
            title: "딸기 치즈 케익",
            description: "#케익 #딸기 #삼평동 #카페 #분위기 #소개팅",
            image_url:
              "http://k.kakaocdn.net/dn/Q2iNx/btqgeRgV54P/VLdBs9cvyn8BJXB3o7N8UK/kakaolink40_original.png",
            link: {
              mobile_web_url: "https://developers.kakao.com",
              web_url: "https://developers.kakao.com",
            },
          },
          social: {
            like_count: 286,
            comment_count: 45,
            shared_count: 845,
          },
          buttons: [
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
          ],
        },
      },
      success: function (res) {
        console.log("success: " + JSON.stringify(res));
      },
      fail: function (err) {
        console.log("error: " + JSON.stringify(err));
      },
    });
    return (
      <div>
        <h1>MSG</h1>
      </div>
    );
  }
}

export default Messege;
