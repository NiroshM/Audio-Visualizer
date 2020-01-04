#include "FastLED.h"
#define NUM_LEDS 150
#define LED_PIN 5
#define SENSOR_PIN 0
#define LED_TYPE NEOPIXEL


// This initializes our led array
CRGBArray<NUM_LEDS> leds;

void setup() {
  // put your setup code here, to run once:
  delay( 1000 );
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  FastLED.addLeds<LED_TYPE, LED_PIN>(leds, NUM_LEDS);
}

void loop() {  
  // put your main code here, to run repeatedly:
  int16_t reading = analogRead(SENSOR_PIN);
  //float voltage = reading * (5.0 / 1023);       Converts the sound sensor reading into the actual voltage read by the arduino (not necessary)
  const float threshold = 300;

/* Below is for turning the leds turn on and off depending on if the music surpassed a certain audio threshold */

//  if(reading > threshold) {
//    leds(0, NUM_LEDS) = CRGB::Red;
//    FastLED.delay(1);
//  } 
//  else {
//    leds(0, NUM_LEDS) = CRGB::Black;
//    int read_to_bright = map(reading, 300, 400, 0, 255);
//    leds(0, NUM_LEDS) = CHSV(160, 255, read_to_bright);
//    FastLED.delay(1);
//  }

/* Below is for making the leds change brightness according to the beat */

  if(reading > 300 && reading < 390) {
    leds(0, NUM_LEDS) = CHSV(180, 255, 10);
    FastLED.delay(1);
  } else if (reading > 390 && reading < 450) {
    leds(0, NUM_LEDS) = CHSV(180, 255, 80);
    FastLED.delay(1);
  } else if (reading > 450) {
    leds(0, NUM_LEDS) = CHSV(180, 255, 255);
    FastLED.delay(1);
  }

//  int read_to_bright = map(reading, 300, 400, 0, 255);
//  leds(0, NUM_LEDS) = CHSV(160, 255, read_to_bright);
//  FastLED.delay(1);


/* Below is for making leds strips move up and down according to the beat, changing colours constantly*/

//  int lights_on = map(reading, 300, 450, 0, 150);
//
//  for(int hue = 0; hue < 255; hue++) {
//    leds(0, lights_on) = CHSV(hue, 255, 255);
//    FastLED.delay(1);
//    leds(lights_on, 150) = CRGB::Black;
//    FastLED.delay(1);
//  }

/* This prints out the voltage reading from the sound sensor */
  
  Serial.println(reading);
}
