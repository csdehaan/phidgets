#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>

#include <ruby.h>
#include <phidget21.h>

#ifndef _PHIDGETS_EXT_
#define _PHIDGETS_EXT_


#define PH_CALLBACK_POLLING_INTERVAL   100000
#define EPHIDGET_NOTIMPLEMENTED        PHIDGET_ERROR_CODE_COUNT


#ifdef PH_CALLBACK
typedef struct ph_callback_data {
  volatile bool called;
  volatile bool exit;
  VALUE phidget;
  VALUE callback;
} ph_callback_data_t;

void ph_callback_thread(ph_callback_data_t *callback_data);
VALUE wait_for_callback(void *arg);
void cancel_wait_for_callback(void *arg);
#endif


typedef struct ph_data {
  CPhidgetHandle handle;
#ifdef PH_CALLBACK
  ph_callback_data_t attach_callback;
  ph_callback_data_t detach_callback;
  ph_callback_data_t server_connect_callback;
  ph_callback_data_t server_disconnect_callback;
  ph_callback_data_t dev_callback_1;
  ph_callback_data_t dev_callback_2;
  ph_callback_data_t dev_callback_3;
  ph_callback_data_t dev_callback_4;
  ph_callback_data_t dev_callback_5;
  ph_callback_data_t dev_callback_6;
  ph_callback_data_t dev_callback_7;
  ph_callback_data_t dev_callback_8;
#endif
} ph_data_t;


void Init_phidgets();
VALUE Init_phidgets_dictionary(VALUE ph_module);
VALUE Init_phidgets_manager(VALUE ph_module);
VALUE Init_phidgets_common(VALUE ph_module);
VALUE Init_phidgets_accel(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_advservo(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_analog(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_bridge(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_encoder(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_freq(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_gps(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_ifkit(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_ir(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_led(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_motor_control(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_phsensor(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_rfid(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_servo(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_spatial(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_stepper(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_temp(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_textlcd(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_textled(VALUE ph_module, VALUE ph_common);
VALUE Init_phidgets_weight(VALUE ph_module, VALUE ph_common);


ph_data_t *get_ph_data(VALUE self);
CPhidgetHandle get_ph_handle(VALUE self);
void ph_raise(int err_code);

#endif

