// Defining the constants for the pins
const int enableAPin = 11;
const int in1Pin=10;
const int in2Pin=9;
const int button=4;
// Initialising the button state to false
int pressed=false;

void setup() {
  // put your setup code here, to run once:
  //Setting the output pins to the H-bridge
  pinMode(enableAPin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  //Setting the input button pin
  pinMode(button, INPUT);
  }

void loop() {
  // put your main code here, to run repeatedly:
  //setting the potentiometer analogue input
  int potValue = analogRead(A5);
  //mapping the pot input to an 8-bit scale.
  int pwmOutput=map(potValue, 0, 1023, 0, 255);
  //outputing the pot input as speed to the H-bridge
  analogWrite(enableAPin, pwmOutput);
  if (digitalRead(button)==true){
    pressed=!pressed; //if the button is pressed then the pressed variable changes to the opposite.
  }
  while (digitalRead(button)==true);
  delay(20);

  if (pressed == true ){
    // if pressed is true then the H-bridge moves in direction 1
    digitalWrite(in1Pin, LOW);
    digitalWrite(in2Pin, HIGH);
    delay(20);
  }

 else if (pressed==false){
  // if pressed is false then the H-bridge moves in direction 2
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  delay(10);
  }
  
  

}
