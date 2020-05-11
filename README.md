# Flicker Fusion Threshold 
### Embedded system assignment 0



## AIM

Set up a prototype of an Embedded System for the measurement of a person’s subjective flicker fusion threshold using Teensy 3.2 board. An LED with varying blinking frequency is used as stimulus and when it reaches the threshold flicker fusion frequency, the current frequency should be displayed in a serial monitor on a connected PC.


## INTRODUCTION

*"The **flicker fusion threshold**, is a concept in the psycho-physics of vision. It is defined as the frequency at which an intermittent light stimulus appears to be completely steady to the average human observer. Flicker fusion threshold is related to persistence of vision."*
##### Flicker Fusion Threshold https://en.wikipedia.org/wiki/Flicker_fusion_threshold
In this project I used a Teensy 3.2, a push button, 390 ohm resistor and LED to create a prototype. The frequency of LED blinking is continuously increasing in my prototype.  The flicker fusion frequency is displayed using serial monitor of VSCode when the push button is pressed.

## METHODS
### Hardware Description


#### Components


 1. Teensy 3.2
 2. 390 ohm resistor
 3. Push button
 4. Wires
 5. Breadboard



#### Pull up resistor calculation


The equation to find the resistance of a pullup resistor
R = (Vs-Vf)/If
According to the [Teensy 3.2 data card](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Datasheet/Teensy%203_2%20card%20%20.pdf)the input voltage of Teensy board is 3.3 - 6 Volts.The output voltage of Teensy 3.2 board is 3.3V. The typical Vf of a red LED is 1.8 to 2.1Volts. The safe operating forward current through this led is taken as 10mA.
 Then,
(3.3-1.8)/10mA = 150ohm
Therefore for the safe operation of LED the pullup resistance should be greater than 150 ohm. The pullup resistor used in this circuit is 390 ohm.

#### Push Button

The mechanical push button may produce errors in switching therefore we have written codes for debouncing and enabled input pullup resistor internally in teensy 3.2.

### Circuit
The push button is connected to the D5 pin of Teensy 3.2 and GND pin. Led is connected to the D12 pin and GND.
It is also explained in this Youtube video:
https://youtu.be/GUNod7JRGfk

![ Breadboard representation of circuit](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Circuit/Flickerfusion%20breadboard.png)
![Schematic Diagram](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Circuit/Flickerfusion%20Schematic.png)
### [Software](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Flicker_fusion/src/main.cpp)
 VSCode with Platform IO extension is used to code in this project. The pin 12 and 5 is defined as *ledpin* and *buttonpin* respectively. Internal pullup resistor is enabled by `pinMode(buttonpin, INPUT_PULLUP)` for the button pin. The frequency of led is varied from 0.5Hz to 90Hz using if loop. When the Flicker fusion frequency reaches, the person will press the button and it will trigger the interrupt. In the interrupt routine function, frequency at that time is displayed on the serial monitor along with time period in millisecond. Interrupt is triggered on the falling edge of the switching action. 
 
### Output Waveform Display
The waves generated is, by serial printing the led state and plotting it using [Serialplot](https://hackaday.io/project/5334-serialplot-realtime-plotting-software) software. 
## [RESULT](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/tree/master/Output)
The flicker fusion threshold frequency is printed on the serial monitor when the button is pressed.
![Screenshot of VSCode serial monitor](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Output/Serial%20monitor%20Screenshot.jpg)

The output is verified by plotting the led state by using Serial plot software.
![Screenshot of Serialplot software at iption hereherehere](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Output/Serial%20Plot%20output_waveform.png)
This waveform is plotted at 35Hz frequency. The plotted waveform consist of 4 samples in every wave cycle. In the above figure at right corner of the serial plot window SPS (samples per second) is shown. By dividing the SPS by 4 we get the frequency of the plotted waveform.
In this case the SPS is 138
Therefore the frequency of the plotted waveform will be 138/4 = **34.5Hz**.
## FUTURE SCOPE & LIMITATIONS
The current prototype is giving flicker fusion threshold frequency value almost similar to the theoretical value of human flicker fusion threshold frequency. Eventhough,the plotted waveform have some error with the actual serial printed frequency. In future I like to eliminate this error and make it available for primary school teachers, because it will be helpful for them to teach persistence of vision.

## CONCLUSION

Human  flicker fusion threshold was tested successfully using this prototype. My conclusion after several tests is that my flicker fusion threshold frequency is between 37-39.5Hz.

This project gave me the opportunity to get into GitHub, Teensy 3.2 and different IDEs etc.


## REFERENCES

 1. Wikipedia contributors. (2020, January 29). Flicker fusion threshold. Retrieved from https://en.wikipedia.org/wiki/Flicker_fusion_threshold
 2. Teensyduino: Using the UART (real serial) with Teensy on the Arduino IDE. (2020). Retrieved from https://www.pjrc.com/teensy/td_uart.html
 3. Vishay Semiconductors. (2019). _TLUR6400, TLUR6401 datasheet_ (2019 revised ed.), Vishay Semiconductors.
