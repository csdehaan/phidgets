
#include "phidgets.h"


VALUE ph_freq_init(VALUE self);
VALUE ph_freq_get_frequency_input_count(VALUE self);
VALUE ph_freq_reset(VALUE self, VALUE index);
VALUE ph_freq_get_frequency(VALUE self, VALUE index);
VALUE ph_freq_get_total_time(VALUE self, VALUE index);
VALUE ph_freq_get_total_count(VALUE self, VALUE index);
VALUE ph_freq_get_timeout(VALUE self, VALUE index);
VALUE ph_freq_set_timeout(VALUE self, VALUE index, VALUE timeout);
VALUE ph_freq_get_enabled(VALUE self, VALUE index);
VALUE ph_freq_set_enabled(VALUE self, VALUE index, VALUE state);
VALUE ph_freq_get_filter(VALUE self, VALUE index);
VALUE ph_freq_set_filter(VALUE self, VALUE index, VALUE filter);

#ifdef PH_CALLBACK
VALUE ph_freq_set_on_count_handler(VALUE self, VALUE handler);
int ph_freq_on_count(CPhidgetFrequencyCounterHandle phid, void *userPtr, int index, int time, int counts);
#endif


void Init_frequency_counter() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_freq = rb_define_class_under(ph_module, "FrequencyCounter", ph_common);

  rb_define_const(ph_freq, "FILTERTYPE_ZERO_CROSSING", INT2FIX(PHIDGET_FREQUENCYCOUNTER_FILTERTYPE_ZERO_CROSSING));
  rb_define_const(ph_freq, "FILTERTYPE_LOGIC_LEVEL", INT2FIX(PHIDGET_FREQUENCYCOUNTER_FILTERTYPE_LOGIC_LEVEL));
  rb_define_const(ph_freq, "FILTERTYPE_UNKNOWN", INT2FIX(PHIDGET_FREQUENCYCOUNTER_FILTERTYPE_UNKNOWN));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget FrequencyCounter object.
   */
  rb_define_method(ph_freq, "initialize", ph_freq_init, 0);

  /* Document-method: getFrequencyInputCount
   * call-seq: getFrequencyInputCount -> count
   *
   * Gets the number of inputs supported by this phidget frequency counter.
   */
  rb_define_method(ph_freq, "getFrequencyInputCount", ph_freq_get_frequency_input_count, 0);

  /* Document-method: reset
   * call-seq: reset(index)
   *
   * Resets total count and total time for an input.
   */
  rb_define_method(ph_freq, "reset", ph_freq_reset, 1);

  /* Document-method: getFrequency
   * call-seq: getFrequency(index) -> frequency
   *
   * Gets the measured frequency of an input, in Hz.
   */
  rb_define_method(ph_freq, "getFrequency", ph_freq_get_frequency, 1);

  /* Document-method: getTotalTime
   * call-seq: getTotalTime(index) -> time
   *
   * Gets the total time that has passed since the last reset on this input, in microseconds.
   */
  rb_define_method(ph_freq, "getTotalTime", ph_freq_get_total_time, 1);

  /* Document-method: getTotalCount
   * call-seq: getTotalCount(index) -> count
   *
   * Gets the total number of ticks that have happened since the last reset on this input.
   */
  rb_define_method(ph_freq, "getTotalCount", ph_freq_get_total_count, 1);

  /* Document-method: getTimeout
   * call-seq: getTimeout(index) -> timeout
   *
   * Gets the timeout value for an input, in microseconds. This controls the lowest measurable frequency.
   */
  rb_define_method(ph_freq, "getTimeout", ph_freq_get_timeout, 1);

  /* Document-method: setTimeout
   * call-seq: setTimeout(index, timeout)
   *
   * Sets the timeout value for an input, in microseconds.
   */
  rb_define_method(ph_freq, "setTimeout", ph_freq_set_timeout, 2);

  /* Document-method: getEnabled
   * call-seq: getEnabled(index) -> true or false
   *
   * Gets the enabled state for an input.
   */
  rb_define_method(ph_freq, "getEnabled", ph_freq_get_enabled, 1);

  /* Document-method: setEnabled
   * call-seq: setEnabled(index, state)
   *
   * Sets the enabled state for an input.
   */
  rb_define_method(ph_freq, "setEnabled", ph_freq_set_enabled, 2);

  /* Document-method: getFilter
   * call-seq: getFilter(index) -> filter_type
   *
   * Gets the filter type for an input.
   */
  rb_define_method(ph_freq, "getFilter", ph_freq_get_filter, 1);

  /* Document-method: setFilter
   * call-seq: setFilter(index, filter_type)
   *
   * Sets the filter type for an input.
   */
  rb_define_method(ph_freq, "setFilter", ph_freq_set_filter, 2);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_freq, "ext_setOnCountHandler", ph_freq_set_on_count_handler, 1);
