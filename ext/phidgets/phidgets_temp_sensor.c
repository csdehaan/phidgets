
#include "phidgets.h"

#if 0
VALUE ph_temp_init(VALUE self);
VALUE ph_temp_get_temperature_input_count(VALUE self);
VALUE ph_temp_get_temperature(VALUE self, VALUE index);
VALUE ph_temp_get_temperature_min(VALUE self, VALUE index);
VALUE ph_temp_get_temperature_max(VALUE self, VALUE index);
VALUE ph_temp_get_temperature_change_trigger(VALUE self, VALUE index);
VALUE ph_temp_set_temperature_change_trigger(VALUE self, VALUE index, VALUE temperature);
VALUE ph_temp_get_potential(VALUE self, VALUE index);
VALUE ph_temp_get_potential_min(VALUE self, VALUE index);
VALUE ph_temp_get_potential_max(VALUE self, VALUE index);
VALUE ph_temp_get_ambient_temperature(VALUE self);
VALUE ph_temp_get_ambient_temperature_min(VALUE self);
VALUE ph_temp_get_ambient_temperature_max(VALUE self);
VALUE ph_temp_get_thermocouple_type(VALUE self, VALUE index);
VALUE ph_temp_set_thermocouple_type(VALUE self, VALUE index, VALUE thermocouple);

VALUE ph_temp_set_on_temperature_change_handler(VALUE self, VALUE handler);
int ph_temp_on_temperature_change(PhidgetTemperatureSensorHandle phid, void *userPtr, int index, double temperature);


