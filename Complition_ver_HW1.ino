//Pin definition
const int buttonPin=2;//Pin connected to the button
const int RedLED=3;//Pin for Red LED
const int GreenLED=4;//pin for green LED
const int BlueLED=5;//pin for blue LED

int buttonState=0;//To store the current button state 
int LEDcolor=0;//Initial LED color state(0=off)

bool ButtonPressed=false;//To track whether the button is currently pressed

unsigned long Pressingtime=0;// for  measuring the time of pressing the button 

String currentcolor="LED";// to confirm what LEDcolor is now. 


void setup() {
  
  pinMode(buttonPin,INPUT);//setting the buttonPin as an input
  //↓setting the RGB module as an OUTPUT
  pinMode(RedLED,OUTPUT);
  pinMode(GreenLED,OUTPUT);
  pinMode(BlueLED,OUTPUT);

  Serial.begin(9600);//Initialize Serial communication at 9600 baud

}

void loop() {

  buttonState = digitalRead(buttonPin);// to get the buttonPin state

//↓ Turning off the light if the button is held for at least 1000ms

//↓Detect when the button is first pressed 
  if(buttonState==LOW && !ButtonPressed){

    ButtonPressed=true;//Marking the button as pressed

    Pressingtime=millis();//Recording the time when the button is pressed  

  }
//↓ Check whether the button is being held


  if(buttonState==LOW && ButtonPressed){

    if(millis()-Pressingtime>=1000){

      LEDcolor=0;//Turn off the LED if the button is held for at least 1000ms

    }
  }
// ↓Handling a short press when the button is released 
  if(buttonState==HIGH && ButtonPressed){

    if(millis()-Pressingtime<1000){

      if(LEDcolor==7){

        LEDcolor=0;//Reset LEDcolor to 0 when it reaches 7

        }else{

          LEDcolor=LEDcolor+1;// If the user clicks the button shortly, the LEDcolor will move to next LED color

        }

      }

      ButtonPressed=false;// Reset the button press 

  }
  
//↓Update the RGB LED outputs based on LEDcolor
 if (LEDcolor==0) {
    currentcolor="LED off";
    digitalWrite(RedLED,HIGH);
    digitalWrite(GreenLED,HIGH);
    digitalWrite(BlueLED,HIGH);

    Serial.print("Color ");
    Serial.println(currentcolor);

  } else if (LEDcolor==1) {
    currentcolor="Red";
    digitalWrite(RedLED,LOW);
    digitalWrite(GreenLED,HIGH);
    digitalWrite(BlueLED,HIGH);

    Serial.print("Color ");
    Serial.println(currentcolor);

  } else if (LEDcolor==2) {
    currentcolor="Green";
    digitalWrite(RedLED,HIGH);
    digitalWrite(GreenLED,LOW);
    digitalWrite(BlueLED,HIGH);

    Serial.print("Color ");
    Serial.println(currentcolor);

  } else if (LEDcolor==3) {
    currentcolor="Blue";
    digitalWrite(RedLED,HIGH);
    digitalWrite(GreenLED,HIGH);
    digitalWrite(BlueLED,LOW);

    Serial.print("Color ");
    Serial.println(currentcolor);

  } else if (LEDcolor==4) {
    currentcolor="Purple";
    digitalWrite(RedLED,LOW);
    digitalWrite(GreenLED,HIGH);
    digitalWrite(BlueLED,LOW);

    Serial.print("Color ");
    Serial.println(currentcolor);

  } else if (LEDcolor==5) {
    currentcolor="Yellow";
    digitalWrite(RedLED,LOW);
    digitalWrite(GreenLED,LOW);
    digitalWrite(BlueLED,HIGH);

    Serial.print("Color ");
    Serial.println(currentcolor);

  } else if (LEDcolor==6) {
    currentcolor="Cyan";
    digitalWrite(RedLED,HIGH);
    digitalWrite(GreenLED,LOW);
    digitalWrite(BlueLED,LOW);

    Serial.print("Color ");
    Serial.println(currentcolor);

  } else if (LEDcolor==7) {
    currentcolor="White";
    digitalWrite(RedLED,LOW);
    digitalWrite(GreenLED,LOW);
    digitalWrite(BlueLED,LOW);

    Serial.print("Color ");
    Serial.println(currentcolor);
  } 
}
