
#include "phidgets.h"


VALUE ph_digital_output_init(VALUE self);
VALUE ph_digital_output_get_duty_cycle(VALUE self);
VALUE ph_digital_output_set_duty_cycle(VALUE self, VALUE duty_cycle);
VALUE ph_digital_output_get_min_duty_cycle(VALUE self);
VALUE ph_digital_output_get_max_duty_cycle(VALUE self);
VALUE ph_digital_output_get_led_current_limit(VALUE self);
VALUE ph_digital_output_set_led_current_limit(VALUE self, VALUE current_limit);
VALUE ph_digital_output_get_min_led_current_limit(VALUE self);
VALUE ph_digital_output_get_max_led_current_limit(VALUE self);
VALUE ph_digital_output_get_led_forward_voltage(VALUE self);
VALUE ph_digital_output_set_led_forward_voltage(VALUE self, VALUE forward_voltage);
VALUE ph_digital_output_get_state(VALUE self);
VALUE ph_digital_output_set_state(VALUE self, VALUE state);


void Init_digital_output() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_digital_output = rb_define_class_under(ph_module, "DigitalOutput", ph_common);


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget DigitalOutput object.
   */
  rb_define_method(ph_digital_output, "initialize", ph_digital_output_init, 0);

  /* Document-method: getDutyCycle
   * call-seq: getDutyCycle -> duty_cycle
   *
   * The DutyCycle represents the fraction of time the output is on (high).
   * A DutyCycle of 1.0 translates to a high output, a DutyCycle of 0 translates to a low output.
   * A DutyCycle of 0.5 translates to an output that is high half the time, which results in an average output voltage of (output voltage x 0.5)
   * You can use the DutyCycle to create a dimming effect on LEDs.
   */
  rb_define_method(ph_digital_output, "getDutyCycle", ph_digital_output_get_duty_cycle, 0);
  rb_define_alias(ph_digital_output, "duty_cycle", "getDutyCycle");

  /* Document-method: setDutyCycle
   * call-seq: setDutyCycle(duty_cycle)
   *
   * The DutyCycle represents the fraction of time the output is on (high).
   * This will override the State setting on the channel.
   * A DutyCycle of 1.0 translates to a high output, a DutyCycle of 0 translates to a low output.
   * This is equivalent to setting a State of TRUE and FALSE respectively.
   * A DutyCycle of 0.5 translates to an output that is high half the time, which results in an average output voltage of (output voltage x 0.5)
   * You can use the DutyCycle to create a dimming effect on LEDs.
   * If the DigitalOutput channel you are using does not support PWM, then this value may only be set to 1.0 or 0.0.
   */
  rb_define_method(ph_digital_output, "setDutyCycle", ph_digital_output_set_duty_cycle, 1);
  rb_define_alias(ph_digital_output, "duty_cycle=", "setDutyCycle");

  /* Document-method: getMinDutyCycle
   * call-seq: getMinDutyCycle -> min_duty_cycle
   *
   * The minimum value that DutyCycle can be set to.
   */
  rb_define_method(ph_digital_output, "getMinDutyCycle", ph_digital_output_get_min_duty_cycle, 0);
  rb_define_alias(ph_digital_output, "min_duty_cycle", "getMinDutyCycle");

  /* Document-method: getMaxDutyCycle
   * call-seq: getMaxDutyCycle -> max_duty_cycle
   *
   * The maximum value that DutyCycle can be set to.
   */
  rb_define_method(ph_digital_output, "getMaxDutyCycle", ph_digital_output_get_max_duty_cycle, 0);
  rb_define_alias(ph_digital_output, "max_duty_cycle", "getMaxDutyCycle");

  /* Document-method: getLEDCurrentLimit
   * call-seq: getLEDCurrentLimit -> current_limit
   *
   * The LEDCurrentLimit is the maximum amount of current that the controller will provide to the output.
   * Reference the data sheet of the LED you are using before setting this value.
   */
  rb_define_method(ph_digital_output, "getLEDCurrentLimit", ph_digital_output_get_led_current_limit, 0);
  rb_define_alias(ph_digital_output, "led_current_limit", "getLEDCurrentLimit");

  /* Document-method: setLEDCurrentLimit
   * call-seq: setLEDCurrentLimit(current_limit)
   *
   * The LEDCurrentLimit is the maximum amount of current that the controller will provide to the output.
   * Reference the data sheet of the LED you are using before setting this value.
   */
  rb_define_method(ph_digital_output, "setLEDCurrentLimit", ph_digital_output_set_led_current_limit, 1);
  rb_define_alias(ph_digital_output, "led_current_limit=", "setLEDCurrentLimit");

  /* Document-method: getMinLEDCurrentLimit
   * call-seq: getMinLEDCurrentLimit -> min_current_limit
   *
   * The minimum value that LEDCurrentLimit can be set to.
   */
  rb_define_method(ph_digital_output, "getMinLEDCurrentLimit", ph_digital_output_get_min_led_current_limit, 0);
  rb_define_alias(ph_digital_output, "min_led_current_limit", "getMinLEDCurrentLimit");

  /* Document-method: getMaxLEDCurrentLimit
   * call-seq: getMaxLEDCurrentLimit -> max_current_limit
   *
   * The maximum value that LEDCurrentLimit can be set to.
   */
  rb_define_method(ph_digital_output, "getMaxLEDCurrentLimit", ph_digital_output_get_max_led_current_limit, 0);
  rb_define_alias(ph_digital_output, "max_led_current_limit", "getMaxLEDCurrentLimit");

  /* Document-method: getLEDForwardVoltage
   * call-seq: getLEDForwardVoltage -> forward_voltage
   *
   * The LEDForwardVoltage is the voltage that will be available to your LED.
   * Reference the data sheet of the LED you are using before setting this value. Choose the LEDForwardVoltage that is closest to the forward voltage specified in the data sheet.
   * This forward voltage is shared for all channels on this device. Setting the LEDForwardVoltage on any channel will set the LEDForwardVoltage for all channels on the device.
   */
  rb_define_method(ph_digital_output, "getLEDForwardVoltage", ph_digital_output_get_led_forward_voltage, 0);
  rb_define_alias(ph_digital_output, "led_forward_voltage", "getLEDForwardVoltage");

  /* Document-method: setLEDForwardVoltage
   * call-seq: setLEDForwardVoltage(forward_voltage)
   *
   * The LEDForwardVoltage is the voltage that will be available to your LED.
   * Reference the data sheet of the LED you are using before setting this value. Choose the LEDForwardVoltage that is closest to the forward voltage specified in the data sheet.
   * This forward voltage is shared for all channels on this device. Setting the LEDForwardVoltage on any channel will set the LEDForwardVoltage for all channels on the device.
   */
  rb_define_method(ph_digital_output, "setLEDForwardVoltage", ph_digital_output_set_led_forward_voltage, 1);
  rb_define_alias(ph_digital_output, "led_forward_voltage=", "setLEDForwardVoltage");

  /* Document-method: getState
   * call-seq: getState -> state
   *
   * The State will indicate whether the output is high (true) or low (false).
   * If a DutyCycle has been set, the state will return as true if the DutyCycle is above 0.5, or false otherwise.
   */
  rb_define_method(ph_digital_output, "getState", ph_digital_output_get_state, 0);
  rb_define_alias(ph_digital_output, "state", "getState");

  /* Document-method: setState
   * call-seq: setState(state)
   *
   * The State will dictate whether the output is constantly high (TRUE) or low (FALSE).
   * This will override any DutyCycle that may have been set on the channel.
   * Setting the State to TRUE is the same as setting DutyCycle to 1.0, and setting the State to FALSE is the same as setting a DutyCycle of 0.0.
   */
  rb_define_method(ph_digital_output, "setState", ph_digital_output_set_state, 1);
  rb_define_alias(ph_digital_output, "state=", "setState");
}



