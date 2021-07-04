#include "usb_nsgamepad.h"

#define PRESS_DELAY 500
#define FRAME_MS 33 // 30 fps

void pressButton(NSButtons b, int d)
{
  NSGamepad.press(b);
  NSGamepad.write();
  delay(d);
  NSGamepad.release(b);
  NSGamepad.write();
}

void pressButtonPrecise(NSButtons b, int numFrames)
{
  noInterrupts();
  uint32_t beginMillis = systick_millis_count;
  interrupts();
  pressButton(b, FRAME_MS);
  noInterrupts();
  uint32_t delayMillis = int((FRAME_MS * numFrames) - (systick_millis_count - beginMillis));
  interrupts();
  delay(delayMillis);
}

void pressTriggers(int d)
{
  NSGamepad.press(NSButton_LeftTrigger);
  NSGamepad.press(NSButton_RightTrigger);
  NSGamepad.write();
  delay(d);
  NSGamepad.release(NSButton_LeftTrigger);
  NSGamepad.release(NSButton_RightTrigger);
  NSGamepad.write();
}

void confirmController()
{
  // Send it some input, then wait, so the Switch begins the change controller menu
  pressButton(NSButton_Y, PRESS_DELAY);
  delay(PRESS_DELAY);
  pressButton(NSButton_Y, PRESS_DELAY);
  delay(PRESS_DELAY);
  pressButton(NSButton_Y, PRESS_DELAY);
  delay(PRESS_DELAY);
  pressTriggers(300);
  delay(PRESS_DELAY);
  pressButton(NSButton_A, PRESS_DELAY);
}

void botwViewMemoryPrompt()
{
  pressButtonPrecise(NSButton_A, 6);
  pressButtonPrecise(NSButton_A, 10);
  pressButtonPrecise(NSButton_A, 9);

  NSGamepad.dPad(NSGAMEPAD_DPAD_RIGHT);
  NSGamepad.write();

  delay(FRAME_MS);

  NSGamepad.press(NSButton_A);
  NSGamepad.write();

  delay(FRAME_MS);

  NSGamepad.release(NSButton_A);
  NSGamepad.write();
  NSGamepad.dPad(NSGAMEPAD_DPAD_CENTERED);
  NSGamepad.write();
}

void setup() {
  // Sends a clean HID report to the host.
  NSGamepad.begin();
  confirmController();
  delay(3000);
  botwViewMemoryPrompt();
}

void loop() {
  NSGamepad.loop();
}
