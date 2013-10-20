
#include "phidgets.h"


VALUE ph_errors[PHIDGET_ERROR_CODE_COUNT+1];

VALUE ph_get_library_version(VALUE self);
VALUE ph_enable_logging(VALUE self, VALUE level, VALUE output_file);
VALUE ph_disable_logging(VALUE self);
VALUE ph_log(VALUE self, VALUE level, VALUE msg_id, VALUE message);



void Init_phidgets() {
  VALUE ph_module = rb_define_module("Phidgets");
  VALUE ph_error;
  VALUE ph_common;

  rb_define_const(ph_module, "NOTATTACHED", INT2FIX(PHIDGET_NOTATTACHED));
  rb_define_const(ph_module, "ATTACHED", INT2FIX(PHIDGET_ATTACHED));

  rb_define_const(ph_module, "CLASS_ACCELEROMETER", INT2FIX(PHIDCLASS_ACCELEROMETER));
  rb_define_const(ph_module, "CLASS_ADVANCEDSERVO", INT2FIX(PHIDCLASS_ADVANCEDSERVO));
  rb_define_const(ph_module, "CLASS_ANALOG", INT2FIX(PHIDCLASS_ANALOG));
  rb_define_const(ph_module, "CLASS_BRIDGE", INT2FIX(PHIDCLASS_BRIDGE));
  rb_define_const(ph_module, "CLASS_ENCODER", INT2FIX(PHIDCLASS_ENCODER));
  rb_define_const(ph_module, "CLASS_FREQUENCYCOUNTER", INT2FIX(PHIDCLASS_FREQUENCYCOUNTER));
  rb_define_const(ph_module, "CLASS_GPS", INT2FIX(PHIDCLASS_GPS));
  rb_define_const(ph_module, "CLASS_INTERFACEKIT", INT2FIX(PHIDCLASS_INTERFACEKIT));
  rb_define_const(ph_module, "CLASS_IR", INT2FIX(PHIDCLASS_IR));
  rb_define_const(ph_module, "CLASS_LED", INT2FIX(PHIDCLASS_LED));
  rb_define_const(ph_module, "CLASS_MOTORCONTROL", INT2FIX(PHIDCLASS_MOTORCONTROL));
  rb_define_const(ph_module, "CLASS_PHSENSOR", INT2FIX(PHIDCLASS_PHSENSOR));
  rb_define_const(ph_module, "CLASS_RFID", INT2FIX(PHIDCLASS_RFID));
  rb_define_const(ph_module, "CLASS_SERVO", INT2FIX(PHIDCLASS_SERVO));
  rb_define_const(ph_module, "CLASS_SPATIAL", INT2FIX(PHIDCLASS_SPATIAL));
  rb_define_const(ph_module, "CLASS_STEPPER", INT2FIX(PHIDCLASS_STEPPER));
  rb_define_const(ph_module, "CLASS_TEMPERATURESENSOR", INT2FIX(PHIDCLASS_TEMPERATURESENSOR));
  rb_define_const(ph_module, "CLASS_TEXTLCD", INT2FIX(PHIDCLASS_TEXTLCD));
  rb_define_const(ph_module, "CLASS_TEXTLED", INT2FIX(PHIDCLASS_TEXTLED));
  rb_define_const(ph_module, "CLASS_WEIGHTSENSOR", INT2FIX(PHIDCLASS_WEIGHTSENSOR));

  rb_define_const(ph_module, "ID_ACCELEROMETER_3AXIS", INT2FIX(PHIDID_ACCELEROMETER_3AXIS));
  rb_define_const(ph_module, "ID_ADVANCEDSERVO_1MOTOR", INT2FIX(PHIDID_ADVANCEDSERVO_1MOTOR));
  rb_define_const(ph_module, "ID_ADVANCEDSERVO_8MOTOR", INT2FIX(PHIDID_ADVANCEDSERVO_8MOTOR));
  rb_define_const(ph_module, "ID_ANALOG_4OUTPUT", INT2FIX(PHIDID_ANALOG_4OUTPUT));
  rb_define_const(ph_module, "ID_BIPOLAR_STEPPER_1MOTOR", INT2FIX(PHIDID_BIPOLAR_STEPPER_1MOTOR));
  rb_define_const(ph_module, "ID_BRIDGE_4INPUT", INT2FIX(PHIDID_BRIDGE_4INPUT));
  rb_define_const(ph_module, "ID_ENCODER_1ENCODER_1INPUT", INT2FIX(PHIDID_ENCODER_1ENCODER_1INPUT));
  rb_define_const(ph_module, "ID_ENCODER_HS_1ENCODER", INT2FIX(PHIDID_ENCODER_HS_1ENCODER));
  rb_define_const(ph_module, "ID_ENCODER_HS_4ENCODER_4INPUT", INT2FIX(PHIDID_ENCODER_HS_4ENCODER_4INPUT));
  rb_define_const(ph_module, "ID_FREQUENCYCOUNTER_2INPUT", INT2FIX(PHIDID_FREQUENCYCOUNTER_2INPUT));
  rb_define_const(ph_module, "ID_GPS", INT2FIX(PHIDID_GPS));
  rb_define_const(ph_module, "ID_INTERFACEKIT_0_0_4", INT2FIX(PHIDID_INTERFACEKIT_0_0_4));
  rb_define_const(ph_module, "ID_INTERFACEKIT_0_0_8", INT2FIX(PHIDID_INTERFACEKIT_0_0_8));
  rb_define_const(ph_module, "ID_INTERFACEKIT_0_16_16", INT2FIX(PHIDID_INTERFACEKIT_0_16_16));
  rb_define_const(ph_module, "ID_INTERFACEKIT_2_2_2", INT2FIX(PHIDID_INTERFACEKIT_2_2_2));
  rb_define_const(ph_module, "ID_INTERFACEKIT_8_8_8", INT2FIX(PHIDID_INTERFACEKIT_8_8_8));
  rb_define_const(ph_module, "ID_INTERFACEKIT_8_8_8_w_LCD", INT2FIX(PHIDID_INTERFACEKIT_8_8_8_w_LCD));
  rb_define_const(ph_module, "ID_IR", INT2FIX(PHIDID_IR));
  rb_define_const(ph_module, "ID_LED_64_ADV", INT2FIX(PHIDID_LED_64_ADV));
  rb_define_const(ph_module, "ID_LINEAR_TOUCH", INT2FIX(PHIDID_LINEAR_TOUCH));
  rb_define_const(ph_module, "ID_MOTORCONTROL_1MOTOR", INT2FIX(PHIDID_MOTORCONTROL_1MOTOR));
  rb_define_const(ph_module, "ID_MOTORCONTROL_HC_2MOTOR", INT2FIX(PHIDID_MOTORCONTROL_HC_2MOTOR));
  rb_define_const(ph_module, "ID_RFID_2OUTPUT", INT2FIX(PHIDID_RFID_2OUTPUT));
  rb_define_const(ph_module, "ID_RFID_2OUTPUT_READ_WRITE", INT2FIX(PHIDID_RFID_2OUTPUT_READ_WRITE));
  rb_define_const(ph_module, "ID_ROTARY_TOUCH", INT2FIX(PHIDID_ROTARY_TOUCH));
  rb_define_const(ph_module, "ID_SPATIAL_ACCEL_3AXIS", INT2FIX(PHIDID_SPATIAL_ACCEL_3AXIS));
  rb_define_const(ph_module, "ID_SPATIAL_ACCEL_GYRO_COMPASS", INT2FIX(PHIDID_SPATIAL_ACCEL_GYRO_COMPASS));
  rb_define_const(ph_module, "ID_TEMPERATURESENSOR", INT2FIX(PHIDID_TEMPERATURESENSOR));
  rb_define_const(ph_module, "ID_TEMPERATURESENSOR_4", INT2FIX(PHIDID_TEMPERATURESENSOR_4));
  rb_define_const(ph_module, "ID_TEMPERATURESENSOR_IR", INT2FIX(PHIDID_TEMPERATURESENSOR_IR));
  rb_define_const(ph_module, "ID_TEXTLCD_2x20_w_8_8_8", INT2FIX(PHIDID_TEXTLCD_2x20_w_8_8_8));
  rb_define_const(ph_module, "ID_TEXTLCD_ADAPTER", INT2FIX(PHIDID_TEXTLCD_ADAPTER));
  rb_define_const(ph_module, "ID_UNIPOLAR_STEPPER_4MOTOR", INT2FIX(PHIDID_UNIPOLAR_STEPPER_4MOTOR));
  rb_define_const(ph_module, "ID_ACCELEROMETER_2AXIS", INT2FIX(PHIDID_ACCELEROMETER_2AXIS));
  rb_define_const(ph_module, "ID_INTERFACEKIT_0_8_8_w_LCD", INT2FIX(PHIDID_INTERFACEKIT_0_8_8_w_LCD));
  rb_define_const(ph_module, "ID_INTERFACEKIT_4_8_8", INT2FIX(PHIDID_INTERFACEKIT_4_8_8));
  rb_define_const(ph_module, "ID_LED_64", INT2FIX(PHIDID_LED_64));
  rb_define_const(ph_module, "ID_MOTORCONTROL_LV_2MOTOR_4INPUT", INT2FIX(PHIDID_MOTORCONTROL_LV_2MOTOR_4INPUT));
  rb_define_const(ph_module, "ID_PHSENSOR", INT2FIX(PHIDID_PHSENSOR));
  rb_define_const(ph_module, "ID_RFID", INT2FIX(PHIDID_RFID));
  rb_define_const(ph_module, "ID_SERVO_1MOTOR", INT2FIX(PHIDID_SERVO_1MOTOR));
  rb_define_const(ph_module, "ID_SERVO_1MOTOR_OLD", INT2FIX(PHIDID_SERVO_1MOTOR_OLD));
  rb_define_const(ph_module, "ID_SERVO_4MOTOR", INT2FIX(PHIDID_SERVO_4MOTOR));
  rb_define_const(ph_module, "ID_SERVO_4MOTOR_OLD", INT2FIX(PHIDID_SERVO_4MOTOR_OLD));
  rb_define_const(ph_module, "ID_TEXTLCD_2x20", INT2FIX(PHIDID_TEXTLCD_2x20));
  rb_define_const(ph_module, "ID_TEXTLCD_2x20_w_0_8_8", INT2FIX(PHIDID_TEXTLCD_2x20_w_0_8_8));
  rb_define_const(ph_module, "ID_TEXTLED_1x8", INT2FIX(PHIDID_TEXTLED_1x8));
  rb_define_const(ph_module, "ID_TEXTLED_4x8", INT2FIX(PHIDID_TEXTLED_4x8));
  rb_define_const(ph_module, "ID_WEIGHTSENSOR", INT2FIX(PHIDID_WEIGHTSENSOR));
  rb_define_const(ph_module, "ID_FIRMWARE_UPGRADE", INT2FIX(PHIDID_FIRMWARE_UPGRADE));

  rb_define_const(ph_module, "LOG_CRITICAL", INT2FIX(PHIDGET_LOG_CRITICAL));
  rb_define_const(ph_module, "LOG_ERROR", INT2FIX(PHIDGET_LOG_ERROR));
  rb_define_const(ph_module, "LOG_WARNING", INT2FIX(PHIDGET_LOG_WARNING));
  rb_define_const(ph_module, "LOG_DEBUG", INT2FIX(PHIDGET_LOG_DEBUG));
  rb_define_const(ph_module, "LOG_INFO", INT2FIX(PHIDGET_LOG_INFO));
  rb_define_const(ph_module, "LOG_VERBOSE", INT2FIX(PHIDGET_LOG_VERBOSE));

  ph_error = rb_define_class_under(ph_module, "Error", rb_eStandardError);
  ph_errors[EPHIDGET_NOTFOUND] = rb_define_class_under(ph_error, "NotFound", ph_error);
  ph_errors[EPHIDGET_NOMEMORY] = rb_define_class_under(ph_error, "NoMemory", ph_error);
  ph_errors[EPHIDGET_UNEXPECTED] = rb_define_class_under(ph_error, "Unexpected", ph_error);
  ph_errors[EPHIDGET_INVALIDARG] = rb_define_class_under(ph_error, "InvalidArg", ph_error);
  ph_errors[EPHIDGET_NOTATTACHED] = rb_define_class_under(ph_error, "NotAttached", ph_error);
  ph_errors[EPHIDGET_INTERRUPTED] = rb_define_class_under(ph_error, "Interrupted", ph_error);
  ph_errors[EPHIDGET_INVALID] = rb_define_class_under(ph_error, "Invalid", ph_error);
  ph_errors[EPHIDGET_NETWORK] = rb_define_class_under(ph_error, "Network", ph_error);
  ph_errors[EPHIDGET_UNKNOWNVAL] = rb_define_class_under(ph_error, "UnknownVal", ph_error);
  ph_errors[EPHIDGET_BADPASSWORD] = rb_define_class_under(ph_error, "BadPassword", ph_error);
  ph_errors[EPHIDGET_UNSUPPORTED] = rb_define_class_under(ph_error, "Unsupported", ph_error);
  ph_errors[EPHIDGET_DUPLICATE] = rb_define_class_under(ph_error, "Duplicate", ph_error);
  ph_errors[EPHIDGET_TIMEOUT] = rb_define_class_under(ph_error, "Timeout", ph_error);
  ph_errors[EPHIDGET_OUTOFBOUNDS] = rb_define_class_under(ph_error, "OutOfBounds", ph_error);
  ph_errors[EPHIDGET_EVENT] = rb_define_class_under(ph_error, "Event", ph_error);
  ph_errors[EPHIDGET_NETWORK_NOTCONNECTED] = rb_define_class_under(ph_error, "NetworkNotConnected", ph_error);
  ph_errors[EPHIDGET_WRONGDEVICE] = rb_define_class_under(ph_error, "WrongDevice", ph_error);
  ph_errors[EPHIDGET_CLOSED] = rb_define_class_under(ph_error, "Closed", ph_error);
  ph_errors[EPHIDGET_BADVERSION] = rb_define_class_under(ph_error, "BadVersion", ph_error);
  ph_errors[EPHIDGET_NOTIMPLEMENTED] = rb_define_class_under(ph_error, "NotImplemented", ph_error);

  /*
   * Document-method: getLibraryVersion
   * call-seq: getLibraryVersion -> version
   *
   * Gets the library version. This contains a version number and a build date.
   */
  rb_define_singleton_method(ph_module, "getLibraryVersion", ph_get_library_version, 0);

  /*
   * Document-method: library_version
   * call-seq: library_version -> version
   *
   * Gets the library version. This contains a version number and a build date.
   */
  rb_define_singleton_method(ph_module, "library_version", ph_get_library_version, 0);

  /*
   * Document-method: enableLogging
   * call-seq: enableLogging(log_level, output_file)
   *
   * Enables logging.
   */
  rb_define_singleton_method(ph_module, "enableLogging", ph_enable_logging, 2);

  /*
   * Document-method: enable_logging
   * call-seq: enable_logging(log_level, output_file)
   *
   * Enables logging.
   */
  rb_define_singleton_method(ph_module, "enable_logging", ph_enable_logging, 2);

  /*
   * Document-method: disableLogging
   * call-seq: disableLogging
   *
   * Disables logging.
   */
  rb_define_singleton_method(ph_module, "disableLogging", ph_disable_logging, 0);

  /*
   * Document-method: disable_logging
   * call-seq: disable_logging
   *
   * Disables logging.
   */
  rb_define_singleton_method(ph_module, "disable_logging", ph_disable_logging, 0);

  /*
   * Document-method: log
   * call-seq: log(log_level, msg_id, msg)
   *
   * Appends a message to the log.
   */
  rb_define_singleton_method(ph_module, "log", ph_log, 3);

  Init_phidgets_dictionary(ph_module);
  Init_phidgets_manager(ph_module);
  ph_common = Init_phidgets_common(ph_module);
  Init_phidgets_accel(ph_module, ph_common);
  Init_phidgets_advservo(ph_module, ph_common);
  Init_phidgets_analog(ph_module, ph_common);
  Init_phidgets_bridge(ph_module, ph_common);
  Init_phidgets_encoder(ph_module, ph_common);
  Init_phidgets_freq(ph_module, ph_common);
  Init_phidgets_gps(ph_module, ph_common);
  Init_phidgets_ifkit(ph_module, ph_common);
  Init_phidgets_ir(ph_module, ph_common);
  Init_phidgets_led(ph_module, ph_common);
  Init_phidgets_motor_control(ph_module, ph_common);
  Init_phidgets_phsensor(ph_module, ph_common);
  Init_phidgets_rfid(ph_module, ph_common);
  Init_phidgets_servo(ph_module, ph_common);
  Init_phidgets_spatial(ph_module, ph_common);
  Init_phidgets_stepper(ph_module, ph_common);
  Init_phidgets_temp(ph_module, ph_common);
  Init_phidgets_textlcd(ph_module, ph_common);
  Init_phidgets_textled(ph_module, ph_common);
  Init_phidgets_weight(ph_module, ph_common);
}


ph_data_t *get_ph_data(VALUE self) {
  ph_data_t *ph;
  Data_Get_Struct(self, ph_data_t, ph);
  return ph;
}

CPhidgetHandle get_ph_handle(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  return ph->handle;
}

void ph_raise(int err_code) {
  if(err_code > EPHIDGET_OK && err_code < PHIDGET_ERROR_CODE_COUNT) {
    const char *err_description;
    CPhidget_getErrorDescription(err_code, &err_description);
    rb_raise(ph_errors[err_code], err_description);
  }
  if(err_code == EPHIDGET_NOTIMPLEMENTED) {
    rb_raise(ph_errors[EPHIDGET_NOTIMPLEMENTED], "This functionality has not been implemented yet");
  }
}

VALUE ph_get_library_version(VALUE self) {
  const char *lib_version;
  ph_raise(CPhidget_getLibraryVersion(&lib_version));
  return rb_str_new2(lib_version);
}

VALUE ph_enable_logging(VALUE self, VALUE level, VALUE output_file) {
  ph_raise(CPhidget_enableLogging(FIX2INT(level), StringValueCStr(output_file)));
  return Qnil;
}

VALUE ph_disable_logging(VALUE self) {
  ph_raise(CPhidget_disableLogging());
  return Qnil;
}

VALUE ph_log(VALUE self, VALUE level, VALUE msg_id, VALUE message) {
  ph_raise(CPhidget_log(FIX2INT(level), StringValueCStr(msg_id), StringValueCStr(message)));
  return Qnil;
}


#ifdef PH_CALLBACK
void ph_callback_thread(ph_callback_data_t *callback_data) {
  while(! callback_data->exit) {
    rb_thread_blocking_region(wait_for_callback, (void *)callback_data, cancel_wait_for_callback, (void *)callback_data);
    if(TYPE(callback_data->callback) != T_NIL) rb_funcall(callback_data->callback, rb_intern("call"), 1, callback_data->phidget);
    callback_data->called = false;
  };
}

VALUE wait_for_callback(void *arg) {
  ph_callback_data_t *callback_data = (ph_callback_data_t *)arg;
  while(! callback_data->exit) {
    usleep(PH_CALLBACK_POLLING_INTERVAL);
    if(callback_data->called) return Qnil;
  };
  return Qnil;
}

void cancel_wait_for_callback(void *arg) {
  ph_callback_data_t *callback_data = (ph_callback_data_t *)arg;
  callback_data->exit = true;
}
#endif

