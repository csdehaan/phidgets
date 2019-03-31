
#include "phidgets.h"

#define RFID_TAG_CALLBACK        0
#define RFID_TAG_LOST_CALLBACK   1



VALUE ph_rfid_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetRFID_create((PhidgetRFIDHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_rfid_get_antenna_enabled(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetRFID_getAntennaEnabled);
}

VALUE ph_rfid_set_antenna_enabled(VALUE self, VALUE on) {
  ph_raise(PhidgetRFID_setAntennaEnabled((PhidgetRFIDHandle)get_ph_handle(self), TYPE(on) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_rfid_get_last_tag(VALUE self) {
  char tag[256];
  PhidgetRFID_Protocol protocol;
  ph_raise(PhidgetRFID_getLastTag((PhidgetRFIDHandle)get_ph_handle(self), tag, 256, &protocol));
  return rb_ary_new3(2, rb_str_new2(tag), INT2NUM(protocol));
}

VALUE ph_rfid_get_tag_present(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetRFID_getTagPresent);
}

VALUE ph_rfid_write(VALUE self, VALUE tag, VALUE protocol, VALUE lock) {
  ph_raise(PhidgetRFID_write((PhidgetRFIDHandle)get_ph_handle(self), StringValueCStr(tag), NUM2INT(protocol), TYPE(lock) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}


void CCONV ph_rfid_on_tag(PhidgetRFIDHandle phid, void *userPtr, const char *tagString, PhidgetRFID_Protocol protocol) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = rb_str_new2(tagString);
  callback_data->arg2 = INT2NUM(protocol);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}

VALUE ph_rfid_set_on_tag_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[RFID_TAG_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetRFID_setOnTagHandler((PhidgetRFIDHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetRFID_setOnTagHandler((PhidgetRFIDHandle)ph->handle, ph_rfid_on_tag, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_rfid_on_tag_lost(PhidgetRFIDHandle phid, void *userPtr, const char *tagString, PhidgetRFID_Protocol protocol) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = rb_str_new2(tagString);
  callback_data->arg2 = INT2NUM(protocol);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}

VALUE ph_rfid_set_on_tag_lost_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[RFID_TAG_LOST_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetRFID_setOnTagLostHandler((PhidgetRFIDHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetRFID_setOnTagLostHandler((PhidgetRFIDHandle)ph->handle, ph_rfid_on_tag, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_rfid() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_rfid = rb_define_class_under(ph_module, "RFID", ph_common);

  /* EM4100 (EM4102) 40-bit */
  rb_define_const(ph_rfid, "PROTOCOL_EM4100", INT2NUM(PROTOCOL_EM4100));
  /* ISO11785 FDX-B encoding (Animal ID) */
  rb_define_const(ph_rfid, "PROTOCOL_ISO11785_FDX_B", INT2NUM(PROTOCOL_ISO11785_FDX_B));
  /* PhidgetTAG Protocol 24 character ASCII */
  rb_define_const(ph_rfid, "PROTOCOL_PHIDGETS", INT2NUM(PROTOCOL_PHIDGETS));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget RFID object.
   */
  rb_define_method(ph_rfid, "initialize", ph_rfid_init, 0);

  /* Document-method: getAntennaEnabled
   * call-seq: getAntennaEnabled -> true or false
   *
   * The on/off state of the antenna.
   * You can turn the antenna off to save power.
   * You must turn the antenna on in order to detect and read RFID tags.
   */
  rb_define_method(ph_rfid, "getAntennaEnabled", ph_rfid_get_antenna_enabled, 0);
  rb_define_alias(ph_rfid, "antenna_enabled?", "getAntennaEnabled");

  /* Document-method: setAntennaEnabled
   * call-seq: setAntennaEnabled(state)
   *
   * The on/off state of the antenna.
   * You can turn the antenna off to save power.
   * You must turn the antenna on in order to detect and read RFID tags.
   */
  rb_define_method(ph_rfid, "setAntennaEnabled", ph_rfid_set_antenna_enabled, 1);
  rb_define_alias(ph_rfid, "antenna_enabled=", "setAntennaEnabled");

  /* Document-method: getLastTag
   * call-seq: getLastTag -> tag
   *
   * Gets the most recently read tag's data, even if that tag is no longer within read range.
   * Only valid after at least one tag has been read.
   */
  rb_define_method(ph_rfid, "getLastTag", ph_rfid_get_last_tag, 0);
  rb_define_alias(ph_rfid, "last_tag", "getLastTag");

  /* Document-method: getTagPresent
   * call-seq: getTagPresent -> true or false
   *
   * This property is true if a compatibile RFID tag is being read by the reader.
   * TagPresent will remain true until the tag is out of range and can no longer be read.
   */
  rb_define_method(ph_rfid, "getTagPresent", ph_rfid_get_tag_present, 0);
  rb_define_alias(ph_rfid, "tag_present?", "getTagPresent");

  /* Document-method: write
   * call-seq: write(tag, protocol, lock)
   *
   * Writes data to the tag being currently read by the reader.
   * You cannot write to a read-only or locked tag.
   */
  rb_define_method(ph_rfid, "write", ph_rfid_write, 3);

  rb_define_private_method(ph_rfid, "ext_setOnTagHandler", ph_rfid_set_on_tag_handler, 1);
  rb_define_private_method(ph_rfid, "ext_setOnTagLostHandler", ph_rfid_set_on_tag_lost_handler, 1);
}

