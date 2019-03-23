
#include "phidgets.h"


VALUE ph_lcd_initialize(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetLCD_create((PhidgetLCDHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_lcd_get_backlight(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLCD_getBacklight);
}

VALUE ph_lcd_set_backlight(VALUE self, VALUE backlight) {
  ph_raise(PhidgetLCD_setBacklight((PhidgetLCDHandle)get_ph_handle(self), NUM2DBL(backlight)));
  return Qnil;
}

VALUE ph_lcd_get_min_backlight(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLCD_getMinBacklight);
}

VALUE ph_lcd_get_max_backlight(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLCD_getMaxBacklight);
}

VALUE ph_lcd_set_character_bitmap(VALUE self, VALUE font, VALUE character, VALUE bitmap) {
  int i, bitmap_len = RARRAY_LEN(bitmap);
  uint8_t *bm = malloc(bitmap_len);
  for(i=0; i<bitmap_len; i++) { bm[i] = (uint8_t)NUM2CHR(rb_ary_entry(bitmap, i)); }
  ph_raise(PhidgetLCD_setCharacterBitmap((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(font), StringValueCStr(character), bm));
  free(bm);
  return Qnil;
}

VALUE ph_lcd_get_max_characters(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetLCD_getMaxCharacters);
}

VALUE ph_lcd_clear(VALUE self) {
  ph_raise(PhidgetLCD_clear((PhidgetLCDHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_lcd_get_contrast(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLCD_getContrast);
}

VALUE ph_lcd_set_contrast(VALUE self, VALUE contrast) {
  ph_raise(PhidgetLCD_setContrast((PhidgetLCDHandle)get_ph_handle(self), NUM2DBL(contrast)));
  return Qnil;
}

VALUE ph_lcd_get_min_contrast(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLCD_getMinContrast);
}

VALUE ph_lcd_get_max_contrast(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLCD_getMaxContrast);
}

VALUE ph_lcd_copy(VALUE self, VALUE src_fb, VALUE dest_fb, VALUE src_x1, VALUE src_y1, VALUE src_x2, VALUE src_y2, VALUE dest_x, VALUE dest_y, VALUE invert) {
  ph_raise(PhidgetLCD_copy((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(src_fb), NUM2INT(dest_fb), NUM2INT(src_x1), NUM2INT(src_y1), NUM2INT(src_x2), NUM2INT(src_y2), NUM2INT(dest_x), NUM2INT(dest_y), TYPE(invert) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_lcd_get_cursor_blink(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetLCD_getCursorBlink);
}

VALUE ph_lcd_set_cursor_blink(VALUE self, VALUE cursor_blink) {
  ph_raise(PhidgetLCD_setCursorBlink((PhidgetLCDHandle)get_ph_handle(self), TYPE(cursor_blink) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_lcd_get_cursor_on(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetLCD_getCursorOn);
}

VALUE ph_lcd_set_cursor_on(VALUE self, VALUE cursor_on) {
  ph_raise(PhidgetLCD_setCursorOn((PhidgetLCDHandle)get_ph_handle(self), TYPE(cursor_on) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_lcd_draw_line(VALUE self, VALUE x1, VALUE y1, VALUE x2, VALUE y2) {
  ph_raise(PhidgetLCD_drawLine((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(x1), NUM2INT(y1), NUM2INT(x2), NUM2INT(y2)));
  return Qnil;
}

VALUE ph_lcd_draw_pixel(VALUE self, VALUE x, VALUE y, VALUE pixel_state) {
  ph_raise(PhidgetLCD_drawPixel((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(x), NUM2INT(y), NUM2INT(pixel_state)));
  return Qnil;
}

VALUE ph_lcd_draw_rect(VALUE self, VALUE x1, VALUE y1, VALUE x2, VALUE y2, VALUE filled, VALUE invert) {
  ph_raise(PhidgetLCD_drawRect((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(x1), NUM2INT(y1), NUM2INT(x2), NUM2INT(y2), TYPE(filled) == T_TRUE ? PTRUE : PFALSE, TYPE(invert) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_lcd_flush(VALUE self) {
  ph_raise(PhidgetLCD_flush((PhidgetLCDHandle)get_ph_handle(self)));
  return Qnil;
}


VALUE ph_lcd_get_font_size(VALUE self, VALUE font) {
  PhidgetLCDHandle handle = (PhidgetLCDHandle)get_ph_handle(self);
  int width, height;
  VALUE rb_font_size = rb_hash_new();

  ph_raise(PhidgetLCD_getFontSize(handle, NUM2INT(font), &width, &height));
  rb_hash_aset(rb_font_size, rb_str_new2("width"), INT2NUM(width));
  rb_hash_aset(rb_font_size, rb_str_new2("height"), INT2NUM(height));
  return rb_font_size;
}

VALUE ph_lcd_set_font_size(VALUE self, VALUE font, VALUE width, VALUE height) {
  ph_raise(PhidgetLCD_setFontSize((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(font), NUM2INT(width), NUM2INT(height)));
  return Qnil;
}

VALUE ph_lcd_get_frame_buffer(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetLCD_getFrameBuffer);
}

VALUE ph_lcd_set_frame_buffer(VALUE self, VALUE frame_buffer) {
  ph_raise(PhidgetLCD_setFrameBuffer((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(frame_buffer)));
  return Qnil;
}

VALUE ph_lcd_get_height(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetLCD_getHeight);
}

VALUE ph_lcd_init(VALUE self) {
  ph_raise(PhidgetLCD_initialize((PhidgetLCDHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_lcd_save_frame_buffer(VALUE self, VALUE frame_buffer) {
  ph_raise(PhidgetLCD_saveFrameBuffer((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(frame_buffer)));
  return Qnil;
}

VALUE ph_lcd_get_screen_size(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetLCD_getScreenSize);
}

VALUE ph_lcd_set_screen_size(VALUE self, VALUE screen_size) {
  ph_raise(PhidgetLCD_setScreenSize((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(screen_size)));
  return Qnil;
}

VALUE ph_lcd_get_sleeping(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetLCD_getSleeping);
}

VALUE ph_lcd_set_sleeping(VALUE self, VALUE sleeping) {
  ph_raise(PhidgetLCD_setSleeping((PhidgetLCDHandle)get_ph_handle(self), TYPE(sleeping) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_lcd_get_width(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetLCD_getWidth);
}

VALUE ph_lcd_write_bitmap(VALUE self, VALUE x_pos, VALUE y_pos, VALUE x_size, VALUE y_size, VALUE bitmap) {
  int i, bitmap_len = RARRAY_LEN(bitmap);
  uint8_t *bm = malloc(bitmap_len);
  for(i=0; i<bitmap_len; i++) { bm[i] = (uint8_t)NUM2CHR(rb_ary_entry(bitmap, i)); }
  ph_raise(PhidgetLCD_writeBitmap((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(x_pos), NUM2INT(y_pos), NUM2INT(x_size), NUM2INT(y_size), bm));
  free(bm);
  return Qnil;
}

VALUE ph_lcd_write_text(VALUE self, VALUE font, VALUE x_pos, VALUE y_pos, VALUE text) {
  ph_raise(PhidgetLCD_writeText((PhidgetLCDHandle)get_ph_handle(self), NUM2INT(font), NUM2INT(x_pos), NUM2INT(y_pos), StringValueCStr(text)));
  return Qnil;
}


void Init_lcd() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_lcd = rb_define_class_under(ph_module, "LCD", ph_common);


  rb_define_const(ph_lcd, "FONT_User1", INT2NUM(FONT_User1));
  rb_define_const(ph_lcd, "FONT_User2", INT2NUM(FONT_User2));
  rb_define_const(ph_lcd, "FONT_6x10", INT2NUM(FONT_6x10));
  rb_define_const(ph_lcd, "FONT_5x8", INT2NUM(FONT_5x8));
  rb_define_const(ph_lcd, "FONT_6x12", INT2NUM(FONT_6x12));

  rb_define_const(ph_lcd, "SCREEN_SIZE_NONE", INT2NUM(SCREEN_SIZE_NONE));
  rb_define_const(ph_lcd, "SCREEN_SIZE_1x8", INT2NUM(SCREEN_SIZE_1x8));
  rb_define_const(ph_lcd, "SCREEN_SIZE_2x8", INT2NUM(SCREEN_SIZE_2x8));
  rb_define_const(ph_lcd, "SCREEN_SIZE_1x16", INT2NUM(SCREEN_SIZE_1x16));
  rb_define_const(ph_lcd, "SCREEN_SIZE_2x16", INT2NUM(SCREEN_SIZE_2x16));
  rb_define_const(ph_lcd, "SCREEN_SIZE_4x16", INT2NUM(SCREEN_SIZE_4x16));
  rb_define_const(ph_lcd, "SCREEN_SIZE_2x20", INT2NUM(SCREEN_SIZE_2x20));
  rb_define_const(ph_lcd, "SCREEN_SIZE_4x20", INT2NUM(SCREEN_SIZE_4x20));
  rb_define_const(ph_lcd, "SCREEN_SIZE_2x24", INT2NUM(SCREEN_SIZE_2x24));
  rb_define_const(ph_lcd, "SCREEN_SIZE_1x40", INT2NUM(SCREEN_SIZE_1x40));
  rb_define_const(ph_lcd, "SCREEN_SIZE_2x40", INT2NUM(SCREEN_SIZE_2x40));
  rb_define_const(ph_lcd, "SCREEN_SIZE_4x40", INT2NUM(SCREEN_SIZE_4x40));
  rb_define_const(ph_lcd, "SCREEN_SIZE_64x128", INT2NUM(SCREEN_SIZE_64x128));

  rb_define_const(ph_lcd, "PIXEL_STATE_OFF", INT2NUM(PIXEL_STATE_OFF));
  rb_define_const(ph_lcd, "PIXEL_STATE_ON", INT2NUM(PIXEL_STATE_ON));
  rb_define_const(ph_lcd, "PIXEL_STATE_INVERT", INT2NUM(PIXEL_STATE_INVERT));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget LCD object.
   */
  rb_define_method(ph_lcd, "initialize", ph_lcd_init, 0);

  /* Document-method: getBacklight
   * call-seq: getBacklight -> backlight
   *
   * The Backlight affects the brightness of the LCD screen.
   * Backlight is bounded by MinBackLight and MaxBacklight.
   */
  rb_define_method(ph_lcd, "getBacklight", ph_lcd_get_backlight, 0);
  rb_define_alias(ph_lcd, "backlight", "getBacklight");

  /* Document-method: setBacklight
   * call-seq: setBacklight(backlight)
   *
   * The Backlight affects the brightness of the LCD screen.
   * Backlight is bounded by MinBackLight and MaxBacklight.
   */
  rb_define_method(ph_lcd, "setBacklight", ph_lcd_set_backlight, 1);
  rb_define_alias(ph_lcd, "backlight=", "setBacklight");

  /* Document-method: getMinBacklight
   * call-seq: getMinBacklight -> backlight
   *
   * The minimum value that Backlight can be set to.
   */
  rb_define_method(ph_lcd, "getMinBacklight", ph_lcd_get_min_backlight, 0);
  rb_define_alias(ph_lcd, "min_backlight", "getMinBacklight");

  /* Document-method: getMaxBacklight
   * call-seq: getMaxBacklight -> backlight
   *
   * The maximum value that Backlight can be set to.
   */
  rb_define_method(ph_lcd, "getMaxBacklight", ph_lcd_get_max_backlight, 0);
  rb_define_alias(ph_lcd, "max_backlight", "getMaxBacklight");

  /* Document-method: setCharacterBitmap
   * call-seq: setCharacterBitmap(font, character, bitmap)
   *
   * Create a bitmap and select a character to represent it. Now, when you use the specific character, the bitmap will show in it's place.
   */
  rb_define_method(ph_lcd, "setCharacterBitmap", ph_lcd_set_character_bitmap, 3);
  rb_define_alias(ph_lcd, "set_character_bitmap", "setCharacterBitmap");

  /* Document-method: getMaxCharacters
   * call-seq: getMaxCharacters -> max_characters
   *
   * The maximum number of characters that can fit on the frame buffer for the specified font.
   */
  rb_define_method(ph_lcd, "getMaxCharacters", ph_lcd_get_max_characters, 0);
  rb_define_alias(ph_lcd, "get_max_characters", "getMaxCharacters");

  /* Document-method: clear
   * call-seq: clear
   *
   * Clears all pixels in the current frame buffer.
   * Changes made to the frame buffer must be flushed to the LCD screen using flush.
   */
  rb_define_method(ph_lcd, "clear", ph_lcd_clear, 0);

  /* Document-method: getContrast
   * call-seq: getContrast -> contrast
   *
   * Contrast level of the text or graphic pixels.
   * A higher contrast will make the image darker.
   * Contrast is bounded by MinContrast and MaxContrast.
   */
  rb_define_method(ph_lcd, "getContrast", ph_lcd_get_contrast, 0);
  rb_define_alias(ph_lcd, "contrast", "getContrast");

  /* Document-method: setContrast
   * call-seq: setContrast(contrast)
   *
   * Contrast level of the text or graphic pixels.
   * A higher contrast will make the image darker.
   * Contrast is bounded by MinContrast and MaxContrast.
   */
  rb_define_method(ph_lcd, "setContrast", ph_lcd_set_contrast, 1);
  rb_define_alias(ph_lcd, "contrast=", "setContrast");

  /* Document-method: getMinContrast
   * call-seq: getMinContrast -> contrast
   *
   * The minimum value that Contrast can be set to.
   */
  rb_define_method(ph_lcd, "getMinContrast", ph_lcd_get_min_contrast, 0);
  rb_define_alias(ph_lcd, "min_contrast", "getMinContrast");

  /* Document-method: getMaxContrast
   * call-seq: getMaxContrast -> contrast
   *
   * The maximum value that Contrast can be set to.
   */
  rb_define_method(ph_lcd, "getMaxContrast", ph_lcd_get_max_contrast, 0);
  rb_define_alias(ph_lcd, "max_contrast", "getMaxContrast");

  /* Document-method: copy
   * call-seq: copy(src_framebuffer, dest_framebuffer, src_x1, src_y1, src_x2, src_y2, dest_x, dest_y, inverted)
   *
   * Copies all pixels from a specified rectangular region to another.
   */
  rb_define_method(ph_lcd, "copy", ph_lcd_copy, 9);

  /* Document-method: getCursorBlink
   * call-seq: getCursorBlink -> cursor_blink
   *
   * When CursorBlink is true, the device will cause the cursor to periodically blink.
   */
  rb_define_method(ph_lcd, "getCursorBlink", ph_lcd_get_cursor_blink, 0);
  rb_define_alias(ph_lcd, "cursor_blink", "getCursorBlink");

  /* Document-method: setCursorBlink
   * call-seq: setCursorBlink(cursor_blink)
   *
   * When CursorBlink is true, the device will cause the cursor to periodically blink.
   */
  rb_define_method(ph_lcd, "setCursorBlink", ph_lcd_set_cursor_blink, 1);
  rb_define_alias(ph_lcd, "cursor_blink=", "setCursorBlink");

  /* Document-method: getCursorOn
   * call-seq: getCursorOn -> cursor_on
   *
   * When CursorOn is true, the device will underline to the cursor position.
   */
  rb_define_method(ph_lcd, "getCursorOn", ph_lcd_get_cursor_on, 0);
  rb_define_alias(ph_lcd, "cursor_on", "getCursorOn");

  /* Document-method: setCursorOn
   * call-seq: setCursorOn(cursor_on)
   *
   * When CursorOn is true, the device will underline to the cursor position.
   */
  rb_define_method(ph_lcd, "setCursorOn", ph_lcd_set_cursor_on, 1);
  rb_define_alias(ph_lcd, "cursor_on=", "setCursorOn");

  /* Document-method: drawLine
   * call-seq: drawLine(x1, y1, x2, y2)
   *
   * Draws a straight line in the current frame buffer between two specified points.
   * Changes made to the frame buffer must be flushed to the LCD screen using flush.
   */
  rb_define_method(ph_lcd, "drawLine", ph_lcd_draw_line, 4);
  rb_define_alias(ph_lcd, "draw_line", "drawLine");

  /* Document-method: drawPixel
   * call-seq: drawPixel(x, y, pixel_state)
   *
   * Draws, erases, or inverts a single specified pixel.
   * Changes made to the frame buffer must be flushed to the LCD screen using flush.
   */
  rb_define_method(ph_lcd, "drawPixel", ph_lcd_draw_pixel, 3);
  rb_define_alias(ph_lcd, "draw_pixel", "drawPixel");

  /* Document-method: drawRect
   * call-seq: drawRect(x1, y1, x2, y2, filled, inverted)
   *
   * Draws a rectangle in the current frame buffer using the specified points.
   * Changes made to the frame buffer must be flushed to the LCD screen using flush.
   */
  rb_define_method(ph_lcd, "drawRect", ph_lcd_draw_rect, 6);
  rb_define_alias(ph_lcd, "draw_rect", "drawRect");

  /* Document-method: flush
   * call-seq: flush
   *
   * Flushes the buffered LCD contents to the LCD screen.
   */
  rb_define_method(ph_lcd, "flush", ph_lcd_flush, 0);

  /* Document-method: getFontSize
   * call-seq: getFontSize(font) -> font_size
   *
   * Gets the size of the specified font.
   */
  rb_define_method(ph_lcd, "getFontSize", ph_lcd_get_font_size, 1);
  rb_define_alias(ph_lcd, "font_size", "getFontSize");

  /* Document-method: setFontSize
   * call-seq: setFontSize(font, width, height)
   *
   * Sets the size of the specified font.
   */
  rb_define_method(ph_lcd, "setFontSize", ph_lcd_set_font_size, 3);
  rb_define_alias(ph_lcd, "set_font_size", "setFontSize");

  /* Document-method: getFrameBuffer
   * call-seq: getFrameBuffer -> frame_buffer
   *
   * The frame buffer that is currently being used.
   * Commands sent to the device are performed on this buffer.
   */
  rb_define_method(ph_lcd, "getFrameBuffer", ph_lcd_get_frame_buffer, 0);
  rb_define_alias(ph_lcd, "frame_buffer", "getFrameBuffer");

  /* Document-method: setFrameBuffer
   * call-seq: setFrameBuffer(frame_buffer)
   *
   * The frame buffer that is currently being used.
   * Commands sent to the device are performed on this buffer.
   */
  rb_define_method(ph_lcd, "setFrameBuffer", ph_lcd_set_frame_buffer, 1);
  rb_define_alias(ph_lcd, "frame_buffer=", "setFrameBuffer");

  /* Document-method: getHeight
   * call-seq: getHeight -> height
   *
   * The height of the LCD screen attached to the channel.
   */
  rb_define_method(ph_lcd, "getHeight", ph_lcd_get_height, 0);
  rb_define_alias(ph_lcd, "height", "getHeight");

  /* Document-method: init
   * call-seq: init
   *
   * Initializes the Text LCD display.
   */
  rb_define_method(ph_lcd, "init", ph_lcd_init, 0);

  /* Document-method: saveFrameBuffer
   * call-seq: saveFrameBuffer(frame_buffer)
   *
   * Writes the specified frame buffer to flash memory
   * Use sparingly. The flash memory is only designed to be written to 10,000 times before it may
   * become unusable. This method can only be called one time each time the channel is opened.
   */
  rb_define_method(ph_lcd, "saveFrameBuffer", ph_lcd_save_frame_buffer, 1);
  rb_define_alias(ph_lcd, "save_frame_buffer", "saveFrameBuffer");

  /* Document-method: getScreenSize
   * call-seq: getScreenSize -> screen_size
   *
   * The size of the LCD screen attached to the channel.
   */
  rb_define_method(ph_lcd, "getScreenSize", ph_lcd_get_screen_size, 0);
  rb_define_alias(ph_lcd, "screen_size", "getScreenSize");

  /* Document-method: setScreenSize
   * call-seq: setScreenSize(screen_size)
   *
   * The size of the LCD screen attached to the channel.
   */
  rb_define_method(ph_lcd, "setScreenSize", ph_lcd_set_screen_size, 1);
  rb_define_alias(ph_lcd, "screen_size=", "setScreenSize");

  /* Document-method: getSleeping
   * call-seq: getSleeping -> sleeping
   *
   * The on/off state of Sleeping. Putting the device to sleep turns off the display and backlight in order to save power.
   * The device will still take commands while asleep, and will wake up if the screen is flushed, or if the contrast or backlight are changed.
   * When the device wakes up, it will return to its last known state, taking into account any changes that happened while asleep.
   */
  rb_define_method(ph_lcd, "getSleeping", ph_lcd_get_sleeping, 0);
  rb_define_alias(ph_lcd, "sleeping", "getSleeping");

  /* Document-method: setSleeping
   * call-seq: setSleeping(sleeping)
   *
   * The on/off state of Sleeping. Putting the device to sleep turns off the display and backlight in order to save power.
   * The device will still take commands while asleep, and will wake up if the screen is flushed, or if the contrast or backlight are changed.
   * When the device wakes up, it will return to its last known state, taking into account any changes that happened while asleep.
   */
  rb_define_method(ph_lcd, "setSleeping", ph_lcd_set_sleeping, 1);
  rb_define_alias(ph_lcd, "sleeping=", "setSleeping");

  /* Document-method: getWidth
   * call-seq: getWidth -> width
   *
   * The width of the LCD screen attached to the channel.
   */
  rb_define_method(ph_lcd, "getWidth", ph_lcd_get_width, 0);
  rb_define_alias(ph_lcd, "width", "getWidth");

  /* Document-method: writeBitmap
   * call-seq: writeBitmap(x_pos, y_pos, x_size, y_size, bitmap)
   *
   * Draws a bitmap to the current frame buffer at the given location.
   * Each byte in the array represents one pixel in row-major order.
   * Changes made to the frame buffer must be flushed to the LCD screen using flush.
   */
  rb_define_method(ph_lcd, "writeBitmap", ph_lcd_write_bitmap, 5);
  rb_define_alias(ph_lcd, "write_bitmap", "writeBitmap");

  /* Document-method: writeText
   * call-seq: writeText(font, x_pos, y_pos, text)
   *
   * Writes text to the current frame buffer at the specified location
   * Changes made to the frame buffer must be flushed to the LCD screen using flush.
   */
  rb_define_method(ph_lcd, "writeText", ph_lcd_write_text, 4);
  rb_define_alias(ph_lcd, "write_text", "writeText");
}

