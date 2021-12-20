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

function set_test(){
  var formString  = document.getElementById('displaytext');
  formString.value = "We're no strangers to love, You know the rules and so do I, A full commitment's what I'm thinking of, You wouldn't get this from any other guy, I just wanna tell you how I'm feeling, Gotta make you understand. Never gonna give you up, Never gonna let you down, Never gonna run around and desert you, Never gonna make you cry, Never gonna say goodbye, Never gonna tell a lie and hurt you.";
  formString.focus();
}




   
  