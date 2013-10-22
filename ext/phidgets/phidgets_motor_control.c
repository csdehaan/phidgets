
#include "phidgets.h"


VALUE ph_motor_init(VALUE self);
VALUE ph_motor_get_motor_count(VALUE self);
VALUE ph_motor_get_velocity(VALUE self, VALUE index);
VALUE ph_motor_set_velocity(VALUE self, VALUE index, VALUE velocity);
VALUE ph_motor_get_acceleration(VALUE self, VALUE index);
VALUE ph_motor_get_acceleration_min(VALUE self, VALUE index);
VALUE ph_motor_get_acceleration_max(VALUE self, VALUE index);
VALUE ph_motor_set_acceleration(VALUE self, VALUE index, VALUE accel);
VALUE ph_motor_get_current(VALUE self, VALUE index);
VALUE ph_motor_get_input_count(VALUE self);
VALUE ph_motor_get_input_state(VALUE self, VALUE index);
VALUE ph_motor_get_encoder_count(VALUE self);
VALUE ph_motor_get_encoder_position(VALUE self, VALUE index);
VALUE ph_motor_set_encoder_position(VALUE self, VALUE index, VALUE position);
VALUE ph_motor_get_back_emf(VALUE self, VALUE index);
VALUE ph_motor_get_back_emf_sensing_state(VALUE self, VALUE index);
VALUE ph_motor_set_back_emf_sensing_state(VALUE self, VALUE index, VALUE state);
VALUE ph_motor_get_supply_voltage(VALUE self);
VALUE ph_motor_get_braking(VALUE self, VALUE index);
VALUE ph_motor_set_braking(VALUE self, VALUE index, VALUE braking);
VALUE ph_motor_get_sensor_count(VALUE self);
VALUE ph_motor_get_sensor_value(VALUE self, VALUE index);
VALUE ph_motor_get_sensor_raw_value(VALUE self, VALUE index);
VALUE ph_motor_get_ratiometric(VALUE self);
VALUE ph_motor_set_ratiometric(VALUE self, VALUE ratiometric);

#ifdef PH_CALLBACK
VALUE ph_motor_set_on_velocity_change_handler(VALUE self, VALUE handler);
VALUE ph_motor_set_on_current_change_handler(VALUE self, VALUE handler);
VALUE ph_motor_set_on_current_update_handler(VALUE self, VALUE handler);
VALUE ph_motor_set_on_input_change_handler(VALUE self, VALUE handler);
VALUE ph_motor_set_on_encoder_position_change_handler(VALUE self, VALUE handler);
VALUE ph_motor_set_on_encoder_position_update_handler(VALUE self, VALUE handler);
VALUE ph_motor_set_on_back_emf_update_handler(VALUE self, VALUE handler);
VALUE ph_motor_set_on_sensor_update_handler(VALUE self, VALUE handler);
int ph_motor_on_velocity_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, double velocity);
int ph_motor_on_current_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, double current);
int ph_motor_on_current_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, double current);
int ph_motor_on_input_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, int state);
int ph_motor_on_encoder_position_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, int time, int change);
int ph_motor_on_encoder_position_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, int change);
int ph_motor_on_back_emf_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, double voltage);
int ph_motor_on_sensor_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, int value);
#endif


