/*************************************************************
PIN 12: control channel A motor (HIGH forward / LOW backward)
PIN 13: control channel B motor

PIN 9: control channel A brake (HIGH break/ LOW)
PIN 8: control channel B brake

Analog 3: control channel A motor speed (0-255)
Analog 11: control channel B motor speed (0-255)



*************************************************************/

const int DEFAULT_SPEED = 255;

const int TURN_SPEED = 180;
const int TURN_TIME = 1000;

void setup() {
  
  //Setup Channel A
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin

  //Setup Channel B
  pinMode(13, OUTPUT); //Initiates Motor Channel A pin
  pinMode(8, OUTPUT);  //Initiates Brake Channel A pin
  
}

void loop(){

  //Go forward
  goForward(DEFAULT_SPEED,1000);

  brake();

  turnLeft();

  brake();

  turnRight();

  brake();

  goBackward(DEFAULT_SPEED,1000);
  
  brake();

  
}

void goForward(int speed, int msTime){
  //Motor A forward @  speed
  digitalWrite(12, HIGH); 
  //brake off
  digitalWrite(9, LOW);   
  // speed
  analogWrite(3, speed);   

  //Motor B forward @  speed
  digitalWrite(13, HIGH);
  //brake off  
  digitalWrite(8, LOW); 
  // spedd  
  analogWrite(11, speed);  

  delay(msTime);  
}

void goBackward(int speed,int msTime){
  //Motor A backward @  speed
  digitalWrite(12, LOW); 
  //brake off
  digitalWrite(9, LOW);   
  // speed
  analogWrite(3, speed);   

  //Motor B backward @  speed
  digitalWrite(13, LOW);
  //brake off  
  digitalWrite(8, LOW); 
  // spedd  
  analogWrite(11, speed); 

  delay(msTime);     
}

void turnLeft(){

  delay(TURN_TIME);
  
  //Motor A backward @  speed
  digitalWrite(12, LOW); 
  //brake off
  digitalWrite(9, LOW);   
  // speed
  analogWrite(3, TURN_SPEED);   

  //Motor B backward @  speed
  digitalWrite(13, HIGH);
  //brake off  
  digitalWrite(8, LOW); 
  // spedd  
  analogWrite(11, TURN_SPEED); 

  delay(TURN_TIME);

}

void turnRight(){

  delay(TURN_TIME);
    
  //Motor A backward @  speed
  digitalWrite(12, HIGH); 
  //brake off
  digitalWrite(9, LOW);   
  // speed
  analogWrite(3, TURN_SPEED);   

  //Motor B backward @  speed
  digitalWrite(13, LOW);
  //brake off  
  digitalWrite(8, LOW); 
  // spedd  
  analogWrite(11, TURN_SPEED); 

  delay(TURN_TIME);

}



void brake(){
  digitalWrite(9, HIGH);  //Brake for Channel A
  digitalWrite(8, HIGH);  //Brake for Channel B
}
