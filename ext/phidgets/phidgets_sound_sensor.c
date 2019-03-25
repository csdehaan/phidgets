
#include "phidgets.h"

#define SOUND_SENSOR_SPL_CHANGE_CALLBACK    0


VALUE ph_sound_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetSoundSensor_create((PhidgetSoundSensorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_sound_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetSoundSensor_getDataInterval);
}

VALUE ph_sound_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetSoundSensor_setDataInterval((PhidgetSoundSensorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_sound_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetSoundSensor_getMinDataInterval);
}

VALUE ph_sound_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetSoundSensor_getMaxDataInterval);
}

VALUE ph_sound_get_db(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getdB);
}

VALUE ph_sound_get_max_db(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getMaxdB);
}

VALUE ph_sound_get_dba(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getdBA);
}

VALUE ph_sound_get_dbc(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getdBC);
}

VALUE ph_sound_get_noise_floor(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getNoiseFloor);
}

VALUE ph_sound_get_octaves(VALUE self) {
  double octaves[10];
  ph_raise(PhidgetSoundSensor_getOctaves((PhidgetSoundSensorHandle)get_ph_handle(self), &octaves));
  return rb_ary_new3(10, DBL2NUM(octaves[0]), DBL2NUM(octaves[1]), DBL2NUM(octaves[2]), DBL2NUM(octaves[3]), DBL2NUM(octaves[4]), DBL2NUM(octaves[5]), DBL2NUM(octaves[6]), DBL2NUM(octaves[7]), DBL2NUM(octaves[8]), DBL2NUM(octaves[9]));
}

VALUE ph_sound_get_spl_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getSPLChangeTrigger);
}

VALUE ph_sound_set_spl_change_trigger(VALUE self, VALUE change_trigger) {
  ph_raise(PhidgetSoundSensor_setSPLChangeTrigger((PhidgetSoundSensorHandle)get_ph_handle(self), NUM2DBL(change_trigger)));
  return Qnil;
}

VALUE ph_sound_get_min_spl_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getMinSPLChangeTrigger);
}

VALUE ph_sound_get_max_spl_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetSoundSensor_getMaxSPLChangeTrigger);
}

VALUE ph_sound_get_spl_range(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetSoundSensor_getSPLRange);
}

VALUE ph_sound_set_spl_range(VALUE self, VALUE spl_range) {
  ph_raise(PhidgetSoundSensor_setSPLRange((PhidgetSoundSensorHandle)get_ph_handle(self), NUM2INT(spl_range)));
  return Qnil;
}


void CCONV ph_sound_on_spl_change(PhidgetSoundSensorHandle phid, void *userPtr, double db, double dba, double dbc, const double octaves[10]) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(db);
  callback_data->arg2 = DBL2NUM(dba);
  callback_data->arg3 = DBL2NUM(dbc);
  callback_data->arg4 = rb_ary_new3(10, DBL2NUM(octaves[0]), DBL2NUM(octaves[1]), DBL2NUM(octaves[2]), DBL2NUM(octaves[3]), DBL2NUM(octaves[4]), DBL2NUM(octaves[5]), DBL2NUM(octaves[6]), DBL2NUM(octaves[7]), DBL2NUM(octaves[8]), DBL2NUM(octaves[9]));
  sem_post(&callback_data->sem);
}


