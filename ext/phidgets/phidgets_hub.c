
#include "phidgets.h"


VALUE ph_hub_init(VALUE self) {
  ph_data_t *ph = get_ph_data(self);
  ph_raise(PhidgetHub_create((PhidgetHubHandle *)(&(ph->handle))));
  return self;
}


VALUE ph_hub_set_port_power(VALUE self, VALUE port, VALUE state) {
  ph_raise(PhidgetHub_setPortPower((PhidgetHubHandle)get_ph_handle(self), NUM2INT(port), TYPE(state) == T_TRUE ? PTRUE : PFALSE));
  return Qnil;
}



void Init_hub() {
  VALUE ph_module = rb_const_get(rb_cObject, rb_intern("Phidgets"));
  VALUE ph_common = rb_const_get(ph_module, rb_intern("Common"));
  VALUE ph_hub = rb_define_class_under(ph_module, "Hub", ph_common);

  /* Document-method: new
   * call-seq: new
   *
   * Creates a Phidget Hub object.
   */
  rb_define_method(ph_hub, "initialize", ph_hub_init, 0);

  /* Document-method: setPortPower
   * call-seq: setPortPower(port, state)
   *
   * Controls power to the VINT Hub Ports.
   */
  rb_define_method(ph_hub, "setPortPower", ph_hub_set_port_power, 2);
  rb_define_alias(ph_hub, "set_port_power", "setPortPower");
}

