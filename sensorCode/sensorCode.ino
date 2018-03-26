const int xPort = A0;
const int yPort = A1;
const int fsrPort = A5;
const int resetPort = 13;
const int fsrMax = 1023;
//int x_min = 1023;
//int x_max = 0;

unsigned long targetTime = 0;
const unsigned long interval = 10; //TODO: How fast should we read
void setup(){
  Serial.begin(115200);
}

void loop(){  
  if (digitalRead(resetPort) == 0) {
    Serial.println("rst");
    return;
  }

	if(millis() < targetTime || analogRead(fsrPort) != fsrMax){
    return;
	}

	targetTime= millis()+interval;
	String x = String(analogRead(xPort));
  String y = String(analogRead(yPort));
  String data = x + "," + y;
  Serial.println(data);

//  int x = analogRead(yPort);
//  x_min = min(x_min, x);
//  x_max = max(x_max, x);
//  String data = String(x_min) + ", " + String(x_max);
//  Serial.println(data);
//
//		 //TODO: Add other sensor read outs
//     //TODO: convert values into a string https://www.arduino.cc/en/Tutorial/StringConstructors
//		 //TODO: combine them into a string that can be understood by server.js
//		 //TODO: send the string over serial
//
//	// TODO: Detect if you want to reset the screen(shake the etch-a-sketch)
//  // TODO: write the reset message(see server.js) to the serial port

}
