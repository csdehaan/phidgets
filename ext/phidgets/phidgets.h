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
void Init_dictionary();
void Init_manager();
void Init_common();
void Init_accelerometer();
void Init_advanced_servo();
void Init_analog();
void Init_bridge();
void Init_encoder();
void Init_frequency_counter();
void Init_gps();
void Init_interface_kit();
void Init_ir();
void Init_led();
void Init_motor_control();
void Init_ph_sensor();
void Init_rfid();
void Init_servo();
void Init_spatial();
void Init_stepper();
void Init_temperature_sensor();
void Init_text_lcd();
void Init_text_led();
void Init_weight_sensor();


ph_data_t *get_ph_data(VALUE self);
CPhidgetHandle get_ph_handle(VALUE self);
void ph_raise(int err_code);

#endif

