Title: It works!... almost
Date: 2023-01-09
Series: arduino-testing

Today I fiddled around with the Armdroid and the patch cable I made to connect the Armdroid's parallel port to my Arduino. After working out the pin numbers, I was able to get motors to run.

Originally I was using a cheap 2-amp-max bench power supply and occasionally the Arduino would glitch and a motor would start wiggling randomly. Doing some quick calculations with the Armdroid's power demands (6 motors, 2 phases each, 0.3 amps per phase) showed that the Armdroid was potentially drawing 3.6 amps, way more than the rated 2 amps of the power supply I was using, and so the voltage was probably drooping enough to cause the Arduino to go haywire.

I dug out the large 12-volt NiMH battery pack that I was already planning on using for the Armdroid and hooked it up. This battery was rated for 20 amps maximum (ten times the mximum power output of the power supply) and everything worked nicely. Almost.

While I was fiddling around with it I was able to determine which port address controlled to which motor. I was able to determine 6 of the 8 motor numbers from fiddling with it, and wrote them into the code with the joysticks module I had made up on a breadboard so I could control the Armdroid. I took a guess on the other two motors. 

Unfortunately, one motor still didn't work. Either I guessed wrong and I was sending the signal to the wrong motor port, or the motor was physically malfunctioning. The `WRIST_RIGHT` motor would not turn, and I do not really know why.

But aside from this, the rest of it works. This is a whole lot farther along than I expected I would end up at this point in the year, and I am thankful I was even able to start this project, let alone get this far. The poor Armdroid hadn't probably been even turned on in over 20 years, and now the fact that a hobbyist like me was able to make it run is just amazing.