VALUE ph_sound_set_on_spl_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[SOUND_SENSOR_SPL_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetSoundSensor_setOnSPLChangeHandler((PhidgetSoundSensorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetSoundSensor_setOnSPLChangeHandler((PhidgetSoundSensorHandle)ph->handle, ph_sound_on_spl_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_sound() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_sound = rb_define_class_under(ph_module, "SoundSensor", ph_common);


  rb_define_const(ph_sound, "SPL_RANGE_102dB", INT2NUM(SPL_RANGE_102dB));
  rb_define_const(ph_sound, "SPL_RANGE_82dB", INT2NUM(SPL_RANGE_82dB));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget SoundSensor object.
   */
  rb_define_method(ph_sound, "initialize", ph_sound_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another SPLChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between SPLChange events can also affected by the SPLChangeTrigger.
   */
  rb_define_method(ph_sound, "getDataInterval", ph_sound_get_data_interval, 0);
  rb_define_alias(ph_sound, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another SPLChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between SPLChange events can also affected by the SPLChangeTrigger.
   */
  rb_define_method(ph_sound, "setDataInterval", ph_sound_set_data_interval, 1);
  rb_define_alias(ph_sound, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_sound, "getMinDataInterval", ph_sound_get_min_data_interval, 0);
  rb_define_alias(ph_sound, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_sound, "getMaxDataInterval", ph_sound_get_max_data_interval, 0);
  rb_define_alias(ph_sound, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getdB
   * call-seq: getdB -> db
   *
   * The most recent dB SPL value that has been calculated.
   * This value is bounded by MaxdB.
   */
  rb_define_method(ph_sound, "getdB", ph_sound_get_db, 0);
  rb_define_alias(ph_sound, "db", "getdB");

  /* Document-method: getMaxdB
   * call-seq: getMaxdB -> db
   *
   * The maximum value the SPLChange event will report.
   */
  rb_define_method(ph_sound, "getMaxdB", ph_sound_get_max_db, 0);
  rb_define_alias(ph_sound, "max_db", "getMaxdB");

  /* Document-method: getdBA
   * call-seq: getdBA -> dba
   *
   * The most recent dBA SPL value that has been calculated.
   * The dBA SPL value is calculated by applying a A-weighted filter to the Octaves data.
   */
  rb_define_method(ph_sound, "getdBA", ph_sound_get_dba, 0);
  rb_define_alias(ph_sound, "dba", "getdBA");

  /* Document-method: getdBC
   * call-seq: getdBC -> dbc
   *
   * The most recent dBC SPL value that has been calculated.
   * The dBC SPL value is calculated by applying a C-weighted filter to the Octaves data.
   */
  rb_define_method(ph_sound, "getdBC", ph_sound_get_dbc, 0);
  rb_define_alias(ph_sound, "dbc", "getdBC");

  /* Document-method: getNoiseFloor
   * call-seq: getNoiseFloor -> noise_floor
   *
   * The minimum SPL value that the channel can accurately measure.
   * Input SPLs below this level will not produce an output from the microphone.
   */
  rb_define_method(ph_sound, "getNoiseFloor", ph_sound_get_noise_floor, 0);
  rb_define_alias(ph_sound, "noise_floor", "getNoiseFloor");

  /* Document-method: getOctaves
   * call-seq: getOctaves -> octaves
   *
   * The unweighted value of each frequency band.
   * The following frequency bands are represented:
   *   octaves[0] = 31.5 Hz
   *   octaves[1] = 63 Hz
   *   octaves[2] = 125 Hz
   *   octaves[3] = 250 Hz
   *   octaves[4] = 500 Hz
   *   octaves[5] = 1 kHz
   *   octaves[6] = 2 kHz
   *   octaves[7] = 4 kHz
   *   octaves[8] = 8 kHz
   *   octaves[9] = 16 kHz
   */
  rb_define_method(ph_sound, "getOctaves", ph_sound_get_octaves, 0);
  rb_define_alias(ph_sound, "octaves", "getOctaves");

  /* Document-method: getSPLChangeTrigger
   * call-seq: getSPLChangeTrigger -> change_trigger
   *
   * The channel will not issue a SPLChange event until the dB value has changed by the amount specified by the SPLChangeTrigger.
   * Setting the SPLChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_sound, "getSPLChangeTrigger", ph_sound_get_spl_change_trigger, 0);
  rb_define_alias(ph_sound, "spl_change_trigger", "getSPLChangeTrigger");

  /* Document-method: setSPLChangeTrigger
   * call-seq: setSPLChangeTrigger(change_trigger)
   *
   * The channel will not issue a SPLChange event until the dB value has changed by the amount specified by the SPLChangeTrigger.
   * Setting the SPLChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_sound, "setSPLChangeTrigger", ph_sound_set_spl_change_trigger, 1);
  rb_define_alias(ph_sound, "spl_change_trigger=", "setSPLChangeTrigger");

  /* Document-method: getMinSPLChangeTrigger
   * call-seq: getMinSPLChangeTrigger -> change_trigger
   *
   * The minimum value that SPLChangeTrigger can be set to.
   */
  rb_define_method(ph_sound, "getMinSPLChangeTrigger", ph_sound_get_min_spl_change_trigger, 0);
  rb_define_alias(ph_sound, "min_spl_change_trigger", "getMinSPLChangeTrigger");

  /* Document-method: getMaxSPLChangeTrigger
   * call-seq: getMaxSPLChangeTrigger -> change_trigger
   *
   * The maximum value that SPLChangeTrigger can be set to.
   */
  rb_define_method(ph_sound, "getMaxSPLChangeTrigger", ph_sound_get_max_spl_change_trigger, 0);
  rb_define_alias(ph_sound, "max_spl_change_trigger", "getMaxSPLChangeTrigger");

  /* Document-method: getSPLRange
   * call-seq: getSPLRange -> spl_range
   *
   * When selecting a range, first decide how sensitive you want the microphone to be. Select a smaller range when you want more sensitivity from the microphone.
   * If a Saturation event occurrs, increase the range.
   */
  rb_define_method(ph_sound, "getSPLRange", ph_sound_get_spl_range, 0);
  rb_define_alias(ph_sound, "spl_range", "getSPLRange");

  /* Document-method: setSPLRange
   * call-seq: setSPLRange(spl_range)
   *
   * When selecting a range, first decide how sensitive you want the microphone to be. Select a smaller range when you want more sensitivity from the microphone.
   * If a Saturation event occurrs, increase the range.
   */
  rb_define_method(ph_sound, "setSPLRange", ph_sound_set_spl_range, 1);
  rb_define_alias(ph_sound, "spl_range=", "setSPLRange");


  rb_define_private_method(ph_sound, "ext_setOnSPLChangeHandler", ph_sound_set_on_spl_change_handler, 1);
}

