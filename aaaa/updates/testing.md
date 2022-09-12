title: Motor Test
date: 2022-04-27
Series: testing

After my [investigation]({filename}investigation.md) with the conveyor belt, I thought that the board inside the conveyor would be able to drive any stepper motor. It had the same plug connecting to the motor as all the others and appeared to be wired up the same way.

I took the accessory motor port out of the broken Armdroid and used it to connect the turntable followed by the screw slider to the conveyor belt's control board. And the weird thing was, no matter how I set the switches on the control panel, (fast/medium/slow, forward/reverse, etc) the motors would just refuse to run. They just made the same "d-d-d-d-d-d-d-d-d-d-d-d" sound like they were trying to move.

I double checked all the connections, and they were okay. I double checked the ~~ULN2003A~~ (EDIT: that was an incorrect assumtion!), and it had all of its pins in its socket (and was getting quite hot, thus the heatsink). There's clearly something I am missing.
