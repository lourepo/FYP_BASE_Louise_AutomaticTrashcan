#include <Servo.h>

#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);



int trigPin = 8;
int echoPin = 9;
int limit = 20;

Servo myServo;



void setup()
{
  myServo.attach(7);
  
  lcd.begin(16, 2); // Set display to 16 columns and 2 rows
}

void loop()
{
  long duration, cm;

  pinMode(trigPin,OUTPUT);
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(trigPin,LOW);

  pinMode(echoPin,INPUT);
  duration = pulseIn(echoPin,HIGH);

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  if (cm<limit) {
    myServo.write(90);
    
    lcd.clear();
    delay(250);
    lcd.setCursor(0, 0);
  	lcd.print("Terima kasih sdh");
    lcd.setCursor(0, 1);
  	lcd.print("buang sampahnya!");
    delay(1000);
  }
  else {
    myServo.write(0);
    
    lcd.clear();
    delay(250);
    lcd.setCursor(0, 0);
  	lcd.print("Jangan lupa");
  	lcd.setCursor(0, 1);
  	lcd.print("buang sampah!");
    delay(1000);
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}