void Init_motor_control() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_motor = rb_define_class_under(ph_module, "MotorControl", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget MotorControl object.
   */
  rb_define_method(ph_motor, "initialize", ph_motor_init, 0);

  /* Document-method: getMotorCount
   * call-seq: getMotorCount -> count
   *
   * Gets the number of motors supported by this controller.
   */
  rb_define_method(ph_motor, "getMotorCount", ph_motor_get_motor_count, 0);

  /* Document-method: getVelocity
   * call-seq: getVelocity(index) -> velocity
   *
   * Gets the current velocity of a motor.
   */
  rb_define_method(ph_motor, "getVelocity", ph_motor_get_velocity, 1);

  /* Document-method: setVelocity
   * call-seq: setVelocity(index, velocity)
   *
   * Sets the velocity of a motor.
   */
  rb_define_method(ph_motor, "setVelocity", ph_motor_set_velocity, 2);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration(index) -> acceleration
   *
   * Gets the last set acceleration of a motor.
   */
  rb_define_method(ph_motor, "getAcceleration", ph_motor_get_acceleration, 1);

  /* Document-method: getAccelerationMin
   * call-seq: getAccelerationMin(index) -> acceleration
   *
   * Gets the minimum acceleration supported by a motor.
   */
  rb_define_method(ph_motor, "getAccelerationMin", ph_motor_get_acceleration_min, 1);

  /* Document-method: getAccelerationMax
   * call-seq: getAccelerationMax(index) -> acceleration
   *
   * Gets the maximum acceleration supported by a motor
   */
  rb_define_method(ph_motor, "getAccelerationMax", ph_motor_get_acceleration_max, 1);

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(index, acceleration)
   *
   * Sets the acceleration of a motor.
   */
  rb_define_method(ph_motor, "setAcceleration", ph_motor_set_acceleration, 2);

  /* Document-method: getCurrent
   * call-seq: getCurrent(index) -> current
   *
   * Gets the current current draw for a motor.
   */
  rb_define_method(ph_motor, "getCurrent", ph_motor_get_current, 1);

  /* Document-method: getInputCount
   * call-seq: getInputCount -> count
   *
   * Gets the number of digital inputs supported by this board.
   */
  rb_define_method(ph_motor, "getInputCount", ph_motor_get_input_count, 0);

  /* Document-method: getInputState
   * call-seq: getInputState(index) -> true or false
   *
   * Gets the state of a digital input.
   */
  rb_define_method(ph_motor, "getInputState", ph_motor_get_input_state, 1);

  /* Document-method: getEncoderCount
   * call-seq: getEncoderCount -> count
   *
   * Gets the number of encoder inputs supported by this board.
   */
  rb_define_method(ph_motor, "getEncoderCount", ph_motor_get_encoder_count, 0);

  /* Document-method: getEncoderPosition
   * call-seq: getEncoderPosition(index) -> position
   *
   * Gets the position of an encoder. This position starts at 0 every time the phidget is opened.
   */
  rb_define_method(ph_motor, "getEncoderPosition", ph_motor_get_encoder_position, 1);

  /* Document-method: setEncoderPosition
   * call-seq: setEncoderPosition(index, position)
   *
   * Sets the encoder position. This can be used to set the position to a known value,
   * and should only be called when the encoder is not moving.
   */
  rb_define_method(ph_motor, "setEncoderPosition", ph_motor_set_encoder_position, 2);

  /* Document-method: getBackEMF
   * call-seq: getBackEMF(index) -> voltage
   *
   * Gets the Back EMF voltage for a motor.
   */
  rb_define_method(ph_motor, "getBackEMF", ph_motor_get_back_emf, 1);

  /* Document-method: getBackEMFSensingState
   * call-seq: getBackEMFSensingState(index) -> true or false
   *
   * Gets the Back EMF sensing state for a motor.
   */
  rb_define_method(ph_motor, "getBackEMFSensingState", ph_motor_get_back_emf_sensing_state, 1);

  /* Document-method: setBackEMFSensingState
   * call-seq: setBackEMFSensingState(index, state)
   *
   * Sets the Back EMF sensing state for a motor.
   */
  rb_define_method(ph_motor, "setBackEMFSensingState", ph_motor_set_back_emf_sensing_state, 2);

  /* Document-method: getSupplyVoltage
   * call-seq: getSupplyVoltage -> voltage
   *
   * Gets the Supply voltage for the motors. This could be higher then the actual supply voltage.
   */
  rb_define_method(ph_motor, "getSupplyVoltage", ph_motor_get_supply_voltage, 0);

  /* Document-method: getBraking
   * call-seq: getBraking(index) -> braking
   *
   * Gets the Braking value for a motor.
   */
  rb_define_method(ph_motor, "getBraking", ph_motor_get_braking, 1);

  /* Document-method: setBraking
   * call-seq: setBraking(index, braking)
   *
   * Sets the Braking value for a motor. This is applied when velocity is 0. Default is 0%.
   */
  rb_define_method(ph_motor, "setBraking", ph_motor_set_braking, 2);

  /* Document-method: getSensorCount
   * call-seq: getSensorCount -> count
   *
   * Gets the number of sensor inputs supported by this board.
   */
  rb_define_method(ph_motor, "getSensorCount", ph_motor_get_sensor_count, 0);

  /* Document-method: getSensorValue
   * call-seq: getSensorValue(index) -> value
   *
   * Gets the value of a sensor.
   */
  rb_define_method(ph_motor, "getSensorValue", ph_motor_get_sensor_value, 1);

  /* Document-method: getSensorRawValue
   * call-seq: getSensorRawValue(index) -> value
   *
   * Gets the raw value of a sensor (12-bit).
   */
  rb_define_method(ph_motor, "getSensorRawValue", ph_motor_get_sensor_raw_value, 1);

  /* Document-method: getRatiometric
   * call-seq: getRatiometric -> true or false
   *
   * Gets the ratiometric state.
   */
  rb_define_method(ph_motor, "getRatiometric", ph_motor_get_ratiometric, 0);

  /* Document-method: setRatiometric
   * call-seq: setRatiometric(state)
   *
   * Sets the ratiometric state. This controls the voltage reference used for sampling the analog sensors.
   */
  rb_define_method(ph_motor, "setRatiometric", ph_motor_set_ratiometric, 1);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_motor, "ext_setOnVelocityChangeHandler", ph_motor_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnCurrentChangeHandler", ph_motor_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnCurrentUpdateHandler", ph_motor_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnInputChangeHandler", ph_motor_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnEncoderPositionChangeHandler", ph_motor_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnEncoderPositionUpdateHandler", ph_motor_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnBackEMFUpdateHandler", ph_motor_set_on_velocity_change_handler, 1);
  rb_define_private_method(ph_motor, "ext_setOnSensorUpdateHandler", ph_motor_set_on_velocity_change_handler, 1);
#endif

  rb_define_alias(ph_motor, "motor_count", "getMotorCount");
  rb_define_alias(ph_motor, "velocity", "getVelocity");
  rb_define_alias(ph_motor, "set_velocity", "setVelocity");
  rb_define_alias(ph_motor, "acceleration", "getAcceleration");
  rb_define_alias(ph_motor, "acceleration_min", "getAccelerationMin");
  rb_define_alias(ph_motor, "acceleration_max", "getAccelerationMax");
  rb_define_alias(ph_motor, "set_acceleration", "setAcceleration");
  rb_define_alias(ph_motor, "current", "getCurrent");
  rb_define_alias(ph_motor, "input_count", "getInputCount");
  rb_define_alias(ph_motor, "input_state", "getInputState");
  rb_define_alias(ph_motor, "encoder_count", "getEncoderCount");
  rb_define_alias(ph_motor, "encoder_position", "getEncoderPosition");
  rb_define_alias(ph_motor, "set_encoder_position", "setEncoderPosition");
  rb_define_alias(ph_motor, "back_emf", "getBackEMF");
  rb_define_alias(ph_motor, "back_emf_sensing_state", "getBackEMFSensingState");
  rb_define_alias(ph_motor, "set_back_emf_sensing_state", "setBackEMFSensingState");
  rb_define_alias(ph_motor, "supply_voltage", "getSupplyVoltage");
  rb_define_alias(ph_motor, "braking", "getBraking");
  rb_define_alias(ph_motor, "set_braking", "setBraking");
  rb_define_alias(ph_motor, "sensor_count", "getSensorCount");
  rb_define_alias(ph_motor, "sensor_value", "getSensorValue");
  rb_define_alias(ph_motor, "sensor_raw_value", "getSensorRawValue");
  rb_define_alias(ph_motor, "ratiometric?", "getRatiometric");
  rb_define_alias(ph_motor, "ratiometric=", "setRatiometric");
}



