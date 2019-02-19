
#include "phidgets.h"


VALUE ph_common_allocate(VALUE klass);
void  ph_common_free(ph_data_t *ph);
VALUE ph_common_open(VALUE self);
VALUE ph_common_open_wait_for_attachment(VALUE self, VALUE milliseconds);
VALUE ph_common_get_attached(VALUE self);
VALUE ph_common_close(VALUE self);
VALUE ph_common_get_device_channel_count(VALUE self, VALUE channel_class);
VALUE ph_common_get_device_class(VALUE self);
VALUE ph_common_get_device_class_name(VALUE self);
VALUE ph_common_get_device_id(VALUE self);
VALUE ph_common_get_device_name(VALUE self);
VALUE ph_common_get_device_serial_number(VALUE self);
VALUE ph_common_set_device_serial_number(VALUE self, VALUE serial_number);
VALUE ph_common_get_device_sku(VALUE self);
VALUE ph_common_get_device_version(VALUE self);
VALUE ph_common_get_device_label(VALUE self);
VALUE ph_common_set_device_label(VALUE self, VALUE label);
VALUE ph_common_write_device_label(VALUE self, VALUE label);
VALUE ph_common_get_channel(VALUE self);
VALUE ph_common_set_channel(VALUE self, VALUE channel);
VALUE ph_common_get_channel_name(VALUE self);
VALUE ph_common_get_channel_class(VALUE self);
VALUE ph_common_get_channel_class_name(VALUE self);
VALUE ph_common_get_channel_subclass(VALUE self);
VALUE ph_common_get_data_interval(VALUE self);
VALUE ph_common_set_data_interval(VALUE self, VALUE interval);
VALUE ph_common_get_hub_port(VALUE self);
VALUE ph_common_set_hub_port(VALUE self, VALUE hub_port);
VALUE ph_common_get_hub_port_count(VALUE self);
VALUE ph_common_get_is_channel(VALUE self);
VALUE ph_common_get_is_hub_port_device(VALUE self);
VALUE ph_common_set_is_hub_port_device(VALUE self, VALUE is_hub_port_device);
VALUE ph_common_get_is_local(VALUE self);
VALUE ph_common_set_is_local(VALUE self, VALUE is_local);
VALUE ph_common_get_is_remote(VALUE self);
VALUE ph_common_set_is_remote(VALUE self, VALUE is_remote);

VALUE ph_common_get_server_hostname(VALUE self);
VALUE ph_common_get_server_name(VALUE self);
VALUE ph_common_set_server_name(VALUE self, VALUE server_name);
VALUE ph_common_get_server_peer_name(VALUE self);
VALUE ph_common_get_server_unique_name(VALUE self);

VALUE ph_common_set_on_attach_handler(VALUE self, VALUE handler);
VALUE ph_common_set_on_detach_handler(VALUE self, VALUE handler);
VALUE ph_common_set_on_error_handler(VALUE self, VALUE handler);
VALUE ph_common_set_on_property_change_handler(VALUE self, VALUE handler);
void CCONV ph_common_on_attach(PhidgetHandle phid, void *userPtr);
void CCONV ph_common_on_detach(PhidgetHandle phid, void *userPtr);
void CCONV ph_common_on_error(PhidgetHandle phid, void *userPtr, Phidget_ErrorEventCode code, const char* description);
void CCONV ph_common_on_property_change(PhidgetHandle phid, void *userPtr, const char *propertyName);


