This code was used with a ULN2003A on a breadboard to test the motors.

Connect pins 3, 4, 5, and 6 of the Arduino (or whatever you choose, edit the `#define`s at the top) to four input channels of the ULN2003A, and the output channels to the four leftmost pins on the motor's plug.

Connect the remaining (rightmost) pin of the motor plug, pin 9 of the ULN2003A ("flybacks common cathode"), and the Arduino's VIN pin to +12V, and the Arduino ground to pin 8 of the ULN2003A and power supply ground.

Connect the ends of a potentiometer to +5V and GND coming off the Arduino, and the wiper to pin A0. This is the speed control.
