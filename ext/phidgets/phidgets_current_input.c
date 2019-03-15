
#include "phidgets.h"

#define CURRENT_INPUT_CURRENT_CHANGE_CALLBACK  0


VALUE ph_current_input_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetCurrentInput_create((PhidgetCurrentInputHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_current_input_get_current(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCurrentInput_getCurrent);
}

VALUE ph_current_input_get_min_current(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCurrentInput_getMinCurrent);
}

VALUE ph_current_input_get_max_current(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCurrentInput_getMaxCurrent);
}

VALUE ph_current_input_get_current_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCurrentInput_getCurrentChangeTrigger);
}

VALUE ph_current_input_set_current_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetCurrentInput_setCurrentChangeTrigger((PhidgetCurrentInputHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_current_input_get_min_current_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCurrentInput_getMinCurrentChangeTrigger);
}

VALUE ph_current_input_get_max_current_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCurrentInput_getMaxCurrentChangeTrigger);
}

VALUE ph_current_input_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetCurrentInput_getDataInterval);
}

VALUE ph_current_input_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetCurrentInput_setDataInterval((PhidgetCurrentInputHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_current_input_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetCurrentInput_getMinDataInterval);
}

VALUE ph_current_input_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetCurrentInput_getMaxDataInterval);
}

VALUE ph_current_input_get_power_supply(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetCurrentInput_getPowerSupply);
}

VALUE ph_current_input_set_power_supply(VALUE self, VALUE power_supply) {
  ph_raise(PhidgetCurrentInput_setPowerSupply((PhidgetCurrentInputHandle)get_ph_handle(self), NUM2INT(power_supply)));
  return Qnil;
}


void CCONV ph_current_input_on_current_change(PhidgetCurrentInputHandle phid, void *userPtr, double current) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(current);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}

VALUE ph_current_input_set_on_current_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[CURRENT_INPUT_CURRENT_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetCurrentInput_setOnCurrentChangeHandler((PhidgetCurrentInputHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetCurrentInput_setOnCurrentChangeHandler((PhidgetCurrentInputHandle)ph->handle, ph_current_input_on_current_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_current_input() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_current_input = rb_define_class_under(ph_module, "CurrentInput", ph_common);


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget CurrentInput object.
   */
  rb_define_method(ph_current_input, "initialize", ph_current_input_init, 0);

  /* Document-method: getCurrent
   * call-seq: getCurrent -> current
   *
   * The most recent current value that the channel has reported.
   * This value will always be between MinCurrent and MaxCurrent.
   */
  rb_define_method(ph_current_input, "getCurrent", ph_current_input_get_current, 0);
  rb_define_alias(ph_current_input, "current", "getCurrent");

  /* Document-method: getMinCurrent
   * call-seq: getMinCurrent -> current
   *
   * The minimum value the CurrentChange event will report.
   */
  rb_define_method(ph_current_input, "getMinCurrent", ph_current_input_get_min_current, 0);
  rb_define_alias(ph_current_input, "min_current", "getMinCurrent");

  /* Document-method: getMaxCurrent
   * call-seq: getMaxCurrent -> current
   *
   * The maximum value the CurrentChange event will report.
   */
  rb_define_method(ph_current_input, "getMaxCurrent", ph_current_input_get_max_current, 0);
  rb_define_alias(ph_current_input, "max_current", "getMaxCurrent");

  /* Document-method: getCurrentChangeTrigger
   * call-seq: getCurrentChangeTrigger -> trigger
   *
   * The channel will not issue a CurrentChange event until the current value has changed by the amount specified by the CurrentChangeTrigger.
   * Setting the CurrentChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_current_input, "getCurrentChangeTrigger", ph_current_input_get_current_change_trigger, 0);
  rb_define_alias(ph_current_input, "current_change_trigger", "getCurrentChangeTrigger");

  /* Document-method: setCurrentChangeTrigger
   * call-seq: setCurrentChangeTrigger(trigger)
   *
   * The channel will not issue a CurrentChange event until the current value has changed by the amount specified by the CurrentChangeTrigger.
   * Setting the CurrentChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_current_input, "setCurrentChangeTrigger", ph_current_input_set_current_change_trigger, 1);
  rb_define_alias(ph_current_input, "current_change_trigger=", "setCurrentChangeTrigger");

  /* Document-method: getMinCurrentChangeTrigger
   * call-seq: getMinCurrentChangeTrigger -> trigger
   *
   * The minimum value that CurrentChangeTrigger can be set to.
   */
  rb_define_method(ph_current_input, "getMinCurrentChangeTrigger", ph_current_input_get_min_current_change_trigger, 0);
  rb_define_alias(ph_current_input, "min_current_change_trigger", "getMinCurrentChangeTrigger");

  /* Document-method: getMaxCurrentChangeTrigger
   * call-seq: getMaxCurrentChangeTrigger -> trigger
   *
   * The maximum value that CurrentChangeTrigger can be set to.
   */
  rb_define_method(ph_current_input, "getMaxCurrentChangeTrigger", ph_current_input_get_max_current_change_trigger, 0);
  rb_define_alias(ph_current_input, "max_current_change_trigger", "getMaxCurrentChangeTrigger");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another CurrentChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between CurrentChange events can also affected by the CurrentChangeTrigger.
   */
  rb_define_method(ph_current_input, "getDataInterval", ph_current_input_get_data_interval, 0);
  rb_define_alias(ph_current_input, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another CurrentChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between CurrentChange events can also affected by the CurrentChangeTrigger.
   */
  rb_define_method(ph_current_input, "setDataInterval", ph_current_input_set_data_interval, 1);
  rb_define_alias(ph_current_input, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_current_input, "getMinDataInterval", ph_current_input_get_min_data_interval, 0);
  rb_define_alias(ph_current_input, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_current_input, "getMaxDataInterval", ph_current_input_get_max_data_interval, 0);
  rb_define_alias(ph_current_input, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getPowerSupply
   * call-seq: getPowerSupply -> power_supply
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_current_input, "getPowerSupply", ph_current_input_get_power_supply, 0);
  rb_define_alias(ph_current_input, "power_supply", "getPowerSupply");

  /* Document-method: setPowerSupply
   * call-seq: setPowerSupply(power_supply)
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_current_input, "setPowerSupply", ph_current_input_set_power_supply, 1);
  rb_define_alias(ph_current_input, "power_supply=", "setPowerSupply");


  rb_define_private_method(ph_current_input, "ext_setOnCurrentChangeHandler", ph_current_input_set_on_current_change_handler, 1);
}

