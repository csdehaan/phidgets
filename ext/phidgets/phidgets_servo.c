
#include "phidgets.h"


VALUE ph_servo_init(VALUE self);
VALUE ph_servo_get_motor_count(VALUE self);
VALUE ph_servo_get_position(VALUE self, VALUE index);
VALUE ph_servo_get_position_min(VALUE self, VALUE index);
VALUE ph_servo_get_position_max(VALUE self, VALUE index);
VALUE ph_servo_set_position(VALUE self, VALUE index, VALUE position);
VALUE ph_servo_get_engaged(VALUE self, VALUE index);
VALUE ph_servo_set_engaged(VALUE self, VALUE index, VALUE engaged);
VALUE ph_servo_get_servo_type(VALUE self, VALUE index);
VALUE ph_servo_set_servo_type(VALUE self, VALUE index, VALUE type);
VALUE ph_servo_set_servo_parameters(VALUE self, VALUE index, VALUE min_us, VALUE max_us, VALUE degrees);

#ifdef PH_CALLBACK
VALUE ph_servo_set_on_position_change_handler(VALUE self, VALUE handler);
int ph_servo_on_position_change(CPhidgetServoHandle phid, void *userPtr, int index, double position);
#endif


void Init_servo() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_servo = rb_define_class_under(ph_module, "Servo", ph_common);

  /* Default - This is what the servo API been historically used, originally based on the Futaba FP-S148 */
  rb_define_const(ph_servo, "DEFAULT", INT2FIX(PHIDGET_SERVO_DEFAULT));
  /* Raw us mode - all position, velocity, acceleration functions are specified in microseconds rather then degrees */
  rb_define_const(ph_servo, "RAW_US_MODE", INT2FIX(PHIDGET_SERVO_RAW_us_MODE));
  /* HiTec HS-322HD Standard \Servo */
  rb_define_const(ph_servo, "HITEC_HS322HD", INT2FIX(PHIDGET_SERVO_HITEC_HS322HD));
  /* HiTec HS-5245MG Digital Mini \Servo */
  rb_define_const(ph_servo, "HITEC_HS5245MG", INT2FIX(PHIDGET_SERVO_HITEC_HS5245MG));
  /* HiTec HS-805BB Mega Quarter Scale \Servo */
  rb_define_const(ph_servo, "HITEC_805BB", INT2FIX(PHIDGET_SERVO_HITEC_805BB));
  /* HiTec HS-422 Standard \Servo */
  rb_define_const(ph_servo, "HITEC_HS422", INT2FIX(PHIDGET_SERVO_HITEC_HS422));
  /* Tower Pro MG90 Micro \Servo */
  rb_define_const(ph_servo, "TOWERPRO_MG90", INT2FIX(PHIDGET_SERVO_TOWERPRO_MG90));
  /* HiTec HSR-1425CR Continuous Rotation \Servo */
  rb_define_const(ph_servo, "HITEC_HSR1425CR", INT2FIX(PHIDGET_SERVO_HITEC_HSR1425CR));
  /* HiTec HS-785HB Sail Winch \Servo */
  rb_define_const(ph_servo, "HITEC_HS785HB", INT2FIX(PHIDGET_SERVO_HITEC_HS785HB));
  /* HiTec HS-485HB Deluxe \Servo */
  rb_define_const(ph_servo, "HITEC_HS485HB", INT2FIX(PHIDGET_SERVO_HITEC_HS485HB));
  /* HiTec HS-645MG Ultra Torque \Servo */
  rb_define_const(ph_servo, "HITEC_HS645MG", INT2FIX(PHIDGET_SERVO_HITEC_HS645MG));
  /* HiTec HS-815BB Mega Sail \Servo */
  rb_define_const(ph_servo, "HITEC_815BB", INT2FIX(PHIDGET_SERVO_HITEC_815BB));
  /* Document-const:
   * Firgelli L12 Linear Actuator 30mm 50\:1 */
  rb_define_const(ph_servo, "FIRGELLI_L12_30_50_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_30_50_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 50mm 100\:1 */
  rb_define_const(ph_servo, "FIRGELLI_L12_50_100_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_50_100_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 50mm 210\:1 */
  rb_define_const(ph_servo, "FIRGELLI_L12_50_210_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_50_210_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 100mm 50\:1 */
  rb_define_const(ph_servo, "FIRGELLI_L12_100_50_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_100_50_06_R));
  /* Document-const:
   * Firgelli L12 Linear Actuator 100mm 100\:1 */
  rb_define_const(ph_servo, "FIRGELLI_L12_100_100_06_R", INT2FIX(PHIDGET_SERVO_FIRGELLI_L12_100_100_06_R));
  /* SpringRC SM-S2313M Micro \Servo */
  rb_define_const(ph_servo, "SPRINGRC_SM_S2313M", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S2313M));
  /* SpringRC SM-S3317M Small \Servo */
  rb_define_const(ph_servo, "SPRINGRC_SM_S3317M", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S3317M));
  /* SpringRC SM-S3317SR Small Continuous Rotation \Servo */
  rb_define_const(ph_servo, "SPRINGRC_SM_S3317SR", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S3317SR));
  /* SpringRC SM-S4303R Standard Continuous Rotation \Servo */
  rb_define_const(ph_servo, "SPRINGRC_SM_S4303R", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4303R));
  /* SpringRC SM-S4315M High Torque \Servo */
  rb_define_const(ph_servo, "SPRINGRC_SM_S4315M", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4315M));
  /* SpringRC SM-S4315R High Torque Continuous Rotation \Servo */
  rb_define_const(ph_servo, "SPRINGRC_SM_S4315R", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4315R));
  /* SpringRC SM-S4505B Standard \Servo */
  rb_define_const(ph_servo, "SPRINGRC_SM_S4505B", INT2FIX(PHIDGET_SERVO_SPRINGRC_SM_S4505B));

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Servo object.
   */
  rb_define_method(ph_servo, "initialize", ph_servo_init, 0);

  /* Document-method: getMotorCount
   * call-seq: getMotorCount -> count
   *
   * Gets the number of motors supported by this controller
   */
  rb_define_method(ph_servo, "getMotorCount", ph_servo_get_motor_count, 0);

  /* Document-method: getPosition
   * call-seq: getPosition(index) -> position
   *
   * Gets the current position of a motor.
   */
  rb_define_method(ph_servo, "getPosition", ph_servo_get_position, 1);

  /* Document-method: getPositionMin
   * call-seq: getPositionMin(index) -> min
   *
   * Gets the minimum position that a motor can go to.
   */
  rb_define_method(ph_servo, "getPositionMin", ph_servo_get_position_min, 1);

  /* Document-method: getPositionMax
   * call-seq: getPositionMax(index) -> max
   *
   * Gets the maximum position that a motor can go to.
   */
  rb_define_method(ph_servo, "getPositionMax", ph_servo_get_position_max, 1);

  /* Document-method: setPosition
   * call-seq: setPosition(index, position)
   *
   * Sets the position of a motor.
   */
  rb_define_method(ph_servo, "setPosition", ph_servo_set_position, 2);

  /* Document-method: getEngaged
   * call-seq: getEngaged(index) -> true or false
   *
   * Gets the engaged state of a motor. This is whether the motor is powered or not.
   */
  rb_define_method(ph_servo, "getEngaged", ph_servo_get_engaged, 1);

  /* Document-method: setEngaged
   * call-seq: setEngaged(index, state)
   *
   * Sets the engaged state of a motor. This is whether the motor is powered or not.
   */
  rb_define_method(ph_servo, "setEngaged", ph_servo_set_engaged, 2);

  /* Document-method: getServoType
   * call-seq: getServoType(index) -> servo_type
   *
   * Gets the servo type of a motor.
   */
  rb_define_method(ph_servo, "getServoType", ph_servo_get_servo_type, 1);

  /* Document-method: setServoType
   * call-seq: setServoType(index, servo_type)
   *
   * Sets the servo type of a motor.
   */
  rb_define_method(ph_servo, "setServoType", ph_servo_set_servo_type, 2);

  /* Document-method: setServoParameters
   * call-seq: setServoParameters(index, min_us, max_us, degrees)
   *
   * Sets the servo parameters of a motor.
   */
  rb_define_method(ph_servo, "setServoParameters", ph_servo_set_servo_parameters, 4);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_servo, "ext_setOnPositionChangeHandler", ph_servo_set_on_position_change_handler, 1);
#endif

  rb_define_alias(ph_servo, "motor_count", "getMotorCount");
  rb_define_alias(ph_servo, "position", "getPosition");
  rb_define_alias(ph_servo, "position_min", "getPositionMin");
  rb_define_alias(ph_servo, "position_max", "getPositionMax");
  rb_define_alias(ph_servo, "set_position", "setPosition");
  rb_define_alias(ph_servo, "engaged?", "getEngaged");
  rb_define_alias(ph_servo, "set_engaged", "setEngaged");
  rb_define_alias(ph_servo, "servo_type", "getServoType");
  rb_define_alias(ph_servo, "set_servo_type", "setServoType");
  rb_define_alias(ph_servo, "set_servo_parameters", "setServoParameters");
}



VALUE ph_servo_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetServo_create((CPhidgetServoHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_servo_get_motor_count(VALUE self) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  int count;
  ph_raise(CPhidgetServo_getMotorCount(handle, &count));
  return INT2FIX(count);
}

VALUE ph_servo_get_position(VALUE self, VALUE index) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  double position;
  ph_raise(CPhidgetServo_getPosition(handle, FIX2INT(index), &position));
  return rb_float_new(position);
}

VALUE ph_servo_get_position_min(VALUE self, VALUE index) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  double position;
  ph_raise(CPhidgetServo_getPositionMin(handle, FIX2INT(index), &position));
  return rb_float_new(position);
}

