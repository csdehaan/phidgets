
#include "phidgets.h"

#define STEPPER_POSITION_CHANGE_CALLBACK        0
#define STEPPER_STOPPED_CALLBACK                1
#define STEPPER_VELOCITY_CHANGE_CALLBACK        2
#define STEPPER_TARGET_POSITION_ASYNC_CALLBACK  3


VALUE ph_stepper_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetStepper_create((PhidgetStepperHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_stepper_get_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getAcceleration);
}

VALUE ph_stepper_set_acceleration(VALUE self, VALUE accel) {
  ph_raise(PhidgetStepper_setAcceleration((PhidgetStepperHandle)get_ph_handle(self), NUM2DBL(accel)));
  return Qnil;
}

VALUE ph_stepper_get_min_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMinAcceleration);
}

VALUE ph_stepper_get_max_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMaxAcceleration);
}

VALUE ph_stepper_get_control_mode(VALUE self) {
  return ph_get_int(get_ph_handle(self), PhidgetStepper_getControlMode);
}

VALUE ph_stepper_set_control_mode(VALUE self, VALUE mode) {
  ph_raise(PhidgetStepper_setControlMode((PhidgetStepperHandle)get_ph_handle(self), NUM2INT(mode)));
  return Qnil;
}

VALUE ph_stepper_get_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getCurrentLimit);
}

VALUE ph_stepper_set_current_limit(VALUE self, VALUE limit) {
  ph_raise(PhidgetStepper_setCurrentLimit((PhidgetStepperHandle)get_ph_handle(self), NUM2DBL(limit)));
  return Qnil;
}

VALUE ph_stepper_get_min_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMinCurrentLimit);
}

VALUE ph_stepper_get_max_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMaxCurrentLimit);
}

VALUE ph_stepper_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetStepper_getDataInterval);
}

VALUE ph_stepper_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetStepper_setDataInterval((PhidgetStepperHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_stepper_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetStepper_getMinDataInterval);
}

VALUE ph_stepper_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), PhidgetStepper_getMaxDataInterval);
}

VALUE ph_stepper_get_engaged(VALUE self) {
  return ph_get_bool(get_ph_handle(self), PhidgetStepper_getEngaged);
}

VALUE ph_stepper_set_engaged(VALUE self, VALUE state) {
  ph_raise(PhidgetStepper_setEngaged((PhidgetStepperHandle)get_ph_handle(self), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_stepper_get_holding_current_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getHoldingCurrentLimit);
}

VALUE ph_stepper_set_holding_current_limit(VALUE self, VALUE limit) {
  ph_raise(PhidgetStepper_setHoldingCurrentLimit((PhidgetStepperHandle)get_ph_handle(self), NUM2DBL(limit)));
  return Qnil;
}

VALUE ph_stepper_get_is_moving(VALUE self) {
  return ph_get_bool(get_ph_handle(self), PhidgetStepper_getIsMoving);
}

VALUE ph_stepper_get_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getPosition);
}

VALUE ph_stepper_get_min_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMinPosition);
}

VALUE ph_stepper_get_max_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMaxPosition);
}

VALUE ph_stepper_add_position_offset(VALUE self, VALUE offset) {
  ph_raise(PhidgetStepper_addPositionOffset((PhidgetStepperHandle)get_ph_handle(self), NUM2DBL(offset)));
  return Qnil;
}

VALUE ph_stepper_get_rescale_factor(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getRescaleFactor);
}

VALUE ph_stepper_set_rescale_factor(VALUE self, VALUE rescale_factor) {
  ph_raise(PhidgetStepper_setRescaleFactor((PhidgetStepperHandle)get_ph_handle(self), NUM2DBL(rescale_factor)));
  return Qnil;
}

VALUE ph_stepper_get_target_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getTargetPosition);
}

VALUE ph_stepper_set_target_position(VALUE self, VALUE position) {
  ph_raise(PhidgetStepper_setTargetPosition((PhidgetStepperHandle)get_ph_handle(self), NUM2DBL(position)));
  return Qnil;
}

VALUE ph_stepper_get_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getVelocity);
}

