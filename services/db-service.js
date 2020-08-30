const db = require('electron-db');
const { app, BrowserWindow } = require("electron");
 


const path = require('path')
 
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