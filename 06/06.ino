//bluetooth溝通
#include<SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12); 
const int motorln1 = 7;
const int motorln2 = 6;
const int motorln3 = 8;
const int motorln4 = 9;
const int EnableA =  3;
const int EnableB =  5;


void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  Serial.println("test");
  pinMode(motorln1,OUTPUT);
  pinMode(motorln2,OUTPUT);
  pinMode(motorln3,OUTPUT);
  pinMode(motorln4,OUTPUT);
  pinMode(EnableA,OUTPUT);
  pinMode(EnableB,OUTPUT);
}


void forward(){
  analogWrite(EnableA,250);
  analogWrite(EnableB,250);
  digitalWrite(motorln1, HIGH);
  digitalWrite(motorln2, LOW);
  digitalWrite(motorln3, HIGH);
  digitalWrite(motorln4, LOW);
}


void backward(){
  analogWrite(EnableA,250);
  analogWrite(EnableB,250);
  digitalWrite(motorln1, LOW);
  digitalWrite(motorln2, HIGH);
  digitalWrite(motorln3, LOW);
  digitalWrite(motorln4, HIGH);
}

void mstop(){
  analogWrite(EnableA,250);
  analogWrite(EnableB,250);
  digitalWrite(motorln1, LOW);
  digitalWrite(motorln2, LOW);
  digitalWrite(motorln3, LOW);
  digitalWrite(motorln4, LOW);
  
  }

void right(){
  analogWrite(EnableA,150);
  analogWrite(EnableB,70);
  digitalWrite(motorln1, HIGH);
  digitalWrite(motorln2, LOW);
  digitalWrite(motorln3, HIGH);
  digitalWrite(motorln4, LOW);
  
  }
  
void left(){
  analogWrite(EnableA,70);
  analogWrite(EnableB,150);
  digitalWrite(motorln1, HIGH);
  digitalWrite(motorln2, LOW);
  digitalWrite(motorln3, HIGH);
  digitalWrite(motorln4, LOW);
  
  }

  
void loop() {
  
if(BTSerial.available()){
  
  unsigned char cr = BTSerial.read();
    if(cr == 'f'){
      forward();
      Serial.println("forward");
      BTSerial.println("forward");
    }
    if(cr == 'b'){
      backward();
      Serial.println("backward");
      BTSerial.println("backward");
    }
    if(cr == 's'){
      mstop();
      Serial.println("stop");
      BTSerial.println("stop");
    }
    if(cr == 'r'){
      right();
      Serial.println("right");
      BTSerial.println("right");
    }
    if(cr == 'l'){
      left();
      Serial.println("left");
      BTSerial.println("left");
    }
  }
 }