#endif

  rb_define_alias(ph_freq, "frequency_input_count", "getFrequencyInputCount");
  rb_define_alias(ph_freq, "frequency", "getFrequency");
  rb_define_alias(ph_freq, "total_time", "getTotalTime");
  rb_define_alias(ph_freq, "total_count", "getTotalCount");
  rb_define_alias(ph_freq, "timeout", "getTimeout");
  rb_define_alias(ph_freq, "set_timeout", "setTimeout");
  rb_define_alias(ph_freq, "enabled?", "getEnabled");
  rb_define_alias(ph_freq, "set_enabled", "setEnabled");
  rb_define_alias(ph_freq, "filter", "getFilter");
  rb_define_alias(ph_freq, "set_filter", "setFilter");
}



VALUE ph_freq_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetFrequencyCounter_create((CPhidgetFrequencyCounterHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_freq_get_frequency_input_count(VALUE self) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetFrequencyCounter_getFrequencyInputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_freq_reset(VALUE self, VALUE index) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  ph_raise(CPhidgetFrequencyCounter_reset(handle, FIX2INT(index)));
  return Qnil;
}

VALUE ph_freq_get_frequency(VALUE self, VALUE index) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  double freq;
  ph_raise(CPhidgetFrequencyCounter_getFrequency(handle, FIX2INT(index), &freq));
  return rb_float_new(freq);
}

VALUE ph_freq_get_total_time(VALUE self, VALUE index) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  __int64 time;
  ph_raise(CPhidgetFrequencyCounter_getTotalTime(handle, FIX2INT(index), &time));
  return INT2NUM(time);
}

VALUE ph_freq_get_total_count(VALUE self, VALUE index) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  __int64 count;
  ph_raise(CPhidgetFrequencyCounter_getTotalCount(handle, FIX2INT(index), &count));
  return INT2NUM(count);
}

VALUE ph_freq_get_timeout(VALUE self, VALUE index) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  int timeout;
  ph_raise(CPhidgetFrequencyCounter_getTimeout(handle, FIX2INT(index), &timeout));
  return INT2FIX(timeout);
}

VALUE ph_freq_set_timeout(VALUE self, VALUE index, VALUE timeout) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  ph_raise(CPhidgetFrequencyCounter_setTimeout(handle, FIX2INT(index), FIX2INT(timeout)));
  return Qnil;
}

VALUE ph_freq_get_enabled(VALUE self, VALUE index) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetFrequencyCounter_getEnabled(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_freq_set_enabled(VALUE self, VALUE index, VALUE state) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  ph_raise(CPhidgetFrequencyCounter_setEnabled(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_freq_get_filter(VALUE self, VALUE index) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  CPhidgetFrequencyCounter_FilterType filter;
  ph_raise(CPhidgetFrequencyCounter_getFilter(handle, FIX2INT(index), &filter));
  return INT2FIX(filter);
}

VALUE ph_freq_set_filter(VALUE self, VALUE index, VALUE filter) {
  CPhidgetFrequencyCounterHandle handle = (CPhidgetFrequencyCounterHandle)get_ph_handle(self);
  ph_raise(CPhidgetFrequencyCounter_setFilter(handle, FIX2INT(index), FIX2INT(filter)));
  return Qnil;
}


#ifdef PH_CALLBACK
VALUE ph_freq_set_on_count_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetFrequencyCounter_set_OnCount_Handler((CPhidgetFrequencyCounterHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetFrequencyCounter_set_OnCount_Handler((CPhidgetFrequencyCounterHandle)ph->handle, ph_freq_on_count, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_freq_on_count(CPhidgetFrequencyCounterHandle phid, void *userPtr, int index, int time, int counts) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

