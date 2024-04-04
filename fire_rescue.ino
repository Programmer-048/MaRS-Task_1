#include<SoftwareSerial.h>

int sensorPin = A0; // select the input pin for the LDR
int gassenPin = A1;
int pirsenPin = 2;
int sensorValue = 0;// variable to store the value coming from the sensor
int gassenValue = 0;
int pirsenValue = 0;
int led = 9; // Output pin for LED
int buzzer = 12; // Output pin for Buzzer
int sensorMin = 20;		//
int sensorMax = 358;	//

void setup()
{
	// declare the ledPin and buzzer as an OUTPUT:
	pinMode(sensorPin,INPUT);
	pinMode(gassenPin,INPUT);
	pinMode(pirsenPin,INPUT);
	pinMode(led, OUTPUT);
	pinMode(buzzer,OUTPUT);
	Serial.begin(9600);
}

void loop()
{
	sensorValue = analogRead(sensorPin);
    gassenValue = analogRead(gassenPin);
    pirsenValue = digitalRead(pirsenPin);
	Serial.print(sensorValue);
	Serial.print("\t");
	Serial.println(pirsenValue);
  	//int range = map(sensorValue,  sensorMin, sensorMax, 0, 20);
	if (sensorValue>315 && pirsenValue)
	{
		Serial.println("Fire Detected, Person trapped\nSave Him/Her.");
		Serial.println("LED on");
		digitalWrite(led,HIGH);
		digitalWrite(buzzer,HIGH);
		delay(1000);
	}
	digitalWrite(led,LOW);
	digitalWrite(buzzer,LOW);
	delay(sensorValue);
}