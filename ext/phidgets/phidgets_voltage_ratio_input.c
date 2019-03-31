
#include "phidgets.h"

#define VOLTAGE_RATIO_INPUT_SENSOR_CHANGE_CALLBACK        0
#define VOLTAGE_RATIO_INPUT_VOLTAGE_RATIO_CHANGE_CALLBACK 1


VALUE ph_voltage_ratio_input_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetVoltageRatioInput_create((PhidgetVoltageRatioInputHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_voltage_ratio_input_get_bridge_enabled(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetVoltageRatioInput_getBridgeEnabled);
}

VALUE ph_voltage_ratio_input_set_bridge_enabled(VALUE self, VALUE enabled) {
  ph_raise(PhidgetVoltageRatioInput_setBridgeEnabled((PhidgetVoltageRatioInputHandle)get_ph_handle(self), TYPE(enabled) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_voltage_ratio_input_get_bridge_gain(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetVoltageRatioInput_getBridgeGain);
}

VALUE ph_voltage_ratio_input_set_bridge_gain(VALUE self, VALUE bridge_gain) {
  ph_raise(PhidgetVoltageRatioInput_setBridgeGain((PhidgetVoltageRatioInputHandle)get_ph_handle(self), NUM2INT(bridge_gain)));
  return Qnil;
}

VALUE ph_voltage_ratio_input_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetVoltageRatioInput_getDataInterval);
}

VALUE ph_voltage_ratio_input_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetVoltageRatioInput_setDataInterval((PhidgetVoltageRatioInputHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_voltage_ratio_input_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetVoltageRatioInput_getMinDataInterval);
}

VALUE ph_voltage_ratio_input_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetVoltageRatioInput_getMaxDataInterval);
}

VALUE ph_voltage_ratio_input_get_sensor_type(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetVoltageRatioInput_getSensorType);
}

VALUE ph_voltage_ratio_input_set_sensor_type(VALUE self, VALUE sensor_type) {
  ph_raise(PhidgetVoltageRatioInput_setSensorType((PhidgetVoltageRatioInputHandle)get_ph_handle(self), NUM2INT(sensor_type)));
  return Qnil;
}

VALUE ph_voltage_ratio_input_get_sensor_unit(VALUE self) {
  VALUE unit_info = rb_hash_new();
  Phidget_UnitInfo sensorUnit;
  ph_raise(PhidgetVoltageRatioInput_getSensorUnit((PhidgetVoltageRatioInputHandle)get_ph_handle(self), &sensorUnit));
  rb_hash_aset(unit_info, rb_str_new2("unit"), INT2NUM(sensorUnit.unit));
  rb_hash_aset(unit_info, rb_str_new2("name"), rb_str_new2(sensorUnit.name));
  rb_hash_aset(unit_info, rb_str_new2("symbol"), rb_str_new2(sensorUnit.symbol));
  return unit_info;
}

VALUE ph_voltage_ratio_input_get_sensor_value(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getSensorValue);
}

VALUE ph_voltage_ratio_input_get_sensor_value_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getSensorValueChangeTrigger);
}

VALUE ph_voltage_ratio_input_set_sensor_value_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetVoltageRatioInput_setSensorValueChangeTrigger((PhidgetVoltageRatioInputHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_voltage_ratio_input_get_voltage_ratio(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getVoltageRatio);
}

VALUE ph_voltage_ratio_input_get_min_voltage_ratio(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getMinVoltageRatio);
}

VALUE ph_voltage_ratio_input_get_max_voltage_ratio(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getMaxVoltageRatio);
}

VALUE ph_voltage_ratio_input_get_voltage_ratio_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getVoltageRatioChangeTrigger);
}

VALUE ph_voltage_ratio_input_set_voltage_ratio_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetVoltageRatioInput_setVoltageRatioChangeTrigger((PhidgetVoltageRatioInputHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_voltage_ratio_input_get_min_voltage_ratio_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getMinVoltageRatioChangeTrigger);
}

VALUE ph_voltage_ratio_input_get_max_voltage_ratio_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageRatioInput_getMaxVoltageRatioChangeTrigger);
}


