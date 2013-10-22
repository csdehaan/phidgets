
#include "phidgets.h"


VALUE ph_ifkit_init(VALUE self);
VALUE ph_ifkit_get_input_count(VALUE self);
VALUE ph_ifkit_get_input_state(VALUE self, VALUE index);
VALUE ph_ifkit_get_output_count(VALUE self);
VALUE ph_ifkit_get_output_state(VALUE self, VALUE index);
VALUE ph_ifkit_set_output_state(VALUE self, VALUE index, VALUE state);
VALUE ph_ifkit_get_sensor_count(VALUE self);
VALUE ph_ifkit_get_sensor_value(VALUE self, VALUE index);
VALUE ph_ifkit_get_sensor_raw_value(VALUE self, VALUE index);
VALUE ph_ifkit_get_ratiometric(VALUE self);
VALUE ph_ifkit_set_ratiometric(VALUE self, VALUE ratiometric);
VALUE ph_ifkit_get_data_rate(VALUE self, VALUE index);
VALUE ph_ifkit_get_data_rate_min(VALUE self, VALUE index);
VALUE ph_ifkit_get_data_rate_max(VALUE self, VALUE index);
VALUE ph_ifkit_set_data_rate(VALUE self, VALUE index, VALUE rate);

#ifdef PH_CALLBACK
VALUE ph_ifkit_set_on_input_change_handler(VALUE self, VALUE handler);
VALUE ph_ifkit_set_on_output_change_handler(VALUE self, VALUE handler);
VALUE ph_ifkit_set_on_sensor_change_handler(VALUE self, VALUE handler);
int ph_ifkit_on_input_change(CPhidgetInterfaceKitHandle phid, void *userPtr, int index, int state);
int ph_ifkit_on_output_change(CPhidgetInterfaceKitHandle phid, void *userPtr, int index, int state);
int ph_ifkit_on_sensor_change(CPhidgetInterfaceKitHandle phid, void *userPtr, int index, int value);
#endif


void Init_interface_kit() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_ifkit = rb_define_class_under(ph_module, "InterfaceKit", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget InterfaceKit object.
   */
  rb_define_method(ph_ifkit, "initialize", ph_ifkit_init, 0);

  /* Document-method: getInputCount
   * call-seq: getInputCount -> count
   *
   * Gets the number of digital inputs supported by this board.
   */
  rb_define_method(ph_ifkit, "getInputCount", ph_ifkit_get_input_count, 0);

  /* Document-method: getInputState
   * call-seq: getInputState(index) -> true or false
   *
   * Gets the state of a digital input.
   */
  rb_define_method(ph_ifkit, "getInputState", ph_ifkit_get_input_state, 1);

  /* Document-method: getOutputCount
   * call-seq: getOutputCount -> count
   *
   * Gets the number of digital outputs supported by this board.
   */
  rb_define_method(ph_ifkit, "getOutputCount", ph_ifkit_get_output_count, 0);

  /* Document-method: getOutputState
   * call-seq: getOutputState(index) -> true or false
   *
   * Gets the state of a digital output.
   */
  rb_define_method(ph_ifkit, "getOutputState", ph_ifkit_get_output_state, 1);

  /* Document-method: setOutputState
   * call-seq: setOutputState(index, state)
   *
   * Sets the state of a digital output.
   */
  rb_define_method(ph_ifkit, "setOutputState", ph_ifkit_set_output_state, 2);

  /* Document-method: getSensorCount
   * call-seq: getSensorCount -> count
   *
   * Gets the number of sensor (analog) inputs supported by this board.
   */
  rb_define_method(ph_ifkit, "getSensorCount", ph_ifkit_get_sensor_count, 0);

  /* Document-method: getSensorValue
   * call-seq: getSensorValue(index) -> value
   *
   * Gets a sensor value (0-1000).
   */
  rb_define_method(ph_ifkit, "getSensorValue", ph_ifkit_get_sensor_value, 1);

  /* Document-method: getSensorRawValue
   * call-seq: getSensorRawValue(index) -> value
   *
   * Gets a sensor raw value (12-bit).
   */
  rb_define_method(ph_ifkit, "getSensorRawValue", ph_ifkit_get_sensor_raw_value, 1);

  /* Document-method: getRatiometric
   * call-seq: getRatiometric -> true or false
   *
   * Gets the ratiometric state for this board.
   */
  rb_define_method(ph_ifkit, "getRatiometric", ph_ifkit_get_ratiometric, 0);

  /* Document-method: setRatiometric
   * call-seq: setRatiometric(state)
   *
   * Sets the ratiometric state for this board.
   */
  rb_define_method(ph_ifkit, "setRatiometric", ph_ifkit_set_ratiometric, 1);

  /* Document-method: getDataRate
   * call-seq: getDataRate(index) -> milliseconds
   *
   * Gets the Data Rate for an analog input.
   */
  rb_define_method(ph_ifkit, "getDataRate", ph_ifkit_get_data_rate, 1);

  /* Document-method: getDataRateMin
   * call-seq: getDataRateMin(index) -> milliseconds
   *
   * Gets the minimum supported data rate for an analog input
   */
  rb_define_method(ph_ifkit, "getDataRateMin", ph_ifkit_get_data_rate_min, 1);

  /* Document-method: getDataRateMax
   * call-seq: getDataRateMax(index) -> milliseconds
   *
   * Gets the maximum supported data rate for an analog input
   */
  rb_define_method(ph_ifkit, "getDataRateMax", ph_ifkit_get_data_rate_max, 1);

  /* Document-method: setDataRate
   * call-seq: setDataRate(index, milliseconds)
   *
   * Gets the maximum supported data rate for an analog input
   */
  rb_define_method(ph_ifkit, "setDataRate", ph_ifkit_set_data_rate, 2);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_ifkit, "ext_setOnInputChangeHandler", ph_ifkit_set_on_input_change_handler, 1);
  rb_define_private_method(ph_ifkit, "ext_setOnOutputChangeHandler", ph_ifkit_set_on_output_change_handler, 1);
  rb_define_private_method(ph_ifkit, "ext_setOnSensorChangeHandler", ph_ifkit_set_on_sensor_change_handler, 1);
#endif

  rb_define_alias(ph_ifkit, "input_count", "getInputCount");
  rb_define_alias(ph_ifkit, "input_state", "getInputState");
  rb_define_alias(ph_ifkit, "output_count", "getOutputCount");
  rb_define_alias(ph_ifkit, "output_state", "getOutputState");
  rb_define_alias(ph_ifkit, "set_output_state", "setOutputState");
  rb_define_alias(ph_ifkit, "sensor_count", "getSensorCount");
  rb_define_alias(ph_ifkit, "sensor_value", "getSensorValue");
  rb_define_alias(ph_ifkit, "sensor_raw_value", "getSensorRawValue");
  rb_define_alias(ph_ifkit, "ratiometric?", "getRatiometric");
  rb_define_alias(ph_ifkit, "ratiometric=", "setRatiometric");
  rb_define_alias(ph_ifkit, "data_rate", "getDataRate");
  rb_define_alias(ph_ifkit, "data_rate_min", "getDataRateMin");
  rb_define_alias(ph_ifkit, "data_rate_max", "getDataRateMax");
  rb_define_alias(ph_ifkit, "set_data_rate", "setDataRate");
}



VALUE ph_ifkit_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetInterfaceKit_create((CPhidgetInterfaceKitHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_ifkit_get_input_count(VALUE self) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetInterfaceKit_getInputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_ifkit_get_input_state(VALUE self, VALUE index) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetInterfaceKit_getInputState(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_ifkit_get_output_count(VALUE self) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetInterfaceKit_getOutputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_ifkit_get_output_state(VALUE self, VALUE index) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetInterfaceKit_getOutputState(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_ifkit_set_output_state(VALUE self, VALUE index, VALUE state) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  ph_raise(CPhidgetInterfaceKit_setOutputState(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_ifkit_get_sensor_count(VALUE self) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetInterfaceKit_getSensorCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_ifkit_get_sensor_value(VALUE self, VALUE index) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetInterfaceKit_getSensorValue(handle, FIX2INT(index), &value));
  return INT2FIX(value);
}

VALUE ph_ifkit_get_sensor_raw_value(VALUE self, VALUE index) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetInterfaceKit_getSensorRawValue(handle, FIX2INT(index), &value));
  return INT2FIX(value);
}

VALUE ph_ifkit_get_ratiometric(VALUE self) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int ratiometric;
  ph_raise(CPhidgetInterfaceKit_getRatiometric(handle, &ratiometric));
  return ratiometric == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_ifkit_set_ratiometric(VALUE self, VALUE ratiometric) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  ph_raise(CPhidgetInterfaceKit_setRatiometric(handle, TYPE(ratiometric) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_ifkit_get_data_rate(VALUE self, VALUE index) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int rate;
  ph_raise(CPhidgetInterfaceKit_getDataRate(handle, FIX2INT(index), &rate));
  return INT2FIX(rate);
}

VALUE ph_ifkit_get_data_rate_min(VALUE self, VALUE index) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int rate;
  ph_raise(CPhidgetInterfaceKit_getDataRateMin(handle, FIX2INT(index), &rate));
  return INT2FIX(rate);
}

VALUE ph_ifkit_get_data_rate_max(VALUE self, VALUE index) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  int rate;
  ph_raise(CPhidgetInterfaceKit_getDataRateMax(handle, FIX2INT(index), &rate));
  return INT2FIX(rate);
}

VALUE ph_ifkit_set_data_rate(VALUE self, VALUE index, VALUE rate) {
  CPhidgetInterfaceKitHandle handle = (CPhidgetInterfaceKitHandle)get_ph_handle(self);
  ph_raise(CPhidgetInterfaceKit_setDataRate(handle, FIX2INT(index), FIX2INT(rate)));
  return Qnil;
}

#ifdef PH_CALLBACK
VALUE ph_ifkit_set_on_input_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetInterfaceKit_set_OnInputChange_Handler((CPhidgetInterfaceKitHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetInterfaceKit_set_OnInputChange_Handler((CPhidgetInterfaceKitHandle)ph->handle, ph_ifkit_on_input_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_ifkit_set_on_output_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetInterfaceKit_set_OnOutputChange_Handler((CPhidgetInterfaceKitHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetInterfaceKit_set_OnOutputChange_Handler((CPhidgetInterfaceKitHandle)ph->handle, ph_ifkit_on_output_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_ifkit_set_on_sensor_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_3;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetInterfaceKit_set_OnSensorChange_Handler((CPhidgetInterfaceKitHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetInterfaceKit_set_OnSensorChange_Handler((CPhidgetInterfaceKitHandle)ph->handle, ph_ifkit_on_sensor_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_ifkit_on_input_change(CPhidgetInterfaceKitHandle phid, void *userPtr, int index, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_ifkit_on_output_change(CPhidgetInterfaceKitHandle phid, void *userPtr, int index, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_ifkit_on_sensor_change(CPhidgetInterfaceKitHandle phid, void *userPtr, int index, int value) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif


