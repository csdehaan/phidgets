
#include "phidgets.h"

#if 0
VALUE ph_weight_init(VALUE self);
VALUE ph_weight_get_weight(VALUE self);
VALUE ph_weight_get_weight_change_trigger(VALUE self);
VALUE ph_weight_set_weight_change_trigger(VALUE self, VALUE trigger);

VALUE ph_weight_set_on_weight_change_handler(VALUE self, VALUE handler);
int ph_weight_on_weight_change(PhidgetWeightSensorHandle phid, void *userPtr, double weight);


void Init_weight_sensor() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_weight = rb_define_class_under(ph_module, "WeightSensor", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget WeightSensor object.
   */
  rb_define_method(ph_weight, "initialize", ph_weight_init, 0);

  /* Document-method: getWeight
   * call-seq: getWeight -> weight
   *
   * Gets the sensed weight.
   */
  rb_define_method(ph_weight, "getWeight", ph_weight_get_weight, 0);

  /* Document-method: getWeightChangeTrigger
   * call-seq: getWeightChangeTrigger -> trigger
   *
   * Gets the weight change trigger.
   */
  rb_define_method(ph_weight, "getWeightChangeTrigger", ph_weight_get_weight_change_trigger, 0);

  /* Document-method: setWeightChangeTrigger
   * call-seq: setWeightChangeTrigger(trigger)
   *
   * Sets the weight change trigger.
   */
  rb_define_method(ph_weight, "setWeightChangeTrigger", ph_weight_set_weight_change_trigger, 1);

  rb_define_private_method(ph_weight, "ext_setOnWeightChangeHandler", ph_weight_set_on_weight_change_handler, 1);

  rb_define_alias(ph_weight, "weight", "getWeight");
  rb_define_alias(ph_weight, "weight_change_trigger", "getWeightChangeTrigger");
  rb_define_alias(ph_weight, "weight_change_trigger=", "setWeightChangeTrigger");
}



VALUE ph_weight_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetWeightSensor_create((PhidgetWeightSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_weight_get_weight(VALUE self) {
  PhidgetWeightSensorHandle handle = (PhidgetWeightSensorHandle)get_ph_handle(self);
  double weight;
  ph_raise(PhidgetWeightSensor_getWeight(handle, &weight));
  return rb_float_new(weight);
}

VALUE ph_weight_get_weight_change_trigger(VALUE self) {
  PhidgetWeightSensorHandle handle = (PhidgetWeightSensorHandle)get_ph_handle(self);
  double trigger;
  ph_raise(PhidgetWeightSensor_getWeightChangeTrigger(handle, &trigger));
  return rb_float_new(trigger);
}

VALUE ph_weight_set_weight_change_trigger(VALUE self, VALUE trigger) {
  PhidgetWeightSensorHandle handle = (PhidgetWeightSensorHandle)get_ph_handle(self);
  ph_raise(PhidgetWeightSensor_setWeightChangeTrigger(handle, NUM2DBL(trigger)));
  return Qnil;
}


VALUE ph_weight_set_on_weight_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetWeightSensor_set_OnWeightChange_Handler((PhidgetWeightSensorHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetWeightSensor_set_OnWeightChange_Handler((PhidgetWeightSensorHandle)ph->handle, ph_weight_on_weight_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_weight_on_weight_change(PhidgetWeightSensorHandle phid, void *userPtr, double weight) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif
