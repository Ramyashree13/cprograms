int calibrationTime=30;
long unsigned int lowIn,pause=2000;
boolean lockLow=true;
boolean takeLowTime;
int pir=4;
int led=13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pir,INPUT);
  pinMode(led,OUTPUT);
  digitalWrite(pir,LOW);
  Serial.print("calibrating the sensor:");
  for(int i=0;i<calibrationTime;i++)
  {Serial.print('.');
  delay(100);
  }
  Serial.println("Done.");
  Serial.println("Sensor active:");
  delay(10);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(pir)==HIGH)
  {
    digitalWrite(led,HIGH);
    if(lockLow)
    {
      lockLow=false;
      Serial.println("----");
      Serial.println("Motion detected at");
      Serial.println((millis()/1000));
      Serial.println("sec.");
      delay(50);
    }
    takeLowTime=true;
    
   }
   if(digitalRead(pir)==LOW)
   {
    digitalWrite(led,LOW);
    if(takeLowTime)
    {
      lowIn=millis();
      takeLowTime=false;
    }
    if(!lockLow && millis()-lowIn>pause)
    {
      lockLow=true;
      Serial.print("Motion ended at :");
      Serial.print((millis()-pause)/1000);
      Serial.println("Sec:");
      delay(50);
    }
  }
}
