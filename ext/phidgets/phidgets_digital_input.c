
#include "phidgets.h"

#define DIGITAL_INPUT_STATE_CHANGE_CALLBACK  0


VALUE ph_digital_input_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetDigitalInput_create((PhidgetDigitalInputHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_digital_input_get_input_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), PhidgetDigitalInput_getInputMode);
}

VALUE ph_digital_input_set_input_mode(VALUE self, VALUE mode) {
  ph_raise(PhidgetDigitalInput_setInputMode((PhidgetDigitalInputHandle)get_ph_handle(self), NUM2INT(mode)));
  return Qnil;
}

VALUE ph_digital_input_get_power_supply(VALUE self) {
  return ph_get_int(get_ph_handle(self), PhidgetDigitalInput_getPowerSupply);
}

VALUE ph_digital_input_set_power_supply(VALUE self, VALUE power_supply) {
  ph_raise(PhidgetDigitalInput_setPowerSupply((PhidgetDigitalInputHandle)get_ph_handle(self), NUM2INT(power_supply)));
  return Qnil;
}

VALUE ph_digital_input_get_state(VALUE self) {
  return ph_get_bool(get_ph_handle(self), PhidgetDigitalInput_getState);
}


void CCONV ph_digital_input_on_state_change(PhidgetDigitalInputHandle phid, void *userPtr, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = state == PTRUE ? Qtrue : Qfalse;
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}

VALUE ph_digital_input_set_on_state_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DIGITAL_INPUT_STATE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDigitalInput_setOnStateChangeHandler((PhidgetDigitalInputHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDigitalInput_setOnStateChangeHandler((PhidgetDigitalInputHandle)ph->handle, ph_digital_input_on_state_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_digital_input() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_digital_input = rb_define_class_under(ph_module, "DigitalInput", ph_common);


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget DigitalInput object.
   */
  rb_define_method(ph_digital_input, "initialize", ph_digital_input_init, 0);

  /* Document-method: getInputMode
   * call-seq: getInputMode -> mode
   *
   * The input polarity mode for your channel.
   * See your device's User Guide for more information about what value to chooose for the InputMode.
   */
  rb_define_method(ph_digital_input, "getInputMode", ph_digital_input_get_input_mode, 0);
  rb_define_alias(ph_digital_input, "input_mode", "getInputMode");

  /* Document-method: setInputMode
   * call-seq: setInputMode(mode)
   *
   * The input polarity mode for your channel.
   * See your device's User Guide for more information about what value to chooose for the InputMode.
   */
  rb_define_method(ph_digital_input, "setInputMode", ph_digital_input_set_input_mode, 1);
  rb_define_alias(ph_digital_input, "input_mode=", "setInputMode");

  /* Document-method: getPowerSupply
   * call-seq: getPowerSupply -> power_supply
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_digital_input, "getPowerSupply", ph_digital_input_get_power_supply, 0);
  rb_define_alias(ph_digital_input, "power_supply", "getPowerSupply");

  /* Document-method: setPowerSupply
   * call-seq: setPowerSupply(power_supply)
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_digital_input, "setPowerSupply", ph_digital_input_set_power_supply, 1);
  rb_define_alias(ph_digital_input, "power_supply=", "setPowerSupply");

  /* Document-method: getState
   * call-seq: getState -> state
   *
   * The most recent state value that the channel has reported.
   */
  rb_define_method(ph_digital_input, "getState", ph_digital_input_get_state, 0);
  rb_define_alias(ph_digital_input, "state", "getState");


  rb_define_private_method(ph_digital_input, "ext_setOnStateChangeHandler", ph_digital_input_set_on_state_change_handler, 1);
}

