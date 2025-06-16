


## r0 Assembly Notes

- I forgot IO8 needs to be high at boot to be able to program the part.  Currently connected to c6, so I won't be able to use that output for now.
- I don't have the right inductors for the regulator on hand, so I used 33uH for both.  3.3v works, but 12v is down around 1v.  I'll try the correct inductor, but it might be easier to use a 12v wall wart.  Doorbell transformers give AC, so I'd have to convert it anyways.


## Changes for r1

- Removed the 12V regulator and added a barrel jack for power input.  
- Moved the `c6` signal from IO8 to IO18.  `IO8` needs to be high to program the esp32.  I'm not planning on using USB, so IO18 should be fine.
- Added a screw terminal to signal that the button has been pressed and wired it to IO19.  Added a pull-up on the signal, but I'm not sure if I'll need it.


I wasn't thinking about how the signal will come from the button, but in a typical doorbell, the button closes a circuit that will supply us with 12-14V AC.  I could put a bridge rectifier circuit in, and just use that but then I will only have power while the button is held down.  I think the best option would to use  12v wall wart and signal the bell to activate either by:
	1. A small circuit that detects when the low side of the doorbell transformer turns on and sends a 3.3v signal to my board
	2. Something wireless
So either way, the driver board will just expect a 3.3v signal and start the sequence when it gets the signal