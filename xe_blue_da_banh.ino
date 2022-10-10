#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
#define IN1 7
#define IN2 5
#define IN3 6
#define IN4 4
#define IN5 11
#define IN6 10
#define IN7 9
#define IN8 8

int tocdo=120;

void setup()
{
  //set all of the outputs

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
}
void lui() {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0); 
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  digitalWrite(IN5, 1);
  digitalWrite(IN6, 0); 
  digitalWrite(IN7, 1);
  digitalWrite(IN8, 0);
  
}

void tien() {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  digitalWrite(IN5, 0);
  digitalWrite(IN6, 1);
  digitalWrite(IN7, 0);
  digitalWrite(IN8, 1);
  
}
void quayphai() {
  digitalWrite(IN1, 1);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 1);
  digitalWrite(IN5, 1);
  digitalWrite(IN6, 0);
  digitalWrite(IN7, 0);
  digitalWrite(IN8, 1);
}
void quaytrai() {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 1);
  digitalWrite(IN3, 1);
  digitalWrite(IN4, 0);
  digitalWrite(IN5, 0);
  digitalWrite(IN6, 1);
  digitalWrite(IN7, 1);
  digitalWrite(IN8, 0);
}
void dung() {
  digitalWrite(IN1, 0);
  digitalWrite(IN2, 0);
  digitalWrite(IN3, 0);
  digitalWrite(IN4, 0);
  digitalWrite(IN5, 0);
  digitalWrite(IN6, 0);
  digitalWrite(IN7, 0);
  digitalWrite(IN8, 0);
}
void loop()
{
  char state = "a";
  if(mySerial.available())
   {
     state = mySerial.read();
     Serial.println(state);
   }
    switch (state) 
    {
    case 'R': // phai
     Serial.println("PHAI");
     quayphai();
     break;
   case 'L': //quẹo trai
     Serial.println("TRAI");
     quaytrai();
     break;
   case 'B': //đi lui
     Serial.println("LUI");
     lui();
     break;
   case 'F': //đi toi
     Serial.println("TIEN");
     tien();
     break;
  case 'G': // tien trai
     Serial.println("TIEN TRAI");
   
     break;
    case 'I': //tien phai
     Serial.println("TIEN PHAI");
   
     break;
   case 'S'://dừng
    Serial.println("DUNG");
     dung();   
     break;
   case 'H':
     Serial.println("LUI TRAI");
        
     break;
   case 'J':
     Serial.println("LUI PHAI");
       
     break;
  }     
}
