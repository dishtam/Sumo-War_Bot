// Pins for IR sensors
#define IR1 4;  // front IR
#define IR2 5;  // back IR

//Pins for drive wheels

//Front wheels
#define M1I1 13;
#define M1I2 12;
#define M1I3 11;
#define M1I4 10;

//Back wheels
#define M2I1 9;
#define M2I2 8;
#define M2I3 7;
#define M2I4 6;

//Pins for Ultarsonic sensor
#define trigPin  2;
#define echoPin 3;


void setup(){
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);

  pinMode(M1I1,OUTPUT);
  pinMode(M1I2,OUTPUT);
  pinMode(M1I3,OUTPUT);
  pinMode(M1I4,OUTPUT);

  pinMode(M2I1,OUTPUT);
  pinMode(M2I2,OUTPUT);
  pinMode(M2I3,OUTPUT);
  pinMode(M2I4,OUTPUT);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  Serial.begin(9600);
}

void loop(){

}

void forward(){
  digitalWrite(M1I1,HIGH);
  digitalWrite(M1I2,LOW);
  digitalWrite(M1I3,HIGH);
  digitalWrite(M1I4,LOW);

  digitalWrite(M2I1,HIGH);
  digitalWrite(M2I2,LOW);
  digitalWrite(M2I3,HIGH);
  digitalWrite(M2I4,LOW);
}

void backward(){
  digitalWrite(M1I1,LOW);
  digitalWrite(M1I2,HIGH);
  digitalWrite(M1I3,LOW);
  digitalWrite(M1I4,HIGH);

  digitalWrite(M2I1,LOW);
  digitalWrite(M2I2,HIGH);
  digitalWrite(M2I3,LOW);
  digitalWrite(M2I4,HIGH);
}

void rotate(){
  digitalWrite(M1I1,HIGH);
  digitalWrite(M1I2,LOW);
  digitalWrite(M1I3,LOW);
  digitalWrite(M1I4,HIGH);

  digitalWrite(M2I1,HIGH);
  digitalWrite(M2I2,LOW);
  digitalWrite(M2I3,LOW);
  digitalWrite(M2I4,HIGH);
}

void stop(){
  digitalWrite(M1I1,LOW);
  digitalWrite(M1I2,LOW);
  digitalWrite(M1I3,LOW);
  digitalWrite(M1I4,LOW);

  digitalWrite(M2I1,LOW);
  digitalWrite(M2I2,LOW);
  digitalWrite(M2I3,LOW);
  digitalWrite(M2I4,LOW);
}

int distanceCal(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  return distance;
}