
#include "phidgets.h"


VALUE ph_gps_init(VALUE self);
VALUE ph_gps_get_latitude(VALUE self);
VALUE ph_gps_get_longitude(VALUE self);
VALUE ph_gps_get_altitude(VALUE self);
VALUE ph_gps_get_heading(VALUE self);
VALUE ph_gps_get_velocity(VALUE self);
VALUE ph_gps_get_time(VALUE self);
VALUE ph_gps_get_date(VALUE self);
VALUE ph_gps_get_position_fix_status(VALUE self);
VALUE ph_gps_get_nmea_data(VALUE self);

#ifdef PH_CALLBACK
VALUE ph_gps_set_on_position_change_handler(VALUE self, VALUE handler);
VALUE ph_gps_set_on_position_fix_status_change_handler(VALUE self, VALUE handler);
int ph_gps_on_position_change(CPhidgetGPSHandle phid, void *userPtr, double latitude, double longitude, double altitude);
int ph_gps_on_position_fix_status_change(CPhidgetGPSHandle phid, void *userPtr, int status);
#endif


VALUE Init_phidgets_gps(VALUE ph_module, VALUE ph_common) {
  VALUE ph_gps = rb_define_class_under(ph_module, "GPS", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget GPS object.
   */
  rb_define_method(ph_gps, "initialize", ph_gps_init, 0);

  /* Document-method: getLatitude
   * call-seq: getLatitude -> latitude
   *
   * Gets the current latitude.
   */
  rb_define_method(ph_gps, "getLatitude", ph_gps_get_latitude, 0);

  /* Document-method: getLongitude
   * call-seq: getLongitude -> longitude
   *
   * Gets the current longitude.
   */
  rb_define_method(ph_gps, "getLongitude", ph_gps_get_longitude, 0);

  /* Document-method: getAltitude
   * call-seq: getAltitude -> altitude
   *
   * Gets the current altitude, in meters.
   */
  rb_define_method(ph_gps, "getAltitude", ph_gps_get_altitude, 0);

  /* Document-method: getHeading
   * call-seq: getHeading -> heading
   *
   * Gets the current heading, in degrees.
   */
  rb_define_method(ph_gps, "getHeading", ph_gps_get_heading, 0);

  /* Document-method: getVelocity
   * call-seq: getVelocity -> velocity
   *
   * Gets the current velocity, in km/h.
   */
  rb_define_method(ph_gps, "getVelocity", ph_gps_get_velocity, 0);

  /* Document-method: getTime
   * call-seq: getTime -> time
   *
   * Gets the current GPS time, in UTC, as an array [hour, minute, second, millisecond].
   */
  rb_define_method(ph_gps, "getTime", ph_gps_get_time, 0);

  /* Document-method: getDate
   * call-seq: getDate -> date
   *
   * Gets the current GPS date, in UTC, as an array [year, month, day].
   */
  rb_define_method(ph_gps, "getDate", ph_gps_get_date, 0);

  /* Document-method: getPositionFixStatus
   * call-seq: getPositionFixStatus -> status
   *
   * Gets the position fix status.
   */
  rb_define_method(ph_gps, "getPositionFixStatus", ph_gps_get_position_fix_status, 0);

  /* Document-method: getNMEAData
   * call-seq: getNMEAData -> data
   *
   * ** NOT IMPLEMENTED **
   */
  rb_define_method(ph_gps, "getNMEAData", ph_gps_get_nmea_data, 0);
#ifdef PH_CALLBACK
  rb_define_private_method(ph_gps, "ext_setOnPositionChangeHandler", ph_gps_set_on_position_change_handler, 1);
  rb_define_private_method(ph_gps, "ext_setOnPositionFixStatusChangeHandler", ph_gps_set_on_position_fix_status_change_handler, 1);
#endif

  rb_define_alias(ph_gps, "latitude", "getLatitude");
  rb_define_alias(ph_gps, "longitude", "getLongitude");
  rb_define_alias(ph_gps, "altitude", "getAltitude");
  rb_define_alias(ph_gps, "heading", "getHeading");
  rb_define_alias(ph_gps, "velocity", "getVelocity");
  rb_define_alias(ph_gps, "time", "getTime");
  rb_define_alias(ph_gps, "date", "getDate");
  rb_define_alias(ph_gps, "position_fix_status", "getPositionFixStatus");
  rb_define_alias(ph_gps, "nmea_data", "getNMEAData");

  return ph_gps;
}



VALUE ph_gps_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetGPS_create((CPhidgetGPSHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_gps_get_latitude(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  double latitude;
  ph_raise(CPhidgetGPS_getLatitude(handle, &latitude));
  return rb_float_new(latitude);
}

VALUE ph_gps_get_longitude(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  double longitude;
  ph_raise(CPhidgetGPS_getLongitude(handle, &longitude));
  return rb_float_new(longitude);
}

VALUE ph_gps_get_altitude(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  double altitude;
  ph_raise(CPhidgetGPS_getAltitude(handle, &altitude));
  return rb_float_new(altitude);
}

VALUE ph_gps_get_heading(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  double heading;
  ph_raise(CPhidgetGPS_getHeading(handle, &heading));
  return rb_float_new(heading);
}

VALUE ph_gps_get_velocity(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  double velocity;
  ph_raise(CPhidgetGPS_getVelocity(handle, &velocity));
  return rb_float_new(velocity);
}

VALUE ph_gps_get_time(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  GPSTime time;
  ph_raise(CPhidgetGPS_getTime(handle, &time));
  return rb_ary_new3(4, INT2FIX(time.tm_hour), INT2FIX(time.tm_min), INT2FIX(time.tm_sec), INT2FIX(time.tm_ms));
}

VALUE ph_gps_get_date(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  GPSDate date;
  ph_raise(CPhidgetGPS_getDate(handle, &date));
  return rb_ary_new3(3, INT2FIX(date.tm_year), INT2FIX(date.tm_mon), INT2FIX(date.tm_mday));
}

VALUE ph_gps_get_position_fix_status(VALUE self) {
  CPhidgetGPSHandle handle = (CPhidgetGPSHandle)get_ph_handle(self);
  int state;
  ph_raise(CPhidgetGPS_getPositionFixStatus(handle, &state));
  return INT2FIX(state);
}

VALUE ph_gps_get_nmea_data(VALUE self) {
  ph_raise(EPHIDGET_NOTIMPLEMENTED);
  return Qnil;
}


#ifdef PH_CALLBACK
VALUE ph_gps_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_1;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetGPS_set_OnPositionChange_Handler((CPhidgetGPSHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetGPS_set_OnPositionChange_Handler((CPhidgetGPSHandle)ph->handle, ph_gps_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


VALUE ph_gps_set_on_position_fix_status_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callback_2;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetGPS_set_OnPositionFixStatusChange_Handler((CPhidgetGPSHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetGPS_set_OnPositionFixStatusChange_Handler((CPhidgetGPSHandle)ph->handle, ph_gps_on_position_fix_status_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_gps_on_position_change(CPhidgetGPSHandle phid, void *userPtr, double latitude, double longitude, double altitude) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_gps_on_position_fix_status_change(CPhidgetGPSHandle phid, void *userPtr, int status) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}

#endif

