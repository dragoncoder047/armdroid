Title: Armdroid Power Supply Pictures
Status: hidden

The power supply that came with the Armdroid was just a big black box with a switch on the front and two banana jacks on the back. I plugged it in and tested it one day - something is broken, because no power came out the banana jacks.

I took a picture of the front of the power supply, but I lost it. If I find it, I will put it here and edit this out.

The back of the power supply is dominated by a large heatsink containing two 2N3771 power NPN transistors.

%%% figure
    ![power transistors]({attach}start/power/power_back.jpg)

Inside the unit there is a large transformer (largely responsible for the weight), a circuit board balanced on a large 16000&micro;F capacitor, and various point-to-point components. There is a large 2200&micro;F capacitor hanging from the banana jacks, and two 10&ohm; 5W power resistors connecting one of the pins of the 2N3771's to ground (which are wired in parallel).

%%% figure
    ![inside]({attach}start/power/power_inside.jpg)

Pulling the capacitor out of the clamp allowed me to get a shot of the underside of the circuit board. This photo also revealed the half-bridge rectifier that turns the AC from the transformer into DC.

%%% figure
    ![underside]({attach}start/power/power_inside_under.jpg)
    %: The large capacitor looks like it is rated for 25V, but when I turned on the power supply it charged up to 60V. I'm proably not reading that label right.

Here's a zoomed in shot of the circuit board. The first thing that jumped out at me was the LM723CN power regulator.

%%% figure
    ![details]({attach}start/power/power_circuit_detail.png)
