Title: Images

This page contains the images I took of the two Armdroid units.

The other accessories each have their own page:

* [Conveyor belt]({filename}conveyor.md)
* [Power supply unit]({filename}power.md)
* [Screw slider]({filename}slider.md)
* [Turntable]({filename}turntable.md)

## Base and Shoulder

Here's all the power connectors on the base:

%%% figure
    ![base connectors]({attach}start/front.png)

    %: I got the DB9 pinout from [here](https://armdroid1000.wordpress.com/control-protocol/).

The fourth accessory output is mounted on the shoulder.

%%% figure
    ![shoulder bearing]({attach}start/shoulder_bearing.png)

The labeling on the Armdroid 1000 was a little bit confusing. The serial number label on the base lists the address of D&M as "PO Box 2102, Fargo, North Dakota, 58107", but the stickers on the stepper motors simply list it as "Moorhead, Minnesota".

%%% figure
    ![side of armdroid]({attach}start/side.png)

    %: Where is D&M based out of??

The shoulder contains five of the six stepper motors that drive the movements of the Armdroid 1000. The motion is transmitted up to the joints by toothed timing belts and pulleys.

%%% figure
    ![gears view]({attach}start/shoulder.png)

    %: The wrist and claw motor's pulleys have 20 teeth while the elbow and shoulder pulleys have 14. The larger reduction pulleys have 72 teeth, and the gear pairs have 12 and 108 teeth (a 1:9 reduction).

Most of the joints have a pretty wide range of motion. The shoulder joint can easily flip over backwards and reveal the belts and tension rollers underneath.

%%% figure
    ![flip over]({attach}start/broken_base.png)

    %: This was taken of the broken Armdroid. The serial of that one is 1106.

The sixth motor rotates the base bearing via another gear-and pulley setup.

%%% figure
    ![base]({attach}start/top_base.png)

    %: This was taken of the Armdroid in better condition. The serial number of that one is 1105.

## Elbow and Claw

The elbow simply transmits the motion of the wrist belts and claw string. The pulley on the side is fixed to the forearm and is turned by the elbow motor belt.

%%% figure
    ![elbow]({attach}start/elbow.png)

The intact Armdroid (serial number 1105) had the two-finger claw on it. The broken one (serial 1106) had the cool three-finger claw that all the Armdroid 1's have, but unfortunately, it was broken.

%%% figure
    ![three finger claw]({attach}start/claw/claw_broken.png)
    ![two finger claw]({attach}start/claw/claw.png)

    %: It's a shame the three-finger claw is broken. It would look really cool!

## Circuitry

The circuit board inside contains a bunch of microchips in sockets (most from the 74LS series) that, as far as I have found, form a giant demultiplexer that routes the control signals to the right motor or output.

%%% figure
    ![circuit top]({attach}start/circuits/circuit_top.png)
    ![circuit bottom]({attach}start/circuits/circuit_bottom.png)

Dan Kohn has done the work of figuring out the general schematic of the circuit inside (although his pinout of the DB9 connector differs from the one I found above). You can find his schematic [here](http://dankohn.info/projects/armdroid_1000/schematic.pdf) (and if that goes down, there's a link to a local copy [here]({filename}../resources/index.md)). His part numbers differ slightly, but they're just different companies' takes of the same functional component.

There is more point-to-point wiring inside the base (here of the broken Armdroid, 1106). The motors all come down and terminate in a plug (including the accessory motor port wires), and there is a large reverse-polarity protection diode on the power connector. The positive wires also go through a kill switch and to one terminal of each of the accessory outputs. The low power outputs are wired to their own plug.

%%% figure
    ![inside base]({attach}start/inside_base.png)

    %: **Man**, those wires are twisted up.

Taking a closer look, the motor is a standard 200 steps/revolution unipolar motor. Unfortunately, in the broken Armdroid, the shoulder had been twisted around so many times that the wire leading up to the fourth accessory output in the shoulder broke the terminal of the third output and tore some of the wires leading to the motors.

%%% figure
    ![inside base detail]({attach}start/inside_detail.png)

    %: Yikes, that's pretty badly broken.
