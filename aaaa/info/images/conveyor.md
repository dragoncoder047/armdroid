Title: Conveyor Images
Status: hidden

The conveyor accessory is just a long conveyor, about three feet long. One end holds a power supply unit and a stepper motor to run the belt and a simple control board that controls the speed and direction of the conveyor. Because of the power supply the whole thing weighs abut ten pounds, and combined with its size, makes it a little awkward to move around and store.

%%% figure
    ![conveyor front]({attach}start/conveyor/conveyor_front.png)

On the side there is a fuse receptable and a power switch.

%%% figure
    ![conveyor switch side]({attach}start/conveyor/conveyor_switch.png)

    %: Strange, the fuse rating isn't marked.

Inside the control box you can see the toroidal transformer in the back, the stepper motor (mounted on slots to adjust the belt tension), and the circuit board.

%%% figure
    ![conveyor inside]({attach}start/conveyor/conveyor_inside.png)

%%% figure
    ![circuit top]({attach}start/conveyor/conveyor_board_front.png)

    %: The heatsunk one is a [L6220](../resources/datasheets/L6220-darlington-switches.pdf) Darlington switch (I think?) that runs the motor, while the other large chip is a [74LS175](../resources/datasheets/74LS175-d-flip-flop.pdf) quad D flip-flop with the flops wired into each other to count the pulses from the oscillator and turn it into control signals for the motor. The small 8-pin microchip (next to the small blue 4.7&micro;F timing capacitor) is a 555 timer wired in astable mode.

Someone had ~~green~~ yellow-wired the back of the circuit board to fix a routing error.

%%% figure
    ![circuit bottom]({attach}start/conveyor/conveyor_board_back.png)

    %: The pin on the bottom was supposed to be connected to +5V, but it was routed to GND by mistake. The trace had been carefully cut (due to the proximity of the nearby pins) and the yellow wire connected to it and the OUT pin of the voltage regulator.

The back of the control panel contains some point-to-point wiring to connect all the banana jacks and switches to the ribbon cable from the main circuit board.

%%% figure
    ![conveyor control board wiring]({attach}start/conveyor/conveyor_control_wiring.png)

    %: I have no idea how this is wired up. And I really don't know what the 10&micro;F capacitor is for -- debouncing, perhaps?
