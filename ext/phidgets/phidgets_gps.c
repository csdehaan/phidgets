
#include "phidgets.h"

#define GPS_HEADING_CHANGE_CALLBACK    0
#define GPS_POSITION_CHANGE_CALLBACK   1
#define GPS_FIX_STATE_CHANGE_CALLBACK  2



VALUE ph_gps_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetGPS_create((PhidgetGPSHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_gps_get_latitude(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetGPS_getLatitude);
}

VALUE ph_gps_get_longitude(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetGPS_getLongitude);
}

VALUE ph_gps_get_altitude(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetGPS_getAltitude);
}

VALUE ph_gps_get_heading(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetGPS_getHeading);
}

VALUE ph_gps_get_velocity(VALUE self) {
  return ph_get_double(get_ph_handle(self), PhidgetGPS_getVelocity);
}

VALUE ph_gps_get_time(VALUE self) {
  PhidgetGPSHandle handle = (PhidgetGPSHandle)get_ph_handle(self);
  PhidgetGPS_Time time;
  VALUE rb_time = rb_hash_new();
  ph_raise(PhidgetGPS_getTime(handle, &time));
  rb_hash_aset(rb_time, rb_str_new2("tm_hour"), INT2NUM(time.tm_hour));
  rb_hash_aset(rb_time, rb_str_new2("tm_min"), INT2NUM(time.tm_min));
  rb_hash_aset(rb_time, rb_str_new2("tm_sec"), INT2NUM(time.tm_sec));
  rb_hash_aset(rb_time, rb_str_new2("tm_ms"), INT2NUM(time.tm_ms));
  return rb_time;
}

VALUE ph_gps_get_date(VALUE self) {
  PhidgetGPSHandle handle = (PhidgetGPSHandle)get_ph_handle(self);
  PhidgetGPS_Date date;
  VALUE rb_date = rb_hash_new();
  ph_raise(PhidgetGPS_getDate(handle, &date));
  rb_hash_aset(rb_date, rb_str_new2("tm_year"), INT2NUM(date.tm_year));
  rb_hash_aset(rb_date, rb_str_new2("tm_mon"), INT2NUM(date.tm_mon));
  rb_hash_aset(rb_date, rb_str_new2("tm_mday"), INT2NUM(date.tm_mday));
  return rb_date;
}

VALUE ph_gps_get_position_fix_state(VALUE self) {
  return ph_get_bool(get_ph_handle(self), PhidgetGPS_getPositionFixState);
}

