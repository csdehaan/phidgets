
#include "phidgets.h"

#define VOLTAGE_INPUT_SENSOR_CHANGE_CALLBACK  0
#define VOLTAGE_INPUT_VOLTAGE_CHANGE_CALLBACK 1


VALUE ph_voltage_input_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetVoltageInput_create((PhidgetVoltageInputHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_voltage_input_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetVoltageInput_getDataInterval);
}

VALUE ph_voltage_input_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetVoltageInput_setDataInterval((PhidgetVoltageInputHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_voltage_input_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetVoltageInput_getMinDataInterval);
}

VALUE ph_voltage_input_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetVoltageInput_getMaxDataInterval);
}

VALUE ph_voltage_input_get_power_supply(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetVoltageInput_getPowerSupply);
}

VALUE ph_voltage_input_set_power_supply(VALUE self, VALUE power_supply) {
  ph_raise(PhidgetVoltageInput_setPowerSupply((PhidgetVoltageInputHandle)get_ph_handle(self), NUM2INT(power_supply)));
  return Qnil;
}

VALUE ph_voltage_input_get_sensor_type(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetVoltageInput_getSensorType);
}

VALUE ph_voltage_input_set_sensor_type(VALUE self, VALUE sensor_type) {
  ph_raise(PhidgetVoltageInput_setSensorType((PhidgetVoltageInputHandle)get_ph_handle(self), NUM2INT(sensor_type)));
  return Qnil;
}

VALUE ph_voltage_input_get_sensor_unit(VALUE self) {
  VALUE unit_info = rb_hash_new();
  Phidget_UnitInfo sensorUnit;
  ph_raise(PhidgetVoltageInput_getSensorUnit((PhidgetVoltageInputHandle)get_ph_handle(self), &sensorUnit));
  rb_hash_aset(unit_info, rb_str_new2("unit"), INT2NUM(sensorUnit.unit));
  rb_hash_aset(unit_info, rb_str_new2("name"), rb_str_new2(sensorUnit.name));
  rb_hash_aset(unit_info, rb_str_new2("symbol"), rb_str_new2(sensorUnit.symbol));
  return unit_info;
}

VALUE ph_voltage_input_get_sensor_value(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getSensorValue);
}

VALUE ph_voltage_input_get_sensor_value_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getSensorValueChangeTrigger);
}

VALUE ph_voltage_input_set_sensor_value_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetVoltageInput_setSensorValueChangeTrigger((PhidgetVoltageInputHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_voltage_input_get_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getVoltage);
}

VALUE ph_voltage_input_get_min_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getMinVoltage);
}

VALUE ph_voltage_input_get_max_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getMaxVoltage);
}

VALUE ph_voltage_input_get_voltage_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getVoltageChangeTrigger);
}

VALUE ph_voltage_input_set_voltage_change_trigger(VALUE self, VALUE trigger) {
  ph_raise(PhidgetVoltageInput_setVoltageChangeTrigger((PhidgetVoltageInputHandle)get_ph_handle(self), NUM2DBL(trigger)));
  return Qnil;
}

VALUE ph_voltage_input_get_min_voltage_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getMinVoltageChangeTrigger);
}

VALUE ph_voltage_input_get_max_voltage_change_trigger(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetVoltageInput_getMaxVoltageChangeTrigger);
}

VALUE ph_voltage_input_get_voltage_range(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetVoltageInput_getVoltageRange);
}

VALUE ph_voltage_input_set_voltage_range(VALUE self, VALUE voltage_range) {
  ph_raise(PhidgetVoltageInput_setVoltageRange((PhidgetVoltageInputHandle)get_ph_handle(self), NUM2INT(voltage_range)));
  return Qnil;
}


void CCONV ph_voltage_input_on_sensor_change(PhidgetVoltageInputHandle phid, void *userPtr, double sensor_value, Phidget_UnitInfo *sensor_unit) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(sensor_value);
  callback_data->arg2 = INT2NUM(sensor_unit->unit);
  callback_data->arg3 = rb_str_new2(sensor_unit->name);
  callback_data->arg4 = rb_str_new2(sensor_unit->symbol);
  sem_post(&callback_data->sem);
}

