//defining all the digital pins
const int enA=11;
const int enB = 6;
const int in1 = 10;
const int in2 = 9;
const int in3 = 4;
const int in4 = 5;
//intialising the speed values for each motor
int speedA=0;
int speedB=0;

void setup() {
  // put your setup code here, to run once:
  //setting the pin modes for each digital pin. They are all outputs to the H-bridge
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Reading the x axis and y axis joystick values
  int xaxis=analogRead(A0);
  int yaxis=analogRead(A1);

  if (yaxis>550){
    //If the joystick moved forwards in the yaxis, the drone will turn
    speedA=map(xaxis, 550, 1023, 0, 255);
    speedB=map(yaxis, 550, 1023, 0, 255);
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);          
  }
  else if (yaxis<490) {
    //If the joystick moved backwards in the yaxis, the drone will turn

    speedA=map(yaxis, 460, 0, 0, 255);
    speedB=map(yaxis, 460, 0, 0, 255);
    
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);  
  }
  else if (xaxis>570) {
    //If the joystick moved forwards in the xaxis, the drone will move forwards
    speedA=map(xaxis, 550, 1023, 0, 255);
    speedB=map(xaxis, 550, 1023, 0, 255);
   
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
  }
  else if (xaxis<490) {
    //If the joystick moved backwards in the xaxis, the drone will move backwards
    speedA=map(xaxis, 490, 0, 0, 255);
    speedB=map(xaxis, 490, 0, 0, 255);
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  }
  else{
    //If there are no inputs, then the motor will not turn.
    speedA=0;
    speedB=0;
  }
  
  analogWrite(enA, speedA);
  analogWrite(enB, speedB);
}
