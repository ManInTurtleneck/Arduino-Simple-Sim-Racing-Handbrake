#include <Joystick.h>

const uint8_t POT_PIN = A0; // change to A1/A2/A3 if soldered to different analog pin
const bool INVERT = true;  // set true if direction is backwards
const int start = 1023;     // adjust value to increase distance you need to pull handbrake for start of activation (default 1023)
const int end = 1023;       // adjust value to reduce distance you need to pull handbrake for full activation (default 1023)

// disables unnecessary joystick library features
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, JOYSTICK_TYPE_GAMEPAD,
  0, 0,                       // buttons, hats
  true, false, false,        // X,Y,Z
  false, false, false,        // Rx,Ry,Rz
  false, false,  false,  false // Rudder, Throttle, Accelerator, Steering
);

void setup() {
  Joystick.setXAxisRange(0, end); 
  Joystick.begin(false);
}

void loop() {
  int raw = analogRead(POT_PIN);
  if (INVERT) raw = start - raw; 
    else raw -= (1023 - start);
  Joystick.setXAxis(raw);
  Joystick.sendState();
  delay(2);
}
