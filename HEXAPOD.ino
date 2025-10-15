#include <Servo.h> 
#include "IRremote.h"

const int receiver = 11;      

IRrecv irrecv(receiver);    
decode_results results;      

String signal = "";


void translateIR() {          
// describing Remote IR codes 
  Serial.println(irrecv.decodedIRData.decodedRawData, HEX);  // Add this line
  switch(irrecv.decodedIRData.decodedRawData){
    case 0xBA45FF00: signal = "POWER"; break;
    case 0xB847FF00: signal = "FUNC/STOP"; break;
    case 0xB946FF00: signal = "VOL+"; break;
    case 0xBB44FF00: signal ="FAST BACK";    break;
    case 0xBF40FF00: signal ="PAUSE";    break;
    case 0xBC43FF00: signal ="FAST FORWARD";   break;
    case 0xF807FF00: signal ="DOWN";    break;
    case 0xEA15FF00: signal ="VOL-";    break;
    case 0xF609FF00: signal ="UP";    break;
    case 0xE619FF00: signal ="EQ";    break;
    case 0xF20DFF00: signal ="ST/REPT";    break;
    case 0xE916FF00: signal ="0";    break;
    case 0xF30CFF00: signal ="1";    break;
    case 0xE718FF00: signal ="2";    break;
    case 0xA15EFF00: signal ="3";    break;
    case 0xF708FF00: signal ="4";    break;
    case 0xE31CFF00: signal ="5";    break;
    case 0xA55AFF00: signal ="6";    break;
    case 0xBD42FF00: signal ="7";    break;
    case 0xAD52FF00: signal ="8";    break;
    case 0xB54AFF00: signal ="9";    break;
    case 0xFFFFFFFF: signal =" REPEAT";break;  

  }

} 


Servo Servo11; 
Servo Servo12; 
Servo Servo13; 

Servo Servo21; 
Servo Servo22; 
Servo Servo23; 

Servo Servo31; 
Servo Servo32; 
Servo Servo33; 

Servo Servo41; 
Servo Servo42; 
Servo Servo43; 

Servo Servo51; 
Servo Servo52; 
Servo Servo53; 


Servo Servo61; 
Servo Servo62; 
Servo Servo63; 

void setup() { 
   // We need to attach the servo to the used pin number  
   Servo11.attach(22);
   Servo12.attach(23);
   Servo13.attach(24);   
   Servo21.attach(25);
   Servo22.attach(26);
   Servo23.attach(27); 
   Servo31.attach(28);
   Servo32.attach(29);
   Servo33.attach(30); 
   Servo41.attach(31);
   Servo42.attach(32);
   Servo43.attach(33); 
   Servo51.attach(34);
   Servo52.attach(35);
   Servo53.attach(36); 
   Servo61.attach(37);
   Servo62.attach(38);
   Servo63.attach(39); 
  irrecv.enableIRIn();  
   
}

void loop(){
  signal = "";
  if (irrecv.decode())   // have we received an IR signal?
  {
    translateIR(); 
    delay(500);                 // Do not get immediate repeat
    irrecv.resume();            // receive the next value
  }  
  if (signal == "1") {
    motor1up();
    delay(2000);
    motor1down(); 
  } else if (signal == "2") {
    motor2up();
    delay(2000);
    motor2down();
  } else if (signal == "3") {
    motor3up();
    delay(2000);
    motor3down(); 
  } else if (signal == "4") {
    motor4up();
    delay(2000);
    motor4down(); 
  } else if (signal == "5") {
    motor5up();
    delay(2000);
    motor5down(); 
  } else if (signal == "6") {
    motor6up();
    delay(2000);
    motor6down(); 
  }
}
void stand(){
  //calling motor separately wont be synchrnous so delay then up
  
  Servo11.write(130); //mid
  Servo21.write(60);//mid
  Servo31.write(90); //mid
  Servo41.write(100); //mid
  Servo51.write(50);//mid
  Servo61.write(120); //mid

  Servo13.write(35);
  Servo23.write(170);
  Servo33.write(35);
  Servo43.write(170); 
  Servo53.write(35);
  Servo63.write(170);
  delay(1000);
  Servo12.write(45);  
  Servo22.write(130); 
  Servo32.write(50);  
  Servo42.write(130); 
  Servo52.write(50);
  Servo62.write(130);
  
  
}
void sit() {
  
  Servo12.write(130);
  Servo22.write(50);
  Servo32.write(130);
  Servo42.write(50);
  Servo52.write(130);
  Servo62.write(50);
  delay(1000);
  Servo13.write(120);
  Servo23.write(70);
  Servo33.write(120);
  Servo43.write(70);
  Servo53.write(120);
  Servo63.write(70);
 
}
//motor 1 down up
void motor1down() {
  Servo13.write(30);
  delay(250);
  Servo12.write(50);  
  delay(200);
}
void motor1up() {
  Servo12.write(130);
  delay(200);
  Servo13.write(120);
  delay(200);
}
//motor 2 down up
void motor2down() {
  Servo23.write(160);
  delay(250);
  Servo22.write(130);  
  delay(200);
}
void motor2up() {
  Servo22.write(50);
  delay(200);
  Servo23.write(70);
  delay(200);
}
//motor 3 down up
void motor3down() {
  Servo33.write(30);
  delay(250);
  Servo32.write(50);  
  delay(200);
}
void motor3up() {
  Servo32.write(130);
  delay(200);
  Servo33.write(120);
  delay(200);
}
//motor 4 down up
void motor4down() {
  Servo43.write(160);
  delay(250);
  Servo42.write(130);  
  delay(200);
}
void motor4up() {
  Servo42.write(50);
  delay(200);
  Servo43.write(70);
  delay(200);
}
//motor 5 down up
void motor5down() {
  Servo53.write(30);
  delay(250);
  Servo52.write(50);  
  delay(200);
}
void motor5up() {
  Servo52.write(130);
  delay(200);
  Servo53.write(120);
  delay(200);
}
void motor6down() {
  Servo63.write(160);
  delay(250);
  Servo62.write(130);  
  delay(200);
}
void motor6up() {
  Servo62.write(50);
  delay(200);
  Servo63.write(70);
  delay(200);
}
void motor1forward() {
  motor1up();
  delay(600);
  Servo11.write(70);
  delay(400);
  motor1down();
}
void motor1backward() {
  motor1up();
  delay(600);
  Servo11.write(130);
  delay(400);
  motor1down();
}
