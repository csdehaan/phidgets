
#include "phidgets.h"

#define MAGNETOMETER_MAGNETIC_FIELD_CHANGE_CALLBACK    0


VALUE ph_magnetometer_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetMagnetometer_create((PhidgetMagnetometerHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_magnetometer_get_axis_count(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetMagnetometer_getAxisCount);
}

VALUE ph_magnetometer_set_correction_parameters(VALUE self, VALUE mag_field, VALUE offset0, VALUE offset1, VALUE offset2, VALUE gain0, VALUE gain1, VALUE gain2, VALUE T0, VALUE T1, VALUE T2, VALUE T3, VALUE T4, VALUE T5) {
  ph_raise(PhidgetMagnetometer_setCorrectionParameters((PhidgetMagnetometerHandle)get_ph_handle(self), NUM2DBL(mag_field), NUM2DBL(offset0), NUM2DBL(offset1), NUM2DBL(offset2),
      NUM2DBL(gain0), NUM2DBL(gain1), NUM2DBL(gain2), NUM2DBL(T0), NUM2DBL(T1), NUM2DBL(T2), NUM2DBL(T3), NUM2DBL(T4), NUM2DBL(T5)));
  return Qnil;
}

VALUE ph_magnetometer_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetMagnetometer_getDataInterval);
}

VALUE ph_magnetometer_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetMagnetometer_setDataInterval((PhidgetMagnetometerHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_magnetometer_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetMagnetometer_getMinDataInterval);
}

VALUE ph_magnetometer_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetMagnetometer_getMaxDataInterval);
}

VALUE ph_magnetometer_get_magnetic_field(VALUE self) {
  double mag_field[3];
  ph_raise(PhidgetMagnetometer_getMagneticField((PhidgetMagnetometerHandle)get_ph_handle(self), &mag_field));
  return rb_ary_new3(3, DBL2NUM(mag_field[0]), DBL2NUM(mag_field[1]), DBL2NUM(mag_field[2]));
}

VALUE ph_magnetometer_get_min_magnetic_field(VALUE self) {
  double mag_field[3];
  ph_raise(PhidgetMagnetometer_getMinMagneticField((PhidgetMagnetometerHandle)get_ph_handle(self), &mag_field));
  return rb_ary_new3(3, DBL2NUM(mag_field[0]), DBL2NUM(mag_field[1]), DBL2NUM(mag_field[2]));
}

VALUE ph_magnetometer_get_max_magnetic_field(VALUE self) {
  double mag_field[3];
  ph_raise(PhidgetMagnetometer_getMaxMagneticField((PhidgetMagnetometerHandle)get_ph_handle(self), &mag_field));
  return rb_ary_new3(3, DBL2NUM(mag_field[0]), DBL2NUM(mag_field[1]), DBL2NUM(mag_field[2]));
}

VALUE ph_magnetometer_get_magnetic_field_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetMagnetometer_getMagneticFieldChangeTrigger);
}

VALUE ph_magnetometer_set_magnetic_field_change_trigger(VALUE self, VALUE change_trigger) {
  ph_raise(PhidgetMagnetometer_setMagneticFieldChangeTrigger((PhidgetMagnetometerHandle)get_ph_handle(self), NUM2DBL(change_trigger)));
  return Qnil;
}

VALUE ph_magnetometer_get_min_magnetic_field_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetMagnetometer_getMinMagneticFieldChangeTrigger);
}

VALUE ph_magnetometer_get_max_magnetic_field_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetMagnetometer_getMaxMagneticFieldChangeTrigger);
}

VALUE ph_magnetometer_reset_correction_parameters(VALUE self) {
  ph_raise(PhidgetMagnetometer_resetCorrectionParameters((PhidgetMagnetometerHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_magnetometer_save_correction_parameters(VALUE self) {
  ph_raise(PhidgetMagnetometer_saveCorrectionParameters((PhidgetMagnetometerHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_magnetometer_get_timestamp(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetMagnetometer_getTimestamp);
}


void CCONV ph_magnetometer_on_magnetic_field_change(PhidgetMagnetometerHandle phid, void *userPtr, const double mag_field[3], double timestamp) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = rb_ary_new3(3, DBL2NUM(mag_field[0]), DBL2NUM(mag_field[1]), DBL2NUM(mag_field[2]));
  callback_data->arg2 = DBL2NUM(timestamp);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_magnetometer_set_on_magnetic_field_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[MAGNETOMETER_MAGNETIC_FIELD_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetMagnetometer_setOnMagneticFieldChangeHandler((PhidgetMagnetometerHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetMagnetometer_setOnMagneticFieldChangeHandler((PhidgetMagnetometerHandle)ph->handle, ph_magnetometer_on_magnetic_field_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_magnetometer() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_magnetometer = rb_define_class_under(ph_module, "Magnetometer", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Magnetometer object.
   */
  rb_define_method(ph_magnetometer, "initialize", ph_magnetometer_init, 0);

  /* Document-method: getAxisCount
   * call-seq: getAxisCount -> axis_count
   *
   * The number of axes the channel can measure field strength on.
   * See your device's User Guide for more information about the number of axes and their orientation.
   */
  rb_define_method(ph_magnetometer, "getAxisCount", ph_magnetometer_get_axis_count, 0);
  rb_define_alias(ph_magnetometer, "axis_count", "getAxisCount");

  /* Document-method: setCorrectionParameters
   * call-seq: setCorrectionParameters(mag_field, offset0, offset1, offset2, gain0, gain1, gain2, T0, T1, T2, T3, T4, T5)
   *
   * Calibrate your device for the environment it will be used in.
   * Due to physical location, hard and soft iron offsets, and even bias errors, your device should be calibrated.
   * We have created a calibration program that will provide you with the CompassCorrectionParameters for your specific situation.
   * See your device's User Guide for more information.
   */
  rb_define_method(ph_magnetometer, "setCorrectionParameters", ph_magnetometer_set_correction_parameters, 13);
  rb_define_alias(ph_magnetometer, "set_correction_parameters", "setCorrectionParameters");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another IlluminanceChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between IlluminanceChange events can also affected by the IlluminanceChangeTrigger.
   */
  rb_define_method(ph_magnetometer, "getDataInterval", ph_magnetometer_get_data_interval, 0);
  rb_define_alias(ph_magnetometer, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another IlluminanceChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between IlluminanceChange events can also affected by the IlluminanceChangeTrigger.
   */
  rb_define_method(ph_magnetometer, "setDataInterval", ph_magnetometer_set_data_interval, 1);
  rb_define_alias(ph_magnetometer, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_magnetometer, "getMinDataInterval", ph_magnetometer_get_min_data_interval, 0);
  rb_define_alias(ph_magnetometer, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_magnetometer, "getMaxDataInterval", ph_magnetometer_get_max_data_interval, 0);
  rb_define_alias(ph_magnetometer, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getMagneticField
   * call-seq: getMagneticField -> magnetic_field
   *
   * The most recent field strength value that the channel has reported.
   * This value will always be between MinMagneticField and MaxMagneticField.
   */
  rb_define_method(ph_magnetometer, "getMagneticField", ph_magnetometer_get_magnetic_field, 0);
  rb_define_alias(ph_magnetometer, "magnetic_field", "getMagneticField");

  /* Document-method: getMinMagneticField
   * call-seq: getMinMagneticField -> magnetic_field
   *
   * The minimum value that the MagneticFieldChange event will report.
   */
  rb_define_method(ph_magnetometer, "getMinMagneticField", ph_magnetometer_get_min_magnetic_field, 0);
  rb_define_alias(ph_magnetometer, "min_magnetic_field", "getMinMagneticField");

  /* Document-method: getMaxMagneticField
   * call-seq: getMaxMagneticField -> magnetic_field
   *
   * The maximum value that the MagneticFieldChange event will report.
   */
  rb_define_method(ph_magnetometer, "getMaxMagneticField", ph_magnetometer_get_max_magnetic_field, 0);
  rb_define_alias(ph_magnetometer, "max_magnetic_field", "getMaxMagneticField");

  /* Document-method: getMagneticFieldChangeTrigger
   * call-seq: getMagneticFieldChangeTrigger -> change_trigger
   *
   * The channel will not issue a MagneticFieldChange event until the field strength value has changed by the amount specified by the MagneticFieldChangeTrigger.
   * Setting the MagneticFieldChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_magnetometer, "getMagneticFieldChangeTrigger", ph_magnetometer_get_magnetic_field_change_trigger, 0);
  rb_define_alias(ph_magnetometer, "magnetic_field_change_trigger", "getMagneticFieldChangeTrigger");

  /* Document-method: setMagneticFieldChangeTrigger
   * call-seq: setMagneticFieldChangeTrigger(change_trigger)
   *
   * The channel will not issue a MagneticFieldChange event until the field strength value has changed by the amount specified by the MagneticFieldChangeTrigger.
   * Setting the MagneticFieldChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_magnetometer, "setMagneticFieldChangeTrigger", ph_magnetometer_set_magnetic_field_change_trigger, 1);
  rb_define_alias(ph_magnetometer, "magnetic_field_change_trigger=", "setMagneticFieldChangeTrigger");

  /* Document-method: getMinMagneticFieldChangeTrigger
   * call-seq: getMinMagneticFieldChangeTrigger -> change_trigger
   *
   * The minimum value that MagneticFieldChangeTrigger can be set to.
   */
  rb_define_method(ph_magnetometer, "getMinMagneticFieldChangeTrigger", ph_magnetometer_get_min_magnetic_field_change_trigger, 0);
  rb_define_alias(ph_magnetometer, "min_magnetic_field_change_trigger", "getMinMagneticFieldChangeTrigger");

  /* Document-method: getMaxMagneticFieldChangeTrigger
   * call-seq: getMaxMagneticFieldChangeTrigger -> change_trigger
   *
   * The maximum value that MagneticFieldChangeTrigger can be set to.
   */
  rb_define_method(ph_magnetometer, "getMaxMagneticFieldChangeTrigger", ph_magnetometer_get_max_magnetic_field_change_trigger, 0);
  rb_define_alias(ph_magnetometer, "max_magnetic_field_change_trigger", "getMaxMagneticFieldChangeTrigger");

  /* Document-method: resetCorrectionParameters
   * call-seq: resetCorrectionParameters
   *
   * Resets the CompassCorrectionParameters to their default values.
   * Due to physical location, hard and soft iron offsets, and even bias errors, your device should be calibrated.
   * We have created a calibration program that will provide you with the CompassCorrectionParameters for your specific situation. See your device's User Guide for more information.
   */
  rb_define_method(ph_magnetometer, "resetCorrectionParameters", ph_magnetometer_reset_correction_parameters, 0);
  rb_define_alias(ph_magnetometer, "reset_correction_parameters", "resetCorrectionParameters");

  /* Document-method: saveCorrectionParameters
   * call-seq: saveCorrectionParameters
   *
   * Saves the CalibrationParameters.
   * Due to physical location, hard and soft iron offsets, and even bias errors, your device should be calibrated.
   * We have created a calibration program that will provide you with the CompassCorrectionParameters for your specific situation. See your device's User Guide for more information.
   */
  rb_define_method(ph_magnetometer, "saveCorrectionParameters", ph_magnetometer_save_correction_parameters, 0);
  rb_define_alias(ph_magnetometer, "save_correction_parameters", "saveCorrectionParameters");

  /* Document-method: getTimestamp
   * call-seq: getTimestamp -> timestamp
   *
   * The most recent timestamp value that the channel has reported. This is an extremely accurate time measurement streamed from the device.
   * If your application requires a time measurement, you should use this value over a local software timestamp.
   */
  rb_define_method(ph_magnetometer, "getTimestamp", ph_magnetometer_get_timestamp, 0);
  rb_define_alias(ph_magnetometer, "timestamp", "getTimestamp");


  rb_define_private_method(ph_magnetometer, "ext_setOnMagneticFieldChangeHandler", ph_magnetometer_set_on_magnetic_field_change_handler, 1);
}

