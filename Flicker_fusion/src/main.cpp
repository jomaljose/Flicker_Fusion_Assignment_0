#include <Arduino.h>
#define buttonpin 5
#define ledPin    12// the number of the LED pin
int ledState = LOW;             // ledState used to set the LED
unsigned long previousMillis = 0;        // will store last time LED was updated
const uint32_t debouncedelay_ms = 150;
volatile boolean buttonpress = 0;
void buttonpress_ISR();
float frequency = 0.5, time_period = 1;
uint16_t repeat = 0;

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonpin), buttonpress_ISR, FALLING); // push button external interrupts
}

void loop() {
  if(frequency==90)
  {
    frequency=0;
  }
 
  if(repeat == 15000)
  {
   frequency = frequency + 0.5;
   repeat = 0;
  }
 
  time_period = (1/frequency) * 1000;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= (time_period/2))
  {
    
    //Plot point - 1
    //Serial.println(ledState);
    //Serial.println(previousMillis);
    ledState = !ledState;
    digitalWrite(ledPin,ledState);
    previousMillis = currentMillis;
    //Plot point - 2
    //Serial.println(ledState);
  }
  repeat++;
}

void buttonpress_ISR()
{
  static uint32_t previoustimebutton_ms = 0;
  uint32_t currenttimebutton_ms = millis();
   if((currenttimebutton_ms - previoustimebutton_ms) >= debouncedelay_ms)
   {buttonpress = !buttonpress;
   previoustimebutton_ms = currenttimebutton_ms;
   
  Serial.print("Frequency:");
  Serial.print(frequency);
  Serial.print("Hz");
  Serial.print("       Time period:");
  Serial .print(time_period);
  Serial.print("ms");
  Serial.println();
}}