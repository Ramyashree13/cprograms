int apin=0;

void setup() {
  pinMode(apin,INPUT);
  Serial.begin(9600);  

}

void loop() {
  int val=analogRead(apin);
  float mvvalue=((float)val/1024) * 5000;
  float tempc= mvvalue/10;
  Serial.println("Temp in c");
  Serial.println(tempc);
  Serial.println("temp in f");
  Serial.println((9/5)* tempc+32);
  delay(1000);

}
