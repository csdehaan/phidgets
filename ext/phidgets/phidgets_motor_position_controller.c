
#include "phidgets.h"

#define MOTOR_DUTY_CYCLE_UPDATE_CALLBACK      0
#define MOTOR_POSITION_UPDATE_CALLBACK        1
#define MOTOR_TARGET_POSITION_ASYNC_CALLBACK  2



VALUE ph_motor_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetMotorPositionController_create((PhidgetMotorPositionControllerHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_motor_get_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getAcceleration);
}

VALUE ph_motor_set_acceleration(VALUE self, VALUE accel) {
  ph_raise(PhidgetMotorPositionController_setAcceleration((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(accel)));
  return Qnil;
}

VALUE ph_motor_get_min_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMinAcceleration);
}

VALUE ph_motor_get_max_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMaxAcceleration);
}

VALUE ph_motor_get_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getCurrentLimit);
}

VALUE ph_motor_set_current_limit(VALUE self, VALUE current) {
  ph_raise(PhidgetMotorPositionController_setCurrentLimit((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(current)));
  return Qnil;
}

VALUE ph_motor_get_min_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMinCurrentLimit);
}

VALUE ph_motor_get_max_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMaxCurrentLimit);
}

VALUE ph_motor_get_current_regulator_gain(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getCurrentRegulatorGain);
}

VALUE ph_motor_set_current_regulator_gain(VALUE self, VALUE gain) {
  ph_raise(PhidgetMotorPositionController_setCurrentRegulatorGain((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(gain)));
  return Qnil;
}

VALUE ph_motor_get_min_current_regulator_gain(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMinCurrentRegulatorGain);
}

VALUE ph_motor_get_max_current_regulator_gain(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMaxCurrentRegulatorGain);
}

VALUE ph_motor_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetMotorPositionController_getDataInterval);
}

VALUE ph_motor_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetMotorPositionController_setDataInterval((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_motor_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetMotorPositionController_getMinDataInterval);
}

VALUE ph_motor_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetMotorPositionController_getMaxDataInterval);
}

VALUE ph_motor_get_dead_band(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getDeadBand);
}

VALUE ph_motor_set_dead_band(VALUE self, VALUE dead_band) {
  ph_raise(PhidgetMotorPositionController_setDeadBand((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(dead_band)));
  return Qnil;
}

VALUE ph_motor_get_duty_cycle(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getDutyCycle);
}

VALUE ph_motor_get_engaged(VALUE self) {
  return ph_get_bool(get_ph_handle(self), PhidgetMotorPositionController_getEngaged);
}

VALUE ph_motor_set_engaged(VALUE self, VALUE engaged) {
  ph_raise(PhidgetMotorPositionController_setEngaged((PhidgetMotorPositionControllerHandle)get_ph_handle(self), TYPE(engaged) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_motor_get_fan_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), PhidgetMotorPositionController_getFanMode);
}

VALUE ph_motor_set_fan_mode(VALUE self, VALUE fan_mode) {
  ph_raise(PhidgetMotorPositionController_setFanMode((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2INT(fan_mode)));
  return Qnil;
}

VALUE ph_motor_get_io_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), PhidgetMotorPositionController_getIOMode);
}

VALUE ph_motor_set_io_mode(VALUE self, VALUE io_mode) {
  ph_raise(PhidgetMotorPositionController_setIOMode((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2INT(io_mode)));
  return Qnil;
}

VALUE ph_motor_get_kd(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getKd);
}

VALUE ph_motor_set_kd(VALUE self, VALUE kd) {
  ph_raise(PhidgetMotorPositionController_setKd((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(kd)));
  return Qnil;
}

VALUE ph_motor_get_ki(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getKi);
}

VALUE ph_motor_set_ki(VALUE self, VALUE ki) {
  ph_raise(PhidgetMotorPositionController_setKi((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(ki)));
  return Qnil;
}

VALUE ph_motor_get_kp(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getKp);
}

VALUE ph_motor_set_kp(VALUE self, VALUE kp) {
  ph_raise(PhidgetMotorPositionController_setKp((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(kp)));
  return Qnil;
}

VALUE ph_motor_get_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getPosition);
}

VALUE ph_motor_get_min_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMinPosition);
}

VALUE ph_motor_get_max_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMaxPosition);
}

VALUE ph_motor_add_position_offset(VALUE self, VALUE offset) {
  ph_raise(PhidgetMotorPositionController_addPositionOffset((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(offset)));
  return Qnil;
}

VALUE ph_motor_get_rescale_factor(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getRescaleFactor);
}

VALUE ph_motor_set_rescale_factor(VALUE self, VALUE rescale_factor) {
  ph_raise(PhidgetMotorPositionController_setRescaleFactor((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(rescale_factor)));
  return Qnil;
}

VALUE ph_motor_get_stall_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getStallVelocity);
}

VALUE ph_motor_set_stall_velocity(VALUE self, VALUE stall_velocity) {
  ph_raise(PhidgetMotorPositionController_setStallVelocity((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(stall_velocity)));
  return Qnil;
}

VALUE ph_motor_get_min_stall_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMinStallVelocity);
}

VALUE ph_motor_get_max_stall_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMaxStallVelocity);
}

VALUE ph_motor_get_target_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getTargetPosition);
}

VALUE ph_motor_set_target_position(VALUE self, VALUE target_position) {
  ph_raise(PhidgetMotorPositionController_setTargetPosition((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(target_position)));
  return Qnil;
}

VALUE ph_motor_get_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getVelocityLimit);
}

VALUE ph_motor_set_velocity_limit(VALUE self, VALUE velocity) {
  ph_raise(PhidgetMotorPositionController_setVelocityLimit((PhidgetMotorPositionControllerHandle)get_ph_handle(self), NUM2DBL(velocity)));
  return Qnil;
}

VALUE ph_motor_get_min_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMinVelocityLimit);
}

VALUE ph_motor_get_max_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetMotorPositionController_getMaxVelocityLimit);
}


void CCONV ph_motor_on_duty_cycle_update(PhidgetMotorPositionControllerHandle phid, void *userPtr, double duty_cycle) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(duty_cycle);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_motor_set_on_duty_cycle_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[MOTOR_DUTY_CYCLE_UPDATE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetMotorPositionController_setOnDutyCycleUpdateHandler((PhidgetMotorPositionControllerHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetMotorPositionController_setOnDutyCycleUpdateHandler((PhidgetMotorPositionControllerHandle)ph->handle, ph_motor_on_duty_cycle_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_motor_on_position_change(PhidgetMotorPositionControllerHandle phid, void *userPtr, double position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(position);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_motor_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[MOTOR_POSITION_UPDATE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetMotorPositionController_setOnPositionChangeHandler((PhidgetMotorPositionControllerHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetMotorPositionController_setOnPositionChangeHandler((PhidgetMotorPositionControllerHandle)ph->handle, ph_motor_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_motor_target_position_async(PhidgetHandle phid, void *userPtr, PhidgetReturnCode res) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->exit = true;
  callback_data->arg1 = INT2NUM(res);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_motor_set_target_position_async(VALUE self, VALUE position, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[MOTOR_TARGET_POSITION_ASYNC_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    PhidgetMotorPositionController_setTargetPosition_async((PhidgetMotorPositionControllerHandle)ph->handle, NUM2DBL(position), NULL, (void *)NULL);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    PhidgetMotorPositionController_setTargetPosition_async((PhidgetMotorPositionControllerHandle)ph->handle, NUM2DBL(position), ph_motor_target_position_async, (void *)callback_data);
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_motor_position_controller() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_motor = rb_define_class_under(ph_module, "MotorPositionController", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget MotorPositionController object.
   */
  rb_define_method(ph_motor, "initialize", ph_motor_init, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration -> acceleration
   *
   * The rate at which the controller can change the motor's velocity.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getAcceleration", ph_motor_get_acceleration, 0);
  rb_define_alias(ph_motor, "acceleration", "getAcceleration");

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(acceleration)
   *
   * The rate at which the controller can change the motor's velocity.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "setAcceleration", ph_motor_set_acceleration, 1);
  rb_define_alias(ph_motor, "acceleration=", "setAcceleration");

  /* Document-method: getMinAcceleration
   * call-seq: getMinAcceleration -> min_acceleration
   *
   * The minimum value that Acceleration can be set to.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getMinAcceleration", ph_motor_get_min_acceleration, 0);
  rb_define_alias(ph_motor, "min_acceleration", "getMinAcceleration");

  /* Document-method: getMaxAcceleration
   * call-seq: getMaxAcceleration -> max_acceleration
   *
   * The maximum value that Acceleration can be set to.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getMaxAcceleration", ph_motor_get_max_acceleration, 0);
  rb_define_alias(ph_motor, "max_acceleration", "getMaxAcceleration");

  /* Document-method: getCurrentLimit
   * call-seq: getCurrentLimit -> current_limit
   *
   * The controller will limit the current through the motor to this value.
   */
  rb_define_method(ph_motor, "getCurrentLimit", ph_motor_get_current_limit, 0);
  rb_define_alias(ph_motor, "current_limit", "getCurrentLimit");

  /* Document-method: setCurrentLimit
   * call-seq: setCurrentLimit(current_limit)
   *
   * The controller will limit the current through the motor to this value.
   */
  rb_define_method(ph_motor, "setCurrentLimit", ph_motor_set_current_limit, 1);
  rb_define_alias(ph_motor, "current_limit=", "setCurrentLimit");

  /* Document-method: getMinCurrentLimit
   * call-seq: getMinCurrentLimit -> current_limit
   *
   * The minimum current limit that can be set for the device.
   */
  rb_define_method(ph_motor, "getMinCurrentLimit", ph_motor_get_min_current_limit, 0);
  rb_define_alias(ph_motor, "min_current_limit", "getMinCurrentLimit");

  /* Document-method: getMaxCurrentLimit
   * call-seq: getMaxCurrentLimit -> current_limit
   *
   * The maximum current limit that can be set for the device.
   */
  rb_define_method(ph_motor, "getMaxCurrentLimit", ph_motor_get_max_current_limit, 0);
  rb_define_alias(ph_motor, "max_current_limit", "getMaxCurrentLimit");

  /* Document-method: getCurrentRegulatorGain
   * call-seq: getCurrentRegulatorGain -> regulator_gain
   *
   * Depending on power supply voltage and motor coil inductance, current through the motor can change relatively slowly or extremely rapidly.
   * A physically larger DC Motor will typically have a lower inductance, requiring a higher current regulator gain.
   * A higher power supply voltage will result in motor current changing more rapidly, requiring a higher current regulator gain.
   * If the current regulator gain is too small, spikes in current will occur, causing large variations in torque, and possibly damaging the motor controller.
   * If the current regulator gain is too high, the current will jitter, causing the motor to sound 'rough', especially when changing directions.
   */
  rb_define_method(ph_motor, "getCurrentRegulatorGain", ph_motor_get_current_regulator_gain, 0);
  rb_define_alias(ph_motor, "current_regulator_gain", "getCurrentRegulatorGain");

  /* Document-method: setCurrentRegulatorGain
   * call-seq: setCurrentRegulatorGain(regulator_gain)
   *
   * Depending on power supply voltage and motor coil inductance, current through the motor can change relatively slowly or extremely rapidly.
   * A physically larger DC Motor will typically have a lower inductance, requiring a higher current regulator gain.
   * A higher power supply voltage will result in motor current changing more rapidly, requiring a higher current regulator gain.
   * If the current regulator gain is too small, spikes in current will occur, causing large variations in torque, and possibly damaging the motor controller.
   * If the current regulator gain is too high, the current will jitter, causing the motor to sound 'rough', especially when changing directions.
   */
  rb_define_method(ph_motor, "setCurrentRegulatorGain", ph_motor_set_current_regulator_gain, 1);
  rb_define_alias(ph_motor, "current_regulator_gain=", "setCurrentRegulatorGain");

  /* Document-method: getMinCurrentRegulatorGain
   * call-seq: getMinCurrentRegulatorGain -> regulator_gain
   *
   * The minimum current regulator gain for the device.
   */
  rb_define_method(ph_motor, "getMinCurrentRegulatorGain", ph_motor_get_min_current_regulator_gain, 0);
  rb_define_alias(ph_motor, "min_current_regulator_gain", "getMinCurrentRegulatorGain");

  /* Document-method: getMaxCurrentRegulatorGain
   * call-seq: getMaxCurrentRegulatorGain -> regulator_gain
   *
   * The maximum current regulator gain for the device.
   */
  rb_define_method(ph_motor, "getMaxCurrentRegulatorGain", ph_motor_get_max_current_regulator_gain, 0);
  rb_define_alias(ph_motor, "max_current_regulator_gain", "getMaxCurrentRegulatorGain");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the controller will fire another CurrentChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between CurrentChange events can also affected by the CurrentChangeTrigger.
   */
  rb_define_method(ph_motor, "getDataInterval", ph_motor_get_data_interval, 0);
  rb_define_alias(ph_motor, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the controller will fire another CurrentChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between CurrentChange events can also affected by the CurrentChangeTrigger.
   */
  rb_define_method(ph_motor, "setDataInterval", ph_motor_set_data_interval, 1);
  rb_define_alias(ph_motor, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_motor, "getMinDataInterval", ph_motor_get_min_data_interval, 0);
  rb_define_alias(ph_motor, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_motor, "getMaxDataInterval", ph_motor_get_max_data_interval, 0);
  rb_define_alias(ph_motor, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getDeadBand
   * call-seq: getDeadBand -> dead_band
   *
   * Depending on your system, it may not be possible to bring the position error (TargetPosition - Position) to zero.
   * A small error can lead to the motor continually 'hunting' for a target position, which can cause unwanted effects.
   * By setting a non-zero DeadBand, the position controller will relax control of the motor within the deadband, preventing the 'hunting' behavior.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getDeadBand", ph_motor_get_dead_band, 0);
  rb_define_alias(ph_motor, "dead_band", "getDeadBand");

  /* Document-method: setDeadBand
   * call-seq: setDeadBand(dead_band)
   *
   * Depending on your system, it may not be possible to bring the position error (TargetPosition - Position) to zero.
   * A small error can lead to the motor continually 'hunting' for a target position, which can cause unwanted effects.
   * By setting a non-zero DeadBand, the position controller will relax control of the motor within the deadband, preventing the 'hunting' behavior.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "setDeadBand", ph_motor_set_dead_band, 1);
  rb_define_alias(ph_motor, "dead_band=", "setDeadBand");

  /* Document-method: getDutyCycle
   * call-seq: getDutyCycle -> duty_cycle
   *
   * The most recent duty cycle value that the controller has reported.
   * This value will be between -1 and 1 where a sign change (±) is indicitave of a direction change.
   * Note that DutyCycle is merely an indication of the average voltage across the motor. At a constant load, an increase in DutyCycle indicates an increase in motor speed.
   * The units of DutyCycle refer to 'duty cycle'. This is because the controller must rapidly switch the power on/off (i.e. change the duty cycle) in order to manipulate the voltage across the motor.
   */
  rb_define_method(ph_motor, "getDutyCycle", ph_motor_get_duty_cycle, 0);
  rb_define_alias(ph_motor, "duty_cycle", "getDutyCycle");

  /* Document-method: getEngaged
   * call-seq: getEngaged -> engaged
   *
   * When engaged, a motor has the ability to be positioned. When disengaged, no commands are sent to the motor.
   * This function is useful for completely relaxing a motor once it has reached the target position.
   */
  rb_define_method(ph_motor, "getEngaged", ph_motor_get_engaged, 0);
  rb_define_alias(ph_motor, "engaged", "getEngaged");

  /* Document-method: setEngaged
   * call-seq: setEngaged(engaged)
   *
   * When engaged, a motor has the ability to be positioned. When disengaged, no commands are sent to the motor.
   * This function is useful for completely relaxing a motor once it has reached the target position.
   */
  rb_define_method(ph_motor, "setEngaged", ph_motor_set_engaged, 1);
  rb_define_alias(ph_motor, "engaged=", "setEngaged");

  /* Document-method: getFanMode
   * call-seq: getFanMode -> fan_mode
   *
   * The FanMode dictates the operating condition of the fan.
   * Choose between on, off, or automatic (based on temperature).
   * If the FanMode is set to automatic, the fan will turn on when the temperature reaches 70°C and it will remain on until the temperature falls below 55°C.
   * If the FanMode is off, the controller will still turn on the fan if the temperature reaches 85°C and it will remain on until it falls below 70°C.
   */
  rb_define_method(ph_motor, "getFanMode", ph_motor_get_fan_mode, 0);
  rb_define_alias(ph_motor, "fan_mode", "getFanMode");

  /* Document-method: setFanMode
   * call-seq: setFanMode(fan_mode)
   *
   * The FanMode dictates the operating condition of the fan.
   * Choose between on, off, or automatic (based on temperature).
   * If the FanMode is set to automatic, the fan will turn on when the temperature reaches 70°C and it will remain on until the temperature falls below 55°C.
   * If the FanMode is off, the controller will still turn on the fan if the temperature reaches 85°C and it will remain on until it falls below 70°C.
   */
  rb_define_method(ph_motor, "setFanMode", ph_motor_set_fan_mode, 1);
  rb_define_alias(ph_motor, "fan_mode=", "setFanMode");

  /* Document-method: getIOMode
   * call-seq: getIOMode -> io_mode
   *
   * The encoder interface mode. Match the mode to the type of encoder you have attached.
   * It is recommended to only change this when the encoder is disabled in order to avoid unexpected results.
   */
  rb_define_method(ph_motor, "getIOMode", ph_motor_get_io_mode, 0);
  rb_define_alias(ph_motor, "io_mode", "getIOMode");

  /* Document-method: setIOMode
   * call-seq: setIOMode(io_mode)
   *
   * The encoder interface mode. Match the mode to the type of encoder you have attached.
   * It is recommended to only change this when the encoder is disabled in order to avoid unexpected results.
   */
  rb_define_method(ph_motor, "setIOMode", ph_motor_set_io_mode, 1);
  rb_define_alias(ph_motor, "io_mode=", "setIOMode");

  /* Document-method: getKd
   * call-seq: getKd -> kd
   *
   * Derivative gain constant. A higher Kd will help reduce oscillations.
   */
  rb_define_method(ph_motor, "getKd", ph_motor_get_kd, 0);
  rb_define_alias(ph_motor, "kd", "getKd");

  /* Document-method: setKd
   * call-seq: setKd(kd)
   *
   * Derivative gain constant. A higher Kd will help reduce oscillations.
   */
  rb_define_method(ph_motor, "setKd", ph_motor_set_kd, 1);
  rb_define_alias(ph_motor, "kd=", "setKd");

  /* Document-method: getKi
   * call-seq: getKi -> ki
   *
   * Integral gain constant. The integral term will help eliminate steady-state error.
   */
  rb_define_method(ph_motor, "getKi", ph_motor_get_ki, 0);
  rb_define_alias(ph_motor, "ki", "getKi");

  /* Document-method: setKi
   * call-seq: setKi(ki)
   *
   * Integral gain constant. The integral term will help eliminate steady-state error.
   */
  rb_define_method(ph_motor, "setKi", ph_motor_set_ki, 1);
  rb_define_alias(ph_motor, "ki=", "setKi");

  /* Document-method: getKp
   * call-seq: getKp -> kp
   *
   * Proportional gain constant. A small Kp value will result in a less responsive controller, however, if Kp is too high, the system can become unstable.
   */
  rb_define_method(ph_motor, "getKp", ph_motor_get_kp, 0);
  rb_define_alias(ph_motor, "kp", "getKp");

  /* Document-method: setKp
   * call-seq: setKp(kp)
   *
   * Proportional gain constant. A small Kp value will result in a less responsive controller, however, if Kp is too high, the system can become unstable.
   */
  rb_define_method(ph_motor, "setKp", ph_motor_set_kp, 1);
  rb_define_alias(ph_motor, "kp=", "setKp");

  /* Document-method: getPosition
   * call-seq: getPosition -> position
   *
   * The most recent position value that the controller has reported.
   * This value will always be between MinPosition and MaxPosition.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getPosition", ph_motor_get_position, 0);
  rb_define_alias(ph_motor, "position", "getPosition");

  /* Document-method: getMinPosition
   * call-seq: getMinPosition -> min_position
   *
   * The minimum value that TargetPosition can be set to.
   */
  rb_define_method(ph_motor, "getMinPosition", ph_motor_get_min_position, 0);
  rb_define_alias(ph_motor, "min_position", "getMinPosition");

  /* Document-method: getMaxPosition
   * call-seq: getMaxPosition -> max_position
   *
   * The maximum value that TargetPosition can be set to.
   */
  rb_define_method(ph_motor, "getMaxPosition", ph_motor_get_max_position, 0);
  rb_define_alias(ph_motor, "max_position", "getMaxPosition");

  /* Document-method: addPositionOffset
   * call-seq: addPositionOffset(offset)
   *
   * Adds an offset (positive or negative) to the current position. Useful for zeroing position.
   */
  rb_define_method(ph_motor, "addPositionOffset", ph_motor_add_position_offset, 1);
  rb_define_alias(ph_motor, "add_position_offset", "addPositionOffset");

  /* Document-method: getRescaleFactor
   * call-seq: getRescaleFactor -> rescale_factor
   *
   * Change the units of your parameters so that your application is more intuitive.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getRescaleFactor", ph_motor_get_rescale_factor, 0);
  rb_define_alias(ph_motor, "rescale_factor", "getRescaleFactor");

  /* Document-method: setRescaleFactor
   * call-seq: setRescaleFactor(rescale_factor)
   *
   * Change the units of your parameters so that your application is more intuitive.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "setRescaleFactor", ph_motor_set_rescale_factor, 1);
  rb_define_alias(ph_motor, "rescale_factor=", "setRescaleFactor");

  /* Document-method: getStallVelocity
   * call-seq: getStallVelocity -> stall_velocity
   *
   * Before reading this description, it is important to note the difference between the units of StallVelocity and Velocity.
   * Velocity is a number between -1 and 1 with units of 'duty cycle'. It simply represents the average voltage across the motor.
   * StallVelocity represents a real velocity (e.g. m/s, RPM, etc.) and the units are determined by the RescaleFactor.
   * With a RescaleFactor of 1, the default units would be in commutations per second.
   * If the load on your motor is large, your motor may begin rotating more slowly, or even fully stall.
   * Depending on the voltage across your motor, this may result in a large amount of current through both the controller and the motor.
   * In order to prevent damage in these situations, you can use the StallVelocity property.
   *
   * The StallVelocity should be set to the lowest velocity you would expect from your motor.
   * The controller will then monitor the motor's velocity, as well as the Velocity, and prevent a 'dangerous stall' from occuring.
   * If the controller detects a dangerous stall, it will immediately disengage the motor (i.e. Engaged will be set to false) and an error will be reported to your program.
   * A 'dangerous stall' will occur faster when the Velocity is higher (i.e. when the average voltage across the motor is higher)
   * A 'dangerous stall' will occur faster as (StallVelocity - motor velocity) becomes larger .
   * Setting StallVelocity to 0 will turn off stall protection functionality.
   */
  rb_define_method(ph_motor, "getStallVelocity", ph_motor_get_stall_velocity, 0);
  rb_define_alias(ph_motor, "stall_velocity", "getStallVelocity");

  /* Document-method: setStallVelocity
   * call-seq: setStallVelocity(stall_velocity)
   *
   * Before reading this description, it is important to note the difference between the units of StallVelocity and Velocity.
   * Velocity is a number between -1 and 1 with units of 'duty cycle'. It simply represents the average voltage across the motor.
   * StallVelocity represents a real velocity (e.g. m/s, RPM, etc.) and the units are determined by the RescaleFactor.
   * With a RescaleFactor of 1, the default units would be in commutations per second.
   * If the load on your motor is large, your motor may begin rotating more slowly, or even fully stall.
   * Depending on the voltage across your motor, this may result in a large amount of current through both the controller and the motor.
   * In order to prevent damage in these situations, you can use the StallVelocity property.
   *
   * The StallVelocity should be set to the lowest velocity you would expect from your motor.
   * The controller will then monitor the motor's velocity, as well as the Velocity, and prevent a 'dangerous stall' from occuring.
   * If the controller detects a dangerous stall, it will immediately disengage the motor (i.e. Engaged will be set to false) and an error will be reported to your program.
   * A 'dangerous stall' will occur faster when the Velocity is higher (i.e. when the average voltage across the motor is higher)
   * A 'dangerous stall' will occur faster as (StallVelocity - motor velocity) becomes larger .
   * Setting StallVelocity to 0 will turn off stall protection functionality.
   */
  rb_define_method(ph_motor, "setStallVelocity", ph_motor_set_stall_velocity, 1);
  rb_define_alias(ph_motor, "stall_velocity=", "setStallVelocity");

  /* Document-method: getMinStallVelocity
   * call-seq: getMinStallVelocity -> stall_velocity
   *
   * The lower bound of StallVelocity.
   */
  rb_define_method(ph_motor, "getMinStallVelocity", ph_motor_get_min_stall_velocity, 0);
  rb_define_alias(ph_motor, "min_stall_velocity", "getMinStallVelocity");

  /* Document-method: getMaxStallVelocity
   * call-seq: getMaxStallVelocity -> stall_velocity
   *
   * The upper bound of StallVelocity.
   */
  rb_define_method(ph_motor, "getMaxStallVelocity", ph_motor_get_max_stall_velocity, 0);
  rb_define_alias(ph_motor, "max_stall_velocity", "getMaxStallVelocity");

  /* Document-method: getTargetPosition
   * call-seq: getTargetPosition -> target_position
   *
   * If the controller is configured and the TargetPosition is set, the motor will try to reach the TargetPosition.
   * If the DeadBand is non-zero, the final position of the motor may not match the TargetPosition
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getTargetPosition", ph_motor_get_target_position, 0);
  rb_define_alias(ph_motor, "target_position", "getTargetPosition");

  /* Document-method: setTargetPosition
   * call-seq: setTargetPosition(target_position)
   *
   * If the controller is configured and the TargetPosition is set, the motor will try to reach the TargetPosition.
   * If the DeadBand is non-zero, the final position of the motor may not match the TargetPosition
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "setTargetPosition", ph_motor_set_target_position, 1);
  rb_define_alias(ph_motor, "target_position=", "setTargetPosition");

  /* Document-method: getVelocityLimit
   * call-seq: getVelocityLimit -> velocity_limit
   *
   * When moving, the motor velocity will be limited by this value.
   * VelocityLimit is bounded by MinVelocityLimit and MaxVelocityLimit.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "getVelocityLimit", ph_motor_get_velocity_limit, 0);
  rb_define_alias(ph_motor, "velocity_limit", "getVelocityLimit");

  /* Document-method: setVelocityLimit
   * call-seq: setVelocityLimit(velocity_limit)
   *
   * When moving, the motor velocity will be limited by this value.
   * VelocityLimit is bounded by MinVelocityLimit and MaxVelocityLimit.
   * Units for Position, VelocityLimit, Acceleration, and DeadBand can be set by the user through the RescaleFactor.
   * The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_motor, "setVelocityLimit", ph_motor_set_velocity_limit, 1);
  rb_define_alias(ph_motor, "velocity_limit=", "setVelocityLimit");

  /* Document-method: getMinVelocityLimit
   * call-seq: getMinVelocityLimit -> velocity_limit
   *
   * The minimum value that VelocityLimit can be set to.
   */
  rb_define_method(ph_motor, "getMinVelocityLimit", ph_motor_get_min_velocity_limit, 0);
  rb_define_alias(ph_motor, "min_velocity_limit", "getMinVelocityLimit");

  /* Document-method: getMaxVelocityLimit
   * call-seq: getMaxVelocityLimit -> velocity_limit
   *
   * The maximum value that VelocityLimit can be set to.
   */
  rb_define_method(ph_motor, "getMaxVelocityLimit", ph_motor_get_max_velocity_limit, 0);
  rb_define_alias(ph_motor, "max_velocity_limit", "getMaxVelocityLimit");


  rb_define_private_method(ph_motor, "ext_setOnDutyCycleUpdateHandler", ph_motor_set_on_duty_cycle_update_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnPositionChangeHandler", ph_motor_set_on_position_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setTargetPosition_async", ph_motor_set_target_position_async, 2);
}