void Init_common() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_define_class_under(ph_module, "Common", rb_cObject);
  rb_define_alloc_func(ph_common, ph_common_allocate);

  /* Document-method: open
   * call-seq: open
   *
   * Opens the Phidget channel. The specific channel to be opened can be specified by setting any of the following properties:
   *    DeviceSerialNumber
   *    DeviceLabel
   *    Channel
   *    HubPort
   *    IsHubPortDevice
   *    ServerName
   *    IsLocal
   *    IsRemote
   *
   * open will return immediately, with the attachment process proceeding asynchronously. Use the Attach event or Attached property to determine when the channel is ready to use.
   */
  rb_define_method(ph_common, "open", ph_common_open, 0);

  /* Document-method: openWaitForAttachment
   * call-seq: openWaitForAttachment(milliseconds)
   *
   * Opens the Phidget channel and waits a defined amount of time for the device to attach.The specific channel to be opened can be specified by setting any of the following properties:
   *    DeviceSerialNumber
   *    DeviceLabel
   *    Channel
   *    HubPort
   *    IsHubPortDevice
   *    ServerName
   *    IsLocal
   *    IsRemote
   *
   * openWaitForAttachment will block until the channel is attached or a timeout occurs. A timeout value of 0 will wait forever.
   */
  rb_define_method(ph_common, "openWaitForAttachment", ph_common_open_wait_for_attachment, 1);
  rb_define_alias(ph_common, "open_wait_for_attachment", "openWaitForAttachment");

  /* Document-method: getAttached
   * call-seq: getAttached -> status
   *
   * Gets the attached status of channel. A Phidget is attached after it has been opened and the Phidget library finds and connects to the corresponding hardware device.
   */
  rb_define_method(ph_common, "getAttached", ph_common_get_attached, 0);
  rb_define_alias(ph_common, "attached?", "getAttached");

  /* Document-method: close
   * call-seq: close
   *
   * Closes a Phidget channel that has been opened.
   */
  rb_define_method(ph_common, "close", ph_common_close, 0);

  /* Document-method: getDeviceChannelCount
   * call-seq: getDeviceChannelCount(channel_class) -> channel_count
   *
   * Gets the number of channels of the specified channel class on the device. Pass Phidgets::CHCLASS_NOTHING to get the total number of channels.
   */
  rb_define_method(ph_common, "getDeviceChannelCount", ph_common_get_device_channel_count, 1);
  rb_define_alias(ph_common, "device_channel_count", "getDeviceChannelCount");

  /* Document-method: getDeviceClass
   * call-seq: getDeviceClass -> device_class
   *
   * Gets the device class for the Phidget which this channel is a part of.
   */
  rb_define_method(ph_common, "getDeviceClass", ph_common_get_device_class, 0);
  rb_define_alias(ph_common, "device_class", "getDeviceClass");

  /* Document-method: getDeviceClassName
   * call-seq: getDeviceClassName -> device_class_name
   *
   * Gets the name of the device class for the Phidget which this channel is a part of.
   */
  rb_define_method(ph_common, "getDeviceClassName", ph_common_get_device_class_name, 0);
  rb_define_alias(ph_common, "device_class_name", "getDeviceClassName");

  /* Document-method: getDeviceID
   * call-seq: getDeviceID -> device_id
   *
   * Gets the DeviceID for the Phidget which this channel is a part of.
   */
  rb_define_method(ph_common, "getDeviceID", ph_common_get_device_id, 0);
  rb_define_alias(ph_common, "device_id", "getDeviceID");

  /* Document-method: getDeviceName
   * call-seq: getDeviceName -> device_name
   *
   * Gets the name of the Phidget which this channel is a part of.
   */
  rb_define_method(ph_common, "getDeviceName", ph_common_get_device_name, 0);
  rb_define_alias(ph_common, "device_name", "getDeviceName");

  /* Document-method: getDeviceSerialNumber
   * call-seq: getDeviceSerialNumber -> serial_number
   *
   * Gets the serial number of the Phidget which this channel is a part of.
   * If the channel is part of a VINT device, this will be the serial number of the VINT Hub the device is attached to.
   */
  rb_define_method(ph_common, "getDeviceSerialNumber", ph_common_get_device_serial_number, 0);
  rb_define_alias(ph_common, "device_serial_number", "getDeviceSerialNumber");

  /* Document-method: setDeviceSerialNumber
   * call-seq: setDeviceSerialNumber(serial_number)
   *
   * Specifies the serial number of the Phidget to be opened. Leave un-set, or set to Phidgets::SERIALNUMBER_ANY to open any serial number.
   * If the channel is part of a VINT device, this will be the serial number of the VINT Hub the device is attached to.
   *
   * If setting this property, it must be set before the channel is opened. The behaviour of setting this property while the channel is open is undefined.
   */
  rb_define_method(ph_common, "setDeviceSerialNumber", ph_common_set_device_serial_number, 1);
  rb_define_alias(ph_common, "device_serial_number=", "setDeviceSerialNumber");

  /* Document-method: getDeviceSKU
   * call-seq: getDeviceSKU -> device_sku
   *
   * Gets the SKU (part number) of the Phidget which this channel is a part of.
   */
  rb_define_method(ph_common, "getDeviceSKU", ph_common_get_device_sku, 0);
  rb_define_alias(ph_common, "device_sku", "getDeviceSKU");

  /* Document-method: getDeviceVersion
   * call-seq: getDeviceVersion -> version
   *
   * Gets the firmware version of the Phidget which this channel is a part of.
   */
  rb_define_method(ph_common, "getDeviceVersion", ph_common_get_device_version, 0);
  rb_define_alias(ph_common, "device_version", "getDeviceVersion");

  /* Document-method: getDeviceLabel
   * call-seq: getDeviceLabel -> label
   *
   * Gets the label of the Phidget which this channel is a part of. A device label is a custom string used to more easily identify a Phidget.
   * Labels are written to a Phidget using writeDeviceLabel().
   */
  rb_define_method(ph_common, "getDeviceLabel", ph_common_get_device_label, 0);
  rb_define_alias(ph_common, "device_label", "getDeviceLabel");

  /* Document-method: setDeviceLabel
   * call-seq: setDeviceLabel(label)
   *
   * Specifies the label of the Phidget to be opened. Leave un-set to open any label. A device label is a custom string used to more easily identify a Phidget.
   * Labels are written to a Phidget using writeDeviceLabel().
   */
  rb_define_method(ph_common, "setDeviceLabel", ph_common_write_device_label, 1);
  rb_define_alias(ph_common, "device_label=", "setDeviceLabel");

  /* Document-method: writeDeviceLabel
   * call-seq: writeDeviceLabel(label)
   *
   * Writes a label to the device in the form of a string in the device flash memory. This label can then be used to identify the device, and will persist across power cycles.
   */
  rb_define_method(ph_common, "writeDeviceLabel", ph_common_write_device_label, 1);
  rb_define_alias(ph_common, "write_device_label", "writeDeviceLabel");

  /* Document-method: getChannel
   * call-seq: getChannel -> channel
   *
   * Gets the channel index of the channel on the device.
   */
  rb_define_method(ph_common, "getChannel", ph_common_get_channel, 0);
  rb_define_alias(ph_common, "channel", "getChannel");

  /* Document-method: setChannel
   * call-seq: setChannel(channel)
   *
   * Specifies the channel index to be opened. The default channel is 0. Set to PHIDGET_CHANNEL_ANY to open any channel on the specified device.
   *
   * If setting this property, it must be set before the channel is opened. The behaviour of setting this property while the channel is open is undefined.
   */
  rb_define_method(ph_common, "setChannel", ph_common_set_channel, 1);
  rb_define_alias(ph_common, "channel=", "setChannel");

  /* Document-method: getChannelName
   * call-seq: getChannelName -> channel_name
   *
   * Gets the channel's name. This name serves as a description of the specific nature of the channel.
   */
  rb_define_method(ph_common, "getChannelName", ph_common_get_channel_name, 0);
  rb_define_alias(ph_common, "channel_name", "getChannelName");

  /* Document-method: getChannelClass
   * call-seq: getChannelClass -> channel_class
   *
   * Gets the channel class of the channel.
   */
  rb_define_method(ph_common, "getChannelClass", ph_common_get_channel_class, 0);
  rb_define_alias(ph_common, "channel_class", "getChannelClass");

  /* Document-method: getChannelClassName
   * call-seq: getChannelClassName -> channel_class_name
   *
   * Gets the name of the channel class the channel belongs to.
   */
  rb_define_method(ph_common, "getChannelClassName", ph_common_get_channel_class_name, 0);
  rb_define_alias(ph_common, "channel_class_name", "getChannelClassName");

  /* Document-method: getChannelSubclass
   * call-seq: getChannelSubclass -> channel_subclass
   *
   * Gets the subclass for this channel. Allows for identifying channels with specific characteristics without needing to know the exact device and channel index.
   */
  rb_define_method(ph_common, "getChannelSubclass", ph_common_get_channel_subclass, 0);
  rb_define_alias(ph_common, "channel_subclass", "getChannelSubclass");

  /* Document-method: getDataInterval
   * call-seq: getDataInterval -> data_interval
   *
   * Gets the data interval for any channel that supports one. 
   * The DataInterval is the time that must elapse before the channel will fire another data event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between data events can also be affected by the specific change trigger for the channel.
   */
  rb_define_method(ph_common, "getDataInterval", ph_common_get_data_interval, 0);
  rb_define_alias(ph_common, "data_interval", "getDataInterval");

  /* Document-method: setDataInterval
   * call-seq: setDataInterval(data_interval)
   *
   * Sets the data interval for any channel that supports one. 
   * The DataInterval is the time that must elapse before the channel will fire another data event.
   * The data interval is bounded by MinDataInterval and MaxDataInterval.
   * The timing between data events can also be affected by the specific change trigger for the channel.
   */
  rb_define_method(ph_common, "setDataInterval", ph_common_set_data_interval, 1);
  rb_define_alias(ph_common, "data_interval=", "setDataInterval");

  /* Document-method: getHubPort
   * call-seq: getHubPort -> hub_port
   *
   * Gets the hub port index of the VINT Hub port that the channel is attached to.
   */
  rb_define_method(ph_common, "getHubPort", ph_common_get_hub_port, 0);
  rb_define_alias(ph_common, "hub_port", "getHubPort");

  /* Document-method: setHubPort
   * call-seq: setHubPort(hub_port)
   *
   * Specifies the hub port index of the VINT Hub port to open this channel on. Leave un-set, or set to Phidgets::HUBPORT_ANY to open the channel on any VINT Hub port.
   */
  rb_define_method(ph_common, "setHubPort", ph_common_set_hub_port, 1);
  rb_define_alias(ph_common, "hub_port=", "setHubPort");

  /* Document-method: getHubPortCount
   * call-seq: getHubPortCount -> hub_port_count
   *
   * Gets the number of VINT ports present on the VINT Hub that the channel is attached to.
   */
  rb_define_method(ph_common, "getHubPortCount", ph_common_get_hub_port_count, 0);
  rb_define_alias(ph_common, "hub_port_count", "getHubPortCount");

  /* Document-method: getIsChannel
   * call-seq: getIsChannel -> is_channel
   *
   * Returns true if it is a channel. Mostly for use alongside getParent() to distinguish channel handles from device handles.
   */
  rb_define_method(ph_common, "getIsChannel", ph_common_get_is_channel, 0);
  rb_define_alias(ph_common, "is_channel?", "getIsChannel");

  /* Document-method: getIsHubPortDevice
   * call-seq: getIsHubPortDevice -> is_hub_port_device
   *
   * Gets whether this channel is a VINT Hub port channel, or part of a VINT device attached to a hub port.
   */
  rb_define_method(ph_common, "getIsHubPortDevice", ph_common_get_is_hub_port_device, 0);
  rb_define_alias(ph_common, "is_hub_port_device?", "getIsHubPortDevice");

  /* Document-method: setIsHubPortDevice
   * call-seq: setIsHubPortDevice(is_hub_port_device)
   *
   * Specifies whether this channel should be opened on a VINT Hub port directly, or on a VINT device attached to a hub port.
   */
  rb_define_method(ph_common, "setIsHubPortDevice", ph_common_set_is_hub_port_device, 1);
  rb_define_alias(ph_common, "is_hub_port_device=", "setIsHubPortDevice");

  /* Document-method: getIsLocal
   * call-seq: getIsLocal -> is_local
   *
   * Returns true when this channel is attached directly on the local machine, or false otherwise.
   */
  rb_define_method(ph_common, "getIsLocal", ph_common_get_is_local, 0);
  rb_define_alias(ph_common, "is_local?", "getIsLocal");

  /* Document-method: setIsLocal
   * call-seq: setIsLocal(is_local)
   *
   * Set to true if the channel is to be opened locally, and not over a network. If both this and IsRemote are set to False (the default),
   * the channel will be opened either locally or remotely, on whichever matching channel is found first.
   */
  rb_define_method(ph_common, "setIsLocal", ph_common_set_is_local, 0);
  rb_define_alias(ph_common, "is_local=", "setIsLocal");

  /* Document-method: getIsRemote
   * call-seq: getIsRemote -> is_remote
   *
   * Returns true when this channel is attached via a Phidget network server, or false otherwise.
   */
  rb_define_method(ph_common, "getIsRemote", ph_common_get_is_remote, 0);
  rb_define_alias(ph_common, "is_remote?", "getIsRemote");

  /* Document-method: setIsRemote
   * call-seq: setIsRemote(is_remote)
   *
   * Set to true if the channel is to be opened remotely, rather than locally. If both this and IsLocal are set to False (the default),
   * the channel will be opened either locally or remotely, on whichever matching channel is found first.
   */
  rb_define_method(ph_common, "setIsRemote", ph_common_set_is_remote, 0);
  rb_define_alias(ph_common, "is_remote=", "setIsRemote");

  /* Document-method: getServerHostname
   * call-seq: getServerHostname -> server_hostname
   *
   * Gets the hostname of the Phidget network server for network attached Phidgets.
   * Fails if the channel is not connected to a Phidget network server.
   */
  rb_define_method(ph_common, "getServerHostname", ph_common_get_server_hostname, 0);
  rb_define_alias(ph_common, "server_hostname", "getServerHostname");

  /* Document-method: getServerName
   * call-seq: getServerName -> server_name
   *
   * Gets the name of the Phidget network server the channel is attached to, if any. 
   * Fails if the channel is not connected to a Phidget network server.
   */
  rb_define_method(ph_common, "getServerName", ph_common_get_server_name, 0);
  rb_define_alias(ph_common, "server_name", "getServerName");

  /* Document-method: setServerName
   * call-seq: setServerName(server_name)
   *
   * Specifies that this channel will be opened remotely, on a Phidget network server with this name.
   * This function should only be used if you want your Phidget to be found on a specific server, and does not need to be specified if the Phidget can be on any any available server.
   * In order for your program to have access to remote Phidgets, you must use the Networking API to EnableServerDiscovery or AddServer.
   * If setting this property, it must be set before the channel is opened. The behaviour of setting this property while the channel is open is undefined.
   */
  rb_define_method(ph_common, "setServerName", ph_common_set_server_name, 1);
  rb_define_alias(ph_common, "server_name=", "setServerName");

  /* Document-method: getServerPeerName
   * call-seq: getServerPeerName -> peer_name
   *
   * Gets the peer name (address and port) of the Phidget server for network attached Phidgets, formatted as: address:port 
   * Fails if the channel is not connected to a Phidget network server.
   */
  rb_define_method(ph_common, "getServerPeerName", ph_common_get_server_peer_name, 0);
  rb_define_alias(ph_common, "server_peer_name", "getServerPeerName");

  /* Document-method: getServerUniqueName
   * call-seq: getServerUniqueName -> unique_name
   *
   * Gets the unique name for the server the channel is attached to, if any. This is either a unique mDNS name, or the name specified in addServer
   * Fails if the channel is not connected to a Phidget network server.
   */
  rb_define_method(ph_common, "getServerUniqueName", ph_common_get_server_unique_name, 0);
  rb_define_alias(ph_common, "server_unique_name", "getServerUniqueName");

  rb_define_private_method(ph_common, "ext_setOnAttachHandler", ph_common_set_on_attach_handler, 1);
  rb_define_private_method(ph_common, "ext_setOnDetachHandler", ph_common_set_on_detach_handler, 1);
  rb_define_private_method(ph_common, "ext_setOnErrorHandler", ph_common_set_on_error_handler, 1);
  rb_define_private_method(ph_common, "ext_setOnPropertyChangeHandler", ph_common_set_on_property_change_handler, 1);
}



VALUE ph_common_allocate(VALUE klass) {
  ph_data_t *ph;
  VALUE self = Data_Make_Struct(klass, ph_data_t, 0, ph_common_free, ph);
  memset(ph, 0, sizeof(ph_data_t));
  sem_init(&ph->attach_callback.sem, 0, 0);
  sem_init(&ph->detach_callback.sem, 0, 0);
  sem_init(&ph->error_callback.sem, 0, 0);
  sem_init(&ph->property_change_callback.sem, 0, 0);
  sem_init(&ph->dev_callbacks[0].sem, 0, 0);
  sem_init(&ph->dev_callbacks[1].sem, 0, 0);
  sem_init(&ph->dev_callbacks[2].sem, 0, 0);
  sem_init(&ph->dev_callbacks[3].sem, 0, 0);
  return self;
}

void ph_common_free(ph_data_t *ph) {
  if (ph && ph->handle) {
    Phidget_close(ph->handle);
    Phidget_delete(&ph->handle);
    ph->handle = NULL;
  }
  if(ph) {
    sem_destroy(&ph->attach_callback.sem);
    sem_destroy(&ph->detach_callback.sem);
    sem_destroy(&ph->error_callback.sem);
    sem_destroy(&ph->property_change_callback.sem);
    sem_destroy(&ph->dev_callbacks[0].sem);
    sem_destroy(&ph->dev_callbacks[1].sem);
    sem_destroy(&ph->dev_callbacks[2].sem);
    sem_destroy(&ph->dev_callbacks[3].sem);
    xfree(ph);
  }
}

