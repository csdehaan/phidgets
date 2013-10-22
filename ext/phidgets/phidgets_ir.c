
#include "phidgets.h"


VALUE ph_ir_init(VALUE self);
VALUE ph_ir_transmit(VALUE self, VALUE data, VALUE code_info);
VALUE ph_ir_transmit_repeat(VALUE self);
VALUE ph_ir_transmit_raw(VALUE self, VALUE data, VALUE carrier_freq, VALUE duty_cycle, VALUE gap);
VALUE ph_ir_get_raw_data(VALUE self, VALUE length);
VALUE ph_ir_get_last_code(VALUE self);
VALUE ph_ir_get_last_learned_code(VALUE self);

#ifdef PH_CALLBACK
VALUE ph_ir_set_on_code_handler(VALUE self, VALUE handler);
VALUE ph_ir_set_on_learn_handler(VALUE self, VALUE handler);
VALUE ph_ir_set_on_raw_data_handler(VALUE self, VALUE handler);
int ph_ir_on_code(CPhidgetIRHandle phid, void *userPtr, unsigned char *data, int dataLength, int bitCount, int repeat);
int ph_ir_on_learn(CPhidgetIRHandle phid, void *userPtr, unsigned char *data, int dataLength, CPhidgetIR_CodeInfoHandle codeInfo);
int ph_ir_on_raw_data(CPhidgetIRHandle phid, void *userPtr, int *data, int dataLength);
#endif


void Init_ir() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_ir = rb_define_class_under(ph_module, "IR", ph_common);

  /* Unknown - the default value */
  rb_define_const(ph_ir, "ENCODING_UNKNOWN", INT2FIX(PHIDGET_IR_ENCODING_UNKNOWN));
  /* Space encoding, or Pulse Distance Modulation */
  rb_define_const(ph_ir, "ENCODING_SPACE", INT2FIX(PHIDGET_IR_ENCODING_SPACE));
  /* Pulse encoding, or Pulse Width Modulation */
  rb_define_const(ph_ir, "ENCODING_PULSE", INT2FIX(PHIDGET_IR_ENCODING_PULSE));
  /* Bi-Phase, or Manchester encoding */
  rb_define_const(ph_ir, "ENCODING_BIPHASE", INT2FIX(PHIDGET_IR_ENCODING_BIPHASE));
  /* RC5 - a type of Bi-Phase encoding */
  rb_define_const(ph_ir, "ENCODING_RC5", INT2FIX(PHIDGET_IR_ENCODING_RC5));
  /* RC6 - a type of Bi-Phase encoding */
  rb_define_const(ph_ir, "ENCODING_RC6", INT2FIX(PHIDGET_IR_ENCODING_RC6));

  /* Unknown - the default value */
  rb_define_const(ph_ir, "LENGTH_UNKNOWN", INT2FIX(PHIDGET_IR_LENGTH_UNKNOWN));
  /* Constant - the bitstream + gap length is constant */
  rb_define_const(ph_ir, "LENGTH_CONSTANT", INT2FIX(PHIDGET_IR_LENGTH_CONSTANT));
  /* Variable - the bitstream has a variable length with a constant gap */
  rb_define_const(ph_ir, "LENGTH_VARIABLE", INT2FIX(PHIDGET_IR_LENGTH_VARIABLE));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget IR object.
   */
  rb_define_method(ph_ir, "initialize", ph_ir_init, 0);

  /* Document-method: transmit
   * call-seq: transmit(data, code_info)
   *
   * ** NOT IMPLEMENTED **
   */
  rb_define_method(ph_ir, "transmit", ph_ir_transmit, 2);

  /* Document-method: transmitRepeat
   * call-seq: transmitRepeat
   *
   * Transmits a repeat of the last transmited code. Depending of the CodeInfo structure,
   * this may be a retransmission of the code itself, or there may be a special repeat code.
   */
  rb_define_method(ph_ir, "transmitRepeat", ph_ir_transmit_repeat, 0);

  /* Document-method: transmitRaw
   * call-seq: transmitRaw(data, carrier_frequency, duty_cycle, gap)
   *
   * Transmits RAW data as a series of pulses and spaces.
   */
  rb_define_method(ph_ir, "transmitRaw", ph_ir_transmit_raw, 4);

  /* Document-method: getRawData
   * call-seq: getRawData(max_length) -> raw_data
   *
   * Read any available raw data. This should be polled continuously (every 20ms) to avoid missing data.
   * Read data always starts with a space and ends with a pulse.
   */
  rb_define_method(ph_ir, "getRawData", ph_ir_get_raw_data, 1);

  /* Document-method: getLastCode
   * call-seq: getLastCode -> code
   *
   * ** NOT IMPLEMENTED **
   */
  rb_define_method(ph_ir, "getLastCode", ph_ir_get_last_code, 0);

  /* Document-method: getLastLearnedCode
   * call-seq: getLastLearnedCode -> code
   *
   * ** NOT IMPLEMENTED **
   */
  rb_define_method(ph_ir, "getLastLearnedCode", ph_ir_get_last_learned_code, 0);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_ir, "ext_setOnCodeHandler", ph_ir_set_on_code_handler, 1);
  rb_define_private_method(ph_ir, "ext_setOnLearnHandler", ph_ir_set_on_learn_handler, 1);
  rb_define_private_method(ph_ir, "ext_setOnRawDataHandler", ph_ir_set_on_raw_data_handler, 1);
