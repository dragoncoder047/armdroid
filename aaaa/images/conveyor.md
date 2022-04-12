Title: Conveyor Images
Status: hidden

The conveyor accessory is just a long conveyor, about a meter's worth of it. One end holds a power supply unit and a stepper motor to run the belt and a simple control board that controls the speed and direction of the conveyor.

%%% figure
    ![conveyor front]({attach}start/conveyor/conveyor_front.png)

On the side there is a fuse receptable and a power switch.

%%% figure
    ![conveyor switch side]({attach}start/conveyor/conveyor_switch.png)
    %: Strange, the fuse rating isn't marked.

Inside the control box you can see the toroidal transformer in the back, the stepper motor (mounted on slots to adjust the belt tension), the 4700&micro;F power capacitor, a voltage regulator, and a few microchips.

%%% figure
    ![conveyor inside]({attach}start/conveyor/conveyor_inside.png)
    %: I'm guessing the heatsunk one is probably the Darlington switch that runs the motor, while the larger of the unheatsunk ones is some sort of binary counter thing to count the pulses from the oscillator and turn it into control signals for the motor. The small 8-pin microchip (behind the small blue capacitor) is probably a 555 timer or something to generate a clock signal.

The back of the control board contains some point-to-point wiring to connect all the banana jacks and switches to the ribbon cable from the main circuit board.

%%% figure
    ![conveyor control board wiring]({attach}start/conveyor/conveyor_control_wiring.png)
    %: I have no idea how this is wired up.
