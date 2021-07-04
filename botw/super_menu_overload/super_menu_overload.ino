#include "usb_nsgamepad.h"

#define FRAME_MS 33 // 30 fps
#define CONFIRM_DELAY_FRAMES_MS (FRAME_MS * 15)
#define MENU_DELAY_SHORT_FRAMES_MS (FRAME_MS * 2)
#define MENU_DELAY_MEDIUM_FRAMES_MS (FRAME_MS * 6)
#define MENU_DELAY_LONG_FRAMES_MS (FRAME_MS * 10)

void pressButton(NSButtons b, int d)
{
  NSGamepad.press(b);
  NSGamepad.write();
  delay(d);
  NSGamepad.release(b);
  NSGamepad.write();
}

void pressDPad(uint8_t dp, int d)
{
  NSGamepad.dPad(dp);
  NSGamepad.write();
  delay(d);
  NSGamepad.dPad(NSGAMEPAD_DPAD_CENTERED);
  NSGamepad.write();
}

void pressTriggers(float d)
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
  pressButton(NSButton_LeftTrigger, CONFIRM_DELAY_FRAMES_MS);
  delay(CONFIRM_DELAY_FRAMES_MS);
  pressButton(NSButton_LeftTrigger, CONFIRM_DELAY_FRAMES_MS);
  delay(CONFIRM_DELAY_FRAMES_MS);
  pressButton(NSButton_LeftTrigger, CONFIRM_DELAY_FRAMES_MS);
  delay(CONFIRM_DELAY_FRAMES_MS);

  pressTriggers(CONFIRM_DELAY_FRAMES_MS);
  delay(CONFIRM_DELAY_FRAMES_MS);
  pressButton(NSButton_A, CONFIRM_DELAY_FRAMES_MS);
  
}

/* Before calling this, make sure that:
 * - Game is paused
 * - Regular menu overload is set up
 * - Weapon to be desynced is highlighted, and the cursor is on it
 * - Weapon to desync with is on the left side
 */
void botwSuperMenuOverload()
{
  // Move cursor to the weapon on the left, desyncing the current
  pressDPad(NSGAMEPAD_DPAD_LEFT, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Select/desync
  pressButton(NSButton_A, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Equip
  pressButton(NSButton_A, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Unpause
  pressButton(NSButton_Plus, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Aim and throw
  pressButton(NSButton_RightTrigger, FRAME_MS * 30);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Pause
  pressButton(NSButton_Plus, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Move cursor to weapon that will be desynced
  pressDPad(NSGAMEPAD_DPAD_RIGHT, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Select weapon
  pressButton(NSButton_A, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Equip
  pressButton(NSButton_A, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  // Unpause
  pressButton(NSButton_Plus, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);

  //Draw bow, and wait a bit, usually causes another overload
  pressButton(NSButton_RightThrottle, MENU_DELAY_SHORT_FRAMES_MS);
  delay(FRAME_MS * 30);

  // Pause
  pressButton(NSButton_Plus, MENU_DELAY_SHORT_FRAMES_MS);
  delay(MENU_DELAY_MEDIUM_FRAMES_MS);
}

void setup() {
  // Sends a clean HID report to the host.
  NSGamepad.begin();
  confirmController();
  delay(FRAME_MS * 100);
}

void loop() {
  botwSuperMenuOverload();
  NSGamepad.loop();
}
