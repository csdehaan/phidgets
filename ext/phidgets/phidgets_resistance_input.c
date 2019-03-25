
#include "phidgets.h"

#define RESISTANCE_INPUT_RESISTANCE_CHANGE_CALLBACK    0


VALUE ph_resistance_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetResistanceInput_create((PhidgetResistanceInputHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_resistance_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetResistanceInput_getDataInterval);
}

VALUE ph_resistance_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetResistanceInput_setDataInterval((PhidgetResistanceInputHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_resistance_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetResistanceInput_getMinDataInterval);
}

VALUE ph_resistance_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetResistanceInput_getMaxDataInterval);
}

VALUE ph_resistance_get_resistance(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetResistanceInput_getResistance);
}

VALUE ph_resistance_get_min_resistance(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetResistanceInput_getMinResistance);
}

VALUE ph_resistance_get_max_resistance(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetResistanceInput_getMaxResistance);
}

VALUE ph_resistance_get_resistance_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetResistanceInput_getResistanceChangeTrigger);
}

VALUE ph_resistance_set_resistance_change_trigger(VALUE self, VALUE change_trigger) {
  ph_raise(PhidgetResistanceInput_setResistanceChangeTrigger((PhidgetResistanceInputHandle)get_ph_handle(self), NUM2DBL(change_trigger)));
  return Qnil;
}

VALUE ph_resistance_get_min_resistance_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetResistanceInput_getMinResistanceChangeTrigger);
}

VALUE ph_resistance_get_max_resistance_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetResistanceInput_getMaxResistanceChangeTrigger);
}

VALUE ph_resistance_get_rtd_wire_setup(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetResistanceInput_getRTDWireSetup);
}

VALUE ph_resistance_set_rtd_wire_setup(VALUE self, VALUE wire_setup) {
  ph_raise(PhidgetResistanceInput_setRTDWireSetup((PhidgetResistanceInputHandle)get_ph_handle(self), NUM2INT(wire_setup)));
  return Qnil;
}


void CCONV ph_resistance_on_resistance_change(PhidgetResistanceInputHandle phid, void *userPtr, double resistance) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(resistance);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_resistance_set_on_resistance_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[RESISTANCE_INPUT_RESISTANCE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetResistanceInput_setOnResistanceChangeHandler((PhidgetResistanceInputHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetResistanceInput_setOnResistanceChangeHandler((PhidgetResistanceInputHandle)ph->handle, ph_resistance_on_resistance_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_resistance() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_resistance = rb_define_class_under(ph_module, "ResistanceInput", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget ResistanceInput object.
   */
  rb_define_method(ph_resistance, "initialize", ph_resistance_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another ResistanceChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between ResistanceChange events can also affected by the ResistanceChangeTrigger.
   */
  rb_define_method(ph_resistance, "getDataInterval", ph_resistance_get_data_interval, 0);
  rb_define_alias(ph_resistance, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another ResistanceChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between ResistanceChange events can also affected by the ResistanceChangeTrigger.
   */
  rb_define_method(ph_resistance, "setDataInterval", ph_resistance_set_data_interval, 1);
  rb_define_alias(ph_resistance, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_resistance, "getMinDataInterval", ph_resistance_get_min_data_interval, 0);
  rb_define_alias(ph_resistance, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_resistance, "getMaxDataInterval", ph_resistance_get_max_data_interval, 0);
  rb_define_alias(ph_resistance, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getResistance
   * call-seq: getResistance -> resistance
   *
   * The most recent resistance value that the channel has reported.
   * This value will always be between MinResistance and MaxResistance.
   */
  rb_define_method(ph_resistance, "getResistance", ph_resistance_get_resistance, 0);
  rb_define_alias(ph_resistance, "resistance", "getResistance");

  /* Document-method: getMinResistance
   * call-seq: getMinResistance -> resistance
   *
   * The minimum value that the ResistanceChange event will report.
   */
  rb_define_method(ph_resistance, "getMinResistance", ph_resistance_get_min_resistance, 0);
  rb_define_alias(ph_resistance, "min_resistance", "getMinResistance");

  /* Document-method: getMaxResistance
   * call-seq: getMaxResistance -> resistance
   *
   * The maximum value that the ResistanceChange event will report.
   */
  rb_define_method(ph_resistance, "getMaxResistance", ph_resistance_get_max_resistance, 0);
  rb_define_alias(ph_resistance, "max_resistance", "getMaxResistance");

  /* Document-method: getResistanceChangeTrigger
   * call-seq: getResistanceChangeTrigger -> change_trigger
   *
   * The channel will not issue a ResistanceChange event until the resistance value has changed by the amount specified by the ResistanceChangeTrigger.
   * Setting the ResistanceChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_resistance, "getResistanceChangeTrigger", ph_resistance_get_resistance_change_trigger, 0);
  rb_define_alias(ph_resistance, "resistance_change_trigger", "getResistanceChangeTrigger");

  /* Document-method: setResistanceChangeTrigger
   * call-seq: setResistanceChangeTrigger(change_trigger)
   *
   * The channel will not issue a ResistanceChange event until the resistance value has changed by the amount specified by the ResistanceChangeTrigger.
   * Setting the ResistanceChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_resistance, "setResistanceChangeTrigger", ph_resistance_set_resistance_change_trigger, 1);
  rb_define_alias(ph_resistance, "resistance_change_trigger=", "setResistanceChangeTrigger");

  /* Document-method: getMinResistanceChangeTrigger
   * call-seq: getMinResistanceChangeTrigger -> change_trigger
   *
   * The minimum value that ResistanceChangeTrigger can be set to.
   */
  rb_define_method(ph_resistance, "getMinResistanceChangeTrigger", ph_resistance_get_min_resistance_change_trigger, 0);
  rb_define_alias(ph_resistance, "min_resistance_change_trigger", "getMinResistanceChangeTrigger");

  /* Document-method: getMaxResistanceChangeTrigger
   * call-seq: getMaxResistanceChangeTrigger -> change_trigger
   *
   * The maximum value that ResistanceChangeTrigger can be set to.
   */
  rb_define_method(ph_resistance, "getMaxResistanceChangeTrigger", ph_resistance_get_max_resistance_change_trigger, 0);
  rb_define_alias(ph_resistance, "max_resistance_change_trigger", "getMaxResistanceChangeTrigger");

  /* Document-method: getRTDWireSetup
   * call-seq: getRTDWireSetup -> wire_setup
   *
   * Select the RTD wiring configuration.
   * More information about RTD wiring can be found in the user guide.
   */
  rb_define_method(ph_resistance, "getRTDWireSetup", ph_resistance_get_rtd_wire_setup, 0);
  rb_define_alias(ph_resistance, "rtd_wire_setup", "getRTDWireSetup");

  /* Document-method: setRTDWireSetup
   * call-seq: setRTDWireSetup(wire_setup)
   *
   * Select the RTD wiring configuration.
   * More information about RTD wiring can be found in the user guide.
   */
  rb_define_method(ph_resistance, "setRTDWireSetup", ph_resistance_set_rtd_wire_setup, 1);
  rb_define_alias(ph_resistance, "rtd_wire_setup=", "setRTDWireSetup");


  rb_define_private_method(ph_resistance, "ext_setOnResistanceChangeHandler", ph_resistance_set_on_resistance_change_handler, 1);
}

