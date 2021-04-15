import React from "react";

class GetUser extends React.Component {
  state = {
    age_range: 0,
    profile_image_url: "",
  };

  componentDidMount(){
    const GetUser = this;

    window.Kakao.API.request({
      url: "/v2/user/me",
      success: function ({ kakao_account }) {
        const { age_range, profile } = kakao_account;
        console.log(age_range);
        console.log(`responsed img: ${profile.profile_image_url}`);
        GetUser.setState({
          age_range,
          profile_image_url: profile.profile_image_url,
        });
      },
      fail: function (error) {
        console.log(error);
      },
    });
  };

  render() {
    const { age_range, profile_image_url } = this.state;

    return (
      <div>
        <h1>{age_range ? age_range : "" }</h1>
        <img src={profile_image_url} alt="profile_img" title="img_title" />
      </div>
    );
  }
}

export default GetUser;
