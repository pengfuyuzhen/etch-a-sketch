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
  } else if (analogRead(fsrPort) < 1023) {
    String x = String(analogRead(xPort));
    String y = String(analogRead(yPort));
    String data = x + "," + y;
    Serial.println(data);
    delay(10);
  }
}
