/*pixel LED control with Arduino nano.
  Read the code below and use it for any of your creation
*/
#include <FastLED.h>//include library---library link in my blog
#define NUM_LEDS 2//num of leds
#define DATAPIN 3//define arduino pin
#define chip WS2811 //chip name
#define colorArrange RGB//color
CRGB pixels [NUM_LEDS];//create array

void setup() {
  FastLED.addLeds<chip, DATAPIN, colorArrange>(pixels, NUM_LEDS);//initializing pixel led

}
void loop() {

  // De 0 a 255 en azul
  for(int i = 0; i <= 255; ++i){
    
    pixels[0] = CRGB(0, 0, i);
    pixels[1] = CRGB(0, i, 10);
    delay(5);
    FastLED.show();

  }
  // De 0 a 255 en verde
  for(int i = 0; i <= 255; ++i){
    pixels[0] = CRGB(0, i, 0);
    pixels[1] = CRGB(i, 0, 0);
    delay(5);
    FastLED.show();
  }
  // De 0 a 255 en rojo
  for(int i = 0; i <= 255; ++i){
    pixels[0] = CRGB(i, 0, 0);
    pixels[1] = CRGB(0, 0, i);
    delay(5);
    FastLED.show();
  }

}