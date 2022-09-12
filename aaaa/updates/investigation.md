Title: Investigation
Date: 2022-04-22
Series: testing

A couple days ago it finally dawned on me that I hadn't tested the power supply inside the [conveyor belt](/armdroid/page/images/conveyor.html) that came with the Armdroid. So I plugged everything together and turned it on.

The motor started making a "d-d-d-d-d-d-d-d-d-d-d-d" sound like it was trying to move, and when I (carefully!) removed the cover with the motor on, I could see that it was indeed trying to move, but something was wrong and it was jumping backwards every cycle. I didn't really know what was going on, but unfortunately the bell rang at the end of lunch and I had to go to fifth period.

Today I pulled the little circuit board off the plastic standoffs it was attached to and had a look at it. Back when I opened the front cover to get the pictures of it, the heatsunk chip popped out of its socket, and so I absentmindedly smushed it back in. It turns out that one of its pins had missed the hole in the socket when I had done that and was not connected, hence the missing step in the driver cycle. And the out-of-place pin was hiding between the socket and the stepper motor's plug next to it, where I could not see without taking the board out. Sneaky sneaky.

After fixing the chip's pin, the motor ran just fine. On "high" it ran about 60 RPM (and with 200 steps per revolution, that's 200 Hz for the clock if each step takes one oscillation of the clock), on "medium" it ran about 40 RPM, and "low" was 20 RPM (3 seconds per revolution).

Pulling the board out of its enclosure also allowed me to get a look at the chips on it. And it turns out my hunch was right -- the small 8-pin chip was indeed a 555 timer, ~~the heatsunk chip was the same ULN2003A quad Darlington switch used in the Armdroid itself~~ (EDIT 9/12/22: Nope, I was wrong!), and the third one is a 74LS175 quad D flip-flop that I assume is wired into itself to turn the pulses from the 555 into quadrature control signals for the motor. I updated the conveyor's page on the Armdroid website to actually list these part numbers instead of just my hunch.

See how much you can learn when you *actually look at stuff closely*? That's a lesson that I really need to learn.
