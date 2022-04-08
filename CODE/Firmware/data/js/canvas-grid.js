// document.createSvg = function(tagName) {
//     var svgNS = "http://www.w3.org/2000/svg";
//     return this.createElementNS(svgNS, tagName);
// };

// var grid = function(numberPerSide, size, height, width, colors){
//     var svg = document.createSvg("svg");
//     svg.setAttribute('width', width);
//     svg.setAttribute('height', height);
//     svg.setAttribute('viewBox', [0, 0, width * size, height * size].join(" "));

//     for(let i = 0; i < height; i++){
//         for(let j = 0; j < width; j++){
//             let color1 = colors[(i - j) % colors.length];
//             let color2 = colors[(i - j + 1) % colors.length];
//             let g = document.createSvg("g");
//             g.setAttribute("transform", ["translate(", i*size, ",", j*size, ")"].join(" "));
//             let number = numberPerSide * i + j;
//             let box = document.createSvg("rect");
//             box.setAttribute('width', size);
//             box.setAttribute('height', size);
//             box.setAttribute('fill', color1);
//             box.setAttribute('id', "b" + number);
//             g.appendChild(box);
//             let text = document.createSvg("text");
//             text.appendChild(document.createTextNode(i * numberPerSide + j));
//             text.setAttribute("fill", color2);
//             text.setAttribute("font-size", 6);
//             text.setAttribute("x", 0);
//             text.setAttribute("y", size/2);
//             text.setAttribute("id", "t" + number);
//             g.appendChild(text);
//             svg.appendChild(g);
//         }
//     }
//     return svg;
// }

// let container = document.getElementById("canvas-container");
// container.appendChild(grid(5, 10, 200, 1, ["white", "grey"]));

document.createSvg = function(tagName) {
    var svgNS = "http://www.w3.org/2000/svg";
    return this.createElementNS(svgNS, tagName);
};

var numberPerSide = 20;
var size = 10;
var pixelsPerSide = 400;



var grid = function(numberPerSideX, numberPerSideY, size, pixelsPerSideX, pixelsPerSideY, colors) {
    var svg = document.createSvg("svg");
    svg.setAttribute("width", pixelsPerSideY);
    svg.setAttribute("height", pixelsPerSideX);
    svg.setAttribute("viewBox", [0, 0, numberPerSideY * size, numberPerSideX * size].join(" "));
    
    for(var i = 0; i < numberPerSideY; i++) {
        for(var j = 0; j < numberPerSideX; j++) {
          var color1 = colors[(i+j) % colors.length];
          var color2 = colors[(i+j+1) % colors.length];  
          var g = document.createSvg("g");
          g.setAttribute("transform", ["translate(", i*size, ",", j*size, ")"].join(""));
          var number = numberPerSideX * i + j;
          var box = document.createSvg("rect");
          box.setAttribute("width", size);
          box.setAttribute("height", size);
          box.setAttribute("fill", color1);
          box.setAttribute("id", "b" + number); 
          g.appendChild(box);
        //   var text = document.createSvg("text");
        //   text.appendChild(document.createTextNode(i * numberPerSideX + j));
        //   text.setAttribute("fill", color2);
        //   text.setAttribute("font-size", 6);
        //   text.setAttribute("x", 0);
        //   text.setAttribute("y", size/2);
        //   text.setAttribute("id", "t" + number);
        //   g.appendChild(text);
          svg.appendChild(g);
        }  
    }
    svg.addEventListener(
        "click",
        function(e){
            var id = e.target.id;
            if(id){
                let cell = document.getElementById(id);
                let cell_number = parseInt(id.substring(1));
                let x = Math.floor(cell_number / 9);
                let y = cell_number % 9;
                console.log("(" + x + ", " + y + ")");
                if(cell.getAttribute("fill") == "green")
                    cell.setAttribute("fill", "white");
                else cell.setAttribute("fill", "green");
                //alert(id.substring(1));
            }
        },
        false);
    return svg;
};

var container = document.getElementById("canvas-container");
container.appendChild(grid(9, 39, 15, 300, 1000, ["white"]));
