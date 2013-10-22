
#include "phidgets.h"


VALUE ph_common_allocate(VALUE klass);
void  ph_common_free(ph_data_t *ph);
VALUE ph_common_open(VALUE self, VALUE serial_number);
VALUE ph_common_open_label(VALUE self, VALUE label);
VALUE ph_common_open_remote(VALUE self, VALUE serial_number, VALUE server_id, VALUE password);
VALUE ph_common_open_label_remote(VALUE self, VALUE label, VALUE server_id, VALUE password);
VALUE ph_common_open_remote_ip(VALUE self, VALUE serial_number, VALUE address, VALUE port, VALUE password);
VALUE ph_common_open_label_remote_ip(VALUE self, VALUE label, VALUE address, VALUE port, VALUE password);
VALUE ph_common_wait_for_attachment(VALUE self, VALUE milliseconds);
VALUE ph_common_close(VALUE self);
VALUE ph_common_get_device_class(VALUE self);
VALUE ph_common_get_device_id(VALUE self);
VALUE ph_common_get_device_type(VALUE self);
VALUE ph_common_get_device_name(VALUE self);
VALUE ph_common_get_serial_number(VALUE self);
VALUE ph_common_get_device_version(VALUE self);
VALUE ph_common_get_device_status(VALUE self);
VALUE ph_common_get_device_label(VALUE self);
VALUE ph_common_set_device_label(VALUE self, VALUE label);
VALUE ph_common_get_server_id(VALUE self);
VALUE ph_common_get_server_address(VALUE self);
VALUE ph_common_get_server_status(VALUE self);

#ifdef PH_CALLBACK
VALUE ph_common_set_on_attach_handler(VALUE self, VALUE handler);
VALUE ph_common_set_on_detach_handler(VALUE self, VALUE handler);
VALUE ph_common_set_on_server_connect_handler(VALUE self, VALUE handler);
VALUE ph_common_set_on_server_disconnect_handler(VALUE self, VALUE handler);
int ph_common_on_attach(CPhidgetHandle phid, void *userPtr);
int ph_common_on_detach(CPhidgetHandle phid, void *userPtr);
int ph_common_on_server_connect(CPhidgetHandle phid, void *userPtr);
int ph_common_on_server_disconnect(CPhidgetHandle phid, void *userPtr);
#endif


