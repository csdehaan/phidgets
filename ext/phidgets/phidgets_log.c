
#include "phidgets.h"


VALUE ph_log_enable(VALUE self, VALUE level, VALUE output_file);
VALUE ph_log_disable(VALUE self);
VALUE ph_log_get_level(VALUE self);
VALUE ph_log_set_level(VALUE self, VALUE level);
VALUE ph_log_log(VALUE self, VALUE level, VALUE message);
VALUE ph_log_loge(VALUE self, VALUE file, VALUE line, VALUE function, VALUE source, VALUE level, VALUE message);
VALUE ph_log_rotate(VALUE self);
VALUE ph_log_is_rotating(VALUE self);
VALUE ph_log_get_rotating(VALUE self);
VALUE ph_log_set_rotating(VALUE self, VALUE size, VALUE keep_count);
VALUE ph_log_enable_rotating(VALUE self);
VALUE ph_log_disable_rotating(VALUE self);
VALUE ph_log_add_source(VALUE self, VALUE source, VALUE level);
VALUE ph_log_get_source_level(VALUE self, VALUE source);
VALUE ph_log_set_source_level(VALUE self, VALUE source, VALUE level);
VALUE ph_log_get_sources(VALUE self);


void Init_logging() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_log = rb_define_class_under(ph_module, "Log", rb_cObject);

  rb_define_const(ph_log, "CRITICAL", INT2FIX(PHIDGET_LOG_CRITICAL));
  rb_define_const(ph_log, "ERROR", INT2FIX(PHIDGET_LOG_ERROR));
  rb_define_const(ph_log, "WARNING", INT2FIX(PHIDGET_LOG_WARNING));
  rb_define_const(ph_log, "DEBUG", INT2FIX(PHIDGET_LOG_DEBUG));
  rb_define_const(ph_log, "INFO", INT2FIX(PHIDGET_LOG_INFO));
  rb_define_const(ph_log, "VERBOSE", INT2FIX(PHIDGET_LOG_VERBOSE));

  /*
   * Document-method: enable
   * call-seq: enable(log_level, output_file)
   *
   * Enables logging.
   */
  rb_define_singleton_method(ph_log, "enable", ph_log_enable, 2);

  /*
   * Document-method: disable
   * call-seq: disable
   *
   * Disables logging.
   */
  rb_define_singleton_method(ph_log, "disable", ph_log_disable, 0);

  /*
   * Document-method: getLevel
   * call-seq: getLevel
   *
   * Gets the log level for the phidget22 source.
   */
  rb_define_singleton_method(ph_log, "getLevel", ph_log_get_level, 0);

  /*
   * Document-method: setLevel
   * call-seq: setLevel
   *
   * Sets the log level for all sources not prefaced with _phidget22.
   */
  rb_define_singleton_method(ph_log, "setLevel", ph_log_set_level, 1);

  /*
   * Document-method: log
   * call-seq: log(log_level, msg)
   *
   * Appends a message to the log.
   */
  rb_define_singleton_method(ph_log, "log", ph_log_log, 2);

  /*
   * Document-method: loge
   * call-seq: loge(file, line, function, source, log_level, msg)
   *
   * Writes a message to the Phidget library log from a specified source.
   */
  rb_define_singleton_method(ph_log, "loge", ph_log_loge, 6);

  /*
   * Document-method: rotate
   * call-seq: rotate
   *
   * Manually rotate the log file. This will only have an effect if automatic rotation is disabled and the log file is larger than the specified maximum file size.
   */
  rb_define_singleton_method(ph_log, "rotate", ph_log_rotate, 0);

  /*
   * Document-method: isRotating
   * call-seq: isRotating
   *
   * Determines if the library is automatically rotating the log file.
   */
  rb_define_singleton_method(ph_log, "isRotating", ph_log_is_rotating, 0);

  /*
   * Document-method: getRotating
   * call-seq: getRotating
   *
   * Gets the current log rotation parameters.
   */
  rb_define_singleton_method(ph_log, "getRotating", ph_log_get_rotating, 0);

  /*
   * Document-method: setRotating
   * call-seq: setRotating(size, keep_count)
   *
   * Sets log rotation parameters.
   */
  rb_define_singleton_method(ph_log, "setRotating", ph_log_set_rotating, 2);

  /*
   * Document-method: enableRotating
   * call-seq: enableRotating
   *
   * Enables automatic rotation of the log file (the default).
   */
  rb_define_singleton_method(ph_log, "enableRotating", ph_log_enable_rotating, 0);

  /*
   * Document-method: disableRotating
   * call-seq: disableRotating
   *
   * Disables automatic rotation of the log file.
   */
  rb_define_singleton_method(ph_log, "disableRotating", ph_log_disable_rotating, 0);

  /*
   * Document-method: addSource
   * call-seq: addSource(source, level)
   *
   * Adds a source to the Phidget logging system. This is useful for declaring a source and setting its log level before sending any messages.
   */
  rb_define_singleton_method(ph_log, "addSource", ph_log_add_source, 2);

  /*
   * Document-method: getSourceLevel
   * call-seq: getSourceLevel(source)
   *
   * Gets the log level of the specified log source.
   */
  rb_define_singleton_method(ph_log, "getSourceLevel", ph_log_get_source_level, 1);

  /*
   * Document-method: setSourceLevel
   * call-seq: setSourceLevel(source, level)
   *
   * Sets the log level of the specified log source.
   */
  rb_define_singleton_method(ph_log, "setSourceLevel", ph_log_set_source_level, 2);

  /*
   * Document-method: getSources
   * call-seq: getSources
   *
   * Gets an array of log sources in the system.
   */
  rb_define_singleton_method(ph_log, "getSources", ph_log_get_sources, 0);
}


