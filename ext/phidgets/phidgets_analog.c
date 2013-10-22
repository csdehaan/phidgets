
#include "phidgets.h"


VALUE ph_analog_init(VALUE self);
VALUE ph_analog_get_output_count(VALUE self);
VALUE ph_analog_get_voltage(VALUE self, VALUE index);
VALUE ph_analog_get_voltage_min(VALUE self, VALUE index);
VALUE ph_analog_get_voltage_max(VALUE self, VALUE index);
VALUE ph_analog_set_voltage(VALUE self, VALUE index, VALUE voltage);
VALUE ph_analog_get_enabled(VALUE self, VALUE index);
VALUE ph_analog_set_enabled(VALUE self, VALUE index, VALUE state);


void Init_analog() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_analog = rb_define_class_under(ph_module, "Analog", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Analog object.
   */
  rb_define_method(ph_analog, "initialize", ph_analog_init, 0);

  /* Document-method: getOutputCount
   * call-seq: getOutputCount -> output_count
   *
   * Gets the number of outputs supported by this phidget analog.
   */
  rb_define_method(ph_analog, "getOutputCount", ph_analog_get_output_count, 0);

  /* Document-method: getVoltage
   * call-seq: getVoltage(index) -> voltage
   *
   * Gets the currently set voltage for an output, in V.
   */
  rb_define_method(ph_analog, "getVoltage", ph_analog_get_voltage, 1);

  /* Document-method: getVoltageMin
   * call-seq: getVoltageMin(index) -> min
   *
   * Gets the minimum settable output voltage, in V.
   */
  rb_define_method(ph_analog, "getVoltageMin", ph_analog_get_voltage_min, 1);

  /* Document-method: getVoltageMax
   * call-seq: getVoltageMax(index) -> max
   *
   * Gets the maximum settable output voltage, in V.
   */
  rb_define_method(ph_analog, "getVoltageMax", ph_analog_get_voltage_max, 1);

  /* Document-method: setVoltage
   * call-seq: setVoltage(index, voltage)
   *
   * Sets the voltage of an output, in V.
   */
  rb_define_method(ph_analog, "setVoltage", ph_analog_set_voltage, 2);

  /* Document-method: getEnabled
   * call-seq: getEnabled(index) -> true or false
   *
   * Gets the enabled state for an output.
   */
  rb_define_method(ph_analog, "getEnabled", ph_analog_get_enabled, 1);

  /* Document-method: setEnabled
   * call-seq: setEnabled(index, enabled)
   *
   * Sets the enabled state for an output.
   */
  rb_define_method(ph_analog, "setEnabled", ph_analog_set_enabled, 2);

  rb_define_alias(ph_analog, "output_count", "getOutputCount");
  rb_define_alias(ph_analog, "voltage", "getVoltage");
  rb_define_alias(ph_analog, "voltage_min", "getVoltageMin");
  rb_define_alias(ph_analog, "voltage_max", "getVoltageMax");
  rb_define_alias(ph_analog, "set_voltage", "setVoltage");
  rb_define_alias(ph_analog, "enabled?", "getEnabled");
  rb_define_alias(ph_analog, "set_enabled", "setEnabled");
}



VALUE ph_analog_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetAnalog_create((CPhidgetAnalogHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_analog_get_output_count(VALUE self) {
  CPhidgetAnalogHandle handle = (CPhidgetAnalogHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetAnalog_getOutputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_analog_get_voltage(VALUE self, VALUE index) {
  CPhidgetAnalogHandle handle = (CPhidgetAnalogHandle)get_ph_handle(self);
  double volts;
  ph_raise(CPhidgetAnalog_getVoltage(handle, FIX2INT(index), &volts));
  return rb_float_new(volts);
}

VALUE ph_analog_get_voltage_min(VALUE self, VALUE index) {
  CPhidgetAnalogHandle handle = (CPhidgetAnalogHandle)get_ph_handle(self);
  double volts;
  ph_raise(CPhidgetAnalog_getVoltageMin(handle, FIX2INT(index), &volts));
  return rb_float_new(volts);
}

VALUE ph_analog_get_voltage_max(VALUE self, VALUE index) {
  CPhidgetAnalogHandle handle = (CPhidgetAnalogHandle)get_ph_handle(self);
  double volts;
  ph_raise(CPhidgetAnalog_getVoltageMax(handle, FIX2INT(index), &volts));
  return rb_float_new(volts);
}

VALUE ph_analog_set_voltage(VALUE self, VALUE index, VALUE voltage) {
  CPhidgetAnalogHandle handle = (CPhidgetAnalogHandle)get_ph_handle(self);
  ph_raise(CPhidgetAnalog_setVoltage(handle, FIX2INT(index), NUM2DBL(voltage)));
  return Qnil;
}

VALUE ph_analog_get_enabled(VALUE self, VALUE index) {
  CPhidgetAnalogHandle handle = (CPhidgetAnalogHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetAnalog_getEnabled(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_analog_set_enabled(VALUE self, VALUE index, VALUE state) {
  CPhidgetAnalogHandle handle = (CPhidgetAnalogHandle)get_ph_handle(self);
  ph_raise(CPhidgetAnalog_setEnabled(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

