This code was used with a ULN2003A on a breadboard to test the motors.

Connect pins 3, 4, 5, and 6 of the Arduino (or whatever you choose, edit the `#define`s at the top) to four input channels of the ULN2003A, and the output channels to the four leftmost pins on the motor's plug. Alternatively you can just use four transistors if you don't have a ULN2003A -- I like the 2N7000.

Connect the remaining (rightmost) pin of the motor plug, pin 9 of the ULN2003A ("flybacks common cathode"), and the Arduino's VIN pin to +12V, and the Arduino ground to pin 8 of the ULN2003A and power supply ground.

Pin A0 is the control voltage which affects the motor speed and direction. Connecting it to GND will try to run the motor at 600 RPM backwards, while +5V will try to run it at 600 RPM forwards. You can use a potetntionmeter to vary the speed in-between.