VALUE ph_servo_get_position_max(VALUE self, VALUE index) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  double position;
  ph_raise(CPhidgetServo_getPositionMax(handle, FIX2INT(index), &position));
  return rb_float_new(position);
}

VALUE ph_servo_set_position(VALUE self, VALUE index, VALUE position) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  ph_raise(CPhidgetServo_setPosition(handle, FIX2INT(index), NUM2DBL(position)));
  return Qnil;
}

VALUE ph_servo_get_engaged(VALUE self, VALUE index) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  int engaged;
  ph_raise(CPhidgetServo_getEngaged(handle, FIX2INT(index), &engaged));
  return engaged == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_servo_set_engaged(VALUE self, VALUE index, VALUE engaged) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  ph_raise(CPhidgetServo_setEngaged(handle, FIX2INT(index), TYPE(engaged) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_servo_get_servo_type(VALUE self, VALUE index) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  CPhidget_ServoType type;
  ph_raise(CPhidgetServo_getServoType(handle, FIX2INT(index), &type));
  return INT2FIX(type);
}

VALUE ph_servo_set_servo_type(VALUE self, VALUE index, VALUE type) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  ph_raise(CPhidgetServo_setServoType(handle, FIX2INT(index), (CPhidget_ServoType)FIX2INT(type)));
  return Qnil;
}

VALUE ph_servo_set_servo_parameters(VALUE self, VALUE index, VALUE min_us, VALUE max_us, VALUE degrees) {
  CPhidgetServoHandle handle = (CPhidgetServoHandle)get_ph_handle(self);
  ph_raise(CPhidgetServo_setServoParameters(handle, FIX2INT(index), NUM2DBL(min_us), NUM2DBL(max_us), NUM2DBL(degrees)));
  return Qnil;
}


#ifdef PH_CALLBACK
VALUE ph_servo_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetServo_set_OnPositionChange_Handler((CPhidgetServoHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetServo_set_OnPositionChange_Handler((CPhidgetServoHandle)ph->handle, ph_servo_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_servo_on_position_change(CPhidgetServoHandle phid, void *userPtr, int index, double position) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

