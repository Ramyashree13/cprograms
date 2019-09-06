#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int echo=2,trigPin=3,inches,cm;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  long duration,inches,cn;
  lcd.setCursor(0,1);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  duration=pulseIn(echo,HIGH);
  inches=msi(duration);
  cm=msc(duration);
  Serial.println(inches);
  Serial.println("in, ");
  Serial.println(cm);
  Serial.println("cm");
 lcd.print(inches);
  lcd.print("in, ");
  lcd.print(cm);
  lcd.print("cm");
  delay(1000);
  
}
long msi(long microseconds)
{
  return microseconds/74/2;
}
long msc(long microsecond)
{
  return microsecond/29/2;
}
