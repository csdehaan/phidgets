
#include "phidgets.h"

#if 0
VALUE ph_advservo_init(VALUE self);
VALUE ph_advservo_get_motor_count(VALUE self);
VALUE ph_advservo_get_acceleration(VALUE self, VALUE index);
VALUE ph_advservo_get_acceleration_min(VALUE self, VALUE index);
VALUE ph_advservo_get_acceleration_max(VALUE self, VALUE index);
VALUE ph_advservo_set_acceleration(VALUE self, VALUE index, VALUE accel);
VALUE ph_advservo_get_velocity(VALUE self, VALUE index);
VALUE ph_advservo_get_velocity_min(VALUE self, VALUE index);
VALUE ph_advservo_get_velocity_max(VALUE self, VALUE index);
VALUE ph_advservo_get_velocity_limit(VALUE self, VALUE index);
VALUE ph_advservo_set_velocity_limit(VALUE self, VALUE index, VALUE limit);
VALUE ph_advservo_get_position(VALUE self, VALUE index);
VALUE ph_advservo_get_position_min(VALUE self, VALUE index);
VALUE ph_advservo_get_position_max(VALUE self, VALUE index);
VALUE ph_advservo_set_position(VALUE self, VALUE index, VALUE position);
VALUE ph_advservo_set_position_min(VALUE self, VALUE index, VALUE min);
VALUE ph_advservo_set_position_max(VALUE self, VALUE index, VALUE max);
VALUE ph_advservo_get_current(VALUE self, VALUE index);
VALUE ph_advservo_get_speed_ramping_on(VALUE self, VALUE index);
VALUE ph_advservo_set_speed_ramping_on(VALUE self, VALUE index, VALUE state);
VALUE ph_advservo_get_engaged(VALUE self, VALUE index);
VALUE ph_advservo_set_engaged(VALUE self, VALUE index, VALUE state);
VALUE ph_advservo_get_stopped(VALUE self, VALUE index);
VALUE ph_advservo_get_servo_type(VALUE self, VALUE index);
VALUE ph_advservo_set_servo_type(VALUE self, VALUE index, VALUE type);
VALUE ph_advservo_set_servo_parameters(VALUE self, VALUE index, VALUE min_us, VALUE max_us, VALUE degrees, VALUE velocity_max);

VALUE ph_advservo_set_on_velocity_change_handler(VALUE self, VALUE handler);
VALUE ph_advservo_set_on_position_change_handler(VALUE self, VALUE handler);
VALUE ph_advservo_set_on_current_change_handler(VALUE self, VALUE handler);
int ph_advservo_on_velocity_change(PhidgetAdvancedServoHandle phid, void *userPtr, int index, double velocity);
int ph_advservo_on_position_change(PhidgetAdvancedServoHandle phid, void *userPtr, int index, double position);
int ph_advservo_on_current_change(PhidgetAdvancedServoHandle phid, void *userPtr, int index, double current);


