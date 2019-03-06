
#include "phidgets.h"

#define IR_CODE_CALLBACK      0
#define IR_LEARN_CALLBACK     1
#define IR_RAW_DATA_CALLBACK  2



VALUE ph_ir_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetIR_create((PhidgetIRHandle *)(&(ph->handle))));
  return self;
}


VALUE ph_ir_transmit(VALUE self, VALUE code, VALUE code_info) {
  PhidgetIRHandle handle = (PhidgetIRHandle)get_ph_handle(self);
  PhidgetIR_CodeInfo info;
  int i;

  if(! RB_TYPE_P(code, T_STRING)) ph_raise(EPHIDGET_INVALIDARG);
  if(! RB_TYPE_P(code_info, T_HASH)) ph_raise(EPHIDGET_INVALIDARG);

  info.bitCount = NUM2UINT(rb_hash_aref(code_info, rb_str_new2("bitCount")));
  info.encoding = NUM2INT(rb_hash_aref(code_info, rb_str_new2("encoding")));
  info.length = NUM2INT(rb_hash_aref(code_info, rb_str_new2("length")));
  info.gap = NUM2UINT(rb_hash_aref(code_info, rb_str_new2("gap")));
  info.trail = NUM2UINT(rb_hash_aref(code_info, rb_str_new2("trail")));
  for(i=0; i<2; i++) { info.header[i] = NUM2UINT(rb_ary_entry(rb_hash_aref(code_info, rb_str_new2("header")), i)); }
  for(i=0; i<2; i++) { info.one[i] = NUM2UINT(rb_ary_entry(rb_hash_aref(code_info, rb_str_new2("one")), i)); }
  for(i=0; i<2; i++) { info.zero[i] = NUM2UINT(rb_ary_entry(rb_hash_aref(code_info, rb_str_new2("zero")), i)); }
  for(i=0; i<26; i++) { info.repeat[i] = NUM2UINT(rb_ary_entry(rb_hash_aref(code_info, rb_str_new2("repeat")), i)); }
  info.minRepeat = NUM2UINT(rb_hash_aref(code_info, rb_str_new2("minRepeat")));
  info.dutyCycle = NUM2DBL(rb_hash_aref(code_info, rb_str_new2("dutyCycle")));
  info.carrierFrequency = NUM2UINT(rb_hash_aref(code_info, rb_str_new2("carrierFrequency")));
  for(i=0; i<33; i++) { info.toggleMask[i] = NUM2CHR(rb_ary_entry(rb_hash_aref(code_info, rb_str_new2("toggleMask")), i)); }

  ph_raise(PhidgetIR_transmit(handle, StringValuePtr(code), &info));
  return Qnil;
}


VALUE ph_ir_transmit_repeat(VALUE self) {
  ph_raise(PhidgetIR_transmitRepeat((PhidgetIRHandle)get_ph_handle(self)));
  return Qnil;
}


VALUE ph_ir_transmit_raw(VALUE self, VALUE data, VALUE carrier_freq, VALUE duty_cycle, VALUE gap) {
  PhidgetIRHandle handle = (PhidgetIRHandle)get_ph_handle(self);
  size_t data_length = RARRAY_LEN(data);
  uint32_t raw_data[200];
  size_t i;

  for(i=0; i<data_length; i++) { raw_data[i] = NUM2UINT(rb_ary_entry(data, i)); }
  ph_raise(PhidgetIR_transmitRaw(handle, raw_data, data_length, NUM2UINT(carrier_freq), NUM2DBL(duty_cycle), NUM2UINT(gap)));
  return Qnil;
}


VALUE ph_ir_get_last_code(VALUE self) {
  PhidgetIRHandle handle = (PhidgetIRHandle)get_ph_handle(self);
  char code[IR_MAX_CODE_STR_LENGTH];
  uint32_t bitCount;
  VALUE rb_code_data = rb_hash_new();

  ph_raise(PhidgetIR_getLastCode(handle, code, IR_MAX_CODE_STR_LENGTH, &bitCount));
  rb_hash_aset(rb_code_data, rb_str_new2("code"), rb_str_new2(code));
  rb_hash_aset(rb_code_data, rb_str_new2("bitCount"), UINT2NUM(bitCount));
  return rb_code_data;
}


