#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <unistd.h>
#include <semaphore.h>

#include <ruby.h>
#include <phidget22.h>

#ifndef _PHIDGETS_EXT_
#define _PHIDGETS_EXT_


#define PH_CALLBACK_POLLING_INTERVAL   100000
#define EPHIDGET_NOTIMPLEMENTED        0x5000


typedef struct ph_callback_data {
  sem_t sem;
  volatile bool exit;
  VALUE phidget;
  VALUE callback;
  VALUE arg1;
  VALUE arg2;
} ph_callback_data_t;

void ph_callback_thread(ph_callback_data_t *callback_data);
void *wait_for_callback(void *arg);
void cancel_wait_for_callback(void *arg);


typedef struct ph_data {
  PhidgetHandle handle;
  ph_callback_data_t attach_callback;
  ph_callback_data_t detach_callback;
  ph_callback_data_t error_callback;
  ph_callback_data_t property_change_callback;
  ph_callback_data_t dev_callbacks[4];
} ph_data_t;


void Init_phidgets();
void Init_logging();
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
void Init_digital_input();
void Init_digital_output();
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
PhidgetHandle get_ph_handle(VALUE self);
void ph_raise(int err_code);

#endif

