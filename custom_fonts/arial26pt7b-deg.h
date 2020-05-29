const uint8_t arial26pt8bBitmaps[] PROGMEM = {
  0x0F, 0xC0, 0x7F, 0x83, 0xFF, 0x1E, 0x1E, 0x70, 0x3F, 0x80, 0x7E, 0x01,
  0xF8, 0x07, 0xE0, 0x1D, 0xC0, 0xF7, 0x87, 0x8F, 0xFC, 0x1F, 0xE0, 0x3F,
  0x00 };

const GFXglyph arial26pt8bGlyphs[] PROGMEM = {
  {     0,  14,  14,  20,    3,  -36 } }; // 0xB0

const GFXfont arial26pt8b PROGMEM = {
  (uint8_t  *)arial26pt8bBitmaps,
  (GFXglyph *)arial26pt8bGlyphs,
  0xB0, 0xB0, 59 };

// Approx. 39 bytes