VALUE ph_common_open(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_open(handle));
  return Qnil;
}

VALUE ph_common_open_wait_for_attachment(VALUE self, VALUE milliseconds) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_openWaitForAttachment(handle, NUM2UINT(milliseconds)));
  return Qnil;
}

VALUE ph_common_get_attached(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int device_status;
  ph_raise(Phidget_getAttached(handle, &device_status));
  return (device_status == PTRUE) ? Qtrue : Qfalse;
}

VALUE ph_common_close(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_close(handle));
  return Qnil;
}

VALUE ph_common_get_device_channel_count(VALUE self, VALUE channel_class) {
  PhidgetHandle handle = get_ph_handle(self);
  uint32_t count;
  ph_raise(Phidget_getDeviceChannelCount(handle, NUM2INT(channel_class), &count));
  return UINT2NUM(count);
}

VALUE ph_common_get_device_class(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  Phidget_DeviceClass device_class;
  ph_raise(Phidget_getDeviceClass(handle, &device_class));
  return INT2NUM(device_class);
}

VALUE ph_common_get_device_class_name(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *device_class_name;
  ph_raise(Phidget_getDeviceClassName(handle, &device_class_name));
  return rb_str_new2(device_class_name);
}

VALUE ph_common_get_device_id(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  Phidget_DeviceID device_id;
  ph_raise(Phidget_getDeviceID(handle, &device_id));
  return INT2NUM(device_id);
}

VALUE ph_common_get_device_name(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *device_name;
  ph_raise(Phidget_getDeviceName(handle, &device_name));
  return rb_str_new2(device_name);
}

VALUE ph_common_get_device_serial_number(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int32_t serial;
  ph_raise(Phidget_getDeviceSerialNumber(handle, &serial));
  return INT2NUM(serial);
}

VALUE ph_common_set_device_serial_number(VALUE self, VALUE serial_number) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setDeviceSerialNumber(handle, NUM2INT(serial_number)));
  return Qnil;
}

VALUE ph_common_get_device_sku(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *sku;
  ph_raise(Phidget_getDeviceSKU(handle, &sku));
  return rb_str_new2(sku);
}

VALUE ph_common_get_device_version(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int device_version;
  ph_raise(Phidget_getDeviceVersion(handle, &device_version));
  return INT2NUM(device_version);
}

VALUE ph_common_get_device_label(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *device_label;
  ph_raise(Phidget_getDeviceLabel(handle, &device_label));
  return rb_str_new2(device_label);
}

VALUE ph_common_set_device_label(VALUE self, VALUE label) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setDeviceLabel(handle, StringValueCStr(label)));
  return Qnil;
}

VALUE ph_common_write_device_label(VALUE self, VALUE label) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_writeDeviceLabel(handle, StringValueCStr(label)));
  return Qnil;
}

