
#include "phidgets.h"

#define TEMP_SENSOR_TEMPERATURE_CHANGE_CALLBACK  0


VALUE ph_temp_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetTemperatureSensor_create((PhidgetTemperatureSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_temp_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetTemperatureSensor_getDataInterval);
}

VALUE ph_temp_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetTemperatureSensor_setDataInterval((PhidgetTemperatureSensorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_temp_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetTemperatureSensor_getMinDataInterval);
}

VALUE ph_temp_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetTemperatureSensor_getMaxDataInterval);
}

VALUE ph_temp_get_rtd_type(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetTemperatureSensor_getRTDType);
}

VALUE ph_temp_set_rtd_type(VALUE self, VALUE rtd_type) {
  ph_raise(PhidgetTemperatureSensor_setRTDType((PhidgetTemperatureSensorHandle)get_ph_handle(self), NUM2INT(rtd_type)));
  return Qnil;
}

VALUE ph_temp_get_rtd_wire_setup(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetTemperatureSensor_getRTDWireSetup);
}

VALUE ph_temp_set_rtd_wire_setup(VALUE self, VALUE wire_setup) {
  ph_raise(PhidgetTemperatureSensor_setRTDWireSetup((PhidgetTemperatureSensorHandle)get_ph_handle(self), NUM2INT(wire_setup)));
  return Qnil;
}

VALUE ph_temp_get_temperature(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetTemperatureSensor_getTemperature);
}

VALUE ph_temp_get_min_temperature(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetTemperatureSensor_getMinTemperature);
}

VALUE ph_temp_get_max_temperature(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetTemperatureSensor_getMaxTemperature);
}

VALUE ph_temp_get_temperature_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetTemperatureSensor_getTemperatureChangeTrigger);
}

VALUE ph_temp_set_temperature_change_trigger(VALUE self, VALUE temperature) {
  ph_raise(PhidgetTemperatureSensor_setTemperatureChangeTrigger((PhidgetTemperatureSensorHandle)get_ph_handle(self), NUM2DBL(temperature)));
  return Qnil;
}

VALUE ph_temp_get_min_temperature_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetTemperatureSensor_getMinTemperatureChangeTrigger);
}

VALUE ph_temp_get_max_temperature_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetTemperatureSensor_getMaxTemperatureChangeTrigger);
}

VALUE ph_temp_get_thermocouple_type(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetTemperatureSensor_getThermocoupleType);
}

VALUE ph_temp_set_thermocouple_type(VALUE self, VALUE type) {
  ph_raise(PhidgetTemperatureSensor_setThermocoupleType((PhidgetTemperatureSensorHandle)get_ph_handle(self), (PhidgetTemperatureSensor_ThermocoupleType)NUM2INT(type)));
  return Qnil;
}


void CCONV ph_temp_on_temperature_change(PhidgetTemperatureSensorHandle phid, void *userPtr, double temperature) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(temperature);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_temp_set_on_temperature_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[TEMP_SENSOR_TEMPERATURE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetTemperatureSensor_setOnTemperatureChangeHandler((PhidgetTemperatureSensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetTemperatureSensor_setOnTemperatureChangeHandler((PhidgetTemperatureSensorHandle)ph->handle, ph_temp_on_temperature_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_temperature_sensor() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_temp = rb_define_class_under(ph_module, "TemperatureSensor", ph_common);

  rb_define_const(ph_temp, "RTD_TYPE_PT100_3850", INT2NUM(RTD_TYPE_PT100_3850));
  rb_define_const(ph_temp, "RTD_TYPE_PT1000_3850", INT2NUM(RTD_TYPE_PT1000_3850));
  rb_define_const(ph_temp, "RTD_TYPE_PT100_3920", INT2NUM(RTD_TYPE_PT100_3920));
  rb_define_const(ph_temp, "RTD_TYPE_PT1000_3920", INT2NUM(RTD_TYPE_PT1000_3920));

  rb_define_const(ph_temp, "THERMOCOUPLE_TYPE_K", INT2NUM(THERMOCOUPLE_TYPE_K));
  rb_define_const(ph_temp, "THERMOCOUPLE_TYPE_J", INT2NUM(THERMOCOUPLE_TYPE_J));
  rb_define_const(ph_temp, "THERMOCOUPLE_TYPE_E", INT2NUM(THERMOCOUPLE_TYPE_E));
  rb_define_const(ph_temp, "THERMOCOUPLE_TYPE_T", INT2NUM(THERMOCOUPLE_TYPE_T));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget TemperatureSensor object.
   */
  rb_define_method(ph_temp, "initialize", ph_temp_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another TemperatureChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between TemperatureChange events can also affected by the TemperatureChangeTrigger.
   */
  rb_define_method(ph_temp, "getDataInterval", ph_temp_get_data_interval, 0);
  rb_define_alias(ph_temp, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another TemperatureChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between TemperatureChange events can also affected by the TemperatureChangeTrigger.
   */
  rb_define_method(ph_temp, "setDataInterval", ph_temp_set_data_interval, 1);
  rb_define_alias(ph_temp, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_temp, "getMinDataInterval", ph_temp_get_min_data_interval, 0);
  rb_define_alias(ph_temp, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_temp, "getMaxDataInterval", ph_temp_get_max_data_interval, 0);
  rb_define_alias(ph_temp, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getRTDType
   * call-seq: getRTDType -> rtd_type
   *
   * The RTDType must correspond to the RTD type you are using in your application.
   * If you are unsure which RTDType to use, visit your device's User Guide for more information.
   */
  rb_define_method(ph_temp, "getRTDType", ph_temp_get_rtd_type, 0);
  rb_define_alias(ph_temp, "rtd_type", "getRTDType");

  /* Document-method: setRTDType
   * call-seq: setRTDType(rtd_type)
   *
   * The RTDType must correspond to the RTD type you are using in your application.
   * If you are unsure which RTDType to use, visit your device's User Guide for more information.
   */
  rb_define_method(ph_temp, "setRTDType", ph_temp_set_rtd_type, 1);
  rb_define_alias(ph_temp, "rtd_type=", "setRTDType");

  /* Document-method: getRTDWireSetup
   * call-seq: getRTDWireSetup -> wire_setup
   *
   * The RTDWireSetup must correspond to the wire configuration you are using in your application.
   * If you are unsure which RTDWireSetup to use, visit your device's User Guide for more information.
   */
  rb_define_method(ph_temp, "getRTDWireSetup", ph_temp_get_rtd_wire_setup, 0);
  rb_define_alias(ph_temp, "rtd_wire_setup", "getRTDWireSetup");

  /* Document-method: setRTDWireSetup
   * call-seq: setRTDWireSetup(wire_setup)
   *
   * The RTDWireSetup must correspond to the wire configuration you are using in your application.
   * If you are unsure which RTDWireSetup to use, visit your device's User Guide for more information.
   */
  rb_define_method(ph_temp, "setRTDWireSetup", ph_temp_set_rtd_wire_setup, 1);
  rb_define_alias(ph_temp, "rtd_wire_setup=", "setRTDWireSetup");

  /* Document-method: getTemperature
   * call-seq: getTemperature -> temperature
   *
   * The most recent temperature value that the channel has reported.
   * This value will always be between MinTemperature and MaxTemperature.
   */
  rb_define_method(ph_temp, "getTemperature", ph_temp_get_temperature, 0);
  rb_define_alias(ph_temp, "temperature", "getTemperature");

  /* Document-method: getMinTemperature
   * call-seq: getMinTemperature -> temperature
   *
   * The minimum value the TemperatureChange event will report.
   */
  rb_define_method(ph_temp, "getMinTemperature", ph_temp_get_min_temperature, 0);
  rb_define_alias(ph_temp, "min_temperature", "getMinTemperature");

  /* Document-method: getMaxTemperature
   * call-seq: getMaxTemperature -> temperature
   *
   * The maximum value the TemperatureChange event will report.
   */
  rb_define_method(ph_temp, "getMaxTemperature", ph_temp_get_max_temperature, 0);
  rb_define_alias(ph_temp, "max_temperature", "getMaxTemperature");

  /* Document-method: getTemperatureChangeTrigger
   * call-seq: getTemperatureChangeTrigger -> trigger
   *
   * The channel will not issue a TemperatureChange event until the temperature value has changed by the amount specified by the TemperatureChangeTrigger.
   * Setting the TemperatureChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_temp, "getTemperatureChangeTrigger", ph_temp_get_temperature_change_trigger, 0);
  rb_define_alias(ph_temp, "temperature_change_trigger", "getTemperatureChangeTrigger");

  /* Document-method: setTemperatureChangeTrigger
   * call-seq: setTemperatureChangeTrigger(trigger)
   *
   * The channel will not issue a TemperatureChange event until the temperature value has changed by the amount specified by the TemperatureChangeTrigger.
   * Setting the TemperatureChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_temp, "setTemperatureChangeTrigger", ph_temp_set_temperature_change_trigger, 1);
  rb_define_alias(ph_temp, "temperature_change_trigger=", "setTemperatureChangeTrigger");

  /* Document-method: getMinTemperatureChangeTrigger
   * call-seq: getMinTemperatureChangeTrigger -> trigger
   *
   * The minimum value that TemperatureChangeTrigger can be set to.
   */
  rb_define_method(ph_temp, "getMinTemperatureChangeTrigger", ph_temp_get_min_temperature_change_trigger, 0);
  rb_define_alias(ph_temp, "min_temperature_change_trigger", "getMinTemperatureChangeTrigger");

  /* Document-method: getMaxTemperatureChangeTrigger
   * call-seq: getMaxTemperatureChangeTrigger -> trigger
   *
   * The maximum value that TemperatureChangeTrigger can be set to.
   */
  rb_define_method(ph_temp, "getMaxTemperatureChangeTrigger", ph_temp_get_max_temperature_change_trigger, 0);
  rb_define_alias(ph_temp, "max_temperature_change_trigger", "getMaxTemperatureChangeTrigger");

  /* Document-method: getThermocoupleType
   * call-seq: getThermocoupleType -> type
   *
   * The ThermocoupleType must correspond to the thermocouple type you are using in your application.
   * If you are unsure which ThermocoupleType to use, visit the Thermocouple Primer for more information.
   */
  rb_define_method(ph_temp, "getThermocoupleType", ph_temp_get_thermocouple_type, 0);
  rb_define_alias(ph_temp, "thermocouple_type", "getThermocoupleType");

  /* Document-method: setThermocoupleType
   * call-seq: setThermocoupleType(type)
   *
   * The ThermocoupleType must correspond to the thermocouple type you are using in your application.
   * If you are unsure which ThermocoupleType to use, visit the Thermocouple Primer for more information.
   */
  rb_define_method(ph_temp, "setThermocoupleType", ph_temp_set_thermocouple_type, 1);
  rb_define_alias(ph_temp, "thermocouple_type=", "setThermocoupleType");

  rb_define_private_method(ph_temp, "ext_setOnTemperatureChangeHandler", ph_temp_set_on_temperature_change_handler, 1);
}

