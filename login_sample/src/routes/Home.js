import React from "react";

class Home extends React.Component {
  constructor(props) {
    super(props);
    console.log(`created:${this.state}`);
  }

  state = {
    isLoading: true,
    profile_img: null,
  };

  getUser = async () => {
    let {kakao_account} = await window.Kakao.API.request({
      url: "/v2/user/me",
      success: function ({ kakao_account }) {
        let {age_range, profile} = kakao_account;
        console.log(kakao_account);

        console.log(age_range);
        console.log(`responsed img: ${profile.profile_image_url}`);
        console.log(profile.profile_image_url);
      },
      fail: function (error) {
        console.log(error);
      },
    });
    const { age_range, profile, birthday } = kakao_account;
    console.log(`set=========`);
    console.log(age_range);
    console.log(profile.profile_image_url);
    console.log(birthday);
    this.setState({ isLoading: false, profile_img: profile.profile_image_url });
  };

  login = async () => {
    const scope = "profile, age_range, birthday";

    await window.Kakao.Auth.login({
      scope,
      success: function (response) {
        console.log(response);
        console.log(`login success: ${response.access_token}`);
        window.Kakao.Auth.setAccessToken(response.access_token);
        console.log(`is set?: ${window.Kakao.Auth.getAccessToken()}`);
      },
      fail: function (error) {
        console.log(error);
      },
    });
  };

  componentDidMount() {
    const jsKey = "a337783bc70075abaeb0f047a09ced63";
    const redirectUri = "http://localhost:3000/login/";

    if (this.state.isLoading) {
      window.Kakao.init(jsKey);
      console.log(window.Kakao.isInitialized());
      this.login();

      if (window.Kakao.Auth.getAccessToken()) this.getUser();
    }
  }

  render() {
    const { isLoading, profile_img } = this.state;

    return (
      <section className="container">
        {isLoading ? (
          <div className="loader">
            <span className="loader_text">Loading...</span>
          </div>
        ) : (
          <div>
            <img src={profile_img} alt="" title={"title"} />
          </div>
        )}
      </section>
    );
  }
}

export default Home;
