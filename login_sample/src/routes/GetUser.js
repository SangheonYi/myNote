import React from "react";

class GetUser extends React.Component {
  state = {
    profile_image_url: "",
    age_range: "",
    birthday: ""
  };

  componentDidMount() {
    const GetUser = this;
    window.Kakao.API.request({
      url: "/v2/user/me",
      success: function ({ kakao_account }) {
        const { age_range, profile, birthday } = kakao_account;
        console.log(age_range);
        console.log(birthday);
        GetUser.setState({
          profile_image_url: profile.profile_image_url,
          age_range,
          birthday
        });
      },
      fail: function (error) {
        console.log(error);
      },
    });
  };

  render() {
    const { profile_image_url, age_range, birthday } = this.state;
    return (
      <div>
        <h1>{ age_range }</h1>
        <h1>{ birthday }</h1>
        <img src={profile_image_url} alt="profile_img" title="img_title" />
      </div>
    );
  }
}

export default GetUser;
