
#include "phidgets.h"


VALUE ph_textlcd_init(VALUE self);
VALUE ph_textlcd_get_row_count(VALUE self);
VALUE ph_textlcd_get_column_count(VALUE self);
VALUE ph_textlcd_get_backlight(VALUE self);
VALUE ph_textlcd_set_backlight(VALUE self, VALUE state);
VALUE ph_textlcd_get_brightness(VALUE self);
VALUE ph_textlcd_set_brightness(VALUE self, VALUE brightness);
VALUE ph_textlcd_get_contrast(VALUE self);
VALUE ph_textlcd_set_contrast(VALUE self, VALUE contrast);
VALUE ph_textlcd_get_cursor_on(VALUE self);
VALUE ph_textlcd_set_cursor_on(VALUE self, VALUE state);
VALUE ph_textlcd_get_cursor_blink(VALUE self);
VALUE ph_textlcd_set_cursor_blink(VALUE self, VALUE state);
VALUE ph_textlcd_set_custom_character(VALUE self, VALUE index, VALUE var1, VALUE var2);
VALUE ph_textlcd_set_display_character(VALUE self, VALUE index, VALUE column, VALUE character);
VALUE ph_textlcd_set_display_string(VALUE self, VALUE index, VALUE string);
VALUE ph_textlcd_get_screen_count(VALUE self);
VALUE ph_textlcd_get_screen(VALUE self);
VALUE ph_textlcd_set_screen(VALUE self, VALUE index);
VALUE ph_textlcd_get_screen_size(VALUE self);
VALUE ph_textlcd_set_screen_size(VALUE self, VALUE screen);
VALUE ph_textlcd_init_screen(VALUE self);


VALUE Init_phidgets_textlcd(VALUE ph_module, VALUE ph_common) {
  VALUE ph_textlcd = rb_define_class_under(ph_module, "TextLCD", ph_common);

  /* no screen attached */
  rb_define_const(ph_textlcd, "SCREEN_NONE", INT2FIX(PHIDGET_TEXTLCD_SCREEN_NONE));
  /* 1 row, 8 column screen */
  rb_define_const(ph_textlcd, "SCREEN_1x8", INT2FIX(PHIDGET_TEXTLCD_SCREEN_1x8));
  /* 2 row, 8 column screen */
  rb_define_const(ph_textlcd, "SCREEN_2x8", INT2FIX(PHIDGET_TEXTLCD_SCREEN_2x8));
  /* 1 row, 16 column screen */
  rb_define_const(ph_textlcd, "SCREEN_1x16", INT2FIX(PHIDGET_TEXTLCD_SCREEN_1x16));
  /* 2 row, 16 column screen */
  rb_define_const(ph_textlcd, "SCREEN_2x16", INT2FIX(PHIDGET_TEXTLCD_SCREEN_2x16));
  /* 4 row, 16 column screen */
  rb_define_const(ph_textlcd, "SCREEN_4x16", INT2FIX(PHIDGET_TEXTLCD_SCREEN_4x16));
  /* 2 row, 20 column screen */
  rb_define_const(ph_textlcd, "SCREEN_2x20", INT2FIX(PHIDGET_TEXTLCD_SCREEN_2x20));
  /* 4 row, 20 column screen */
  rb_define_const(ph_textlcd, "SCREEN_4x20", INT2FIX(PHIDGET_TEXTLCD_SCREEN_4x20));
  /* 2 row, 24 column screen */
  rb_define_const(ph_textlcd, "SCREEN_2x24", INT2FIX(PHIDGET_TEXTLCD_SCREEN_2x24));
  /* 1 row, 40 column screen */
  rb_define_const(ph_textlcd, "SCREEN_1x40", INT2FIX(PHIDGET_TEXTLCD_SCREEN_1x40));
  /* 2 row, 40 column screen */
  rb_define_const(ph_textlcd, "SCREEN_2x40", INT2FIX(PHIDGET_TEXTLCD_SCREEN_2x40));
  /* 4 row, 40 column screen (special case, requires both screen connections) */
  rb_define_const(ph_textlcd, "SCREEN_4x40", INT2FIX(PHIDGET_TEXTLCD_SCREEN_4x40));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget TextLCD object.
   */
  rb_define_method(ph_textlcd, "initialize", ph_textlcd_init, 0);

  /* Document-method: getRowCount
   * call-seq: getRowCount -> count
   *
   * Gets the number of rows supported by this display.
   */
  rb_define_method(ph_textlcd, "getRowCount", ph_textlcd_get_row_count, 0);

  /* Document-method: getColumnCount
   * call-seq: getColumnCount -> count
   *
   * Gets the number of columns per supported by this display.
   */
  rb_define_method(ph_textlcd, "getColumnCount", ph_textlcd_get_column_count, 0);

  /* Document-method: getBacklight
   * call-seq: getBacklight -> true or false
   *
   * Gets the state of the backlight.
   */
  rb_define_method(ph_textlcd, "getBacklight", ph_textlcd_get_backlight, 0);

  /* Document-method: setBacklight
   * call-seq: setBacklight(state)
   *
   * Sets the state of the backlight.
   */
  rb_define_method(ph_textlcd, "setBacklight", ph_textlcd_set_backlight, 1);

  /* Document-method: getBrightness
   * call-seq: getBrightness -> brightness
   *
   * Gets the brightness of the backlight. Not supported on all TextLCDs
   */
  rb_define_method(ph_textlcd, "getBrightness", ph_textlcd_get_brightness, 0);

  /* Document-method: setBrightness
   * call-seq: setBrightness(brightness)
   *
   * Sets the brightness of the backlight. Not supported on all TextLCDs
   */
  rb_define_method(ph_textlcd, "setBrightness", ph_textlcd_set_brightness, 1);

  /* Document-method: getContrast
   * call-seq: getContrast -> contrast
   *
   * Gets the last set contrast value.
   */
  rb_define_method(ph_textlcd, "getContrast", ph_textlcd_get_contrast, 0);

  /* Document-method: setContrast
   * call-seq: setContrast(contrast)
   *
   * Sets the last set contrast value.
   */
  rb_define_method(ph_textlcd, "setContrast", ph_textlcd_set_contrast, 1);

  /* Document-method: getCursorOn
   * call-seq: getCursorOn -> true or false
   *
   * Gets the cursor visible state.
   */
  rb_define_method(ph_textlcd, "getCursorOn", ph_textlcd_get_cursor_on, 0);

  /* Document-method: setCursorOn
   * call-seq: setCursorOn(state)
   *
   * Sets the cursor visible state.
   */
  rb_define_method(ph_textlcd, "setCursorOn", ph_textlcd_set_cursor_on, 1);

  /* Document-method: getCursorBlink
   * call-seq: getCursorBlink -> true or false
   *
   * Gets the cursor blink state.
   */
  rb_define_method(ph_textlcd, "getCursorBlink", ph_textlcd_get_cursor_blink, 0);

  /* Document-method: setCursorBlink
   * call-seq: setCursorBlink(state)
   *
   * Sets the cursor blink state.
   */
  rb_define_method(ph_textlcd, "setCursorBlink", ph_textlcd_set_cursor_blink, 1);

  /* Document-method: setCustomCharacter
   * call-seq: setCustomCharacter(index, var1, var2)
   *
   * Sets a custom character. See the product manual for more information.
   */
  rb_define_method(ph_textlcd, "setCustomCharacter", ph_textlcd_set_custom_character, 3);

  /* Document-method: setDisplayCharacter
   * call-seq: setDisplayCharacter(index, column, character)
   *
   * Sets a single character on the display.
   */
  rb_define_method(ph_textlcd, "setDisplayCharacter", ph_textlcd_set_display_character, 3);

  /* Document-method: setDisplayString
   * call-seq: setDisplayString(index, string)
   *
   * Sets a row on the display.
   */
  rb_define_method(ph_textlcd, "setDisplayString", ph_textlcd_set_display_string, 2);

  /* Document-method: getScreenCount
   * call-seq: getScreenCount -> count
   *
   * Gets the number of Display supported by this TextLCD
   */
  rb_define_method(ph_textlcd, "getScreenCount", ph_textlcd_get_screen_count, 0);

  /* Document-method: getScreen
   * call-seq: getScreen -> index
   *
   * Gets the active screen.
   */
  rb_define_method(ph_textlcd, "getScreen", ph_textlcd_get_screen, 0);

  /* Document-method: setScreen
   * call-seq: setScreen(index)
   *
   * Sets the active screen. This is the screen that all subsequent API calls will apply to.
   */
  rb_define_method(ph_textlcd, "setScreen", ph_textlcd_set_screen, 1);

  /* Document-method: getScreenSize
   * call-seq: getScreenSize -> size
   *
   * Gets the screen size.
   */
  rb_define_method(ph_textlcd, "getScreenSize", ph_textlcd_get_screen_size, 0);

  /* Document-method: setScreenSize
   * call-seq: setScreenSize(size)
   *
   * Sets the active screen size. Only supported on the TextLCD Adapter.
   */
  rb_define_method(ph_textlcd, "setScreenSize", ph_textlcd_set_screen_size, 1);

  /* Document-method: initScreen
   * call-seq: initScreen
   *
   * Initializes the active screen. Only supported on the TextLCD adapter. This should be called
   * if a screen is attached after power up, or to clear the screen after setting the size.
   */
  rb_define_method(ph_textlcd, "initScreen", ph_textlcd_init_screen, 0);

  rb_define_alias(ph_textlcd, "row_count", "getRowCount");
  rb_define_alias(ph_textlcd, "column_count", "getColumnCount");
  rb_define_alias(ph_textlcd, "backlight?", "getBacklight");
  rb_define_alias(ph_textlcd, "backlight=", "setBacklight");
  rb_define_alias(ph_textlcd, "brightness", "getBrightness");
  rb_define_alias(ph_textlcd, "brightness=", "setBrightness");
  rb_define_alias(ph_textlcd, "contrast", "getContrast");
  rb_define_alias(ph_textlcd, "contrast=", "setContrast");
  rb_define_alias(ph_textlcd, "cursor_on?", "getCursorOn");
  rb_define_alias(ph_textlcd, "cursor_on=", "setCursorOn");
  rb_define_alias(ph_textlcd, "cursor_blink?", "getCursorBlink");
  rb_define_alias(ph_textlcd, "cursor_blink=", "setCursorBlink");
  rb_define_alias(ph_textlcd, "custom_character", "setCustomCharacter");
  rb_define_alias(ph_textlcd, "display_character", "setDisplayCharacter");
  rb_define_alias(ph_textlcd, "display_string", "setDisplayString");
  rb_define_alias(ph_textlcd, "screen_count", "getScreenCount");
  rb_define_alias(ph_textlcd, "screen", "getScreen");
  rb_define_alias(ph_textlcd, "screen=", "setScreen");
  rb_define_alias(ph_textlcd, "screen_size", "getScreenSize");
  rb_define_alias(ph_textlcd, "screen_size=", "setScreenSize");
  rb_define_alias(ph_textlcd, "init_screen", "initScreen");

  return ph_textlcd;
}



VALUE ph_textlcd_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetTextLCD_create((CPhidgetTextLCDHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_textlcd_get_row_count(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetTextLCD_getRowCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_textlcd_get_column_count(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetTextLCD_getColumnCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_textlcd_get_backlight(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetTextLCD_getBacklight(handle, &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_textlcd_set_backlight(VALUE self, VALUE state) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setBacklight(handle, TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_textlcd_get_brightness(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int brightness;
  ph_raise(CPhidgetTextLCD_getBrightness(handle, &brightness));
  return INT2FIX(brightness);
}

VALUE ph_textlcd_set_brightness(VALUE self, VALUE brightness) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setBrightness(handle, FIX2INT(brightness)));
  return Qnil;
}

VALUE ph_textlcd_get_contrast(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int contrast;
  ph_raise(CPhidgetTextLCD_getContrast(handle, &contrast));
  return INT2FIX(contrast);
}

VALUE ph_textlcd_set_contrast(VALUE self, VALUE contrast) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setContrast(handle, FIX2INT(contrast)));
  return Qnil;
}

VALUE ph_textlcd_get_cursor_on(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetTextLCD_getCursorOn(handle, &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_textlcd_set_cursor_on(VALUE self, VALUE state) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setCursorOn(handle, TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_textlcd_get_cursor_blink(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetTextLCD_getCursorBlink(handle, &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_textlcd_set_cursor_blink(VALUE self, VALUE state) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setCursorBlink(handle, TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_textlcd_set_custom_character(VALUE self, VALUE index, VALUE var1, VALUE var2) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setCustomCharacter(handle, FIX2INT(index), FIX2INT(var1), FIX2INT(var2)));
  return Qnil;
}

VALUE ph_textlcd_set_display_character(VALUE self, VALUE index, VALUE column, VALUE character) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  char *str = StringValueCStr(character);
  ph_raise(CPhidgetTextLCD_setDisplayCharacter(handle, FIX2INT(index), FIX2INT(column), str[0]));
  return Qnil;
}

VALUE ph_textlcd_set_display_string(VALUE self, VALUE index, VALUE string) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setDisplayString(handle, FIX2INT(index), StringValueCStr(string)));
  return Qnil;
}

VALUE ph_textlcd_get_screen_count(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetTextLCD_getScreenCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_textlcd_get_screen(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  int screen;
  ph_raise(CPhidgetTextLCD_getScreen(handle, &screen));
  return INT2FIX(screen);
}

VALUE ph_textlcd_set_screen(VALUE self, VALUE screen) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setScreen(handle, FIX2INT(screen)));
  return Qnil;
}

VALUE ph_textlcd_get_screen_size(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  CPhidgetTextLCD_ScreenSize screen;
  ph_raise(CPhidgetTextLCD_getScreenSize(handle, &screen));
  return INT2FIX(screen);
}

VALUE ph_textlcd_set_screen_size(VALUE self, VALUE screen) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_setScreenSize(handle, (CPhidgetTextLCD_ScreenSize)FIX2INT(screen)));
  return Qnil;
}

VALUE ph_textlcd_init_screen(VALUE self) {
  CPhidgetTextLCDHandle handle = (CPhidgetTextLCDHandle)get_ph_handle(self);
  ph_raise(CPhidgetTextLCD_initialize(handle));
  return Qnil;
}

