#include <WS2812FX.h>

/* Pinout Definition */
#define LED_PIN 10

/*LED*/
#define LED_COUNT 12
#define AI_I2
WS2812FX ws2812fx = WS2812FX(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  ws2812fx.init();
  ws2812fx.setBrightness(1);
  ws2812fx.setSpeed(200);
  ws2812fx.setMode(FX_MODE_STATIC);
  ws2812fx.setPixelColor(1,0xFF,0xFF,0);
  ws2812fx.start();
}

void loop() {
  // put your main code here, to run repeatedly:
  ws2812fx.service();
}
