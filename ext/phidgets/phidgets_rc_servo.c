
#include "phidgets.h"

#define RC_SERVO_POSITION_CHANGE_CALLBACK           0
#define RC_SERVO_TARGET_POSITION_REACHED_CALLBACK   1
#define RC_SERVO_VELOCITY_CHANGE_CALLBACK           2
#define RC_SERVO_TARGET_POSITION_ASYNC_CALLBACK     3



VALUE ph_rc_servo_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetRCServo_create((PhidgetRCServoHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_rc_servo_get_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getAcceleration);
}

VALUE ph_rc_servo_set_acceleration(VALUE self, VALUE acceleration) {
  ph_raise(PhidgetRCServo_setAcceleration((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(acceleration)));
  return Qnil;
}

VALUE ph_rc_servo_get_min_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMinAcceleration);
}

VALUE ph_rc_servo_get_max_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMaxAcceleration);
}

VALUE ph_rc_servo_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetRCServo_getDataInterval);
}

VALUE ph_rc_servo_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetRCServo_setDataInterval((PhidgetRCServoHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_rc_servo_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetRCServo_getMinDataInterval);
}

VALUE ph_rc_servo_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetRCServo_getMaxDataInterval);
}

VALUE ph_rc_servo_get_engaged(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetRCServo_getEngaged);
}

VALUE ph_rc_servo_set_engaged(VALUE self, VALUE engaged) {
  ph_raise(PhidgetRCServo_setEngaged((PhidgetRCServoHandle)get_ph_handle(self), TYPE(engaged) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_rc_servo_get_is_moving(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetRCServo_getIsMoving);
}

VALUE ph_rc_servo_get_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getPosition);
}

VALUE ph_rc_servo_get_min_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMinPosition);
}

VALUE ph_rc_servo_set_min_position(VALUE self, VALUE position) {
  ph_raise(PhidgetRCServo_setMinPosition((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(position)));
  return Qnil;
}

VALUE ph_rc_servo_get_max_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMaxPosition);
}

VALUE ph_rc_servo_set_max_position(VALUE self, VALUE position) {
  ph_raise(PhidgetRCServo_setMaxPosition((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(position)));
  return Qnil;
}

VALUE ph_rc_servo_get_min_pulse_width(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMinPulseWidth);
}

VALUE ph_rc_servo_set_min_pulse_width(VALUE self, VALUE pulse_width) {
  ph_raise(PhidgetRCServo_setMinPulseWidth((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(pulse_width)));
  return Qnil;
}

VALUE ph_rc_servo_get_max_pulse_width(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMaxPulseWidth);
}

VALUE ph_rc_servo_set_max_pulse_width(VALUE self, VALUE pulse_width) {
  ph_raise(PhidgetRCServo_setMaxPulseWidth((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(pulse_width)));
  return Qnil;
}

VALUE ph_rc_servo_get_min_pulse_width_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMinPulseWidthLimit);
}

VALUE ph_rc_servo_get_max_pulse_width_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMaxPulseWidthLimit);
}

VALUE ph_rc_servo_get_speed_ramping_state(VALUE self) {
  return ph_get_bool(get_ph_handle(self), (phidget_get_bool_func)PhidgetRCServo_getSpeedRampingState);
}

VALUE ph_rc_servo_set_speed_ramping_state(VALUE self, VALUE speed_ramping_state) {
  ph_raise(PhidgetRCServo_setSpeedRampingState((PhidgetRCServoHandle)get_ph_handle(self), TYPE(speed_ramping_state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_rc_servo_get_target_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getTargetPosition);
}

VALUE ph_rc_servo_set_target_position(VALUE self, VALUE position) {
  ph_raise(PhidgetRCServo_setTargetPosition((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(position)));
  return Qnil;
}

VALUE ph_rc_servo_get_torque(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getTorque);
}

VALUE ph_rc_servo_set_torque(VALUE self, VALUE torque) {
  ph_raise(PhidgetRCServo_setTorque((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(torque)));
  return Qnil;
}

VALUE ph_rc_servo_get_min_torque(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMinTorque);
}

VALUE ph_rc_servo_get_max_torque(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMaxTorque);
}

VALUE ph_rc_servo_get_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getVelocity);
}

VALUE ph_rc_servo_get_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getVelocityLimit);
}

VALUE ph_rc_servo_set_velocity_limit(VALUE self, VALUE velocity_limit) {
  ph_raise(PhidgetRCServo_setVelocityLimit((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(velocity_limit)));
  return Qnil;
}

VALUE ph_rc_servo_get_min_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMinVelocityLimit);
}

VALUE ph_rc_servo_get_max_velocity_limit(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getMaxVelocityLimit);
}

VALUE ph_rc_servo_get_voltage(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetRCServo_getVoltage);
}

VALUE ph_rc_servo_set_voltage(VALUE self, VALUE voltage) {
  ph_raise(PhidgetRCServo_setVoltage((PhidgetRCServoHandle)get_ph_handle(self), NUM2DBL(voltage)));
  return Qnil;
}


void CCONV ph_rc_servo_on_position_change(PhidgetRCServoHandle phid, void *userPtr, double position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(position);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_rc_servo_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[RC_SERVO_POSITION_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetRCServo_setOnPositionChangeHandler((PhidgetRCServoHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetRCServo_setOnPositionChangeHandler((PhidgetRCServoHandle)ph->handle, ph_rc_servo_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_rc_servo_on_target_position_reached(PhidgetRCServoHandle phid, void *userPtr, double position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(position);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_rc_servo_set_on_target_position_reached_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[RC_SERVO_TARGET_POSITION_REACHED_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetRCServo_setOnTargetPositionReachedHandler((PhidgetRCServoHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetRCServo_setOnTargetPositionReachedHandler((PhidgetRCServoHandle)ph->handle, ph_rc_servo_on_target_position_reached, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_rc_servo_on_velocity_change(PhidgetRCServoHandle phid, void *userPtr, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(velocity);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_rc_servo_set_on_velocity_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[RC_SERVO_VELOCITY_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetRCServo_setOnVelocityChangeHandler((PhidgetRCServoHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetRCServo_setOnVelocityChangeHandler((PhidgetRCServoHandle)ph->handle, ph_rc_servo_on_velocity_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_rc_servo_target_position_async(PhidgetHandle phid, void *userPtr, PhidgetReturnCode res) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->exit = true;
  callback_data->arg1 = INT2NUM(res);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_rc_servo_set_target_position_async(VALUE self, VALUE position, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[RC_SERVO_TARGET_POSITION_ASYNC_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    PhidgetRCServo_setTargetPosition_async((PhidgetRCServoHandle)ph->handle, NUM2DBL(position), NULL, (void *)NULL);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    PhidgetRCServo_setTargetPosition_async((PhidgetRCServoHandle)ph->handle, NUM2DBL(position), ph_rc_servo_target_position_async, (void *)callback_data);
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_rc_servo() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_rc_servo = rb_define_class_under(ph_module, "RCServo", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget RCServo object.
   */
  rb_define_method(ph_rc_servo, "initialize", ph_rc_servo_init, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration -> acceleration
   *
   * When changing velocity, the RC servo motor will accelerate/decelerate at this rate.
   * The acceleration is bounded by MaxAcceleration and MinAcceleration.
   * SpeedRampingState controls whether or not the acceleration value is actually applied when trying to reach a target position.
   * There is a practical limit on how fast your RC servo motor can accelerate. This is based on the load and physical design of the motor.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getAcceleration", ph_rc_servo_get_acceleration, 0);
  rb_define_alias(ph_rc_servo, "acceleration", "getAcceleration");

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(acceleration)
   *
   * When changing velocity, the RC servo motor will accelerate/decelerate at this rate.
   * The acceleration is bounded by MaxAcceleration and MinAcceleration.
   * SpeedRampingState controls whether or not the acceleration value is actually applied when trying to reach a target position.
   * There is a practical limit on how fast your RC servo motor can accelerate. This is based on the load and physical design of the motor.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "setAcceleration", ph_rc_servo_set_acceleration, 1);
  rb_define_alias(ph_rc_servo, "acceleration=", "setAcceleration");

  /* Document-method: getMinAcceleration
   * call-seq: getMinAcceleration -> acceleration
   *
   * The minimum value that Acceleration can be set to
   * This value depends on MinPosition/MaxPosition and MinPulseWidth/MaxPulseWidth.
   */
  rb_define_method(ph_rc_servo, "getMinAcceleration", ph_rc_servo_get_min_acceleration, 0);
  rb_define_alias(ph_rc_servo, "min_acceleration", "getMinAcceleration");

  /* Document-method: getMaxAcceleration
   * call-seq: getMaxAcceleration -> acceleration
   *
   * The maximum acceleration that Acceleration can be set to.
   * This value depends on MinPosition/MaxPosition and MinPulseWidth/MaxPulseWidth.
   */
  rb_define_method(ph_rc_servo, "getMaxAcceleration", ph_rc_servo_get_max_acceleration, 0);
  rb_define_alias(ph_rc_servo, "max_acceleration", "getMaxAcceleration");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> data_interval
   *
   * The DataInterval is the time that must elapse before the controller will fire another PositionChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_rc_servo, "getDataInterval", ph_rc_servo_get_data_interval, 0);
  rb_define_alias(ph_rc_servo, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(data_interval)
   *
   * The DataInterval is the time that must elapse before the controller will fire another PositionChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_rc_servo, "setDataInterval", ph_rc_servo_set_data_interval, 1);
  rb_define_alias(ph_rc_servo, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> data_interval
   *
   * The DataInterval is the time that must elapse before the controller will fire another PositionChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_rc_servo, "getMinDataInterval", ph_rc_servo_get_min_data_interval, 0);
  rb_define_alias(ph_rc_servo, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> data_interval
   *
   * The DataInterval is the time that must elapse before the controller will fire another PositionChange event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_rc_servo, "getMaxDataInterval", ph_rc_servo_get_max_data_interval, 0);
  rb_define_alias(ph_rc_servo, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getEngaged
   * call-seq: getEngaged -> true or false
   *
   * When engaged, a RC servo motor has the ability to be positioned. When disengaged, no commands are sent to the RC servo motor.
   * There is no position feedback to the controller, so the RC servo motor will immediately snap to the TargetPosition after being engaged from a disengaged state.
   * This property is useful for relaxing a servo once it has reached a given position.
   * If you are concerned about tracking position accurately, you should not disengage the motor while IsMoving is true.
   */
  rb_define_method(ph_rc_servo, "getEngaged", ph_rc_servo_get_engaged, 0);
  rb_define_alias(ph_rc_servo, "engaged?", "getEngaged");

  /* Document-method: setEngaged
   * call-seq: setEngaged(state)
   *
   * When engaged, a RC servo motor has the ability to be positioned. When disengaged, no commands are sent to the RC servo motor.
   * There is no position feedback to the controller, so the RC servo motor will immediately snap to the TargetPosition after being engaged from a disengaged state.
   * This property is useful for relaxing a servo once it has reached a given position.
   * If you are concerned about tracking position accurately, you should not disengage the motor while IsMoving is true.
   */
  rb_define_method(ph_rc_servo, "setEngaged", ph_rc_servo_set_engaged, 1);
  rb_define_alias(ph_rc_servo, "engaged=", "setEngaged");

  /* Document-method: getIsMoving
   * call-seq: getIsMoving -> true or false
   *
   * IsMoving returns true if the RC servo motor is currently in motion.
   * The controller cannot know if the RC servo motor is physically moving. When < code > IsMoving is false, it simply means there are no commands in the pipeline to the RC servo motor.
   */
  rb_define_method(ph_rc_servo, "getIsMoving", ph_rc_servo_get_is_moving, 0);
  rb_define_alias(ph_rc_servo, "is_moving?", "getIsMoving");

  /* Document-method: getPosition
   * call-seq: getPosition -> position
   *
   * The most recent position of the RC servo motor that the controller has reported.
   * This value will always be between MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getPosition", ph_rc_servo_get_position, 0);
  rb_define_alias(ph_rc_servo, "position", "getPosition");

  /* Document-method: getMinPosition
   * call-seq: getMinPosition -> position
   *
   * The minimum position that TargetPosition can be set to.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getMinPosition", ph_rc_servo_get_min_position, 0);
  rb_define_alias(ph_rc_servo, "min_position", "getMinPosition");

  /* Document-method: setMinPosition
   * call-seq: setMinPosition(position)
   *
   * The minimum position that TargetPosition can be set to.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "setMinPosition", ph_rc_servo_set_min_position, 1);
  rb_define_alias(ph_rc_servo, "min_position=", "setMinPosition");

  /* Document-method: getMaxPosition
   * call-seq: getMaxPosition -> position
   *
   * The maximum position TargetPosition can be set to.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getMaxPosition", ph_rc_servo_get_max_position, 0);
  rb_define_alias(ph_rc_servo, "max_position", "getMaxPosition");

  /* Document-method: setMaxPosition
   * call-seq: setMaxPosition(position)
   *
   * The maximum position that TargetPosition can be set to.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "setMaxPosition", ph_rc_servo_set_max_position, 1);
  rb_define_alias(ph_rc_servo, "max_position=", "setMaxPosition");

  /* Document-method: getMinPulseWidth
   * call-seq: getMinPulseWidth -> pulse_width
   *
   * The MinPulseWidth represents the minimum pulse width that your RC servo motor specifies.
   * This value can be found in the data sheet of most RC servo motors.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getMinPulseWidth", ph_rc_servo_get_min_pulse_width, 0);
  rb_define_alias(ph_rc_servo, "min_pulse_width", "getMinPulseWidth");

  /* Document-method: setMinPulseWidth
   * call-seq: setMinPulseWidth(pulse_width)
   *
   * The MinPulseWidth represents the minimum pulse width that your RC servo motor specifies.
   * This value can be found in the data sheet of most RC servo motors.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "setMinPulseWidth", ph_rc_servo_set_min_pulse_width, 1);
  rb_define_alias(ph_rc_servo, "min_pulse_width=", "setMinPulseWidth");

  /* Document-method: getMaxPulseWidth
   * call-seq: getMaxPulseWidth -> pulse_width
   *
   * The MaxPulseWidth represents the maximum pulse width that your RC servo motor specifies.
   * This value can be found in the data sheet of most RC servo motors.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getMaxPulseWidth", ph_rc_servo_get_max_pulse_width, 0);
  rb_define_alias(ph_rc_servo, "max_pulse_width", "getMaxPulseWidth");

  /* Document-method: setMaxPulseWidth
   * call-seq: setMaxPulseWidth(pulse_width)
   *
   * The MaxPulseWidth represents the maximum pulse width that your RC servo motor specifies.
   * This value can be found in the data sheet of most RC servo motors.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "setMaxPulseWidth", ph_rc_servo_set_max_pulse_width, 1);
  rb_define_alias(ph_rc_servo, "max_pulse_width=", "setMaxPulseWidth");

  /* Document-method: getMinPulseWidthLimit
   * call-seq: getMinPulseWidthLimit -> pulse_width
   *
   * The minimum pulse width that MinPulseWidth can be set to.
   */
  rb_define_method(ph_rc_servo, "getMinPulseWidthLimit", ph_rc_servo_get_min_pulse_width_limit, 0);
  rb_define_alias(ph_rc_servo, "min_pulse_width_limit", "getMinPulseWidthLimit");

  /* Document-method: getMaxPulseWidthLimit
   * call-seq: getMaxPulseWidthLimit -> pulse_width
   *
   * The maximum pulse width that MaxPulseWidth can be set to.
   */
  rb_define_method(ph_rc_servo, "getMaxPulseWidthLimit", ph_rc_servo_get_max_pulse_width_limit, 0);
  rb_define_alias(ph_rc_servo, "max_pulse_width_limit", "getMaxPulseWidthLimit");

  /* Document-method: getSpeedRampingState
   * call-seq: getSpeedRampingState -> ramping_state
   *
   * When speed ramping state is enabled, the controller will take the Acceleration and Velocity properties into account when moving the
   * RC servo motor, usually resulting in smooth motion. If speed ramping state is not enabled, the controller will simply set the RC servo motor to the requested position.
   */
  rb_define_method(ph_rc_servo, "getSpeedRampingState", ph_rc_servo_get_speed_ramping_state, 0);
  rb_define_alias(ph_rc_servo, "speed_ramping_state", "getSpeedRampingState");

  /* Document-method: setSpeedRampingState
   * call-seq: setSpeedRampingState(ramping_state)
   *
   * When speed ramping state is enabled, the controller will take the Acceleration and Velocity properties into account when moving the
   * RC servo motor, usually resulting in smooth motion. If speed ramping state is not enabled, the controller will simply set the RC servo motor to the requested position.
   */
  rb_define_method(ph_rc_servo, "setSpeedRampingState", ph_rc_servo_set_speed_ramping_state, 1);
  rb_define_alias(ph_rc_servo, "speed_ramping_state=", "setSpeedRampingState");

  /* Document-method: getTargetPosition
   * call-seq: getTargetPosition -> position
   *
   * If the RC servo motor is configured and TargetPosition is set, the controller will continuously try to reach targeted position.
   * The target position is bounded by MinPosition and MaxPosition.
   * If the RC servo motor is not engaged, then the position cannot be read.
   * The position can still be set while the RC servo motor is not engaged. Once engaged, the RC servo motor will snap to position, assuming it is not there already.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getTargetPosition", ph_rc_servo_get_target_position, 0);
  rb_define_alias(ph_rc_servo, "target_position", "getTargetPosition");

  /* Document-method: setTargetPosition
   * call-seq: setTargetPosition(position)
   *
   * If the RC servo motor is configured and TargetPosition is set, the controller will continuously try to reach targeted position.
   * The target position is bounded by MinPosition and MaxPosition.
   * If the RC servo motor is not engaged, then the position cannot be read.
   * The position can still be set while the RC servo motor is not engaged. Once engaged, the RC servo motor will snap to position, assuming it is not there already.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "setTargetPosition", ph_rc_servo_set_target_position, 1);
  rb_define_alias(ph_rc_servo, "target_position=", "setTargetPosition");

  /* Document-method: getTorque
   * call-seq: getTorque -> torque
   *
   * The Torque is a ratio of the maximum available torque.
   * The torque is bounded by MinTorque and MaxTorque
   * Increasing the torque will increase the speed and power consumption of the RC servo motor.
   */
  rb_define_method(ph_rc_servo, "getTorque", ph_rc_servo_get_torque, 0);
  rb_define_alias(ph_rc_servo, "torque", "getTorque");

  /* Document-method: setTorque
   * call-seq: setTorque(torque)
   *
   * The Torque is a ratio of the maximum available torque.
   * The torque is bounded by MinTorque and MaxTorque
   * Increasing the torque will increase the speed and power consumption of the RC servo motor.
   */
  rb_define_method(ph_rc_servo, "setTorque", ph_rc_servo_set_torque, 1);
  rb_define_alias(ph_rc_servo, "torque=", "setTorque");

  /* Document-method: getMinTorque
   * call-seq: getMinTorque -> torque
   *
   * The minimum value that Torque can be set to.
   * Torque is a ratio of the maximum available torque, therefore the minimum torque is a unitless constant.
   */
  rb_define_method(ph_rc_servo, "getMinTorque", ph_rc_servo_get_min_torque, 0);
  rb_define_alias(ph_rc_servo, "min_torque", "getMinTorque");

  /* Document-method: getMaxTorque
   * call-seq: getMaxTorque -> torque
   *
   * The maximum value that Torque can be set to.
   * Torque is a ratio of the maximum available torque, therefore the minimum torque is a unitless constant.
   */
  rb_define_method(ph_rc_servo, "getMaxTorque", ph_rc_servo_get_max_torque, 0);
  rb_define_alias(ph_rc_servo, "max_torque", "getMaxTorque");

  /* Document-method: getVelocity
   * call-seq: getVelocity -> velocity
   *
   * The velocity that the RC servo motor is being driven at.
   * A negative value means the RC servo motor is moving towards a lower position.
   * The velocity range of the RC servo motor will be from -VelocityLimit to VelocityLimit, depending on direction.
   * This is not the actual physical velocity of the RC servo motor.
   */
  rb_define_method(ph_rc_servo, "getVelocity", ph_rc_servo_get_velocity, 0);
  rb_define_alias(ph_rc_servo, "velocity", "getVelocity");

  /* Document-method: getVelocityLimit
   * call-seq: getVelocityLimit -> velocity
   *
   * When moving, the RC servo motor velocity will be limited by this value.
   * The velocity limit is bounded by MinVelocityLimit and MaxVelocityLimit.
   * SpeedRampingState controls whether or not the velocity limit value is actually applied when trying to reach a target position.
   * The velocity range of the RC servo motor will be from -VelocityLimit to VelocityLimit, depending on direction.
   * Note that when this value is set to 0, the RC servo motor will not move.
   * There is a practical limit on how fast your servo can rotate, based on the physical design of the motor.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "getVelocityLimit", ph_rc_servo_get_velocity_limit, 0);
  rb_define_alias(ph_rc_servo, "velocity_limit", "getVelocityLimit");

  /* Document-method: setVelocityLimit
   * call-seq: setVelocityLimit(velocity)
   *
   * When moving, the RC servo motor velocity will be limited by this value.
   * The velocity limit is bounded by MinVelocityLimit and MaxVelocityLimit.
   * SpeedRampingState controls whether or not the velocity limit value is actually applied when trying to reach a target position.
   * The velocity range of the RC servo motor will be from -VelocityLimit to VelocityLimit, depending on direction.
   * Note that when this value is set to 0, the RC servo motor will not move.
   * There is a practical limit on how fast your servo can rotate, based on the physical design of the motor.
   * The units for Position,Velocity, and Acceleration are configured by scaling the internal timing (set with MinPulseWidth and MaxPulseWidth) to a user specified range with MinPosition and MaxPosition.
   */
  rb_define_method(ph_rc_servo, "setVelocityLimit", ph_rc_servo_set_velocity_limit, 1);
  rb_define_alias(ph_rc_servo, "velocity_limit=", "setVelocityLimit");

  /* Document-method: getMinVelocityLimit
   * call-seq: getMinVelocityLimit -> velocity
   *
   * The minimum velocity VelocityLimit can be set to.
   */
  rb_define_method(ph_rc_servo, "getMinVelocityLimit", ph_rc_servo_get_min_velocity_limit, 0);
  rb_define_alias(ph_rc_servo, "min_velocity_limit", "getMinVelocityLimit");

  /* Document-method: getMaxVelocityLimit
   * call-seq: getMaxVelocityLimit -> velocity
   *
   * The maximum velocity VelocityLimit can be set to. This value depends on MinPosition/MaxPosition and MinPulseWidth/MaxPulseWidth.
   */
  rb_define_method(ph_rc_servo, "getMaxVelocityLimit", ph_rc_servo_get_max_velocity_limit, 0);
  rb_define_alias(ph_rc_servo, "max_velocity_limit", "getMaxVelocityLimit");

  /* Document-method: getVoltage
   * call-seq: getVoltage -> voltage
   *
   * The supply voltage for the RC servo motor.
   * If your controller supports multiple RC servo motors, every motor will have the same supply voltage. It is not possible to set individual supply voltages.
   */
  rb_define_method(ph_rc_servo, "getVoltage", ph_rc_servo_get_voltage, 0);
  rb_define_alias(ph_rc_servo, "voltage", "getVoltage");

  /* Document-method: setVoltage
   * call-seq: setVoltage(voltage)
   *
   * The supply voltage for the RC servo motor.
   * If your controller supports multiple RC servo motors, every motor will have the same supply voltage. It is not possible to set individual supply voltages.
   */
  rb_define_method(ph_rc_servo, "setVoltage", ph_rc_servo_set_voltage, 1);
  rb_define_alias(ph_rc_servo, "voltage=", "setVoltage");

  rb_define_private_method(ph_rc_servo, "ext_setOnPositionChangeHandler", ph_rc_servo_set_on_position_change_handler, 1);
}