VALUE ph_common_get_channel(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int channel;
  ph_raise(Phidget_getChannel(handle, &channel));
  return INT2NUM(channel);
}

VALUE ph_common_set_channel(VALUE self, VALUE channel) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setChannel(handle, NUM2INT(channel)));
  return Qnil;
}

VALUE ph_common_get_channel_name(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *name;
  ph_raise(Phidget_getChannelName(handle, &name));
  return rb_str_new2(name);
}

VALUE ph_common_get_channel_class(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  Phidget_ChannelClass class;
  ph_raise(Phidget_getChannelClass(handle, &class));
  return INT2NUM(class);
}

VALUE ph_common_get_channel_class_name(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *name;
  ph_raise(Phidget_getChannelClassName(handle, &name));
  return rb_str_new2(name);
}

VALUE ph_common_get_channel_subclass(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  Phidget_ChannelSubclass subclass;
  ph_raise(Phidget_getChannelSubclass(handle, &subclass));
  return INT2NUM(subclass);
}

VALUE ph_common_get_data_interval(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  uint32_t interval;
  ph_raise(Phidget_getDataInterval(handle, &interval));
  return UINT2NUM(interval);
}

VALUE ph_common_set_data_interval(VALUE self, VALUE interval) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setDataInterval(handle, NUM2UINT(interval)));
  return Qnil;
}

VALUE ph_common_get_hub_port(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int port;
  ph_raise(Phidget_getHubPort(handle, &port));
  return INT2NUM(port);
}

VALUE ph_common_set_hub_port(VALUE self, VALUE hub_port) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setHubPort(handle, NUM2INT(hub_port)));
  return Qnil;
}

VALUE ph_common_get_hub_port_count(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int port_count;
  ph_raise(Phidget_getHubPortCount(handle, &port_count));
  return INT2NUM(port_count);
}

VALUE ph_common_get_is_channel(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int is_channel;
  ph_raise(Phidget_getIsChannel(handle, &is_channel));
  return (is_channel == PTRUE) ? Qtrue : Qfalse;
}

VALUE ph_common_get_is_hub_port_device(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int is_hub_port_device;
  ph_raise(Phidget_getIsHubPortDevice(handle, &is_hub_port_device));
  return (is_hub_port_device == PTRUE) ? Qtrue : Qfalse;
}

VALUE ph_common_set_is_hub_port_device(VALUE self, VALUE is_hub_port_device) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setIsHubPortDevice(handle, NUM2INT(is_hub_port_device)));
  return Qnil;
}

VALUE ph_common_get_is_local(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int is_local;
  ph_raise(Phidget_getIsLocal(handle, &is_local));
  return (is_local == PTRUE) ? Qtrue : Qfalse;
}

