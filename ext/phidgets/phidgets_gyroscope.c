
#include "phidgets.h"

#define GYROSCOPE_ANGULAR_RATE_UPDATE_CALLBACK  0


VALUE ph_gyroscope_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetGyroscope_create((PhidgetGyroscopeHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_gyroscope_get_angular_rate(VALUE self) {
  PhidgetGyroscopeHandle handle = (PhidgetGyroscopeHandle)get_ph_handle(self);
  double angular_rate[3];
  ph_raise(PhidgetGyroscope_getAngularRate((PhidgetGyroscopeHandle)get_ph_handle(self), &angular_rate));
  return rb_ary_new3(3, DBL2NUM(angular_rate[0]), DBL2NUM(angular_rate[1]), DBL2NUM(angular_rate[2]));
}

VALUE ph_gyroscope_get_min_angular_rate(VALUE self) {
  PhidgetGyroscopeHandle handle = (PhidgetGyroscopeHandle)get_ph_handle(self);
  double angular_rate[3];
  ph_raise(PhidgetGyroscope_getMinAngularRate((PhidgetGyroscopeHandle)get_ph_handle(self), &angular_rate));
  return rb_ary_new3(3, DBL2NUM(angular_rate[0]), DBL2NUM(angular_rate[1]), DBL2NUM(angular_rate[2]));
}

VALUE ph_gyroscope_get_max_angular_rate(VALUE self) {
  PhidgetGyroscopeHandle handle = (PhidgetGyroscopeHandle)get_ph_handle(self);
  double angular_rate[3];
  ph_raise(PhidgetGyroscope_getMaxAngularRate((PhidgetGyroscopeHandle)get_ph_handle(self), &angular_rate));
  return rb_ary_new3(3, DBL2NUM(angular_rate[0]), DBL2NUM(angular_rate[1]), DBL2NUM(angular_rate[2]));
}

VALUE ph_gyroscope_get_axis_count(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetGyroscope_getAxisCount);
}

VALUE ph_gyroscope_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetGyroscope_getDataInterval);
}

VALUE ph_gyroscope_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetGyroscope_setDataInterval((PhidgetGyroscopeHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_gyroscope_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetGyroscope_getMinDataInterval);
}

VALUE ph_gyroscope_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetGyroscope_getMaxDataInterval);
}

VALUE ph_gyroscope_get_timestamp(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetGyroscope_getTimestamp);
}

VALUE ph_gyroscope_zero(VALUE self) {
  ph_raise(PhidgetGyroscope_zero((PhidgetGyroscopeHandle)get_ph_handle(self)));
  return Qnil;
}


void CCONV ph_gyroscope_on_angular_rate_update(PhidgetGyroscopeHandle phid, void *userPtr, const double angularRate[3], double timestamp) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = rb_ary_new3(3, DBL2NUM(angularRate[0]), DBL2NUM(angularRate[1]), DBL2NUM(angularRate[2]));
  callback_data->arg2 = DBL2NUM(timestamp);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_gyroscope_set_on_angular_rate_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[GYROSCOPE_ANGULAR_RATE_UPDATE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetGyroscope_setOnAngularRateUpdateHandler((PhidgetGyroscopeHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetGyroscope_setOnAngularRateUpdateHandler((PhidgetGyroscopeHandle)ph->handle, ph_gyroscope_on_angular_rate_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_gyroscope() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_gyroscope = rb_define_class_under(ph_module, "Gyroscope", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Gyroscope object.
   */
  rb_define_method(ph_gyroscope, "initialize", ph_gyroscope_init, 0);

  /* Document-method: getAngularRate
   * call-seq: getAngularRate -> angular_rate
   *
   * The most recent angular rate value that the channel has reported.
   * This value will always be between MinAngularRate and MaxAngularRate.
   */
  rb_define_method(ph_gyroscope, "getAngularRate", ph_gyroscope_get_angular_rate, 0);
  rb_define_alias(ph_gyroscope, "angular_rate", "getAngularRate");

  /* Document-method: getMinAngularRate
   * call-seq: getMinAngularRate -> angular_rate
   *
   * The minimum value the AngularRateUpdate event will report.
   */
  rb_define_method(ph_gyroscope, "getMinAngularRate", ph_gyroscope_get_min_angular_rate, 0);
  rb_define_alias(ph_gyroscope, "min_angular_rate", "getMinAngularRate");

  /* Document-method: getMaxAngularRate
   * call-seq: getMaxAngularRate -> angular_rate
   *
   * The maximum value the AngularRateUpdate event will report.
   */
  rb_define_method(ph_gyroscope, "getMaxAngularRate", ph_gyroscope_get_max_angular_rate, 0);
  rb_define_alias(ph_gyroscope, "max_angular_rate", "getMaxAngularRate");

  /* Document-method: getAxisCount
   * call-seq: getAxisCount -> axis_count
   *
   * The number of axes the channel can measure angular rate on.
   * See your device's User Guide for more information about the number of axes and their orientation.
   */
  rb_define_method(ph_gyroscope, "getAxisCount", ph_gyroscope_get_axis_count, 0);
  rb_define_alias(ph_gyroscope, "axis_count", "getAxisCount");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another AngularRateUpdate event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_gyroscope, "getDataInterval", ph_gyroscope_get_data_interval, 0);
  rb_define_alias(ph_gyroscope, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another AngularRateUpdate event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_gyroscope, "setDataInterval", ph_gyroscope_set_data_interval, 1);
  rb_define_alias(ph_gyroscope, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_gyroscope, "getMinDataInterval", ph_gyroscope_get_min_data_interval, 0);
  rb_define_alias(ph_gyroscope, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_gyroscope, "getMaxDataInterval", ph_gyroscope_get_max_data_interval, 0);
  rb_define_alias(ph_gyroscope, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getTimestamp
   * call-seq: getTimestamp -> timestamp
   *
   * The most recent timestamp value that the channel has reported. This is an extremely accurate time measurement streamed from the device.
   * If your application requires a time measurement, you should use this value over a local software timestamp.
   */
  rb_define_method(ph_gyroscope, "getTimestamp", ph_gyroscope_get_timestamp, 0);
  rb_define_alias(ph_gyroscope, "timestamp", "getTimestamp");

  /* Document-method: zero
   * call-seq: zero
   *
   * Re-zeros the gyroscope in 1-2 seconds.
   * The device must be stationary when zeroing.
   * The angular rate will be reported as 0.0°/s while zeroing.
   * Zeroing the gyroscope is a method of compensating for the drift that is inherent to all gyroscopes. See your device's User Guide for more information on dealing with drift.
   */
  rb_define_method(ph_gyroscope, "zero", ph_gyroscope_zero, 0);
  rb_define_alias(ph_gyroscope, "zero", "zero");


  rb_define_private_method(ph_gyroscope, "ext_setOnAngularRateUpdateHandler", ph_gyroscope_set_on_angular_rate_update_handler, 1);
}

