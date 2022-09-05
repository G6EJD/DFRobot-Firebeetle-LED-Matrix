#include "DFRobot_HT1632C.h"
#include <Adafruit_NeoPixel.h>

// Firebeetle USB long edge
#define DATA 13
#define CS   25
#define WR   2
#define RD   21

DFRobot_HT1632C   ht1632c = DFRobot_HT1632C(DATA, WR, CS);
Adafruit_NeoPixel pixels(NumPixels, PixelPin, NEO_GRB + NEO_KHZ800);

char display_text[] = "Hello";

void setup() {
  Serial.begin(115200);
  delay(200);
  pixels.begin(); // INITIALIZE NeoPixel object (REQUIRED)
  delay(200);
  ht1632c.begin();
  ht1632c.isLedOn(true);
  ht1632c.clearScreen();
  ht1632c.setPwm(15); // Pwm range = 0 - 15 brightness
}

void loop() {
  ht1632c.print(display_text, 30);
  delay(5000); // wait 5-secs
}
