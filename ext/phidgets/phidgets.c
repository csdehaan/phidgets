
#include "phidgets.h"

#if defined(HAVE_RUBY_THREAD_H)
#include <ruby/thread.h>
#endif



VALUE ph_get_library_version(VALUE self) {
  const char *lib_version;
  ph_raise(Phidget_getLibraryVersion(&lib_version));
  return rb_str_new2(lib_version);
}

VALUE ph_add_server(VALUE self, VALUE name, VALUE address, VALUE port, VALUE password, VALUE flags) {
  ph_raise(PhidgetNet_addServer(StringValueCStr(name), StringValueCStr(address), NUM2INT(port), StringValueCStr(password), NUM2INT(flags)));
  return Qnil;
}

VALUE ph_remove_server(VALUE self, VALUE name) {
  ph_raise(PhidgetNet_removeServer(StringValueCStr(name)));
  return Qnil;
}

VALUE ph_enable_server(VALUE self, VALUE name) {
  ph_raise(PhidgetNet_enableServer(StringValueCStr(name)));
  return Qnil;
}

VALUE ph_disable_server(VALUE self, VALUE name, VALUE flags) {
  ph_raise(PhidgetNet_disableServer(StringValueCStr(name), NUM2INT(flags)));
  return Qnil;
}

VALUE ph_enable_server_discovery(VALUE self, VALUE server_type) {
  ph_raise(PhidgetNet_enableServerDiscovery(NUM2INT(server_type)));
  return Qnil;
}

VALUE ph_disable_server_discovery(VALUE self, VALUE server_type) {
  ph_raise(PhidgetNet_disableServerDiscovery(NUM2INT(server_type)));
  return Qnil;
}

VALUE ph_set_server_password(VALUE self, VALUE name, VALUE password) {
  ph_raise(PhidgetNet_setServerPassword(StringValueCStr(name), StringValueCStr(password)));
  return Qnil;
}


void Init_phidgets() {
  VALUE ph_module = rb_define_module("Phidgets");
  VALUE ph_error;

  rb_define_const(ph_module, "SERVER_DEVICEREMOTE", INT2NUM(PHIDGETSERVER_DEVICEREMOTE));
  rb_define_const(ph_module, "SERVER_WWWREMOTE", INT2NUM(PHIDGETSERVER_WWWREMOTE));
  rb_define_const(ph_module, "SERVER_SBC", INT2NUM(PHIDGETSERVER_SBC));

  rb_define_const(ph_module, "SERIALNUMBER_ANY", INT2NUM(PHIDGET_SERIALNUMBER_ANY));
  rb_define_const(ph_module, "HUBPORT_ANY", INT2NUM(PHIDGET_HUBPORT_ANY));
  rb_define_const(ph_module, "CHANNEL_ANY", INT2NUM(PHIDGET_CHANNEL_ANY));
  rb_define_const(ph_module, "LABEL_ANY", Qnil);
  rb_define_const(ph_module, "TIMEOUT_INFINITE", INT2NUM(PHIDGET_TIMEOUT_INFINITE));
  rb_define_const(ph_module, "TIMEOUT_DEFAULT", INT2NUM(PHIDGET_TIMEOUT_DEFAULT));
  rb_define_const(ph_module, "SERVER_AUTHREQUIRED", INT2NUM(PHIDGETSERVER_AUTHREQUIRED));

  rb_define_const(ph_module, "CLASS_NOTHING", INT2NUM(PHIDCLASS_NOTHING));
  rb_define_const(ph_module, "CLASS_ACCELEROMETER", INT2NUM(PHIDCLASS_ACCELEROMETER));
  rb_define_const(ph_module, "CLASS_ADVANCEDSERVO", INT2NUM(PHIDCLASS_ADVANCEDSERVO));
  rb_define_const(ph_module, "CLASS_ANALOG", INT2NUM(PHIDCLASS_ANALOG));
  rb_define_const(ph_module, "CLASS_BRIDGE", INT2NUM(PHIDCLASS_BRIDGE));
  rb_define_const(ph_module, "CLASS_ENCODER", INT2NUM(PHIDCLASS_ENCODER));
  rb_define_const(ph_module, "CLASS_FREQUENCYCOUNTER", INT2NUM(PHIDCLASS_FREQUENCYCOUNTER));
  rb_define_const(ph_module, "CLASS_GPS", INT2NUM(PHIDCLASS_GPS));
  rb_define_const(ph_module, "CLASS_INTERFACEKIT", INT2NUM(PHIDCLASS_INTERFACEKIT));
  rb_define_const(ph_module, "CLASS_IR", INT2NUM(PHIDCLASS_IR));
  rb_define_const(ph_module, "CLASS_LED", INT2NUM(PHIDCLASS_LED));
  rb_define_const(ph_module, "CLASS_MOTORCONTROL", INT2NUM(PHIDCLASS_MOTORCONTROL));
  rb_define_const(ph_module, "CLASS_PHSENSOR", INT2NUM(PHIDCLASS_PHSENSOR));
  rb_define_const(ph_module, "CLASS_RFID", INT2NUM(PHIDCLASS_RFID));
  rb_define_const(ph_module, "CLASS_SERVO", INT2NUM(PHIDCLASS_SERVO));
  rb_define_const(ph_module, "CLASS_SPATIAL", INT2NUM(PHIDCLASS_SPATIAL));
  rb_define_const(ph_module, "CLASS_STEPPER", INT2NUM(PHIDCLASS_STEPPER));
  rb_define_const(ph_module, "CLASS_TEMPERATURESENSOR", INT2NUM(PHIDCLASS_TEMPERATURESENSOR));
  rb_define_const(ph_module, "CLASS_TEXTLCD", INT2NUM(PHIDCLASS_TEXTLCD));
  rb_define_const(ph_module, "CLASS_HUB", INT2NUM(PHIDCLASS_HUB));
  rb_define_const(ph_module, "CLASS_MESHDONGLE", INT2NUM(PHIDCLASS_MESHDONGLE));
  rb_define_const(ph_module, "CLASS_VINT", INT2NUM(PHIDCLASS_VINT));
  rb_define_const(ph_module, "CLASS_GENERIC", INT2NUM(PHIDCLASS_GENERIC));
  rb_define_const(ph_module, "CLASS_FIRMWAREUPGRADE", INT2NUM(PHIDCLASS_FIRMWAREUPGRADE));
  rb_define_const(ph_module, "CLASS_DICTIONARY", INT2NUM(PHIDCLASS_DICTIONARY));

  rb_define_const(ph_module, "CHCLASS_NOTHING", INT2NUM(PHIDCHCLASS_NOTHING));
  rb_define_const(ph_module, "CHCLASS_ACCELEROMETER", INT2NUM(PHIDCHCLASS_ACCELEROMETER));
  rb_define_const(ph_module, "CHCLASS_CURRENTINPUT", INT2NUM(PHIDCHCLASS_CURRENTINPUT));
  rb_define_const(ph_module, "CHCLASS_DATAADAPTER", INT2NUM(PHIDCHCLASS_DATAADAPTER));
  rb_define_const(ph_module, "CHCLASS_DCMOTOR", INT2NUM(PHIDCHCLASS_DCMOTOR));
  rb_define_const(ph_module, "CHCLASS_DIGITALINPUT", INT2NUM(PHIDCHCLASS_DIGITALINPUT));
  rb_define_const(ph_module, "CHCLASS_DIGITALOUTPUT", INT2NUM(PHIDCHCLASS_DIGITALOUTPUT));
  rb_define_const(ph_module, "CHCLASS_DISTANCESENSOR", INT2NUM(PHIDCHCLASS_DISTANCESENSOR));
  rb_define_const(ph_module, "CHCLASS_ENCODER", INT2NUM(PHIDCHCLASS_ENCODER));
  rb_define_const(ph_module, "CHCLASS_FREQUENCYCOUNTER", INT2NUM(PHIDCHCLASS_FREQUENCYCOUNTER));
  rb_define_const(ph_module, "CHCLASS_GPS", INT2NUM(PHIDCHCLASS_GPS));
  rb_define_const(ph_module, "CHCLASS_LCD", INT2NUM(PHIDCHCLASS_LCD));
  rb_define_const(ph_module, "CHCLASS_GYROSCOPE", INT2NUM(PHIDCHCLASS_GYROSCOPE));
  rb_define_const(ph_module, "CHCLASS_HUB", INT2NUM(PHIDCHCLASS_HUB));
  rb_define_const(ph_module, "CHCLASS_CAPACITIVETOUCH", INT2NUM(PHIDCHCLASS_CAPACITIVETOUCH));
  rb_define_const(ph_module, "CHCLASS_HUMIDITYSENSOR", INT2NUM(PHIDCHCLASS_HUMIDITYSENSOR));
  rb_define_const(ph_module, "CHCLASS_IR", INT2NUM(PHIDCHCLASS_IR));
  rb_define_const(ph_module, "CHCLASS_LIGHTSENSOR", INT2NUM(PHIDCHCLASS_LIGHTSENSOR));
  rb_define_const(ph_module, "CHCLASS_MAGNETOMETER", INT2NUM(PHIDCHCLASS_MAGNETOMETER));
  rb_define_const(ph_module, "CHCLASS_MESHDONGLE", INT2NUM(PHIDCHCLASS_MESHDONGLE));
  rb_define_const(ph_module, "CHCLASS_PHSENSOR", INT2NUM(PHIDCHCLASS_PHSENSOR));
  rb_define_const(ph_module, "CHCLASS_POWERGUARD", INT2NUM(PHIDCHCLASS_POWERGUARD));
  rb_define_const(ph_module, "CHCLASS_PRESSURESENSOR", INT2NUM(PHIDCHCLASS_PRESSURESENSOR));
  rb_define_const(ph_module, "CHCLASS_RCSERVO", INT2NUM(PHIDCHCLASS_RCSERVO));
  rb_define_const(ph_module, "CHCLASS_RESISTANCEINPUT", INT2NUM(PHIDCHCLASS_RESISTANCEINPUT));
  rb_define_const(ph_module, "CHCLASS_RFID", INT2NUM(PHIDCHCLASS_RFID));
  rb_define_const(ph_module, "CHCLASS_SOUNDSENSOR", INT2NUM(PHIDCHCLASS_SOUNDSENSOR));
  rb_define_const(ph_module, "CHCLASS_SPATIAL", INT2NUM(PHIDCHCLASS_SPATIAL));
  rb_define_const(ph_module, "CHCLASS_STEPPER", INT2NUM(PHIDCHCLASS_STEPPER));
  rb_define_const(ph_module, "CHCLASS_TEMPERATURESENSOR", INT2NUM(PHIDCHCLASS_TEMPERATURESENSOR));
  rb_define_const(ph_module, "CHCLASS_VOLTAGEINPUT", INT2NUM(PHIDCHCLASS_VOLTAGEINPUT));
  rb_define_const(ph_module, "CHCLASS_VOLTAGEOUTPUT", INT2NUM(PHIDCHCLASS_VOLTAGEOUTPUT));
  rb_define_const(ph_module, "CHCLASS_VOLTAGERATIOINPUT", INT2NUM(PHIDCHCLASS_VOLTAGERATIOINPUT));
  rb_define_const(ph_module, "CHCLASS_FIRMWAREUPGRADE", INT2NUM(PHIDCHCLASS_FIRMWAREUPGRADE));
  rb_define_const(ph_module, "CHCLASS_GENERIC", INT2NUM(PHIDCHCLASS_GENERIC));
  rb_define_const(ph_module, "CHCLASS_MOTORPOSITIONCONTROLLER", INT2NUM(PHIDCHCLASS_MOTORPOSITIONCONTROLLER));
  rb_define_const(ph_module, "CHCLASS_BLDCMOTOR", INT2NUM(PHIDCHCLASS_BLDCMOTOR));
  rb_define_const(ph_module, "CHCLASS_DICTIONARY", INT2NUM(PHIDCHCLASS_DICTIONARY));
  rb_define_const(ph_module, "CHCLASS_CURRENTOUTPUT", INT2NUM(PHIDCHCLASS_CURRENTOUTPUT));

  rb_define_const(ph_module, "CHSUBCLASS_NONE", INT2NUM(PHIDCHSUBCLASS_NONE));
  rb_define_const(ph_module, "CHSUBCLASS_DIGITALOUTPUT_DUTY_CYCLE", INT2NUM(PHIDCHSUBCLASS_DIGITALOUTPUT_DUTY_CYCLE));
  rb_define_const(ph_module, "CHSUBCLASS_DIGITALOUTPUT_LED_DRIVER", INT2NUM(PHIDCHSUBCLASS_DIGITALOUTPUT_LED_DRIVER));
  rb_define_const(ph_module, "CHSUBCLASS_TEMPERATURESENSOR_RTD", INT2NUM(PHIDCHSUBCLASS_TEMPERATURESENSOR_RTD));
  rb_define_const(ph_module, "CHSUBCLASS_TEMPERATURESENSOR_THERMOCOUPLE", INT2NUM(PHIDCHSUBCLASS_TEMPERATURESENSOR_THERMOCOUPLE));
  rb_define_const(ph_module, "CHSUBCLASS_VOLTAGEINPUT_SENSOR_PORT", INT2NUM(PHIDCHSUBCLASS_VOLTAGEINPUT_SENSOR_PORT));
  rb_define_const(ph_module, "CHSUBCLASS_VOLTAGERATIOINPUT_SENSOR_PORT", INT2NUM(PHIDCHSUBCLASS_VOLTAGERATIOINPUT_SENSOR_PORT));
  rb_define_const(ph_module, "CHSUBCLASS_VOLTAGERATIOINPUT_BRIDGE", INT2NUM(PHIDCHSUBCLASS_VOLTAGERATIOINPUT_BRIDGE));
  rb_define_const(ph_module, "CHSUBCLASS_LCD_GRAPHIC", INT2NUM(PHIDCHSUBCLASS_LCD_GRAPHIC));
  rb_define_const(ph_module, "CHSUBCLASS_LCD_TEXT", INT2NUM(PHIDCHSUBCLASS_LCD_TEXT));
  rb_define_const(ph_module, "CHSUBCLASS_ENCODER_MODE_SETTABLE", INT2NUM(PHIDCHSUBCLASS_ENCODER_MODE_SETTABLE));

  rb_define_const(ph_module, "ID_NOTHING", INT2NUM(PHIDID_NOTHING));
  rb_define_const(ph_module, "ID_UNKNOWN", INT2NUM(PHIDID_UNKNOWN));
  rb_define_const(ph_module, "ID_INTERFACEKIT_4_8_8", INT2NUM(PHIDID_INTERFACEKIT_4_8_8));
  rb_define_const(ph_module, "ID_1000", INT2NUM(PHIDID_1000));
  rb_define_const(ph_module, "ID_1001", INT2NUM(PHIDID_1001));
  rb_define_const(ph_module, "ID_1002", INT2NUM(PHIDID_1002));
  rb_define_const(ph_module, "ID_1008", INT2NUM(PHIDID_1008));
  rb_define_const(ph_module, "ID_1010_1013_1018_1019", INT2NUM(PHIDID_1010_1013_1018_1019));
  rb_define_const(ph_module, "ID_1011", INT2NUM(PHIDID_1011));
  rb_define_const(ph_module, "ID_1012", INT2NUM(PHIDID_1012));
  rb_define_const(ph_module, "ID_1014", INT2NUM(PHIDID_1014));
  rb_define_const(ph_module, "ID_1015", INT2NUM(PHIDID_1015));
  rb_define_const(ph_module, "ID_1016", INT2NUM(PHIDID_1016));
  rb_define_const(ph_module, "ID_1017", INT2NUM(PHIDID_1017));
  rb_define_const(ph_module, "ID_1023", INT2NUM(PHIDID_1023));
  rb_define_const(ph_module, "ID_1024", INT2NUM(PHIDID_1024));
  rb_define_const(ph_module, "ID_1030", INT2NUM(PHIDID_1030));
  rb_define_const(ph_module, "ID_1031", INT2NUM(PHIDID_1031));
  rb_define_const(ph_module, "ID_1032", INT2NUM(PHIDID_1032));
  rb_define_const(ph_module, "ID_1040", INT2NUM(PHIDID_1040));
  rb_define_const(ph_module, "ID_1041", INT2NUM(PHIDID_1041));
  rb_define_const(ph_module, "ID_1042", INT2NUM(PHIDID_1042));
  rb_define_const(ph_module, "ID_1043", INT2NUM(PHIDID_1043));
  rb_define_const(ph_module, "ID_1044", INT2NUM(PHIDID_1044));
  rb_define_const(ph_module, "ID_1045", INT2NUM(PHIDID_1045));
  rb_define_const(ph_module, "ID_1046", INT2NUM(PHIDID_1046));
  rb_define_const(ph_module, "ID_1047", INT2NUM(PHIDID_1047));
  rb_define_const(ph_module, "ID_1048", INT2NUM(PHIDID_1048));
  rb_define_const(ph_module, "ID_1049", INT2NUM(PHIDID_1049));
  rb_define_const(ph_module, "ID_1051", INT2NUM(PHIDID_1051));
  rb_define_const(ph_module, "ID_1052", INT2NUM(PHIDID_1052));
  rb_define_const(ph_module, "ID_1053", INT2NUM(PHIDID_1053));
  rb_define_const(ph_module, "ID_1054", INT2NUM(PHIDID_1054));
  rb_define_const(ph_module, "ID_1055", INT2NUM(PHIDID_1055));
  rb_define_const(ph_module, "ID_1056", INT2NUM(PHIDID_1056));
  rb_define_const(ph_module, "ID_1057", INT2NUM(PHIDID_1057));
  rb_define_const(ph_module, "ID_1058", INT2NUM(PHIDID_1058));
  rb_define_const(ph_module, "ID_1059", INT2NUM(PHIDID_1059));
  rb_define_const(ph_module, "ID_1060", INT2NUM(PHIDID_1060));
  rb_define_const(ph_module, "ID_1061", INT2NUM(PHIDID_1061));
  rb_define_const(ph_module, "ID_1062", INT2NUM(PHIDID_1062));
  rb_define_const(ph_module, "ID_1063", INT2NUM(PHIDID_1063));
  rb_define_const(ph_module, "ID_1064", INT2NUM(PHIDID_1064));
  rb_define_const(ph_module, "ID_1065", INT2NUM(PHIDID_1065));
  rb_define_const(ph_module, "ID_1066", INT2NUM(PHIDID_1066));
  rb_define_const(ph_module, "ID_1067", INT2NUM(PHIDID_1067));
  rb_define_const(ph_module, "ID_1202_1203", INT2NUM(PHIDID_1202_1203));
  rb_define_const(ph_module, "ID_1204", INT2NUM(PHIDID_1204));
  rb_define_const(ph_module, "ID_1215__1218", INT2NUM(PHIDID_1215__1218));
  rb_define_const(ph_module, "ID_1219__1222", INT2NUM(PHIDID_1219__1222));
  rb_define_const(ph_module, "ID_ADP1000", INT2NUM(PHIDID_ADP1000));
  rb_define_const(ph_module, "ID_DAQ1000", INT2NUM(PHIDID_DAQ1000));
  rb_define_const(ph_module, "ID_DAQ1200", INT2NUM(PHIDID_DAQ1200));
  rb_define_const(ph_module, "ID_DAQ1300", INT2NUM(PHIDID_DAQ1300));
  rb_define_const(ph_module, "ID_DAQ1301", INT2NUM(PHIDID_DAQ1301));
  rb_define_const(ph_module, "ID_DAQ1400", INT2NUM(PHIDID_DAQ1400));
  rb_define_const(ph_module, "ID_DAQ1500", INT2NUM(PHIDID_DAQ1500));
  rb_define_const(ph_module, "ID_DCC1000", INT2NUM(PHIDID_DCC1000));
  rb_define_const(ph_module, "ID_DST1000", INT2NUM(PHIDID_DST1000));
  rb_define_const(ph_module, "ID_DST1200", INT2NUM(PHIDID_DST1200));
  rb_define_const(ph_module, "ID_ENC1000", INT2NUM(PHIDID_ENC1000));
  rb_define_const(ph_module, "ID_HIN1000", INT2NUM(PHIDID_HIN1000));
  rb_define_const(ph_module, "ID_HIN1001", INT2NUM(PHIDID_HIN1001));
  rb_define_const(ph_module, "ID_HIN1100", INT2NUM(PHIDID_HIN1100));
  rb_define_const(ph_module, "ID_HUB0000", INT2NUM(PHIDID_HUB0000));
  rb_define_const(ph_module, "ID_HUB0001", INT2NUM(PHIDID_HUB0001));
  rb_define_const(ph_module, "ID_HUB0004", INT2NUM(PHIDID_HUB0004));
  rb_define_const(ph_module, "ID_HUM1000", INT2NUM(PHIDID_HUM1000));
  rb_define_const(ph_module, "ID_LCD1100", INT2NUM(PHIDID_LCD1100));
  rb_define_const(ph_module, "ID_LED1000", INT2NUM(PHIDID_LED1000));
  rb_define_const(ph_module, "ID_LUX1000", INT2NUM(PHIDID_LUX1000));
  rb_define_const(ph_module, "ID_MOT1100", INT2NUM(PHIDID_MOT1100));
  rb_define_const(ph_module, "ID_MOT1101", INT2NUM(PHIDID_MOT1101));
  rb_define_const(ph_module, "ID_OUT1000", INT2NUM(PHIDID_OUT1000));
  rb_define_const(ph_module, "ID_OUT1001", INT2NUM(PHIDID_OUT1001));
  rb_define_const(ph_module, "ID_OUT1002", INT2NUM(PHIDID_OUT1002));
  rb_define_const(ph_module, "ID_OUT1100", INT2NUM(PHIDID_OUT1100));
  rb_define_const(ph_module, "ID_PRE1000", INT2NUM(PHIDID_PRE1000));
  rb_define_const(ph_module, "ID_RCC1000", INT2NUM(PHIDID_RCC1000));
  rb_define_const(ph_module, "ID_REL1000", INT2NUM(PHIDID_REL1000));
  rb_define_const(ph_module, "ID_REL1100", INT2NUM(PHIDID_REL1100));
  rb_define_const(ph_module, "ID_REL1101", INT2NUM(PHIDID_REL1101));
  rb_define_const(ph_module, "ID_SAF1000", INT2NUM(PHIDID_SAF1000));
  rb_define_const(ph_module, "ID_SND1000", INT2NUM(PHIDID_SND1000));
  rb_define_const(ph_module, "ID_STC1000", INT2NUM(PHIDID_STC1000));
  rb_define_const(ph_module, "ID_TMP1000", INT2NUM(PHIDID_TMP1000));
  rb_define_const(ph_module, "ID_TMP1100", INT2NUM(PHIDID_TMP1100));
  rb_define_const(ph_module, "ID_TMP1101", INT2NUM(PHIDID_TMP1101));
  rb_define_const(ph_module, "ID_TMP1200", INT2NUM(PHIDID_TMP1200));
  rb_define_const(ph_module, "ID_VCP1000", INT2NUM(PHIDID_VCP1000));
  rb_define_const(ph_module, "ID_VCP1001", INT2NUM(PHIDID_VCP1001));
  rb_define_const(ph_module, "ID_VCP1002", INT2NUM(PHIDID_VCP1002));
  rb_define_const(ph_module, "ID_DIGITALINPUT_PORT", INT2NUM(PHIDID_DIGITALINPUT_PORT));
  rb_define_const(ph_module, "ID_DIGITALOUTPUT_PORT", INT2NUM(PHIDID_DIGITALOUTPUT_PORT));
  rb_define_const(ph_module, "ID_VOLTAGEINPUT_PORT", INT2NUM(PHIDID_VOLTAGEINPUT_PORT));
  rb_define_const(ph_module, "ID_VOLTAGERATIOINPUT_PORT", INT2NUM(PHIDID_VOLTAGERATIOINPUT_PORT));
  rb_define_const(ph_module, "ID_FIRMWARE_UPGRADE_USB", INT2NUM(PHIDID_FIRMWARE_UPGRADE_USB));
  rb_define_const(ph_module, "ID_FIRMWARE_UPGRADE_STM32F0", INT2NUM(PHIDID_FIRMWARE_UPGRADE_STM32F0));
  rb_define_const(ph_module, "ID_FIRMWARE_UPGRADE_STM32F3", INT2NUM(PHIDID_FIRMWARE_UPGRADE_STM32F3));
  rb_define_const(ph_module, "ID_FIRMWARE_UPGRADE_STM32G0", INT2NUM(PHIDID_FIRMWARE_UPGRADE_STM32G0));
  rb_define_const(ph_module, "ID_FIRMWARE_UPGRADE_STM8S", INT2NUM(PHIDID_FIRMWARE_UPGRADE_STM8S));
  rb_define_const(ph_module, "ID_FIRMWARE_UPGRADE_SPI", INT2NUM(PHIDID_FIRMWARE_UPGRADE_SPI));
  rb_define_const(ph_module, "ID_VCP1100", INT2NUM(PHIDID_VCP1100));
  rb_define_const(ph_module, "ID_DCC1100", INT2NUM(PHIDID_DCC1100));
  rb_define_const(ph_module, "ID_HIN1101", INT2NUM(PHIDID_HIN1101));
  rb_define_const(ph_module, "ID_DCC1001", INT2NUM(PHIDID_DCC1001));
  rb_define_const(ph_module, "ID_DICTIONARY", INT2NUM(PHIDID_DICTIONARY));
  rb_define_const(ph_module, "ID_STC1001", INT2NUM(PHIDID_STC1001));
  rb_define_const(ph_module, "ID_DCC1002", INT2NUM(PHIDID_DCC1002));
  rb_define_const(ph_module, "ID_STC1002", INT2NUM(PHIDID_STC1002));
  rb_define_const(ph_module, "ID_STC1003", INT2NUM(PHIDID_STC1003));
  rb_define_const(ph_module, "ID_DCC1003", INT2NUM(PHIDID_DCC1003));
  rb_define_const(ph_module, "ID_DST1001", INT2NUM(PHIDID_DST1001));
  rb_define_const(ph_module, "ID_HUB5000", INT2NUM(PHIDID_HUB5000));
  rb_define_const(ph_module, "ID_RCC0004", INT2NUM(PHIDID_RCC0004));
  rb_define_const(ph_module, "ID_DST1002", INT2NUM(PHIDID_DST1002));
  rb_define_const(ph_module, "ID_HUM1001", INT2NUM(PHIDID_HUM1001));
  rb_define_const(ph_module, "ID_HUM1100", INT2NUM(PHIDID_HUM1100));
  rb_define_const(ph_module, "ID_MOT0100", INT2NUM(PHIDID_MOT0100));
  rb_define_const(ph_module, "ID_MOT0109", INT2NUM(PHIDID_MOT0109));
  rb_define_const(ph_module, "ID_MOT0110", INT2NUM(PHIDID_MOT0110));
  rb_define_const(ph_module, "ID_MOT1102", INT2NUM(PHIDID_MOT1102));

  rb_define_const(ph_module, "INPUT_MODE_NPN", INT2NUM(INPUT_MODE_NPN));
  rb_define_const(ph_module, "INPUT_MODE_PNP", INT2NUM(INPUT_MODE_PNP));

  rb_define_const(ph_module, "POWER_SUPPLY_OFF", INT2NUM(POWER_SUPPLY_OFF));
  rb_define_const(ph_module, "POWER_SUPPLY_12V", INT2NUM(POWER_SUPPLY_12V));
  rb_define_const(ph_module, "POWER_SUPPLY_24V", INT2NUM(POWER_SUPPLY_24V));

  rb_define_const(ph_module, "RTD_WIRE_SETUP_2WIRE", INT2NUM(RTD_WIRE_SETUP_2WIRE));
  rb_define_const(ph_module, "RTD_WIRE_SETUP_3WIRE", INT2NUM(RTD_WIRE_SETUP_3WIRE));
  rb_define_const(ph_module, "RTD_WIRE_SETUP_4WIRE", INT2NUM(RTD_WIRE_SETUP_4WIRE));

  rb_define_const(ph_module, "FAN_MODE_OFF", INT2NUM(FAN_MODE_OFF));
  rb_define_const(ph_module, "FAN_MODE_ON", INT2NUM(FAN_MODE_ON));
  rb_define_const(ph_module, "FAN_MODE_AUTO", INT2NUM(FAN_MODE_AUTO));

  ph_error = rb_define_class_under(ph_module, "Error", rb_eStandardError);
  rb_define_class_under(ph_error, "NotPermitted", ph_error);
  rb_define_class_under(ph_error, "NoSuchEntity", ph_error);
  rb_define_class_under(ph_error, "TimedOut", ph_error);
  rb_define_class_under(ph_error, "KeepAliveFailure", ph_error);
  rb_define_class_under(ph_error, "OpInterrupted", ph_error);
  rb_define_class_under(ph_error, "IOError", ph_error);
  rb_define_class_under(ph_error, "MemoryError", ph_error);
  rb_define_class_under(ph_error, "AccessError", ph_error);
  rb_define_class_under(ph_error, "AddressError", ph_error);
  rb_define_class_under(ph_error, "ResourceBusy", ph_error);
  rb_define_class_under(ph_error, "ObjectExists", ph_error);
  rb_define_class_under(ph_error, "ObjectNotDirectory", ph_error);
  rb_define_class_under(ph_error, "ObjectIsDirectory", ph_error);
  rb_define_class_under(ph_error, "Invalid", ph_error);
  rb_define_class_under(ph_error, "TooManyOpenFilesInSystem", ph_error);
  rb_define_class_under(ph_error, "TooManyOpenFiles", ph_error);
  rb_define_class_under(ph_error, "NoSpace", ph_error);
  rb_define_class_under(ph_error, "FileTooBig", ph_error);
  rb_define_class_under(ph_error, "ReadOnlyFilesystem", ph_error);
  rb_define_class_under(ph_error, "ReadOnlyObject", ph_error);
  rb_define_class_under(ph_error, "OpNotSupported", ph_error);
  rb_define_class_under(ph_error, "InvalidArg", ph_error);
  rb_define_class_under(ph_error, "TryAgain", ph_error);
  rb_define_class_under(ph_error, "NotEmpty", ph_error);
  rb_define_class_under(ph_error, "UnexpectedError", ph_error);
  rb_define_class_under(ph_error, "Duplicate", ph_error);
  rb_define_class_under(ph_error, "BadCredential", ph_error);
  rb_define_class_under(ph_error, "NetworkUnavailable", ph_error);
  rb_define_class_under(ph_error, "ConnectionRefused", ph_error);
  rb_define_class_under(ph_error, "ConnectionReset", ph_error);
  rb_define_class_under(ph_error, "NoRouteToHost", ph_error);
  rb_define_class_under(ph_error, "NoSuchDevice", ph_error);
  rb_define_class_under(ph_error, "WrongDevice", ph_error);
  rb_define_class_under(ph_error, "BrokenPipe", ph_error);
  rb_define_class_under(ph_error, "NameResolutionError", ph_error);
  rb_define_class_under(ph_error, "UnknownValue", ph_error);
  rb_define_class_under(ph_error, "DeviceNotAttached", ph_error);
  rb_define_class_under(ph_error, "InvalidPacket", ph_error);
  rb_define_class_under(ph_error, "ArgListTooLong", ph_error);
  rb_define_class_under(ph_error, "BadVersion", ph_error);
  rb_define_class_under(ph_error, "Closed", ph_error);
  rb_define_class_under(ph_error, "NotConfigured", ph_error);
  rb_define_class_under(ph_error, "EndOfFile", ph_error);
  rb_define_class_under(ph_error, "NotImplemented", ph_error);
  rb_define_class_under(ph_error, "UnknownError", ph_error);
  rb_define_class_under(ph_error, "FailSafe", ph_error);
  rb_define_class_under(ph_error, "InvalidValueHigh", ph_error);
  rb_define_class_under(ph_error, "InvalidValueLow", ph_error);

  /*
   * Document-method: getLibraryVersion
   * call-seq: getLibraryVersion -> version
   *
   * Gets the library version. This contains a version number and a build date.
   */
  rb_define_singleton_method(ph_module, "getLibraryVersion", ph_get_library_version, 0);
  rb_define_singleton_method(ph_module, "library_version", ph_get_library_version, 0);


  /*
   * Document-method: addServer
   * call-seq: addServer(server_name, address, port, password, flags)
   *
   * Registers a server that the client (your program) will try to connect to. The client will continually try to connect to the server, increasing the time between each attempt to a maximum interval of 16 seconds.
   * This call is intended for use when server discovery is not enabled, or to connect to a server that is not discoverable.
   * The server name used by this function does not have to match the name of the server running on the host machine. Only the address, port, and password need to match.
   * This call will fail if a server with the same name has already been discovered.
   * This call will fail if PhidgetNet_setServerPassword() has already been called with the same server name, as PhidgetNet_setServerPassword() registers the server entry anticipating the discovery of the server.
   */
  rb_define_singleton_method(ph_module, "addServer", ph_add_server, 5);
  rb_define_singleton_method(ph_module, "add_server", ph_add_server, 5);


  /*
   * Document-method: removeServer
   * call-seq: removeServer(server_name)
   *
   * Removes a registration for a server that the client (your program) is trying to connect to.If the client is currently connected to the server, the connection will be closed.
   * If the server was discovered (not added by PhidgetNet_addServer()), the connection may be reestablished if and when the server is rediscovered. PhidgetNet_disableServer()
   * should be used to prevent the reconnection of a discovered server.
   */
  rb_define_singleton_method(ph_module, "removeServer", ph_remove_server, 1);
  rb_define_singleton_method(ph_module, "remove_server", ph_remove_server, 1);


  /*
   * Document-method: enableServer
   * call-seq: enableServer(server_name)
   *
   * Enables attempts to connect to a discovered server, if attempts were previously disabled by PhidgetNet_disableServer(). All servers are enabled by default.
   * This call will fail if the server was not previously added, disabled or discovered.
   */
  rb_define_singleton_method(ph_module, "enableServer", ph_enable_server, 1);
  rb_define_singleton_method(ph_module, "enable_server", ph_enable_server, 1);


  /*
   * Document-method: disableServer
   * call-seq: disableServer(server_name, flags)
   *
   * Prevents attempts to automatically connect to a server.
   * By default the client (your program) will continually attempt to connect to added or discovered servers.This call will disable those attempts, but will not close an already established connection.
   */
  rb_define_singleton_method(ph_module, "disableServer", ph_disable_server, 2);
  rb_define_singleton_method(ph_module, "disable_server", ph_disable_server, 2);


  /*
   * Document-method: enableServerDiscovery
   * call-seq: enableServerDiscovery(server_type)
   *
   * Enables the dynamic discovery of servers that publish their identity to the network. Currently Multicast DNS is used to discover and publish Phidget servers.
   * To connect to remote Phidgets, call this function with server type DEVICEREMOTE.
   * PhidgetNet_enableServerDiscovery() must be called once for each server type your program requires. Multiple calls for the same server type are ignored
   * This call will fail with the error code EPHIDGET_UNSUPPORTED if your computer does not have the required mDNS support. We recommend using Bonjour Print Services on Windows and Mac, or Avahi on Linux.
   */
  rb_define_singleton_method(ph_module, "enableServerDiscovery", ph_enable_server_discovery, 1);
  rb_define_singleton_method(ph_module, "enable_server_discovery", ph_enable_server_discovery, 1);


  /*
   * Document-method: disableServerDiscovery
   * call-seq: disableServerDiscovery(server_type)
   *
   * Disables the dynamic discovery of servers that publish their identity.
   * PhidgetNet_disableServerDiscovery() does not disconnect already established connections.
   */
  rb_define_singleton_method(ph_module, "disableServerDiscovery", ph_disable_server_discovery, 1);
  rb_define_singleton_method(ph_module, "disable_server_discovery", ph_disable_server_discovery, 1);


  /*
   * Document-method: setServerPassword
   * call-seq: setServerPassword(server_name, password)
   *
   * Sets the password that will be used to attempt to connect to the server. If the server has not already been added or discovered, a placeholder server entry
   * will be registered to use this password on the server once it is discovered.
   */
  rb_define_singleton_method(ph_module, "setServerPassword", ph_set_server_password, 2);
  rb_define_singleton_method(ph_module, "server_password", ph_set_server_password, 2);


  Init_logging();
  Init_manager();
  Init_common();
  Init_accelerometer();
  Init_bldc_motor();
  Init_capacitive_touch();
  Init_current_input();
  Init_dc_motor();
  Init_dictionary();
  Init_digital_input();
  Init_digital_output();
  Init_distance();
  Init_encoder();
  Init_frequency_counter();
  Init_gps();
  Init_gyroscope();
  Init_hub();
  Init_humidity();
  Init_ir();
  Init_lcd();
  Init_light();
  Init_magnetometer();
  Init_motor_position_controller();
  Init_ph_sensor();
  Init_power_guard();
  Init_pressure();
  Init_rc_servo();
  Init_rfid();
  Init_resistance();
  Init_sound();
  Init_spatial();
  Init_stepper();
  Init_temperature_sensor();
  Init_voltage_input();
  Init_voltage_output();
  Init_voltage_ratio_input();
}


ph_data_t *get_ph_data(VALUE self) {
  ph_data_t *ph;
  Data_Get_Struct(self, ph_data_t, ph);
  return ph;
}

PhidgetHandle get_ph_handle(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  return ph->handle;
}

void ph_raise(int err_code) {
  if(err_code != EPHIDGET_OK) {
    VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
    VALUE ph_error = rb_const_get(ph_module, rb_intern("Error"));

    switch( err_code ) {
      case EPHIDGET_PERM:
        rb_raise(rb_const_get(ph_error, rb_intern("NotPermitted")), "Not Permitted");
        break;
      case EPHIDGET_NOENT:
        rb_raise(rb_const_get(ph_error, rb_intern("NoSuchEntity")), "No Such Entity");
        break;
      case EPHIDGET_TIMEOUT:
        rb_raise(rb_const_get(ph_error, rb_intern("TimedOut")), "Timed Out");
        break;
      case EPHIDGET_KEEPALIVE:
        rb_raise(rb_const_get(ph_error, rb_intern("KeepAliveFailure")), "Keep Alive Failure");
        break;
      case EPHIDGET_INTERRUPTED:
        rb_raise(rb_const_get(ph_error, rb_intern("OpInterrupted")), "Op Interrupted");
        break;
      case EPHIDGET_IO:
        rb_raise(rb_const_get(ph_error, rb_intern("IOError")), "IO Issue");
        break;
      case EPHIDGET_NOMEMORY:
        rb_raise(rb_const_get(ph_error, rb_intern("MemoryError")), "Memory Issue");
        break;
      case EPHIDGET_ACCESS:
        rb_raise(rb_const_get(ph_error, rb_intern("AccessError")), "Access (Permission) Issue");
        break;
      case EPHIDGET_FAULT:
        rb_raise(rb_const_get(ph_error, rb_intern("AddressError")), "Address Issue");
        break;
      case EPHIDGET_BUSY:
        rb_raise(rb_const_get(ph_error, rb_intern("ResourceBusy")), "Resource Busy");
        break;
      case EPHIDGET_EXIST:
        rb_raise(rb_const_get(ph_error, rb_intern("ObjectExists")), "Object Exists");
        break;
      case EPHIDGET_NOTDIR:
        rb_raise(rb_const_get(ph_error, rb_intern("ObjectNotDirectory")), "Object is not a directory");
        break;
      case EPHIDGET_ISDIR:
        rb_raise(rb_const_get(ph_error, rb_intern("ObjectIsDirectory")), "Object is a directory");
        break;
      case EPHIDGET_INVALID:
        rb_raise(rb_const_get(ph_error, rb_intern("Invalid")), "Invalid");
        break;
      case EPHIDGET_NFILE:
        rb_raise(rb_const_get(ph_error, rb_intern("TooManyOpenFilesInSystem")), "Too many open files in system");
        break;
      case EPHIDGET_MFILE:
        rb_raise(rb_const_get(ph_error, rb_intern("TooManyOpenFiles")), "Too many open files");
        break;
      case EPHIDGET_NOSPC:
        rb_raise(rb_const_get(ph_error, rb_intern("NoSpace")), "Not enough space");
        break;
      case EPHIDGET_FBIG:
        rb_raise(rb_const_get(ph_error, rb_intern("FileTooBig")), "File too Big");
        break;
      case EPHIDGET_ROFS:
        rb_raise(rb_const_get(ph_error, rb_intern("ReadOnlyFilesystem")), "Read Only Filesystem");
        break;
      case EPHIDGET_RO:
        rb_raise(rb_const_get(ph_error, rb_intern("ReadOnlyObject")), "Read Only Object");
        break;
      case EPHIDGET_UNSUPPORTED:
        rb_raise(rb_const_get(ph_error, rb_intern("OpNotSupported")), "Operation Not Supported");
        break;
      case EPHIDGET_INVALIDARG:
        rb_raise(rb_const_get(ph_error, rb_intern("InvalidArg")), "Invalid Argument");
        break;
      case EPHIDGET_AGAIN:
        rb_raise(rb_const_get(ph_error, rb_intern("TryAgain")), "Try again");
        break;
      case EPHIDGET_NOTEMPTY:
        rb_raise(rb_const_get(ph_error, rb_intern("NotEmpty")), "Not Empty");
        break;
      case EPHIDGET_UNEXPECTED:
        rb_raise(rb_const_get(ph_error, rb_intern("UnexpectedError")), "Unexpected Error");
        break;
      case EPHIDGET_DUPLICATE:
        rb_raise(rb_const_get(ph_error, rb_intern("Duplicate")), "Duplicate");
        break;
      case EPHIDGET_BADPASSWORD:
        rb_raise(rb_const_get(ph_error, rb_intern("BadCredential")), "Bad Credential");
        break;
      case EPHIDGET_NETUNAVAIL:
        rb_raise(rb_const_get(ph_error, rb_intern("NetworkUnavailable")), "Network Unavailable");
        break;
      case EPHIDGET_CONNREF:
        rb_raise(rb_const_get(ph_error, rb_intern("ConnectionRefused")), "Connection Refused");
        break;
      case EPHIDGET_CONNRESET:
        rb_raise(rb_const_get(ph_error, rb_intern("ConnectionReset")), "Connection Reset");
        break;
      case EPHIDGET_HOSTUNREACH:
        rb_raise(rb_const_get(ph_error, rb_intern("NoRouteToHost")), "No route to host");
        break;
      case EPHIDGET_NODEV:
        rb_raise(rb_const_get(ph_error, rb_intern("NoSuchDevice")), "No Such Device");
        break;
      case EPHIDGET_WRONGDEVICE:
        rb_raise(rb_const_get(ph_error, rb_intern("WrongDevice")), "Wrong Device");
        break;
      case EPHIDGET_PIPE:
        rb_raise(rb_const_get(ph_error, rb_intern("BrokenPipe")), "Broken Pipe");
        break;
      case EPHIDGET_RESOLV:
        rb_raise(rb_const_get(ph_error, rb_intern("NameResolutionError")), "Name Resolution Failure");
        break;
      case EPHIDGET_UNKNOWNVAL:
        rb_raise(rb_const_get(ph_error, rb_intern("UnknownValue")), "Unknown or Invalid Value");
        break;
      case EPHIDGET_NOTATTACHED:
        rb_raise(rb_const_get(ph_error, rb_intern("DeviceNotAttached")), "Device not Attached");
        break;
      case EPHIDGET_INVALIDPACKET:
        rb_raise(rb_const_get(ph_error, rb_intern("InvalidPacket")), "Invalid or Unexpected Packet");
        break;
      case EPHIDGET_2BIG:
        rb_raise(rb_const_get(ph_error, rb_intern("ArgListTooLong")), "Argument List Too Long");
        break;
      case EPHIDGET_BADVERSION:
        rb_raise(rb_const_get(ph_error, rb_intern("BadVersion")), "Bad Version");
        break;
      case EPHIDGET_CLOSED:
        rb_raise(rb_const_get(ph_error, rb_intern("Closed")), "Closed");
        break;
      case EPHIDGET_NOTCONFIGURED:
        rb_raise(rb_const_get(ph_error, rb_intern("NotConfigured")), "Not Configured");
        break;
      case EPHIDGET_EOF:
        rb_raise(rb_const_get(ph_error, rb_intern("EndOfFile")), "End of File");
        break;
      case EPHIDGET_FAILSAFE:
        rb_raise(rb_const_get(ph_error, rb_intern("FailSafe")), "Failsafe condition detected");
        break;
      case EPHIDGET_UNKNOWNVALHIGH:
        rb_raise(rb_const_get(ph_error, rb_intern("InvalidValueHigh")), "The value has been measured to be higher than the valid range of the sensor");
        break;
      case EPHIDGET_UNKNOWNVALLOW:
        rb_raise(rb_const_get(ph_error, rb_intern("InvalidValueLow")), "The value has been measured to be lower than the valid range of the sensor");
        break;
      case EPHIDGET_NOTIMPLEMENTED:
        rb_raise(rb_const_get(ph_error, rb_intern("NotImplemented")), "This functionality has not been implemented yet");
        break;
      default:
        rb_raise(rb_const_get(ph_error, rb_intern("UnknownError")), "Unknown Error");
    }
  }
}


VALUE ph_get_instance_from_handle(PhidgetHandle ph_handle) {
  VALUE ph_module = rb_const_get(rb_cModule, rb_intern("Phidgets"));
  VALUE klass;
  VALUE argv[0];
  Phidget_ChannelClass ch_class;
  Phidget_getChannelClass(ph_handle, &ch_class);

  switch( ch_class ) {
    case PHIDCHCLASS_ACCELEROMETER:
      klass = rb_const_get(ph_module, rb_intern("Accelerometer"));
      break;
    case PHIDCHCLASS_BLDCMOTOR:
      klass = rb_const_get(ph_module, rb_intern("BLDCMotor"));
      break;
    case PHIDCHCLASS_CAPACITIVETOUCH:
      klass = rb_const_get(ph_module, rb_intern("CapacitiveTouch"));
      break;
    case PHIDCHCLASS_CURRENTINPUT:
      klass = rb_const_get(ph_module, rb_intern("CurrentInput"));
      break;
    case PHIDCHCLASS_DCMOTOR:
      klass = rb_const_get(ph_module, rb_intern("DCMotor"));
      break;
    case PHIDCHCLASS_DIGITALINPUT:
      klass = rb_const_get(ph_module, rb_intern("DigitalInput"));
      break;
    case PHIDCHCLASS_DIGITALOUTPUT:
      klass = rb_const_get(ph_module, rb_intern("DigitalOutput"));
      break;
    case PHIDCHCLASS_DISTANCESENSOR:
      klass = rb_const_get(ph_module, rb_intern("DistanceSensor"));
      break;
    case PHIDCHCLASS_ENCODER:
      klass = rb_const_get(ph_module, rb_intern("Encoder"));
      break;
    case PHIDCHCLASS_FREQUENCYCOUNTER:
      klass = rb_const_get(ph_module, rb_intern("FrequencyCounter"));
      break;
    case PHIDCHCLASS_GPS:
      klass = rb_const_get(ph_module, rb_intern("GPS"));
      break;
    case PHIDCHCLASS_GYROSCOPE:
      klass = rb_const_get(ph_module, rb_intern("Gyroscope"));
      break;
    case PHIDCHCLASS_HUB:
      klass = rb_const_get(ph_module, rb_intern("Hub"));
      break;
    case PHIDCHCLASS_HUMIDITYSENSOR:
      klass = rb_const_get(ph_module, rb_intern("HumiditySensor"));
      break;
    case PHIDCHCLASS_IR:
      klass = rb_const_get(ph_module, rb_intern("IR"));
      break;
    case PHIDCHCLASS_LCD:
      klass = rb_const_get(ph_module, rb_intern("LCD"));
      break;
    case PHIDCHCLASS_LIGHTSENSOR:
      klass = rb_const_get(ph_module, rb_intern("LightSensor"));
      break;
    case PHIDCHCLASS_MAGNETOMETER:
      klass = rb_const_get(ph_module, rb_intern("Magnetometer"));
      break;
    case PHIDCHCLASS_MOTORPOSITIONCONTROLLER:
      klass = rb_const_get(ph_module, rb_intern("MotorPositionController"));
      break;
    case PHIDCHCLASS_PHSENSOR:
      klass = rb_const_get(ph_module, rb_intern("PHSensor"));
      break;
    case PHIDCHCLASS_POWERGUARD:
      klass = rb_const_get(ph_module, rb_intern("PowerGuard"));
      break;
    case PHIDCHCLASS_PRESSURESENSOR:
      klass = rb_const_get(ph_module, rb_intern("PressureSensor"));
      break;
    case PHIDCHCLASS_RCSERVO:
      klass = rb_const_get(ph_module, rb_intern("RCServo"));
      break;
    case PHIDCHCLASS_RESISTANCEINPUT:
      klass = rb_const_get(ph_module, rb_intern("ResistanceInput"));
      break;
    case PHIDCHCLASS_RFID:
      klass = rb_const_get(ph_module, rb_intern("RFID"));
      break;
    case PHIDCHCLASS_SOUNDSENSOR:
      klass = rb_const_get(ph_module, rb_intern("SoundSensor"));
      break;
    case PHIDCHCLASS_SPATIAL:
      klass = rb_const_get(ph_module, rb_intern("Spatial"));
      break;
    case PHIDCHCLASS_STEPPER:
      klass = rb_const_get(ph_module, rb_intern("Stepper"));
      break;
    case PHIDCHCLASS_TEMPERATURESENSOR:
      klass = rb_const_get(ph_module, rb_intern("TemperatureSensor"));
      break;
    case PHIDCHCLASS_VOLTAGEINPUT:
      klass = rb_const_get(ph_module, rb_intern("VoltageInput"));
      break;
    case PHIDCHCLASS_VOLTAGEOUTPUT:
      klass = rb_const_get(ph_module, rb_intern("VoltageOutput"));
      break;
    case PHIDCHCLASS_VOLTAGERATIOINPUT:
      klass = rb_const_get(ph_module, rb_intern("VoltageRatioInput"));
      break;
    case PHIDCHCLASS_DICTIONARY:
      klass = rb_const_get(ph_module, rb_intern("Dictionary"));
      break;
    default:
      klass = Qnil;
  }

  return rb_class_new_instance(0, argv, klass);
}


VALUE ph_get_int(PhidgetHandle handle, PhidgetReturnCode (*func)(PhidgetHandle, int *))
{
  int value;
  ph_raise(func(handle, &value));
  return INT2NUM(value);
}


VALUE ph_get_uint(PhidgetHandle handle, PhidgetReturnCode (*func)(PhidgetHandle, uint32_t *))
{
  uint32_t value;
  ph_raise(func(handle, &value));
  return UINT2NUM(value);
}


VALUE ph_get_int64(PhidgetHandle handle, PhidgetReturnCode (*func)(PhidgetHandle, int64_t *))
{
  int64_t value;
  ph_raise(func(handle, &value));
  return LL2NUM(value);
}


VALUE ph_get_uint64(PhidgetHandle handle, PhidgetReturnCode (*func)(PhidgetHandle, uint64_t *))
{
  uint64_t value;
  ph_raise(func(handle, &value));
  return ULL2NUM(value);
}


VALUE ph_get_bool(PhidgetHandle handle, PhidgetReturnCode (*func)(PhidgetHandle, int *))
{
  int value;
  ph_raise(func(handle, &value));
  return value == PTRUE ? Qtrue : Qfalse;
}


VALUE ph_get_double(PhidgetHandle handle, PhidgetReturnCode (*func)(PhidgetHandle, double *))
{
  double value;
  ph_raise(func(handle, &value));
  return DBL2NUM(value);
}


VALUE ph_get_string(PhidgetHandle handle, PhidgetReturnCode (*func)(PhidgetHandle, const char **))
{
  const char *value;
  ph_raise(func(handle, &value));
  if(value == NULL) return Qnil;
  return rb_str_new2(value);
}


void ph_callback_thread(ph_callback_data_t *callback_data) {
  while(! callback_data->exit) {
    rb_thread_call_without_gvl(wait_for_callback, (void *)callback_data, cancel_wait_for_callback, (void *)callback_data);
    if(TYPE(callback_data->callback) != T_NIL) rb_funcall(callback_data->callback, rb_intern("call"), 5, callback_data->phidget, callback_data->arg1, callback_data->arg2, callback_data->arg3, callback_data->arg4);
  };
}

void *wait_for_callback(void *arg) {
  ph_callback_data_t *callback_data = (ph_callback_data_t *)arg;
  while(! callback_data->exit) {
    sem_post(&callback_data->handler_ready);
    while(sem_wait(&callback_data->callback_called)!=0) {};
    return (void *)Qnil;
  };
  return (void *)Qnil;
}

void cancel_wait_for_callback(void *arg) {
  ph_callback_data_t *callback_data = (ph_callback_data_t *)arg;
  callback_data->callback = T_NIL;
  callback_data->exit = true;
  sem_post(&callback_data->handler_ready);
  sem_post(&callback_data->callback_called);
}

