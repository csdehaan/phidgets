
#include "phidgets.h"


VALUE ph_bridge_init(VALUE self);
VALUE ph_bridge_get_input_count(VALUE self);
VALUE ph_bridge_get_bridge_value(VALUE self, VALUE index);
VALUE ph_bridge_get_bridge_min(VALUE self, VALUE index);
VALUE ph_bridge_get_bridge_max(VALUE self, VALUE index);
VALUE ph_bridge_get_enabled(VALUE self, VALUE index);
VALUE ph_bridge_set_enabled(VALUE self, VALUE index, VALUE state);
VALUE ph_bridge_get_gain(VALUE self, VALUE index);
VALUE ph_bridge_set_gain(VALUE self, VALUE index, VALUE gain);
VALUE ph_bridge_get_data_rate(VALUE self);
VALUE ph_bridge_get_data_rate_min(VALUE self);
VALUE ph_bridge_get_data_rate_max(VALUE self);
VALUE ph_bridge_set_data_rate(VALUE self, VALUE milliseconds);

#ifdef PH_CALLBACK
VALUE ph_bridge_set_on_bridge_data_handler(VALUE self, VALUE handler);
int ph_bridge_on_bridge_data(CPhidgetBridgeHandle phid, void *userPtr, int index, double value);
#endif


VALUE Init_phidgets_bridge(VALUE ph_module, VALUE ph_common) {
  VALUE ph_bridge = rb_define_class_under(ph_module, "Bridge", ph_common);

  rb_define_const(ph_bridge, "GAIN_1", INT2FIX(PHIDGET_BRIDGE_GAIN_1));
  rb_define_const(ph_bridge, "GAIN_8", INT2FIX(PHIDGET_BRIDGE_GAIN_8));
  rb_define_const(ph_bridge, "GAIN_16", INT2FIX(PHIDGET_BRIDGE_GAIN_16));
  rb_define_const(ph_bridge, "GAIN_32", INT2FIX(PHIDGET_BRIDGE_GAIN_32));
  rb_define_const(ph_bridge, "GAIN_64", INT2FIX(PHIDGET_BRIDGE_GAIN_64));
  rb_define_const(ph_bridge, "GAIN_128", INT2FIX(PHIDGET_BRIDGE_GAIN_128));
  rb_define_const(ph_bridge, "GAIN_UNKNOWN", INT2FIX(PHIDGET_BRIDGE_GAIN_UNKNOWN));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Bridge object.
   */
  rb_define_method(ph_bridge, "initialize", ph_bridge_init, 0);

  /* Document-method: getInputCount
   * call-seq: getInputCount -> count
   *
   * Gets the number of inputs supported by this phidget bridge.
   */
  rb_define_method(ph_bridge, "getInputCount", ph_bridge_get_input_count, 0);

  /* Document-method: getBridgeValue
   * call-seq: getBridgeValue(index) -> value
   *
   * Gets the current value of a bridge input, in mV/V.
   */
  rb_define_method(ph_bridge, "getBridgeValue", ph_bridge_get_bridge_value, 1);

  /* Document-method: getBridgeMin
   * call-seq: getBridgeMin(index) -> min
   *
   * Gets the minimum value supported by a bridge input, in mV/V. This is affected by Gain.
   */
  rb_define_method(ph_bridge, "getBridgeMin", ph_bridge_get_bridge_min, 1);

  /* Document-method: getBridgeMax
   * call-seq: getBridgeMax(index) -> max
   *
   * Gets the maximum value supported by a bridge input, in mV/V. This is affected by Gain.
   */
  rb_define_method(ph_bridge, "getBridgeMax", ph_bridge_get_bridge_max, 1);

  /* Document-method: getEnabled
   * call-seq: getEnabled(index) -> true or false
   *
   * Gets the enabled state for an input.
   */
  rb_define_method(ph_bridge, "getEnabled", ph_bridge_get_enabled, 1);

  /* Document-method: setEnabled
   * call-seq: setEnabled(index, enabled_state)
   *
   * Sets the enabled state for an input.
   */
  rb_define_method(ph_bridge, "setEnabled", ph_bridge_set_enabled, 2);

  /* Document-method: getGain
   * call-seq: getGain(index) -> gain
   *
   * Gets the the Gain for an input.
   */
  rb_define_method(ph_bridge, "getGain", ph_bridge_get_gain, 1);

  /* Document-method: setGain
   * call-seq: setGain(index, gain)
   *
   * Sets the Gain for an input.
   */
  rb_define_method(ph_bridge, "setGain", ph_bridge_set_enabled, 2);

  /* Document-method: getDataRate
   * call-seq: getDataRate(index) -> milliseconds
   *
   * Gets the the data rate for the Phidget Bridge, in milliseconds.
   */
  rb_define_method(ph_bridge, "getDataRate", ph_bridge_get_data_rate, 0);

  /* Document-method: getDataRateMin
   * call-seq: getDataRateMin(index) -> milliseconds
   *
   * Gets the the minimum data rate for the Phidget Bridge, in milliseconds.
   */
  rb_define_method(ph_bridge, "getDataRateMin", ph_bridge_get_data_rate_min, 0);

  /* Document-method: getDataRateMax
   * call-seq: getDataRateMax(index) -> milliseconds
   *
   * Gets the the maximum data rate for the Phidget Bridge, in milliseconds.
   */
  rb_define_method(ph_bridge, "getDataRateMax", ph_bridge_get_data_rate_max, 0);

  /* Document-method: setDataRate
   * call-seq: setDataRate(index, milliseconds)
   *
   * Sets the the data rate for the Phidget Bridge, in milliseconds.
   */
  rb_define_method(ph_bridge, "setDataRate", ph_bridge_set_data_rate, 1);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_bridge, "ext_setOnBridgeDataHandler", ph_bridge_set_on_bridge_data_handler, 1);
#endif

  rb_define_alias(ph_bridge, "input_count", "getInputCount");
  rb_define_alias(ph_bridge, "bridge_value", "getBridgeValue");
  rb_define_alias(ph_bridge, "bridge_min", "getBridgeMin");
  rb_define_alias(ph_bridge, "bridge_max", "getBridgeMax");
  rb_define_alias(ph_bridge, "enabled?", "getEnabled");
  rb_define_alias(ph_bridge, "set_enabled", "setEnabled");
  rb_define_alias(ph_bridge, "gain", "getGain");
  rb_define_alias(ph_bridge, "set_gain", "setGain");
  rb_define_alias(ph_bridge, "data_rate", "getDataRate");
  rb_define_alias(ph_bridge, "data_rate_min", "getDataRateMin");
  rb_define_alias(ph_bridge, "data_rate_max", "getDataRateMax");
  rb_define_alias(ph_bridge, "data_rate=", "setDataRate");

  return ph_bridge;
}



VALUE ph_bridge_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetBridge_create((CPhidgetBridgeHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_bridge_get_input_count(VALUE self) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetBridge_getInputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_bridge_get_bridge_value(VALUE self, VALUE index) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  double value;
  ph_raise(CPhidgetBridge_getBridgeValue(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_bridge_get_bridge_min(VALUE self, VALUE index) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  double value;
  ph_raise(CPhidgetBridge_getBridgeMin(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_bridge_get_bridge_max(VALUE self, VALUE index) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  double value;
  ph_raise(CPhidgetBridge_getBridgeMax(handle, FIX2INT(index), &value));
  return rb_float_new(value);
}

VALUE ph_bridge_get_enabled(VALUE self, VALUE index) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetBridge_getEnabled(handle, FIX2INT(index), &value));
  return value == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_bridge_set_enabled(VALUE self, VALUE index, VALUE state) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  ph_raise(CPhidgetBridge_setEnabled(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_bridge_get_gain(VALUE self, VALUE index) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  CPhidgetBridge_Gain value;
  ph_raise(CPhidgetBridge_getGain(handle, FIX2INT(index), &value));
  return INT2FIX(value);
}

VALUE ph_bridge_set_gain(VALUE self, VALUE index, VALUE gain) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  ph_raise(CPhidgetBridge_setGain(handle, FIX2INT(index), FIX2INT(gain)));
  return Qnil;
}

VALUE ph_bridge_get_data_rate(VALUE self) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetBridge_getDataRate(handle, &value));
  return INT2FIX(value);
}

VALUE ph_bridge_get_data_rate_min(VALUE self) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetBridge_getDataRateMin(handle, &value));
  return INT2FIX(value);
}

VALUE ph_bridge_get_data_rate_max(VALUE self) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetBridge_getDataRateMax(handle, &value));
  return INT2FIX(value);
}

VALUE ph_bridge_set_data_rate(VALUE self, VALUE milliseconds) {
  CPhidgetBridgeHandle handle = (CPhidgetBridgeHandle)get_ph_handle(self);
  ph_raise(CPhidgetBridge_setDataRate(handle, FIX2INT(milliseconds)));
  return Qnil;
}


#ifdef PH_CALLBACK
VALUE ph_bridge_set_on_bridge_data_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetBridge_set_OnBridgeData_Handler((CPhidgetBridgeHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetBridge_set_OnBridgeData_Handler((CPhidgetBridgeHandle)ph->handle, ph_bridge_on_bridge_data, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_bridge_on_bridge_data(CPhidgetBridgeHandle phid, void *userPtr, int index, double value) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

