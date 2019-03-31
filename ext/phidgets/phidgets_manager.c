
#include "phidgets.h"


void ph_manager_free(ph_data_t *ph) {
  if (ph && ph->handle) {
    PhidgetManager_close((PhidgetManagerHandle)ph->handle);
    PhidgetManager_delete((PhidgetManagerHandle *)(&(ph->handle)));
    ph->handle = NULL;
  }
  if(ph) {
    sem_destroy(&ph->attach_callback.handler_ready);
    sem_destroy(&ph->attach_callback.callback_called);
    sem_destroy(&ph->detach_callback.handler_ready);
    sem_destroy(&ph->detach_callback.callback_called);
    xfree(ph);
  }
}


VALUE ph_manager_allocate(VALUE klass) {
  ph_data_t *ph;
  VALUE self = Data_Make_Struct(klass, ph_data_t, 0, ph_manager_free, ph);
  memset(ph, 0, sizeof(ph_data_t));
  sem_init(&ph->attach_callback.handler_ready, 0, 0);
  sem_init(&ph->attach_callback.callback_called, 0, 0);
  sem_init(&ph->detach_callback.handler_ready, 0, 0);
  sem_init(&ph->detach_callback.callback_called, 0, 0);
  return self;
}

VALUE ph_manager_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetManager_create((PhidgetManagerHandle *)(&(ph->handle))));
  return self;
}

VALUE ph_manager_open(VALUE self) {
  ph_raise(PhidgetManager_open((PhidgetManagerHandle)get_ph_handle(self)));
  return Qnil;
}

VALUE ph_manager_close(VALUE self) {
  ph_raise(PhidgetManager_close((PhidgetManagerHandle)get_ph_handle(self)));
  return Qnil;
}


void CCONV ph_manager_on_attach(PhidgetManagerHandle phid, void *userPtr, PhidgetHandle channel) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  int32_t device_serial_number;
  int hub_port;
  int channel_index;
  const char *channel_name;
  Phidget_getDeviceSerialNumber(channel, &device_serial_number);
  Phidget_getHubPort(channel, &hub_port);
  Phidget_getChannel(channel, &channel_index);
  Phidget_getChannelName(channel, &channel_name);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = INT2NUM(device_serial_number);
  callback_data->arg2 = INT2NUM(hub_port);
  callback_data->arg3 = INT2NUM(channel_index);
  callback_data->arg4 = rb_str_new2(channel_name);
  sem_post(&callback_data->callback_called);
}


VALUE ph_manager_set_on_attach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->attach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetManager_setOnAttachHandler((PhidgetManagerHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetManager_setOnAttachHandler((PhidgetManagerHandle)ph->handle, ph_manager_on_attach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_manager_on_detach(PhidgetManagerHandle phid, void *userPtr, PhidgetHandle channel) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  int32_t device_serial_number;
  Phidget_ChannelClass channel_class;
  int channel_index;
  Phidget_getDeviceSerialNumber(channel, &device_serial_number);
  Phidget_getChannelClass(channel, &channel_class);
  Phidget_getChannel(channel, &channel_index);
  while(sem_wait(&callback_data->handler_ready)!=0) {};
  callback_data->arg1 = INT2NUM(device_serial_number);
  callback_data->arg2 = INT2NUM(channel_class);
  callback_data->arg3 = INT2NUM(channel_index);
  callback_data->arg4 = Qnil;
  sem_post(&callback_data->callback_called);
}


VALUE ph_manager_set_on_detach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->detach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->callback = T_NIL;
    callback_data->exit = true;
    ph_raise(PhidgetManager_setOnDetachHandler((PhidgetManagerHandle)ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->callback_called);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(PhidgetManager_setOnDetachHandler((PhidgetManagerHandle)ph->handle, ph_manager_on_detach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}



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

  /* Document-method: open
   * call-seq: open
   *
   * Opens the Phidget Manager.
   * Be sure to register Attach and Detach event handlers for the Manager before opening it, to ensure you program doesn't miss the events reported for devices already connected to your system.
   */
  rb_define_method(ph_manager, "open", ph_manager_open, 0);

  /* Document-method: close
   * call-seq: close
   *
   * Closes a Phidget Manager that has been opened. PhidgetManage#close will release the Phidget Manager, and should be called prior to delete.
   */
  rb_define_method(ph_manager, "close", ph_manager_close, 0);

  rb_define_private_method(ph_manager, "ext_setOnAttachHandler", ph_manager_set_on_attach_handler, 1);
  rb_define_private_method(ph_manager, "ext_setOnDetachHandler", ph_manager_set_on_detach_handler, 1);
}