VALUE ph_common_set_is_local(VALUE self, VALUE is_local) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setIsLocal(handle, NUM2INT(is_local)));
  return Qnil;
}

VALUE ph_common_get_is_remote(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  int is_remote;
  ph_raise(Phidget_getIsRemote(handle, &is_remote));
  return (is_remote == PTRUE) ? Qtrue : Qfalse;
}

VALUE ph_common_set_is_remote(VALUE self, VALUE is_remote) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setIsRemote(handle, NUM2INT(is_remote)));
  return Qnil;
}

VALUE ph_common_get_server_hostname(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *server_hostname;
  ph_raise(Phidget_getServerHostname(handle, &server_hostname));
  return rb_str_new2(server_hostname);
}

VALUE ph_common_get_server_name(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *server_name;
  ph_raise(Phidget_getServerName(handle, &server_name));
  return rb_str_new2(server_name);
}

VALUE ph_common_set_server_name(VALUE self, VALUE server_name) {
  PhidgetHandle handle = get_ph_handle(self);
  ph_raise(Phidget_setServerName(handle, StringValueCStr(server_name)));
  return Qnil;
}

VALUE ph_common_get_server_peer_name(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *peer_name;
  ph_raise(Phidget_getServerPeerName(handle, &peer_name));
  return rb_str_new2(peer_name);
}

VALUE ph_common_get_server_unique_name(VALUE self) {
  PhidgetHandle handle = get_ph_handle(self);
  const char *unique_name;
  ph_raise(Phidget_getServerUniqueName(handle, &unique_name));
  return rb_str_new2(unique_name);
}

VALUE ph_common_set_on_attach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->attach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(Phidget_setOnAttachHandler(ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(Phidget_setOnAttachHandler(ph->handle, ph_common_on_attach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_common_set_on_detach_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->detach_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(Phidget_setOnDetachHandler(ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(Phidget_setOnDetachHandler(ph->handle, ph_common_on_detach, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_common_set_on_error_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->error_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(Phidget_setOnErrorHandler(ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(Phidget_setOnErrorHandler(ph->handle, ph_common_on_error, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}

VALUE ph_common_set_on_property_change_handler(VALUE self, VALUE handler) {
  ph_data_t *ph = get_ph_data(self);
  ph_callback_data_t *callback_data = &ph->property_change_callback;
  if( TYPE(handler) == T_NIL ) {
    callback_data->exit = true;
    ph_raise(Phidget_setOnPropertyChangeHandler(ph->handle, NULL, (void *)NULL));
    sem_post(&callback_data->sem);
  } else {
    callback_data->exit = false;
    callback_data->phidget = self;
    callback_data->callback = handler;
    ph_raise(Phidget_setOnPropertyChangeHandler(ph->handle, ph_common_on_property_change, (void *)callback_data));
    ph_callback_thread(callback_data);
  }
  return Qnil;
}


void CCONV ph_common_on_attach(PhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = Qnil;
  callback_data->arg2 = Qnil;
  sem_post(&callback_data->sem);
}


void CCONV ph_common_on_detach(PhidgetHandle phid, void *userPtr) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = Qnil;
  callback_data->arg2 = Qnil;
  sem_post(&callback_data->sem);
}


void CCONV ph_common_on_error(PhidgetHandle phid, void *userPtr, Phidget_ErrorEventCode code, const char* description) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = INT2NUM(code);
  callback_data->arg2 = rb_str_new2(description);
  sem_post(&callback_data->sem);
}


void CCONV ph_common_on_property_change(PhidgetHandle phid, void *userPtr, const char *propertyName) {
  ph_callback_data_t *callback_data = ((ph_callback_data_t *)userPtr);
  callback_data->arg1 = rb_str_new2(propertyName);
  callback_data->arg2 = Qnil;
  sem_post(&callback_data->sem);
}

