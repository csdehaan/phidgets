
#include "phidgets.h"

#if 0
VALUE ph_spatial_init(VALUE self);
VALUE ph_spatial_get_acceleration_axis_count(VALUE self);
VALUE ph_spatial_get_gyro_axis_count(VALUE self);
VALUE ph_spatial_get_compass_axis_count(VALUE self);
VALUE ph_spatial_get_acceleration(VALUE self, VALUE index);
VALUE ph_spatial_get_acceleration_min(VALUE self, VALUE index);
VALUE ph_spatial_get_acceleration_max(VALUE self, VALUE index);
VALUE ph_spatial_get_angular_rate(VALUE self, VALUE index);
VALUE ph_spatial_get_angular_rate_min(VALUE self, VALUE index);
VALUE ph_spatial_get_angular_rate_max(VALUE self, VALUE index);
VALUE ph_spatial_get_magnetic_field(VALUE self, VALUE index);
VALUE ph_spatial_get_magnetic_field_min(VALUE self, VALUE index);
VALUE ph_spatial_get_magnetic_field_max(VALUE self, VALUE index);
VALUE ph_spatial_get_data_rate(VALUE self);
VALUE ph_spatial_get_data_rate_min(VALUE self);
VALUE ph_spatial_get_data_rate_max(VALUE self);
VALUE ph_spatial_set_data_rate(VALUE self, VALUE rate);
VALUE ph_spatial_zero_gyro(VALUE self);
VALUE ph_spatial_set_compass_correction_parameters(VALUE self, VALUE mag_field, VALUE offset0, VALUE offset1, VALUE offset2, VALUE gain0, VALUE gain1, VALUE gain2, VALUE T0, VALUE T1, VALUE T2, VALUE T3, VALUE T4, VALUE T5);
VALUE ph_spatial_reset_compass_correction_parameters(VALUE self);

VALUE ph_spatial_set_on_spatial_data_handler(VALUE self, VALUE handler);
int ph_spatial_on_spatial_data(PhidgetSpatialHandle phid, void *userPtr, PhidgetSpatial_SpatialEventDataHandle *data, int data_count);


void Init_spatial() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_spatial = rb_define_class_under(ph_module, "Spatial", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Spatial object.
   */
  rb_define_method(ph_spatial, "initialize", ph_spatial_init, 0);

  /* Document-method: getAccelerationAxisCount
   * call-seq: getAccelerationAxisCount -> count
   *
   * Gets the number of acceleration axes supplied by this board.
   */
  rb_define_method(ph_spatial, "getAccelerationAxisCount", ph_spatial_get_acceleration_axis_count, 0);

  /* Document-method: getGyroAxisCount
   * call-seq: getGyroAxisCount -> count
   *
   * Gets the number of gyroscope axes supplied by this board.
   */
  rb_define_method(ph_spatial, "getGyroAxisCount", ph_spatial_get_gyro_axis_count, 0);

  /* Document-method: getCompassAxisCount
   * call-seq: getCompassAxisCount -> count
   *
   * Gets the number of compass axes supplied by this board.
   */
  rb_define_method(ph_spatial, "getCompassAxisCount", ph_spatial_get_compass_axis_count, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration(index) -> acceleration
   *
   * Gets the current acceleration of an axis.
   */
  rb_define_method(ph_spatial, "getAcceleration", ph_spatial_get_acceleration, 1);

  /* Document-method: getAccelerationMin
   * call-seq: getAccelerationMin(index) -> acceleration
   *
   * Gets the minimum acceleration supported by an axis.
   */
  rb_define_method(ph_spatial, "getAccelerationMin", ph_spatial_get_acceleration_min, 1);

  /* Document-method: getAccelerationMax
   * call-seq: getAccelerationMax(index) -> acceleration
   *
   * Gets the maximum accleration supported by an axis.
   */
  rb_define_method(ph_spatial, "getAccelerationMax", ph_spatial_get_acceleration_max, 1);

  /* Document-method: getAngularRate
   * call-seq: getAngularRate(index) -> rate
   *
   * Gets the current angular rate of an axis.
   */
  rb_define_method(ph_spatial, "getAngularRate", ph_spatial_get_angular_rate, 1);

  /* Document-method: getAngularRateMin
   * call-seq: getAngularRateMin(index) -> rate
   *
   * Gets the minimum angular rate supported by an axis.
   */
  rb_define_method(ph_spatial, "getAngularRateMin", ph_spatial_get_angular_rate_min, 1);

  /* Document-method: getAngularRateMax
   * call-seq: getAngularRateMax(index) -> rate
   *
   * Gets the maximum angular rate supported by an axis.
   */
  rb_define_method(ph_spatial, "getAngularRateMax", ph_spatial_get_angular_rate_max, 1);

  /* Document-method: getMagneticField
   * call-seq: getMagneticField(index) -> field
   *
   * Gets the current magnetic field stregth of an axis.
   */
  rb_define_method(ph_spatial, "getMagneticField", ph_spatial_get_magnetic_field, 1);

  /* Document-method: getMagneticFieldMin
   * call-seq: getMagneticFieldMin(index) -> field
   *
   * Gets the minimum magnetic field stregth supported by an axis.
   */
  rb_define_method(ph_spatial, "getMagneticFieldMin", ph_spatial_get_magnetic_field_min, 1);

  /* Document-method: getMagneticFieldMax
   * call-seq: getMagneticFieldMax(index) -> field
   *
   * Gets the maximum magnetic field stregth supported by an axis.
   */
  rb_define_method(ph_spatial, "getMagneticFieldMax", ph_spatial_get_magnetic_field_max, 1);

  /* Document-method: getDataRate
   * call-seq: getDataRate -> rate
   *
   * Get the data rate in milliseconds.
   */
  rb_define_method(ph_spatial, "getDataRate", ph_spatial_get_data_rate, 0);

  /* Document-method: getDataRateMin
   * call-seq: getDataRateMin -> rate
   *
   * Gets the minimum supported data rate in milliseconds.
   */
  rb_define_method(ph_spatial, "getDataRateMin", ph_spatial_get_data_rate_min, 0);

  /* Document-method: getDataRateMax
   * call-seq: getDataRateMax -> rate
   *
   * Gets the maximum supported data rate in milliseconds.
   */
  rb_define_method(ph_spatial, "getDataRateMax", ph_spatial_get_data_rate_max, 0);

  /* Document-method: setDataRate
   * call-seq: setDataRate(rate)
   *
   * Sets the data rate in milliseconds.
   */
  rb_define_method(ph_spatial, "setDataRate", ph_spatial_set_data_rate, 1);

  /* Document-method: zeroGyro
   * call-seq: zeroGyro
   *
   * Zeroes the gyroscope. This takes about two seconds and the gyro zxes will report 0 during the process.
   * This should only be called when the board is not moving.
   */
  rb_define_method(ph_spatial, "zeroGyro", ph_spatial_zero_gyro, 0);

  /* Document-method: setCompassCorrectionParameters
   * call-seq: setCompassCorrectionParameters(mag_field, offset0, offset1, offset2, gain0, gain1, gain2, T0, T1, T2, T3, T4, T5)
   *
   * Sets the compass correction factors. This can be used to correcting any sensor errors,
   * including hard and soft iron offsets and sensor error factors.
   */
  rb_define_method(ph_spatial, "setCompassCorrectionParameters", ph_spatial_set_compass_correction_parameters, 13);

  /* Document-method: resetCompassCorrectionParameters
   * call-seq: resetCompassCorrectionParameters
   *
   * Resets the compass correction factors. Magnetic field data will be presented directly as reported by the sensor.
   */
  rb_define_method(ph_spatial, "resetCompassCorrectionParameters", ph_spatial_reset_compass_correction_parameters, 0);

  rb_define_private_method(ph_spatial, "ext_setOnSpatialDataHandler", ph_spatial_set_on_spatial_data_handler, 1);

  rb_define_alias(ph_spatial, "acceleration_axis_count", "getAccelerationAxisCount");
  rb_define_alias(ph_spatial, "gyro_axis_count", "getGyroAxisCount");
  rb_define_alias(ph_spatial, "compass_axis_count", "getCompassAxisCount");
  rb_define_alias(ph_spatial, "acceleration", "getAcceleration");
  rb_define_alias(ph_spatial, "acceleration_min", "getAccelerationMin");
  rb_define_alias(ph_spatial, "acceleration_max", "getAccelerationMax");
  rb_define_alias(ph_spatial, "angular_rate", "getAngularRate");
  rb_define_alias(ph_spatial, "angular_rate_min", "getAngularRateMin");
  rb_define_alias(ph_spatial, "angular_rate_max", "getAngularRateMax");
  rb_define_alias(ph_spatial, "magnetic_field", "getMagneticField");
  rb_define_alias(ph_spatial, "magnetic_field_min", "getMagneticFieldMin");
  rb_define_alias(ph_spatial, "magnetic_field_max", "getMagneticFieldMax");
  rb_define_alias(ph_spatial, "data_rate", "getDataRate");
  rb_define_alias(ph_spatial, "data_rate_min", "getDataRateMin");
  rb_define_alias(ph_spatial, "data_rate_max", "getDataRateMax");
  rb_define_alias(ph_spatial, "data_rate=", "setDataRate");
  rb_define_alias(ph_spatial, "zero_gyro", "zeroGyro");
  rb_define_alias(ph_spatial, "set_compass_correction_parameters", "setCompassCorrectionParameters");
  rb_define_alias(ph_spatial, "reset_compass_correction_parameters", "resetCompassCorrectionParameters");
}



VALUE ph_spatial_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetSpatial_create((PhidgetSpatialHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_spatial_get_acceleration_axis_count(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetSpatial_getAccelerationAxisCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_spatial_get_gyro_axis_count(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetSpatial_getGyroAxisCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_spatial_get_compass_axis_count(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetSpatial_getCompassAxisCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_spatial_get_acceleration(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getAcceleration(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_acceleration_min(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getAccelerationMin(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_acceleration_max(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getAccelerationMax(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_angular_rate(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getAngularRate(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_angular_rate_min(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getAngularRateMin(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_angular_rate_max(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getAngularRateMax(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_magnetic_field(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getMagneticField(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_magnetic_field_min(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getMagneticFieldMin(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_magnetic_field_max(VALUE self, VALUE index) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  double value;
  ph_raise(PhidgetSpatial_getMagneticFieldMax(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_spatial_get_data_rate(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  int value;
  ph_raise(PhidgetSpatial_getDataRate(handle, &value));
  return INT2FIX(value);
}

VALUE ph_spatial_get_data_rate_min(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  int value;
  ph_raise(PhidgetSpatial_getDataRateMin(handle, &value));
  return INT2FIX(value);
}

VALUE ph_spatial_get_data_rate_max(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  int value;
  ph_raise(PhidgetSpatial_getDataRateMax(handle, &value));
  return INT2FIX(value);
}

VALUE ph_spatial_set_data_rate(VALUE self, VALUE milliseconds) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  ph_raise(PhidgetSpatial_setDataRate(handle, FIX2INT(milliseconds)));
  return Qnil;
}

VALUE ph_spatial_zero_gyro(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  ph_raise(PhidgetSpatial_zeroGyro(handle));
  return Qnil;
}

VALUE ph_spatial_set_compass_correction_parameters(VALUE self, VALUE mag_field, VALUE offset0, VALUE offset1, VALUE offset2, VALUE gain0, VALUE gain1, VALUE gain2, VALUE T0, VALUE T1, VALUE T2, VALUE T3, VALUE T4, VALUE T5) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  ph_raise(PhidgetSpatial_setCompassCorrectionParameters(handle, NUM2DBL(mag_field), NUM2DBL(offset0), NUM2DBL(offset1), NUM2DBL(offset2),
      NUM2DBL(gain0), NUM2DBL(gain1), NUM2DBL(gain2), NUM2DBL(T0), NUM2DBL(T1), NUM2DBL(T2), NUM2DBL(T3), NUM2DBL(T4), NUM2DBL(T5)));
  return Qnil;
}

VALUE ph_spatial_reset_compass_correction_parameters(VALUE self) {
  PhidgetSpatialHandle handle = (PhidgetSpatialHandle)get_ph_handle(self);
  ph_raise(PhidgetSpatial_resetCompassCorrectionParameters(handle));
  return Qnil;
}


VALUE ph_spatial_set_on_spatial_data_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetSpatial_set_OnSpatialData_Handler((PhidgetSpatialHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetSpatial_set_OnSpatialData_Handler((PhidgetSpatialHandle)ph->handle, ph_spatial_on_spatial_data, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_spatial_on_spatial_data(PhidgetSpatialHandle phid, void *userPtr, PhidgetSpatial_SpatialEventDataHandle *data, int data_count) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif
