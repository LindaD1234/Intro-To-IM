#include <Adafruit_NeoPixel.h> //lib

// NeoPixel setup
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5

#define NUM_PIXELS_2 46
#define NUM_PIXELS_3 31
#define NUM_PIXELS_4 32
#define NUM_PIXELS_5 27

//creates the object for controlling a NeoPixel strip
Adafruit_NeoPixel strip2(NUM_PIXELS_2, PIN_2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip3(NUM_PIXELS_3, PIN_3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip4(NUM_PIXELS_4, PIN_4, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip5(NUM_PIXELS_5, PIN_5, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);

  strip2.begin();
  strip3.begin();
  strip4.begin();
  strip5.begin();

  strip2.show(); // Initialize all pixels to "off"
  strip3.show();
  strip4.show();
  strip5.show();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // read incoming serial data
    handleSerialInput(input);
  }
}

// handle serial input of the format "pin:brightness"
void handleSerialInput(String input) {
  int delimiterIndex = input.indexOf(':');
  if (delimiterIndex > 0) {
    int pin = input.substring(0, delimiterIndex).toInt(); // extracts the part before the colon
    int brightness = input.substring(delimiterIndex + 1).toInt(); //extracts the part after the colon
    setBrightness(pin, brightness);
  }
}

// set brightness for a specific pin
void setBrightness(int pin, int brightness) {
  Adafruit_NeoPixel* strip;

  // assign the correct strip based on the pin
  switch (pin) {
    case 2: strip = &strip2; break;
    case 3: strip = &strip3; break;
    case 4: strip = &strip4; break;
    case 5: strip = &strip5; break;
    default: return; // Ignore invalid pin numbers
  }

  // Update brightness for all LEDs in the strip
  for (int i = 0; i < strip->numPixels(); i++) {
    strip->setPixelColor(i, strip->Color(brightness, 0, 0)); // Set to red with adjusted brightness
  }
  strip->show(); // Update the strip
}
