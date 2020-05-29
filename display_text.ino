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
 * fontconvert arial.ttf 8 > arial8pt7b.h
 * fontconvert arial.ttf 16 > arial16pt7b.h
 * fontconvert arial.ttf 24 46 57 > arial24pt7b.h    (46 is ascii for . to 57 is ascii for 9) missing degree symbol
 * fontconvert arial.ttf 24 176 176 > arial24pt7b-deg.h      (degree symbol by itself)
 * copy the generated .h files to C:\Users\java_\Desktop\Arduino\libraries\Adafruit_GFX_Library\Fonts
 * to use them, include the fonts file, and call set font.
 * the deg file data was added to the 24 pt font file.  (character after 9 will be the degree symbol)
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
#define __CS   15
#define __DC    5
//#define TFT_MOSI 13
//#define TFT_CLK  14
//#define TFT_RST  -1
//#define TFT_MISO 12

//#define T_IRQ     5
//#define T_DO     12
//#define T_DIN    13
//#define T_CS      4
//#define T_CLK    14


#include <Adafruit_GFX.h>


// pick the font to use
#define ARIAL
//#define SEGOE_UI


// pick the display type
//#define DISPLAY_14
#define DISPLAY_18
//#define DISPLAY_22
//#define DISPLAY_28




#ifdef ARIAL
#include <Fonts/arial8pt7b.h>    // 12
#include <Fonts/arial12pt7b.h>   // 17
#include <Fonts/arial14pt7b.h>   // 20
#include <Fonts/arial18pt7b.h>   // 25
#include <Fonts/arial19pt7b.h>   // 27
//#include <Fonts/arial20pt7b.h>   // 28
//#include <Fonts/arial24pt7b.h>   // 34
#include <Fonts/arial26pt7b.h>   // 37
#include <Fonts/arial28pt7b.h>   // 39
#include <Fonts/arial30pt7b.h>   // 41
#endif

#ifdef SEGOE_UI
#include <Fonts/segoe-ui8pt7b.h>
#include <Fonts/segoe-ui12pt7b.h>
#include <Fonts/segoe-ui14pt7b.h>
#include <Fonts/segoe-ui20pt7b.h>
#include <Fonts/segoe-ui24pt7b.h>
#endif


#ifdef DISPLAY_14
#include <TFT_ILI9163C.h>
#define GREEN 0x07E0
#define RED   0xF800
TFT_ILI9163C tft = TFT_ILI9163C(__CS, __DC);
#endif
#ifdef DISPLAY_18
#include <Adafruit_ST7735.h>
#define BLACK ST7735_BLACK
#define GREEN ST7735_GREEN
#define RED   ST7735_RED
Adafruit_ST7735 tft = Adafruit_ST7735(__CS, __DC, -1);
#endif
#ifdef DISPLAY_22
#include <Adafruit_ILI9341.h>
#define BLACK ILI9341_BLACK
#define GREEN ILI9341_GREEN
#define RED   ILI9341_REDAdafruit_ILI9341 display = Adafruit_ILI9341(__CS, __DC, -1);
Adafruit_ILI9341 tft = Adafruit_ILI9341(__CS, __DC, -1);
// softare spi
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);
#endif
#ifdef DISPLAY_28
#include <Adafruit_ILI9341.h>
#define BLACK ILI9341_BLACK
#define GREEN ILI9341_GREEN
#define RED   ILI9341_REDAdafruit_ILI9341 display = Adafruit_ILI9341(__CS, __DC);
Adafruit_ILI9341 tft = Adafruit_ILI9341(__CS, __DC, -1);
#endif



void setup(void) {
  Serial.begin(115200);
  Serial.println(F("\n\n\nDisplay Test\n\n")); 

#ifdef DISPLAY_14
  Serial.println(F("1.4\" tft display"));
  tft.begin();
  tft.setBitrate(16000000);
#endif
#ifdef DISPLAY_18
  Serial.println(F("1.8\" tft display"));
  tft.initR(INITR_BLACKTAB);
#endif
#ifdef DISPLAY_22
  Serial.println(F("2.2\" tft display"));
  tft.begin();
#endif
#ifdef DISPLAY_28
  Serial.println(F("2.8\" tft display"));
  tft.begin();
#endif

  tft.fillScreen(BLACK);

  const char *string = "123";

  tft.setTextColor(GREEN);
  tft.setTextSize(1);

  uint16_t height = 0;
  int16_t x1, y1;
  uint16_t w, h;


  int numFonts = 6;
  const GFXfont *f[6];
  int fs[6];

  // unlike custom fonts, the defualt font prints below the cursor y coordinate
  // and they don't need extra space (2 px)
  // custom fonts print above
  f[0] = NULL;
  fs[0] = 5;
  fs[1] = 8;
  fs[2] = 12;
  fs[3] = 14;
  fs[4] = 20;
  fs[5] = 24;

#ifdef ARIAL
  Serial.println(F("arial font"));
  f[1] = &arial8pt7b;
  f[2] = &arial12pt7b;
  f[3] = &arial14pt7b;
  f[4] = &arial28pt7b;
  f[5] = &arial30pt7b;
//  f[4] = &arial20pt7b;
//  f[5] = &arial24pt7b;
#endif
#ifdef SEGOE_UI
  Serial.println(F("segoe ui font"));
  f[1] = &segoe_ui8pt7b;
  f[2] = &segoe_ui12pt7b;
  f[3] = &segoe_ui14pt7b;
  f[4] = &segoe_ui20pt7b;
  f[5] = &segoe_ui24pt7b;
#endif


  for (int i = 0; i < numFonts; ++i) {
    // set the font
    tft.setFont(f[i]);

    // get the size of the string we're going to draw
    // (so we know how to erase it
    tft.getTextBounds(string, 0, height, &x1, &y1, &w, &h);

    // erase the area occupied by the string
    if (f[i] != NULL)
      tft.fillRect(x1, y1+h, w, h, RED);  // custom font, fill below cursor y
    else
      tft.fillRect(x1, y1, w, h, RED);    // default font, fill above cursor y
      
    if (f[i] != NULL)
      height += h;  // custom font prints below cursor y
    Serial.printf("%d pt: %d, %d: Width %d, Height %d\n", fs[i], x1, y1, w, h);

    // draw the text
    tft.setCursor(0, height);
    tft.print(string);
    
    if (f[i] != NULL)
      height += 2;      // gap between lines    
    else
      height += h + 2;  // default font prints above cursor y
  }
}


void loop(void) {
}