void CCONV ph_voltage_ratio_input_on_sensor_change(PhidgetVoltageRatioInputHandle phid, void *userPtr, double sensor_value, Phidget_UnitInfo *sensor_unit) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(sensor_value);
  callback_data->arg2 = INT2NUM(sensor_unit->unit);
  callback_data->arg3 = rb_str_new2(sensor_unit->name);
  callback_data->arg4 = rb_str_new2(sensor_unit->symbol);
  sem_post(&callback_data->callback_called);
}

VALUE ph_voltage_ratio_input_set_on_sensor_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[VOLTAGE_RATIO_INPUT_SENSOR_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetVoltageRatioInput_setOnSensorChangeHandler((PhidgetVoltageRatioInputHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetVoltageRatioInput_setOnSensorChangeHandler((PhidgetVoltageRatioInputHandle)ph->handle, ph_voltage_ratio_input_on_sensor_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_voltage_ratio_input_on_voltage_ratio_change(PhidgetVoltageRatioInputHandle phid, void *userPtr, double voltage_ratio) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(voltage_ratio);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}

VALUE ph_voltage_ratio_input_set_on_voltage_ratio_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[VOLTAGE_RATIO_INPUT_VOLTAGE_RATIO_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetVoltageRatioInput_setOnVoltageRatioChangeHandler((PhidgetVoltageRatioInputHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetVoltageRatioInput_setOnVoltageRatioChangeHandler((PhidgetVoltageRatioInputHandle)ph->handle, ph_voltage_ratio_input_on_voltage_ratio_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_voltage_ratio_input() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_voltage_ratio_input = rb_define_class_under(ph_module, "VoltageRatioInput", ph_common);


  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_VOLTAGERATIO", INT2NUM(SENSOR_TYPE_VOLTAGERATIO));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1101_SHARP_2D120X", INT2NUM(SENSOR_TYPE_1101_SHARP_2D120X));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1101_SHARP_2Y0A21", INT2NUM(SENSOR_TYPE_1101_SHARP_2Y0A21));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1101_SHARP_2Y0A02", INT2NUM(SENSOR_TYPE_1101_SHARP_2Y0A02));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1102", INT2NUM(SENSOR_TYPE_1102));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1103", INT2NUM(SENSOR_TYPE_1103));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1104", INT2NUM(SENSOR_TYPE_1104));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1105", INT2NUM(SENSOR_TYPE_1105));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1106", INT2NUM(SENSOR_TYPE_1106));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1107", INT2NUM(SENSOR_TYPE_1107));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1108", INT2NUM(SENSOR_TYPE_1108));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1109", INT2NUM(SENSOR_TYPE_1109));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1110", INT2NUM(SENSOR_TYPE_1110));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1111", INT2NUM(SENSOR_TYPE_1111));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1112", INT2NUM(SENSOR_TYPE_1112));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1113", INT2NUM(SENSOR_TYPE_1113));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1115", INT2NUM(SENSOR_TYPE_1115));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1116", INT2NUM(SENSOR_TYPE_1116));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1118_AC", INT2NUM(SENSOR_TYPE_1118_AC));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1118_DC", INT2NUM(SENSOR_TYPE_1118_DC));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1119_AC", INT2NUM(SENSOR_TYPE_1119_AC));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1119_DC", INT2NUM(SENSOR_TYPE_1119_DC));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1120", INT2NUM(SENSOR_TYPE_1120));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1121", INT2NUM(SENSOR_TYPE_1121));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1122_AC", INT2NUM(SENSOR_TYPE_1122_AC));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1122_DC", INT2NUM(SENSOR_TYPE_1122_DC));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1124", INT2NUM(SENSOR_TYPE_1124));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1125_HUMIDITY", INT2NUM(SENSOR_TYPE_1125_HUMIDITY));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1125_TEMPERATURE", INT2NUM(SENSOR_TYPE_1125_TEMPERATURE));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1126", INT2NUM(SENSOR_TYPE_1126));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1128", INT2NUM(SENSOR_TYPE_1128));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1129", INT2NUM(SENSOR_TYPE_1129));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1131", INT2NUM(SENSOR_TYPE_1131));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1134", INT2NUM(SENSOR_TYPE_1134));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1136", INT2NUM(SENSOR_TYPE_1136));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1137", INT2NUM(SENSOR_TYPE_1137));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1138", INT2NUM(SENSOR_TYPE_1138));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1139", INT2NUM(SENSOR_TYPE_1139));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1140", INT2NUM(SENSOR_TYPE_1140));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1141", INT2NUM(SENSOR_TYPE_1141));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_1146", INT2NUM(SENSOR_TYPE_1146));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3120", INT2NUM(SENSOR_TYPE_3120));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3121", INT2NUM(SENSOR_TYPE_3121));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3122", INT2NUM(SENSOR_TYPE_3122));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3123", INT2NUM(SENSOR_TYPE_3123));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3130", INT2NUM(SENSOR_TYPE_3130));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3520", INT2NUM(SENSOR_TYPE_3520));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3521", INT2NUM(SENSOR_TYPE_3521));
  rb_define_const(ph_voltage_ratio_input, "SENSOR_TYPE_3522", INT2NUM(SENSOR_TYPE_3522));

  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_1", INT2NUM(BRIDGE_GAIN_1));
  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_2", INT2NUM(BRIDGE_GAIN_2));
  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_4", INT2NUM(BRIDGE_GAIN_4));
  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_8", INT2NUM(BRIDGE_GAIN_8));
  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_16", INT2NUM(BRIDGE_GAIN_16));
  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_32", INT2NUM(BRIDGE_GAIN_32));
  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_64", INT2NUM(BRIDGE_GAIN_64));
  rb_define_const(ph_voltage_ratio_input, "BRIDGE_GAIN_128", INT2NUM(BRIDGE_GAIN_128));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget VoltageInput object.
   */
  rb_define_method(ph_voltage_ratio_input, "initialize", ph_voltage_ratio_input_init, 0);

  /* Document-method: getBridgeEnabled
   * call-seq: getBridgeEnabled -> bridge_enabled
   *
   * Enable power to and data from the input by setting BridgeEnabled to true.
   */
  rb_define_method(ph_voltage_ratio_input, "getBridgeEnabled", ph_voltage_ratio_input_get_bridge_enabled, 0);
  rb_define_alias(ph_voltage_ratio_input, "bridge_enabled?", "getBridgeEnabled");

  /* Document-method: setBridgeEnabled
   * call-seq: setBridgeEnabled(bridge_enabled)
   *
   * Enable power to and data from the input by setting BridgeEnabled to true.
   */
  rb_define_method(ph_voltage_ratio_input, "setBridgeEnabled", ph_voltage_ratio_input_set_bridge_enabled, 1);
  rb_define_alias(ph_voltage_ratio_input, "bridge_enabled=", "setBridgeEnabled");

  /* Document-method: getBridgeGain
   * call-seq: getBridgeGain -> bridge_gain
   *
   * Choose a BridgeGain that best suits your application.
   * For more information about the range and accuracy of each BridgeGain to decide which best suits your application, see your device's User Guide.
   */
  rb_define_method(ph_voltage_ratio_input, "getBridgeGain", ph_voltage_ratio_input_get_bridge_gain, 0);
  rb_define_alias(ph_voltage_ratio_input, "bridge_gain", "getBridgeGain");

  /* Document-method: setBridgeGain
   * call-seq: setBridgeGain(bridge_gain)
   *
   * Choose a BridgeGain that best suits your application.
   * For more information about the range and accuracy of each BridgeGain to decide which best suits your application, see your device's User Guide.
   */
  rb_define_method(ph_voltage_ratio_input, "setBridgeGain", ph_voltage_ratio_input_set_bridge_gain, 1);
  rb_define_alias(ph_voltage_ratio_input, "bridge_gain=", "setBridgeGain");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between events can also affected by the change trigger values.
   */
  rb_define_method(ph_voltage_ratio_input, "getDataInterval", ph_voltage_ratio_input_get_data_interval, 0);
  rb_define_alias(ph_voltage_ratio_input, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between events can also affected by the change trigger values.
   */
  rb_define_method(ph_voltage_ratio_input, "setDataInterval", ph_voltage_ratio_input_set_data_interval, 1);
  rb_define_alias(ph_voltage_ratio_input, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_voltage_ratio_input, "getMinDataInterval", ph_voltage_ratio_input_get_min_data_interval, 0);
  rb_define_alias(ph_voltage_ratio_input, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_voltage_ratio_input, "getMaxDataInterval", ph_voltage_ratio_input_get_max_data_interval, 0);
  rb_define_alias(ph_voltage_ratio_input, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getSensorType
   * call-seq: getSensorType -> sensor_type
   *
   * We sell a variety of analog sensors that do not have their own API, they simply output a voltage that can be converted to a digital value using a specific formula.
   * By matching the SensorType to your analog sensor, the correct formula will automatically be applied to data when you get the SensorValue or subscribe to the SensorChange event.
   * The SensorChange event has its own change trigger associated with it: SensorValueChangeTrigger.
   * Any data from getting the SensorValue or subscribing to the SensorChange event will have a SensorUnit associated with it.
   * Note: Unlike other properties such as DeviceSerialNumber or Channel, SensorType is set after the device is opened, not before.
   */
  rb_define_method(ph_voltage_ratio_input, "getSensorType", ph_voltage_ratio_input_get_sensor_type, 0);
  rb_define_alias(ph_voltage_ratio_input, "sensor_type", "getSensorType");

  /* Document-method: setSensorType
   * call-seq: setSensorType(sensor_type)
   *
   * We sell a variety of analog sensors that do not have their own API, they simply output a voltage that can be converted to a digital value using a specific formula.
   * By matching the SensorType to your analog sensor, the correct formula will automatically be applied to data when you get the SensorValue or subscribe to the SensorChange event.
   * The SensorChange event has its own change trigger associated with it: SensorValueChangeTrigger.
   * Any data from getting the SensorValue or subscribing to the SensorChange event will have a SensorUnit associated with it.
   * Note: Unlike other properties such as DeviceSerialNumber or Channel, SensorType is set after the device is opened, not before.
   */
  rb_define_method(ph_voltage_ratio_input, "setSensorType", ph_voltage_ratio_input_set_sensor_type, 1);
  rb_define_alias(ph_voltage_ratio_input, "sensor_type=", "setSensorType");

  /* Document-method: getSensorUnit
   * call-seq: getSensorUnit -> sensor_unit
   *
   * The unit of measurement that applies to the sensor values of the SensorType that has been selected.
   * Helps keep track of the type of information being calculated from the voltage ratio input.
   */
  rb_define_method(ph_voltage_ratio_input, "getSensorUnit", ph_voltage_ratio_input_get_sensor_unit, 0);
  rb_define_alias(ph_voltage_ratio_input, "sensor_unit", "getSensorUnit");

  /* Document-method: getSensorValue
   * call-seq: getSensorValue -> sensor_value
   *
   * The most recent sensor value that the channel has reported.
   * Use SensorUnit to get the measurement units that are associated with the SensorValue.
   */
  rb_define_method(ph_voltage_ratio_input, "getSensorValue", ph_voltage_ratio_input_get_sensor_value, 0);
  rb_define_alias(ph_voltage_ratio_input, "sensor_value", "getSensorValue");

  /* Document-method: getSensorValueChangeTrigger
   * call-seq: getSensorValueChangeTrigger -> trigger
   *
   * The channel will not issue a SensorChange event until the sensor value has changed by the amount specified by the SensorValueChangeTrigger.
   * Setting the SensorChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_ratio_input, "getSensorValueChangeTrigger", ph_voltage_ratio_input_get_sensor_value_change_trigger, 0);
  rb_define_alias(ph_voltage_ratio_input, "sensor_value_change_trigger", "getSensorValueChangeTrigger");

  /* Document-method: setSensorValueChangeTrigger
   * call-seq: setSensorValueChangeTrigger(trigger)
   *
   * The channel will not issue a SensorChange event until the sensor value has changed by the amount specified by the SensorValueChangeTrigger.
   * Setting the SensorChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_ratio_input, "setSensorValueChangeTrigger", ph_voltage_ratio_input_set_sensor_value_change_trigger, 1);
  rb_define_alias(ph_voltage_ratio_input, "sensor_value_change_trigger=", "setSensorValueChangeTrigger");

  /* Document-method: getVoltageRatio
   * call-seq: getVoltageRatio -> voltage_ratio
   *
   * The most recent voltage ratio value that the channel has reported.
   * This value will always be between MinVoltageRatio and MaxVoltageRatio.
   */
  rb_define_method(ph_voltage_ratio_input, "getVoltageRatio", ph_voltage_ratio_input_get_voltage_ratio, 0);
  rb_define_alias(ph_voltage_ratio_input, "voltage_ratio", "getVoltageRatio");

  /* Document-method: getMinVoltageRatio
   * call-seq: getMinVoltageRatio -> voltage_ratio
   *
   * The minimum value the VoltageRatioChange event will report.
   */
  rb_define_method(ph_voltage_ratio_input, "getMinVoltageRatio", ph_voltage_ratio_input_get_min_voltage_ratio, 0);
  rb_define_alias(ph_voltage_ratio_input, "min_voltage_ratio", "getMinVoltageRatio");

  /* Document-method: getMaxVoltageRatio
   * call-seq: getMaxVoltageRatio -> voltage_ratio
   *
   * The maximum value the VoltageRatioChange event will report.
   */
  rb_define_method(ph_voltage_ratio_input, "getMaxVoltageRatio", ph_voltage_ratio_input_get_max_voltage_ratio, 0);
  rb_define_alias(ph_voltage_ratio_input, "max_voltage_ratio", "getMaxVoltageRatio");

  /* Document-method: getVoltageRatioChangeTrigger
   * call-seq: getVoltageRatioChangeTrigger -> trigger
   *
   * The channel will not issue a VoltageRatioChange event until the voltage ratio value has changed by the amount specified by the VoltageRatioChangeTrigger.
   * Setting the VoltageRatioChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_ratio_input, "getVoltageRatioChangeTrigger", ph_voltage_ratio_input_get_voltage_ratio_change_trigger, 0);
  rb_define_alias(ph_voltage_ratio_input, "voltage_ratio_change_trigger", "getVoltageRatioChangeTrigger");

  /* Document-method: setVoltageRatioChangeTrigger
   * call-seq: setVoltageRatioChangeTrigger(trigger)
   *
   * The channel will not issue a VoltageRatioChange event until the voltage value has changed by the amount specified by the VoltageRatioChangeTrigger.
   * Setting the VoltageRatioChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_ratio_input, "setVoltageRatioChangeTrigger", ph_voltage_ratio_input_set_voltage_ratio_change_trigger, 1);
  rb_define_alias(ph_voltage_ratio_input, "voltage_ratio_change_trigger=", "setVoltageRatioChangeTrigger");

  /* Document-method: getMinVoltageRatioChangeTrigger
   * call-seq: getMinVoltageRatioChangeTrigger -> trigger
   *
   * The minimum value that VoltageRatioChangeTrigger can be set to.
   */
  rb_define_method(ph_voltage_ratio_input, "getMinVoltageRatioChangeTrigger", ph_voltage_ratio_input_get_min_voltage_ratio_change_trigger, 0);
  rb_define_alias(ph_voltage_ratio_input, "min_voltage_ratio_change_trigger", "getMinVoltageRatioChangeTrigger");

  /* Document-method: getMaxVoltageRatioChangeTrigger
   * call-seq: getMaxVoltageRatioChangeTrigger -> trigger
   *
   * The maximum value that VoltageRatioChangeTrigger can be set to.
   */
  rb_define_method(ph_voltage_ratio_input, "getMaxVoltageRatioChangeTrigger", ph_voltage_ratio_input_get_max_voltage_ratio_change_trigger, 0);
  rb_define_alias(ph_voltage_ratio_input, "max_voltage_ratio_change_trigger", "getMaxVoltageRatioChangeTrigger");


  rb_define_private_method(ph_voltage_ratio_input, "ext_setOnSensorChangeHandler", ph_voltage_ratio_input_set_on_sensor_change_handler, 1);
  rb_define_private_method(ph_voltage_ratio_input, "ext_setOnVoltageRatioChangeHandler", ph_voltage_ratio_input_set_on_voltage_ratio_change_handler, 1);
}

