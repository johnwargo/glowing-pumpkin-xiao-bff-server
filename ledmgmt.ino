/*********************************************************
* LED Management
* This is the code that controls what displays on the 
* LED array.
*/

bool doRandom = false;

void enableRandom() {
  doRandom = true;
}

void disableRandom() {
  doRandom = false;
}

void flashLEDs(CRGB color, int count, int duration) {
  // Calculate this only once, no reason to calculate this in the loop
  int offDuration = duration / 2;

  for (int i = 0; i < count; i++) {
    fill_solid(leds, NUM_LEDS, CRGB::Red);
    FastLED.show();
    delay(duration);
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(offDuration);
  }
}

void flicker() {
  // how many times are we going to flash?
  int flashCount = (int)random(1, 6);
  //flash the lights in white flashCount times
  //with a random duration and random delay between each flash
  for (int i = 0; i < flashCount; i++) {
    // Set all pixels to white and turn them on
    fill_solid(leds, NUM_LEDS, CRGB::White);
    FastLED.show();
    // Delay for a random period of time (in milliseconds)
    delay((int)random(50, 150));
    //clear the lights (set the color to none)
    fill_solid(leds, NUM_LEDS, CRGB::Black);
    FastLED.show();
    // Delay for a random period of time (in milliseconds)
    delay((int)random(100, 500));
  }
}

// Fill the NeoPixel array with a specific color
void fadeColor(CRGB c) {
  for (int i = 0; i < 25; i++) {
    leds[i] = c;
    FastLED.show();
    delay(10);
  }
  delay((int)random(250, 2000));
}
