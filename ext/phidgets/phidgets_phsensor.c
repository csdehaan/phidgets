
#include "phidgets.h"

#define PH_CHANGE_CALLBACK  0



VALUE ph_phsensor_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetPHSensor_create((PhidgetPHSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_phsensor_get_correction_temperature(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getCorrectionTemperature);
}

VALUE ph_phsensor_set_correction_temperature(VALUE self, VALUE temperature) {
  ph_raise(PhidgetPHSensor_setCorrectionTemperature((PhidgetPHSensorHandle)get_ph_handle(self), NUM2DBL(temperature)));
  return Qnil;
}

VALUE ph_phsensor_get_min_correction_temperature(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getMinCorrectionTemperature);
}

VALUE ph_phsensor_get_max_correction_temperature(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getMaxCorrectionTemperature);
}

VALUE ph_phsensor_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetPHSensor_getDataInterval);
}

VALUE ph_phsensor_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetPHSensor_setDataInterval((PhidgetPHSensorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_phsensor_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetPHSensor_getMinDataInterval);
}

VALUE ph_phsensor_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetPHSensor_getMaxDataInterval);
}

VALUE ph_phsensor_get_ph(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getPH);
}

VALUE ph_phsensor_get_min_ph(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getMinPH);
}

VALUE ph_phsensor_get_max_ph(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getMaxPH);
}

VALUE ph_phsensor_get_ph_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getPHChangeTrigger);
}

VALUE ph_phsensor_set_ph_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetPHSensor_setPHChangeTrigger((PhidgetPHSensorHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_phsensor_get_min_ph_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getMinPHChangeTrigger);
}

VALUE ph_phsensor_get_max_ph_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetPHSensor_getMaxPHChangeTrigger);
}


void CCONV ph_phsensor_on_ph_change(PhidgetPHSensorHandle phid, void *userPtr, double ph) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(ph);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_phsensor_set_on_ph_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[PH_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetPHSensor_setOnPHChangeHandler((PhidgetPHSensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetPHSensor_setOnPHChangeHandler((PhidgetPHSensorHandle)ph->handle, ph_phsensor_on_ph_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_ph_sensor() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_phsensor = rb_define_class_under(ph_module, "PHSensor", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget PHSensor object.
   */
  rb_define_method(ph_phsensor, "initialize", ph_phsensor_init, 0);

  /* Document-method: getCorrectionTemperature
   * call-seq: getCorrectionTemperature -> temperature
   *
   * Set this property to the measured temperature of the solution to correct the slope of the pH conversion for temperature.
   */
  rb_define_method(ph_phsensor, "getCorrectionTemperature", ph_phsensor_get_correction_temperature, 0);
  rb_define_alias(ph_phsensor, "correction_temperature", "getCorrectionTemperature");

  /* Document-method: setCorrectionTemperature
   * call-seq: setCorrectionTemperature(temperature)
   *
   * Set this property to the measured temperature of the solution to correct the slope of the pH conversion for temperature.
   */
  rb_define_method(ph_phsensor, "setCorrectionTemperature", ph_phsensor_set_correction_temperature, 1);
  rb_define_alias(ph_phsensor, "correction_temperature=", "setCorrectionTemperature");

  /* Document-method: getMinCorrectionTemperature
   * call-seq: getMinCorrectionTemperature -> temperature
   *
   * The minimum value that CorrectionTemperature can be set to.
   */
  rb_define_method(ph_phsensor, "getMinCorrectionTemperature", ph_phsensor_get_min_correction_temperature, 0);
  rb_define_alias(ph_phsensor, "min_correction_temperature", "getMinCorrectionTemperature");

  /* Document-method: getMaxCorrectionTemperature
   * call-seq: getMaxCorrectionTemperature -> temperature
   *
   * The maximum value that CorrectionTemperature can be set to.
   */
  rb_define_method(ph_phsensor, "getMaxCorrectionTemperature", ph_phsensor_get_max_correction_temperature, 0);
  rb_define_alias(ph_phsensor, "max_correction_temperature", "getMaxCorrectionTemperature");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> data_interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another PHChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between PHChange events can also affected by the PHChangeTrigger.
   */
  rb_define_method(ph_phsensor, "getDataInterval", ph_phsensor_get_data_interval, 0);
  rb_define_alias(ph_phsensor, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(data_interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another PHChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between PHChange events can also affected by the PHChangeTrigger.
   */
  rb_define_method(ph_phsensor, "setDataInterval", ph_phsensor_set_data_interval, 1);
  rb_define_alias(ph_phsensor, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> data_interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_phsensor, "getMinDataInterval", ph_phsensor_get_min_data_interval, 0);
  rb_define_alias(ph_phsensor, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> data_interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_phsensor, "getMaxDataInterval", ph_phsensor_get_max_data_interval, 0);
  rb_define_alias(ph_phsensor, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getPH
   * call-seq: getPH -> ph
   *
   * The most recent pH value that the channel has reported.
   * This value will always be between MinPH and MaxPH.
   */
  rb_define_method(ph_phsensor, "getPH", ph_phsensor_get_ph, 0);
  rb_define_alias(ph_phsensor, "ph", "getPH");

  /* Document-method: getMinPH
   * call-seq: getMinPH -> ph
   *
   * The minimum value the PHChange event will report.
   */
  rb_define_method(ph_phsensor, "getMinPH", ph_phsensor_get_min_ph, 0);
  rb_define_alias(ph_phsensor, "min_ph", "getMinPH");

  /* Document-method: getMaxPH
   * call-seq: getMaxPH -> ph
   *
   * The maximum value the PHChange event will report.
   */
  rb_define_method(ph_phsensor, "getMaxPH", ph_phsensor_get_max_ph, 0);
  rb_define_alias(ph_phsensor, "max_ph", "getMaxPH");

  /* Document-method: getPHChangeTrigger
   * call-seq: getPHChangeTrigger -> trigger
   *
   * The channel will not issue a PHChange event until the pH value has changed by the amount specified by the PHChangeTrigger.
   * Setting the PHChangeTrigger to 0 will result in the channel firing events every DataInterval.
   * This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_phsensor, "getPHChangeTrigger", ph_phsensor_get_ph_change_trigger, 0);
  rb_define_alias(ph_phsensor, "ph_change_trigger", "getPHChangeTrigger");

  /* Document-method: setPHChangeTrigger
   * call-seq: setPHChangeTrigger(trigger)
   *
   * The channel will not issue a PHChange event until the pH value has changed by the amount specified by the PHChangeTrigger.
   * Setting the PHChangeTrigger to 0 will result in the channel firing events every DataInterval.
   * This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_phsensor, "setPHChangeTrigger", ph_phsensor_set_ph_change_trigger, 1);
  rb_define_alias(ph_phsensor, "ph_change_trigger=", "setPHChangeTrigger");

  /* Document-method: getMinPHChangeTrigger
   * call-seq: getMinPHChangeTrigger -> trigger
   *
   * The channel will not issue a PHChange event until the pH value has changed by the amount specified by the PHChangeTrigger.
   * Setting the PHChangeTrigger to 0 will result in the channel firing events every DataInterval.
   * This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_phsensor, "getMinPHChangeTrigger", ph_phsensor_get_min_ph_change_trigger, 0);
  rb_define_alias(ph_phsensor, "min_ph_change_trigger", "getMinPHChangeTrigger");

  /* Document-method: getMaxPHChangeTrigger
   * call-seq: getMaxPHChangeTrigger -> trigger
   *
   * The channel will not issue a PHChange event until the pH value has changed by the amount specified by the PHChangeTrigger.
   * Setting the PHChangeTrigger to 0 will result in the channel firing events every DataInterval.
   * This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_phsensor, "getMaxPHChangeTrigger", ph_phsensor_get_max_ph_change_trigger, 0);
  rb_define_alias(ph_phsensor, "max_ph_change_trigger", "getMaxPHChangeTrigger");


  rb_define_private_method(ph_phsensor, "ext_setOnPHChangeHandler", ph_phsensor_set_on_ph_change_handler, 1);
}

