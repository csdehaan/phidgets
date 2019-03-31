
#include "phidgets.h"

#define DC_MOTOR_BACK_EMF_CHANGE_CALLBACK          0
#define DC_MOTOR_BRAKING_STRENGTH_CHANGE_CALLBACK  1
#define DC_MOTOR_VELOCITY_UPDATE_CALLBACK          2


VALUE ph_dc_motor_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetDCMotor_create((PhidgetDCMotorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_dc_motor_get_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getAcceleration);
}

VALUE ph_dc_motor_set_acceleration(VALUE self, VALUE accel) {
  ph_raise(PhidgetDCMotor_setAcceleration((PhidgetDCMotorHandle)get_ph_handle(self), NUM2DBL(accel)));
  return Qnil;
}

VALUE ph_dc_motor_get_min_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMinAcceleration);
}

VALUE ph_dc_motor_get_max_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMaxAcceleration);
}

VALUE ph_dc_motor_get_back_emf(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getBackEMF);
}

VALUE ph_dc_motor_get_back_emf_sensing_state(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetDCMotor_getBackEMFSensingState);
}

VALUE ph_dc_motor_set_back_emf_sensing_state(VALUE self, VALUE sensing_state) {
  ph_raise(PhidgetDCMotor_setBackEMFSensingState((PhidgetDCMotorHandle)get_ph_handle(self), TYPE(sensing_state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_dc_motor_get_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getBrakingStrength);
}

VALUE ph_dc_motor_get_min_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMinBrakingStrength);
}

VALUE ph_dc_motor_get_max_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMaxBrakingStrength);
}

VALUE ph_dc_motor_get_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getCurrentLimit);
}

VALUE ph_dc_motor_set_current_limit(VALUE self, VALUE current_limit) {
  ph_raise(PhidgetDCMotor_setCurrentLimit((PhidgetDCMotorHandle)get_ph_handle(self), NUM2DBL(current_limit)));
  return Qnil;
}

VALUE ph_dc_motor_get_min_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMinCurrentLimit);
}

VALUE ph_dc_motor_get_max_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMaxCurrentLimit);
}

VALUE ph_dc_motor_get_current_regulator_gain(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getCurrentRegulatorGain);
}

VALUE ph_dc_motor_set_current_regulator_gain(VALUE self, VALUE gain) {
  ph_raise(PhidgetDCMotor_setCurrentRegulatorGain((PhidgetDCMotorHandle)get_ph_handle(self), NUM2DBL(gain)));
  return Qnil;
}

VALUE ph_dc_motor_get_min_current_regulator_gain(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMinCurrentRegulatorGain);
}

VALUE ph_dc_motor_get_max_current_regulator_gain(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMaxCurrentRegulatorGain);
}

VALUE ph_dc_motor_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDCMotor_getDataInterval);
}

VALUE ph_dc_motor_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetDCMotor_setDataInterval((PhidgetDCMotorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_dc_motor_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDCMotor_getMinDataInterval);
}

VALUE ph_dc_motor_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetDCMotor_getMaxDataInterval);
}

VALUE ph_dc_motor_get_fan_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), (phidget_get_int_func)PhidgetDCMotor_getFanMode);
}

VALUE ph_dc_motor_set_fan_mode(VALUE self, VALUE fan_mode) {
  ph_raise(PhidgetDCMotor_setFanMode((PhidgetDCMotorHandle)get_ph_handle(self), NUM2INT(fan_mode)));
  return Qnil;
}

VALUE ph_dc_motor_get_target_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getTargetBrakingStrength);
}

VALUE ph_dc_motor_set_target_braking_strength(VALUE self, VALUE target_braking_strength) {
  ph_raise(PhidgetDCMotor_setTargetBrakingStrength((PhidgetDCMotorHandle)get_ph_handle(self), NUM2DBL(target_braking_strength)));
  return Qnil;
}

VALUE ph_dc_motor_get_target_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getTargetVelocity);
}

VALUE ph_dc_motor_set_target_velocity(VALUE self, VALUE target_velocity) {
  ph_raise(PhidgetDCMotor_setTargetVelocity((PhidgetDCMotorHandle)get_ph_handle(self), NUM2DBL(target_velocity)));
  return Qnil;
}

VALUE ph_dc_motor_get_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getVelocity);
}

VALUE ph_dc_motor_get_min_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMinVelocity);
}

VALUE ph_dc_motor_get_max_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetDCMotor_getMaxVelocity);
}


void CCONV ph_dc_motor_on_back_emf_change(PhidgetDCMotorHandle phid, void *userPtr, double back_emf) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(back_emf);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_dc_motor_set_on_back_emf_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DC_MOTOR_BACK_EMF_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDCMotor_setOnBackEMFChangeHandler((PhidgetDCMotorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDCMotor_setOnBackEMFChangeHandler((PhidgetDCMotorHandle)ph->handle, ph_dc_motor_on_back_emf_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_dc_motor_on_braking_strength_change(PhidgetDCMotorHandle phid, void *userPtr, double braking_strength) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(braking_strength);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_dc_motor_set_on_braking_strength_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DC_MOTOR_BRAKING_STRENGTH_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDCMotor_setOnBrakingStrengthChangeHandler((PhidgetDCMotorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDCMotor_setOnBrakingStrengthChangeHandler((PhidgetDCMotorHandle)ph->handle, ph_dc_motor_on_braking_strength_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_dc_motor_on_velocity_update(PhidgetDCMotorHandle phid, void *userPtr, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = DBL2NUM(velocity);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_dc_motor_set_on_velocity_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DC_MOTOR_VELOCITY_UPDATE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDCMotor_setOnVelocityUpdateHandler((PhidgetDCMotorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDCMotor_setOnVelocityUpdateHandler((PhidgetDCMotorHandle)ph->handle, ph_dc_motor_on_velocity_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}



void Init_dc_motor() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_dc_motor = rb_define_class_under(ph_module, "DCMotor", ph_common);



  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget DCMotor object.
   */
  rb_define_method(ph_dc_motor, "initialize", ph_dc_motor_init, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration -> acceleration
   *
   * The rate at which the controller can change the motor's Velocity.
   * The acceleration is bounded by MinAccleration and MaxAcceleration.
   */
  rb_define_method(ph_dc_motor, "getAcceleration", ph_dc_motor_get_acceleration, 0);
  rb_define_alias(ph_dc_motor, "acceleration", "getAcceleration");

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(acceleration)
   *
   * The rate at which the controller can change the motor's Velocity.
   * The acceleration is bounded by MinAccleration and MaxAcceleration.
   */
  rb_define_method(ph_dc_motor, "setAcceleration", ph_dc_motor_set_acceleration, 1);
  rb_define_alias(ph_dc_motor, "acceleration=", "setAcceleration");

  /* Document-method: getMinAcceleration
   * call-seq: getMinAcceleration -> acceleration
   *
   * The minimum value that Acceleration can be set to.
   */
  rb_define_method(ph_dc_motor, "getMinAcceleration", ph_dc_motor_get_min_acceleration, 0);
  rb_define_alias(ph_dc_motor, "min_acceleration", "getMinAcceleration");

  /* Document-method: getMaxAcceleration
   * call-seq: getMaxAcceleration -> acceleration
   *
   * The maximum value that Acceleration can be set to.
   */
  rb_define_method(ph_dc_motor, "getMaxAcceleration", ph_dc_motor_get_max_acceleration, 0);
  rb_define_alias(ph_dc_motor, "max_acceleration", "getMaxAcceleration");

  /* Document-method: getBackEMF
   * call-seq: getBackEMF -> back_emf
   *
   * The most recent BackEMF value that the controller has reported.
   */
  rb_define_method(ph_dc_motor, "getBackEMF", ph_dc_motor_get_back_emf, 0);
  rb_define_alias(ph_dc_motor, "back_emf", "getBackEMF");

  /* Document-method: getBackEMFSensingState
   * call-seq: getBackEMFSensingState -> sensing_state
   *
   * When BackEMFSensingState is enabled, the controller will measure and report the BackEMF.
   * The motor will coast (freewheel) 5% of the time while the back EMF is being measured (800μs every 16ms).
   * Therefore, at a DutyCycle of 100%, the motor will only be driven for 95% of the time.
   */
  rb_define_method(ph_dc_motor, "getBackEMFSensingState", ph_dc_motor_get_back_emf_sensing_state, 0);
  rb_define_alias(ph_dc_motor, "back_emf_sensing_state", "getBackEMFSensingState");

  /* Document-method: setBackEMFSensingState
   * call-seq: setBackEMFSensingState(sensing_state)
   *
   * When BackEMFSensingState is enabled, the controller will measure and report the BackEMF.
   * The motor will coast (freewheel) 5% of the time while the back EMF is being measured (800μs every 16ms).
   * Therefore, at a DutyCycle of 100%, the motor will only be driven for 95% of the time.
   */
  rb_define_method(ph_dc_motor, "setBackEMFSensingState", ph_dc_motor_set_back_emf_sensing_state, 1);
  rb_define_alias(ph_dc_motor, "back_emf_sensing_state=", "setBackEMFSensingState");

  /* Document-method: getBrakingStrength
   * call-seq: getBrakingStrength -> braking_strength
   *
   * The most recent braking strength value that the controller has reported.
   */
  rb_define_method(ph_dc_motor, "getBrakingStrength", ph_dc_motor_get_braking_strength, 0);
  rb_define_alias(ph_dc_motor, "braking_strength", "getBrakingStrength");

  /* Document-method: getMinBrakingStrength
   * call-seq: getMinBrakingStrength -> braking_strength
   *
   * The minimum value that TargetBrakingStrength can be set to.
   */
  rb_define_method(ph_dc_motor, "getMinBrakingStrength", ph_dc_motor_get_min_braking_strength, 0);
  rb_define_alias(ph_dc_motor, "min_braking_strength", "getMinBrakingStrength");

  /* Document-method: getMaxBrakingStrength
   * call-seq: getMaxBrakingStrength -> braking_strength
   *
   * The maximum value that TargetBrakingStrength can be set to.
   */
  rb_define_method(ph_dc_motor, "getMaxBrakingStrength", ph_dc_motor_get_max_braking_strength, 0);
  rb_define_alias(ph_dc_motor, "max_braking_strength", "getMaxBrakingStrength");

  /* Document-method: getCurrentLimit
   * call-seq: getCurrentLimit -> current_limit
   *
   * The controller will limit the current through the motor to the CurrentLimit value.
   */
  rb_define_method(ph_dc_motor, "getCurrentLimit", ph_dc_motor_get_current_limit, 0);
  rb_define_alias(ph_dc_motor, "current_limit", "getCurrentLimit");

  /* Document-method: setCurrentLimit
   * call-seq: setCurrentLimit(current_limit)
   *
   * The controller will limit the current through the motor to the CurrentLimit value.
   */
  rb_define_method(ph_dc_motor, "setCurrentLimit", ph_dc_motor_set_current_limit, 1);
  rb_define_alias(ph_dc_motor, "current_limit=", "setCurrentLimit");

  /* Document-method: getMinCurrentLimit
   * call-seq: getMinCurrentLimit -> current_limit
   *
   * The minimum value that CurrentLimit can be set to.
   */
  rb_define_method(ph_dc_motor, "getMinCurrentLimit", ph_dc_motor_get_min_current_limit, 0);
  rb_define_alias(ph_dc_motor, "min_current_limit", "getMinCurrentLimit");

  /* Document-method: getMaxCurrentLimit
   * call-seq: getMaxCurrentLimit -> current_limit
   *
   * The maximum value that CurrentLimit can be set to.
   */
  rb_define_method(ph_dc_motor, "getMaxCurrentLimit", ph_dc_motor_get_max_current_limit, 0);
  rb_define_alias(ph_dc_motor, "max_current_limit", "getMaxCurrentLimit");

  /* Document-method: getCurrentRegulatorGain
   * call-seq: getCurrentRegulatorGain -> regulator_gain
   *
   * Depending on power supply voltage and motor coil inductance, current through the motor can
   * change relatively slowly or extremely rapidly. A physically larger DC Motor will typically
   * have a lower inductance, requiring a higher current regulator gain. A higher power supply
   * voltage will result in motor current changing more rapidly, requiring a higher current regulator
   * gain. If the current regulator gain is too small, spikes in current will occur, causing large
   * variations in torque, and possibly damaging the motor controller. If the current regulator gain
   * is too high, the current will jitter, causing the motor to sound 'rough', especially when changing directions.
   * Each DC Motor we sell specifies a suitable current regulator gain.
   */
  rb_define_method(ph_dc_motor, "getCurrentRegulatorGain", ph_dc_motor_get_current_regulator_gain, 0);
  rb_define_alias(ph_dc_motor, "current_regulator_gain", "getCurrentRegulatorGain");

  /* Document-method: setCurrentRegulatorGain
   * call-seq: setCurrentRegulatorGain(regulator_gain)
   *
   * Depending on power supply voltage and motor coil inductance, current through the motor can
   * change relatively slowly or extremely rapidly. A physically larger DC Motor will typically
   * have a lower inductance, requiring a higher current regulator gain. A higher power supply
   * voltage will result in motor current changing more rapidly, requiring a higher current regulator
   * gain. If the current regulator gain is too small, spikes in current will occur, causing large
   * variations in torque, and possibly damaging the motor controller. If the current regulator gain
   * is too high, the current will jitter, causing the motor to sound 'rough', especially when changing directions.
   * Each DC Motor we sell specifies a suitable current regulator gain.
   */
  rb_define_method(ph_dc_motor, "setCurrentRegulatorGain", ph_dc_motor_set_current_regulator_gain, 1);
  rb_define_alias(ph_dc_motor, "current_regulator_gain=", "setCurrentRegulatorGain");

  /* Document-method: getMinCurrentRegulatorGain
   * call-seq: getMinCurrentRegulatorGain -> regulator_gain
   *
   * The minimum value that CurrentRegulatorGain can be set to.
   */
  rb_define_method(ph_dc_motor, "getMinCurrentRegulatorGain", ph_dc_motor_get_min_current_regulator_gain, 0);
  rb_define_alias(ph_dc_motor, "min_current_regulator_gain", "getMinCurrentRegulatorGain");

  /* Document-method: getMaxCurrentRegulatorGain
   * call-seq: getMaxCurrentRegulatorGain -> regulator_gain
   *
   * The maximum value that CurrentRegulatorGain can be set to.
   */
  rb_define_method(ph_dc_motor, "getMaxCurrentRegulatorGain", ph_dc_motor_get_max_current_regulator_gain, 0);
  rb_define_alias(ph_dc_motor, "max_current_regulator_gain", "getMaxCurrentRegulatorGain");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the controller will fire another update event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_dc_motor, "getDataInterval", ph_dc_motor_get_data_interval, 0);
  rb_define_alias(ph_dc_motor, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the controller will fire another update event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_dc_motor, "setDataInterval", ph_dc_motor_set_data_interval, 1);
  rb_define_alias(ph_dc_motor, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_dc_motor, "getMinDataInterval", ph_dc_motor_get_min_data_interval, 0);
  rb_define_alias(ph_dc_motor, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_dc_motor, "getMaxDataInterval", ph_dc_motor_get_max_data_interval, 0);
  rb_define_alias(ph_dc_motor, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getFanMode
   * call-seq: getFanMode -> fan_mode
   *
   * The FanMode dictates the operating condition of the fan.
   * Choose between on, off, or automatic (based on temperature).
   * If the FanMode is set to automatic, the fan will turn on when the temperature
   * reaches 70°C and it will remain on until the temperature falls below 55°C.
   * If the FanMode is off, the controller will still turn on the fan if the temperature
   * reaches 85°C and it will remain on until it falls below 70°C.
   */
  rb_define_method(ph_dc_motor, "getFanMode", ph_dc_motor_get_fan_mode, 0);
  rb_define_alias(ph_dc_motor, "fan_mode", "getFanMode");

  /* Document-method: setFanMode
   * call-seq: setFanMode(fan_mode)
   *
   * The FanMode dictates the operating condition of the fan.
   * Choose between on, off, or automatic (based on temperature).
   * If the FanMode is set to automatic, the fan will turn on when the temperature
   * reaches 70°C and it will remain on until the temperature falls below 55°C.
   * If the FanMode is off, the controller will still turn on the fan if the temperature
   * reaches 85°C and it will remain on until it falls below 70°C.
   */
  rb_define_method(ph_dc_motor, "setFanMode", ph_dc_motor_set_fan_mode, 1);
  rb_define_alias(ph_dc_motor, "fan_mode=", "setFanMode");

  /* Document-method: getTargetBrakingStrength
   * call-seq: getTargetBrakingStrength -> braking_strength
   *
   * When a motor is not being actively driven forward or reverse, you can choose if the motor will be allowed to freely turn, or will resist being turned.
   * A low TargetBrakingStrength value corresponds to free wheeling, this will have the following effects:
   * The motor will continue to rotate after the controller is no longer driving the motor (i.e. Velocity is 0), due to inertia.
   * The motor shaft will provide little resistance to being turned when it is stopped.
   * A higher TargetBrakingStrength value will resist being turned, this will have the following effects:
   * The motor will more stop more quickly if it is in motion and braking has been requested. It will fight against the rotation of the shaft.
   * Braking mode is enabled by setting the Velocity to MinVelocity.
   */
  rb_define_method(ph_dc_motor, "getTargetBrakingStrength", ph_dc_motor_get_target_braking_strength, 0);
  rb_define_alias(ph_dc_motor, "target_braking_strength", "getTargetBrakingStrength");

  /* Document-method: setTargetBrakingStrength
   * call-seq: setTargetBrakingStrength(braking_strength)
   *
   * When a motor is not being actively driven forward or reverse, you can choose if the motor will be allowed to freely turn, or will resist being turned.
   * A low TargetBrakingStrength value corresponds to free wheeling, this will have the following effects:
   * The motor will continue to rotate after the controller is no longer driving the motor (i.e. Velocity is 0), due to inertia.
   * The motor shaft will provide little resistance to being turned when it is stopped.
   * A higher TargetBrakingStrength value will resist being turned, this will have the following effects:
   * The motor will more stop more quickly if it is in motion and braking has been requested. It will fight against the rotation of the shaft.
   * Braking mode is enabled by setting the Velocity to MinVelocity.
   */
  rb_define_method(ph_dc_motor, "setTargetBrakingStrength", ph_dc_motor_set_target_braking_strength, 1);
  rb_define_alias(ph_dc_motor, "target_braking_strength=", "setTargetBrakingStrength");

  /* Document-method: getTargetVelocity
   * call-seq: getTargetVelocity -> velocity
   *
   * The average voltage across the motor is based on the TargetVelocity value.
   * At a constant load, increasing the target velocity will increase the speed of the motor.
   * TargetVelocity is bounded by -1×MaxVelocity and MaxVelocity, where a sign change (±) is indicitave of a direction change.
   * Setting TargetVelocity to MinVelocity will stop the motor. See TargetBrakingStrength for more information on stopping the motor.
   * The units of TargetVelocity and Acceleration refer to 'duty cycle'. This is because the controller must rapidly switch the power
   * on/off (i.e. change the duty cycle) in order to manipulate the voltage across the motor.
   */
  rb_define_method(ph_dc_motor, "getTargetVelocity", ph_dc_motor_get_target_velocity, 0);
  rb_define_alias(ph_dc_motor, "target_velocity", "getTargetVelocity");

  /* Document-method: setTargetVelocity
   * call-seq: setTargetVelocity(velocity)
   *
   * The average voltage across the motor is based on the TargetVelocity value.
   * At a constant load, increasing the target velocity will increase the speed of the motor.
   * TargetVelocity is bounded by -1×MaxVelocity and MaxVelocity, where a sign change (±) is indicitave of a direction change.
   * Setting TargetVelocity to MinVelocity will stop the motor. See TargetBrakingStrength for more information on stopping the motor.
   * The units of TargetVelocity and Acceleration refer to 'duty cycle'. This is because the controller must rapidly switch the power
   * on/off (i.e. change the duty cycle) in order to manipulate the voltage across the motor.
   */
  rb_define_method(ph_dc_motor, "setTargetVelocity", ph_dc_motor_set_target_velocity, 1);
  rb_define_alias(ph_dc_motor, "target_velocity=", "setTargetVelocity");

  /* Document-method: getVelocity
   * call-seq: getVelocity -> velocity
   *
   * The most recent velocity value that the controller has reported.
   */
  rb_define_method(ph_dc_motor, "getVelocity", ph_dc_motor_get_velocity, 0);
  rb_define_alias(ph_dc_motor, "velocity", "getVelocity");

  /* Document-method: getMinVelocity
   * call-seq: getMinVelocity -> velocity
   *
   * The minimum value that TargetVelocity can be set to
   * Set the TargetVelocity to MinVelocity to stop the motor. See TargetBrakingStrength for more information on stopping the motor.
   * TargetVelocity is bounded by -1×MaxVelocity and MaxVelocity, where a sign change (±) is indicitave of a direction change.
   */
  rb_define_method(ph_dc_motor, "getMinVelocity", ph_dc_motor_get_min_velocity, 0);
  rb_define_alias(ph_dc_motor, "min_velocity", "getMinVelocity");

  /* Document-method: getMaxVelocity
   * call-seq: getMaxVelocity -> velocity
   *
   * The maximum value that TargetVelocity can be set to.
   * TargetVelocity is bounded by -1×MaxVelocity and MaxVelocity, where a sign change (±) is indicitave of a direction change.
   */
  rb_define_method(ph_dc_motor, "getMaxVelocity", ph_dc_motor_get_max_velocity, 0);
  rb_define_alias(ph_dc_motor, "max_velocity", "getMaxVelocity");

  rb_define_private_method(ph_dc_motor, "ext_setOnBackEMFChangeHandler", ph_dc_motor_set_on_back_emf_change_handler, 1);
  rb_define_private_method(ph_dc_motor, "ext_setOnBrakingStrengthChangeHandler", ph_dc_motor_set_on_braking_strength_change_handler, 1);
  rb_define_private_method(ph_dc_motor, "ext_setOnVelocityUpdateHandler", ph_dc_motor_set_on_velocity_update_handler, 1);
}

