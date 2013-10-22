
#include "phidgets.h"


VALUE ph_phsensor_init(VALUE self);
VALUE ph_phsensor_get_ph(VALUE self);
VALUE ph_phsensor_get_ph_min(VALUE self);
VALUE ph_phsensor_get_ph_max(VALUE self);
VALUE ph_phsensor_get_ph_change_trigger(VALUE self);
VALUE ph_phsensor_set_ph_change_trigger(VALUE self, VALUE trigger);
VALUE ph_phsensor_get_potential(VALUE self);
VALUE ph_phsensor_get_potential_min(VALUE self);
VALUE ph_phsensor_get_potential_max(VALUE self);
VALUE ph_phsensor_set_temperature(VALUE self, VALUE temperature);

#ifdef PH_CALLBACK
VALUE ph_phsensor_set_on_ph_change_handler(VALUE self, VALUE handler);
int ph_phsensor_on_ph_change(CPhidgetPHSensorHandle phid, void *userPtr, double ph);
#endif


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

  /* Document-method: getPH
   * call-seq: getPH -> ph
   *
   * Gets the sensed PH.
   */
  rb_define_method(ph_phsensor, "getPH", ph_phsensor_get_ph, 0);

  /* Document-method: getPHMin
   * call-seq: getPHMin -> ph
   *
   * Gets the minimum PH that the sensor could report.
   */
  rb_define_method(ph_phsensor, "getPHMin", ph_phsensor_get_ph_min, 0);

  /* Document-method: getPHMax
   * call-seq: getPHMax -> ph
   *
   * Gets the maximum PH that the sensor could report.
   */
  rb_define_method(ph_phsensor, "getPHMax", ph_phsensor_get_ph_max, 0);

  /* Document-method: getPHChangeTrigger
   * call-seq: getPHChangeTrigger -> trigger
   *
   * Gets the PH change trigger.
   */
  rb_define_method(ph_phsensor, "getPHChangeTrigger", ph_phsensor_get_ph_change_trigger, 0);

  /* Document-method: setPHChangeTrigger
   * call-seq: setPHChangeTrigger(trigger)
   *
   * Sets the PH change trigger.
   */
  rb_define_method(ph_phsensor, "setPHChangeTrigger", ph_phsensor_set_ph_change_trigger, 1);

  /* Document-method: getPotential
   * call-seq: getPotential -> potential
   *
   * Gets the sensed potential.
   */
  rb_define_method(ph_phsensor, "getPotential", ph_phsensor_get_potential, 0);

  /* Document-method: getPotentialMin
   * call-seq: getPotentialMin -> potential
   *
   * Gets the minimum potential that can be sensed.
   */
  rb_define_method(ph_phsensor, "getPotentialMin", ph_phsensor_get_potential_min, 0);

  /* Document-method: getPotentialMax
   * call-seq: getPotentialMax -> potential
   *
   * Gets the maximum potential that can be sensed.
   */
  rb_define_method(ph_phsensor, "getPotentialMax", ph_phsensor_get_potential_max, 0);

  /* Document-method: setTemperature
   * call-seq: setTemperature(temperature)
   *
   * Sets the temperature to be used for PH calculations.
   */
  rb_define_method(ph_phsensor, "setTemperature", ph_phsensor_set_temperature, 1);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_phsensor, "ext_setOnPHChangeHandler", ph_phsensor_set_on_ph_change_handler, 1);
#endif

  rb_define_alias(ph_phsensor, "ph", "getPH");
  rb_define_alias(ph_phsensor, "ph_min", "getPHMin");
  rb_define_alias(ph_phsensor, "ph_max", "getPHMax");
  rb_define_alias(ph_phsensor, "ph_change_trigger", "getPHChangeTrigger");
  rb_define_alias(ph_phsensor, "ph_change_trigger=", "setPHChangeTrigger");
  rb_define_alias(ph_phsensor, "potential", "getPotential");
  rb_define_alias(ph_phsensor, "potential_min", "getPotentialMin");
  rb_define_alias(ph_phsensor, "potential_max", "getPotentialMax");
  rb_define_alias(ph_phsensor, "temperature=", "setTemperature");
}



VALUE ph_phsensor_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetPHSensor_create((CPhidgetPHSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_phsensor_get_ph(VALUE self) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  double ph;
  ph_raise(CPhidgetPHSensor_getPH(handle, &ph));
  return rb_float_new(ph);
}

VALUE ph_phsensor_get_ph_min(VALUE self) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  double ph;
  ph_raise(CPhidgetPHSensor_getPHMin(handle, &ph));
  return rb_float_new(ph);
}

VALUE ph_phsensor_get_ph_max(VALUE self) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  double ph;
  ph_raise(CPhidgetPHSensor_getPHMax(handle, &ph));
  return rb_float_new(ph);
}

VALUE ph_phsensor_get_ph_change_trigger(VALUE self) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  double trigger;
  ph_raise(CPhidgetPHSensor_getPHChangeTrigger(handle, &trigger));
  return rb_float_new(trigger);
}

VALUE ph_phsensor_set_ph_change_trigger(VALUE self, VALUE trigger) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  ph_raise(CPhidgetPHSensor_setPHChangeTrigger(handle, NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_phsensor_get_potential(VALUE self) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  double potential;
  ph_raise(CPhidgetPHSensor_getPotential(handle, &potential));
  return rb_float_new(potential);
}

VALUE ph_phsensor_get_potential_min(VALUE self) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  double potential;
  ph_raise(CPhidgetPHSensor_getPotentialMin(handle, &potential));
  return rb_float_new(potential);
}

VALUE ph_phsensor_get_potential_max(VALUE self) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  double potential;
  ph_raise(CPhidgetPHSensor_getPotentialMax(handle, &potential));
  return rb_float_new(potential);
}

VALUE ph_phsensor_set_temperature(VALUE self, VALUE temperature) {
  CPhidgetPHSensorHandle handle = (CPhidgetPHSensorHandle)get_ph_handle(self);
  ph_raise(CPhidgetPHSensor_setTemperature(handle, NUM2DBL(temperature)));
  return Qnil;
}


#ifdef PH_CALLBACK
VALUE ph_phsensor_set_on_ph_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetPHSensor_set_OnPHChange_Handler((CPhidgetPHSensorHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetPHSensor_set_OnPHChange_Handler((CPhidgetPHSensorHandle)ph->handle, ph_phsensor_on_ph_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_phsensor_on_ph_change(CPhidgetPHSensorHandle phid, void *userPtr, double ph) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

