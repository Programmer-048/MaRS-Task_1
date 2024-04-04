#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

int seconds = 0;
float cm = 0.0f;
int trigPin=12;
int echoPin=11;
int buzzer=3;
bool crash=false;

void setup()
{
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(2, INPUT);
  pinMode(buzzer, OUTPUT);
  lcd_1.blink();
  delay(1500);
  lcd_1.noBlink();
  noTone(buzzer);
  lcd_1.print("Booting");
  delay(200);
  lcd_1.print(".");
  delay(200);
  lcd_1.print(".");
  delay(200);
  lcd_1.print(".");
  delay(400);
  lcd_1.print("!");
  delay(500);
  lcd_1.blink();
  delay(2000);
  lcd_1.noBlink();
}

long readUltrasonicDistance(int triggerPin, int echoPin)
{
    // Clear the trigger
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void loop()
{
  lcd_1.setCursor(0, 1);
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(trigPin, echoPin);
  Serial.print(cm);
  Serial.print("cm\t");
  int reading = digitalRead(2);
  Serial.println(reading);
  if(reading&&cm>100)
  {
    lcd_1.home();
    lcd_1.noBlink();
    if(crash)
    {
      lcd_1.print("Flight Recovered!");
      delay(1000);
      lcd_1.clear();
    }
    crash=false;
    lcd_1.print("Flight Control:");
    lcd_1.setCursor(0, 1);
    lcd_1.print("Altitude:");
    lcd_1.print(cm);
  }
  else if(millis()>30000)
  {
    if(!reading&&cm>100)
  	{
      crash=true;
      lcd_1.clear();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Warning!!!");
    	lcd_1.setCursor(0, 1);
      lcd_1.blink();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Rolling!");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Pls Str.");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.setCursor(0, 1);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Rolling!");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Pls Str.");
      delay(1630);
      lcd_1.clear();
    }
    else if(cm<=100&&cm>=30&&!reading)
    {
      crash=true;
      lcd_1.clear();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Warning!!!");
      lcd_1.setCursor(0, 1);
      lcd_1.blink();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Altitude!");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("LowAlt");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.setCursor(0, 1);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Flight ");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.blink();
      lcd_1.print("Yawning!  ");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      delay(1630);
      lcd_1.clear();
    }
    else if(cm<=100&&cm>=30&&reading)
    {
      crash=true;
      lcd_1.clear();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Warning!!!");
      lcd_1.setCursor(0, 1);
      lcd_1.blink();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Altitude!");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("LowAlt");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.setCursor(0, 1);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Flight ");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.blink();
      lcd_1.print("Stalling!");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      delay(1630);
      lcd_1.clear();
    }
    else if(cm<30||cm>336)
    {
      crash=true;
      lcd_1.clear();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Warning!!!");
      lcd_1.setCursor(0, 1);
      lcd_1.blink();
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Altitude!");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("LowAlt");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.setCursor(0, 1);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.print("Flight ");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      lcd_1.blink();
      lcd_1.print("Crashing!");
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      tone(buzzer, 3951, 100);
      delay(170);
      noTone(buzzer);
      delay(1630);
      lcd_1.clear();
    }
  }
  delay(100); // Wait for 100 millisecond(s)
}