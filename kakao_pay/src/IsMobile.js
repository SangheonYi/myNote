function IsMobile() {
  const filter = "win16|win32|win64|mac";
  let result = "";

  if (navigator.platform) {
    if (0 > filter.indexOf(navigator.platform.toLowerCase())) result = true;
    else result = false;
  }
  return result;
}

export default IsMobile();
