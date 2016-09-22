/*
 * This is a minimal example, see extra-examples.cpp for a version
 * with more explantory documentation, example routines, how to
 * hook up your pixels and all of the pixel types that are supported.
 *
 */

#include "application.h"
//#include "neopixel/neopixel.h" // use for Build IDE
#include "neopixel.h" // use for local build

SYSTEM_MODE(AUTOMATIC);

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D4
#define PIXEL_COUNT 60
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

// Prototypes for local build, ok to leave in for Build IDE
void rainbow(uint8_t wait);
uint32_t Wheel(byte WheelPos);

void setup()
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
    Particle.function("state", setLightState);
  //Particle.function("color", setLightColor);
  //Particle.function("brightness", setLightBrightness);
}
//void loop()
//{
  //rainbow(200);
//}
int setLightState(String state) {
  Serial.println("state: " + state);

  if(state == "on") {
    rainbow(50);
    return 1;
  }
}
void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<255; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      //strip.setPixelColor(i, Wheel((i+j) & 255));
      strip.setPixelColor(i, strip.Color(j*255/255,j*100/255,j*0/255));
     //strip.setPixelColor(i-1, strip.Color(255,165,0));
    }
    strip.show();
    delay(wait);
  }
      for(i=0; i<60; i++) {
        strip.setPixelColor(i, strip.Color(255,255,255));
        strip.show();
         delay(wait);
        strip.setPixelColor(i, strip.Color(255,255,255));
        strip.show();
         delay(wait);
    }
          for(j=0; j<60; j++) {
          for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(0,0,0));
            //delay(20);
          }
        strip.show();
        delay(20);
        for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(250,250,250));
            //delay(20);
          }
     strip.show();
        delay(20);
          }
    for(j=0; j<60; j++) {
          for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(0,0,0));
            //delay(20);
          }
        strip.show();
        delay(20);
        for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(250,0,0));
            //delay(20);
          }
     strip.show();
        delay(20);
          }
              for(j=0; j<60; j++) {
          for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(0,0,0));
            //delay(20);
          }
        strip.show();
        delay(20);
        for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(0,255,0));
            //delay(20);
          }
     strip.show();
        delay(20);
          }
         for(j=0; j<60; j++) {
          for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(0,0,0));
            //delay(20);
          }
        strip.show();
        delay(20);
        for(i=0; i<60; i++) {

             strip.setPixelColor(i, strip.Color(0,0,255));
            //delay(20);
          }
     strip.show();
        delay(20);
          }
        for(i=0; i<61; i++) {

             strip.setPixelColor(i, strip.Color(0,0,0));
            //delay(20);
          }
     strip.show();

}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