VALUE ph_log_enable(VALUE self, VALUE level, VALUE output_file) {
  ph_raise(PhidgetLog_enable(NUM2INT(level), StringValueCStr(output_file)));
  return Qnil;
}

VALUE ph_log_disable(VALUE self) {
  ph_raise(PhidgetLog_disable());
  return Qnil;
}

VALUE ph_log_get_level(VALUE self) {
  Phidget_LogLevel level;
  ph_raise(PhidgetLog_getLevel(&level));
  return INT2NUM(level);
}

VALUE ph_log_set_level(VALUE self, VALUE level) {
  ph_raise(PhidgetLog_setLevel(NUM2INT(level)));
  return Qnil;
}

VALUE ph_log_log(VALUE self, VALUE level, VALUE message) {
  ph_raise(PhidgetLog_log(NUM2INT(level), StringValueCStr(message)));
  return Qnil;
}

VALUE ph_log_loge(VALUE self, VALUE file, VALUE line, VALUE function, VALUE source, VALUE level, VALUE message) {
  ph_raise(PhidgetLog_loge( StringValueCStr(file),  NUM2INT(line), StringValueCStr(function),  StringValueCStr(source), NUM2INT(level), StringValueCStr(message)));
  return Qnil;
}

VALUE ph_log_rotate(VALUE self) {
  ph_raise(PhidgetLog_rotate());
  return Qnil;
}

VALUE ph_log_is_rotating(VALUE self) {
  int rotating;
  ph_raise(PhidgetLog_isRotating(&rotating));
  return rotating == PTRUE ? Qtrue : Qfalse;
}

VALUE ph_log_get_rotating(VALUE self) {
  uint64_t size;
  int count;
  ph_raise(PhidgetLog_getRotating(&size, &count));
  return rb_ary_new3(2, ULL2NUM(size), INT2NUM(count));
}

VALUE ph_log_set_rotating(VALUE self, VALUE size, VALUE keep_count) {
  ph_raise(PhidgetLog_setRotating(NUM2ULL(size), NUM2INT(keep_count)));
  return Qnil;
}

VALUE ph_log_enable_rotating(VALUE self) {
  ph_raise(PhidgetLog_enableRotating());
  return Qnil;
}

VALUE ph_log_disable_rotating(VALUE self) {
  ph_raise(PhidgetLog_disableRotating());
  return Qnil;
}

VALUE ph_log_add_source(VALUE self, VALUE source, VALUE level) {
  ph_raise(PhidgetLog_addSource(StringValueCStr(source), NUM2INT(level)));
  return Qnil;
}

VALUE ph_log_get_source_level(VALUE self, VALUE source) {
  Phidget_LogLevel level;
  ph_raise(PhidgetLog_getSourceLevel(StringValueCStr(source), &level));
  return INT2NUM(level);
}

VALUE ph_log_set_source_level(VALUE self, VALUE source, VALUE level) {
  ph_raise(PhidgetLog_setSourceLevel(StringValueCStr(source), NUM2INT(level)));
  return Qnil;
}

VALUE ph_log_get_sources(VALUE self) {
  PhidgetReturnCode rc;
  const char **sources;
  uint32_t count;
  VALUE ary = rb_ary_new();
  uint32_t i;

  ph_raise(PhidgetLog_getSources(NULL, &count));
  sources = malloc(sizeof(const char *) * count);

  rc = PhidgetLog_getSources(sources, &count);
  if( rc != EPHIDGET_OK ) {
    free(sources);
    ph_raise(rc);
  }

  for(i=0; i<count; i++) rb_ary_push(ary, rb_str_new2(sources[i]));
  free(sources);
  return ary;
}

