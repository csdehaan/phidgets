
#include "phidgets.h"

#define HUMIDITY_SENSOR_HUMIDITY_CHANGE_CALLBACK    0


VALUE ph_humidity_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetHumiditySensor_create((PhidgetHumiditySensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_humidity_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetHumiditySensor_getDataInterval);
}

VALUE ph_humidity_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetHumiditySensor_setDataInterval((PhidgetHumiditySensorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_humidity_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetHumiditySensor_getMinDataInterval);
}

VALUE ph_humidity_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetHumiditySensor_getMaxDataInterval);
}

VALUE ph_humidity_get_humidity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetHumiditySensor_getHumidity);
}

VALUE ph_humidity_get_min_humidity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetHumiditySensor_getMinHumidity);
}

VALUE ph_humidity_get_max_humidity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetHumiditySensor_getMaxHumidity);
}

VALUE ph_humidity_get_humidity_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetHumiditySensor_getHumidityChangeTrigger);
}

VALUE ph_humidity_set_humidity_change_trigger(VALUE self, VALUE change_trigger) {
  ph_raise(PhidgetHumiditySensor_setHumidityChangeTrigger((PhidgetHumiditySensorHandle)get_ph_handle(self), NUM2DBL(change_trigger)));
  return Qnil;
}

VALUE ph_humidity_get_min_humidity_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetHumiditySensor_getMinHumidityChangeTrigger);
}

VALUE ph_humidity_get_max_humidity_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetHumiditySensor_getMaxHumidityChangeTrigger);
}


void CCONV ph_humidity_on_humidity_change(PhidgetHumiditySensorHandle phid, void *userPtr, double humidity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(humidity);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_humidity_set_on_humidity_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[HUMIDITY_SENSOR_HUMIDITY_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetHumiditySensor_setOnHumidityChangeHandler((PhidgetHumiditySensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetHumiditySensor_setOnHumidityChangeHandler((PhidgetHumiditySensorHandle)ph->handle, ph_humidity_on_humidity_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_humidity() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_humidity = rb_define_class_under(ph_module, "HumiditySensor", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget HumiditySensor object.
   */
  rb_define_method(ph_humidity, "initialize", ph_humidity_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another HumidityChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between HumidityChange events can also affected by the HumidityChangeTrigger.
   */
  rb_define_method(ph_humidity, "getDataInterval", ph_humidity_get_data_interval, 0);
  rb_define_alias(ph_humidity, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another HumidityChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between HumidityChange events can also affected by the HumidityChangeTrigger.
   */
  rb_define_method(ph_humidity, "setDataInterval", ph_humidity_set_data_interval, 1);
  rb_define_alias(ph_humidity, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_humidity, "getMinDataInterval", ph_humidity_get_min_data_interval, 0);
  rb_define_alias(ph_humidity, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_humidity, "getMaxDataInterval", ph_humidity_get_max_data_interval, 0);
  rb_define_alias(ph_humidity, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getHumidity
   * call-seq: getHumidity -> humidity
   *
   * The most recent humidity value that the channel has reported.
   * This value will always be between MinHumidity and MaxHumidity.
   */
  rb_define_method(ph_humidity, "getHumidity", ph_humidity_get_humidity, 0);
  rb_define_alias(ph_humidity, "humidity", "getHumidity");

  /* Document-method: getMinHumidity
   * call-seq: getMinHumidity -> humidity
   *
   * The minimum value that the HumidityChange event will report.
   */
  rb_define_method(ph_humidity, "getMinHumidity", ph_humidity_get_min_humidity, 0);
  rb_define_alias(ph_humidity, "min_humidity", "getMinHumidity");

  /* Document-method: getMaxHumidity
   * call-seq: getMaxHumidity -> humidity
   *
   * The maximum value that the HumidityChange event will report.
   */
  rb_define_method(ph_humidity, "getMaxHumidity", ph_humidity_get_max_humidity, 0);
  rb_define_alias(ph_humidity, "max_humidity", "getMaxHumidity");

  /* Document-method: getHumidityChangeTrigger
   * call-seq: getHumidityChangeTrigger -> change_trigger
   *
   * The channel will not issue a HumidityChange event until the humidity value has changed by the amount specified by the HumidityChangeTrigger.
   * Setting the HumidityChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_humidity, "getHumidityChangeTrigger", ph_humidity_get_humidity_change_trigger, 0);
  rb_define_alias(ph_humidity, "humidity_change_trigger", "getHumidityChangeTrigger");

  /* Document-method: setHumidityChangeTrigger
   * call-seq: setHumidityChangeTrigger(change_trigger)
   *
   * The channel will not issue a HumidityChange event until the humidity value has changed by the amount specified by the HumidityChangeTrigger.
   * Setting the HumidityChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_humidity, "setHumidityChangeTrigger", ph_humidity_set_humidity_change_trigger, 1);
  rb_define_alias(ph_humidity, "humidity_change_trigger=", "setHumidityChangeTrigger");

  /* Document-method: getMinHumidityChangeTrigger
   * call-seq: getMinHumidityChangeTrigger -> change_trigger
   *
   * The minimum value that HumidityChangeTrigger can be set to.
   */
  rb_define_method(ph_humidity, "getMinHumidityChangeTrigger", ph_humidity_get_min_humidity_change_trigger, 0);
  rb_define_alias(ph_humidity, "min_humidity_change_trigger", "getMinHumidityChangeTrigger");

  /* Document-method: getMaxHumidityChangeTrigger
   * call-seq: getMaxHumidityChangeTrigger -> change_trigger
   *
   * The maximum value that HumidityChangeTrigger can be set to.
   */
  rb_define_method(ph_humidity, "getMaxHumidityChangeTrigger", ph_humidity_get_max_humidity_change_trigger, 0);
  rb_define_alias(ph_humidity, "max_humidity_change_trigger", "getMaxHumidityChangeTrigger");


  rb_define_private_method(ph_humidity, "ext_setOnHumidityChangeHandler", ph_humidity_set_on_humidity_change_handler, 1);
}

