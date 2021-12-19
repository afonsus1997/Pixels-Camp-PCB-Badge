
 // decides what clicking the start button does
  function button_handler(){
    var typedInName = document.getElementById("nameText").value;
    if(typedInName != ""){
      var Score;
      sendString(typedInName);
      // askScore(typedInName);

    }
    
  }

  // sends the string
  function sendString(typedInName) {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
      if (this.readyState == 4 && this.status == 200) {
        //document.getElementById("LEDState").innerHTML = this.responseText;
      }
    };
    xhttp.open("GET", "StringState?StringTxt="+typedInName, true);
    xhttp.send();
  }

  function askScore(typedInName){
    var Score = 0;
    

      // request data every 5 seconds
      //setTimeout(requestData, 10000);

      function requestData() {
  
        $.get("/Score")
          .done(function(data) {
  
            console.log(data);  // debugging - remove when satisfied
  
            if (data) { // if the returned data is not null, update the values
              //$("#Score").text(data.Score);
              Score = data.Score;
              drawLeaderboard(typedInName, Score);
              
              console.log(Score);
            } else { // a problem occurred
              //$("#Score").text("?");
              Score = "?";
              
            }
          }).fail(function() {
            console.log("The was a problem retrieving the data.");
          });
      }

      requestData();
      
  
    console.log("return");
    
    console.log(Score);
    
  }

  function drawLeaderboard(typedInName, score){
      var addName = typedInName;
      var addScore = score;
      var t = $('#leaderboard').DataTable();

      

      t.row.add( [
        addName,
        addScore
        ] ).draw( false );
      console.log(t);
      t.order(1, "asc");
       
  } 
  

   
  