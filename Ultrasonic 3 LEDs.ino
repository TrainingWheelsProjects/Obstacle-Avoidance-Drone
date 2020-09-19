// define all pins
const int LED1 = 4;//Red LED
const int LED2 = 5;//Amber LED
const int LED3 = 6;//Green LED
const int trig = 3;
const int echo = 2;
float v=340;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo,INPUT);
}
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
  int d = distance();
  Serial.println(d,DEC);
  
  if (d < 5) {// if distance is less than 5cm
    digitalWrite(LED1, HIGH);//Red LED turns on
    digitalWrite(LED2, LOW);// Amber LED is off
    digitalWrite(LED3, LOW);// Green LED is off
  }
  else if (5<d && d<10 ){//if distance is greater than 5cm and less than 10cm 
    digitalWrite(LED1, LOW);// Red LED is off
    digitalWrite(LED2, HIGH);// Amber LED is on
    digitalWrite(LED3, LOW);// Green LED is off
    }

  else if (10<d && d<15){// if distance is greater than 10cm and less than 15cm
    digitalWrite(LED1, LOW);// Red LED is off
    digitalWrite(LED2, LOW);// Amber LED is off
    digitalWrite(LED3, HIGH);// Green LED is on
  }
  else{// all LEDs are off
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
  
 }
  delay(200);
}
