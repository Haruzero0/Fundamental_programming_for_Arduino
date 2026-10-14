const int gLED=3;
const int bLED=4;
const int rLED=5;

void setup() {
  

  Serial.begin(9600);
  pinMode(gLED,OUTPUT);
  pinMode(rLED,OUTPUT);
  pinMode(bLED,OUTPUT);

}

void loop() {
  

  int sensorValue=analogRead(A0);

  Serial.println(sensorValue);

  if(sensorValue>=768){

    digitalWrite(gLED,LOW);
    digitalWrite(rLED,LOW);
    digitalWrite(bLED,LOW);

  }else if(512<=sensorValue && sensorValue<=767){
    digitalWrite(bLED,LOW);
    digitalWrite(gLED,HIGH);
    digitalWrite(rLED,HIGH);
  }else if(256<=sensorValue && sensorValue<=511){

    digitalWrite(bLED,HIGH);
    digitalWrite(gLED,LOW);
    digitalWrite(rLED,HIGH);

  }else{

    digitalWrite(bLED,HIGH);
    digitalWrite(gLED,HIGH);
    digitalWrite(rLED,LOW);

  }

  delay(1);

}
