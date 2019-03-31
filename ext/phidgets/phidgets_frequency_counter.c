
#include "phidgets.h"

#define FREQ_COUNTER_COUNT_CHANGE_CALLBACK      0
#define FREQ_COUNTER_FREQUENCY_CHANGE_CALLBACK  1



VALUE ph_freq_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetFrequencyCounter_create((PhidgetFrequencyCounterHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_freq_get_count(VALUE self) {
  return ph_get_uint64(get_ph_handle(self), (phidget_get_uint64_func)PhidgetFrequencyCounter_getCount);
}

VALUE ph_freq_get_enabled(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetFrequencyCounter_getEnabled);
}

VALUE ph_freq_set_enabled(VALUE self, VALUE state) {
  ph_raise(PhidgetFrequencyCounter_setEnabled((PhidgetFrequencyCounterHandle)get_ph_handle(self), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_freq_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetFrequencyCounter_getDataInterval);
}

VALUE ph_freq_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetFrequencyCounter_setDataInterval((PhidgetFrequencyCounterHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_freq_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetFrequencyCounter_getMinDataInterval);
}

VALUE ph_freq_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetFrequencyCounter_getMaxDataInterval);
}

VALUE ph_freq_get_filter_type(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetFrequencyCounter_getFilterType);
}

VALUE ph_freq_set_filter_type(VALUE self, VALUE filter) {
  ph_raise(PhidgetFrequencyCounter_setFilterType((PhidgetFrequencyCounterHandle)get_ph_handle(self), NUM2INT(filter)));
  return Qnil;
}

VALUE ph_freq_get_frequency(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetFrequencyCounter_getFrequency);
}

VALUE ph_freq_get_max_frequency(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetFrequencyCounter_getMaxFrequency);
}

VALUE ph_freq_get_frequency_cutoff(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetFrequencyCounter_getFrequencyCutoff);
}

VALUE ph_freq_set_frequency_cutoff(VALUE self, VALUE cutoff) {
  ph_raise(PhidgetFrequencyCounter_setFrequencyCutoff((PhidgetFrequencyCounterHandle)get_ph_handle(self), NUM2DBL(cutoff)));
  return Qnil;
}

VALUE ph_freq_get_min_frequency_cutoff(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetFrequencyCounter_getMinFrequencyCutoff);
}

VALUE ph_freq_get_max_frequency_cutoff(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetFrequencyCounter_getMaxFrequencyCutoff);
}

VALUE ph_freq_get_input_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetFrequencyCounter_getInputMode);
}

VALUE ph_freq_set_input_mode(VALUE self, VALUE mode) {
  ph_raise(PhidgetFrequencyCounter_setInputMode((PhidgetFrequencyCounterHandle)get_ph_handle(self), NUM2INT(mode)));
  return Qnil;
}

VALUE ph_freq_get_power_supply(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetFrequencyCounter_getPowerSupply);
}

VALUE ph_freq_set_power_supply(VALUE self, VALUE power_supply) {
  ph_raise(PhidgetFrequencyCounter_setPowerSupply((PhidgetFrequencyCounterHandle)get_ph_handle(self), NUM2INT(power_supply)));
  return Qnil;
}

VALUE ph_freq_reset(VALUE self) {
  ph_raise(PhidgetFrequencyCounter_reset((PhidgetFrequencyCounterHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_freq_get_time_elapsed(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetFrequencyCounter_getTimeElapsed);
}


void CCONV ph_freq_on_count_change(PhidgetFrequencyCounterHandle phid, void *userPtr, uint64_t counts, double timeChange) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = ULL2NUM(counts);
  callback_data->arg2 = DBL2NUM(timeChange);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_freq_set_on_count_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[FREQ_COUNTER_COUNT_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetFrequencyCounter_setOnCountChangeHandler((PhidgetFrequencyCounterHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetFrequencyCounter_setOnCountChangeHandler((PhidgetFrequencyCounterHandle)ph->handle, ph_freq_on_count_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_freq_on_frequency_change(PhidgetFrequencyCounterHandle phid, void *userPtr, double frequency) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(frequency);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_freq_set_on_frequency_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[FREQ_COUNTER_FREQUENCY_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetFrequencyCounter_setOnFrequencyChangeHandler((PhidgetFrequencyCounterHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetFrequencyCounter_setOnFrequencyChangeHandler((PhidgetFrequencyCounterHandle)ph->handle, ph_freq_on_frequency_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_frequency_counter() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_freq = rb_define_class_under(ph_module, "FrequencyCounter", ph_common);


  rb_define_const(ph_freq, "FILTER_TYPE_ZERO_CROSSING", INT2NUM(FILTER_TYPE_ZERO_CROSSING));
  rb_define_const(ph_freq, "FILTER_TYPE_LOGIC_LEVEL", INT2NUM(FILTER_TYPE_LOGIC_LEVEL));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget FrequencyCounter object.
   */
  rb_define_method(ph_freq, "initialize", ph_freq_init, 0);

  /* Document-method: getCount
   * call-seq: getCount -> count
   *
   * The most recent count value the channel has reported.
   * The count represents the total number of pulses since the the channel was opened, or last reset.
   */
  rb_define_method(ph_freq, "getCount", ph_freq_get_count, 0);
  rb_define_alias(ph_freq, "count", "getCount");

  /* Document-method: getEnabled
   * call-seq: getEnabled -> true or false
   *
   * Enables or disables the channel.
   * When a channel is disabled, it will not longer register counts, therefore the TimeElapsed and Count will not be updated until the channel is re-enabled.
   */
  rb_define_method(ph_freq, "getEnabled", ph_freq_get_enabled, 0);
  rb_define_alias(ph_freq, "enabled?", "getEnabled");

  /* Document-method: setEnabled
   * call-seq: setEnabled(state)
   *
   * Enables or disables the channel.
   * When a channel is disabled, it will not longer register counts, therefore the TimeElapsed and Count will not be updated until the channel is re-enabled.
   */
  rb_define_method(ph_freq, "setEnabled", ph_freq_set_enabled, 1);
  rb_define_alias(ph_freq, "enabled=", "setEnabled");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another CountChange/FrequencyChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_freq, "getDataInterval", ph_freq_get_data_interval, 0);
  rb_define_alias(ph_freq, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another CountChange/FrequencyChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_freq, "setDataInterval", ph_freq_set_data_interval, 1);
  rb_define_alias(ph_freq, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_freq, "getMinDataInterval", ph_freq_get_min_data_interval, 0);
  rb_define_alias(ph_freq, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_freq, "getMaxDataInterval", ph_freq_get_max_data_interval, 0);
  rb_define_alias(ph_freq, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getFilterType
   * call-seq: getFilterType -> filter_type
   *
   * Determines the signal type that the channel responds to.
   * The filter type is chosen based on the type of input signal. See the PhidgetFrequencyCounter_FilterType entry under Enumerations for more information.
   */
  rb_define_method(ph_freq, "getFilterType", ph_freq_get_filter_type, 0);
  rb_define_alias(ph_freq, "filter_type", "getFilterType");

  /* Document-method: setFilterType
   * call-seq: setFilterType(filter_type)
   *
   * Determines the signal type that the channel responds to.
   * The filter type is chosen based on the type of input signal. See the PhidgetFrequencyCounter_FilterType entry under Enumerations for more information.
   */
  rb_define_method(ph_freq, "setFilterType", ph_freq_set_filter_type, 1);
  rb_define_alias(ph_freq, "filter_type=", "setFilterType");

  /* Document-method: getFrequency
   * call-seq: getFrequency -> frequency
   *
   * The most recent frequency value that the channel has reported.
   * This value will always be between 0 Hz and MaxFrequency.
   */
  rb_define_method(ph_freq, "getFrequency", ph_freq_get_frequency, 0);
  rb_define_alias(ph_freq, "frequency", "getFrequency");

  /* Document-method: getMaxFrequency
   * call-seq: getMaxFrequency -> frequency
   *
   * The maximum value the FrequencyChange event will report.
   */
  rb_define_method(ph_freq, "getMaxFrequency", ph_freq_get_max_frequency, 0);
  rb_define_alias(ph_freq, "max_frequency", "getMaxFrequency");

  /* Document-method: getFrequencyCutoff
   * call-seq: getFrequencyCutoff -> cutoff
   *
   * The frequency at which zero hertz is assumed.
   * This means any frequency at or below the FrequencyCutoff value will be reported as 0 Hz.
   * This property is stored locally, so other users who have this Phidget open over a network connection won't see the effects of your selected cutoff.
   */
  rb_define_method(ph_freq, "getFrequencyCutoff", ph_freq_get_frequency_cutoff, 0);
  rb_define_alias(ph_freq, "frequency_cutoff", "getFrequencyCutoff");

  /* Document-method: setFrequencyCutoff
   * call-seq: setFrequencyCutoff(cutoff)
   *
   * The frequency at which zero hertz is assumed.
   * This means any frequency at or below the FrequencyCutoff value will be reported as 0 Hz.
   * This property is stored locally, so other users who have this Phidget open over a network connection won't see the effects of your selected cutoff.
   */
  rb_define_method(ph_freq, "setFrequencyCutoff", ph_freq_set_frequency_cutoff, 1);
  rb_define_alias(ph_freq, "frequency_cutoff=", "setFrequencyCutoff");

  /* Document-method: getMinFrequencyCutoff
   * call-seq: getMinFrequencyCutoff -> cutoff
   *
   * The minimum value that FrequencyCutoff can be set to.
   */
  rb_define_method(ph_freq, "getMinFrequencyCutoff", ph_freq_get_min_frequency_cutoff, 0);
  rb_define_alias(ph_freq, "min_frequency_cutoff", "getMinFrequencyCutoff");

  /* Document-method: getMaxFrequencyCutoff
   * call-seq: getMaxFrequencyCutoff -> cutoff
   *
   * The maximum value that FrequencyCutoff can be set to.
   */
  rb_define_method(ph_freq, "getMaxFrequencyCutoff", ph_freq_get_max_frequency_cutoff, 0);
  rb_define_alias(ph_freq, "max_frequency_cutoff", "getMaxFrequencyCutoff");

  /* Document-method: getInputMode
   * call-seq: getInputMode -> mode
   *
   * The input polarity mode for your channel.
   * See your device's User Guide for more information about what value to chooose for the InputMode.
   */
  rb_define_method(ph_freq, "getInputMode", ph_freq_get_input_mode, 0);
  rb_define_alias(ph_freq, "input_mode", "getInputMode");

  /* Document-method: setInputMode
   * call-seq: setInputMode(mode)
   *
   * The input polarity mode for your channel.
   * See your device's User Guide for more information about what value to chooose for the InputMode.
   */
  rb_define_method(ph_freq, "setInputMode", ph_freq_set_input_mode, 1);
  rb_define_alias(ph_freq, "input_mode=", "setInputMode");

  /* Document-method: getPowerSupply
   * call-seq: getPowerSupply -> power_supply
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_freq, "getPowerSupply", ph_freq_get_power_supply, 0);
  rb_define_alias(ph_freq, "power_supply", "getPowerSupply");

  /* Document-method: setPowerSupply
   * call-seq: setPowerSupply(power_supply)
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_freq, "setPowerSupply", ph_freq_set_power_supply, 1);
  rb_define_alias(ph_freq, "power_supply=", "setPowerSupply");

  /* Document-method: reset
   * call-seq: reset
   *
   * Resets the Count and TimeElapsed.
   * For best results, reset should be called when the channel is disabled.
   */
  rb_define_method(ph_freq, "reset", ph_freq_reset, 0);

  /* Document-method: getTimeElapsed
   * call-seq: getTimeElapsed -> time
   *
   * The amount of time the frequency counter has been enabled for.
   * This property complements Count, the total number of pulses detected since the channel was opened, or last reset.
   */
  rb_define_method(ph_freq, "getTimeElapsed", ph_freq_get_time_elapsed, 0);
  rb_define_alias(ph_freq, "time_elapsed", "getTimeElapsed");

  rb_define_private_method(ph_freq, "ext_setOnCountChangeHandler", ph_freq_set_on_count_change_handler, 1);
  rb_define_private_method(ph_freq, "ext_setOnFrequencyChangeHandler", ph_freq_set_on_frequency_change_handler, 1);
}

