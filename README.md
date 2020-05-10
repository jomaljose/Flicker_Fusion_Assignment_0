# Flicker Fusion Threshold 
### Embedded system assignment 0

`

## AIM

Set up a prototype of an Embedded System for the measurement of a person’s subjective flicker fusion threshold using Teensy 3.2 board. An LED with varying blinking frequency is used as stimulus and when it reaches the threshold flicker fusion frequency, the current frequency should be displayed in a serial monitor on a connected PC.


## INTRODUCTION

*"The **flicker fusion threshold**, is a concept in the psycho-physics of vision. It is defined as the frequency at which an intermittent light stimulus appears to be completely steady to the average human observer. Flicker fusion threshold is related to persistence of vision."*
##### Flicker Fusion Threshold https://en.wikipedia.org/wiki/Flicker_fusion_threshold
In this project I used a Teensy 3.2, a push button, 380 ohm resistor and LED to create a prototype. The frequency of LED blinking is continuously increasing in my prototype.  The flicker fusion frequency is displayed using serial monitor of VSCode when the push button is pressed.

## Methods
### Hardware Description
**Components**
 1. Teensy 3.2
 2. 330 ohm resistor
 3. Push button
 4. Wires
 5. Breadboard

**Pull up resistor calculation**
The equation to find the resistance of a pullup resistor
R = (Vs-Vf)/If
According to the [Teensy 3.2 data card](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Datasheet/Teensy%203_2%20card%20%20.pdf)the supply voltage of Teensy board is 3.6 - 6 Volts. The typical Vf of a red LED is 1.8 to 2.1Volts. The safe operating forward current through this led is taken as 10mA.
 Then,
(5-1.8)/10mA = 320ohm
Therefore the pullup resistor used in this circuit is 330 ohm.
**Push Button**
The mechanical push button may produce errors in switching therefore we have written codes for debouncing and enabled input pullup resistor internally in teensy 3.2.

### Circuit
The push button is connected to the D5 pin of Teensy 3.2 and GND pin. Led is connected to the 12th pin and GND.

![ Breadboard representation of circuit](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Circuit/Flickerfusion%20breadboard.png)


![ Schematic Diagram ](https://github.com/jomaljose/Flicker_Fusion_Assignment_0/blob/master/Circuit/Flickerfusion%20Schematic.png)
