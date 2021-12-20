var sendButton = document.getElementById("sendbtn");

function button_handler(){
  var formString  = document.getElementById('displaytext').value;
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        //document.getElementById("LEDState").innerHTML =
        //this.responseText;
      }
    };
    xhttp.open("GET", "StringState?StringTxt="+formString, true);
    xhttp.send();
}

   
  