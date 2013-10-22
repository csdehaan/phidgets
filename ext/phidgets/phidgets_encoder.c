
#include "phidgets.h"


VALUE ph_encoder_init(VALUE self);
VALUE ph_encoder_get_input_count(VALUE self);
VALUE ph_encoder_get_input_state(VALUE self, VALUE index);
VALUE ph_encoder_get_encoder_count(VALUE self);
VALUE ph_encoder_get_position(VALUE self, VALUE index);
VALUE ph_encoder_set_position(VALUE self, VALUE index, VALUE position);
VALUE ph_encoder_get_index_position(VALUE self, VALUE index);
VALUE ph_encoder_get_enabled(VALUE self, VALUE index);
VALUE ph_encoder_set_enabled(VALUE self, VALUE index, VALUE state);

#ifdef PH_CALLBACK
VALUE ph_encoder_set_on_input_change_handler(VALUE self, VALUE handler);
VALUE ph_encoder_set_on_position_change_handler(VALUE self, VALUE handler);
VALUE ph_encoder_set_on_index_handler(VALUE self, VALUE handler);
int ph_encoder_on_input_change(CPhidgetEncoderHandle phid, void *userPtr, int index, int state);
int ph_encoder_on_position_change(CPhidgetEncoderHandle phid, void *userPtr, int index, int time, int change);
int ph_encoder_on_index(CPhidgetEncoderHandle phid, void *userPtr, int index, int index_pos);
#endif


void Init_encoder() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_encoder = rb_define_class_under(ph_module, "Encoder", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Encoder object.
   */
  rb_define_method(ph_encoder, "initialize", ph_encoder_init, 0);

  /* Document-method: getInputCount
   * call-seq: getInputCount -> count
   *
   * Gets the number of digital inputs supported by this board.
   */
  rb_define_method(ph_encoder, "getInputCount", ph_encoder_get_input_count, 0);

  /* Document-method: getInputState
   * call-seq: getInputState(index) -> true or false
   *
   * Gets the state of a digital input.
   */
  rb_define_method(ph_encoder, "getInputState", ph_encoder_get_input_state, 1);

  /* Document-method: getEncoderCount
   * call-seq: getEncoderCount -> count
   *
   * Gets the number of encoder inputs supported by this board.
   */
  rb_define_method(ph_encoder, "getEncoderCount", ph_encoder_get_encoder_count, 0);

  /* Document-method: getPosition
   * call-seq: getPosition(index) -> position
   *
   * Gets the current position of an encoder.
   */
  rb_define_method(ph_encoder, "getPosition", ph_encoder_get_position, 1);

  /* Document-method: setPosition
   * call-seq: setPosition(index, position)
   *
   * Sets the current position of an encoder.
   */
  rb_define_method(ph_encoder, "setPosition", ph_encoder_set_position, 2);

  /* Document-method: getIndexPosition
   * call-seq: getIndexPosition(index) -> position
   *
   * Gets the position of the last index pulse, as referenced to getPosition. This will raise Phidgets::Error::UnknownVal
   * if there hasn't been an index event, or if the encoder doesn't support index.
   */
  rb_define_method(ph_encoder, "getIndexPosition", ph_encoder_get_index_position, 1);

  /* Document-method: getEnabled
   * call-seq: getEnabled(index) -> true or false
   *
   * Gets the enabled state of an encoder. This is whether the encoder is powered or not.
   */
  rb_define_method(ph_encoder, "getEnabled", ph_encoder_get_enabled, 1);

  /* Document-method: setEnabled
   * call-seq: setEnabled(index, state)
   *
   * Sets the enabled state of an encoder. This is whether the encoder is powered or not.
   */
  rb_define_method(ph_encoder, "setEnabled", ph_encoder_set_enabled, 2);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_encoder, "ext_setOnInputChangeHandler", ph_encoder_set_on_input_change_handler, 1);
  rb_define_private_method(ph_encoder, "ext_setOnPositionChangeHandler", ph_encoder_set_on_position_change_handler, 1);
  rb_define_private_method(ph_encoder, "ext_setOnIndexHandler", ph_encoder_set_on_index_handler, 1);
#endif

  rb_define_alias(ph_encoder, "input_count", "getInputCount");
  rb_define_alias(ph_encoder, "input_state", "getInputState");
  rb_define_alias(ph_encoder, "encoder_count", "getEncoderCount");
  rb_define_alias(ph_encoder, "position", "getPosition");
  rb_define_alias(ph_encoder, "set_position", "setPosition");
  rb_define_alias(ph_encoder, "index_position", "getIndexPosition");
  rb_define_alias(ph_encoder, "enabled?", "getEnabled");
  rb_define_alias(ph_encoder, "set_enabled", "setEnabled");
}



VALUE ph_encoder_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetEncoder_create((CPhidgetEncoderHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_encoder_get_input_count(VALUE self) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetEncoder_getInputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_encoder_get_input_state(VALUE self, VALUE index) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetEncoder_getInputState(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_encoder_get_encoder_count(VALUE self) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetEncoder_getEncoderCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_encoder_get_position(VALUE self, VALUE index) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  int position;
  ph_raise(CPhidgetEncoder_getPosition(handle, FIX2INT(index), &position));
  return INT2FIX(position);
}

VALUE ph_encoder_set_position(VALUE self, VALUE index, VALUE position) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  ph_raise(CPhidgetEncoder_setPosition(handle, FIX2INT(index), FIX2INT(position)));
  return Qnil;
}

VALUE ph_encoder_get_index_position(VALUE self, VALUE index) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  int position;
  ph_raise(CPhidgetEncoder_getIndexPosition(handle, FIX2INT(index), &position));
  return INT2FIX(position);
}

VALUE ph_encoder_get_enabled(VALUE self, VALUE index) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetEncoder_getEnabled(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_encoder_set_enabled(VALUE self, VALUE index, VALUE state) {
  CPhidgetEncoderHandle handle = (CPhidgetEncoderHandle)get_ph_handle(self);
  ph_raise(CPhidgetEncoder_setEnabled(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}


#ifdef PH_CALLBACK
VALUE ph_encoder_set_on_input_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetEncoder_set_OnInputChange_Handler((CPhidgetEncoderHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetEncoder_set_OnInputChange_Handler((CPhidgetEncoderHandle)ph->handle, ph_encoder_on_input_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_encoder_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetEncoder_set_OnPositionChange_Handler((CPhidgetEncoderHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetEncoder_set_OnPositionChange_Handler((CPhidgetEncoderHandle)ph->handle, ph_encoder_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_encoder_set_on_index_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_3;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetEncoder_set_OnIndex_Handler((CPhidgetEncoderHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetEncoder_set_OnIndex_Handler((CPhidgetEncoderHandle)ph->handle, ph_encoder_on_index, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_encoder_on_input_change(CPhidgetEncoderHandle phid, void *userPtr, int index, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_encoder_on_position_change(CPhidgetEncoderHandle phid, void *userPtr, int index, int time, int change) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_encoder_on_index(CPhidgetEncoderHandle phid, void *userPtr, int index, int index_pos) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

