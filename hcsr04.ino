void trigger(){
  digitalWrite(4,LOW);
  delayMicroseconds(5);
  digitalWrite(4,HIGH);
  delayMicroseconds(5);
  digitalWrite(4,LOW);
}

double echo(){
  double duration=pulseIn(3,HIGH);
  double distance=duration/58.0;
  return distance;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  pinMode(4,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
   trigger(); 
   float dist=echo();
   Serial.println(dist);
   if(dist<30){
     digitalWrite(11,LOW);
     digitalWrite(12,LOW);
     digitalWrite(13,HIGH);
    }
  else if(dist>10 && dist<100){
      digitalWrite(11,LOW);
     digitalWrite(12,HIGH);
     digitalWrite(13,LOW);
    }
   else if(dist>100){
      digitalWrite(11,HIGH);
     digitalWrite(12,LOW);
     digitalWrite(13,LOW);
    }
   delay(500);
}
