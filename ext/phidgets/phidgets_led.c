
#include "phidgets.h"

#if 0
VALUE ph_led_init(VALUE self);
VALUE ph_led_get_led_count(VALUE self);
VALUE ph_led_get_current_limit(VALUE self);
VALUE ph_led_set_current_limit(VALUE self, VALUE limit);
VALUE ph_led_get_voltage(VALUE self);
VALUE ph_led_set_voltage(VALUE self, VALUE voltage);
VALUE ph_led_get_brightness(VALUE self, VALUE index);
VALUE ph_led_set_brightness(VALUE self, VALUE index, VALUE brightness);
VALUE ph_led_get_current_limit_indexed(VALUE self, VALUE index);
VALUE ph_led_set_current_limit_indexed(VALUE self, VALUE index, VALUE limit);


void Init_led() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_led = rb_define_class_under(ph_module, "LED", ph_common);

  rb_define_const(ph_led, "CURRENT_LIMIT_20mA", INT2FIX(PHIDGET_LED_CURRENT_LIMIT_20mA));
  rb_define_const(ph_led, "CURRENT_LIMIT_40mA", INT2FIX(PHIDGET_LED_CURRENT_LIMIT_40mA));
  rb_define_const(ph_led, "CURRENT_LIMIT_60mA", INT2FIX(PHIDGET_LED_CURRENT_LIMIT_60mA));
  rb_define_const(ph_led, "CURRENT_LIMIT_80mA", INT2FIX(PHIDGET_LED_CURRENT_LIMIT_80mA));
  rb_define_const(ph_led, "VOLTAGE_1_7V", INT2FIX(PHIDGET_LED_VOLTAGE_1_7V));
  rb_define_const(ph_led, "VOLTAGE_2_75V", INT2FIX(PHIDGET_LED_VOLTAGE_2_75V));
  rb_define_const(ph_led, "VOLTAGE_3_9V", INT2FIX(PHIDGET_LED_VOLTAGE_3_9V));
  rb_define_const(ph_led, "VOLTAGE_5_0V", INT2FIX(PHIDGET_LED_VOLTAGE_5_0V));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget LED object.
   */
  rb_define_method(ph_led, "initialize", ph_led_init, 0);

  /* Document-method: getLEDCount
   * call-seq: getLEDCount -> count
   *
   * Gets the number of LEDs supported by this board.
   */
  rb_define_method(ph_led, "getLEDCount", ph_led_get_led_count, 0);

  /* Document-method: getCurrentLimit
   * call-seq: getCurrentLimit -> limit
   *
   * Gets the current limit. This is for all ouputs.
   */
  rb_define_method(ph_led, "getCurrentLimit", ph_led_get_current_limit, 0);

  /* Document-method: setCurrentLimit
   * call-seq: setCurrentLimit(limit)
   *
   * Sets the current limit. This is for all ouputs.
   */
  rb_define_method(ph_led, "setCurrentLimit", ph_led_set_current_limit, 1);

  /* Document-method: getVoltage
   * call-seq: getVoltage -> voltage
   *
   * Gets the output voltage. This is for all ouputs.
   */
  rb_define_method(ph_led, "getVoltage", ph_led_get_voltage, 0);

  /* Document-method: setVoltage
   * call-seq: setVoltage(voltage)
   *
   * Sets the output voltage. This is for all ouputs.
   */
  rb_define_method(ph_led, "setVoltage", ph_led_set_voltage, 1);

  /* Document-method: getBrightness
   * call-seq: getBrightness(index) -> brightness
   *
   * Gets the brightness of an LED.
   */
  rb_define_method(ph_led, "getBrightness", ph_led_get_brightness, 1);

  /* Document-method: setBrightness
   * call-seq: setBrightness(index, brightness)
   *
   * Sets the brightness of an LED.
   */
  rb_define_method(ph_led, "setBrightness", ph_led_set_brightness, 2);

  /* Document-method: getCurrentLimitIndexed
   * call-seq: getCurrentLimitIndexed(index) -> limit
   *
   * Gets the current limit of an LED.
   */
  rb_define_method(ph_led, "getCurrentLimitIndexed", ph_led_get_current_limit_indexed, 1);

  /* Document-method: setCurrentLimitIndexed
   * call-seq: setCurrentLimitIndexed(index, limit)
   *
   * Sets the current limit of an LED.
   */
  rb_define_method(ph_led, "setCurrentLimitIndexed", ph_led_set_current_limit_indexed, 2);

  rb_define_alias(ph_led, "led_count", "getLEDCount");
  rb_define_alias(ph_led, "current_limit", "getCurrentLimit");
  rb_define_alias(ph_led, "current_limit=", "setCurrentLimit");
  rb_define_alias(ph_led, "voltage", "getVoltage");
  rb_define_alias(ph_led, "voltage=", "setVoltage");
  rb_define_alias(ph_led, "brightness", "getBrightness");
  rb_define_alias(ph_led, "set_brightness", "setBrightness");
  rb_define_alias(ph_led, "current_limit_indexed", "getCurrentLimitIndexed");
  rb_define_alias(ph_led, "set_current_limit_indexed", "setCurrentLimitIndexed");
}



VALUE ph_led_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetLED_create((PhidgetLEDHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_led_get_led_count(VALUE self) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetLED_getLEDCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_led_get_current_limit(VALUE self) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  PhidgetLED_CurrentLimit limit;
  ph_raise(PhidgetLED_getCurrentLimit(handle, &limit));
  return INT2FIX(limit);
}

VALUE ph_led_set_current_limit(VALUE self, VALUE limit) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  ph_raise(PhidgetLED_setCurrentLimit(handle, FIX2INT(limit)));
  return Qnil;
}

VALUE ph_led_get_voltage(VALUE self) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  PhidgetLED_Voltage voltage;
  ph_raise(PhidgetLED_getVoltage(handle, &voltage));
  return INT2FIX(voltage);
}

VALUE ph_led_set_voltage(VALUE self, VALUE voltage) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  ph_raise(PhidgetLED_setVoltage(handle, FIX2INT(voltage)));
  return Qnil;
}

VALUE ph_led_get_brightness(VALUE self, VALUE index) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  double brightness;
  ph_raise(PhidgetLED_getBrightness(handle, FIX2INT(index), &brightness));
  return rb_float_new(brightness);
}

VALUE ph_led_set_brightness(VALUE self, VALUE index, VALUE brightness) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  ph_raise(PhidgetLED_setBrightness(handle, FIX2INT(index), NUM2DBL(brightness)));
  return Qnil;
}

VALUE ph_led_get_current_limit_indexed(VALUE self, VALUE index) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  double limit;
  ph_raise(PhidgetLED_getCurrentLimitIndexed(handle, FIX2INT(index), &limit));
  return rb_float_new(limit);
}

VALUE ph_led_set_current_limit_indexed(VALUE self, VALUE index, VALUE limit) {
  PhidgetLEDHandle handle = (PhidgetLEDHandle)get_ph_handle(self);
  ph_raise(PhidgetLED_setCurrentLimitIndexed(handle, FIX2INT(index), NUM2DBL(limit)));
  return Qnil;
}
#endif
