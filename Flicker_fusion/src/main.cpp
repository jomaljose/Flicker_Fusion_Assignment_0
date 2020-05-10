#include <Arduino.h>
#define buttonpin 5                     // Number of the Button pin
#define ledPin    12                    // Number of the LED pin
int ledState = LOW;                     // LedState used to set the LED
unsigned long previousMillis = 0;       // Will store last time(in milli seconds) LED was updated
const uint32_t debouncedelay_ms = 150;  // Small delay for debounce
volatile boolean buttonpress = 0;       // Variable for button state
void buttonpress_ISR();                 // Interrupt function
float frequency = 0.5, time_period_ms = 0; 
uint16_t repeat = 0;                    //variable to repeat same frequency signal multiple times

void setup() {
  
  pinMode(ledPin, OUTPUT);          // set the digital pin as output
  pinMode(buttonpin, INPUT_PULLUP); // Enabling internal pullup resistor for button
  Serial.begin(115200);             // Baud rate
  attachInterrupt(digitalPinToInterrupt(buttonpin), buttonpress_ISR, FALLING); // button press enable interrupt function 'buttonpress_ISR'
}

void loop() {
  if(frequency==90)     //Loop to repeat the blinking frequency from 0.5Hz when it reaches 90Hz
  {
    frequency=0.5;
  }
    //Plot point - 1
    //Serial.println(ledState); 
  if(repeat == 15000)   //Lopp to repeat same frequency signal multiple time and then increment frequency
  {
   frequency = frequency + 0.5;
   repeat = 0;
  }
 
  time_period_ms = (1/frequency) * 1000; //Time period(ms), frequensy relation
  unsigned long currentMillis = millis();//millis function used
    //Plot point - 2
    //Serial.println(ledState);
  if (currentMillis - previousMillis >= (time_period_ms/2)) //Loop for LED toggling after every half time period
  {
    //points 3 and 4 are only used to plot the graph
    //Plot point - 3
    //Serial.println(ledState);        
    ledState = !ledState;
    digitalWrite(ledPin,ledState);
    previousMillis = currentMillis;
    //Plot point - 4 
    //Serial.println(ledState);
    Serial.flush();
  }
  repeat++;
}

void buttonpress_ISR()                                                    // Interrupt function
{
  static uint32_t previoustimebutton_ms = 0;                              // Variable for debouncing
  uint32_t currenttimebutton_ms = millis();                               // Variable for debouncing
   if((currenttimebutton_ms - previoustimebutton_ms) >= debouncedelay_ms) // Code inside loop only executes if buttonpress time is greater than debounce delay_ms
  { buttonpress = !buttonpress;
    previoustimebutton_ms = currenttimebutton_ms;
    // printing commands to print Flicker fusion frequency and timeperiod
    Serial.print("\nFrequency:");
    Serial.print(frequency);
    Serial.print("Hz");
    Serial.print("       Time period:");
    Serial.print(time_period_ms);
    Serial.print("ms");
    Serial.println();
        
  }
}