//寫好用序列埠溝通的所有功能
const int motorln1 = 7;
const int motorln2 = 6;
const int motorln3 = 8;
const int motorln4 = 9;
const int EnableA =  3;
const int EnableB =  5;


void setup() {
  Serial.begin(9600);
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
  
if(Serial.available()){
  
  char c = Serial.read();
  if(c == 'f'){
    forward();
    Serial.println("forward");
    
    }
  if(c == 'b'){
    backward();
    Serial.println("back");
    }

  if(c == 's'){
    mstop();
    Serial.println("stop");
    }
    
  if(c == 'r'){
    right();
    Serial.println("right");
    }

  if(c == 'l'){
    left();
    Serial.println("left");
    }
  }


}