void Init_common() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_define_class_under(ph_module, "Common", rb_cObject);
  rb_define_alloc_func(ph_common, ph_common_allocate);
  rb_define_private_method(ph_common, "ext_open", ph_common_open, 1);

  /* Document-method: openLabel
   * call-seq: openLabel(label)
   *
   * Opens a Phidget by label.
   */
  rb_define_method(ph_common, "openLabel", ph_common_open_label, 1);

  /* Document-method: openRemote
   * call-seq: openRemote(serial, server_id, password)
   *
   * Opens a Phidget remotely by ServerID. Note that this requires Bonjour (mDNS) to be running on both the host and the server.
   */
  rb_define_method(ph_common, "openRemote", ph_common_open_remote, 3);

  /* Document-method: openLabelRemote
   * call-seq: openLabelRemote(label, server_id, password)
   *
   * Opens a Phidget remotely by ServerID. Note that this requires Bonjour (mDNS) to be running on both the host and the server.
   */
  rb_define_method(ph_common, "openLabelRemote", ph_common_open_label_remote, 3);

  /* Document-method: openRemoteIP
   * call-seq: openRemoteIP(serial, address, port, password)
   *
   * Opens a Phidget remotely by address and port, with optional serial number.
   */
  rb_define_method(ph_common, "openRemoteIP", ph_common_open_remote_ip, 4);

  /* Document-method: openLabelRemoteIP
   * call-seq: openLabelRemoteIP(label, address, port, password)
   *
   * Opens a Phidget remotely by address and port, with optional label.
   */
  rb_define_method(ph_common, "openLabelRemoteIP", ph_common_open_label_remote_ip, 4);

  /* Document-method: waitForAttachment
   * call-seq: waitForAttachment(milliseconds)
   *
   * Waits for attachment to happen. This can be called right after calling open, as an alternative to using the attach handler.
   */
  rb_define_method(ph_common, "waitForAttachment", ph_common_wait_for_attachment, 1);

  /* Document-method: close
   * call-seq: close
   *
   * Closes a Phidget.
   */
  rb_define_method(ph_common, "close", ph_common_close, 0);

  /* Document-method: getDeviceClass
   * call-seq: getDeviceClass -> device_class
   *
   * Gets the class of a Phidget.
   */
  rb_define_method(ph_common, "getDeviceClass", ph_common_get_device_class, 0);

  /* Document-method: getDeviceID
   * call-seq: getDeviceID -> device_id
   *
   * Gets the device ID of a Phidget.
   */
  rb_define_method(ph_common, "getDeviceID", ph_common_get_device_id, 0);

  /* Document-method: getDeviceType
   * call-seq: getDeviceType -> device_type
   *
   * Gets the type (class) of a Phidget.
   */
  rb_define_method(ph_common, "getDeviceType", ph_common_get_device_type, 0);

  /* Document-method: getDeviceName
   * call-seq: getDeviceName -> device_name
   *
   * Gets the specific name of a Phidget.
   */
  rb_define_method(ph_common, "getDeviceName", ph_common_get_device_name, 0);

  /* Document-method: getSerialNumber
   * call-seq: getSerialNumber -> serial_number
   *
   * Gets the serial number of a Phidget.
   */
  rb_define_method(ph_common, "getSerialNumber", ph_common_get_serial_number, 0);

  /* Document-method: getDeviceVersion
   * call-seq: getDeviceVersion -> version
   *
   * Gets the firmware version of a Phidget.
   */
  rb_define_method(ph_common, "getDeviceVersion", ph_common_get_device_version, 0);

  /* Document-method: getDeviceStatus
   * call-seq: getDeviceStatus -> status
   *
   * Gets the attached status of a Phidget.
   */
  rb_define_method(ph_common, "getDeviceStatus", ph_common_get_device_status, 0);

  /* Document-method: getDeviceLabel
   * call-seq: getDeviceLabel -> label
   *
   * Gets the label of a Phidget.
   */
  rb_define_method(ph_common, "getDeviceLabel", ph_common_get_device_label, 0);

  /* Document-method: setDeviceLabel
   * call-seq: setDeviceLabel(label)
   *
   * Sets the label of a Phidget. Note that this is not supported on very old Phidgets, and not yet supported in Windows.
   */
  rb_define_method(ph_common, "setDeviceLabel", ph_common_set_device_label, 1);

  /* Document-method: getServerID
   * call-seq: getServerID -> server_id
   *
   * Gets the server ID of a remotely opened Phidget. This will fail if the Phidget was opened locally.
   */
  rb_define_method(ph_common, "getServerID", ph_common_get_server_id, 0);

  /* Document-method: getServerAddress
   * call-seq: getServerAddress -> [address, port]
   *
   * Gets the address and port of a remotely opened Phidget. This will fail if the Phidget was opened locally.
   */
  rb_define_method(ph_common, "getServerAddress", ph_common_get_server_address, 0);

  /* Document-method: getServerStatus
   * call-seq: getServerStatus -> status
   *
   * Gets the connected to server status of a remotely opened Phidget. This will fail if the Phidget was opened locally.
   */
  rb_define_method(ph_common, "getServerStatus", ph_common_get_server_status, 0);

#ifdef PH_CALLBACK
  rb_define_private_method(ph_common, "ext_setOnAttachHandler", ph_common_set_on_attach_handler, 1);
  rb_define_private_method(ph_common, "ext_setOnDetachHandler", ph_common_set_on_detach_handler, 1);
  rb_define_private_method(ph_common, "ext_setOnServerConnectHandler", ph_common_set_on_server_connect_handler, 1);
  rb_define_private_method(ph_common, "ext_setOnServerDisconnectHandler", ph_common_set_on_server_disconnect_handler, 1);
#endif

  rb_define_alias(ph_common, "open_label", "openLabel");
  rb_define_alias(ph_common, "open_remote", "openRemote");
  rb_define_alias(ph_common, "open_label_remote", "openLabelRemote");
  rb_define_alias(ph_common, "open_remote_ip", "openRemoteIP");
  rb_define_alias(ph_common, "open_label_remote_ip", "openLabelRemoteIP");
  rb_define_alias(ph_common, "wait_for_attachment", "waitForAttachment");
  rb_define_alias(ph_common, "device_class", "getDeviceClass");
  rb_define_alias(ph_common, "device_id", "getDeviceID");
  rb_define_alias(ph_common, "device_type", "getDeviceType");
  rb_define_alias(ph_common, "device_name", "getDeviceName");
  rb_define_alias(ph_common, "serial_number", "getSerialNumber");
  rb_define_alias(ph_common, "device_version", "getDeviceVersion");
  rb_define_alias(ph_common, "device_status", "getDeviceStatus");
  rb_define_alias(ph_common, "device_label", "getDeviceLabel");
  rb_define_alias(ph_common, "device_label=", "setDeviceLabel");
  rb_define_alias(ph_common, "server_id", "getServerID");
  rb_define_alias(ph_common, "server_address", "getServerAddress");
  rb_define_alias(ph_common, "server_status", "getServerStatus");
}



VALUE ph_common_allocate(VALUE klass) {
  ph_data_t *ph;
  VALUE self = Data_Make_Struct(klass, ph_data_t, 0, ph_common_free, ph);
  memset(ph, 0, sizeof(ph_data_t));
  return self;
}

void ph_common_free(ph_data_t *ph) {
  if (ph && ph->handle) {
    CPhidget_close(ph->handle);
    CPhidget_delete(ph->handle);
    ph->handle = NULL;
  }
  if(ph) xfree(ph);
}

VALUE ph_common_open(VALUE self, VALUE serial_number) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_open(handle, FIX2INT(serial_number)));
  return Qnil;
}

VALUE ph_common_open_label(VALUE self, VALUE label) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_openLabel(handle, StringValueCStr(label)));
  return Qnil;
}

VALUE ph_common_open_remote(VALUE self, VALUE serial_number, VALUE server_id, VALUE password) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_openRemote(handle, FIX2INT(serial_number), StringValueCStr(server_id), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_common_open_label_remote(VALUE self, VALUE label, VALUE server_id, VALUE password) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_openLabelRemote(handle, StringValueCStr(label), StringValueCStr(server_id), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_common_open_remote_ip(VALUE self, VALUE serial_number, VALUE address, VALUE port, VALUE password) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_openRemoteIP(handle, FIX2INT(serial_number), StringValueCStr(address), FIX2INT(port), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_common_open_label_remote_ip(VALUE self, VALUE label, VALUE address, VALUE port, VALUE password) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_openLabelRemoteIP(handle, StringValueCStr(label), StringValueCStr(address), FIX2INT(port), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_common_wait_for_attachment(VALUE self, VALUE milliseconds) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_waitForAttachment(handle, FIX2INT(milliseconds)));
  return Qnil;
}

VALUE ph_common_close(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_close(handle));
  return Qnil;
}

VALUE ph_common_get_device_class(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  CPhidget_DeviceClass device_class;
  ph_raise(CPhidget_getDeviceClass(handle, &device_class));
  return INT2FIX(device_class);
}

VALUE ph_common_get_device_id(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  CPhidget_DeviceID device_id;
  ph_raise(CPhidget_getDeviceID(handle, &device_id));
  return INT2FIX(device_id);
}

VALUE ph_common_get_device_type(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  const char *device_type;
  ph_raise(CPhidget_getDeviceType(handle, &device_type));
  return rb_str_new2(device_type);
}

VALUE ph_common_get_device_name(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  const char *device_name;
  ph_raise(CPhidget_getDeviceName(handle, &device_name));
  return rb_str_new2(device_name);
}

VALUE ph_common_get_serial_number(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  int serial;
  ph_raise(CPhidget_getSerialNumber(handle, &serial));
  return INT2FIX(serial);
}

VALUE ph_common_get_device_version(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  int device_version;
  ph_raise(CPhidget_getDeviceVersion(handle, &device_version));
  return INT2FIX(device_version);
}

VALUE ph_common_get_device_status(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  int device_status;
  ph_raise(CPhidget_getDeviceStatus(handle, &device_status));
  return INT2FIX(device_status);
}

VALUE ph_common_get_device_label(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  const char *device_label;
  ph_raise(CPhidget_getDeviceLabel(handle, &device_label));
  return rb_str_new2(device_label);
}

VALUE ph_common_set_device_label(VALUE self, VALUE label) {
  CPhidgetHandle handle = get_ph_handle(self);
  ph_raise(CPhidget_setDeviceLabel(handle, StringValueCStr(label)));
  return Qnil;
}

VALUE ph_common_get_server_id(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  const char *server_id;
  ph_raise(CPhidget_getServerID(handle, &server_id));
  return rb_str_new2(server_id);
}

VALUE ph_common_get_server_address(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  const char *address;
  int port;
  ph_raise(CPhidget_getServerAddress(handle, &address, &port));
  return rb_ary_new3(2, rb_str_new2(address), INT2FIX(port));
}

VALUE ph_common_get_server_status(VALUE self) {
  CPhidgetHandle handle = get_ph_handle(self);
  int server_status;
  ph_raise(CPhidget_getServerStatus(handle, &server_status));
  return INT2FIX(server_status);
}

#ifdef PH_CALLBACK
VALUE ph_common_set_on_attach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->attach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidget_set_OnAttach_Handler(ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidget_set_OnAttach_Handler(ph->handle, ph_common_on_attach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_common_set_on_detach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->detach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidget_set_OnDetach_Handler(ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidget_set_OnDetach_Handler(ph->handle, ph_common_on_detach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_common_set_on_server_connect_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->server_connect_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidget_set_OnServerConnect_Handler(ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidget_set_OnServerConnect_Handler(ph->handle, ph_common_on_server_connect, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_common_set_on_server_disconnect_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->server_disconnect_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidget_set_OnServerDisconnect_Handler(ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidget_set_OnServerDisconnect_Handler(ph->handle, ph_common_on_server_disconnect, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_common_on_attach(CPhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_common_on_detach(CPhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_common_on_server_connect(CPhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_common_on_server_disconnect(CPhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif

