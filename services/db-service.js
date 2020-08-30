const db = require('electron-db');
const { app, BrowserWindow } = require("electron");
 


const path = require('path')
let db_data = new Object();
 
// This will save the database in the same directory as the application.
const db_loc = path.join(__dirname, '')
 
db.createTable('db_settings', db_loc, (succ, msg) => {
  // succ - boolean, tells if the call is successful
  if (succ) {
    console.log(msg)
  } else {
    console.log('An error has occured. ' + msg)
  }
})


function saveSettings()
{
    let obj = new Object();
    obj.cap_Full = document.getElementById("form_full").value;
    obj.cap_Allowed = document.getElementById("form_allowed").value;
    obj.cap_PandMax = document.getElementById("form_pandMax").value;
    
    let where = {
        "id": 1598802039309
    }; 

    let set = {
        "cap_Full": obj.cap_Full,
        "cap_Allowed": obj.cap_Allowed,
        "cap_PandMax": obj.cap_PandMax,
    }

    db.updateRow('db_settings', db_loc, where, set, (succ, msg) => {
        // succ - boolean, tells if the call is successful
        console.log("Success: " + succ);
        console.log("Message: " + msg);
      });

}
 function saveCurrent()
 {
    let obj = new Object();
    obj.cap_current = document.getElementById("form_DashCurrent").value;

    let where = {
        "id": 1598802039309
    }; 

    let set = {
        "cap_Current": obj.cap_current
    }

    db.updateRow('db_settings', db_loc, where, set, (succ, msg) => {
        // succ - boolean, tells if the call is successful
        console.log("Success: " + succ);
        console.log("Message: " + msg);
      });

 }
  readCurrent();






function readCurrent()
{
    var res = 0;
    db.getRows('db_settings',db_loc, {
        id: 1598802039309
      }, (succ, result) => {
        // succ - boolean, tells if the call is successful
        console.log("Success: " + succ);
        res = result[0].cap_Current;
        document.getElementById("form_DashCurrent").value = res
        db_data.cap_Full = result[0].cap_Full;
        db_data.cap_Allowed = result[0].cap_Allowed;
        db_data.cap_PandMax = result[0].cap_PandMax;
        db_data.cap_Current = result[0].cap_Current;
      })
}

//function readDB

