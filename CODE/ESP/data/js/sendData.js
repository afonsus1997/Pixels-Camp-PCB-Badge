var stringFrom = document.getElementById("displaytext");
var sendButton = document.getElementById("sendbtn");

sendButton.addEventListener(onclick, button_handler);

function button_handler(){
  stringFrom.value = "";
  sendString();
  
}



  function sendString(value) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        //document.getElementById("LEDState").innerHTML =
        //this.responseText;
      }
    };
    xhttp.open("GET", "StringState?StringTxt="+stringFrom.value , true);
    xhttp.send();
  }
   
  