
#include "phidgets.h"

#define ACCELEROMETER_ACCELERATION_CHANGE_CALLBACK  0


VALUE ph_accel_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetAccelerometer_create((PhidgetAccelerometerHandle *)(&(ph->handle))));
  return self;
}


VALUE ph_accel_get_axis_count(VALUE self) {
  return ph_get_int(get_ph_handle(self), PhidgetAccelerometer_getAxisCount);
}


VALUE ph_accel_get_acceleration(VALUE self) {
  double accel[3];
  ph_raise(PhidgetAccelerometer_getAcceleration((PhidgetAccelerometerHandle)get_ph_handle(self), &accel));
  return rb_ary_new3(3, DBL2NUM(accel[0]), DBL2NUM(accel[1]), DBL2NUM(accel[2]));
}


VALUE ph_accel_get_min_acceleration(VALUE self) {
  double accel[3];
  ph_raise(PhidgetAccelerometer_getMinAcceleration((PhidgetAccelerometerHandle)get_ph_handle(self), &accel));
  return rb_ary_new3(3, DBL2NUM(accel[0]), DBL2NUM(accel[1]), DBL2NUM(accel[2]));
}


VALUE ph_accel_get_max_acceleration(VALUE self) {
  double accel[3];
  ph_raise(PhidgetAccelerometer_getMaxAcceleration((PhidgetAccelerometerHandle)get_ph_handle(self), &accel));
  return rb_ary_new3(3, DBL2NUM(accel[0]), DBL2NUM(accel[1]), DBL2NUM(accel[2]));
}


VALUE ph_accel_get_acceleration_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetAccelerometer_getAccelerationChangeTrigger);
}


VALUE ph_accel_set_acceleration_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetAccelerometer_setAccelerationChangeTrigger((PhidgetAccelerometerHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}


VALUE ph_accel_get_min_acceleration_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetAccelerometer_getMinAccelerationChangeTrigger);
}


VALUE ph_accel_get_max_acceleration_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetAccelerometer_getMaxAccelerationChangeTrigger);
}


VALUE ph_accel_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetAccelerometer_getDataInterval);
}


VALUE ph_accel_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetAccelerometer_setDataInterval((PhidgetAccelerometerHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}


VALUE ph_accel_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetAccelerometer_getMinDataInterval);
}


VALUE ph_accel_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetAccelerometer_getMaxDataInterval);
}


VALUE ph_accel_get_timestamp(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetAccelerometer_getTimestamp);
}


void CCONV ph_accel_on_acceleration_change(PhidgetAccelerometerHandle phid, void *userPtr, const double accel[3], double timestamp) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = rb_ary_new3(3, DBL2NUM(accel[0]), DBL2NUM(accel[1]), DBL2NUM(accel[2]));
  callback_data->arg2 = DBL2NUM(timestamp);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_accel_set_on_acceleration_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[ACCELEROMETER_ACCELERATION_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetAccelerometer_setOnAccelerationChangeHandler((PhidgetAccelerometerHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetAccelerometer_setOnAccelerationChangeHandler((PhidgetAccelerometerHandle)ph->handle, ph_accel_on_acceleration_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}



void Init_accelerometer() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_accel = rb_define_class_under(ph_module, "Accelerometer", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Accelerometer object.
   */
  rb_define_method(ph_accel, "initialize", ph_accel_init, 0);

  /* Document-method: getAxisCount
   * call-seq: getAxisCount -> axis_count
   *
   * The number of axes the channel can measure acceleration on.
   * See your device's User Guide for more information about the number of axes and their orientation.
   */
  rb_define_method(ph_accel, "getAxisCount", ph_accel_get_axis_count, 0);
  rb_define_alias(ph_accel, "axis_count", "getAxisCount");

  /* Document-method: getAcceleration
   * call-seq: getAcceleration -> acceleration
   *
   * The most recent acceleration value that the channel has reported.
   * This value will always be between MinAcceleration and MaxAcceleration.
   */
  rb_define_method(ph_accel, "getAcceleration", ph_accel_get_acceleration, 0);
  rb_define_alias(ph_accel, "acceleration", "getAcceleration");

  /* Document-method: getMinAcceleration
   * call-seq: getMinAcceleration -> min_acceleration
   *
   * The minimum value the AccelerationChange event will report.
   */
  rb_define_method(ph_accel, "getMinAcceleration", ph_accel_get_min_acceleration, 0);
  rb_define_alias(ph_accel, "min_acceleration", "getMinAcceleration");

  /* Document-method: getMaxAcceleration
   * call-seq: getMaxAcceleration -> max_acceleration
   *
   * The maximum value the AccelerationChange event will report.
   */
  rb_define_method(ph_accel, "getMaxAcceleration", ph_accel_get_max_acceleration, 0);
  rb_define_alias(ph_accel, "max_acceleration", "getMaxAcceleration");

  /* Document-method: getAccelerationChangeTrigger
   * call-seq: getAccelerationChangeTrigger -> trigger
   *
   * The channel will not issue a AccelerationChange event until the acceleration value has changed
   * by the amount specified by the AccelerationChangeTrigger.
   * Setting the AccelerationChangeTrigger to 0 will result in the channel firing events every DataInterval.
   * This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_accel, "getAccelerationChangeTrigger", ph_accel_get_acceleration_change_trigger, 0);
  rb_define_alias(ph_accel, "acceleration_change_trigger", "getAccelerationChangeTrigger");

  /* Document-method: setAccelerationChangeTrigger
   * call-seq: setAccelerationChangeTrigger(trigger)
   *
   * The channel will not issue a AccelerationChange event until the acceleration value has changed
   * by the amount specified by the AccelerationChangeTrigger.
   * Setting the AccelerationChangeTrigger to 0 will result in the channel firing events every DataInterval.
   * This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_accel, "setAccelerationChangeTrigger", ph_accel_set_acceleration_change_trigger, 1);
  rb_define_alias(ph_accel, "acceleration_change_trigger=", "setAccelerationChangeTrigger");

  /* Document-method: getMinAccelerationChangeTrigger
   * call-seq: getMinAccelerationChangeTrigger -> trigger
   *
   * The minimum value that AccelerationChangeTrigger can be set to.
   */
  rb_define_method(ph_accel, "getMinAccelerationChangeTrigger", ph_accel_get_min_acceleration_change_trigger, 0);
  rb_define_alias(ph_accel, "min_acceleration_change_trigger", "getMinAccelerationChangeTrigger");

  /* Document-method: getMaxAccelerationChangeTrigger
   * call-seq: getMaxAccelerationChangeTrigger -> trigger
   *
   * The maximum value that AccelerationChangeTrigger can be set to.
   */
  rb_define_method(ph_accel, "getMaxAccelerationChangeTrigger", ph_accel_get_max_acceleration_change_trigger, 0);
  rb_define_alias(ph_accel, "max_acceleration_change_trigger", "getMaxAccelerationChangeTrigger");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another Phidget_OnAccelerationChangeCallback event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between AccelerationChange events can also be affected by the AccelerationChangeTrigger.
   */
  rb_define_method(ph_accel, "getDataInterval", ph_accel_get_data_interval, 0);
  rb_define_alias(ph_accel, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another Phidget_OnAccelerationChangeCallback event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between AccelerationChange events can also be affected by the AccelerationChangeTrigger.
   */
  rb_define_method(ph_accel, "setDataInterval", ph_accel_set_data_interval, 1);
  rb_define_alias(ph_accel, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_accel, "getMinDataInterval", ph_accel_get_min_data_interval, 0);
  rb_define_alias(ph_accel, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_accel, "getMaxDataInterval", ph_accel_get_max_data_interval, 0);
  rb_define_alias(ph_accel, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getTimestamp
   * call-seq: getTimestamp -> timestamp
   *
   * The most recent timestamp value that the channel has reported. This is an extremely accurate time measurement streamed from the device.
   * If your application requires a time measurement, you should use this value over a local software timestamp.
   */
  rb_define_method(ph_accel, "getTimestamp", ph_accel_get_timestamp, 0);
  rb_define_alias(ph_accel, "timestamp", "getTimestamp");

  rb_define_private_method(ph_accel, "ext_setOnAccelerationChangeHandler", ph_accel_set_on_acceleration_change_handler, 1);
}

