Title: Armdroid 1000
Status: hidden
Save_as: index.html

In early 2022 I found two old Armdroid 1000's plus some of their accessories in the back of my engineering teacher's storage closet. Thus began an investigation into the history, mechanics, electronics, and software of the Armdroid 1000. This site curates the result.

## Overview

The Armdroid 1000 is a small blue robot arm produced by D&M Computing in the early 1990s. (They were based out of somewhere in the United States - I'm not sure where.) The Armdroid 1000 was based off another almost identical (and bright orange) robot arm called the Armdroid 1 produced in the mid-1980s by the now-defunct Colne Robotics (themselves based out of Twickenham, England). D&M was bought out by LabVolt and the 1000 was painted white and re-branded as the LabVolt 5100. The 5100 has since been superseded by other robots and is no longer in production as far as I know.

## Construction

The Armdroid 1000 is about two feet tall at its tallest, and weighs about eight pounds by itself. It has 6 degrees of freedom, controlled by stepper motors -- base rotation, shoulder motion, elbow motion, wrist up and down, wrist twisting, and gripper opening and closing. Five of the six motors are mouted on the shoulder frame, and are connected to the joints by toothed timing belts and pulleys.

The Armdroid 1000's base contains no microprocessor - all the circuit does is demultiplex the signals from an eight-bit serial port into the six motors. The software implements the control signal generation.

The Armdroid 1000 also includes four low-power (0-5V TTL) outputs mounted on the base, four high-power outputs (three on the base and one on the shoulder), and a seventh accessory motor output connector (5-pin GX-16) on the base.

## Power

The Armdroid needs about 12 volts and 5 amps to run -- there are 6 stepper motors, 2 phases each, 380mA per phase. An internal regulator produces the 5 volts for the logic circuits. The power is input using a 2-pin female GX-16 connector, with "+" on the right. There is a large reverse-polarity protection diode right behind the connector so it will cause no harm if you get it wrong -- just turn the connector around.
