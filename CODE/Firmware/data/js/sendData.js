// var sendButton = document.getElementById("sendbtn");

function text_button_handler(){
  var formString  = document.getElementById('displaytext').value;
    var xhttp = new XMLHttpRequest();
    // xhttp.onreadystatechange = function() {
    //   if (this.readyState == 4 && this.status == 200) {
    //     //document.getElementById("LEDState").innerHTML =
    //     //this.responseText;
    //   }
    // };
    xhttp.open("GET", "SendString?StringTxt="+formString, true)
    xhttp.send();
}

function speed_button_handler(){
  var formString  = document.getElementById('TextSpeed').value;
    var xhttp = new XMLHttpRequest();
    // xhttp.onreadystatechange = function() {
    //   if (this.readyState == 4 && this.status == 200) {
    //     //document.getElementById("LEDState").innerHTML =
    //     //this.responseText;
    //   }
    // };

    xhttp.open("GET", "SpeedString?StringTxt="+formString, true)
    xhttp.send();
}


function spacing_button_handler(){
  var formString  = document.getElementById('TextSpacing').value;
    var xhttp = new XMLHttpRequest();
    // xhttp.onreadystatechange = function() {
    //   if (this.readyState == 4 && this.status == 200) {
    //     //document.getElementById("LEDState").innerHTML =
    //     //this.responseText;
    //   }
    // };
    xhttp.open("GET", "SpacingString?StringTxt="+formString, true)
    xhttp.send();
}

function brightness_button_handler(){
  var formString  = document.getElementById('Brightness').value;
    var xhttp = new XMLHttpRequest();
    // xhttp.onreadystatechange = function() {
    //   if (this.readyState == 4 && this.status == 200) {
    //     //document.getElementById("LEDState").innerHTML =
    //     //this.responseText;
    //   }
    // };
    xhttp.open("GET", "BrightnessString?StringTxt="+formString, true)
    xhttp.send();
}




   
  