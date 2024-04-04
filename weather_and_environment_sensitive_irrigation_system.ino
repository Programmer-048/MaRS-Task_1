#include <Servo.h>
#include <Adafruit_NeoPixel.h>

#define PIN 2	 // input pin Neopixel is attached to
#define NUMPIXELS      8 // number of neopixels in strip

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Servo servo_9;

int pos = 0;
int moisture=0;
int temperature=0;
int sunlight=0;
int limit;

void setup()
{
  Serial.begin(9600);
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A3, INPUT);
  pinMode(A5, INPUT);
  servo_9.attach(9, 500, 2500);
  servo_9.write(0);
  strip.begin();
}

void loop()
{
  digitalWrite(A0, HIGH);
  delay(10);
  moisture=analogRead(A1);
  temperature=analogRead(A5);
  sunlight=analogRead(A3);
  limit=map(moisture, 0, 872, 0, 8);
  digitalWrite(A0, LOW);
  Serial.print(moisture);
  Serial.print("\t");
  Serial.print(temperature);
  Serial.print("\t");
  Serial.println(sunlight);
  for(int i=0; i<8; i++)
  {
    if(i<=limit)
      strip.setPixelColor(i, 0, 200, 255);
    else
      strip.setPixelColor(i, 0, 0, 0);
  }
  strip.show();
  if(moisture<150 || (sunlight && temperature>215) || (!sunlight && temperature<153))
    servo_9.write(90);
  else
    servo_9.write(0);
}