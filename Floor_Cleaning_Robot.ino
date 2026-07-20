#include <LedControl.h>

// DIN, CLK, CS, number of devices
LedControl lc = LedControl(12, 11, 10, 1);

void setup() {
  lc.shutdown(0, false);   // Wake up MAX7219
  lc.setIntensity(0, 8);   // Brightness (0-15)
  lc.clearDisplay(0);      // Clear display
}

void loop() {
  // Turn on every LED one by one
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, true);
      delay(50);
    }
  }

  delay(1000);

  // Turn off every LED one by one
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, false);
      delay(50);
    }
  }

  delay(1000);
}
