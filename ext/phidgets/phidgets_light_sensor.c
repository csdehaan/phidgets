
#include "phidgets.h"

#define LIGHT_SENSOR_ILLUMINANCE_CHANGE_CALLBACK    0


VALUE ph_light_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetLightSensor_create((PhidgetLightSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_light_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetLightSensor_getDataInterval);
}

VALUE ph_light_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetLightSensor_setDataInterval((PhidgetLightSensorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_light_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetLightSensor_getMinDataInterval);
}

VALUE ph_light_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetLightSensor_getMaxDataInterval);
}

VALUE ph_light_get_illuminance(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLightSensor_getIlluminance);
}

VALUE ph_light_get_min_illuminance(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLightSensor_getMinIlluminance);
}

VALUE ph_light_get_max_illuminance(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLightSensor_getMaxIlluminance);
}

VALUE ph_light_get_illuminance_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLightSensor_getIlluminanceChangeTrigger);
}

VALUE ph_light_set_illuminance_change_trigger(VALUE self, VALUE change_trigger) {
  ph_raise(PhidgetLightSensor_setIlluminanceChangeTrigger((PhidgetLightSensorHandle)get_ph_handle(self), NUM2DBL(change_trigger)));
  return Qnil;
}

VALUE ph_light_get_min_illuminance_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLightSensor_getMinIlluminanceChangeTrigger);
}

VALUE ph_light_get_max_illuminance_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetLightSensor_getMaxIlluminanceChangeTrigger);
}


void CCONV ph_light_on_illuminance_change(PhidgetLightSensorHandle phid, void *userPtr, double illuminance) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(illuminance);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_light_set_on_illuminance_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[LIGHT_SENSOR_ILLUMINANCE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetLightSensor_setOnIlluminanceChangeHandler((PhidgetLightSensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetLightSensor_setOnIlluminanceChangeHandler((PhidgetLightSensorHandle)ph->handle, ph_light_on_illuminance_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_light() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_light = rb_define_class_under(ph_module, "LightSensor", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget LightSensor object.
   */
  rb_define_method(ph_light, "initialize", ph_light_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another IlluminanceChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between IlluminanceChange events can also affected by the IlluminanceChangeTrigger.
   */
  rb_define_method(ph_light, "getDataInterval", ph_light_get_data_interval, 0);
  rb_define_alias(ph_light, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another IlluminanceChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between IlluminanceChange events can also affected by the IlluminanceChangeTrigger.
   */
  rb_define_method(ph_light, "setDataInterval", ph_light_set_data_interval, 1);
  rb_define_alias(ph_light, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_light, "getMinDataInterval", ph_light_get_min_data_interval, 0);
  rb_define_alias(ph_light, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_light, "getMaxDataInterval", ph_light_get_max_data_interval, 0);
  rb_define_alias(ph_light, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getIlluminance
   * call-seq: getIlluminance -> illuminance
   *
   * The most recent illuminance value that the channel has reported.
   * This value will always be between MinIlluminance and MaxIlluminance.
   */
  rb_define_method(ph_light, "getIlluminance", ph_light_get_illuminance, 0);
  rb_define_alias(ph_light, "illuminance", "getIlluminance");

  /* Document-method: getMinIlluminance
   * call-seq: getMinIlluminance -> illuminance
   *
   * The minimum value that the IlluminanceChange event will report.
   */
  rb_define_method(ph_light, "getMinIlluminance", ph_light_get_min_illuminance, 0);
  rb_define_alias(ph_light, "min_illuminance", "getMinIlluminance");

  /* Document-method: getMaxIlluminance
   * call-seq: getMaxIlluminance -> illuminance
   *
   * The maximum value that the IlluminanceChange event will report.
   */
  rb_define_method(ph_light, "getMaxIlluminance", ph_light_get_max_illuminance, 0);
  rb_define_alias(ph_light, "max_illuminance", "getMaxIlluminance");

  /* Document-method: getIlluminanceChangeTrigger
   * call-seq: getIlluminanceChangeTrigger -> change_trigger
   *
   * The channel will not issue a IlluminanceChange event until the illuminance value has changed by the amount specified by the IlluminanceChangeTrigger.
   * Setting the IlluminanceChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_light, "getIlluminanceChangeTrigger", ph_light_get_illuminance_change_trigger, 0);
  rb_define_alias(ph_light, "illuminance_change_trigger", "getIlluminanceChangeTrigger");

  /* Document-method: setIlluminanceChangeTrigger
   * call-seq: setIlluminanceChangeTrigger(change_trigger)
   *
   * The channel will not issue a IlluminanceChange event until the illuminance value has changed by the amount specified by the IlluminanceChangeTrigger.
   * Setting the IlluminanceChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_light, "setIlluminanceChangeTrigger", ph_light_set_illuminance_change_trigger, 1);
  rb_define_alias(ph_light, "illuminance_change_trigger=", "setIlluminanceChangeTrigger");

  /* Document-method: getMinIlluminanceChangeTrigger
   * call-seq: getMinIlluminanceChangeTrigger -> change_trigger
   *
   * The minimum value that IlluminanceChangeTrigger can be set to.
   */
  rb_define_method(ph_light, "getMinIlluminanceChangeTrigger", ph_light_get_min_illuminance_change_trigger, 0);
  rb_define_alias(ph_light, "min_illuminance_change_trigger", "getMinIlluminanceChangeTrigger");

  /* Document-method: getMaxIlluminanceChangeTrigger
   * call-seq: getMaxIlluminanceChangeTrigger -> change_trigger
   *
   * The maximum value that IlluminanceChangeTrigger can be set to.
   */
  rb_define_method(ph_light, "getMaxIlluminanceChangeTrigger", ph_light_get_max_illuminance_change_trigger, 0);
  rb_define_alias(ph_light, "max_illuminance_change_trigger", "getMaxIlluminanceChangeTrigger");


  rb_define_private_method(ph_light, "ext_setOnIlluminanceChangeHandler", ph_light_set_on_illuminance_change_handler, 1);
}