void Init_temperature_sensor() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_temp = rb_define_class_under(ph_module, "TemperatureSensor", ph_common);

  rb_define_const(ph_temp, "K_TYPE", INT2FIX(PHIDGET_TEMPERATURE_SENSOR_K_TYPE));
  rb_define_const(ph_temp, "J_TYPE", INT2FIX(PHIDGET_TEMPERATURE_SENSOR_J_TYPE));
  rb_define_const(ph_temp, "E_TYPE", INT2FIX(PHIDGET_TEMPERATURE_SENSOR_E_TYPE));
  rb_define_const(ph_temp, "T_TYPE", INT2FIX(PHIDGET_TEMPERATURE_SENSOR_T_TYPE));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget TemperatureSensor object.
   */
  rb_define_method(ph_temp, "initialize", ph_temp_init, 0);

  /* Document-method: getTemperatureInputCount
   * call-seq: getTemperatureInputCount -> count
   *
   * Gets the number of thermocouple inputs supported by this board.
   */
  rb_define_method(ph_temp, "getTemperatureInputCount", ph_temp_get_temperature_input_count, 0);

  /* Document-method: getTemperature
   * call-seq: getTemperature(index) -> temperature
   *
   * Gets the temperature measured by a thermocouple input.
   */
  rb_define_method(ph_temp, "getTemperature", ph_temp_get_temperature, 1);

  /* Document-method: getTemperatureMin
   * call-seq: getTemperatureMin(index) -> temperature
   *
   * Gets the minimum temperature that can be measured by a thermocouple input. This depends on the type
   * of thermocouple attached, as well as the ambient temperature.
   */
  rb_define_method(ph_temp, "getTemperatureMin", ph_temp_get_temperature_min, 1);

  /* Document-method: getTemperatureMax
   * call-seq: getTemperatureMax(index) -> temperature
   *
   * Gets the maximum temperature that can be measured by a thermocouple input. This depends on the type
   * of thermocouple attached, as well as the ambient temperature.
   */
  rb_define_method(ph_temp, "getTemperatureMax", ph_temp_get_temperature_max, 1);

  /* Document-method: getTemperatureChangeTrigger
   * call-seq: getTemperatureChangeTrigger(index) -> trigger
   *
   * Gets the change trigger for a thermocouple input.
   */
  rb_define_method(ph_temp, "getTemperatureChangeTrigger", ph_temp_get_temperature_change_trigger, 1);

  /* Document-method: setTemperatureChangeTrigger
   * call-seq: setTemperatureChangeTrigger(index, trigger)
   *
   * Sets the change trigger for a thermocouple input.
   */
  rb_define_method(ph_temp, "setTemperatureChangeTrigger", ph_temp_set_temperature_change_trigger, 2);

  /* Document-method: getPotential
   * call-seq: getPotential(index) -> potential
   *
   * Gets the currently sensed potential for a thermocouple input.
   */
  rb_define_method(ph_temp, "getPotential", ph_temp_get_potential, 1);

  /* Document-method: getPotentialMin
   * call-seq: getPotentialMin(index) -> potential
   *
   * Gets the minimum potential that a thermocouple input can measure.
   */
  rb_define_method(ph_temp, "getPotentialMin", ph_temp_get_potential_min, 1);

  /* Document-method: getPotentialMax
   * call-seq: getPotentialMax(index) -> potential
   *
   * Gets the maximum potential that a thermocouple input can measure.
   */
  rb_define_method(ph_temp, "getPotentialMax", ph_temp_get_potential_max, 1);

  /* Document-method: getAmbientTemperature
   * call-seq: getAmbientTemperature -> temperature
   *
   * Gets the ambient (board) temperature.
   */
  rb_define_method(ph_temp, "getAmbientTemperature", ph_temp_get_ambient_temperature, 0);

  /* Document-method: getAmbientTemperatureMin
   * call-seq: getAmbientTemperatureMin -> temperature
   *
   * Gets the minimum temperature that the ambient onboard temperature sensor can measure.
   */
  rb_define_method(ph_temp, "getAmbientTemperatureMin", ph_temp_get_ambient_temperature_min, 0);

  /* Document-method: getAmbientTemperatureMax
   * call-seq: getAmbientTemperatureMax -> temperature
   *
   * Gets the maximum temperature that the ambient onboard temperature sensor can measure.
   */
  rb_define_method(ph_temp, "getAmbientTemperatureMax", ph_temp_get_ambient_temperature_max, 0);

  /* Document-method: getThermocoupleType
   * call-seq: getThermocoupleType(index) -> type
   *
   * Gets the type of thermocouple set to be at a thermocouple input. By default this is K-Type.
   */
  rb_define_method(ph_temp, "getThermocoupleType", ph_temp_get_thermocouple_type, 1);

  /* Document-method: setThermocoupleType
   * call-seq: setThermocoupleType(index, type)
   *
   * Sets the type of thermocouple plugged into a thermocouple input. By default this is K-Type.
   */
  rb_define_method(ph_temp, "setThermocoupleType", ph_temp_set_thermocouple_type, 2);

  rb_define_private_method(ph_temp, "ext_setOnTemperatureChangeHandler", ph_temp_set_on_temperature_change_handler, 1);

  rb_define_alias(ph_temp, "temperature_input_count", "getTemperatureInputCount");
  rb_define_alias(ph_temp, "temperature", "getTemperature");
  rb_define_alias(ph_temp, "temperature_min", "getTemperatureMin");
  rb_define_alias(ph_temp, "temperature_max", "getTemperatureMax");
  rb_define_alias(ph_temp, "temperature_change_trigger", "getTemperatureChangeTrigger");
  rb_define_alias(ph_temp, "set_temperature_change_trigger", "setTemperatureChangeTrigger");
  rb_define_alias(ph_temp, "potential", "getPotential");
  rb_define_alias(ph_temp, "potential_min", "getPotentialMin");
  rb_define_alias(ph_temp, "potential_max", "getPotentialMax");
  rb_define_alias(ph_temp, "ambient_temperature", "getAmbientTemperature");
  rb_define_alias(ph_temp, "ambient_temperature_min", "getAmbientTemperatureMin");
  rb_define_alias(ph_temp, "ambient_temperature_max", "getAmbientTemperatureMax");
  rb_define_alias(ph_temp, "thermocouple_type", "getThermocoupleType");
  rb_define_alias(ph_temp, "set_thermocouple_type", "setThermocoupleType");
}



VALUE ph_temp_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetTemperatureSensor_create((PhidgetTemperatureSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_temp_get_temperature_input_count(VALUE self) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetTemperatureSensor_getTemperatureInputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_temp_get_temperature(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double temperature;
  ph_raise(PhidgetTemperatureSensor_getTemperature(handle, FIX2INT(index), &temperature));
  return rb_float_new(temperature);
}

VALUE ph_temp_get_temperature_min(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double temperature;
  ph_raise(PhidgetTemperatureSensor_getTemperatureMin(handle, FIX2INT(index), &temperature));
  return rb_float_new(temperature);
}

VALUE ph_temp_get_temperature_max(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double temperature;
  ph_raise(PhidgetTemperatureSensor_getTemperatureMax(handle, FIX2INT(index), &temperature));
  return rb_float_new(temperature);
}

VALUE ph_temp_get_temperature_change_trigger(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double temperature;
  ph_raise(PhidgetTemperatureSensor_getTemperatureChangeTrigger(handle, FIX2INT(index), &temperature));
  return rb_float_new(temperature);
}

VALUE ph_temp_set_temperature_change_trigger(VALUE self, VALUE index, VALUE temperature) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  ph_raise(PhidgetTemperatureSensor_setTemperatureChangeTrigger(handle, FIX2INT(index), NUM2DBL(temperature)));
  return Qnil;
}

VALUE ph_temp_get_potential(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double potential;
  ph_raise(PhidgetTemperatureSensor_getPotential(handle, FIX2INT(index), &potential));
  return rb_float_new(potential);
}

VALUE ph_temp_get_potential_min(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double potential;
  ph_raise(PhidgetTemperatureSensor_getPotentialMin(handle, FIX2INT(index), &potential));
  return rb_float_new(potential);
}

VALUE ph_temp_get_potential_max(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double potential;
  ph_raise(PhidgetTemperatureSensor_getPotentialMax(handle, FIX2INT(index), &potential));
  return rb_float_new(potential);
}

VALUE ph_temp_get_ambient_temperature(VALUE self) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double temperature;
  ph_raise(PhidgetTemperatureSensor_getAmbientTemperature(handle, &temperature));
  return rb_float_new(temperature);
}

VALUE ph_temp_get_ambient_temperature_min(VALUE self) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double temperature;
  ph_raise(PhidgetTemperatureSensor_getAmbientTemperatureMin(handle, &temperature));
  return rb_float_new(temperature);
}

VALUE ph_temp_get_ambient_temperature_max(VALUE self) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  double temperature;
  ph_raise(PhidgetTemperatureSensor_getAmbientTemperatureMax(handle, &temperature));
  return rb_float_new(temperature);
}

VALUE ph_temp_get_thermocouple_type(VALUE self, VALUE index) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  PhidgetTemperatureSensor_ThermocoupleType type;
  ph_raise(PhidgetTemperatureSensor_getThermocoupleType(handle, FIX2INT(index), &type));
  return INT2FIX(type);
}

VALUE ph_temp_set_thermocouple_type(VALUE self, VALUE index, VALUE type) {
  PhidgetTemperatureSensorHandle handle = (PhidgetTemperatureSensorHandle)get_ph_handle(self);
  ph_raise(PhidgetTemperatureSensor_setThermocoupleType(handle, FIX2INT(index), (PhidgetTemperatureSensor_ThermocoupleType)FIX2INT(type)));
  return Qnil;
}


VALUE ph_temp_set_on_temperature_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetTemperatureSensor_set_OnTemperatureChange_Handler((PhidgetTemperatureSensorHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetTemperatureSensor_set_OnTemperatureChange_Handler((PhidgetTemperatureSensorHandle)ph->handle, ph_temp_on_temperature_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_temp_on_temperature_change(PhidgetTemperatureSensorHandle phid, void *userPtr, int index, double temperature) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif
