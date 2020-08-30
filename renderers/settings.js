// renderers/settings.js

const { remote } = require("electron");
const axios = require("axios");
const authService = remote.require("./services/auth-service");
const authProcess = remote.require("./main/auth-process");

const webContents = remote.getCurrentWebContents();

webContents.on("dom-ready", () => {
  const profile = authService.getProfile();
  document.getElementById("picture").src = profile.picture;
  document.getElementById("name").innerText = profile.name;
 // document.getElementById("success").innerText =
  //  "You successfully used OpenID Connect and OAuth 2.0 to authenticate.";
});

document.getElementById("logout").onclick = () => {
  authProcess.createLogoutWindow();
  remote.getCurrentWindow().close();
};



function updateCapacity()
{
    var full = document.getElementById("form_full").value;
    var allowed = document.getElementById("form_allowed").value;
    document.getElementById("form_pandMax").value = full * (allowed/100.0)

}