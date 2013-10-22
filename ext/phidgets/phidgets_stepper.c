
#include "phidgets.h"


VALUE ph_stepper_init(VALUE self);
VALUE ph_stepper_get_input_count(VALUE self);
VALUE ph_stepper_get_input_state(VALUE self, VALUE index);
VALUE ph_stepper_get_motor_count(VALUE self);
VALUE ph_stepper_get_acceleration(VALUE self, VALUE index);
VALUE ph_stepper_get_acceleration_min(VALUE self, VALUE index);
VALUE ph_stepper_get_acceleration_max(VALUE self, VALUE index);
VALUE ph_stepper_set_acceleration(VALUE self, VALUE index, VALUE accel);
VALUE ph_stepper_get_velocity_limit(VALUE self, VALUE index);
VALUE ph_stepper_set_velocity_limit(VALUE self, VALUE index, VALUE limit);
VALUE ph_stepper_get_velocity(VALUE self, VALUE index);
VALUE ph_stepper_get_velocity_min(VALUE self, VALUE index);
VALUE ph_stepper_get_velocity_max(VALUE self, VALUE index);
VALUE ph_stepper_get_target_position(VALUE self, VALUE index);
VALUE ph_stepper_set_target_position(VALUE self, VALUE index, VALUE position);
VALUE ph_stepper_get_current_position(VALUE self, VALUE index);
VALUE ph_stepper_set_current_position(VALUE self, VALUE index, VALUE position);
VALUE ph_stepper_get_position_min(VALUE self, VALUE index);
VALUE ph_stepper_get_position_max(VALUE self, VALUE index);
VALUE ph_stepper_get_current_limit(VALUE self, VALUE index);
VALUE ph_stepper_set_current_limit(VALUE self, VALUE index, VALUE limit);
VALUE ph_stepper_get_current(VALUE self, VALUE index);
VALUE ph_stepper_get_current_min(VALUE self, VALUE index);
VALUE ph_stepper_get_current_max(VALUE self, VALUE index);
VALUE ph_stepper_get_engaged(VALUE self, VALUE index);
VALUE ph_stepper_set_engaged(VALUE self, VALUE index, VALUE state);
VALUE ph_stepper_get_stopped(VALUE self, VALUE index);

#ifdef PH_CALLBACK
VALUE ph_stepper_set_on_input_change_handler(VALUE self, VALUE handler);
VALUE ph_stepper_set_on_velocity_change_handler(VALUE self, VALUE handler);
VALUE ph_stepper_set_on_position_change_handler(VALUE self, VALUE handler);
VALUE ph_stepper_set_on_current_change_handler(VALUE self, VALUE handler);
int ph_stepper_on_input_change(CPhidgetStepperHandle phid, void *userPtr, int index, int state);
int ph_stepper_on_velocity_change(CPhidgetStepperHandle phid, void *userPtr, int index, double velocity);
int ph_stepper_on_position_change(CPhidgetStepperHandle phid, void *userPtr, int index, __int64 position);
int ph_stepper_on_current_change(CPhidgetStepperHandle phid, void *userPtr, int index, double current);
#endif


void Init_stepper() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_stepper = rb_define_class_under(ph_module, "Stepper", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Stepper object.
   */
  rb_define_method(ph_stepper, "initialize", ph_stepper_init, 0);

  /* Document-method: getInputCount
   * call-seq: getInputCount -> count
   *
   * Gets the number of digital inputs supported by this board.
   */
  rb_define_method(ph_stepper, "getInputCount", ph_stepper_get_input_count, 0);

  /* Document-method: getInputState
   * call-seq: getInputState(index) -> true or false
   *
   * Gets the state of a digital input.
   */
  rb_define_method(ph_stepper, "getInputState", ph_stepper_get_input_state, 1);

  /* Document-method: getMotorCount
   * call-seq: getMotorCount -> count
   *
   * Gets the number of motors supported by this controller
   */
  rb_define_method(ph_stepper, "getMotorCount", ph_stepper_get_motor_count, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration(index) -> acceleration
   *
   * Gets the last set acceleration for a motor.
   */
  rb_define_method(ph_stepper, "getAcceleration", ph_stepper_get_acceleration, 1);

  /* Document-method: getAccelerationMin
   * call-seq: getAccelerationMin(index) -> acceleration
   *
   * Gets the minimum acceleration supported by a motor.
   */
  rb_define_method(ph_stepper, "getAccelerationMin", ph_stepper_get_acceleration_min, 1);

  /* Document-method: getAccelerationMax
   * call-seq: getAccelerationMax(index) -> acceleration
   *
   * Gets the maximum acceleration supported by a motor.
   */
  rb_define_method(ph_stepper, "getAccelerationMax", ph_stepper_get_acceleration_max, 1);

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(index, acceleration)
   *
   * Sets the acceleration for a motor.
   */
  rb_define_method(ph_stepper, "setAcceleration", ph_stepper_set_acceleration, 2);

  /* Document-method: getVelocityLimit
   * call-seq: getVelocityLimit(index) -> velocity_limit
   *
   * Gets the last set velocity limit for a motor.
   */
  rb_define_method(ph_stepper, "getVelocityLimit", ph_stepper_get_velocity_limit, 1);

  /* Document-method: setVelocityLimit
   * call-seq: setVelocityLimit(index, velocity_limit)
   *
   * Sets the velocity limit for a motor.
   */
  rb_define_method(ph_stepper, "setVelocityLimit", ph_stepper_set_velocity_limit, 2);

  /* Document-method: getVelocity
   * call-seq: getVelocity(index) -> velocity
   *
   * Gets the current velocity of a motor.
   */
  rb_define_method(ph_stepper, "getVelocity", ph_stepper_get_velocity, 1);

  /* Document-method: getVelocityMin
   * call-seq: getVelocityMin(index) -> velocity
   *
   * Gets the minimum velocity that can be set for a motor.
   */
  rb_define_method(ph_stepper, "getVelocityMin", ph_stepper_get_velocity_min, 1);

  /* Document-method: getVelocityMax
   * call-seq: getVelocityMax(index) -> velocity
   *
   * Gets the maximum velocity that can be set for a motor.
   */
  rb_define_method(ph_stepper, "getVelocityMax", ph_stepper_get_velocity_max, 1);

  /* Document-method: getTargetPosition
   * call-seq: getTargetPosition(index) -> position
   *
   * Gets the last set target position of a motor.
   */
  rb_define_method(ph_stepper, "getTargetPosition", ph_stepper_get_target_position, 1);

  /* Document-method: setTargetPosition
   * call-seq: setTargetPosition(index, position)
   *
   * Sets the target position of a motor.
   */
  rb_define_method(ph_stepper, "setTargetPosition", ph_stepper_set_target_position, 2);

  /* Document-method: getCurrentPosition
   * call-seq: getCurrentPosition(index) -> position
   *
   * Gets the current position of a motor.
   */
  rb_define_method(ph_stepper, "getCurrentPosition", ph_stepper_get_current_position, 1);

  /* Document-method: setCurrentPosition
   * call-seq: setCurrentPosition(index, position)
   *
   * Sets the current position of a motor. This will not move the motor, just update the position value.
   */
  rb_define_method(ph_stepper, "setCurrentPosition", ph_stepper_set_current_position, 2);

  /* Document-method: getPositionMin
   * call-seq: getPositionMin(index) -> position
   *
   * Gets the minimum position that a motor can go to.
   */
  rb_define_method(ph_stepper, "getPositionMin", ph_stepper_get_position_min, 1);

  /* Document-method: getPositionMax
   * call-seq: getPositionMax(index) -> position
   *
   * Gets the maximum position that a motor can go to.
   */
  rb_define_method(ph_stepper, "getPositionMax", ph_stepper_get_position_max, 1);

  /* Document-method: getCurrentLimit
   * call-seq: getCurrentLimit(index) -> limit
   *
   * Gets the current limit for a motor.
   */
  rb_define_method(ph_stepper, "getCurrentLimit", ph_stepper_get_current_limit, 1);

  /* Document-method: setCurrentLimit
   * call-seq: setCurrentLimit(index, limit)
   *
   * Sets the current limit for a motor.
   */
  rb_define_method(ph_stepper, "setCurrentLimit", ph_stepper_set_current_limit, 2);

  /* Document-method: getCurrent
   * call-seq: getCurrent(index) -> current
   *
   * Gets the current current draw for a motor.
   */
  rb_define_method(ph_stepper, "getCurrent", ph_stepper_get_current, 1);

  /* Document-method: getCurrentMin
   * call-seq: getCurrentMin(index) -> current
   *
   * Gets the minimum current limit.
   */
  rb_define_method(ph_stepper, "getCurrentMin", ph_stepper_get_current_min, 1);

  /* Document-method: getCurrentMax
   * call-seq: getCurrentMax(index) -> current
   *
   * Gets the maximum current limit.
   */
  rb_define_method(ph_stepper, "getCurrentMax", ph_stepper_get_current_max, 1);

  /* Document-method: getEngaged
   * call-seq: getEngaged(index) -> true or false
   *
   * Gets the engaged state of a motor. This is whether the motor is powered or not.
   */
  rb_define_method(ph_stepper, "getEngaged", ph_stepper_get_engaged, 1);

  /* Document-method: setEngaged
   * call-seq: setEngaged(index, state)
   *
   * Sets the engaged state of a motor. This is whether the motor is powered or not.
   */
  rb_define_method(ph_stepper, "setEngaged", ph_stepper_set_engaged, 2);

  /* Document-method: getStopped
   * call-seq: getStopped(index) -> true or false
   *
   * Gets the stopped state of a motor. This is true when the motor is not moving and there are no outstanding commands.
   */
  rb_define_method(ph_stepper, "getStopped", ph_stepper_get_stopped, 1);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_stepper, "ext_setOnInputChangeHandler", ph_stepper_set_on_input_change_handler, 1);
  rb_define_private_method(ph_stepper, "ext_setOnVelocityChangeHandler", ph_stepper_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_stepper, "ext_setOnPositionChangeHandler", ph_stepper_set_on_position_change_handler, 1);
  rb_define_private_method(ph_stepper, "ext_setOnCurrentChangeHandler", ph_stepper_set_on_current_change_handler, 1);
#endif

  rb_define_alias(ph_stepper, "input_count", "getInputCount");
  rb_define_alias(ph_stepper, "input_state", "getInputState");
  rb_define_alias(ph_stepper, "motor_count", "getMotorCount");
  rb_define_alias(ph_stepper, "acceleration", "getAcceleration");
  rb_define_alias(ph_stepper, "acceleration_min", "getAccelerationMin");
  rb_define_alias(ph_stepper, "acceleration_max", "getAccelerationMax");
  rb_define_alias(ph_stepper, "set_acceleration", "setAcceleration");
  rb_define_alias(ph_stepper, "velocity_limit", "getVelocityLimit");
  rb_define_alias(ph_stepper, "set_velocity_limit", "setVelocityLimit");
  rb_define_alias(ph_stepper, "velocity", "getVelocity");
  rb_define_alias(ph_stepper, "velocity_min", "getVelocityMin");
  rb_define_alias(ph_stepper, "velocity_max", "getVelocityMax");
  rb_define_alias(ph_stepper, "target_position", "getTargetPosition");
  rb_define_alias(ph_stepper, "set_target_position", "setTargetPosition");
  rb_define_alias(ph_stepper, "current_position", "getCurrentPosition");
  rb_define_alias(ph_stepper, "set_current_position", "setCurrentPosition");
  rb_define_alias(ph_stepper, "position_min", "getPositionMin");
  rb_define_alias(ph_stepper, "position_max", "getPositionMax");
  rb_define_alias(ph_stepper, "current_limit", "getCurrentLimit");
  rb_define_alias(ph_stepper, "set_current_limit", "setCurrentLimit");
  rb_define_alias(ph_stepper, "current", "getCurrent");
  rb_define_alias(ph_stepper, "current_min", "getCurrentMin");
  rb_define_alias(ph_stepper, "current_max", "getCurrentMax");
  rb_define_alias(ph_stepper, "engaged?", "getEngaged");
  rb_define_alias(ph_stepper, "set_engaged", "setEngaged");
  rb_define_alias(ph_stepper, "stopped?", "getStopped");
}



VALUE ph_stepper_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetStepper_create((CPhidgetStepperHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_stepper_get_input_count(VALUE self) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetStepper_getInputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_stepper_get_input_state(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetStepper_getInputState(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_stepper_get_motor_count(VALUE self) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetStepper_getMotorCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_stepper_get_acceleration(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetStepper_getAcceleration(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_stepper_get_acceleration_min(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetStepper_getAccelerationMin(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_stepper_get_acceleration_max(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetStepper_getAccelerationMax(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_stepper_set_acceleration(VALUE self, VALUE index, VALUE accel) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  ph_raise(CPhidgetStepper_setAcceleration(handle, FIX2INT(index), NUM2DBL(accel)));
  return Qnil;
}

VALUE ph_stepper_get_velocity_limit(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double limit;
  ph_raise(CPhidgetStepper_getVelocityLimit(handle, FIX2INT(index), &limit));
  return rb_float_new(limit);
}

VALUE ph_stepper_set_velocity_limit(VALUE self, VALUE index, VALUE limit) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  ph_raise(CPhidgetStepper_setVelocityLimit(handle, FIX2INT(index), NUM2DBL(limit)));
  return Qnil;
}

VALUE ph_stepper_get_velocity(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double velocity;
  ph_raise(CPhidgetStepper_getVelocity(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_stepper_get_velocity_min(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double velocity;
  ph_raise(CPhidgetStepper_getVelocityMin(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_stepper_get_velocity_max(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double velocity;
  ph_raise(CPhidgetStepper_getVelocityMax(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_stepper_get_target_position(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  __int64 position;
  ph_raise(CPhidgetStepper_getTargetPosition(handle, FIX2INT(index), &position));
  return INT2NUM(position);
}

VALUE ph_stepper_set_target_position(VALUE self, VALUE index, VALUE position) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  ph_raise(CPhidgetStepper_setTargetPosition(handle, FIX2INT(index), NUM2INT(position)));
  return Qnil;
}

VALUE ph_stepper_get_current_position(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  __int64 position;
  ph_raise(CPhidgetStepper_getCurrentPosition(handle, FIX2INT(index), &position));
  return INT2NUM(position);
}

VALUE ph_stepper_set_current_position(VALUE self, VALUE index, VALUE position) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  ph_raise(CPhidgetStepper_setCurrentPosition(handle, FIX2INT(index), NUM2INT(position)));
  return Qnil;
}

VALUE ph_stepper_get_position_min(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  __int64 position;
  ph_raise(CPhidgetStepper_getPositionMin(handle, FIX2INT(index), &position));
  return INT2NUM(position);
}

VALUE ph_stepper_get_position_max(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  __int64 position;
  ph_raise(CPhidgetStepper_getPositionMax(handle, FIX2INT(index), &position));
  return INT2NUM(position);
}

VALUE ph_stepper_get_current_limit(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double current;
  ph_raise(CPhidgetStepper_getCurrentLimit(handle, FIX2INT(index), &current));
  return rb_float_new(current);
}

VALUE ph_stepper_set_current_limit(VALUE self, VALUE index, VALUE limit) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  ph_raise(CPhidgetStepper_setCurrentLimit(handle, FIX2INT(index), NUM2DBL(limit)));
  return Qnil;
}

VALUE ph_stepper_get_current(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double current;
  ph_raise(CPhidgetStepper_getCurrent(handle, FIX2INT(index), &current));
  return rb_float_new(current);
}

VALUE ph_stepper_get_current_min(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double current;
  ph_raise(CPhidgetStepper_getCurrentMin(handle, FIX2INT(index), &current));
  return rb_float_new(current);
}

VALUE ph_stepper_get_current_max(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  double current;
  ph_raise(CPhidgetStepper_getCurrentMax(handle, FIX2INT(index), &current));
  return rb_float_new(current);
}

VALUE ph_stepper_get_engaged(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetStepper_getEngaged(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_stepper_set_engaged(VALUE self, VALUE index, VALUE state) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  ph_raise(CPhidgetStepper_setEngaged(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_stepper_get_stopped(VALUE self, VALUE index) {
  CPhidgetStepperHandle handle = (CPhidgetStepperHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetStepper_getStopped(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}


#ifdef PH_CALLBACK
VALUE ph_stepper_set_on_input_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetStepper_set_OnInputChange_Handler((CPhidgetStepperHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetStepper_set_OnInputChange_Handler((CPhidgetStepperHandle)ph->handle, ph_stepper_on_input_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_stepper_set_on_velocity_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetStepper_set_OnVelocityChange_Handler((CPhidgetStepperHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetStepper_set_OnVelocityChange_Handler((CPhidgetStepperHandle)ph->handle, ph_stepper_on_velocity_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_stepper_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_3;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetStepper_set_OnPositionChange_Handler((CPhidgetStepperHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetStepper_set_OnPositionChange_Handler((CPhidgetStepperHandle)ph->handle, ph_stepper_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_stepper_set_on_current_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_4;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetStepper_set_OnCurrentChange_Handler((CPhidgetStepperHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetStepper_set_OnCurrentChange_Handler((CPhidgetStepperHandle)ph->handle, ph_stepper_on_current_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_stepper_on_input_change(CPhidgetStepperHandle phid, void *userPtr, int index, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_stepper_on_velocity_change(CPhidgetStepperHandle phid, void *userPtr, int index, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_stepper_on_position_change(CPhidgetStepperHandle phid, void *userPtr, int index, __int64 position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_stepper_on_current_change(CPhidgetStepperHandle phid, void *userPtr, int index, double current) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

