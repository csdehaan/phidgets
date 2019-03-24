
#include "phidgets.h"

#define PRESSURE_SENSOR_PRESSURE_CHANGE_CALLBACK    0


VALUE ph_pressure_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetPressureSensor_create((PhidgetPressureSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_pressure_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetPressureSensor_getDataInterval);
}

VALUE ph_pressure_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetPressureSensor_setDataInterval((PhidgetPressureSensorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_pressure_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetPressureSensor_getMinDataInterval);
}

VALUE ph_pressure_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetPressureSensor_getMaxDataInterval);
}

VALUE ph_pressure_get_pressure(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPressureSensor_getPressure);
}

VALUE ph_pressure_get_min_pressure(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPressureSensor_getMinPressure);
}

VALUE ph_pressure_get_max_pressure(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPressureSensor_getMaxPressure);
}

VALUE ph_pressure_get_pressure_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPressureSensor_getPressureChangeTrigger);
}

VALUE ph_pressure_set_pressure_change_trigger(VALUE self, VALUE change_trigger) {
  ph_raise(PhidgetPressureSensor_setPressureChangeTrigger((PhidgetPressureSensorHandle)get_ph_handle(self), NUM2DBL(change_trigger)));
  return Qnil;
}

VALUE ph_pressure_get_min_pressure_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPressureSensor_getMinPressureChangeTrigger);
}

VALUE ph_pressure_get_max_pressure_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPressureSensor_getMaxPressureChangeTrigger);
}


void CCONV ph_pressure_on_pressure_change(PhidgetPressureSensorHandle phid, void *userPtr, double pressure) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(pressure);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_pressure_set_on_pressure_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[PRESSURE_SENSOR_PRESSURE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetPressureSensor_setOnPressureChangeHandler((PhidgetPressureSensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetPressureSensor_setOnPressureChangeHandler((PhidgetPressureSensorHandle)ph->handle, ph_pressure_on_pressure_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_pressure() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_pressure = rb_define_class_under(ph_module, "PressureSensor", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget PressureSensor object.
   */
  rb_define_method(ph_pressure, "initialize", ph_pressure_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another PressureChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between PressureChange events can also affected by the PressureChangeTrigger.
   */
  rb_define_method(ph_pressure, "getDataInterval", ph_pressure_get_data_interval, 0);
  rb_define_alias(ph_pressure, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another PressureChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between PressureChange events can also affected by the PressureChangeTrigger.
   */
  rb_define_method(ph_pressure, "setDataInterval", ph_pressure_set_data_interval, 1);
  rb_define_alias(ph_pressure, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_pressure, "getMinDataInterval", ph_pressure_get_min_data_interval, 0);
  rb_define_alias(ph_pressure, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_pressure, "getMaxDataInterval", ph_pressure_get_max_data_interval, 0);
  rb_define_alias(ph_pressure, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getPressure
   * call-seq: getPressure -> pressure
   *
   * The most recent pressure value that the channel has reported.
   * This value will always be between MinPressure and MaxPressure.
   */
  rb_define_method(ph_pressure, "getPressure", ph_pressure_get_pressure, 0);
  rb_define_alias(ph_pressure, "pressure", "getPressure");

  /* Document-method: getMinPressure
   * call-seq: getMinPressure -> pressure
   *
   * The minimum value that the PressureChange event will report.
   */
  rb_define_method(ph_pressure, "getMinPressure", ph_pressure_get_min_pressure, 0);
  rb_define_alias(ph_pressure, "min_pressure", "getMinPressure");

  /* Document-method: getMaxPressure
   * call-seq: getMaxPressure -> pressure
   *
   * The maximum value that the PressureChange event will report.
   */
  rb_define_method(ph_pressure, "getMaxPressure", ph_pressure_get_max_pressure, 0);
  rb_define_alias(ph_pressure, "max_pressure", "getMaxPressure");

  /* Document-method: getPressureChangeTrigger
   * call-seq: getPressureChangeTrigger -> change_trigger
   *
   * The channel will not issue a PressureChange event until the pressure value has changed by the amount specified by the PressureChangeTrigger.
   * Setting the PressureChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_pressure, "getPressureChangeTrigger", ph_pressure_get_pressure_change_trigger, 0);
  rb_define_alias(ph_pressure, "pressure_change_trigger", "getPressureChangeTrigger");

  /* Document-method: setPressureChangeTrigger
   * call-seq: setPressureChangeTrigger(change_trigger)
   *
   * The channel will not issue a PressureChange event until the pressure value has changed by the amount specified by the PressureChangeTrigger.
   * Setting the PressureChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_pressure, "setPressureChangeTrigger", ph_pressure_set_pressure_change_trigger, 1);
  rb_define_alias(ph_pressure, "pressure_change_trigger=", "setPressureChangeTrigger");

  /* Document-method: getMinPressureChangeTrigger
   * call-seq: getMinPressureChangeTrigger -> change_trigger
   *
   * The minimum value that PressureChangeTrigger can be set to.
   */
  rb_define_method(ph_pressure, "getMinPressureChangeTrigger", ph_pressure_get_min_pressure_change_trigger, 0);
  rb_define_alias(ph_pressure, "min_pressure_change_trigger", "getMinPressureChangeTrigger");

  /* Document-method: getMaxPressureChangeTrigger
   * call-seq: getMaxPressureChangeTrigger -> change_trigger
   *
   * The maximum value that PressureChangeTrigger can be set to.
   */
  rb_define_method(ph_pressure, "getMaxPressureChangeTrigger", ph_pressure_get_max_pressure_change_trigger, 0);
  rb_define_alias(ph_pressure, "max_pressure_change_trigger", "getMaxPressureChangeTrigger");


  rb_define_private_method(ph_pressure, "ext_setOnPressureChangeHandler", ph_pressure_set_on_pressure_change_handler, 1);
}