VALUE ph_motor_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetMotorControl_create((CPhidgetMotorControlHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_motor_get_motor_count(VALUE self) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetMotorControl_getMotorCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_motor_get_velocity(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double velocity;
  ph_raise(CPhidgetMotorControl_getVelocity(handle, FIX2INT(index), &velocity));
  return rb_float_new(velocity);
}

VALUE ph_motor_set_velocity(VALUE self, VALUE index, VALUE velocity) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  ph_raise(CPhidgetMotorControl_setVelocity(handle, FIX2INT(index), NUM2DBL(velocity)));
  return Qnil;
}

VALUE ph_motor_get_acceleration(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetMotorControl_getAcceleration(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_motor_get_acceleration_min(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetMotorControl_getAccelerationMin(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_motor_get_acceleration_max(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double accel;
  ph_raise(CPhidgetMotorControl_getAccelerationMax(handle, FIX2INT(index), &accel));
  return rb_float_new(accel);
}

VALUE ph_motor_set_acceleration(VALUE self, VALUE index, VALUE accel) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  ph_raise(CPhidgetMotorControl_setAcceleration(handle, FIX2INT(index), NUM2DBL(accel)));
  return Qnil;
}

VALUE ph_motor_get_current(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double current;
  ph_raise(CPhidgetMotorControl_getCurrent(handle, FIX2INT(index), &current));
  return rb_float_new(current);
}

VALUE ph_motor_get_input_count(VALUE self) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetMotorControl_getInputCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_motor_get_input_state(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetMotorControl_getInputState(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_motor_get_encoder_count(VALUE self) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetMotorControl_getEncoderCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_motor_get_encoder_position(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int position;
  ph_raise(CPhidgetMotorControl_getEncoderPosition(handle, FIX2INT(index), &position));
  return INT2FIX(position);
}

VALUE ph_motor_set_encoder_position(VALUE self, VALUE index, VALUE position) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  ph_raise(CPhidgetMotorControl_setEncoderPosition(handle, FIX2INT(index), FIX2INT(position)));
  return Qnil;
}

VALUE ph_motor_get_back_emf(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double voltage;
  ph_raise(CPhidgetMotorControl_getBackEMF(handle, FIX2INT(index), &voltage));
  return rb_float_new(voltage);
}

VALUE ph_motor_get_back_emf_sensing_state(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetMotorControl_getBackEMFSensingState(handle, FIX2INT(index), &state));
  return state == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_motor_set_back_emf_sensing_state(VALUE self, VALUE index, VALUE state) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  ph_raise(CPhidgetMotorControl_setBackEMFSensingState(handle, FIX2INT(index), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_motor_get_supply_voltage(VALUE self) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double voltage;
  ph_raise(CPhidgetMotorControl_getSupplyVoltage(handle, &voltage));
  return rb_float_new(voltage);
}

VALUE ph_motor_get_braking(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  double braking;
  ph_raise(CPhidgetMotorControl_getBraking(handle, FIX2INT(index), &braking));
  return rb_float_new(braking);
}

VALUE ph_motor_set_braking(VALUE self, VALUE index, VALUE braking) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  ph_raise(CPhidgetMotorControl_setBraking(handle, FIX2INT(index), NUM2DBL(braking)));
  return Qnil;
}

VALUE ph_motor_get_sensor_count(VALUE self) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetMotorControl_getSensorCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_motor_get_sensor_value(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetMotorControl_getSensorValue(handle, FIX2INT(index), &value));
  return INT2FIX(value);
}

VALUE ph_motor_get_sensor_raw_value(VALUE self, VALUE index) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int value;
  ph_raise(CPhidgetMotorControl_getSensorRawValue(handle, FIX2INT(index), &value));
  return INT2FIX(value);
}

VALUE ph_motor_get_ratiometric(VALUE self) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  int ratiometric;
  ph_raise(CPhidgetMotorControl_getRatiometric(handle, &ratiometric));
  return ratiometric == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_motor_set_ratiometric(VALUE self, VALUE ratiometric) {
  CPhidgetMotorControlHandle handle = (CPhidgetMotorControlHandle)get_ph_handle(self);
  ph_raise(CPhidgetMotorControl_setRatiometric(handle, TYPE(ratiometric) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}



#ifdef PH_CALLBACK
VALUE ph_motor_set_on_velocity_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnVelocityChange_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnVelocityChange_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_velocity_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_motor_set_on_current_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnCurrentChange_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnCurrentChange_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_current_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_motor_set_on_current_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_3;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnCurrentUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnCurrentUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_current_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_motor_set_on_input_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_4;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnInputChange_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnInputChange_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_input_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_motor_set_on_encoder_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_5;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnEncoderPositionChange_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnEncoderPositionChange_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_encoder_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_motor_set_on_encoder_position_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_6;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnEncoderPositionUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnEncoderPositionUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_encoder_position_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_motor_set_on_back_emf_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_7;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnBackEMFUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnBackEMFUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_back_emf_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_motor_set_on_sensor_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_8;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetMotorControl_set_OnSensorUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetMotorControl_set_OnSensorUpdate_Handler((CPhidgetMotorControlHandle)ph->handle, ph_motor_on_sensor_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_motor_on_velocity_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_motor_on_current_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, double current) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_motor_on_current_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, double current) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_motor_on_input_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_motor_on_encoder_position_change(CPhidgetMotorControlHandle phid, void *userPtr, int index, int time, int change) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_motor_on_encoder_position_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, int change) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_motor_on_back_emf_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, double voltage) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_motor_on_sensor_update(CPhidgetMotorControlHandle phid, void *userPtr, int index, int value) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