VALUE ph_gps_get_nmea_data(VALUE self) {
  PhidgetGPSHandle handle = (PhidgetGPSHandle)get_ph_handle(self);
  PhidgetGPS_NMEAData nmea_data;
  VALUE rb_gga_data = rb_hash_new();
  VALUE rb_gsa_data = rb_hash_new();
  VALUE rb_rmc_data = rb_hash_new();
  VALUE rb_vtg_data = rb_hash_new();
  VALUE rb_nmea_data = rb_hash_new();
  VALUE sat_used = rb_ary_new();
  int i;

  ph_raise(PhidgetGPS_getNMEAData(handle, &nmea_data));

  // GGA
  rb_hash_aset(rb_gga_data, rb_str_new2("latitude"), DBL2NUM(nmea_data.GGA.latitude));
  rb_hash_aset(rb_gga_data, rb_str_new2("longitude"), DBL2NUM(nmea_data.GGA.longitude));
  rb_hash_aset(rb_gga_data, rb_str_new2("fixQuality"), INT2NUM(nmea_data.GGA.fixQuality));
  rb_hash_aset(rb_gga_data, rb_str_new2("numSatellites"), INT2NUM(nmea_data.GGA.numSatellites));
  rb_hash_aset(rb_gga_data, rb_str_new2("horizontalDilution"), DBL2NUM(nmea_data.GGA.horizontalDilution));
  rb_hash_aset(rb_gga_data, rb_str_new2("altitude"), DBL2NUM(nmea_data.GGA.altitude));
  rb_hash_aset(rb_gga_data, rb_str_new2("heightOfGeoid"), DBL2NUM(nmea_data.GGA.heightOfGeoid));

  // GSA
  rb_hash_aset(rb_gsa_data, rb_str_new2("mode"), INT2NUM(nmea_data.GSA.mode));
  rb_hash_aset(rb_gsa_data, rb_str_new2("fixType"), INT2NUM(nmea_data.GSA.fixType));
  for(i=0; i<12; i++) {rb_ary_push(sat_used, INT2NUM(nmea_data.GSA.satUsed[i]));}
  rb_hash_aset(rb_gsa_data, rb_str_new2("satUsed"), sat_used);
  rb_hash_aset(rb_gsa_data, rb_str_new2("posnDilution"), DBL2NUM(nmea_data.GSA.posnDilution));
  rb_hash_aset(rb_gsa_data, rb_str_new2("horizDilution"), DBL2NUM(nmea_data.GSA.horizDilution));
  rb_hash_aset(rb_gsa_data, rb_str_new2("vertDilution"), DBL2NUM(nmea_data.GSA.vertDilution));

  // RMC
  rb_hash_aset(rb_rmc_data, rb_str_new2("status"), INT2NUM(nmea_data.RMC.status));
  rb_hash_aset(rb_rmc_data, rb_str_new2("latitude"), DBL2NUM(nmea_data.RMC.latitude));
  rb_hash_aset(rb_rmc_data, rb_str_new2("longitude"), DBL2NUM(nmea_data.RMC.longitude));
  rb_hash_aset(rb_rmc_data, rb_str_new2("speedKnots"), DBL2NUM(nmea_data.RMC.speedKnots));
  rb_hash_aset(rb_rmc_data, rb_str_new2("heading"), DBL2NUM(nmea_data.RMC.heading));
  rb_hash_aset(rb_rmc_data, rb_str_new2("magneticVariation"), DBL2NUM(nmea_data.RMC.magneticVariation));
  rb_hash_aset(rb_rmc_data, rb_str_new2("mode"), INT2NUM(nmea_data.RMC.mode));

  // VTG
  rb_hash_aset(rb_vtg_data, rb_str_new2("trueHeading"), DBL2NUM(nmea_data.VTG.trueHeading));
  rb_hash_aset(rb_vtg_data, rb_str_new2("magneticHeading"), DBL2NUM(nmea_data.VTG.magneticHeading));
  rb_hash_aset(rb_vtg_data, rb_str_new2("speedKnots"), DBL2NUM(nmea_data.VTG.speedKnots));
  rb_hash_aset(rb_vtg_data, rb_str_new2("speed"), DBL2NUM(nmea_data.VTG.speed));
  rb_hash_aset(rb_vtg_data, rb_str_new2("mode"), INT2NUM(nmea_data.VTG.mode));

  rb_hash_aset(rb_nmea_data, rb_str_new2("GGA"), rb_gga_data);
  rb_hash_aset(rb_nmea_data, rb_str_new2("GSA"), rb_gsa_data);
  rb_hash_aset(rb_nmea_data, rb_str_new2("RMC"), rb_rmc_data);
  rb_hash_aset(rb_nmea_data, rb_str_new2("VTG"), rb_vtg_data);
  return rb_nmea_data;
}


