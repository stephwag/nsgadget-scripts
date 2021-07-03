# NSGadget Scripts
Scripts/examples to automate inputs in Nintendo Switch games by plugging in a [Teensy](https://www.pjrc.com/teensy) into a Switch.

## Setup
* Clone the [NSGadget_Teensy](https://github.com/gdsports/NSGadget_Teensy) repo and create the "NS Gamepad" USB Type in Teensyduino
  * For Windows or Linux, follow the instructions in that repo.
  * For MacOS, just install Teensyduino, then copy the contents of `hardware` from NSGadget_Teensy to the correct files in Teensyduino.app's `hardware` directory.
* Go to Tools > USB Type, then select "NS Gamepad."
* Open a script, go to Tools > Verify/Compile, then Program and Reboot in the Teensyduino UI.

## Example

`view_memory.ino` will allow you to perform the frame-perfect portion of setting up the [memory storage glitch](https://zelda.fandom.com/wiki/Glitches_in_Breath_of_the_Wild#Memory_Storage).

https://user-images.githubusercontent.com/4019335/124366588-d83df200-dc1e-11eb-9a28-f4f357dc7c25.mp4

