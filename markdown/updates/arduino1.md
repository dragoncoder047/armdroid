Title: Arduino Testing, part 1
Date: 2022-09-19
Series: arduino-testing

I finally was able to throw together a little code to have the Arduino run a motor.

Using a ULN2003A pried off the Armdroid circuit board, a joystick (as a potentiometer), and [this code](https://github.com/dragoncoder047/armdroid/tree/0e6a1e789503525e8df2b1a63d6744e86665522d/code/motor-run-test), I hooked up a motor like so:

![arduino wiring]({attach}arduinotesting.png)

And it worked! The motor ran! And it ran very well!!

My only disappointment is I could not get the motors to run faster than 180 RPM reliably without skipping steps. Of course, they would run faster when under no load, bu when are they ever going to be under no load? Sigh. The Armdroid is a very slow robot.