void CCONV ph_gps_on_heading_change(PhidgetGPSHandle phid, void *userPtr, double heading, double velocity) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(heading);
  callback_data->arg2 = DBL2NUM(velocity);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_gps_set_on_heading_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[GPS_HEADING_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetGPS_setOnHeadingChangeHandler((PhidgetGPSHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetGPS_setOnHeadingChangeHandler((PhidgetGPSHandle)ph->handle, ph_gps_on_heading_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_gps_on_position_change(PhidgetGPSHandle phid, void *userPtr, double latitude, double longitude, double altitude) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = DBL2NUM(latitude);
  callback_data->arg2 = DBL2NUM(longitude);
  callback_data->arg3 = DBL2NUM(altitude);
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_gps_set_on_position_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[GPS_POSITION_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetGPS_setOnPositionChangeHandler((PhidgetGPSHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetGPS_setOnPositionChangeHandler((PhidgetGPSHandle)ph->handle, ph_gps_on_position_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_gps_on_position_fix_state_change(PhidgetGPSHandle phid, void *userPtr, int state) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = state == PTRUE ? Qtrue : Qfalse;
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->sem);
}


VALUE ph_gps_set_on_position_fix_state_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[GPS_FIX_STATE_CHANGE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetGPS_setOnPositionFixStateChangeHandler((PhidgetGPSHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetGPS_setOnPositionFixStateChangeHandler((PhidgetGPSHandle)ph->handle, ph_gps_on_position_fix_state_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void Init_gps() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
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
   * The latitude of the GPS in degrees.
   */
  rb_define_method(ph_gps, "getLatitude", ph_gps_get_latitude, 0);
  rb_define_alias(ph_gps, "latitude", "getLatitude");

  /* Document-method: getLongitude
   * call-seq: getLongitude -> longitude
   *
   * The longitude of the GPS.
   */
  rb_define_method(ph_gps, "getLongitude", ph_gps_get_longitude, 0);
  rb_define_alias(ph_gps, "longitude", "getLongitude");

  /* Document-method: getAltitude
   * call-seq: getAltitude -> altitude
   *
   * The altitude above mean sea level in meters.
   */
  rb_define_method(ph_gps, "getAltitude", ph_gps_get_altitude, 0);
  rb_define_alias(ph_gps, "altitude", "getAltitude");

  /* Document-method: getHeading
   * call-seq: getHeading -> heading
   *
   * The current true course over ground of the GPS.
   */
  rb_define_method(ph_gps, "getHeading", ph_gps_get_heading, 0);
  rb_define_alias(ph_gps, "heading", "getHeading");

  /* Document-method: getVelocity
   * call-seq: getVelocity -> velocity
   *
   * The current speed over ground of the GPS.
   */
  rb_define_method(ph_gps, "getVelocity", ph_gps_get_velocity, 0);
  rb_define_alias(ph_gps, "velocity", "getVelocity");

  /* Document-method: getTime
   * call-seq: getTime -> time
   *
   * The current UTC time of the GPS.
   */
  rb_define_method(ph_gps, "getTime", ph_gps_get_time, 0);
  rb_define_alias(ph_gps, "time", "getTime");

  /* Document-method: getDate
   * call-seq: getDate -> date
   *
   * The UTC date of the last received position.
   */
  rb_define_method(ph_gps, "getDate", ph_gps_get_date, 0);
  rb_define_alias(ph_gps, "date", "getDate");

  /* Document-method: getPositionFixState
   * call-seq: getPositionFixState -> fix_state
   *
   * The status of the position fix
   * True if a fix is available and latitude, longitude, and altitude can be read. False if the fix is not available.
   */
  rb_define_method(ph_gps, "getPositionFixState", ph_gps_get_position_fix_state, 0);
  rb_define_alias(ph_gps, "position_fix?", "getPositionFixState");

  /* Document-method: getNMEAData
   * call-seq: getNMEAData -> nmea_data
   *
   * The NMEA data structure.
   */
  rb_define_method(ph_gps, "getNMEAData", ph_gps_get_nmea_data, 0);
  rb_define_alias(ph_gps, "nmea_data", "getNMEAData");

  rb_define_private_method(ph_gps, "ext_setOnHeadingChangeHandler", ph_gps_set_on_heading_change_handler, 1);
  rb_define_private_method(ph_gps, "ext_setOnPositionChangeHandler", ph_gps_set_on_position_change_handler, 1);
  rb_define_private_method(ph_gps, "ext_setOnPositionFixStateChangeHandler", ph_gps_set_on_position_fix_state_change_handler, 1);
}

