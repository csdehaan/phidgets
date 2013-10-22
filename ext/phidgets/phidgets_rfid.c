
#include "phidgets.h"


VALUE ph_rfid_init(VALUE self);
VALUE ph_rfid_get_output_count(VALUE self);
VALUE ph_rfid_get_output_state(VALUE self, VALUE index);
VALUE ph_rfid_set_output_state(VALUE self, VALUE index, VALUE state);
VALUE ph_rfid_get_antenna_on(VALUE self);
VALUE ph_rfid_set_antenna_on(VALUE self, VALUE on);
VALUE ph_rfid_get_led_on(VALUE self);
VALUE ph_rfid_set_led_on(VALUE self, VALUE on);
VALUE ph_rfid_get_last_tag(VALUE self);
VALUE ph_rfid_get_tag_status(VALUE self);
VALUE ph_rfid_write(VALUE self, VALUE tag, VALUE protocol, VALUE lock);

#ifdef PH_CALLBACK
VALUE ph_rfid_set_on_tag_handler(VALUE self, VALUE handler);
VALUE ph_rfid_set_on_tag_lost_handler(VALUE self, VALUE handler);
VALUE ph_rfid_set_on_output_change_handler(VALUE self, VALUE handler);
int ph_rfid_on_tag(CPhidgetRFIDHandle phid, void *userPtr, char *tagString, CPhidgetRFID_Protocol protocol);
int ph_rfid_on_tag_lost(CPhidgetRFIDHandle phid, void *userPtr, char *tagString, CPhidgetRFID_Protocol protocol);
int ph_rfid_on_output_change(CPhidgetRFIDHandle phid, void *userPtr, int index, int state);
#endif


void Init_rfid() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_rfid = rb_define_class_under(ph_module, "RFID", ph_common);

  /* EM4100 (EM4102) 40-bit */
  rb_define_const(ph_rfid, "PROTOCOL_EM4100", INT2FIX(PHIDGET_RFID_PROTOCOL_EM4100));
  /* ISO11785 FDX-B encoding (Animal ID) */
  rb_define_const(ph_rfid, "PROTOCOL_ISO11785_FDX_B", INT2FIX(PHIDGET_RFID_PROTOCOL_ISO11785_FDX_B));
  /* PhidgetTAG Protocol 24 character ASCII */
  rb_define_const(ph_rfid, "PROTOCOL_PHIDGETS", INT2FIX(PHIDGET_RFID_PROTOCOL_PHIDGETS));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget RFID object.
   */
  rb_define_method(ph_rfid, "initialize", ph_rfid_init, 0);

  /* Document-method: getOutputCount
   * call-seq: getOutputCount -> count
   *
   * Gets the number of outputs supported by this board.
   */
  rb_define_method(ph_rfid, "getOutputCount", ph_rfid_get_output_count, 0);

  /* Document-method: getOutputState
   * call-seq: getOutputState(index) -> true or false
   *
   * Gets the state of an output.
   */
  rb_define_method(ph_rfid, "getOutputState", ph_rfid_get_output_state, 1);

  /* Document-method: setOutputState
   * call-seq: setOutputState(index, state)
   *
   * Sets the state of an output.
   */
  rb_define_method(ph_rfid, "setOutputState", ph_rfid_set_output_state, 2);

  /* Document-method: getAntennaOn
   * call-seq: getAntennaOn -> true or false
   *
   * Gets the state of the antenna.
   */
  rb_define_method(ph_rfid, "getAntennaOn", ph_rfid_get_antenna_on, 0);

  /* Document-method: setAntennaOn
   * call-seq: setAntennaOn(state)
   *
   * Sets the state of the antenna. Note that the antenna must be enabled before tags will be read.
   */
  rb_define_method(ph_rfid, "setAntennaOn", ph_rfid_set_antenna_on, 1);

  /* Document-method: getLEDOn
   * call-seq: getLEDOn -> true or false
   *
   * Gets the state of the onboard LED.
   */
  rb_define_method(ph_rfid, "getLEDOn", ph_rfid_get_led_on, 0);

  /* Document-method: setLEDOn
   * call-seq: setLEDOn(state)
   *
   * Sets the state of the onboard LED.
   */
  rb_define_method(ph_rfid, "setLEDOn", ph_rfid_set_led_on, 1);

  /* Document-method: getLastTag
   * call-seq: getLastTag -> tag
   *
   * Gets the last tag read by the reader. This tag may or may not still be on the reader.
   */
  rb_define_method(ph_rfid, "getLastTag", ph_rfid_get_last_tag, 0);

  /* Document-method: getTagStatus
   * call-seq: getTagStatus -> true or false
   *
   * Gets the tag present status. This is whether or not a tag is being read by the reader.
   */
  rb_define_method(ph_rfid, "getTagStatus", ph_rfid_get_tag_status, 0);

  /* Document-method: write
   * call-seq: write(tag, protocol, lock)
   *
   * Program a tag. This requires a T5577 tag.
   */
  rb_define_method(ph_rfid, "write", ph_rfid_write, 3);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_rfid, "ext_setOnTagHandler", ph_rfid_set_on_tag_handler, 1);
  rb_define_private_method(ph_rfid, "ext_setOnTagLostHandler", ph_rfid_set_on_tag_lost_handler, 1);
  rb_define_private_method(ph_rfid, "ext_setOnOutputChangeHandler", ph_rfid_set_on_output_change_handler, 1);
#endif

  rb_define_alias(ph_rfid, "output_count", "getOutputCount");
  rb_define_alias(ph_rfid, "output_state", "getOutputState");
  rb_define_alias(ph_rfid, "set_output_state", "setOutputState");
  rb_define_alias(ph_rfid, "antenna_on?", "getAntennaOn");
  rb_define_alias(ph_rfid, "antenna_on=", "setAntennaOn");
  rb_define_alias(ph_rfid, "led_on?", "getLEDOn");
  rb_define_alias(ph_rfid, "led_on=", "setLEDOn");
  rb_define_alias(ph_rfid, "last_tag", "getLastTag");
  rb_define_alias(ph_rfid, "tag_status", "getTagStatus");
}



VALUE ph_rfid_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetRFID_create((CPhidgetRFIDHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_rfid_get_output_count(VALUE self) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetRFID_getOutputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_rfid_get_output_state(VALUE self, VALUE index) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetRFID_getOutputState(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_rfid_set_output_state(VALUE self, VALUE index, VALUE state) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  ph_raise(CPhidgetRFID_setOutputState(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_rfid_get_antenna_on(VALUE self) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  int on;
  ph_raise(CPhidgetRFID_getAntennaOn(handle, &on));
  return on == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_rfid_set_antenna_on(VALUE self, VALUE on) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  ph_raise(CPhidgetRFID_setAntennaOn(handle, TYPE(on) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_rfid_get_led_on(VALUE self) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  int on;
  ph_raise(CPhidgetRFID_getLEDOn(handle, &on));
  return on == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_rfid_set_led_on(VALUE self, VALUE on) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  ph_raise(CPhidgetRFID_setLEDOn(handle, TYPE(on) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_rfid_get_last_tag(VALUE self) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  char *tag;
  CPhidgetRFID_Protocol protocol;
  ph_raise(CPhidgetRFID_getLastTag2(handle, &tag, &protocol));
  return rb_ary_new3(2, rb_str_new2(tag), INT2FIX(protocol));
}

VALUE ph_rfid_get_tag_status(VALUE self) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  int status;
  ph_raise(CPhidgetRFID_getTagStatus(handle, &status));
  return status == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_rfid_write(VALUE self, VALUE tag, VALUE protocol, VALUE lock) {
  CPhidgetRFIDHandle handle = (CPhidgetRFIDHandle)get_ph_handle(self);
  ph_raise(CPhidgetRFID_write(handle, StringValueCStr(tag), FIX2INT(protocol), TYPE(lock) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

#ifdef PH_CALLBACK
VALUE ph_rfid_set_on_tag_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetRFID_set_OnTag2_Handler((CPhidgetRFIDHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetRFID_set_OnTag2_Handler((CPhidgetRFIDHandle)ph->handle, ph_rfid_on_tag, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_rfid_set_on_tag_lost_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetRFID_set_OnTagLost2_Handler((CPhidgetRFIDHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetRFID_set_OnTagLost2_Handler((CPhidgetRFIDHandle)ph->handle, ph_rfid_on_tag_lost, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_rfid_set_on_output_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_3;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetRFID_set_OnOutputChange_Handler((CPhidgetRFIDHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetRFID_set_OnOutputChange_Handler((CPhidgetRFIDHandle)ph->handle, ph_rfid_on_output_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_rfid_on_tag(CPhidgetRFIDHandle phid, void *userPtr, char *tagString, CPhidgetRFID_Protocol protocol) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_rfid_on_tag_lost(CPhidgetRFIDHandle phid, void *userPtr, char *tagString, CPhidgetRFID_Protocol protocol) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_rfid_on_output_change(CPhidgetRFIDHandle phid, void *userPtr, int index, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif

