const uint8_t arial18pt8bBitmaps[] PROGMEM = {
  0x1E, 0x1F, 0xC6, 0x1B, 0x03, 0xC0, 0xF0, 0x36, 0x19, 0xFC, 0x1E, 0x00 };

const GFXglyph arial18pt8bGlyphs[] PROGMEM = {
  {     0,  10,   9,  14,    2,  -24 } }; // 0xB0

const GFXfont arial18pt8b PROGMEM = {
  (uint8_t  *)arial18pt8bBitmaps,
  (GFXglyph *)arial18pt8bGlyphs,
  0xB0, 0xB0, 40 };

// Approx. 26 bytes