VALUE ph_digital_output_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetDigitalOutput_create((PhidgetDigitalOutputHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_digital_output_get_duty_cycle(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  double duty_cycle;
  ph_raise(PhidgetDigitalOutput_getDutyCycle(handle, &duty_cycle));
  return DBL2NUM(duty_cycle);
}

VALUE ph_digital_output_set_duty_cycle(VALUE self, VALUE duty_cycle) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  ph_raise(PhidgetDigitalOutput_setDutyCycle(handle, NUM2DBL(duty_cycle)));
  return Qnil;
}

VALUE ph_digital_output_get_min_duty_cycle(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  double duty_cycle;
  ph_raise(PhidgetDigitalOutput_getMinDutyCycle(handle, &duty_cycle));
  return DBL2NUM(duty_cycle);
}

VALUE ph_digital_output_get_max_duty_cycle(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  double duty_cycle;
  ph_raise(PhidgetDigitalOutput_getMaxDutyCycle(handle, &duty_cycle));
  return DBL2NUM(duty_cycle);
}

VALUE ph_digital_output_get_led_current_limit(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  double current_limit;
  ph_raise(PhidgetDigitalOutput_getLEDCurrentLimit(handle, &current_limit));
  return DBL2NUM(current_limit);
}

VALUE ph_digital_output_set_led_current_limit(VALUE self, VALUE current_limit) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  ph_raise(PhidgetDigitalOutput_setLEDCurrentLimit(handle, NUM2DBL(current_limit)));
  return Qnil;
}

VALUE ph_digital_output_get_min_led_current_limit(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  double current_limit;
  ph_raise(PhidgetDigitalOutput_getMinLEDCurrentLimit(handle, &current_limit));
  return DBL2NUM(current_limit);
}

VALUE ph_digital_output_get_max_led_current_limit(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  double current_limit;
  ph_raise(PhidgetDigitalOutput_getMaxLEDCurrentLimit(handle, &current_limit));
  return DBL2NUM(current_limit);
}

VALUE ph_digital_output_get_led_forward_voltage(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  PhidgetDigitalOutput_LEDForwardVoltage forward_voltage;
  ph_raise(PhidgetDigitalOutput_getLEDForwardVoltage(handle, &forward_voltage));
  return INT2NUM(forward_voltage);
}

VALUE ph_digital_output_set_led_forward_voltage(VALUE self, VALUE forward_voltage) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  ph_raise(PhidgetDigitalOutput_setLEDForwardVoltage(handle, NUM2INT(forward_voltage)));
  return Qnil;
}

VALUE ph_digital_output_get_state(VALUE self) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  int state;
  ph_raise(PhidgetDigitalOutput_getState(handle, &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_digital_output_set_state(VALUE self, VALUE state) {
  PhidgetDigitalOutputHandle handle = (PhidgetDigitalOutputHandle)get_ph_handle(self);
  ph_raise(PhidgetDigitalOutput_setState(handle, TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

