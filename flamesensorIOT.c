int ledpin=9;
int buzzer=7;
int flame=A5;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(flame,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  
    digitalWrite(ledpin,LOW);
    digitalWrite(buzzer,LOW);
    int flamevalue=analogRead(flame);
    //Serial.println(flamevalue);
    int threshold=40;
    if(flamevalue<threshold)
    {
      digitalWrite(ledpin,HIGH);
      digitalWrite(buzzer,HIGH);
    }
    else
    {
      digitalWrite(ledpin ,LOW);
      digitalWrite(buzzer,LOW);
    }
    Serial.println("flame value");
    Serial.println(flamevalue);
  
  delay(1000);

}
