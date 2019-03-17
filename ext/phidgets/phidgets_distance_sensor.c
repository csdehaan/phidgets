
#include "phidgets.h"

#define DISTANCE_SENSOR_DISTANCE_CHANGE_CALLBACK           0
#define DISTANCE_SENSOR_SONAR_REFLECTIONS_UPDATE_CALLBACK  1


VALUE ph_distance_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetDistanceSensor_create((PhidgetDistanceSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_distance_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getDataInterval);
}

VALUE ph_distance_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetDistanceSensor_setDataInterval((PhidgetDistanceSensorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_distance_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getMinDataInterval);
}

VALUE ph_distance_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getMaxDataInterval);
}

VALUE ph_distance_get_distance(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getDistance);
}

VALUE ph_distance_get_min_distance(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getMinDistance);
}

VALUE ph_distance_get_max_distance(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getMaxDistance);
}

VALUE ph_distance_get_distance_change_trigger(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getDistanceChangeTrigger);
}

VALUE ph_distance_set_distance_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetDistanceSensor_setDistanceChangeTrigger((PhidgetDistanceSensorHandle)get_ph_handle(self), NUM2UINT(trigger)));
  return Qnil;
}

VALUE ph_distance_get_min_distance_change_trigger(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getMinDistanceChangeTrigger);
}

VALUE ph_distance_get_max_distance_change_trigger(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDistanceSensor_getMaxDistanceChangeTrigger);
}

VALUE ph_distance_get_sonar_quiet_mode(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetDistanceSensor_getSonarQuietMode);
}

VALUE ph_distance_set_sonar_quiet_mode(VALUE self, VALUE mode) {
  ph_raise(PhidgetDistanceSensor_setSonarQuietMode((PhidgetDistanceSensorHandle)get_ph_handle(self), TYPE(mode) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_distance_get_sonar_reflections(VALUE self) {
  PhidgetDistanceSensorHandle handle = (PhidgetDistanceSensorHandle)get_ph_handle(self);
  uint32_t distances[8];
  uint32_t amplitudes[8];
  uint32_t count, i;
  VALUE rb_reflections = rb_hash_new();
  VALUE rb_distances = rb_ary_new();
  VALUE rb_amplitudes = rb_ary_new();
  ph_raise(PhidgetDistanceSensor_getSonarReflections(handle, &distances, &amplitudes, &count));
  for(i=0; i<count; i++) {
    rb_ary_push(rb_distances, UINT2NUM(distances[i]));
    rb_ary_push(rb_amplitudes, UINT2NUM(amplitudes[i]));
  }
  rb_hash_aset(rb_reflections, rb_str_new2("distances"), rb_distances);
  rb_hash_aset(rb_reflections, rb_str_new2("amplitudes"), rb_amplitudes);
  return rb_reflections;
}


void CCONV ph_distance_on_distance_change(PhidgetDistanceSensorHandle phid, void *userPtr, uint32_t distance) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = UINT2NUM(distance);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_distance_set_on_distance_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DISTANCE_SENSOR_DISTANCE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDistanceSensor_setOnDistanceChangeHandler((PhidgetDistanceSensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDistanceSensor_setOnDistanceChangeHandler((PhidgetDistanceSensorHandle)ph->handle, ph_distance_on_distance_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_distance_on_sonar_reflections_update(PhidgetDistanceSensorHandle phid, void *userPtr, const uint32_t distances[8], const uint32_t amplitudes[8], uint32_t count) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  uint32_t i;
  VALUE rb_distances = rb_ary_new();
  VALUE rb_amplitudes = rb_ary_new();
  for(i=0; i<count; i++) {
    rb_ary_push(rb_distances, UINT2NUM(distances[i]));
    rb_ary_push(rb_amplitudes, UINT2NUM(amplitudes[i]));
  }
  callback_data->arg1 = rb_distances;
  callback_data->arg2 = rb_amplitudes;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_distance_set_on_sonar_reflections_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DISTANCE_SENSOR_SONAR_REFLECTIONS_UPDATE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDistanceSensor_setOnSonarReflectionsUpdateHandler((PhidgetDistanceSensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDistanceSensor_setOnSonarReflectionsUpdateHandler((PhidgetDistanceSensorHandle)ph->handle, ph_distance_on_sonar_reflections_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_distance() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_distance = rb_define_class_under(ph_module, "DistanceSensor", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget DistanceSensor object.
   */
  rb_define_method(ph_distance, "initialize", ph_distance_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between events can also affected by the change trigger.
   */
  rb_define_method(ph_distance, "getDataInterval", ph_distance_get_data_interval, 0);
  rb_define_alias(ph_distance, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between events can also affected by the change trigger.
   */
  rb_define_method(ph_distance, "setDataInterval", ph_distance_set_data_interval, 1);
  rb_define_alias(ph_distance, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_distance, "getMinDataInterval", ph_distance_get_min_data_interval, 0);
  rb_define_alias(ph_distance, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_distance, "getMaxDataInterval", ph_distance_get_max_data_interval, 0);
  rb_define_alias(ph_distance, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getDistance
   * call-seq: getDistance -> distance
   *
   * The most recent distance value that the channel has reported.
   * This value will always be between MinDistance and MaxDistance.
   */
  rb_define_method(ph_distance, "getDistance", ph_distance_get_distance, 0);
  rb_define_alias(ph_distance, "distance", "getDistance");

  /* Document-method: getMinDistance
   * call-seq: getMinDistance -> distance
   *
   * The minimum distance that a event will report.
   */
  rb_define_method(ph_distance, "getMinDistance", ph_distance_get_min_distance, 0);
  rb_define_alias(ph_distance, "min_distance", "getMinDistance");

  /* Document-method: getMaxDistance
   * call-seq: getMaxDistance -> distance
   *
   * The maximum distance that a event will report.
   */
  rb_define_method(ph_distance, "getMaxDistance", ph_distance_get_max_distance, 0);
  rb_define_alias(ph_distance, "max_distance", "getMaxDistance");

  /* Document-method: getDistanceChangeTrigger
   * call-seq: getDistanceChangeTrigger -> change_trigger
   *
   * The channel will not issue an event until the distance value has changed by the amount specified by the DistanceChangeTrigger.
   * Setting the DistanceChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_distance, "getDistanceChangeTrigger", ph_distance_get_distance_change_trigger, 0);
  rb_define_alias(ph_distance, "distance_change_trigger", "getDistanceChangeTrigger");

  /* Document-method: setDistanceChangeTrigger
   * call-seq: setDistanceChangeTrigger(change_trigger)
   *
   * The channel will not issue an event until the distance value has changed by the amount specified by the DistanceChangeTrigger.
   * Setting the DistanceChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_distance, "setDistanceChangeTrigger", ph_distance_set_distance_change_trigger, 1);
  rb_define_alias(ph_distance, "distance_change_trigger=", "setDistanceChangeTrigger");

  /* Document-method: getMinDistanceChangeTrigger
   * call-seq: getMinDistanceChangeTrigger -> change_trigger
   *
   * The minimum value that DistanceChangeTrigger can be set to.
   */
  rb_define_method(ph_distance, "getMinDistanceChangeTrigger", ph_distance_get_min_distance_change_trigger, 0);
  rb_define_alias(ph_distance, "min_distance_change_trigger", "getMinDistanceChangeTrigger");

  /* Document-method: getMaxDistanceChangeTrigger
   * call-seq: getMaxDistanceChangeTrigger -> change_trigger
   *
   * The maximum value that DistanceChangeTrigger can be set to.
   */
  rb_define_method(ph_distance, "getMaxDistanceChangeTrigger", ph_distance_get_max_distance_change_trigger, 0);
  rb_define_alias(ph_distance, "max_distance_change_trigger", "getMaxDistanceChangeTrigger");

  /* Document-method: getSonarQuietMode
   * call-seq: getSonarQuietMode -> true or false
   *
   * When set to true, the device will operate more quietly.
   * The measurable range is reduced when operating in quiet mode.
   */
  rb_define_method(ph_distance, "getSonarQuietMode", ph_distance_get_sonar_quiet_mode, 0);
  rb_define_alias(ph_distance, "sonar_quiet_mode", "getSonarQuietMode");

  /* Document-method: setSonarQuietMode
   * call-seq: setSonarQuietMode(quiet_mode)
   *
   * When set to true, the device will operate more quietly.
   * The measurable range is reduced when operating in quiet mode.
   */
  rb_define_method(ph_distance, "setSonarQuietMode", ph_distance_set_sonar_quiet_mode, 1);
  rb_define_alias(ph_distance, "sonar_quiet_mode=", "setSonarQuietMode");

  /* Document-method: getSonarReflections
   * call-seq: getSonarReflections -> reflections
   *
   * The most recent reflection values that the channel has reported.
   * The distance values will always be between MinDistance and MaxDistance.
   * The closest reflection will be placed at index 0 of the distances array, and the furthest reflection at index 7
   * The amplitude values are relative amplitudes of the reflections that are normalized to an arbitrary scale.
   */
  rb_define_method(ph_distance, "getSonarReflections", ph_distance_get_sonar_reflections, 0);
  rb_define_alias(ph_distance, "sonar_reflections", "getSonarReflections");


  rb_define_private_method(ph_distance, "ext_setOnDistanceChangeHandler", ph_distance_set_on_distance_change_handler, 1);
  rb_define_private_method(ph_distance, "ext_setOnSonarReflectionsUpdateHandler", ph_distance_set_on_sonar_reflections_update_handler, 1);
}

