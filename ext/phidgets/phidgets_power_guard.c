
#include "phidgets.h"



VALUE ph_power_guard_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetPowerGuard_create((PhidgetPowerGuardHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_power_guard_get_fan_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetPowerGuard_getFanMode);
}

VALUE ph_power_guard_set_fan_mode(VALUE self, VALUE mode) {
  ph_raise(PhidgetPowerGuard_setFanMode((PhidgetPowerGuardHandle)get_ph_handle(self), NUM2INT(mode)));
  return Qnil;
}

VALUE ph_power_guard_get_over_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPowerGuard_getOverVoltage);
}

VALUE ph_power_guard_set_over_voltage(VALUE self, VALUE over_voltage) {
  ph_raise(PhidgetPowerGuard_setOverVoltage((PhidgetPowerGuardHandle)get_ph_handle(self), NUM2DBL(over_voltage)));
  return Qnil;
}

VALUE ph_power_guard_get_min_over_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPowerGuard_getMinOverVoltage);
}

VALUE ph_power_guard_get_max_over_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetPowerGuard_getMaxOverVoltage);
}

VALUE ph_power_guard_get_power_enabled(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetPowerGuard_getPowerEnabled);
}

VALUE ph_power_guard_set_power_enabled(VALUE self, VALUE enabled) {
  ph_raise(PhidgetPowerGuard_setPowerEnabled((PhidgetPowerGuardHandle)get_ph_handle(self), TYPE(enabled) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}


void Init_power_guard() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_power_guard = rb_define_class_under(ph_module, "PowerGuard", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget PowerGuard object.
   */
  rb_define_method(ph_power_guard, "initialize", ph_power_guard_init, 0);

  /* Document-method: getFanMode
   * call-seq: getFanMode -> fan_mode
   *
   * The FanMode dictates the operating condition of the fan.
   * Choose between on, off, or automatic (based on temperature).
   * If the FanMode is set to automatic, the fan will turn on when the temperature reaches 70°C and it will remain on until the temperature falls below 55°C.
   * If the FanMode is off, the device will still turn on the fan if the temperature reaches 85°C and it will remain on until it falls below 70°C.
   */
  rb_define_method(ph_power_guard, "getFanMode", ph_power_guard_get_fan_mode, 0);
  rb_define_alias(ph_power_guard, "fan_mode", "getFanMode");

  /* Document-method: setFanMode
   * call-seq: setFanMode(fan_mode)
   *
   * The FanMode dictates the operating condition of the fan.
   * Choose between on, off, or automatic (based on temperature).
   * If the FanMode is set to automatic, the fan will turn on when the temperature reaches 70°C and it will remain on until the temperature falls below 55°C.
   * If the FanMode is off, the device will still turn on the fan if the temperature reaches 85°C and it will remain on until it falls below 70°C.
   */
  rb_define_method(ph_power_guard, "setFanMode", ph_power_guard_set_fan_mode, 1);
  rb_define_alias(ph_power_guard, "fan_mode=", "setFanMode");

  /* Document-method: getOverVoltage
   * call-seq: getOverVoltage -> over_voltage
   *
   * The device constantly monitors the output voltage, and if it exceeds the OverVoltage value, it will disconnect the input from the output.
   * This functionality is critical for protecting power supplies from regenerated voltage coming from motors. Many power supplies assume that
   * a higher than output expected voltage is related to an internal failure to the power supply, and will permanently disable themselves to protect
   * the system. A typical safe value is to set OverVoltage to 1-2 volts higher than the output voltage of the supply. For instance, a 12V supply
   * would be protected by setting OverVoltage to 13V.
   * The device will connect the input to the output again when the voltage drops to (OverVoltage - 1V).
   */
  rb_define_method(ph_power_guard, "getOverVoltage", ph_power_guard_get_over_voltage, 0);
  rb_define_alias(ph_power_guard, "over_voltage", "getOverVoltage");

  /* Document-method: setOverVoltage
   * call-seq: setOverVoltage(over_voltage)
   *
   * The device constantly monitors the output voltage, and if it exceeds the OverVoltage value, it will disconnect the input from the output.
   * This functionality is critical for protecting power supplies from regenerated voltage coming from motors. Many power supplies assume that
   * a higher than output expected voltage is related to an internal failure to the power supply, and will permanently disable themselves to protect
   * the system. A typical safe value is to set OverVoltage to 1-2 volts higher than the output voltage of the supply. For instance, a 12V supply
   * would be protected by setting OverVoltage to 13V.
   * The device will connect the input to the output again when the voltage drops to (OverVoltage - 1V).
   */
  rb_define_method(ph_power_guard, "setOverVoltage", ph_power_guard_set_over_voltage, 1);
  rb_define_alias(ph_power_guard, "over_voltage=", "setOverVoltage");

  /* Document-method: getMinOverVoltage
   * call-seq: getMinOverVoltage -> over_voltage
   *
   * The minimum value that OverVoltage can be set to.
   */
  rb_define_method(ph_power_guard, "getMinOverVoltage", ph_power_guard_get_min_over_voltage, 0);
  rb_define_alias(ph_power_guard, "min_over_voltage", "getMinOverVoltage");

  /* Document-method: getMaxOverVoltage
   * call-seq: getMaxOverVoltage -> over_voltage
   *
   * The maximum value that OverVoltage can be set to.
   */
  rb_define_method(ph_power_guard, "getMaxOverVoltage", ph_power_guard_get_max_over_voltage, 0);
  rb_define_alias(ph_power_guard, "max_over_voltage", "getMaxOverVoltage");

  /* Document-method: getPowerEnabled
   * call-seq: getPowerEnabled -> true or false
   *
   * When PowerEnabled is true, the device will connect the input to the output and begin monitoring.
   * The output voltage is constantly monitored and will be automatically disconnected from the input when the output exceeds the OverVoltage value.
   * PowerEnabled allows the device to operate as a Solid State Relay, powering on or off all devices connected to the output.
   */
  rb_define_method(ph_power_guard, "getPowerEnabled", ph_power_guard_get_power_enabled, 0);
  rb_define_alias(ph_power_guard, "power_enabled", "getPowerEnabled");

  /* Document-method: setPowerEnabled
   * call-seq: setPowerEnabled(power_enabled)
   *
   * When PowerEnabled is true, the device will connect the input to the output and begin monitoring.
   * The output voltage is constantly monitored and will be automatically disconnected from the input when the output exceeds the OverVoltage value.
   * PowerEnabled allows the device to operate as a Solid State Relay, powering on or off all devices connected to the output.
   */
  rb_define_method(ph_power_guard, "setPowerEnabled", ph_power_guard_set_power_enabled, 1);
  rb_define_alias(ph_power_guard, "power_enabled=", "setPowerEnabled");
}

