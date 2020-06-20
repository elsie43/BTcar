//參考用程式碼
#include<SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial CAR_BT(11, 12); //RX | TX
const int leftMotorIn1  = 5;
const int leftMotorIn2  = 6;
const int rightMotorIn3  = 9;
const int rightMotorIn4  = 10;

bool isForward = true;
void setup()  
{
  pinMode(leftMotorIn1, OUTPUT);
  pinMode(leftMotorIn2, OUTPUT);
  pinMode(rightMotorIn3, OUTPUT);
  pinMode(rightMotorIn4, OUTPUT);
  Serial.begin(9600); //Arduino起始鮑率：9600
  CAR_BT.begin(9600); //藍牙鮑率：9600 注意！每個藍牙晶片的鮑率都不太一樣，請務必確認
}
void loop()
{
int inSize;
char input;
if( (inSize = (CAR_BT.available())) > 0) { //讀取藍牙訊息
      Serial.print("size = ");
      Serial.println(inSize);
      Serial.print("Input = ");
      Serial.println(input=(char)CAR_BT.read());
      
if( input == 'f' ) {
forward();
        isForward = true;
      }
if( input == 'b' ) {
backward();
        isForward = false;
      }
if( input == 'l' ) {
left();
      }
if( input == 'r' ) {
right();
      }
if( input == 's' ) {
motorstop();
      }
  }    
}
void motorstop()
{
  digitalWrite(leftMotorIn1, LOW);
  digitalWrite(leftMotorIn2, LOW);
  digitalWrite(rightMotorIn3, LOW);
  digitalWrite(rightMotorIn4, LOW);
}
void forward()
{
  digitalWrite(leftMotorIn1, HIGH);
  digitalWrite(leftMotorIn2, LOW);
  digitalWrite(rightMotorIn3, HIGH);
  digitalWrite(rightMotorIn4, LOW);
}
void backward()
{
  digitalWrite(leftMotorIn1, LOW);
  digitalWrite(leftMotorIn2, HIGH);
  digitalWrite(rightMotorIn3, LOW);
  digitalWrite(rightMotorIn4, HIGH);
}


void right()
{
  if( isForward ) {
    digitalWrite(leftMotorIn1, HIGH);
    digitalWrite(leftMotorIn2, LOW);
    digitalWrite(rightMotorIn3, LOW);
    digitalWrite(rightMotorIn4, LOW);
  } 
  else {
    digitalWrite(leftMotorIn1, LOW);
    digitalWrite(leftMotorIn2, LOW);
    digitalWrite(rightMotorIn3, LOW);
    digitalWrite(rightMotorIn4, HIGH);
  }
}

void left()
{
  if( isForward ) {
    digitalWrite(leftMotorIn1, LOW);
    digitalWrite(leftMotorIn2, LOW);
    digitalWrite(rightMotorIn3, HIGH);
    digitalWrite(rightMotorIn4, LOW);
  } 
  else {
    digitalWrite(leftMotorIn1, LOW);
    digitalWrite(leftMotorIn2, HIGH);
    digitalWrite(rightMotorIn3, LOW);
    digitalWrite(rightMotorIn4, LOW);
  }
}


/*

void setup() {
  pinMode(motorIn1,OUTPUT);
  pinMode(motorIn2,OUTPUT);
  
  // Serial.begin(9600);序列埠監控視窗和軟體同步，但這次不用監控視窗做溝通，故註解掉沒差
  BTSerial.begin(9600);
}

void loop() {
  if(BTSerial.available()>0){
    unsigned char charreceived = BTSerial.read();
    switch(charreceived){
      case'1':
        BTSerial.println("GO");
        analogWrite(5,0); //5,6腳位；100:轉速
        analogWrite(6,100);
        break; // 跳脫switch case
      case'2':
        BTSerial.println("BACK");
        analogWrite(5,100);
        analogWrite(6,0);
        break;
      case'3':
        BTSerial.println("STOP");
        analogWrite(5,0); 
        analogWrite(6,0);
        break;
      default:
        break;
      }
    }
  BTSerial.flush(); //為使程序不浪費時間等待發送字符
  delay(10);
}
*/
