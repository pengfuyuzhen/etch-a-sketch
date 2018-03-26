const int xPort = A0;
const int yPort = A1;
const int fsrPort = A5;
const int resetPort = 13;

unsigned long targetTime = 0;
const unsigned long interval = 10; //TODO: How fast should we read
void setup(){
  Serial.begin(115200);
}

void loop(){  
  
  if (digitalRead(resetPort) == 0) {
    Serial.println("rst");
  } else if (analogRead(fsrPort) < 1023) {
    if(millis() >= targetTime){
      targetTime= millis()+interval;
      String x = String(analogRead(xPort));
      String y = String(analogRead(yPort));
      String data = x + "," + y;
      Serial.println(data);
    }
  }
}
