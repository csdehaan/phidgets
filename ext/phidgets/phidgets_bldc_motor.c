
#include "phidgets.h"

#define BLDC_MOTOR_BRAKING_STRENGTH_CHANGE_CALLBACK  0
#define BLDC_MOTOR_POSITION_CHANGE_CALLBACK          1
#define BLDC_MOTOR_VELOCITY_UPDATE_CALLBACK          2


VALUE ph_bldc_motor_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetBLDCMotor_create((PhidgetBLDCMotorHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_bldc_motor_get_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getAcceleration);
}

VALUE ph_bldc_motor_set_acceleration(VALUE self, VALUE accel) {
  ph_raise(PhidgetBLDCMotor_setAcceleration((PhidgetBLDCMotorHandle)get_ph_handle(self), NUM2DBL(accel)));
  return Qnil;
}

VALUE ph_bldc_motor_get_min_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMinAcceleration);
}

VALUE ph_bldc_motor_get_max_acceleration(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMaxAcceleration);
}

VALUE ph_bldc_motor_get_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getBrakingStrength);
}

VALUE ph_bldc_motor_get_min_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMinBrakingStrength);
}

VALUE ph_bldc_motor_get_max_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMaxBrakingStrength);
}

VALUE ph_bldc_motor_get_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetBLDCMotor_getDataInterval);
}

VALUE ph_bldc_motor_set_data_interval(VALUE self, VALUE interval) {
  ph_raise(PhidgetBLDCMotor_setDataInterval((PhidgetBLDCMotorHandle)get_ph_handle(self), NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_bldc_motor_get_min_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetBLDCMotor_getMinDataInterval);
}

VALUE ph_bldc_motor_get_max_data_interval(VALUE self) {
  return ph_get_uint(get_ph_handle(self), (phidget_get_uint_func)PhidgetBLDCMotor_getMaxDataInterval);
}

VALUE ph_bldc_motor_get_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getPosition);
}

VALUE ph_bldc_motor_get_min_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMinPosition);
}

VALUE ph_bldc_motor_get_max_position(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMaxPosition);
}

VALUE ph_bldc_motor_add_position_offset(VALUE self, VALUE offset) {
  ph_raise(PhidgetBLDCMotor_addPositionOffset((PhidgetBLDCMotorHandle)get_ph_handle(self), NUM2DBL(offset)));
  return Qnil;
}

VALUE ph_bldc_motor_get_rescale_factor(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getRescaleFactor);
}

VALUE ph_bldc_motor_set_rescale_factor(VALUE self, VALUE rescale_factor) {
  ph_raise(PhidgetBLDCMotor_setRescaleFactor((PhidgetBLDCMotorHandle)get_ph_handle(self), NUM2DBL(rescale_factor)));
  return Qnil;
}

VALUE ph_bldc_motor_get_stall_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getStallVelocity);
}

VALUE ph_bldc_motor_set_stall_velocity(VALUE self, VALUE stall_velocity) {
  ph_raise(PhidgetBLDCMotor_setStallVelocity((PhidgetBLDCMotorHandle)get_ph_handle(self), NUM2DBL(stall_velocity)));
  return Qnil;
}

VALUE ph_bldc_motor_get_min_stall_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMinStallVelocity);
}

VALUE ph_bldc_motor_get_max_stall_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMaxStallVelocity);
}

VALUE ph_bldc_motor_get_target_braking_strength(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getTargetBrakingStrength);
}

VALUE ph_bldc_motor_set_target_braking_strength(VALUE self, VALUE target_braking_strength) {
  ph_raise(PhidgetBLDCMotor_setTargetBrakingStrength((PhidgetBLDCMotorHandle)get_ph_handle(self), NUM2DBL(target_braking_strength)));
  return Qnil;
}

VALUE ph_bldc_motor_get_target_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getTargetVelocity);
}

