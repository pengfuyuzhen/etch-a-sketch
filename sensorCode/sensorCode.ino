const int xPort = A0;
const int yPort = A1;

unsigned long targetTime=0;
const unsigned long interval=2500; //TODO: How fast should we read
void setup(){
  Serial.begin(115200);
}

void loop(){
	if(millis()>=targetTime){
  
		targetTime= millis()+interval;
		String x = String(analogRead(xPort));
    String y = String(analogRead(yPort));
    String data = x + "," + y;

    Serial.println(data);

    //Serial.write(data);

		 //TODO: Add other sensor read outs
     //TODO: convert values into a string https://www.arduino.cc/en/Tutorial/StringConstructors
		 //TODO: combine them into a string that can be understood by server.js
		 //TODO: send the string over serial
	}
	// TODO: Detect if you want to reset the screen(shake the etch-a-sketch)
  // TODO: write the reset message(see server.js) to the serial port

}
