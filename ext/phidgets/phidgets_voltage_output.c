
#include "phidgets.h"

#define VOLTAGE_OUTPUT_VOLTAGE_ASYNC_CALLBACK     0


VALUE ph_voltage_output_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetVoltageOutput_create((PhidgetVoltageOutputHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_voltage_output_get_enabled(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetVoltageOutput_getEnabled);
}

VALUE ph_voltage_output_set_enabled(VALUE self, VALUE enabled) {
  ph_raise(PhidgetVoltageOutput_setEnabled((PhidgetVoltageOutputHandle)get_ph_handle(self), TYPE(enabled) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_voltage_output_get_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageOutput_getVoltage);
}

VALUE ph_voltage_output_set_voltage(VALUE self, VALUE voltage) {
  ph_raise(PhidgetVoltageOutput_setVoltage((PhidgetVoltageOutputHandle)get_ph_handle(self), NUM2DBL(voltage)));
  return Qnil;
}

VALUE ph_voltage_output_get_min_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageOutput_getMinVoltage);
}

VALUE ph_voltage_output_get_max_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageOutput_getMaxVoltage);
}

VALUE ph_voltage_output_get_voltage_output_range(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetVoltageOutput_getVoltageOutputRange);
}

VALUE ph_voltage_output_set_voltage_output_range(VALUE self, VALUE output_range) {
  ph_raise(PhidgetVoltageOutput_setVoltageOutputRange((PhidgetVoltageOutputHandle)get_ph_handle(self), NUM2INT(output_range)));
  return Qnil;
}



void CCONV ph_voltage_output_voltage_async(PhidgetHandle phid, void *userPtr, PhidgetReturnCode res) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->exit = true;
  callback_data->arg1 = INT2NUM(res);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}

VALUE ph_voltage_output_set_voltage_async(VALUE self, VALUE voltage, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[VOLTAGE_OUTPUT_VOLTAGE_ASYNC_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    PhidgetVoltageOutput_setVoltage_async((PhidgetVoltageOutputHandle)ph->handle, NUM2DBL(voltage), NULL, (void *)NULL);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    PhidgetVoltageOutput_setVoltage_async((PhidgetVoltageOutputHandle)ph->handle, NUM2DBL(voltage), ph_voltage_output_voltage_async, (void *)callback_data);
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_voltage_output() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_voltage_output = rb_define_class_under(ph_module, "VoltageOutput", ph_common);


  rb_define_const(ph_voltage_output, "VOLTAGE_OUTPUT_RANGE_10V", INT2NUM(VOLTAGE_OUTPUT_RANGE_10V));
  rb_define_const(ph_voltage_output, "VOLTAGE_OUTPUT_RANGE_5V", INT2NUM(VOLTAGE_OUTPUT_RANGE_5V));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget VoltageOutput object.
   */
  rb_define_method(ph_voltage_output, "initialize", ph_voltage_output_init, 0);

  /* Document-method: getEnabled
   * call-seq: getEnabled -> enabled
   *
   * Enable the output voltage by setting Enabled to true.
   * Disable the output by seting Enabled to false to save power.
   */
  rb_define_method(ph_voltage_output, "getEnabled", ph_voltage_output_get_enabled, 0);
  rb_define_alias(ph_voltage_output, "enabled?", "getEnabled");

  /* Document-method: setEnabled
   * call-seq: setEnabled(enabled)
   *
   * Enable the output voltage by setting Enabled to true.
   * Disable the output by seting Enabled to false to save power.
   */
  rb_define_method(ph_voltage_output, "setEnabled", ph_voltage_output_set_enabled, 1);
  rb_define_alias(ph_voltage_output, "enabled=", "setEnabled");

  /* Document-method: getVoltage
   * call-seq: getVoltage -> voltage
   *
   * The voltage value that the channel will output.
   * The Voltage value is bounded by MinVoltage and MaxVoltage.
   * The voltage value will not be output until Enabled is set to true.
   */
  rb_define_method(ph_voltage_output, "getVoltage", ph_voltage_output_get_voltage, 0);
  rb_define_alias(ph_voltage_output, "voltage", "getVoltage");

  /* Document-method: setVoltage
   * call-seq: setVoltage(voltage)
   *
   * The voltage value that the channel will output.
   * The Voltage value is bounded by MinVoltage and MaxVoltage.
   * The voltage value will not be output until Enabled is set to true.
   */
  rb_define_method(ph_voltage_output, "setVoltage", ph_voltage_output_set_voltage, 1);
  rb_define_alias(ph_voltage_output, "voltage=", "setVoltage");

  /* Document-method: getMinVoltage
   * call-seq: getMinVoltage -> min_voltage
   *
   * The minimum value that Voltage can be set to.
   */
  rb_define_method(ph_voltage_output, "getMinVoltage", ph_voltage_output_get_min_voltage, 0);
  rb_define_alias(ph_voltage_output, "min_voltage", "getMinVoltage");

  /* Document-method: getMaxVoltage
   * call-seq: getMaxVoltage -> max_voltage
   *
   * The maximum value that Voltage can be set to.
   */
  rb_define_method(ph_voltage_output, "getMaxVoltage", ph_voltage_output_get_max_voltage, 0);
  rb_define_alias(ph_voltage_output, "max_voltage", "getMaxVoltage");

  /* Document-method: getVoltageOutputRange
   * call-seq: getVoltageOutputRange -> output_range
   *
   * Choose a VoltageOutputRange that best suits your application.
   * Changing the VoltageOutputRange will also affect the MinVoltage and MaxVoltage values.
   */
  rb_define_method(ph_voltage_output, "getVoltageOutputRange", ph_voltage_output_get_voltage_output_range, 0);
  rb_define_alias(ph_voltage_output, "voltage_output_range", "getVoltageOutputRange");

  /* Document-method: setVoltageOutputRange
   * call-seq: setVoltageOutputRange(output_range)
   *
   * Choose a VoltageOutputRange that best suits your application.
   * Changing the VoltageOutputRange will also affect the MinVoltage and MaxVoltage values.
   */
  rb_define_method(ph_voltage_output, "setVoltageOutputRange", ph_voltage_output_set_voltage_output_range, 1);
  rb_define_alias(ph_voltage_output, "voltage_output_range=", "setVoltageOutputRange");

  rb_define_private_method(ph_voltage_output, "ext_setVoltage_async", ph_voltage_output_set_voltage_async, 2);
}