#endif

  rb_define_alias(ph_ir, "transmit_repeat", "transmitRepeat");
  rb_define_alias(ph_ir, "transmit_raw", "transmitRaw");
  rb_define_alias(ph_ir, "raw_data", "getRawData");
  rb_define_alias(ph_ir, "last_code", "getLastCode");
  rb_define_alias(ph_ir, "last_learned_code", "getLastLearnedCode");
}



VALUE ph_ir_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetIR_create((CPhidgetIRHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_ir_transmit(VALUE self, VALUE data, VALUE code_info) {
  ph_raise(EPHIDGET_NOTIMPLEMENTED);
  return Qnil;
}

VALUE ph_ir_transmit_repeat(VALUE self) {
  CPhidgetIRHandle handle = (CPhidgetIRHandle)get_ph_handle(self);
  ph_raise(CPhidgetIR_TransmitRepeat(handle));
  return Qnil;
}

VALUE ph_ir_transmit_raw(VALUE self, VALUE data, VALUE carrier_freq, VALUE duty_cycle, VALUE gap) {
  CPhidgetIRHandle handle = (CPhidgetIRHandle)get_ph_handle(self);
  int data_length = RARRAY_LEN(data);
  int *int_data = (int *)malloc(data_length * sizeof(int));
  int i;

  for(i=0; i<data_length; i++) {
    int_data[i] = NUM2INT(rb_ary_entry(data, i));
  }

  ph_raise(CPhidgetIR_TransmitRaw(handle, int_data, data_length, FIX2INT(carrier_freq), FIX2INT(duty_cycle), FIX2INT(gap)));

  free(int_data);
  return Qnil;
}

VALUE ph_ir_get_raw_data(VALUE self, VALUE length) {
  CPhidgetIRHandle handle = (CPhidgetIRHandle)get_ph_handle(self);
  int data_length = FIX2INT(length);
  int *raw_data = (int *)malloc(data_length * sizeof(int));
  VALUE rb_data;
  int i;

  ph_raise(CPhidgetIR_getRawData(handle, raw_data, &data_length));

  rb_data = rb_ary_new();
  for(i=0; i<data_length; i++) {
    rb_ary_push(rb_data, INT2NUM(raw_data[i]));
  }
  free(raw_data);
  return Qnil;
}

VALUE ph_ir_get_last_code(VALUE self) {
  ph_raise(EPHIDGET_NOTIMPLEMENTED);
  return Qnil;
}

VALUE ph_ir_get_last_learned_code(VALUE self) {
  ph_raise(EPHIDGET_NOTIMPLEMENTED);
  return Qnil;
}


#ifdef PH_CALLBACK
VALUE ph_ir_set_on_code_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetIR_set_OnCode_Handler((CPhidgetIRHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetIR_set_OnCode_Handler((CPhidgetIRHandle)ph->handle, ph_ir_on_code, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_ir_set_on_learn_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetIR_set_OnLearn_Handler((CPhidgetIRHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetIR_set_OnLearn_Handler((CPhidgetIRHandle)ph->handle, ph_ir_on_learn, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_ir_set_on_raw_data_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_3;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetIR_set_OnRawData_Handler((CPhidgetIRHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetIR_set_OnRawData_Handler((CPhidgetIRHandle)ph->handle, ph_ir_on_raw_data, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_ir_on_code(CPhidgetIRHandle phid, void *userPtr, unsigned char *data, int dataLength, int bitCount, int repeat) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_ir_on_learn(CPhidgetIRHandle phid, void *userPtr, unsigned char *data, int dataLength, CPhidgetIR_CodeInfoHandle codeInfo) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_ir_on_raw_data(CPhidgetIRHandle phid, void *userPtr, int *data, int dataLength) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

