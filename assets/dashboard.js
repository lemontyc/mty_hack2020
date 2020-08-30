/* globals Chart:false, feather:false */

var pandMax;

(function () {
    'use strict'
  
    feather.replace()
  

  }())

  function getPandMax()
  {
    //This needs to read from a database
    pandMax = document.getElementById("form_pandMax").value;
    return pandMax;
  }

  function addCurrent()
  {
    var currentValue = parseInt(document.getElementById("form_DashCurrent").value);
    if(currentValue < getPandMax())
    {
      // Check for low capacity and warn!
      if(checkwarning())
      {
        document.getElementById("dash_Alert").innerText = "Reaching full capacity!"
        document.getElementById("dash_Alert").className = "alert alert-warning"
      }else{
        document.getElementById("dash_Alert").innerText = "Capactity: OK"
        document.getElementById("dash_Alert").className = "alert alert-success"
      }

      // Increment capacity
      document.getElementById("form_DashCurrent").value = currentValue + 1

      // Vlaidate full capacity and alert
      if(document.getElementById("form_DashCurrent").value == getPandMax())
      {
        document.getElementById("form_DashCurrent").value = document.getElementById("form_pandMax").value
        document.getElementById("dash_Alert").innerText = "MAX capacity reached!"
        document.getElementById("dash_Alert").className = "alert alert-danger"
      }
    }else
    {
      document.getElementById("form_DashCurrent").value = document.getElementById("form_pandMax").value
      document.getElementById("dash_Alert").innerText = "MAX capacity reached!"
      document.getElementById("dash_Alert").className = "alert alert-danger"
    }
  }
  
function checkwarning()
{
  if(document.getElementById("form_pandMax").value - document.getElementById("form_DashCurrent").value < document.getElementById("form_pandMax").value * 0.05)
  {
    return true;
  }else
  {
    return false;
  }

}

  function minusCurrent()
  {
    var currentValue = parseInt(document.getElementById("form_DashCurrent").value);
    if(currentValue > 0 )
    {
      document.getElementById("form_DashCurrent").value = currentValue - 1
    }else
    {
      document.getElementById("form_DashCurrent").value = 0
    }
  }