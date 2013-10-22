
#include "phidgets.h"


VALUE ph_accel_init(VALUE self);
VALUE ph_accel_get_axis_count(VALUE self);
VALUE ph_accel_get_acceleration(VALUE self, VALUE index);
VALUE ph_accel_get_acceleration_min(VALUE self, VALUE index);
VALUE ph_accel_get_acceleration_max(VALUE self, VALUE index);
VALUE ph_accel_get_acceleration_change_trigger(VALUE self, VALUE index);
VALUE ph_accel_set_acceleration_change_trigger(VALUE self, VALUE index, VALUE trigger);

#ifdef PH_CALLBACK
VALUE ph_accel_set_on_acceleration_change_handler(VALUE self, VALUE handler);
int ph_accel_on_acceleration_change(CPhidgetAccelerometerHandle phid, void *userPtr, int index, double accel);
#endif



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
   * call-seq: getAxisCount
   *
   * Gets the number of acceleration axes supported by this accelerometer.
   */
  rb_define_method(ph_accel, "getAxisCount", ph_accel_get_axis_count, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration(index)
   *
   * Gets the current acceleration of an axis.
   */
  rb_define_method(ph_accel, "getAcceleration", ph_accel_get_acceleration, 1);

  /* Document-method: getAccelerationMin
   * call-seq: getAccelerationMin(index)
   *
   * Gets the minimum acceleraiton supported by an axis.
   */
  rb_define_method(ph_accel, "getAccelerationMin", ph_accel_get_acceleration_min, 1);

  /* Document-method: getAccelerationMax
   * call-seq: getAccelerationMax(index)
   *
   * Gets the maximum accleration supported by an axis.
   */
  rb_define_method(ph_accel, "getAccelerationMax", ph_accel_get_acceleration_max, 1);

  /* Document-method: getAccelerationChangeTrigger
   * call-seq: getAccelerationChangeTrigger(index)
   *
   * Gets the change trigger for an axis.
   */
  rb_define_method(ph_accel, "getAccelerationChangeTrigger", ph_accel_get_acceleration_change_trigger, 1);

  /* Document-method: setAccelerationChangeTrigger
   * call-seq: setAccelerationChangeTrigger(index, trigger)
   *
   * Sets the change trigger for an axis.
   */
  rb_define_method(ph_accel, "setAccelerationChangeTrigger", ph_accel_set_acceleration_change_trigger, 2);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_accel, "ext_setOnAccelerationChangeHandler", ph_accel_set_on_acceleration_change_handler, 1);
#endif

  rb_define_alias(ph_accel, "axis_count", "getAxisCount");
  rb_define_alias(ph_accel, "acceleration", "getAcceleration");
  rb_define_alias(ph_accel, "acceleration_min", "getAccelerationMin");
  rb_define_alias(ph_accel, "acceleration_max", "getAccelerationMax");
  rb_define_alias(ph_accel, "acceleration_change_trigger", "getAccelerationChangeTrigger");
  rb_define_alias(ph_accel, "set_acceleration_change_trigger", "setAccelerationChangeTrigger");
}


VALUE ph_accel_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetAccelerometer_create((CPhidgetAccelerometerHandle *)(&(ph->handle))));
  return self;
}


VALUE ph_accel_get_axis_count(VALUE self) {
  CPhidgetAccelerometerHandle handle = (CPhidgetAccelerometerHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetAccelerometer_getAxisCount(handle, &count));
  return INT2FIX(count);
}


VALUE ph_accel_get_acceleration(VALUE self, VALUE index) {
  CPhidgetAccelerometerHandle handle = (CPhidgetAccelerometerHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetAccelerometer_getAcceleration(handle, NUM2INT(index), &accel));
  return rb_float_new(accel);
}


VALUE ph_accel_get_acceleration_min(VALUE self, VALUE index) {
  CPhidgetAccelerometerHandle handle = (CPhidgetAccelerometerHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetAccelerometer_getAccelerationMin(handle, NUM2INT(index), &accel));
  return rb_float_new(accel);
}


VALUE ph_accel_get_acceleration_max(VALUE self, VALUE index) {
  CPhidgetAccelerometerHandle handle = (CPhidgetAccelerometerHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetAccelerometer_getAccelerationMax(handle, NUM2INT(index), &accel));
  return rb_float_new(accel);
}


VALUE ph_accel_get_acceleration_change_trigger(VALUE self, VALUE index) {
  CPhidgetAccelerometerHandle handle = (CPhidgetAccelerometerHandle)get_ph_handle(self);
  double trigger;
  ph_raise(CPhidgetAccelerometer_getAccelerationChangeTrigger(handle, NUM2INT(index), &trigger));
  return rb_float_new(trigger);
}


VALUE ph_accel_set_acceleration_change_trigger(VALUE self, VALUE index, VALUE trigger) {
  CPhidgetAccelerometerHandle handle = (CPhidgetAccelerometerHandle)get_ph_handle(self);
  ph_raise(CPhidgetAccelerometer_setAccelerationChangeTrigger(handle, NUM2INT(index), NUM2DBL(trigger)));
  return Qnil;
}

#ifdef PH_CALLBACK
VALUE ph_accel_set_on_acceleration_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetAccelerometer_set_OnAccelerationChange_Handler((CPhidgetAccelerometerHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetAccelerometer_set_OnAccelerationChange_Handler((CPhidgetAccelerometerHandle)ph->handle, ph_accel_on_acceleration_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_accel_on_acceleration_change(CPhidgetAccelerometerHandle phid, void *userPtr, int index, double accel) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif

