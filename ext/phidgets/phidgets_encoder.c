
#include "phidgets.h"

#define ENCODER_POSITION_CHANGE_CALLBACK  0


VALUE ph_encoder_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetEncoder_create((PhidgetEncoderHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_encoder_get_enabled(VALUE self) {
  return ph_get_bool(get_ph_handle(self), PhidgetEncoder_getEnabled);
}

VALUE ph_encoder_set_enabled(VALUE self, VALUE state) {
  ph_raise(PhidgetEncoder_setEnabled((PhidgetEncoderHandle)get_ph_handle(self), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_encoder_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetEncoder_getDataInterval);
}

VALUE ph_encoder_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetEncoder_setDataInterval((PhidgetEncoderHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_encoder_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetEncoder_getMinDataInterval);
}

VALUE ph_encoder_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetEncoder_getMaxDataInterval);
}

VALUE ph_encoder_get_index_position(VALUE self) {
  return ph_get_int64(get_ph_handle(self), PhidgetEncoder_getIndexPosition);
}

VALUE ph_encoder_get_io_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), PhidgetEncoder_getIOMode);
}

VALUE ph_encoder_set_io_mode(VALUE self, VALUE mode) {
  ph_raise(PhidgetEncoder_setIOMode((PhidgetEncoderHandle)get_ph_handle(self), NUM2INT(mode)));
  return Qnil;
}

VALUE ph_encoder_get_position(VALUE self) {
  return ph_get_int64(get_ph_handle(self), PhidgetEncoder_getPosition);
}

VALUE ph_encoder_set_position(VALUE self, VALUE position) {
  ph_raise(PhidgetEncoder_setPosition((PhidgetEncoderHandle)get_ph_handle(self), NUM2LL(position)));
  return Qnil;
}

VALUE ph_encoder_get_position_change_trigger(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetEncoder_getPositionChangeTrigger);
}

VALUE ph_encoder_set_position_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetEncoder_setPositionChangeTrigger((PhidgetEncoderHandle)get_ph_handle(self), NUM2UINT(trigger)));
  return Qnil;
}

VALUE ph_encoder_get_min_position_change_trigger(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetEncoder_getMinPositionChangeTrigger);
}

VALUE ph_encoder_get_max_position_change_trigger(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetEncoder_getMaxPositionChangeTrigger);
}


void CCONV ph_encoder_on_position_change(PhidgetEncoderHandle phid, void *userPtr, int position_change, double time_change, int index_triggered) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = INT2NUM(position_change);
  callback_data->arg2 = DBL2NUM(time_change);
  callback_data->arg3 = INT2NUM(index_triggered);
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_encoder_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[ENCODER_POSITION_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetEncoder_setOnPositionChangeHandler((PhidgetEncoderHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetEncoder_setOnPositionChangeHandler((PhidgetEncoderHandle)ph->handle, ph_encoder_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_encoder() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_encoder = rb_define_class_under(ph_module, "Encoder", ph_common);

  rb_define_const(ph_encoder, "IO_MODE_PUSH_PULL", INT2NUM(ENCODER_IO_MODE_PUSH_PULL));
  rb_define_const(ph_encoder, "IO_MODE_LINE_DRIVER_2K2", INT2NUM(ENCODER_IO_MODE_LINE_DRIVER_2K2));
  rb_define_const(ph_encoder, "IO_MODE_LINE_DRIVER_10K", INT2NUM(ENCODER_IO_MODE_LINE_DRIVER_10K));
  rb_define_const(ph_encoder, "IO_MODE_OPEN_COLLECTOR_2K2", INT2NUM(ENCODER_IO_MODE_OPEN_COLLECTOR_2K2));
  rb_define_const(ph_encoder, "IO_MODE_OPEN_COLLECTOR_10K", INT2NUM(ENCODER_IO_MODE_OPEN_COLLECTOR_10K));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Encoder object.
   */
  rb_define_method(ph_encoder, "initialize", ph_encoder_init, 0);

  /* Document-method: getEnabled
   * call-seq: getEnabled -> true or false
   *
   * The enabled state of the encoder.
   */
  rb_define_method(ph_encoder, "getEnabled", ph_encoder_get_enabled, 0);
  rb_define_alias(ph_encoder, "enabled?", "getEnabled");

  /* Document-method: setEnabled
   * call-seq: setEnabled(state)
   *
   * The enabled state of the encoder.
   */
  rb_define_method(ph_encoder, "setEnabled", ph_encoder_set_enabled, 1);
  rb_define_alias(ph_encoder, "enabled=", "setEnabled");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another PositionChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between PositionChange events can also affected by the PositionChangeTrigger.
   */
  rb_define_method(ph_encoder, "getDataInterval", ph_encoder_get_data_interval, 0);
  rb_define_alias(ph_encoder, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another PositionChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between PositionChange events can also affected by the PositionChangeTrigger.
   */
  rb_define_method(ph_encoder, "setDataInterval", ph_encoder_set_data_interval, 1);
  rb_define_alias(ph_encoder, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_encoder, "getMinDataInterval", ph_encoder_get_min_data_interval, 0);
  rb_define_alias(ph_encoder, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_encoder, "getMaxDataInterval", ph_encoder_get_max_data_interval, 0);
  rb_define_alias(ph_encoder, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getIndexPosition
   * call-seq: getIndexPosition -> position
   *
   * The most recent position of the index channel calculated by the Phidgets library.
   * The index channel will usually pulse once per rotation.
   * Setting the encoder position will move the index position the same amount so their relative position stays the same.
   * Index position is tracked locally as the last position at which the index was triggered.
   * Setting position will only affect the local copy of the index position value. This means that index positions seen by multiple network applications may not agree.
   */
  rb_define_method(ph_encoder, "getIndexPosition", ph_encoder_get_index_position, 0);
  rb_define_alias(ph_encoder, "index_position", "getIndexPosition");

  /* Document-method: getIOMode
   * call-seq: getIOMode -> mode
   *
   * The encoder interface mode. Match the mode to the type of encoder you have attached.
   * It is recommended to only change this when the encoder disabled in order to avoid unexpected results.
   */
  rb_define_method(ph_encoder, "getIOMode", ph_encoder_get_io_mode, 0);
  rb_define_alias(ph_encoder, "io_mode", "getIOMode");

  /* Document-method: setIOMode
   * call-seq: setIOMode(mode)
   *
   * The encoder interface mode. Match the mode to the type of encoder you have attached.
   * It is recommended to only change this when the encoder disabled in order to avoid unexpected results.
   */
  rb_define_method(ph_encoder, "setIOMode", ph_encoder_set_io_mode, 1);
  rb_define_alias(ph_encoder, "io_mode=", "setIOMode");

  /* Document-method: getPosition
   * call-seq: getPosition -> position
   *
   * The most recent position value calculated by the Phidgets library.
   * Position counts quadrature edges within a quadrature cycle. This means there are four counts per full quadrature cycle.
   * Position is tracked locally as the total position change from the time the channel is opened.
   * Setting position will only affect the local copy of the position value. This means that positions seen by multiple network applications may not agree.
   */
  rb_define_method(ph_encoder, "getPosition", ph_encoder_get_position, 0);
  rb_define_alias(ph_encoder, "position", "getPosition");

  /* Document-method: setPosition
   * call-seq: setPosition(position)
   *
   * The most recent position value calculated by the Phidgets library.
   * Position counts quadrature edges within a quadrature cycle. This means there are four counts per full quadrature cycle.
   * Position is tracked locally as the total position change from the time the channel is opened.
   * Setting position will only affect the local copy of the position value. This means that positions seen by multiple network applications may not agree.
   */
  rb_define_method(ph_encoder, "setPosition", ph_encoder_set_position, 1);
  rb_define_alias(ph_encoder, "position=", "setPosition");

  /* Document-method: getPositionChangeTrigger
   * call-seq: getPositionChangeTrigger -> trigger
   *
   * The channel will not issue a PositionChange event until the position value has changed by the amount specified by the PositionChangeTrigger.
   * Setting the PositionChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_encoder, "getPositionChangeTrigger", ph_encoder_get_position_change_trigger, 0);
  rb_define_alias(ph_encoder, "position_change_trigger", "getPositionChangeTrigger");

  /* Document-method: setPositionChangeTrigger
   * call-seq: setPositionChangeTrigger(trigger)
   *
   * The channel will not issue a PositionChange event until the position value has changed by the amount specified by the PositionChangeTrigger.
   * Setting the PositionChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_encoder, "setPositionChangeTrigger", ph_encoder_set_position_change_trigger, 1);
  rb_define_alias(ph_encoder, "position_change_trigger=", "setPositionChangeTrigger");

  /* Document-method: getMinPositionChangeTrigger
   * call-seq: getMinPositionChangeTrigger -> trigger
   *
   * The minimum value that PositionChangeTrigger can be set to.
   */
  rb_define_method(ph_encoder, "getMinPositionChangeTrigger", ph_encoder_get_min_position_change_trigger, 0);
  rb_define_alias(ph_encoder, "min_position_change_trigger", "getMinPositionChangeTrigger");

  /* Document-method: getMaxPositionChangeTrigger
   * call-seq: getMaxPositionChangeTrigger -> trigger
   *
   * The maximum value that PositionChangeTrigger can be set to.
   */
  rb_define_method(ph_encoder, "getMaxPositionChangeTrigger", ph_encoder_get_max_position_change_trigger, 0);
  rb_define_alias(ph_encoder, "max_position_change_trigger", "getMaxPositionChangeTrigger");

  rb_define_private_method(ph_encoder, "ext_setOnPositionChangeHandler", ph_encoder_set_on_position_change_handler, 1);
}

