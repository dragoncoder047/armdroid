The code in here is what I used to test the 8-bit serial port on the Armdroid.

For the numbering of which number corresponds to which motor please see `armdroid.hpp`.

Note you will need a *very large* power supply to run the armdroid with this code -- it often doesn't turn off the motors when it should, and so it draws on the order of 4 amps even when not moving. A cheap 2-amp benchtop power supply caused massive brown-outs and lots of jittering. A 12-volt NiMH battery capable of supplying 20 amps did the trick.
