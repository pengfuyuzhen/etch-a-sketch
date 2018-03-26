var COLOUR =  '#505050';  // This is the drawing color
var radius = 4;           // Constant radio for the line
var socket = io();        // websocket to the server
var previousPosition=[0,0]; // previous position to draw a line from
var ctx = Sketch.create(); //Creating the drawing context
var firstMessage=true;    // What the first message, to start on the first value

    ctx.container = document.getElementById( 'container' ); //reference drawing canvas
    ctx.autoclear= false; // making sure it stays
    ctx.retina='auto';
    ctx.setup = function() { console.log( 'setup' );} // Setup all variables
    ctx.keydown= function() { if ( ctx.keys.C ) ctx.clear();} // handeling keydowns

    socket.on('reset', function() { // on a 'reset' message clean and reste firstMessage
      firstMessage=true;
      ctx.clear();
      // Reference https://stackoverflow.com/a/5092846
      COLOUR = '#'+(Math.random()*0xFFFFFF<<0).toString(16);
    });

    socket.on('new-pos', function(newPosition) { // handling new sensor values

      //TODO: Map the incoming 10-bit numbers to the height and width of the screen.
      // See https://github.com/soulwire/sketch.js/wiki/API for sketch references

      console.log(newPosition);
      var x = 1000 -(newPosition[0] - 250) * 1000 / 150.0
      var y = (newPosition[1] - 250)*1000/250.0;
      var width = Math.max((1000 - newPosition[2]) / 6.0, radius);
      var pos = [x, y];

      if(firstMessage){ // if its the first message store that value as previous
        firstMessage=false;
        previousPosition=pos;
      }else{ // any other message we use to draw.
        ctx.lineCap = 'round';
        ctx.lineJoin = 'round';
        ctx.fillStyle = ctx.strokeStyle = COLOUR;
        ctx.lineWidth = width;
        ctx.beginPath();  //begin a adrawing
        ctx.moveTo( previousPosition[0], previousPosition[1] ); // from
        ctx.lineTo( pos[0],  pos[1]); // to
        ctx.stroke(); // and only draw a stroke
        previousPosition=pos; // update to the new position.
       }
    });
