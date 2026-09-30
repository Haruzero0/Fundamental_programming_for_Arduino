const int buttonPin=2;
const int rLED=3;
const int bLED=4;
const int gLED=5;

int buttonState=0;
int ledState=LOW;
int ledcolor=0;

bool ButtonPressed=false;

String currentcolor="led off";

unsigned long previousMillis=0;
const long interval=1000;


void setup() {
  // put your setup code here, to run once:
  
  pinMode(rLED,OUTPUT);
  pinMode(bLED,OUTPUT);
  pinMode(gLED,OUTPUT);
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);//Baund rate setting

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState=digitalRead(buttonPin);
  Serial.print("Current Color: ");
  Serial.println(currentcolor);

  if(buttonState==HIGH && !ButtonPressed){
    
    ledcolor = ledcolor+1;

    ButtonPressed=true;

  }

  if(buttonState==LOW && ButtonPressed){

    ButtonPressed=false;
  }

  unsigned long currentMillis =millis();
  if(currentMillis-previousMillis>=interval){

    previousMillis=currentMillis;

    if(ledState==LOW){
      ledState=HIGH;
    }else{
      ledState=LOW;
    }
  }

  

  if(ledcolor==0){

    currentcolor="LED off";
    
    digitalWrite(rLED,HIGH);
    digitalWrite(gLED,HIGH);
    digitalWrite(bLED,HIGH);

  }else if(ledcolor==1){

    currentcolor="Red";
    if(ledState==LOW){
    digitalWrite(rLED,LOW);
    digitalWrite(gLED,HIGH);
    digitalWrite(bLED,HIGH);
    }else{

      digitalWrite(rLED,HIGH);
      digitalWrite(gLED,HIGH);
      digitalWrite(bLED,HIGH);
    }


  }else if(ledcolor==2){

    currentcolor="Green";

    if(ledState==LOW){

    digitalWrite(rLED,HIGH);
    digitalWrite(gLED,LOW);
    digitalWrite(bLED,HIGH);
    }else{

      digitalWrite(rLED,HIGH);
      digitalWrite(gLED,HIGH);
      digitalWrite(bLED,HIGH);
    }


  }else if(ledcolor==3){

    currentcolor="Blue";
   if(ledState==LOW){
    digitalWrite(rLED,HIGH);
    digitalWrite(gLED,HIGH);
    digitalWrite(bLED,LOW);
   }else{

      digitalWrite(rLED,HIGH);
      digitalWrite(gLED,HIGH);
      digitalWrite(bLED,HIGH);
    }

  }else if(ledcolor==4){

    currentcolor="Yellow";
if(ledState==LOW){
    digitalWrite(rLED,LOW);
    digitalWrite(gLED,LOW);
    digitalWrite(bLED,HIGH);
}else{

      digitalWrite(rLED,HIGH);
      digitalWrite(gLED,HIGH);
      digitalWrite(bLED,HIGH);
    }


  }else if(ledcolor==5){

    currentcolor="Purple";
if(ledState==LOW){
    digitalWrite(rLED,LOW);
    digitalWrite(gLED,HIGH);
    digitalWrite(bLED,LOW);
}else{

      digitalWrite(rLED,HIGH);
      digitalWrite(gLED,HIGH);
      digitalWrite(bLED,HIGH);
    }


  }else if(ledcolor==6){

    currentcolor="Cyan";
if(ledState==LOW){
    digitalWrite(rLED,HIGH);
    digitalWrite(gLED,LOW);
    digitalWrite(bLED,LOW);
}else{

      digitalWrite(rLED,HIGH);
      digitalWrite(gLED,HIGH);
      digitalWrite(bLED,HIGH);
    }

  }else if(ledcolor==7){

    currentcolor="White";
if(ledState==LOW){
    digitalWrite(rLED,LOW);
    digitalWrite(gLED,LOW);
    digitalWrite(bLED,LOW);
}else{

      digitalWrite(rLED,HIGH);
      digitalWrite(gLED,HIGH);
      digitalWrite(bLED,HIGH);
    }

  }else if(ledcolor==8){

    ledcolor=0;
  }


}
