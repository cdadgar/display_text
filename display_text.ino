/*
 * library sources:
 * Adafruit_GFX.h - https://github.com/adafruit/Adafruit-GFX-Library (git)
 * Adafruit_ILI9341.h - https://github.com/adafruit/Adafruit_ILI9341
 * TFT_ILI9163C.h - https://github.com/PaulStoffregen/TFT_ILI9163C
 * Adafruit_ST7735.h - https://github.com/adafruit/Adafruit-ST7735-Library
 * XPT2046_Touchscreen.h - https://github.com/PaulStoffregen/XPT2046_Touchscreen
 * 
 * see https://learn.adafruit.com/adafruit-gfx-graphics-library/using-fonts
 * 
 * 
 * what fonts does the thermostat project use?
 * font_arial_8
 * font_arial_16
 * font_arial_24

 * custom fonts:
 * Adafruit_GFX comes with fontconvert in source code
 * get a windows executable from: https://drive.google.com/file/d/1M12mM9rOhCYabiJZKsfMk_Zu_kY1YVlw/view
 * get true type fronts from: https://www.fontdload.com/dl/arial-font/
 * in the zip file, there is another zip called arial_mt.zip
 * in that zip, I used AIR.ttf (renamed to arial.ttf)
 * make the font files with:
 * fontconvert arial.ttf 8 >  alial8pt7b.h
 * fontconvert arial.ttf 16 >  alial16pt7b.h
 * fontconvert arial.ttf 24 >  alial24pt7b.h
 * copy the generated .h files to C:\Users\java_\Desktop\Arduino\libraries\Adafruit_GFX_Library\Fonts
 * to use them, include the fonts file, and call set font.
 */

/*
 * wemos d1 r1 setup
 * 
 * the display comes in 2.2" and 2.8"
 * they both have pins for a sd card
 * Q: how to test the sd card?
 * 
 * the larger display may have a touchscreen added onto it.
 * (see the display_XPT2046_touchscreen project to test it)
 * 
 * RST is optional
 * MISO is optional (since we're only writing to the display)
 * 
 * the LED should be driven by a transistor
 * VCC and all logic levels are 3.3V
 * 
 * this runs pretty slowly....maybe there is a faster library?
 * 
 * todo:  test this with the other tft displays
 */
#define TFT_CS   15
#define TFT_DC    0
#define TFT_MOSI 13
#define TFT_CLK  14
#define TFT_RST  -1
#define TFT_MISO 12

#define T_IRQ     5
#define T_DO     12
#define T_DIN    13
#define T_CS      4
#define T_CLK    14


#include <Adafruit_GFX.h>
#include "Adafruit_ILI9341.h"

//#include <Fonts/FreeMonoBoldOblique12pt7b.h>
//#include <Fonts/FreeMonoBoldOblique18pt7b.h>
//#include <Fonts/FreeMonoBoldOblique24pt7b.h>

#include <Fonts/alial8pt7b.h>
#include <Fonts/alial16pt7b.h>
#include <Fonts/alial24pt7b.h>



Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);


void setup(void) {
  Serial.begin(115200);
  Serial.println("\n\n\nILI9341 Test\n\n"); 
 
  tft.begin();
  tft.fillScreen(ILI9341_BLACK);

  const char *string = "Hello";

  tft.setTextColor(ILI9341_GREEN);
  tft.setTextSize(1);

  uint16_t height = 0;

  int16_t x1, y1;
  uint16_t w, h;

  tft.setFont(&arial8pt7b);
//  tft.setFont(&FreeMonoBoldOblique12pt7b);
  tft.getTextBounds(string, 0, 0, &x1, &y1, &w, &h);
  height += h + 2;
  Serial.printf("8pt: Width %d, Height %d\n", w, h); 
  tft.setCursor(0, height);
  tft.println(string);

  tft.setFont(&arial16pt7b);
//  tft.setFont(&FreeMonoBoldOblique18pt7b);
  tft.getTextBounds(string, 0, 0, &x1, &y1, &w, &h);
  height += h + 2;
  Serial.printf("16pt: Width %d, Height %d\n", w, h); 
  tft.setCursor(0, height);
  tft.println(string);

  tft.setFont(&arial24pt7b);
//  tft.setFont(&FreeMonoBoldOblique24pt7b);
  tft.getTextBounds(string, 0, 0, &x1, &y1, &w, &h);
  height += h + 2;
  Serial.printf("24pt: Width %d, Height %d\n", w, h); 
  tft.setCursor(0, height);
  tft.println(string);
}


void loop(void) {
}
