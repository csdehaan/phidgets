
#include "phidgets.h"

#define CAP_TOUCH_TOUCH_END_CALLBACK   0
#define CAP_TOUCH_TOUCH_CALLBACK       1


VALUE ph_capacitive_touch_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetCapacitiveTouch_create((PhidgetCapacitiveTouchHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_capacitive_touch_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetCapacitiveTouch_getDataInterval);
}

VALUE ph_capacitive_touch_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetCapacitiveTouch_setDataInterval((PhidgetCapacitiveTouchHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_capacitive_touch_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetCapacitiveTouch_getMinDataInterval);
}

VALUE ph_capacitive_touch_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetCapacitiveTouch_getMaxDataInterval);
}

VALUE ph_capacitive_touch_get_is_touched(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetCapacitiveTouch_getIsTouched);
}

VALUE ph_capacitive_touch_get_sensitivity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getSensitivity);
}

VALUE ph_capacitive_touch_set_sensitivity(VALUE self, VALUE sensitivity) {
  ph_raise(PhidgetCapacitiveTouch_setSensitivity((PhidgetCapacitiveTouchHandle)get_ph_handle(self), NUM2DBL(sensitivity)));
  return Qnil;
}

VALUE ph_capacitive_touch_get_min_sensitivity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getMinSensitivity);
}

VALUE ph_capacitive_touch_get_max_sensitivity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getMaxSensitivity);
}

VALUE ph_capacitive_touch_get_touch_value(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getTouchValue);
}

VALUE ph_capacitive_touch_get_min_touch_value(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getMinTouchValue);
}

VALUE ph_capacitive_touch_get_max_touch_value(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getMaxTouchValue);
}

VALUE ph_capacitive_touch_get_touch_value_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getTouchValueChangeTrigger);
}

VALUE ph_capacitive_touch_set_touch_value_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetCapacitiveTouch_setTouchValueChangeTrigger((PhidgetCapacitiveTouchHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_capacitive_touch_get_min_touch_value_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getMinTouchValueChangeTrigger);
}

VALUE ph_capacitive_touch_get_max_touch_value_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetCapacitiveTouch_getMaxTouchValueChangeTrigger);
}


void CCONV ph_capacitive_touch_on_touch_end(PhidgetCapacitiveTouchHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = Qnil;
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_capacitive_touch_set_on_touch_end_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[CAP_TOUCH_TOUCH_END_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetCapacitiveTouch_setOnTouchEndHandler((PhidgetCapacitiveTouchHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetCapacitiveTouch_setOnTouchEndHandler((PhidgetCapacitiveTouchHandle)ph->handle, ph_capacitive_touch_on_touch_end, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_capacitive_touch_on_touch(PhidgetCapacitiveTouchHandle phid, void *userPtr, double touch_value) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(touch_value);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_capacitive_touch_set_on_touch_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[CAP_TOUCH_TOUCH_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetCapacitiveTouch_setOnTouchHandler((PhidgetCapacitiveTouchHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetCapacitiveTouch_setOnTouchHandler((PhidgetCapacitiveTouchHandle)ph->handle, ph_capacitive_touch_on_touch, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}



void Init_capacitive_touch() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_capacitive_touch = rb_define_class_under(ph_module, "CapacitiveTouch", ph_common);



  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget CapacitiveTouch object.
   */
  rb_define_method(ph_capacitive_touch, "initialize", ph_capacitive_touch_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another Touch event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between Touch events can also affected by the TouchValueChangeTrigger.
   */
  rb_define_method(ph_capacitive_touch, "getDataInterval", ph_capacitive_touch_get_data_interval, 0);
  rb_define_alias(ph_capacitive_touch, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another Touch event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between Touch events can also affected by the TouchValueChangeTrigger.
   */
  rb_define_method(ph_capacitive_touch, "setDataInterval", ph_capacitive_touch_set_data_interval, 1);
  rb_define_alias(ph_capacitive_touch, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_capacitive_touch, "getMinDataInterval", ph_capacitive_touch_get_min_data_interval, 0);
  rb_define_alias(ph_capacitive_touch, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_capacitive_touch, "getMaxDataInterval", ph_capacitive_touch_get_max_data_interval, 0);
  rb_define_alias(ph_capacitive_touch, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getIsTouched
   * call-seq: getIsTouched -> true or false
   *
   * The most recent touch state that the channel has reported.
   */
  rb_define_method(ph_capacitive_touch, "getIsTouched", ph_capacitive_touch_get_is_touched, 0);
  rb_define_alias(ph_capacitive_touch, "is_touched?", "getIsTouched");

  /* Document-method: getSensitivity
   * call-seq: getSensitivity -> sensitivity
   *
   * Determines the sensitivity of all capacitive regions on the device.
   * Higher values result in greater touch sensitivity.
   * The sensitivity value is bounded by MinSensitivity and MaxSensitivity.
   */
  rb_define_method(ph_capacitive_touch, "getSensitivity", ph_capacitive_touch_get_sensitivity, 0);
  rb_define_alias(ph_capacitive_touch, "sensitivity", "getSensitivity");

  /* Document-method: setSensitivity
   * call-seq: setSensitivity(sensitivity)
   *
   * Determines the sensitivity of all capacitive regions on the device.
   * Higher values result in greater touch sensitivity.
   * The sensitivity value is bounded by MinSensitivity and MaxSensitivity.
   */
  rb_define_method(ph_capacitive_touch, "setSensitivity", ph_capacitive_touch_set_sensitivity, 1);
  rb_define_alias(ph_capacitive_touch, "sensitivity=", "setSensitivity");

  /* Document-method: getMinSensitivity
   * call-seq: getMinSensitivity -> sensitivity
   *
   * The minimum value that Sensitivity can be set to.
   */
  rb_define_method(ph_capacitive_touch, "getMinSensitivity", ph_capacitive_touch_get_min_sensitivity, 0);
  rb_define_alias(ph_capacitive_touch, "min_sensitivity", "getMinSensitivity");

  /* Document-method: getMaxSensitivity
   * call-seq: getMaxSensitivity -> sensitivity
   *
   * The maximum value that Sensitivity can be set to.
   */
  rb_define_method(ph_capacitive_touch, "getMaxSensitivity", ph_capacitive_touch_get_max_sensitivity, 0);
  rb_define_alias(ph_capacitive_touch, "max_sensitivity", "getMaxSensitivity");

  /* Document-method: getTouchValue
   * call-seq: getTouchValue -> touch_value
   *
   * The most recent touch value that the channel has reported.
   * This will be 0 or 1 for button-type inputs, or a ratio between 0-1 for axis-type inputs.
   * This value is bounded by MinTouchValue and MaxTouchValue
   * The value is not reset when the touch ends.
   */
  rb_define_method(ph_capacitive_touch, "getTouchValue", ph_capacitive_touch_get_touch_value, 0);
  rb_define_alias(ph_capacitive_touch, "touch_value", "getTouchValue");

  /* Document-method: getMinTouchValue
   * call-seq: getMinTouchValue -> touch_value
   *
   * The minimum value the Touch event will report.
   */
  rb_define_method(ph_capacitive_touch, "getMinTouchValue", ph_capacitive_touch_get_min_touch_value, 0);
  rb_define_alias(ph_capacitive_touch, "min_touch_value", "getMinTouchValue");

  /* Document-method: getMaxTouchValue
   * call-seq: getMaxTouchValue -> touch_value
   *
   * The maximum value the Touch event will report.
   */
  rb_define_method(ph_capacitive_touch, "getMaxTouchValue", ph_capacitive_touch_get_max_touch_value, 0);
  rb_define_alias(ph_capacitive_touch, "max_touch_value", "getMaxTouchValue");

  /* Document-method: getTouchValueChangeTrigger
   * call-seq: getTouchValueChangeTrigger -> trigger
   *
   * The channel will not issue a Touch event until the touch value has changed by the amount specified by the TouchValueChangeTrigger.
   * Setting the TouchValueChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_capacitive_touch, "getTouchValueChangeTrigger", ph_capacitive_touch_get_touch_value_change_trigger, 0);
  rb_define_alias(ph_capacitive_touch, "touch_value_change_trigger", "getTouchValueChangeTrigger");

  /* Document-method: setTouchValueChangeTrigger
   * call-seq: setTouchValueChangeTrigger(trigger)
   *
   * The channel will not issue a Touch event until the touch value has changed by the amount specified by the TouchValueChangeTrigger.
   * Setting the TouchValueChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_capacitive_touch, "setTouchValueChangeTrigger", ph_capacitive_touch_set_touch_value_change_trigger, 1);
  rb_define_alias(ph_capacitive_touch, "touch_value_change_trigger=", "setTouchValueChangeTrigger");

  /* Document-method: getMinTouchValueChangeTrigger
   * call-seq: getMinTouchValueChangeTrigger -> trigger
   *
   * The minimum value that TouchValueChangeTrigger can be set to.
   */
  rb_define_method(ph_capacitive_touch, "getMinTouchValueChangeTrigger", ph_capacitive_touch_get_min_touch_value_change_trigger, 0);
  rb_define_alias(ph_capacitive_touch, "min_touch_value_change_trigger", "getMinTouchValueChangeTrigger");

  /* Document-method: getMaxTouchValueChangeTrigger
   * call-seq: getMaxTouchValueChangeTrigger -> trigger
   *
   * The maximum value that TouchValueChangeTrigger can be set to.
   */
  rb_define_method(ph_capacitive_touch, "getMaxTouchValueChangeTrigger", ph_capacitive_touch_get_max_touch_value_change_trigger, 0);
  rb_define_alias(ph_capacitive_touch, "max_touch_value_change_trigger", "getMaxTouchValueChangeTrigger");


  rb_define_private_method(ph_capacitive_touch, "ext_setOnTouchEndHandler", ph_capacitive_touch_set_on_touch_end_handler, 1);
  rb_define_private_method(ph_capacitive_touch, "ext_setOnTouchHandler", ph_capacitive_touch_set_on_touch_handler, 1);
}