VALUE ph_ir_get_last_learned_code(VALUE self) {
  PhidgetIRHandle handle = (PhidgetIRHandle)get_ph_handle(self);
  char code[IR_MAX_CODE_STR_LENGTH];
  PhidgetIR_CodeInfo info;
  VALUE rb_code_data = rb_hash_new();
  VALUE rb_code_info = rb_hash_new();
  VALUE rb_info_header = rb_ary_new();
  VALUE rb_info_one = rb_ary_new();
  VALUE rb_info_zero = rb_ary_new();
  VALUE rb_info_repeat = rb_ary_new();
  VALUE rb_info_toggle_mask = rb_ary_new();
  int i;

  ph_raise(PhidgetIR_getLastLearnedCode(handle, code, IR_MAX_CODE_STR_LENGTH, &info));

  rb_hash_aset(rb_code_info, rb_str_new2("bitCount"), UINT2NUM(info.bitCount));
  rb_hash_aset(rb_code_info, rb_str_new2("encoding"), INT2NUM(info.encoding));
  rb_hash_aset(rb_code_info, rb_str_new2("length"), INT2NUM(info.length));
  rb_hash_aset(rb_code_info, rb_str_new2("gap"), UINT2NUM(info.gap));
  rb_hash_aset(rb_code_info, rb_str_new2("trail"), UINT2NUM(info.trail));
  for(i=0; i<2; i++) { rb_ary_push(rb_info_header, UINT2NUM(info.header[i])); }
  rb_hash_aset(rb_code_info, rb_str_new2("header"), rb_info_header);
  for(i=0; i<2; i++) { rb_ary_push(rb_info_one, UINT2NUM(info.one[i])); }
  rb_hash_aset(rb_code_info, rb_str_new2("one"), rb_info_one);
  for(i=0; i<2; i++) { rb_ary_push(rb_info_zero, UINT2NUM(info.zero[i])); }
  rb_hash_aset(rb_code_info, rb_str_new2("zero"), rb_info_zero);
  for(i=0; i<26; i++) { rb_ary_push(rb_info_repeat, UINT2NUM(info.repeat[i])); }
  rb_hash_aset(rb_code_info, rb_str_new2("repeat"), rb_info_repeat);
  rb_hash_aset(rb_code_info, rb_str_new2("minRepeat"), UINT2NUM(info.minRepeat));
  rb_hash_aset(rb_code_info, rb_str_new2("dutyCycle"), DBL2NUM(info.dutyCycle));
  rb_hash_aset(rb_code_info, rb_str_new2("carrierFrequency"), UINT2NUM(info.carrierFrequency));
  for(i=0; i<33; i++) { rb_ary_push(rb_info_toggle_mask, INT2NUM(info.toggleMask[i])); }
  rb_hash_aset(rb_code_info, rb_str_new2("toggleMask"), rb_info_toggle_mask);

  rb_hash_aset(rb_code_data, rb_str_new2("code"), rb_str_new2(code));
  rb_hash_aset(rb_code_data, rb_str_new2("codeInfo"), rb_code_info);
  return rb_code_data;
}