VALUE ph_bldc_motor_set_target_velocity(VALUE self, VALUE target_velocity) {
  ph_raise(PhidgetBLDCMotor_setTargetVelocity((PhidgetBLDCMotorHandle)get_ph_handle(self), NUM2DBL(target_velocity)));
  return Qnil;
}

VALUE ph_bldc_motor_get_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getVelocity);
}

VALUE ph_bldc_motor_get_min_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMinVelocity);
}

VALUE ph_bldc_motor_get_max_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), (phidget_get_double_func)PhidgetBLDCMotor_getMaxVelocity);
}


void CCONV ph_bldc_motor_on_braking_strength_change(PhidgetBLDCMotorHandle phid, void *userPtr, double braking_strength) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(braking_strength);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_bldc_motor_set_on_braking_strength_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[BLDC_MOTOR_BRAKING_STRENGTH_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetBLDCMotor_setOnBrakingStrengthChangeHandler((PhidgetBLDCMotorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetBLDCMotor_setOnBrakingStrengthChangeHandler((PhidgetBLDCMotorHandle)ph->handle, ph_bldc_motor_on_braking_strength_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_bldc_motor_on_position_change(PhidgetBLDCMotorHandle phid, void *userPtr, double position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(position);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_bldc_motor_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[BLDC_MOTOR_POSITION_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetBLDCMotor_setOnPositionChangeHandler((PhidgetBLDCMotorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetBLDCMotor_setOnPositionChangeHandler((PhidgetBLDCMotorHandle)ph->handle, ph_bldc_motor_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_bldc_motor_on_velocity_update(PhidgetBLDCMotorHandle phid, void *userPtr, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(velocity);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_bldc_motor_set_on_velocity_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[BLDC_MOTOR_VELOCITY_UPDATE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetBLDCMotor_setOnVelocityUpdateHandler((PhidgetBLDCMotorHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetBLDCMotor_setOnVelocityUpdateHandler((PhidgetBLDCMotorHandle)ph->handle, ph_bldc_motor_on_velocity_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}



void Init_bldc_motor() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_bldc_motor = rb_define_class_under(ph_module, "BLDCMotor", ph_common);



  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget BLDCMotor object.
   */
  rb_define_method(ph_bldc_motor, "initialize", ph_bldc_motor_init, 0);

  /* Document-method: getAcceleration
   * call-seq: getAcceleration -> acceleration
   *
   * The rate at which the controller can change the motor's Velocity.
   * The acceleration is bounded by MinAccleration and MaxAcceleration.
   */
  rb_define_method(ph_bldc_motor, "getAcceleration", ph_bldc_motor_get_acceleration, 0);
  rb_define_alias(ph_bldc_motor, "acceleration", "getAcceleration");

  /* Document-method: setAcceleration
   * call-seq: setAcceleration(acceleration)
   *
   * The rate at which the controller can change the motor's Velocity.
   * The acceleration is bounded by MinAccleration and MaxAcceleration.
   */
  rb_define_method(ph_bldc_motor, "setAcceleration", ph_bldc_motor_set_acceleration, 1);
  rb_define_alias(ph_bldc_motor, "acceleration=", "setAcceleration");

  /* Document-method: getMinAcceleration
   * call-seq: getMinAcceleration -> acceleration
   *
   * The minimum value that Acceleration can be set to.
   */
  rb_define_method(ph_bldc_motor, "getMinAcceleration", ph_bldc_motor_get_min_acceleration, 0);
  rb_define_alias(ph_bldc_motor, "min_acceleration", "getMinAcceleration");

  /* Document-method: getMaxAcceleration
   * call-seq: getMaxAcceleration -> acceleration
   *
   * The maximum value that Acceleration can be set to.
   */
  rb_define_method(ph_bldc_motor, "getMaxAcceleration", ph_bldc_motor_get_max_acceleration, 0);
  rb_define_alias(ph_bldc_motor, "max_acceleration", "getMaxAcceleration");

  /* Document-method: getBrakingStrength
   * call-seq: getBrakingStrength -> braking_strength
   *
   * The most recent braking strength value that the controller has reported.
   */
  rb_define_method(ph_bldc_motor, "getBrakingStrength", ph_bldc_motor_get_braking_strength, 0);
  rb_define_alias(ph_bldc_motor, "braking_strength", "getBrakingStrength");

  /* Document-method: getMinBrakingStrength
   * call-seq: getMinBrakingStrength -> braking_strength
   *
   * The minimum value that TargetBrakingStrength can be set to.
   */
  rb_define_method(ph_bldc_motor, "getMinBrakingStrength", ph_bldc_motor_get_min_braking_strength, 0);
  rb_define_alias(ph_bldc_motor, "min_braking_strength", "getMinBrakingStrength");

  /* Document-method: getMaxBrakingStrength
   * call-seq: getMaxBrakingStrength -> braking_strength
   *
   * The maximum value that TargetBrakingStrength can be set to.
   */
  rb_define_method(ph_bldc_motor, "getMaxBrakingStrength", ph_bldc_motor_get_max_braking_strength, 0);
  rb_define_alias(ph_bldc_motor, "max_braking_strength", "getMaxBrakingStrength");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> interval
   *
   * The DataInterval is the time that must elapse before the controller will fire another update event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_bldc_motor, "getDataInterval", ph_bldc_motor_get_data_interval, 0);
  rb_define_alias(ph_bldc_motor, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(interval)
   *
   * The DataInterval is the time that must elapse before the controller will fire another update event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   */
  rb_define_method(ph_bldc_motor, "setDataInterval", ph_bldc_motor_set_data_interval, 1);
  rb_define_alias(ph_bldc_motor, "data_interval=", "setDataInterval");

  /* Document-method: getMinDataInterval
   * call-seq: getMinDataInterval -> interval
   *
   * The minimum value that DataInterval can be set to.
   */
  rb_define_method(ph_bldc_motor, "getMinDataInterval", ph_bldc_motor_get_min_data_interval, 0);
  rb_define_alias(ph_bldc_motor, "min_data_interval", "getMinDataInterval");

  /* Document-method: getMaxDataInterval
   * call-seq: getMaxDataInterval -> interval
   *
   * The maximum value that DataInterval can be set to.
   */
  rb_define_method(ph_bldc_motor, "getMaxDataInterval", ph_bldc_motor_get_max_data_interval, 0);
  rb_define_alias(ph_bldc_motor, "max_data_interval", "getMaxDataInterval");

  /* Document-method: getPosition
   * call-seq: getPosition -> position
   *
   * The most recent position value that the controller has reported.
   * Position values are calculated using Hall Effect sensors mounted on the motor, therefore, the resolution of position depends on the motor you are using.
   * Units for Position can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   * For more information on how to apply the RescaleFactor to your application, see your controller's User Guide.
   */
  rb_define_method(ph_bldc_motor, "getPosition", ph_bldc_motor_get_position, 0);
  rb_define_alias(ph_bldc_motor, "position", "getPosition");

  /* Document-method: getMinPosition
   * call-seq: getMinPosition -> position
   *
   * The lower bound of Position.
   */
  rb_define_method(ph_bldc_motor, "getMinPosition", ph_bldc_motor_get_min_position, 0);
  rb_define_alias(ph_bldc_motor, "min_position", "getMinPosition");

  /* Document-method: getMaxPosition
   * call-seq: getMaxPosition -> position
   *
   * The upper bound of Position.
   */
  rb_define_method(ph_bldc_motor, "getMaxPosition", ph_bldc_motor_get_max_position, 0);
  rb_define_alias(ph_bldc_motor, "max_position", "getMaxPosition");

  /* Document-method: addPositionOffset
   * call-seq: addPositionOffset(position_offset)
   *
   * Adds an offset (positive or negative) to the current position.
   * This can be especially useful for zeroing position.
   */
  rb_define_method(ph_bldc_motor, "addPositionOffset", ph_bldc_motor_add_position_offset, 1);
  rb_define_alias(ph_bldc_motor, "add_position_offset", "addPositionOffset");

  /* Document-method: getRescaleFactor
   * call-seq: getRescaleFactor -> rescale_factor
   *
   * Change the units of your parameters so that your application is more intuitive.
   * Units for Position can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   * For more information on how to apply the RescaleFactor to your application, see your controller's User Guide.
   */
  rb_define_method(ph_bldc_motor, "getRescaleFactor", ph_bldc_motor_get_rescale_factor, 0);
  rb_define_alias(ph_bldc_motor, "rescale_factor", "getRescaleFactor");

  /* Document-method: setRescaleFactor
   * call-seq: setRescaleFactor(rescale_factor)
   *
   * Change the units of your parameters so that your application is more intuitive.
   * Units for Position can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
   * For more information on how to apply the RescaleFactor to your application, see your controller's User Guide.
   */
  rb_define_method(ph_bldc_motor, "setRescaleFactor", ph_bldc_motor_set_rescale_factor, 1);
  rb_define_alias(ph_bldc_motor, "rescale_factor=", "setRescaleFactor");

  /* Document-method: getStallVelocity
   * call-seq: getStallVelocity -> stall_velocity
   *
   * Before reading this description, it is important to note the difference between the units of StallVelocity and Velocity.
   * Velocity is a number between -1 and 1 with units of 'duty cycle'. It simply represents the average voltage across the motor.
   * StallVelocity represents a real velocity (e.g. m/s, RPM, etc.) and the units are determined by the RescaleFactor.
   * With a RescaleFactor of 1, the default units would be in commutations per second.
   * If the load on your motor is large, your motor may begin rotating more slowly, or even fully stall. Depending on the voltage across your motor,
   * this may result in a large amount of current through both the controller and the motor. In order to prevent damage in these situations, you can use the StallVelocity property.

   * The StallVelocity should be set to the lowest velocity you would expect from your motor. The controller will then monitor the motor's velocity,
   * as well as the Velocity, and prevent a 'dangerous stall' from occuring. If the controller detects a dangerous stall, it will immediately reduce the
   * Velocity (i.e. average voltage) to 0 and an error will be reported to your program.
   * A 'dangerous stall' will occur faster when the Velocity is higher (i.e. when the average voltage across the motor is higher)
   * A 'dangerous stall' will occur faster as (StallVelocity - motor velocity) becomes larger .
   * Setting StallVelocity to 0 will turn off stall protection functionality.
   */
  rb_define_method(ph_bldc_motor, "getStallVelocity", ph_bldc_motor_get_stall_velocity, 0);
  rb_define_alias(ph_bldc_motor, "stall_velocity", "getStallVelocity");

  /* Document-method: setStallVelocity
   * call-seq: setStallVelocity(stall_velocity)
   *
   * Before reading this description, it is important to note the difference between the units of StallVelocity and Velocity.
   * Velocity is a number between -1 and 1 with units of 'duty cycle'. It simply represents the average voltage across the motor.
   * StallVelocity represents a real velocity (e.g. m/s, RPM, etc.) and the units are determined by the RescaleFactor.
   * With a RescaleFactor of 1, the default units would be in commutations per second.
   * If the load on your motor is large, your motor may begin rotating more slowly, or even fully stall. Depending on the voltage across your motor,
   * this may result in a large amount of current through both the controller and the motor. In order to prevent damage in these situations, you can use the StallVelocity property.

   * The StallVelocity should be set to the lowest velocity you would expect from your motor. The controller will then monitor the motor's velocity,
   * as well as the Velocity, and prevent a 'dangerous stall' from occuring. If the controller detects a dangerous stall, it will immediately reduce the
   * Velocity (i.e. average voltage) to 0 and an error will be reported to your program.
   * A 'dangerous stall' will occur faster when the Velocity is higher (i.e. when the average voltage across the motor is higher)
   * A 'dangerous stall' will occur faster as (StallVelocity - motor velocity) becomes larger .
   * Setting StallVelocity to 0 will turn off stall protection functionality.
   */
  rb_define_method(ph_bldc_motor, "setStallVelocity", ph_bldc_motor_set_stall_velocity, 1);
  rb_define_alias(ph_bldc_motor, "stall_velocity=", "setStallVelocity");

  /* Document-method: getMinStallVelocity
   * call-seq: getMinStallVelocity -> stall_velocity
   *
   * The lower bound of StallVelocity.
   */
  rb_define_method(ph_bldc_motor, "getMinStallVelocity", ph_bldc_motor_get_min_stall_velocity, 0);
  rb_define_alias(ph_bldc_motor, "min_stall_velocity", "getMinStallVelocity");

  /* Document-method: getMaxStallVelocity
   * call-seq: getMaxStallVelocity -> stall_velocity
   *
   * The upper bound of StallVelocity.
   */
  rb_define_method(ph_bldc_motor, "getMaxStallVelocity", ph_bldc_motor_get_max_stall_velocity, 0);
  rb_define_alias(ph_bldc_motor, "max_stall_velocity", "getMaxStallVelocity");

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
  rb_define_method(ph_bldc_motor, "getTargetBrakingStrength", ph_bldc_motor_get_target_braking_strength, 0);
  rb_define_alias(ph_bldc_motor, "target_braking_strength", "getTargetBrakingStrength");

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
  rb_define_method(ph_bldc_motor, "setTargetBrakingStrength", ph_bldc_motor_set_target_braking_strength, 1);
  rb_define_alias(ph_bldc_motor, "target_braking_strength=", "setTargetBrakingStrength");

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
  rb_define_method(ph_bldc_motor, "getTargetVelocity", ph_bldc_motor_get_target_velocity, 0);
  rb_define_alias(ph_bldc_motor, "target_velocity", "getTargetVelocity");

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
  rb_define_method(ph_bldc_motor, "setTargetVelocity", ph_bldc_motor_set_target_velocity, 1);
  rb_define_alias(ph_bldc_motor, "target_velocity=", "setTargetVelocity");

  /* Document-method: getVelocity
   * call-seq: getVelocity -> velocity
   *
   * The most recent velocity value that the controller has reported.
   */
  rb_define_method(ph_bldc_motor, "getVelocity", ph_bldc_motor_get_velocity, 0);
  rb_define_alias(ph_bldc_motor, "velocity", "getVelocity");

  /* Document-method: getMinVelocity
   * call-seq: getMinVelocity -> velocity
   *
   * The minimum value that TargetVelocity can be set to
   * Set the TargetVelocity to MinVelocity to stop the motor. See TargetBrakingStrength for more information on stopping the motor.
   * TargetVelocity is bounded by -1×MaxVelocity and MaxVelocity, where a sign change (±) is indicitave of a direction change.
   */
  rb_define_method(ph_bldc_motor, "getMinVelocity", ph_bldc_motor_get_min_velocity, 0);
  rb_define_alias(ph_bldc_motor, "min_velocity", "getMinVelocity");

  /* Document-method: getMaxVelocity
   * call-seq: getMaxVelocity -> velocity
   *
   * The maximum value that TargetVelocity can be set to.
   * TargetVelocity is bounded by -1×MaxVelocity and MaxVelocity, where a sign change (±) is indicitave of a direction change.
   */
  rb_define_method(ph_bldc_motor, "getMaxVelocity", ph_bldc_motor_get_max_velocity, 0);
  rb_define_alias(ph_bldc_motor, "max_velocity", "getMaxVelocity");

  rb_define_private_method(ph_bldc_motor, "ext_setOnBrakingStrengthChangeHandler", ph_bldc_motor_set_on_braking_strength_change_handler, 1);
  rb_define_private_method(ph_bldc_motor, "ext_setOnPositionChangeHandler", ph_bldc_motor_set_on_position_change_handler, 1);
  rb_define_private_method(ph_bldc_motor, "ext_setOnVelocityUpdateHandler", ph_bldc_motor_set_on_velocity_update_handler, 1);
}

