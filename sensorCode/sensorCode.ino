const int xPort = A0;
const int yPort = A1;
const int fsrPort = A5;
const int resetPort = 13;

void setup(){
  Serial.begin(115200);
}

void loop(){  
  if (digitalRead(resetPort) == 0) {
    Serial.println("rst");
  } else if (analogRead(fsrPort) < 1000) {
    String x = String(analogRead(xPort));
    String y = String(analogRead(yPort));
    String force = String(analogRead(fsrPort));
    String data = x + "," + y + "," + force;
    Serial.println(data);
    delay(10);
  }
}