void CCONV ph_ir_on_code(PhidgetIRHandle phid, void *userPtr, const char *code, uint32_t bitCount, int repeat) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = rb_str_new2(code);
  callback_data->arg2 = UINT2NUM(bitCount);
  callback_data->arg3 = INT2NUM(repeat);
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_ir_set_on_code_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[IR_CODE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetIR_setOnCodeHandler((PhidgetIRHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetIR_setOnCodeHandler((PhidgetIRHandle)ph->handle, ph_ir_on_code, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_ir_on_learn(PhidgetIRHandle phid, void *userPtr, const char *code, PhidgetIR_CodeInfo *codeInfo) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = Qnil;
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_ir_set_on_learn_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[IR_LEARN_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetIR_setOnLearnHandler((PhidgetIRHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetIR_setOnLearnHandler((PhidgetIRHandle)ph->handle, ph_ir_on_learn, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_ir_on_raw_data(PhidgetIRHandle phid, void *userPtr, const uint32_t *data, size_t dataLen) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = Qnil;
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_ir_set_on_raw_data_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[IR_RAW_DATA_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetIR_setOnRawDataHandler((PhidgetIRHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetIR_setOnRawDataHandler((PhidgetIRHandle)ph->handle, ph_ir_on_raw_data, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_ir() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_ir = rb_define_class_under(ph_module, "IR", ph_common);

  rb_define_const(ph_ir, "ENCODING_UNKNOWN", INT2NUM(IR_ENCODING_UNKNOWN));
  rb_define_const(ph_ir, "ENCODING_SPACE", INT2NUM(IR_ENCODING_SPACE));
  rb_define_const(ph_ir, "ENCODING_PULSE", INT2NUM(IR_ENCODING_PULSE));
  rb_define_const(ph_ir, "ENCODING_BIPHASE", INT2NUM(IR_ENCODING_BIPHASE));
  rb_define_const(ph_ir, "ENCODING_RC5", INT2NUM(IR_ENCODING_RC5));
  rb_define_const(ph_ir, "ENCODING_RC6", INT2NUM(IR_ENCODING_RC6));

  rb_define_const(ph_ir, "LENGTH_UNKNOWN", INT2NUM(IR_LENGTH_UNKNOWN));
  rb_define_const(ph_ir, "LENGTH_CONSTANT", INT2NUM(IR_LENGTH_CONSTANT));
  rb_define_const(ph_ir, "LENGTH_VARIABLE", INT2NUM(IR_LENGTH_VARIABLE));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget IR object.
   */
  rb_define_method(ph_ir, "initialize", ph_ir_init, 0);

  /* Document-method: transmit
   * call-seq: transmit(code, code_info)
   *
   * Transmits a code
   * code data is transmitted MSBit first.
   * MSByte is in array index 0 of code
   * LSBit is right justified, therefore, MSBit may be in bit position 0-7 (of array index 0) depending on the bit count
   */
  rb_define_method(ph_ir, "transmit", ph_ir_transmit, 2);

  /* Document-method: transmitRepeat
   * call-seq: transmitRepeat
   *
   * Transmits a repeat of the last transmited code.
   * Depending on the CodeInfo structure, this may be a retransmission of the code itself, or there may be a special repeat code.
   */
  rb_define_method(ph_ir, "transmitRepeat", ph_ir_transmit_repeat, 0);
  rb_define_alias(ph_ir, "transmit_repeat", "transmitRepeat");

  /* Document-method: transmitRaw
   * call-seq: transmitRaw(data, carrier_frequency, duty_cycle, gap)
   *
   * Transmits raw data as a series of pulses and spaces.
   * data must start and end with a pulse.
   *   Each element is a positive time in μs
   * dataLength has a maximum length of 200, however, streams should be kept must shorter than this (less than 100ms between gaps).
   *   dataLength must be an odd number
   * Leave carrierFrequency as 0 for default.
   *   carrierFrequency has a range of 10kHz - 1MHz
   * Leave dutyCycle as 0 for default
   *   dutyCycle can have a value between 0.1 and 0.5
   * Specifying a gap will guarantee a gap time (no transmitting) after data is sent.
   *   gap time is in μs
   *   gap time can be set to 0
   */
  rb_define_method(ph_ir, "transmitRaw", ph_ir_transmit_raw, 4);
  rb_define_alias(ph_ir, "transmit_raw", "transmitRaw");

  /* Document-method: getLastCode
   * call-seq: getLastCode -> code
   *
   * The last code the channel has received.
   * The code is represented by a hexadecimal string (array of bytes)
   */
  rb_define_method(ph_ir, "getLastCode", ph_ir_get_last_code, 0);
  rb_define_alias(ph_ir, "last_code", "getLastCode");

  /* Document-method: getLastLearnedCode
   * call-seq: getLastLearnedCode -> code
   *
   * The last code the channel has learned.
   * The code is represented by a hexadecimal string (array of bytes).
   * The codeInfo structure holds data that describes the learned code
   */
  rb_define_method(ph_ir, "getLastLearnedCode", ph_ir_get_last_learned_code, 0);
  rb_define_alias(ph_ir, "last_learned_code", "getLastLearnedCode");


  rb_define_private_method(ph_ir, "ext_setOnCodeHandler", ph_ir_set_on_code_handler, 1);
  rb_define_private_method(ph_ir, "ext_setOnLearnHandler", ph_ir_set_on_learn_handler, 1);
  rb_define_private_method(ph_ir, "ext_setOnRawDataHandler", ph_ir_set_on_raw_data_handler, 1);
}

