//define all the pins
const int LED = 4;
const int trig = 3;
const int echo = 2;
float v=340;//speed of sound in air

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);//opens serial port at speed of 115200bps
  pinMode(LED, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
}
float distance() { //Creates function distance
  //Create a pulse here with a period of 8 microseconds
  digitalWrite(trig, LOW);
  delayMicroseconds(3);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
//Timing the pulse here
  float tus = pulseIn(echo, HIGH);
  float t=tus/2000000;//Convert microseconds to seconds
  float dm = (v * t) ; //m
  float dcm = dm * 100;//cm
  return dcm;
}
void loop() {
  // put your main code here, to run repeatedly:
  int d = distance();//calling the function
  Serial.println(d,DEC);
  
  if (d < 20) {// if the distance is less than 20cm
    digitalWrite(LED, HIGH);//Turns LED on
  }
  else{
    digitalWrite(LED, LOW);//Turns LED off
  }

  delay(200);
}
