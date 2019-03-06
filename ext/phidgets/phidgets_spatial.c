
#include "phidgets.h"

#define SPATIAL_SPATIAL_DATA_CALLBACK  0


VALUE ph_spatial_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetSpatial_create((PhidgetSpatialHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_spatial_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetSpatial_getDataInterval);
}

VALUE ph_spatial_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetSpatial_setDataInterval((PhidgetSpatialHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_spatial_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetSpatial_getMinDataInterval);
}

VALUE ph_spatial_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetSpatial_getMaxDataInterval);
}

VALUE ph_spatial_set_magnetometer_correction_parameters(VALUE self, VALUE mag_field, VALUE offset0, VALUE offset1, VALUE offset2, VALUE gain0, VALUE gain1, VALUE gain2, VALUE T0, VALUE T1, VALUE T2, VALUE T3, VALUE T4, VALUE T5) {
  ph_raise(PhidgetSpatial_setMagnetometerCorrectionParameters((PhidgetSpatialHandle)get_ph_handle(self), NUM2DBL(mag_field), NUM2DBL(offset0), NUM2DBL(offset1), NUM2DBL(offset2),
      NUM2DBL(gain0), NUM2DBL(gain1), NUM2DBL(gain2), NUM2DBL(T0), NUM2DBL(T1), NUM2DBL(T2), NUM2DBL(T3), NUM2DBL(T4), NUM2DBL(T5)));
  return Qnil;
}

VALUE ph_spatial_reset_magnetometer_correction_parameters(VALUE self) {
  ph_raise(PhidgetSpatial_resetMagnetometerCorrectionParameters((PhidgetSpatialHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_spatial_save_magnetometer_correction_parameters(VALUE self) {
  ph_raise(PhidgetSpatial_saveMagnetometerCorrectionParameters((PhidgetSpatialHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_spatial_zero_gyro(VALUE self) {
  ph_raise(PhidgetSpatial_zeroGyro((PhidgetSpatialHandle)get_ph_handle(self)));
  return Qnil;
}


void CCONV ph_spatial_on_spatial_data(PhidgetSpatialHandle phid, void *userPtr, const double accel[3], const double angularRate[3], const double magneticField[3], double timestamp) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = rb_ary_new3(3, DBL2NUM(accel[0]), DBL2NUM(accel[1]), DBL2NUM(accel[2]));
  callback_data->arg2 = rb_ary_new3(3, DBL2NUM(angularRate[0]), DBL2NUM(angularRate[1]), DBL2NUM(angularRate[2]));
  callback_data->arg3 = rb_ary_new3(3, DBL2NUM(magneticField[0]), DBL2NUM(magneticField[1]), DBL2NUM(magneticField[2]));
  callback_data->arg4 = DBL2NUM(timestamp);
  sem_post(&callback_data->sem);
}


VALUE ph_spatial_set_on_spatial_data_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[SPATIAL_SPATIAL_DATA_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetSpatial_setOnSpatialDataHandler((PhidgetSpatialHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetSpatial_setOnSpatialDataHandler((PhidgetSpatialHandle)ph->handle, ph_spatial_on_spatial_data, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


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

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another SpatialData event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_spatial, "getDataInterval", ph_spatial_get_data_interval, 0);
  rb_define_alias(ph_spatial, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another SpatialData event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_spatial, "setDataInterval", ph_spatial_set_data_interval, 1);
  rb_define_alias(ph_spatial, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_spatial, "getMinDataInterval", ph_spatial_get_min_data_interval, 0);
  rb_define_alias(ph_spatial, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_spatial, "getMaxDataInterval", ph_spatial_get_max_data_interval, 0);
  rb_define_alias(ph_spatial, "max_data_interval", "getMaxDataInterval");

  /* Document-method: setMagnetometerCorrectionParameters
   * call-seq: setMagnetometerCorrectionParameters(mag_field, offset0, offset1, offset2, gain0, gain1, gain2, T0, T1, T2, T3, T4, T5)
   *
   * Calibrate your device for the environment it will be used in.
   * Due to physical location, hard and soft iron offsets, and even bias errors, your device should be calibrated.
   * We have created a calibration program that will provide you with the MagnetometerCorrectionParameters for your specific situation.
   * See your device's User Guide for more information.
   */
  rb_define_method(ph_spatial, "setMagnetometerCorrectionParameters", ph_spatial_set_magnetometer_correction_parameters, 13);
  rb_define_alias(ph_spatial, "set_magnetometer_correction_parameters", "setMagnetometerCorrectionParameters");

  /* Document-method: resetMagnetometerCorrectionParameters
   * call-seq: resetMagnetometerCorrectionParameters
   *
   * Resets the MagnetometerCorrectionParameters to their default values.
   * Due to physical location, hard and soft iron offsets, and even bias errors, your device should be calibrated.
   * We have created a calibration program that will provide you with the MagnetometerCorrectionParameters for your specific situation.
   * See your device's User Guide for more information
   */
  rb_define_method(ph_spatial, "resetMagnetometerCorrectionParameters", ph_spatial_reset_magnetometer_correction_parameters, 0);
  rb_define_alias(ph_spatial, "reset_magnetometer_correction_parameters", "resetMagnetometerCorrectionParameters");

  /* Document-method: saveMagnetometerCorrectionParameters
   * call-seq: saveMagnetometerCorrectionParameters
   *
   * Saves the MagnetometerCorrectionParameters.
   * Due to physical location, hard and soft iron offsets, and even bias errors, your device should be calibrated.
   * We have created a calibration program that will provide you with the MagnetometerCorrectionParameters for your specific situation.
   * See your device's User Guide for more information
   */
  rb_define_method(ph_spatial, "saveMagnetometerCorrectionParameters", ph_spatial_save_magnetometer_correction_parameters, 0);
  rb_define_alias(ph_spatial, "save_magnetometer_correction_parameters", "saveMagnetometerCorrectionParameters");

  /* Document-method: zeroGyro
   * call-seq: zeroGyro
   *
   * Re-zeros the gyroscope in 1-2 seconds.
   * The device must be stationary when zeroing.
   * The angular rate will be reported as 0.0°/s while zeroing.
   * Zeroing the gyroscope is a method of compensating for the drift that is inherent to all gyroscopes. See your device's User Guide for more information on dealing with drift.
   */
  rb_define_method(ph_spatial, "zeroGyro", ph_spatial_zero_gyro, 0);
  rb_define_alias(ph_spatial, "zero_gyro", "zeroGyro");


  rb_define_private_method(ph_spatial, "ext_setOnSpatialDataHandler", ph_spatial_set_on_spatial_data_handler, 1);
}

