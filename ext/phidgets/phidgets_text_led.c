
#include "phidgets.h"

#if 0
VALUE ph_textled_init(VALUE self);
VALUE ph_textled_get_row_count(VALUE self);
VALUE ph_textled_get_column_count(VALUE self);
VALUE ph_textled_get_brightness(VALUE self);
VALUE ph_textled_set_brightness(VALUE self, VALUE brightness);
VALUE ph_textled_set_display_string(VALUE self, VALUE index, VALUE string);


void Init_text_led() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_textled = rb_define_class_under(ph_module, "TextLED", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget TextLED object.
   */
  rb_define_method(ph_textled, "initialize", ph_textled_init, 0);

  /* Document-method: getRowCount
   * call-seq: getRowCount -> count
   *
   * Gets the number of rows supported by this display.
   */
  rb_define_method(ph_textled, "getRowCount", ph_textled_get_row_count, 0);

  /* Document-method: getColumnCount
   * call-seq: getColumnCount -> count
   *
   * Gets the number of columns per supported by this display.
   */
  rb_define_method(ph_textled, "getColumnCount", ph_textled_get_column_count, 0);

  /* Document-method: getBrightness
   * call-seq: getBrightness -> brightness
   *
   * Gets the last set brightness value.
   */
  rb_define_method(ph_textled, "getBrightness", ph_textled_get_brightness, 0);

  /* Document-method: setBrightness
   * call-seq: setBrightness(brightness)
   *
   * Sets the last set brightness value.
   */
  rb_define_method(ph_textled, "setBrightness", ph_textled_set_brightness, 1);

  /* Document-method: setDisplayString
   * call-seq: setDisplayString(index, string)
   *
   * Sets a row on the display.
   */
  rb_define_method(ph_textled, "setDisplayString", ph_textled_set_display_string, 2);

  rb_define_alias(ph_textled, "row_count", "getRowCount");
  rb_define_alias(ph_textled, "column_count", "getColumnCount");
  rb_define_alias(ph_textled, "brightness", "getBrightness");
  rb_define_alias(ph_textled, "brightness=", "setBrightness");
  rb_define_alias(ph_textled, "display_string", "setDisplayString");
}



VALUE ph_textled_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetTextLED_create((PhidgetTextLEDHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_textled_get_row_count(VALUE self) {
  PhidgetTextLEDHandle handle = (PhidgetTextLEDHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetTextLED_getRowCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_textled_get_column_count(VALUE self) {
  PhidgetTextLEDHandle handle = (PhidgetTextLEDHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetTextLED_getColumnCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_textled_get_brightness(VALUE self) {
  PhidgetTextLEDHandle handle = (PhidgetTextLEDHandle)get_ph_handle(self);
  int brightness;
  ph_raise(PhidgetTextLED_getBrightness(handle, &brightness));
  return INT2FIX(brightness);
}

VALUE ph_textled_set_brightness(VALUE self, VALUE brightness) {
  PhidgetTextLEDHandle handle = (PhidgetTextLEDHandle)get_ph_handle(self);
  ph_raise(PhidgetTextLED_setBrightness(handle, FIX2INT(brightness)));
  return Qnil;
}

VALUE ph_textled_set_display_string(VALUE self, VALUE index, VALUE string) {
  PhidgetTextLEDHandle handle = (PhidgetTextLEDHandle)get_ph_handle(self);
  ph_raise(PhidgetTextLED_setDisplayString(handle, FIX2INT(index), StringValueCStr(string)));
  return Qnil;
}
#endif
