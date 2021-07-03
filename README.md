# NSGadget Scripts
Scripts/examples to automate inputs in Nintendo Switch games by plugging in a [Teensy](https://www.pjrc.com/teensy) into a Switch.

## Setup
* Clone the [NSGadget_Teensy](https://github.com/gdsports/NSGadget_Teensy) repo and create the "NS Gamepad" USB Type in Teensyduino
  * For Windows or Linux, follow the instructions in that repo.
  * For MacOS, just install Teensyduino, then copy the contents of `hardware` from NSGadget_Teensy to the correct files in Teensyduino.app's `hardware` directory.
* Go to Tools > USB Type, then select "NS Gamepad."
* Open a script, go to Tools > Verify/Compile, then Program and Reboot in the Teensyduino UI.
