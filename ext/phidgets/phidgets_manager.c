
#include "phidgets.h"

#if 0
VALUE ph_manager_allocate(VALUE klass);
void  ph_manager_free(ph_data_t *ph);
VALUE ph_manager_init(VALUE self);
VALUE ph_manager_open(VALUE self);
VALUE ph_manager_open_remote(VALUE self, VALUE server_id, VALUE password);
VALUE ph_manager_open_remote_ip(VALUE self, VALUE address, VALUE port, VALUE password);
VALUE ph_manager_close(VALUE self);
VALUE ph_manager_get_server_id(VALUE self);
VALUE ph_manager_get_server_address(VALUE self);
VALUE ph_manager_get_server_status(VALUE self);
VALUE ph_manager_get_attached_devices(VALUE self);
VALUE ph_manager_instance_from_class(Phidget_DeviceClass dev_class);

VALUE ph_manager_set_on_attach_handler(VALUE self, VALUE handler);
VALUE ph_manager_set_on_detach_handler(VALUE self, VALUE handler);
VALUE ph_manager_set_on_server_connect_handler(VALUE self, VALUE handler);
VALUE ph_manager_set_on_server_disconnect_handler(VALUE self, VALUE handler);
int ph_manager_on_attach(PhidgetHandle phid, void *userPtr);
int ph_manager_on_detach(PhidgetHandle phid, void *userPtr);
int ph_manager_on_server_connect(PhidgetManagerHandle phid, void *userPtr);
int ph_manager_on_server_disconnect(PhidgetManagerHandle phid, void *userPtr);


void Init_manager() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_manager = rb_define_class_under(ph_module, "Manager", rb_cObject);
  rb_define_alloc_func(ph_manager, ph_manager_allocate);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Manager object.
   */
  rb_define_method(ph_manager, "initialize", ph_manager_init, 0);
  rb_define_private_method(ph_manager, "ext_open", ph_manager_open, 0);

  /* Document-method: openRemote
   * call-seq: openRemote(server_id, password)
   *
   * Opens a Phidget manager remotely by ServerID. Note that this requires Bonjour
   * (mDNS) to be running on both the host and the server.
   */
  rb_define_method(ph_manager, "openRemote", ph_manager_open_remote, 2);

  /* Document-method: openRemoteIP
   * call-seq: openRemoteIP(address, port, password)
   *
   * Opens a Phidget manager remotely by address and port.
   */
  rb_define_method(ph_manager, "openRemoteIP", ph_manager_open_remote_ip, 3);

  /* Document-method: close
   * call-seq: close
   *
   * Closes a Phidget Manager.
   */
  rb_define_method(ph_manager, "close", ph_manager_close, 0);

  /* Document-method: getServerID
   * call-seq: getServerID -> server_id
   *
   * Gets the server ID of a remotely opened Phidget Manager. This will fail if the manager was opened locally.
   */
  rb_define_method(ph_manager, "getServerID", ph_manager_get_server_id, 0);

  /* Document-method: getServerAddress
   * call-seq: getServerAddress -> [address, port]
   *
   * Gets the address and port of a remotely opened Phidget Manager. This will fail if the manager was opened locally.
   */
  rb_define_method(ph_manager, "getServerAddress", ph_manager_get_server_address, 0);

  /* Document-method: getServerStatus
   * call-seq: getServerStatus -> status
   *
   * Gets the connected to server status of a remotely opened Phidget Manager. This will fail if the manager was opened locally.
   */
  rb_define_method(ph_manager, "getServerStatus", ph_manager_get_server_status, 0);

  /* Document-method: getAttachedDevices
   * call-seq: getAttachedDevices -> [devices]
   *
   * Gets an array of all currently attached Phidgets.
   */
  rb_define_method(ph_manager, "getAttachedDevices", ph_manager_get_attached_devices, 0);

  rb_define_private_method(ph_manager, "ext_setOnAttachHandler", ph_manager_set_on_attach_handler, 1);
  rb_define_private_method(ph_manager, "ext_setOnDetachHandler", ph_manager_set_on_detach_handler, 1);
  rb_define_private_method(ph_manager, "ext_setOnServerConnectHandler", ph_manager_set_on_server_connect_handler, 1);
  rb_define_private_method(ph_manager, "ext_setOnServerDisconnectHandler", ph_manager_set_on_server_disconnect_handler, 1);

  rb_define_alias(ph_manager, "open_remote", "openRemote");
  rb_define_alias(ph_manager, "open_remote_ip", "openRemoteIP");
  rb_define_alias(ph_manager, "server_id", "getServerID");
  rb_define_alias(ph_manager, "server_address", "getServerAddress");
  rb_define_alias(ph_manager, "server_status", "getServerStatus");
  rb_define_alias(ph_manager, "attached_devices", "getAttachedDevices");
}



VALUE ph_manager_allocate(VALUE klass) {
  ph_data_t *ph;
  VALUE self = Data_Make_Struct(klass, ph_data_t, 0, ph_manager_free, ph);
  memset(ph, 0, sizeof(ph_data_t));
  return self;
}

void ph_manager_free(ph_data_t *ph) {
  if (ph && ph->handle) {
    PhidgetManager_close((PhidgetManagerHandle)ph->handle);
    PhidgetManager_delete((PhidgetManagerHandle)ph->handle);
    ph->handle = NULL;
  }
  if(ph) xfree(ph);
}

VALUE ph_manager_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetManager_create((PhidgetManagerHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_manager_open(VALUE self) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  ph_raise(PhidgetManager_open(handle));
  return Qnil;
}

VALUE ph_manager_open_remote(VALUE self, VALUE server_id, VALUE password) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  ph_raise(PhidgetManager_openRemote(handle, StringValueCStr(server_id), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_manager_open_remote_ip(VALUE self, VALUE address, VALUE port, VALUE password) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  ph_raise(PhidgetManager_openRemoteIP(handle, StringValueCStr(address), FIX2INT(port), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_manager_close(VALUE self) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  ph_raise(PhidgetManager_close(handle));
  return Qnil;
}

VALUE ph_manager_get_server_id(VALUE self) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  const char *server_id;
  ph_raise(PhidgetManager_getServerID(handle, &server_id));
  return rb_str_new2(server_id);
}

VALUE ph_manager_get_server_address(VALUE self) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  const char *address;
  int port;
  ph_raise(PhidgetManager_getServerAddress(handle, &address, &port));
  return rb_ary_new3(2, rb_str_new2(address), INT2FIX(port));
}

VALUE ph_manager_get_server_status(VALUE self) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  int server_status;
  ph_raise(PhidgetManager_getServerStatus(handle, &server_status));
  return INT2FIX(server_status);
}

VALUE ph_manager_get_attached_devices(VALUE self) {
  PhidgetManagerHandle handle = (PhidgetManagerHandle)get_ph_handle(self);
  PhidgetHandle *devices;
  int count, i;
  VALUE rb_hash = rb_hash_new();
  ph_raise(PhidgetManager_getAttachedDevices(handle, &devices, &count));
  for(i=0; i<count; i++) {
    int serial;
    Phidget_DeviceClass dev_class;
    ph_raise(Phidget_getSerialNumber(devices[i], &serial));
    ph_raise(Phidget_getDeviceClass(devices[i], &dev_class));
    rb_hash_aset(rb_hash, INT2FIX(serial), ph_manager_instance_from_class(dev_class));
  }
  ph_raise(PhidgetManager_freeAttachedDevicesArray(devices));
  return rb_hash;
}

VALUE ph_manager_instance_from_class(Phidget_DeviceClass dev_class) {
  VALUE ph_module = rb_const_get(rb_cModule, rb_intern("Phidgets"));
  VALUE klass;
  VALUE argv[0];

  switch( dev_class ) {
    case PHIDCLASS_ACCELEROMETER:
      klass = rb_const_get(ph_module, rb_intern("Accelerometer"));
      break;
    case PHIDCLASS_ADVANCEDSERVO:
      klass = rb_const_get(ph_module, rb_intern("AdvancedServo"));
      break;
    case PHIDCLASS_ANALOG:
      klass = rb_const_get(ph_module, rb_intern("Analog"));
      break;
    case PHIDCLASS_BRIDGE:
      klass = rb_const_get(ph_module, rb_intern("Bridge"));
      break;
    case PHIDCLASS_ENCODER:
      klass = rb_const_get(ph_module, rb_intern("Encoder"));
      break;
    case PHIDCLASS_FREQUENCYCOUNTER:
      klass = rb_const_get(ph_module, rb_intern("FrequencyCounter"));
      break;
    case PHIDCLASS_GPS:
      klass = rb_const_get(ph_module, rb_intern("GPS"));
      break;
    case PHIDCLASS_INTERFACEKIT:
      klass = rb_const_get(ph_module, rb_intern("InterfaceKit"));
      break;
    case PHIDCLASS_IR:
      klass = rb_const_get(ph_module, rb_intern("IR"));
      break;
    case PHIDCLASS_LED:
      klass = rb_const_get(ph_module, rb_intern("LED"));
      break;
    case PHIDCLASS_MOTORCONTROL:
      klass = rb_const_get(ph_module, rb_intern("MotorControl"));
      break;
    case PHIDCLASS_PHSENSOR:
      klass = rb_const_get(ph_module, rb_intern("PhSensor"));
      break;
    case PHIDCLASS_RFID:
      klass = rb_const_get(ph_module, rb_intern("RFID"));
      break;
    case PHIDCLASS_SERVO:
      klass = rb_const_get(ph_module, rb_intern("Servo"));
      break;
    case PHIDCLASS_SPATIAL:
      klass = rb_const_get(ph_module, rb_intern("Spatial"));
      break;
    case PHIDCLASS_STEPPER:
      klass = rb_const_get(ph_module, rb_intern("Stepper"));
      break;
    case PHIDCLASS_TEMPERATURESENSOR:
      klass = rb_const_get(ph_module, rb_intern("TemperatureSensor"));
      break;
    case PHIDCLASS_TEXTLCD:
      klass = rb_const_get(ph_module, rb_intern("TextLCD"));
      break;
    case PHIDCLASS_TEXTLED:
      klass = rb_const_get(ph_module, rb_intern("TextLED"));
      break;
    case PHIDCLASS_WEIGHTSENSOR:
      klass = rb_const_get(ph_module, rb_intern("WeightSensor"));
      break;
    default:
      klass = Qnil;
  }

  return rb_class_new_instance(0, argv, klass);
}

VALUE ph_manager_set_on_attach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->attach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetManager_set_OnAttach_Handler((PhidgetManagerHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetManager_set_OnAttach_Handler((PhidgetManagerHandle)ph->handle, ph_manager_on_attach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_manager_set_on_detach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->detach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetManager_set_OnDetach_Handler((PhidgetManagerHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetManager_set_OnDetach_Handler((PhidgetManagerHandle)ph->handle, ph_manager_on_detach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_manager_set_on_server_connect_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->server_connect_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetManager_set_OnServerConnect_Handler((PhidgetManagerHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetManager_set_OnServerConnect_Handler((PhidgetManagerHandle)ph->handle, ph_manager_on_server_connect, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_manager_set_on_server_disconnect_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->server_disconnect_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(PhidgetManager_set_OnServerDisconnect_Handler((PhidgetManagerHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetManager_set_OnServerDisconnect_Handler((PhidgetManagerHandle)ph->handle, ph_manager_on_server_disconnect, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_manager_on_attach(PhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_manager_on_detach(PhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_manager_on_server_connect(PhidgetManagerHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_manager_on_server_disconnect(PhidgetManagerHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif
