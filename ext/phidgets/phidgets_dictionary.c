
#include "phidgets.h"


VALUE ph_dictionary_allocate(VALUE klass);
void  ph_dictionary_free(ph_data_t *ph);
VALUE ph_dictionary_init(VALUE self);
VALUE ph_dictionary_open_remote(VALUE self, VALUE server_id, VALUE password);
VALUE ph_dictionary_open_remote_ip(VALUE self, VALUE address, VALUE port, VALUE password);
VALUE ph_dictionary_close(VALUE self);
VALUE ph_dictionary_get_key(VALUE self, VALUE key);
VALUE ph_dictionary_add_key(VALUE self, VALUE key, VALUE value, VALUE persist);
VALUE ph_dictionary_remove_key(VALUE self, VALUE pattern);
VALUE ph_dictionary_get_server_id(VALUE self);
VALUE ph_dictionary_get_server_address(VALUE self);
VALUE ph_dictionary_get_server_status(VALUE self);

#ifdef PH_CALLBACK
VALUE ph_dictionary_set_on_key_change_handler(VALUE self, VALUE handler);
VALUE ph_dictionary_remove_on_key_change_handler(VALUE self, VALUE listener);
VALUE ph_dictionary_set_on_server_connect_handler(VALUE self, VALUE handler);
VALUE ph_dictionary_set_on_server_disconnect_handler(VALUE self, VALUE handler);
int ph_dictionary_on_server_connect(CPhidgetDictionaryHandle phid, void *userPtr);
int ph_dictionary_on_server_disconnect(CPhidgetDictionaryHandle phid, void *userPtr);
#endif


void Init_dictionary() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_dictionary = rb_define_class_under(ph_module, "Dictionary", rb_cObject);
  rb_define_alloc_func(ph_dictionary, ph_dictionary_allocate);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Dictionary object.
   */
  rb_define_method(ph_dictionary, "initialize", ph_dictionary_init, 0);

  /* Document-method: openRemote
   * call-seq: openRemote(server_id, password)
   *
   * Opens a Phidget dictionary by ServerID. Note that this requires Bonjour (mDNS) to be running on both the host and the server.
   */
  rb_define_method(ph_dictionary, "openRemote", ph_dictionary_open_remote, 2);

  /* Document-method: openRemoteIP
   * call-seq: openRemoteIP(address, port, password)
   *
   * Opens a Phidget dictionary by address and port.
   */
  rb_define_method(ph_dictionary, "openRemoteIP", ph_dictionary_open_remote_ip, 3);

  /* Document-method: close
   * call-seq: close
   *
   * Closes the connection to a Phidget Dictionary.
   */
  rb_define_method(ph_dictionary, "close", ph_dictionary_close, 0);

  /* Document-method: getKey
   * call-seq: getKey(key) -> value
   *
   * Gets a key value. If more then one key matches, only the first value is returned.
   */
  rb_define_method(ph_dictionary, "getKey", ph_dictionary_get_key, 1);

  /* Document-method: addKey
   * call-seq: addKey(key, value, persistent)
   *
   * Adds a key/value pair to the dictionary. Or, changes an existing key's value.
   */
  rb_define_method(ph_dictionary, "addKey", ph_dictionary_add_key, 3);

  /* Document-method: removeKey
   * call-seq: removeKey(pattern)
   *
   * Removes a set of keys from the dictionary.
   */
  rb_define_method(ph_dictionary, "removeKey", ph_dictionary_remove_key, 1);

  /* Document-method: getServerID
   * call-seq: getServerID -> server_id
   *
   * Gets the server ID.
   */
  rb_define_method(ph_dictionary, "getServerID", ph_dictionary_get_server_id, 0);

  /* Document-method: getServerAddress
   * call-seq: getServerAddress -> [address, port]
   *
   * Gets the address and port.
   */
  rb_define_method(ph_dictionary, "getServerAddress", ph_dictionary_get_server_address, 0);

  /* Document-method: getServerStatus
   * call-seq: getServerStatus -> status
   *
   * Gets the connected to server status.
   */
  rb_define_method(ph_dictionary, "getServerStatus", ph_dictionary_get_server_status, 0);

#ifdef PH_CALLBACK

  /* Document-method: setOnKeyChangeHandler
   * call-seq: setOnKeyChangeHandler(proc=nil, &block)
   *
   * ** NOT IMPLEMENTED **
   */
  rb_define_method(ph_dictionary, "setOnKeyChangeHandler", ph_dictionary_set_on_key_change_handler, 1);

  /* Document-method: removeOnKeyChangeHandler
   * call-seq: removeOnKeyChangeHandler(listener)
   *
   * ** NOT IMPLEMENTED **
   */
  rb_define_method(ph_dictionary, "removeOnKeyChangeHandler", ph_dictionary_remove_on_key_change_handler, 1);
  rb_define_private_method(ph_dictionary, "ext_setOnServerConnectHandler", ph_dictionary_set_on_server_connect_handler, 1);
  rb_define_private_method(ph_dictionary, "ext_setOnServerDisconnectHandler", ph_dictionary_set_on_server_disconnect_handler, 1);
  rb_define_alias(ph_dictionary, "on_key_change", "setOnKeyChangeHandler");
  rb_define_alias(ph_dictionary, "remove_on_key_change", "removeOnKeyChangeHandler");
#endif

  rb_define_alias(ph_dictionary, "open_remote", "openRemote");
  rb_define_alias(ph_dictionary, "open_remote_ip", "openRemoteIP");
  rb_define_alias(ph_dictionary, "server_id", "getServerID");
  rb_define_alias(ph_dictionary, "get_key", "getKey");
  rb_define_alias(ph_dictionary, "add_key", "addKey");
  rb_define_alias(ph_dictionary, "remove_key", "removeKey");
  rb_define_alias(ph_dictionary, "server_address", "getServerAddress");
  rb_define_alias(ph_dictionary, "server_status", "getServerStatus");
}



VALUE ph_dictionary_allocate(VALUE klass) {
  ph_data_t *ph;
  VALUE self = Data_Make_Struct(klass, ph_data_t, 0, ph_dictionary_free, ph);
  memset(ph, 0, sizeof(ph_data_t));
  return self;
}

void ph_dictionary_free(ph_data_t *ph) {
  if (ph && ph->handle) {
    CPhidgetDictionary_close((CPhidgetDictionaryHandle)ph->handle);
    CPhidgetDictionary_delete((CPhidgetDictionaryHandle)ph->handle);
    ph->handle = NULL;
  }
  if(ph) xfree(ph);
}

VALUE ph_dictionary_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(CPhidgetDictionary_create((CPhidgetDictionaryHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_dictionary_open_remote(VALUE self, VALUE server_id, VALUE password) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  ph_raise(CPhidgetDictionary_openRemote(handle, StringValueCStr(server_id), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_dictionary_open_remote_ip(VALUE self, VALUE address, VALUE port, VALUE password) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  ph_raise(CPhidgetDictionary_openRemoteIP(handle, StringValueCStr(address), FIX2INT(port), StringValueCStr(password)));
  return Qnil;
}

VALUE ph_dictionary_close(VALUE self) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  ph_raise(CPhidgetDictionary_close(handle));
  return Qnil;
}

VALUE ph_dictionary_get_key(VALUE self, VALUE key) {
#define VALUE_LEN 512
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  char value[VALUE_LEN];
  ph_raise(CPhidgetDictionary_getKey(handle, StringValueCStr(key), value, VALUE_LEN));
  return rb_str_new2(value);
}

VALUE ph_dictionary_add_key(VALUE self, VALUE key, VALUE value, VALUE persist) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  ph_raise(CPhidgetDictionary_addKey(handle, StringValueCStr(key), StringValueCStr(value), TYPE(persist) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}

VALUE ph_dictionary_remove_key(VALUE self, VALUE pattern) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  ph_raise(CPhidgetDictionary_removeKey(handle, StringValueCStr(pattern)));
  return Qnil;
}

VALUE ph_dictionary_get_server_id(VALUE self) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  const char *server_id;
  ph_raise(CPhidgetDictionary_getServerID(handle, &server_id));
  return rb_str_new2(server_id);
}

VALUE ph_dictionary_get_server_address(VALUE self) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  const char *address;
  int port;
  ph_raise(CPhidgetDictionary_getServerAddress(handle, &address, &port));
  return rb_ary_new3(2, rb_str_new2(address), INT2FIX(port));
}

VALUE ph_dictionary_get_server_status(VALUE self) {
  CPhidgetDictionaryHandle handle = (CPhidgetDictionaryHandle)get_ph_handle(self);
  int server_status;
  ph_raise(CPhidgetDictionary_getServerStatus(handle, &server_status));
  return INT2FIX(server_status);
}


#ifdef PH_CALLBACK
VALUE ph_dictionary_set_on_key_change_handler(VALUE self, VALUE handler) {
  ph_raise(EPHIDGET_NOTIMPLEMENTED);
  return Qnil;
}

VALUE ph_dictionary_remove_on_key_change_handler(VALUE self, VALUE listener) {
  ph_raise(EPHIDGET_NOTIMPLEMENTED);
  return Qnil;
}

VALUE ph_dictionary_set_on_server_connect_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->server_connect_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetDictionary_set_OnServerConnect_Handler((CPhidgetDictionaryHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetDictionary_set_OnServerConnect_Handler((CPhidgetDictionaryHandle)ph->handle, ph_dictionary_on_server_connect, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_dictionary_set_on_server_disconnect_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->server_disconnect_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(CPhidgetDictionary_set_OnServerDisconnect_Handler((CPhidgetDictionaryHandle)ph->handle, NULL, (void *)NULL));
  } else {
    callback_data->called = false;
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(CPhidgetDictionary_set_OnServerDisconnect_Handler((CPhidgetDictionaryHandle)ph->handle, ph_dictionary_on_server_disconnect, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


int ph_dictionary_on_server_connect(CPhidgetDictionaryHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}


int ph_dictionary_on_server_disconnect(CPhidgetDictionaryHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->called = true;
  return EPHIDGET_OK;
}
#endif

