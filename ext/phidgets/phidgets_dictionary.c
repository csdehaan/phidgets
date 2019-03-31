
#include "phidgets.h"


#define DICTIONARY_VALUE_LEN        512
#define DICTIONARY_ADD_CALLBACK     0
#define DICTIONARY_REMOVE_CALLBACK  0
#define DICTIONARY_UPDATE_CALLBACK  0


VALUE ph_dictionary_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetDictionary_create((PhidgetDictionaryHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_dictionary_add(VALUE self, VALUE key, VALUE value) {
  ph_raise(PhidgetDictionary_add((PhidgetDictionaryHandle)get_ph_handle(self), StringValueCStr(key), StringValueCStr(value)));
  return Qnil;
}

VALUE ph_dictionary_get(VALUE self, VALUE key) {
  char value[DICTIONARY_VALUE_LEN];
  ph_raise(PhidgetDictionary_get((PhidgetDictionaryHandle)get_ph_handle(self), StringValueCStr(key), value, DICTIONARY_VALUE_LEN));
  return rb_str_new2(value);
}

VALUE ph_dictionary_remove(VALUE self, VALUE key) {
  ph_raise(PhidgetDictionary_remove((PhidgetDictionaryHandle)get_ph_handle(self), StringValueCStr(key)));
  return Qnil;
}

VALUE ph_dictionary_remove_all(VALUE self) {
  ph_raise(PhidgetDictionary_removeAll((PhidgetDictionaryHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_dictionary_scan(VALUE self, VALUE start_key) {
  char list[DICTIONARY_VALUE_LEN * 10];
  ph_raise(PhidgetDictionary_scan((PhidgetDictionaryHandle)get_ph_handle(self), StringValueCStr(start_key), list, DICTIONARY_VALUE_LEN * 10));
  return rb_str_new2(list);
}

VALUE ph_dictionary_set(VALUE self, VALUE key, VALUE value) {
  ph_raise(PhidgetDictionary_set((PhidgetDictionaryHandle)get_ph_handle(self), StringValueCStr(key), StringValueCStr(value)));
  return Qnil;
}

VALUE ph_dictionary_update(VALUE self, VALUE key, VALUE value) {
  ph_raise(PhidgetDictionary_update((PhidgetDictionaryHandle)get_ph_handle(self), StringValueCStr(key), StringValueCStr(value)));
  return Qnil;
}


void CCONV ph_dictionary_on_add(PhidgetDictionaryHandle phid, void *userPtr, const char *key, const char *value) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = rb_str_new2(key);
  callback_data->arg2 = rb_str_new2(value);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_dictionary_set_on_add_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DICTIONARY_ADD_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDictionary_setOnAddHandler((PhidgetDictionaryHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDictionary_setOnAddHandler((PhidgetDictionaryHandle)ph->handle, ph_dictionary_on_add, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_dictionary_on_remove(PhidgetDictionaryHandle phid, void *userPtr, const char *key) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = rb_str_new2(key);
  callback_data->arg2 = Qnil;
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_dictionary_set_on_remove_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DICTIONARY_REMOVE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDictionary_setOnRemoveHandler((PhidgetDictionaryHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDictionary_setOnRemoveHandler((PhidgetDictionaryHandle)ph->handle, ph_dictionary_on_remove, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_dictionary_on_update(PhidgetDictionaryHandle phid, void *userPtr, const char *key, const char *value) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = rb_str_new2(key);
  callback_data->arg2 = rb_str_new2(value);
  callback_data->arg3 = Qnil;
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_dictionary_set_on_update_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->dev_callbacks[DICTIONARY_UPDATE_CALLBACK];
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetDictionary_setOnUpdateHandler((PhidgetDictionaryHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetDictionary_setOnUpdateHandler((PhidgetDictionaryHandle)ph->handle, ph_dictionary_on_update, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}




void Init_dictionary() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_dictionary = rb_define_class_under(ph_module, "Dictionary", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Dictionary object.
   */
  rb_define_method(ph_dictionary, "initialize", ph_dictionary_init, 0);

  /* Document-method: add
   * call-seq: add(key, value)
   *
   * Adds a new key value pair to the dictionary. It is an error if the key already exits.
   */
  rb_define_method(ph_dictionary, "add", ph_dictionary_add, 2);

  /* Document-method: get
   * call-seq: get(key) -> value
   *
   * Gets a key value. If more then one key matches, only the first value is returned.
   */
  rb_define_method(ph_dictionary, "get", ph_dictionary_get, 1);

  /* Document-method: remove
   * call-seq: remove(key)
   *
   * Removes the key from the dictionary.
   */
  rb_define_method(ph_dictionary, "remove", ph_dictionary_remove, 1);

  /* Document-method: removeAll
   * call-seq: removeAll
   *
   * Removes every key from the dictionary.
   */
  rb_define_method(ph_dictionary, "removeAll", ph_dictionary_remove_all, 0);
  rb_define_alias(ph_dictionary, "remove_all", "removeAll");

  /* Document-method: scan
   * call-seq: scan(start_key)
   *
   * Scans the keys in the dictionary, indexed by start or the first key in the dictionary if start is NULL or an empty String.
   * The result is formated as a newline seperated list of keys
   * The list begins at the key following the start key
   * The list might not contain all of the keys in the dictionary
   * To continue scanning, call the method again with the last entry from the previous result
   * When all of the keys have been scanned, a zero length string is returned
   * Keys added during the scan may be missed, and keys deleted during the scan may be included.
   */
  rb_define_method(ph_dictionary, "scan", ph_dictionary_scan, 1);

  /* Document-method: set
   * call-seq: set(key, value)
   *
   * Sets the value of a key, or creates the key value pair if the key does not already exist.
   */
  rb_define_method(ph_dictionary, "set", ph_dictionary_set, 2);

  /* Document-method: update
   * call-seq: update(key, value)
   *
   * Updates a key value pair in the dictionary. It is an error if the key does not exist.
   */
  rb_define_method(ph_dictionary, "update", ph_dictionary_update, 2);


  rb_define_private_method(ph_dictionary, "ext_setOnAddHandler", ph_dictionary_set_on_add_handler, 1);
  rb_define_private_method(ph_dictionary, "ext_setOnRemoveHandler", ph_dictionary_set_on_remove_handler, 1);
  rb_define_private_method(ph_dictionary, "ext_setOnUpdateHandler", ph_dictionary_set_on_update_handler, 1);
}