VALUE ph_stepper_get_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getVelocityLimit);
}

VALUE ph_stepper_set_velocity_limit(VALUE self, VALUE limit) {
  ph_raise(PhidgetStepper_setVelocityLimit((PhidgetStepperHandle)get_ph_handle(self), NUM2DBL(limit)));
  return Qnil;
}

VALUE ph_stepper_get_min_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMinVelocityLimit);
}

VALUE ph_stepper_get_max_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetStepper_getMaxVelocityLimit);
}


void CCONV ph_stepper_on_position_change(PhidgetStepperHandle phid, void *userPtr, double position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(position);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_stepper_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[STEPPER_POSITION_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetStepper_setOnPositionChangeHandler((PhidgetStepperHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetStepper_setOnPositionChangeHandler((PhidgetStepperHandle)ph->handle, ph_stepper_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_stepper_on_stopped(PhidgetStepperHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = Qnil;
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_stepper_set_on_stopped_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[STEPPER_STOPPED_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetStepper_setOnStoppedHandler((PhidgetStepperHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetStepper_setOnStoppedHandler((PhidgetStepperHandle)ph->handle, ph_stepper_on_stopped, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_stepper_on_velocity_change(PhidgetStepperHandle phid, void *userPtr, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(velocity);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_stepper_set_on_velocity_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[STEPPER_VELOCITY_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetStepper_setOnVelocityChangeHandler((PhidgetStepperHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetStepper_setOnVelocityChangeHandler((PhidgetStepperHandle)ph->handle, ph_stepper_on_velocity_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_stepper_target_position_async(PhidgetHandle phid, void *userPtr, PhidgetReturnCode res) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->exit = true;
  callback_data->arg1 = INT2NUM(res);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_stepper_set_target_position_async(VALUE self, VALUE position, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[STEPPER_TARGET_POSITION_ASYNC_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    PhidgetStepper_setTargetPosition_async((PhidgetStepperHandle)ph->handle, NUM2DBL(position), NULL, (void *)NULL);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    PhidgetStepper_setTargetPosition_async((PhidgetStepperHandle)ph->handle, NUM2DBL(position), ph_stepper_target_position_async, (void *)callback_data);
    ph_callback_thread(callback_data);
  }
  return Qnil;
}



void Init_stepper() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_stepper = rb_define_class_under(ph_module, "Stepper", ph_common);

  rb_define_const(ph_stepper, "CONTROL_MODE_STEP", INT2NUM(CONTROL_MODE_STEP));
  rb_define_const(ph_stepper, "CONTROL_MODE_RUN", INT2NUM(CONTROL_MODE_RUN));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Stepper object.
   */
  rb_define_method(ph_stepper, "initialize", ph_stepper_init, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration -> acceleration
   *
   * The rate at which the controller can change the motor's Velocity.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "getAcceleration", ph_stepper_get_acceleration, 0);
  rb_define_alias(ph_stepper, "acceleration", "getAcceleration");

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(acceleration)
   *
   * The rate at which the controller can change the motor's Velocity.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "setAcceleration", ph_stepper_set_acceleration, 1);
  rb_define_alias(ph_stepper, "acceleration=", "setAcceleration");

  /* Document-method: getMinAcceleration
   * call-seq: getMinAcceleration -> acceleration
   *
   * The minimum value that Acceleration can be set to.
   */
  rb_define_method(ph_stepper, "getMinAcceleration", ph_stepper_get_min_acceleration, 0);
  rb_define_alias(ph_stepper, "min_acceleration", "getMinAcceleration");

  /* Document-method: getMaxAcceleration
   * call-seq: getMaxAcceleration -> acceleration
   *
   * The maximum value that Acceleration can be set to.
   */
  rb_define_method(ph_stepper, "getMaxAcceleration", ph_stepper_get_max_acceleration, 0);
  rb_define_alias(ph_stepper, "max_acceleration", "getMaxAcceleration");

  /* Document-method: getControlMode
   * call-seq: getControlMode -> control_mode
   *
   * Use step mode when you want to set a TargetPosition for the Stepper motor. Use run mode when you simply want the Stepper motor to rotate continuously in a specific direction.
   */
  rb_define_method(ph_stepper, "getControlMode", ph_stepper_get_control_mode, 0);
  rb_define_alias(ph_stepper, "control_mode", "getControlMode");

  /* Document-method: setControlMode
   * call-seq: setControlMode(control_mode)
   *
   * Use step mode when you want to set a TargetPosition for the Stepper motor. Use run mode when you simply want the Stepper motor to rotate continuously in a specific direction.
   */
  rb_define_method(ph_stepper, "setControlMode", ph_stepper_set_control_mode, 1);
  rb_define_alias(ph_stepper, "control_mode=", "setControlMode");

  /* Document-method: getCurrentLimit
   * call-seq: getCurrentLimit -> limit
   *
   * The current through the motor will be limited by the CurrentLimit.
   * See your Stepper motor's data sheet for more information about what value the CurrentLimit should be.
   */
  rb_define_method(ph_stepper, "getCurrentLimit", ph_stepper_get_current_limit, 0);
  rb_define_alias(ph_stepper, "current_limit", "getCurrentLimit");

  /* Document-method: setCurrentLimit
   * call-seq: setCurrentLimit(limit)
   *
   * The current through the motor will be limited by the CurrentLimit.
   * See your Stepper motor's data sheet for more information about what value the CurrentLimit should be.
   */
  rb_define_method(ph_stepper, "setCurrentLimit", ph_stepper_set_current_limit, 1);
  rb_define_alias(ph_stepper, "current_limit=", "setCurrentLimit");

  /* Document-method: getMinCurrentLimit
   * call-seq: getMinCurrentLimit -> current_limit
   *
   * The minimum value that CurrentLimit and HoldingCurrentLimit can be set to.
   * Reference your controller's User Guide for more information about how the HoldingCurrentLimit and CurrentLimit can be used in your application.
   */
  rb_define_method(ph_stepper, "getMinCurrentLimit", ph_stepper_get_min_current_limit, 0);
  rb_define_alias(ph_stepper, "min_current_limit", "getMinCurrentLimit");

  /* Document-method: getMaxCurrentLimit
   * call-seq: getMaxCurrentLimit -> current_limit
   *
   * The maximum value that CurrentLimit and HoldingCurrentLimit can be set to.
   * Reference your controller's User Guide for more information about how the HoldingCurrentLimit and CurrentLimit can be used in your application.
   */
  rb_define_method(ph_stepper, "getMaxCurrentLimit", ph_stepper_get_max_current_limit, 0);
  rb_define_alias(ph_stepper, "max_current_limit", "getMaxCurrentLimit");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the controller will fire another PositionChange/VelocityChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_stepper, "getDataInterval", ph_stepper_get_data_interval, 0);
  rb_define_alias(ph_stepper, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the controller will fire another PositionChange/VelocityChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_stepper, "setDataInterval", ph_stepper_set_data_interval, 1);
  rb_define_alias(ph_stepper, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_stepper, "getMinDataInterval", ph_stepper_get_min_data_interval, 0);
  rb_define_alias(ph_stepper, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_stepper, "getMaxDataInterval", ph_stepper_get_max_data_interval, 0);
  rb_define_alias(ph_stepper, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getEngaged
   * call-seq: getEngaged -> true or false
   *
   * When this property is true, the controller will supply power to the motor coils.
   * The controller must be Engaged in order to move the Stepper motor, or have it hold position.
   */
  rb_define_method(ph_stepper, "getEngaged", ph_stepper_get_engaged, 0);
  rb_define_alias(ph_stepper, "engaged?", "getEngaged");

  /* Document-method: setEngaged
   * call-seq: setEngaged(state)
   *
   * When this property is true, the controller will supply power to the motor coils.
   * The controller must be Engaged in order to move the Stepper motor, or have it hold position.
   */
  rb_define_method(ph_stepper, "setEngaged", ph_stepper_set_engaged, 1);
  rb_define_alias(ph_stepper, "engaged=", "setEngaged");

  /* Document-method: getHoldingCurrentLimit
   * call-seq: getHoldingCurrentLimit -> holding_current_limit
   *
   * The HoldingCurrentLimit will activate when the TargetPosition has been reached. It will limit current through the motor.
   * When the motor is not stopped, the current through the motor is limited by the CurrentLimit.
   * If no HoldingCurrentLimit is specified, the CurrentLimit value will persist when the motor is stopped.
   * Reference your controller's User Guide for more information about how the HoldingCurrentLimit and CurrentLimit can be used in your application.
   */
  rb_define_method(ph_stepper, "getHoldingCurrentLimit", ph_stepper_get_holding_current_limit, 0);
  rb_define_alias(ph_stepper, "holding_current_limit", "getHoldingCurrentLimit");

  /* Document-method: setHoldingCurrentLimit
   * call-seq: setHoldingCurrentLimit(holding_current_limit)
   *
   * The HoldingCurrentLimit will activate when the TargetPosition has been reached. It will limit current through the motor.
   * When the motor is not stopped, the current through the motor is limited by the CurrentLimit.
   * If no HoldingCurrentLimit is specified, the CurrentLimit value will persist when the motor is stopped.
   * Reference your controller's User Guide for more information about how the HoldingCurrentLimit and CurrentLimit can be used in your application.
   */
  rb_define_method(ph_stepper, "setHoldingCurrentLimit", ph_stepper_set_holding_current_limit, 1);
  rb_define_alias(ph_stepper, "holding_current_limit=", "setHoldingCurrentLimit");

  /* Document-method: getIsMoving
   * call-seq: getIsMoving -> true or false
   *
   * IsMoving returns true while the controller is sending commands to the motor. Note: there is no feedback to the controller, so it does not know whether the motor shaft is actually moving or not.
   */
  rb_define_method(ph_stepper, "getIsMoving", ph_stepper_get_is_moving, 0);
  rb_define_alias(ph_stepper, "is_moving?", "getIsMoving");

  /* Document-method: getPosition
   * call-seq: getPosition -> position
   *
   * The most recent position value that the controller has reported.
   * This value will always be between MinPosition and MaxPosition.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "getPosition", ph_stepper_get_position, 0);
  rb_define_alias(ph_stepper, "position", "getPosition");

  /* Document-method: getMinPosition
   * call-seq: getMinPosition -> position
   *
   * The minimum value that TargetPosition can be set to.
   */
  rb_define_method(ph_stepper, "getMinPosition", ph_stepper_get_min_position, 0);
  rb_define_alias(ph_stepper, "min_position", "getMinPosition");

  /* Document-method: getMaxPosition
   * call-seq: getMaxPosition -> position
   *
   * The maximum value that TargetPosition can be set to.
   */
  rb_define_method(ph_stepper, "getMaxPosition", ph_stepper_get_max_position, 0);
  rb_define_alias(ph_stepper, "max_position", "getMaxPosition");

  /* Document-method: addPositionOffset
   * call-seq: addPositionOffset(position_offset)
   *
   * Adds an offset (positive or negative) to the current position and target position.
   * This is especially useful for zeroing position.
   */
  rb_define_method(ph_stepper, "addPositionOffset", ph_stepper_add_position_offset, 1);
  rb_define_alias(ph_stepper, "add_position_offset", "addPositionOffset");

  /* Document-method: getRescaleFactor
   * call-seq: getRescaleFactor -> rescale_factor
   *
   * Applies a factor to the [user units] per step to all movement parameters to make the units in your application is more intuitive.
   * For example, starting from position 0 and setting a new position with a rescale factor, the stepper will move Position / RescaleFactor steps.
   * In this way, units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "getRescaleFactor", ph_stepper_get_rescale_factor, 0);
  rb_define_alias(ph_stepper, "rescale_factor", "getRescaleFactor");

  /* Document-method: setRescaleFactor
   * call-seq: setRescaleFactor(rescale_factor)
   *
   * Applies a factor to the [user units] per step to all movement parameters to make the units in your application is more intuitive.
   * For example, starting from position 0 and setting a new position with a rescale factor, the stepper will move Position / RescaleFactor steps.
   * In this way, units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "setRescaleFactor", ph_stepper_set_rescale_factor, 1);
  rb_define_alias(ph_stepper, "rescale_factor=", "setRescaleFactor");

  /* Document-method: getTargetPosition
   * call-seq: getTargetPosition -> position
   *
   * If the controller is configured and the TargetPosition is set, the Stepper motor will move towards the TargetPosition at the specified Acceleration and Velocity.
   * TargetPosition is only used when the ControlMode is set to step mode.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "getTargetPosition", ph_stepper_get_target_position, 0);
  rb_define_alias(ph_stepper, "target_position", "getTargetPosition");

  /* Document-method: setTargetPosition
   * call-seq: setTargetPosition(position)
   *
   * If the controller is configured and the TargetPosition is set, the Stepper motor will move towards the TargetPosition at the specified Acceleration and Velocity.
   * TargetPosition is only used when the ControlMode is set to step mode.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "setTargetPosition", ph_stepper_set_target_position, 1);
  rb_define_alias(ph_stepper, "target_position=", "setTargetPosition");

  /* Document-method: getVelocity
   * call-seq: getVelocity -> velocity
   *
   * The most recent velocity value that the controller has reported.
   * This value is bounded by MinVelocityLimit and MaxVelocityLimit.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "getVelocity", ph_stepper_get_velocity, 0);
  rb_define_alias(ph_stepper, "velocity", "getVelocity");

  /* Document-method: getVelocityLimit
   * call-seq: getVelocityLimit -> velocity_limit
   *
   * When moving, the Stepper motor velocity will be limited by this value.
   * The VelocityLimit is bounded by MinVelocityLimit and MaxVelocityLimit.
   * When in step mode, the MinVelocityLimit has a value of 0. This is because the sign (±) of the TargetPosition will indicate the direction.
   * When in run mode, the MinVelocityLimit has a value of -MaxVelocityLimit. This is because there is no target position, so the direction is defined by the sign (±) of the VelocityLimit.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "getVelocityLimit", ph_stepper_get_velocity_limit, 0);
  rb_define_alias(ph_stepper, "velocity_limit", "getVelocityLimit");

  /* Document-method: setVelocityLimit
   * call-seq: setVelocityLimit(velocity_limit)
   *
   * When moving, the Stepper motor velocity will be limited by this value.
   * The VelocityLimit is bounded by MinVelocityLimit and MaxVelocityLimit.
   * When in step mode, the MinVelocityLimit has a value of 0. This is because the sign (±) of the TargetPosition will indicate the direction.
   * When in run mode, the MinVelocityLimit has a value of -MaxVelocityLimit. This is because there is no target position, so the direction is defined by the sign (±) of the VelocityLimit.
   * Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   */
  rb_define_method(ph_stepper, "setVelocityLimit", ph_stepper_set_velocity_limit, 1);
  rb_define_alias(ph_stepper, "velocity_limit=", "setVelocityLimit");

  /* Document-method: getMinVelocityLimit
   * call-seq: getMinVelocityLimit -> velocity_limit
   *
   * The minimum value that VelocityLimit can be set to.
   */
  rb_define_method(ph_stepper, "getMinVelocityLimit", ph_stepper_get_min_velocity_limit, 0);
  rb_define_alias(ph_stepper, "min_velocity_limit", "getMinVelocityLimit");

  /* Document-method: getMaxVelocityLimit
   * call-seq: getMaxVelocityLimit -> velocity_limit
   *
   * The maximum value that VelocityLimit can be set to.
   */
  rb_define_method(ph_stepper, "getMaxVelocityLimit", ph_stepper_get_max_velocity_limit, 0);
  rb_define_alias(ph_stepper, "max_velocity_limit", "getMaxVelocityLimit");

  rb_define_private_method(ph_stepper, "ext_setOnPositionChangeHandler", ph_stepper_set_on_position_change_handler, 1);
  rb_define_private_method(ph_stepper, "ext_setOnStoppedHandler", ph_stepper_set_on_stopped_handler, 1);
  rb_define_private_method(ph_stepper, "ext_setOnVelocityChangeHandler", ph_stepper_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_stepper, "ext_setTargetPosition_async", ph_stepper_set_target_position_async, 2);
}