VALUE ph_voltage_input_set_on_sensor_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[VOLTAGE_INPUT_SENSOR_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetVoltageInput_setOnSensorChangeHandler((PhidgetVoltageInputHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetVoltageInput_setOnSensorChangeHandler((PhidgetVoltageInputHandle)ph->handle, ph_voltage_input_on_sensor_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_voltage_input_on_voltage_change(PhidgetVoltageInputHandle phid, void *userPtr, double voltage) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(voltage);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}

VALUE ph_voltage_input_set_on_voltage_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[VOLTAGE_INPUT_VOLTAGE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetVoltageInput_setOnVoltageChangeHandler((PhidgetVoltageInputHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetVoltageInput_setOnVoltageChangeHandler((PhidgetVoltageInputHandle)ph->handle, ph_voltage_input_on_voltage_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_voltage_input() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_voltage_input = rb_define_class_under(ph_module, "VoltageInput", ph_common);


  rb_define_const(ph_voltage_input, "SENSOR_TYPE_VOLTAGE", INT2NUM(SENSOR_TYPE_VOLTAGE));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1114", INT2NUM(SENSOR_TYPE_1114));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1117", INT2NUM(SENSOR_TYPE_1117));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1123", INT2NUM(SENSOR_TYPE_1123));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1127", INT2NUM(SENSOR_TYPE_1127));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1130_PH", INT2NUM(SENSOR_TYPE_1130_PH));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1130_ORP", INT2NUM(SENSOR_TYPE_1130_ORP));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1132", INT2NUM(SENSOR_TYPE_1132));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1133", INT2NUM(SENSOR_TYPE_1133));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1135", INT2NUM(SENSOR_TYPE_1135));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1142", INT2NUM(SENSOR_TYPE_1142));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_1143", INT2NUM(SENSOR_TYPE_1143));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3500", INT2NUM(SENSOR_TYPE_3500));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3501", INT2NUM(SENSOR_TYPE_3501));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3502", INT2NUM(SENSOR_TYPE_3502));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3503", INT2NUM(SENSOR_TYPE_3503));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3507", INT2NUM(SENSOR_TYPE_3507));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3508", INT2NUM(SENSOR_TYPE_3508));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3509", INT2NUM(SENSOR_TYPE_3509));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3510", INT2NUM(SENSOR_TYPE_3510));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3511", INT2NUM(SENSOR_TYPE_3511));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3512", INT2NUM(SENSOR_TYPE_3512));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3513", INT2NUM(SENSOR_TYPE_3513));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3514", INT2NUM(SENSOR_TYPE_3514));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3515", INT2NUM(SENSOR_TYPE_3515));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3516", INT2NUM(SENSOR_TYPE_3516));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3517", INT2NUM(SENSOR_TYPE_3517));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3518", INT2NUM(SENSOR_TYPE_3518));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3519", INT2NUM(SENSOR_TYPE_3519));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3584", INT2NUM(SENSOR_TYPE_3584));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3585", INT2NUM(SENSOR_TYPE_3585));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3586", INT2NUM(SENSOR_TYPE_3586));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3587", INT2NUM(SENSOR_TYPE_3587));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3588", INT2NUM(SENSOR_TYPE_3588));
  rb_define_const(ph_voltage_input, "SENSOR_TYPE_3589", INT2NUM(SENSOR_TYPE_3589));

  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_10mV", INT2NUM(VOLTAGE_RANGE_10mV));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_40mV", INT2NUM(VOLTAGE_RANGE_40mV));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_200mV", INT2NUM(VOLTAGE_RANGE_200mV));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_312_5mV", INT2NUM(VOLTAGE_RANGE_312_5mV));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_400mV", INT2NUM(VOLTAGE_RANGE_400mV));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_1000mV", INT2NUM(VOLTAGE_RANGE_1000mV));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_2V", INT2NUM(VOLTAGE_RANGE_2V));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_5V", INT2NUM(VOLTAGE_RANGE_5V));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_15V", INT2NUM(VOLTAGE_RANGE_15V));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_40V", INT2NUM(VOLTAGE_RANGE_40V));
  rb_define_const(ph_voltage_input, "VOLTAGE_RANGE_AUTO", INT2NUM(VOLTAGE_RANGE_AUTO));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget VoltageInput object.
   */
  rb_define_method(ph_voltage_input, "initialize", ph_voltage_input_init, 0);

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the channel will fire another event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between events can also affected by the change trigger values.
   */
  rb_define_method(ph_voltage_input, "getDataInterval", ph_voltage_input_get_data_interval, 0);
  rb_define_alias(ph_voltage_input, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the channel will fire another event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between events can also affected by the change trigger values.
   */
  rb_define_method(ph_voltage_input, "setDataInterval", ph_voltage_input_set_data_interval, 1);
  rb_define_alias(ph_voltage_input, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_voltage_input, "getMinDataInterval", ph_voltage_input_get_min_data_interval, 0);
  rb_define_alias(ph_voltage_input, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_voltage_input, "getMaxDataInterval", ph_voltage_input_get_max_data_interval, 0);
  rb_define_alias(ph_voltage_input, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getPowerSupply
   * call-seq: getPowerSupply -> power_supply
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_voltage_input, "getPowerSupply", ph_voltage_input_get_power_supply, 0);
  rb_define_alias(ph_voltage_input, "power_supply", "getPowerSupply");

  /* Document-method: setPowerSupply
   * call-seq: setPowerSupply(power_supply)
   *
   * Choose the power supply voltage.
   * Set this to the voltage specified in the attached sensor's data sheet to power it.
   * Set to POWER_SUPPLY_OFF to turn off the supply to save power.
   */
  rb_define_method(ph_voltage_input, "setPowerSupply", ph_voltage_input_set_power_supply, 1);
  rb_define_alias(ph_voltage_input, "power_supply=", "setPowerSupply");

  /* Document-method: getSensorType
   * call-seq: getSensorType -> sensor_type
   *
   * By matching the SensorType to your analog sensor, the correct formula will automatically be applied to data when you get the SensorValue or subscribe to the SensorChange event.
   * The SensorChange event has its own change trigger associated with it: SensorValueChangeTrigger.
   * Any data from getting the SensorValue or subscribing to the SensorChange event will have a SensorUnit associated with it.
   * Note: Unlike other properties such as DeviceSerialNumber or Channel, SensorType is set after the device is opened, not before.
   */
  rb_define_method(ph_voltage_input, "getSensorType", ph_voltage_input_get_sensor_type, 0);
  rb_define_alias(ph_voltage_input, "sensor_type", "getSensorType");

  /* Document-method: setSensorType
   * call-seq: setSensorType(sensor_type)
   *
   * By matching the SensorType to your analog sensor, the correct formula will automatically be applied to data when you get the SensorValue or subscribe to the SensorChange event.
   * The SensorChange event has its own change trigger associated with it: SensorValueChangeTrigger.
   * Any data from getting the SensorValue or subscribing to the SensorChange event will have a SensorUnit associated with it.
   * Note: Unlike other properties such as DeviceSerialNumber or Channel, SensorType is set after the device is opened, not before.
   */
  rb_define_method(ph_voltage_input, "setSensorType", ph_voltage_input_set_sensor_type, 1);
  rb_define_alias(ph_voltage_input, "sensor_type=", "setSensorType");

  /* Document-method: getSensorUnit
   * call-seq: getSensorUnit -> sensor_unit
   *
   * The unit of measurement that applies to the sensor values of the SensorType that has been selected.
   * Helps keep track of the type of information being calculated from the voltage input.
   */
  rb_define_method(ph_voltage_input, "getSensorUnit", ph_voltage_input_get_sensor_unit, 0);
  rb_define_alias(ph_voltage_input, "sensor_unit", "getSensorUnit");

  /* Document-method: getSensorValue
   * call-seq: getSensorValue -> sensor_value
   *
   * The most recent sensor value that the channel has reported.
   * Use SensorUnit to get the measurement units that are associated with the SensorValue.
   */
  rb_define_method(ph_voltage_input, "getSensorValue", ph_voltage_input_get_sensor_value, 0);
  rb_define_alias(ph_voltage_input, "sensor_value", "getSensorValue");

  /* Document-method: getSensorValueChangeTrigger
   * call-seq: getSensorValueChangeTrigger -> trigger
   *
   * The channel will not issue a SensorChange event until the sensor value has changed by the amount specified by the SensorValueChangeTrigger.
   * Setting the SensorChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_input, "getSensorValueChangeTrigger", ph_voltage_input_get_sensor_value_change_trigger, 0);
  rb_define_alias(ph_voltage_input, "sensor_value_change_trigger", "getSensorValueChangeTrigger");

  /* Document-method: setSensorValueChangeTrigger
   * call-seq: setSensorValueChangeTrigger(trigger)
   *
   * The channel will not issue a SensorChange event until the sensor value has changed by the amount specified by the SensorValueChangeTrigger.
   * Setting the SensorChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_input, "setSensorValueChangeTrigger", ph_voltage_input_set_sensor_value_change_trigger, 1);
  rb_define_alias(ph_voltage_input, "sensor_value_change_trigger=", "setSensorValueChangeTrigger");

  /* Document-method: getVoltage
   * call-seq: getVoltage -> voltage
   *
   * The most recent voltage value that the channel has reported.
   * This value will always be between MinVoltage and MaxVoltage.
   */
  rb_define_method(ph_voltage_input, "getVoltage", ph_voltage_input_get_voltage, 0);
  rb_define_alias(ph_voltage_input, "voltage", "getVoltage");

  /* Document-method: getMinVoltage
   * call-seq: getMinVoltage -> voltage
   *
   * The minimum value the VoltageChange event will report.
   */
  rb_define_method(ph_voltage_input, "getMinVoltage", ph_voltage_input_get_min_voltage, 0);
  rb_define_alias(ph_voltage_input, "min_voltage", "getMinVoltage");

  /* Document-method: getMaxVoltage
   * call-seq: getMaxVoltage -> voltage
   *
   * The maximum value the VoltageChange event will report.
   */
  rb_define_method(ph_voltage_input, "getMaxVoltage", ph_voltage_input_get_max_voltage, 0);
  rb_define_alias(ph_voltage_input, "max_voltage", "getMaxVoltage");

  /* Document-method: getVoltageChangeTrigger
   * call-seq: getVoltageChangeTrigger -> trigger
   *
   * The channel will not issue a VoltageChange event until the voltage value has changed by the amount specified by the VoltageChangeTrigger.
   * Setting the VoltageChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_input, "getVoltageChangeTrigger", ph_voltage_input_get_voltage_change_trigger, 0);
  rb_define_alias(ph_voltage_input, "voltage_change_trigger", "getVoltageChangeTrigger");

  /* Document-method: setVoltageChangeTrigger
   * call-seq: setVoltageChangeTrigger(trigger)
   *
   * The channel will not issue a VoltageChange event until the voltage value has changed by the amount specified by the VoltageChangeTrigger.
   * Setting the VoltageChangeTrigger to 0 will result in the channel firing events every DataInterval. This is useful for applications that implement their own data filtering.
   */
  rb_define_method(ph_voltage_input, "setVoltageChangeTrigger", ph_voltage_input_set_voltage_change_trigger, 1);
  rb_define_alias(ph_voltage_input, "voltage_change_trigger=", "setVoltageChangeTrigger");

  /* Document-method: getMinVoltageChangeTrigger
   * call-seq: getMinVoltageChangeTrigger -> trigger
   *
   * The minimum value that VoltageChangeTrigger can be set to.
   */
  rb_define_method(ph_voltage_input, "getMinVoltageChangeTrigger", ph_voltage_input_get_min_voltage_change_trigger, 0);
  rb_define_alias(ph_voltage_input, "min_voltage_change_trigger", "getMinVoltageChangeTrigger");

  /* Document-method: getMaxVoltageChangeTrigger
   * call-seq: getMaxVoltageChangeTrigger -> trigger
   *
   * The maximum value that VoltageChangeTrigger can be set to.
   */
  rb_define_method(ph_voltage_input, "getMaxVoltageChangeTrigger", ph_voltage_input_get_max_voltage_change_trigger, 0);
  rb_define_alias(ph_voltage_input, "max_voltage_change_trigger", "getMaxVoltageChangeTrigger");

  /* Document-method: getVoltageRange
   * call-seq: getVoltageRange -> trigger
   *
   * The voltage range you choose should allow you to measure the full range of your input signal.
   * A larger VoltageRange equates to less resolution.
   * If a Saturation event occurs, increase the voltage range.
   */
  rb_define_method(ph_voltage_input, "getVoltageRange", ph_voltage_input_get_voltage_range, 0);
  rb_define_alias(ph_voltage_input, "voltage_range", "getVoltageRange");

  /* Document-method: setVoltageRange
   * call-seq: setVoltageRange(voltage_range)
   *
   * The voltage range you choose should allow you to measure the full range of your input signal.
   * A larger VoltageRange equates to less resolution.
   * If a Saturation event occurs, increase the voltage range.
   */
  rb_define_method(ph_voltage_input, "setVoltageRange", ph_voltage_input_set_voltage_range, 1);
  rb_define_alias(ph_voltage_input, "voltage_range=", "setVoltageRange");


  rb_define_private_method(ph_voltage_input, "ext_setOnSensorChangeHandler", ph_voltage_input_set_on_sensor_change_handler, 1);
  rb_define_private_method(ph_voltage_input, "ext_setOnVoltageChangeHandler", ph_voltage_input_set_on_voltage_change_handler, 1);
}