void Init_advanced_servo() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_advservo = rb_define_class_under(ph_module, "AdvancedServo", ph_common);

  /* Default - This is what the servo API been historically used, originally based on the Futaba FP-S148 */
  rb_define_const(ph_advservo, "DEFAULT", INT2FIX(PHIDGET_SERVO_DEFAULT));
  /* Raw us mode - all position, velocity, acceleration functions are specified in microseconds rather then degrees */
  rb_define_const(ph_advservo, "RAW_US_MODE", INT2FIX(PHIDGET_SERVO_RAW_us_MODE));
  /* HiTec HS-322HD Standard \Servo */
  rb_define_const(ph_advservo, "HITEC_HS322HD", INT2FIX(PHIDGET_SERVO_HITEC_HS322HD));
  /* HiTec HS-5245MG Digital Mini \Servo */
  rb_define_const(ph_advservo, "HITEC_HS5245MG", INT2FIX(PHIDGET_SERVO_HITEC_HS5245MG));
  /* HiTec HS-805BB Mega Quarter Scale \Servo */
  rb_define_const(ph_advservo, "HITEC_805BB", INT2FIX(PHIDGET_SERVO_HITEC_805BB));
  /* HiTec HS-422 Standard \Servo */
  rb_define_const(ph_advservo, "HITEC_HS422", INT2FIX(PHIDGET_SERVO_HITEC_HS422));
  /* Tower Pro MG90 Micro \Servo */
  rb_define_const(ph_advservo, "TOWERPRO_MG90", INT2FIX(PHIDGET_SERVO_TOWERPRO_MG90));
  /* HiTec HSR-1425CR Continuous Rotation \Servo */
  rb_define_const(ph_advservo, "HITEC_HSR1425CR", INT2FIX(PHIDGET_SERVO_HITEC_HSR1425CR));
  /* HiTec HS-785HB Sail Winch \Servo */
  rb_define_const(ph_advservo, "HITEC_HS785HB", INT2FIX(PHIDGET_SERVO_HITEC_HS785HB));
  /* HiTec HS-485HB Deluxe \Servo */
  rb_define_const(ph_advservo, "HITEC_HS485HB", INT2FIX(PHIDGET_SERVO_HITEC_HS485HB));
  /* HiTec HS-645MG Ultra Torque \Servo */
  rb_define_const(ph_advservo, "HITEC_HS645MG", INT2FIX(PHIDGET_SERVO_HITEC_HS645MG));
  /* HiTec HS-815BB Mega Sail \Servo */
  rb_define_const(ph_advservo, "HITEC_815BB", INT2FIX(PHIDGET_SERVO_HITEC_815BB));
  /* Document-const:
   * Firgelli L12 Linear Actuator 30mm 50\:1 */
  rb_define_const(ph_advservo, "FIRGELLI_L12_30_50_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_30_50_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 50mm 100\:1 */
  rb_define_const(ph_advservo, "FIRGELLI_L12_50_100_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_50_100_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 50mm 210\:1 */
  rb_define_const(ph_advservo, "FIRGELLI_L12_50_210_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_50_210_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 100mm 50\:1 */
  rb_define_const(ph_advservo, "FIRGELLI_L12_100_50_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_100_50_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 100mm 100\:1 */
  rb_define_const(ph_advservo, "FIRGELLI_L12_100_100_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_100_100_06_R));
  /* SpringRC SM-S2313M Micro \Servo */
  rb_define_const(ph_advservo, "SPRINGRC_SM_S2313M", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S2313M));
  /* SpringRC SM-S3317M Small \Servo */
  rb_define_const(ph_advservo, "SPRINGRC_SM_S3317M", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S3317M));
  /* SpringRC SM-S3317SR Small Continuous Rotation \Servo */
  rb_define_const(ph_advservo, "SPRINGRC_SM_S3317SR", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S3317SR));
  /* SpringRC SM-S4303R Standard Continuous Rotation \Servo */
  rb_define_const(ph_advservo, "SPRINGRC_SM_S4303R", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4303R));
  /* SpringRC SM-S4315M High Torque \Servo */
  rb_define_const(ph_advservo, "SPRINGRC_SM_S4315M", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4315M));
  /* SpringRC SM-S4315R High Torque Continuous Rotation \Servo */
  rb_define_const(ph_advservo, "SPRINGRC_SM_S4315R", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4315R));
  /* SpringRC SM-S4505B Standard \Servo */
  rb_define_const(ph_advservo, "SPRINGRC_SM_S4505B", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4505B));


  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget AdvancedServo object.
   */
  rb_define_method(ph_advservo, "initialize", ph_advservo_init, 0);

  /* Document-method: getMotorCount
   * call-seq: getMotorCount -> count
   *
   * Gets the number of motors supported by this controller
   */
  rb_define_method(ph_advservo, "getMotorCount", ph_advservo_get_motor_count, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration(index) -> acceleration
   *
   * Gets the last set acceleration for a motor.
   */
  rb_define_method(ph_advservo, "getAcceleration", ph_advservo_get_acceleration, 1);

  /* Document-method: getAccelerationMin
   * call-seq: getAccelerationMin(index) -> min
   *
   * Gets the minimum acceleration supported by a motor.
   */
  rb_define_method(ph_advservo, "getAccelerationMin", ph_advservo_get_acceleration_min, 1);

  /* Document-method: getAccelerationMax
   * call-seq: getAccelerationMax(index) -> max
   *
   * Gets the maximum acceleration supported by a motor
   */
  rb_define_method(ph_advservo, "getAccelerationMax", ph_advservo_get_acceleration_max, 1);

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(index, acceleration)
   *
   * Sets the acceleration for a motor.
   */
  rb_define_method(ph_advservo, "setAcceleration", ph_advservo_set_acceleration, 2);

  /* Document-method: getVelocity
   * call-seq: getVelocity(index) -> velocity
   *
   * Gets the current velocity of a motor.
   */
  rb_define_method(ph_advservo, "getVelocity", ph_advservo_get_velocity, 1);

  /* Document-method: getVelocityMin
   * call-seq: getVelocityMin(index) -> min
   *
   * Gets the minimum velocity that can be set for a motor.
   */
  rb_define_method(ph_advservo, "getVelocityMin", ph_advservo_get_velocity_min, 1);

  /* Document-method: getVelocityMax
   * call-seq: getVelocityMax(index) -> max
   *
   * Gets the maximum velocity that can be set for a motor.
   */
  rb_define_method(ph_advservo, "getVelocityMax", ph_advservo_get_velocity_max, 1);

  /* Document-method: getVelocityLimit
   * call-seq: getVelocityLimit(index) -> limit
   *
   * Gets the last set velocity limit for a motor.
   */
  rb_define_method(ph_advservo, "getVelocityLimit", ph_advservo_get_velocity_limit, 1);

  /* Document-method: setVelocityLimit
   * call-seq: setVelocityLimit(index, limit)
   *
   * Sets the velocity limit for a motor.
   */
  rb_define_method(ph_advservo, "setVelocityLimit", ph_advservo_set_velocity_limit, 2);

  /* Document-method: getPosition
   * call-seq: getPosition(index) -> position
   *
   * Gets the current position of a motor.
   */
  rb_define_method(ph_advservo, "getPosition", ph_advservo_get_position, 1);

  /* Document-method: getPositionMin
   * call-seq: getPositionMin(index) -> min
   *
   * Gets the minimum position that a motor can go to.
   */
  rb_define_method(ph_advservo, "getPositionMin", ph_advservo_get_position_min, 1);

  /* Document-method: getPositionMax
   * call-seq: getPositionMax(index) -> max
   *
   * Gets the maximum position that a motor can go to.
   */
  rb_define_method(ph_advservo, "getPositionMax", ph_advservo_get_position_max, 1);

  /* Document-method: setPosition
   * call-seq: setPosition(index, position)
   *
   * Sets the position of a motor.
   */
  rb_define_method(ph_advservo, "setPosition", ph_advservo_set_position, 2);

  /* Document-method: setPositionMin
   * call-seq: setPositionMin(index, position)
   *
   * Sets the minimum position that a motor can go to.
   */
  rb_define_method(ph_advservo, "setPositionMin", ph_advservo_set_position_min, 2);

  /* Document-method: setPositionMax
   * call-seq: setPositionMax(index, position)
   *
   * Sets the maximum position that a motor can go to.
   */
  rb_define_method(ph_advservo, "setPositionMax", ph_advservo_set_position_max, 2);

  /* Document-method: getCurrent
   * call-seq: getCurrent(index)
   *
   * Gets the current current draw for a motor.
   */
  rb_define_method(ph_advservo, "getCurrent", ph_advservo_get_current, 1);

  /* Document-method: getSpeedRampingOn
   * call-seq: getSpeedRampingOn(index) -> true or false
   *
   * Gets the speed ramping state for a motor. This is whether or not velocity and acceleration are used.
   */
  rb_define_method(ph_advservo, "getSpeedRampingOn", ph_advservo_get_speed_ramping_on, 1);

  /* Document-method: setSpeedRampingOn
   * call-seq: setSpeedRampingOn(index, ramping_state)
   *
   * Sets the speed ramping state for a motor. This is whether or not velocity and acceleration are used.
   */
  rb_define_method(ph_advservo, "setSpeedRampingOn", ph_advservo_set_speed_ramping_on, 2);

  /* Document-method: getEngaged
   * call-seq: getEngaged(index) -> true or false
   *
   * Gets the engaged state of a motor. This is whether the motor is powered or not.
   */
  rb_define_method(ph_advservo, "getEngaged", ph_advservo_get_engaged, 1);

  /* Document-method: setEngaged
   * call-seq: setEngaged(index, engaged_state)
   *
   * Sets the engaged state of a motor. This is whether the motor is powered or not.
   */
  rb_define_method(ph_advservo, "setEngaged", ph_advservo_set_engaged, 2);

  /* Document-method: getStopped
   * call-seq: getStopped(index) -> true or false
   *
   * Gets the stopped state of a motor. This is true when the motor is not moving and there are no outstanding commands.
   */
  rb_define_method(ph_advservo, "getStopped", ph_advservo_get_stopped, 1);

  /* Document-method: getServoType
   * call-seq: getServoType(index) -> servo_type
   *
   * Gets the servo type of a motor.
   */
  rb_define_method(ph_advservo, "getServoType", ph_advservo_get_servo_type, 1);

  /* Document-method: setServoType
   * call-seq: setServoType(index, servo_type)
   *
   * Sets the servo type of a motor.
   */
  rb_define_method(ph_advservo, "setServoType", ph_advservo_set_servo_type, 2);

  /* Document-method: setServoParameters
   * call-seq: setServoParameters(index, min_us, max_us, degrees, velocity_max)
   *
   * Sets the servo parameters of a motor.
   */
  rb_define_method(ph_advservo, "setServoParameters", ph_advservo_set_servo_parameters, 5);

  rb_define_private_method(ph_advservo, "ext_setOnVelocityChangeHandler", ph_advservo_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_advservo, "ext_setOnPositionChangeHandler", ph_advservo_set_on_position_change_handler, 1);
  rb_define_private_method(ph_advservo, "ext_setOnCurrentChangeHandler", ph_advservo_set_on_current_change_handler, 1);

  rb_define_alias(ph_advservo, "motor_count", "getMotorCount");
  rb_define_alias(ph_advservo, "acceleration", "getAcceleration");
  rb_define_alias(ph_advservo, "acceleration_min", "getAccelerationMin");
  rb_define_alias(ph_advservo, "acceleration_max", "getAccelerationMax");
  rb_define_alias(ph_advservo, "set_acceleration", "setAcceleration");
  rb_define_alias(ph_advservo, "velocity", "getVelocity");
  rb_define_alias(ph_advservo, "velocity_min", "getVelocityMin");
  rb_define_alias(ph_advservo, "velocity_max", "getVelocityMax");
  rb_define_alias(ph_advservo, "velocity_limit", "getVelocityLimit");
  rb_define_alias(ph_advservo, "set_velocity_limit", "setVelocityLimit");
  rb_define_alias(ph_advservo, "position", "getPosition");
  rb_define_alias(ph_advservo, "position_min", "getPositionMin");
  rb_define_alias(ph_advservo, "position_max", "getPositionMax");
  rb_define_alias(ph_advservo, "set_position", "setPosition");
  rb_define_alias(ph_advservo, "set_position_min", "setPositionMin");
  rb_define_alias(ph_advservo, "set_position_max", "setPositionMax");
  rb_define_alias(ph_advservo, "current", "getCurrent");
  rb_define_alias(ph_advservo, "speed_ramping_on?", "getSpeedRampingOn");
  rb_define_alias(ph_advservo, "set_speed_ramping_on", "setSpeedRampingOn");
  rb_define_alias(ph_advservo, "engaged?", "getEngaged");
  rb_define_alias(ph_advservo, "set_engaged", "setEngaged");
  rb_define_alias(ph_advservo, "stopped?", "getStopped");
  rb_define_alias(ph_advservo, "servo_type", "getServoType");
  rb_define_alias(ph_advservo, "set_servo_type", "setServoType");
  rb_define_alias(ph_advservo, "set_servo_parameters", "setServoParameters");
}


VALUE ph_advservo_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetAdvancedServo_create((PhidgetAdvancedServoHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_advservo_get_motor_count(VALUE self) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  int count;
  ph_raise(PhidgetAdvancedServo_getMotorCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_advservo_get_acceleration(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double accel;
  ph_raise(PhidgetAdvancedServo_getAcceleration(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_advservo_get_acceleration_min(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double accel;
  ph_raise(PhidgetAdvancedServo_getAccelerationMin(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_advservo_get_acceleration_max(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double accel;
  ph_raise(PhidgetAdvancedServo_getAccelerationMax(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_advservo_set_acceleration(VALUE self, VALUE index, VALUE accel) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setAcceleration(handle, FIX2INT(index), NUM2DBL(accel)));
  return Qnil;
}

VALUE ph_advservo_get_velocity(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double velocity;
  ph_raise(PhidgetAdvancedServo_getVelocity(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_advservo_get_velocity_min(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double velocity;
  ph_raise(PhidgetAdvancedServo_getVelocityMin(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_advservo_get_velocity_max(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double velocity;
  ph_raise(PhidgetAdvancedServo_getVelocityMax(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_advservo_get_velocity_limit(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double velocity;
  ph_raise(PhidgetAdvancedServo_getVelocityLimit(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_advservo_set_velocity_limit(VALUE self, VALUE index, VALUE limit) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setVelocityLimit(handle, FIX2INT(index), NUM2DBL(limit)));
  return Qnil;
}

VALUE ph_advservo_get_position(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double position;
  ph_raise(PhidgetAdvancedServo_getPosition(handle, FIX2INT(index), &position));
  return rb_float_new(position);
}

VALUE ph_advservo_get_position_min(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double position;
  ph_raise(PhidgetAdvancedServo_getPositionMin(handle, FIX2INT(index), &position));
  return rb_float_new(position);
}

VALUE ph_advservo_get_position_max(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double position;
  ph_raise(PhidgetAdvancedServo_getPositionMax(handle, FIX2INT(index), &position));
  return rb_float_new(position);
}

VALUE ph_advservo_set_position(VALUE self, VALUE index, VALUE position) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setPosition(handle, FIX2INT(index), NUM2DBL(position)));
  return Qnil;
}

VALUE ph_advservo_set_position_min(VALUE self, VALUE index, VALUE min) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setPositionMin(handle, FIX2INT(index), NUM2DBL(min)));
  return Qnil;
}

VALUE ph_advservo_set_position_max(VALUE self, VALUE index, VALUE max) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setPositionMax(handle, FIX2INT(index), NUM2DBL(max)));
  return Qnil;
}

VALUE ph_advservo_get_current(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  double current;
  ph_raise(PhidgetAdvancedServo_getCurrent(handle, FIX2INT(index), &current));
  return rb_float_new(current);
}

VALUE ph_advservo_get_speed_ramping_on(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  int on;
  ph_raise(PhidgetAdvancedServo_getSpeedRampingOn(handle, FIX2INT(index), &on));
  return on == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_advservo_set_speed_ramping_on(VALUE self, VALUE index, VALUE state) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setSpeedRampingOn(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_advservo_get_engaged(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  int engaged;
  ph_raise(PhidgetAdvancedServo_getEngaged(handle, FIX2INT(index), &engaged));
  return engaged == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_advservo_set_engaged(VALUE self, VALUE index, VALUE state) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setEngaged(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_advservo_get_stopped(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  int stopped;
  ph_raise(PhidgetAdvancedServo_getStopped(handle, FIX2INT(index), &stopped));
  return stopped == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_advservo_get_servo_type(VALUE self, VALUE index) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  Phidget_ServoType type;
  ph_raise(PhidgetAdvancedServo_getServoType(handle, FIX2INT(index), &type));
  return INT2FIX(type);
}

VALUE ph_advservo_set_servo_type(VALUE self, VALUE index, VALUE type) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setServoType(handle, FIX2INT(index), (Phidget_ServoType)FIX2INT(type)));
  return Qnil;
}

VALUE ph_advservo_set_servo_parameters(VALUE self, VALUE index, VALUE min_us, VALUE max_us, VALUE degrees, VALUE velocity_max) {
  PhidgetAdvancedServoHandle handle = (PhidgetAdvancedServoHandle)get_ph_handle(self);
  ph_raise(PhidgetAdvancedServo_setServoParameters(handle, FIX2INT(index), NUM2DBL(min_us), NUM2DBL(max_us), NUM2DBL(degrees), NUM2DBL(velocity_max)));
  return Qnil;
}


VALUE ph_advservo_set_on_velocity_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetAdvancedServo_set_OnVelocityChange_Handler((PhidgetAdvancedServoHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetAdvancedServo_set_OnVelocityChange_Handler((PhidgetAdvancedServoHandle)ph->handle, ph_advservo_on_velocity_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_advservo_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetAdvancedServo_set_OnPositionChange_Handler((PhidgetAdvancedServoHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetAdvancedServo_set_OnPositionChange_Handler((PhidgetAdvancedServoHandle)ph->handle, ph_advservo_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_advservo_set_on_current_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_3;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetAdvancedServo_set_OnCurrentChange_Handler((PhidgetAdvancedServoHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetAdvancedServo_set_OnCurrentChange_Handler((PhidgetAdvancedServoHandle)ph->handle, ph_advservo_on_current_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_advservo_on_velocity_change(PhidgetAdvancedServoHandle phid, void *userPtr, int index, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_advservo_on_position_change(PhidgetAdvancedServoHandle phid, void *userPtr, int index, double position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_advservo_on_current_change(PhidgetAdvancedServoHandle phid, void *userPtr, int index, double current) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif
