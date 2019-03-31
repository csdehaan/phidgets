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
  sem_t handler_ready;
  sem_t callback_called;
  volatile bool exit;
  VALUE phidget;
  VALUE callback;
  VALUE arg1;
  VALUE arg2;
  VALUE arg3;
  VALUE arg4;
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
void Init_bldc_motor();
void Init_capacitive_touch();
void Init_current_input();
void Init_dc_motor();
void Init_digital_input();
void Init_digital_output();
void Init_distance();
void Init_encoder();
void Init_frequency_counter();
void Init_gps();
void Init_gyroscope();
void Init_hub();
void Init_humidity();
void Init_ir();
void Init_lcd();
void Init_light();
void Init_magnetometer();
void Init_motor_position_controller();
void Init_ph_sensor();
void Init_power_guard();
void Init_pressure();
void Init_rc_servo();
void Init_rfid();
void Init_resistance();
void Init_sound();
void Init_spatial();
void Init_stepper();
void Init_temperature_sensor();
void Init_voltage_input();
void Init_voltage_output();
void Init_voltage_ratio_input();


ph_data_t *get_ph_data(VALUE self);
PhidgetHandle get_ph_handle(VALUE self);
void ph_raise(int err_code);

typedef PhidgetReturnCode (*phidget_get_int_func)(PhidgetHandle, int *);
typedef PhidgetReturnCode (*phidget_get_uint_func)(PhidgetHandle, uint32_t *);
typedef PhidgetReturnCode (*phidget_get_int64_func)(PhidgetHandle, int64_t *);
typedef PhidgetReturnCode (*phidget_get_uint64_func)(PhidgetHandle, uint64_t *);
typedef PhidgetReturnCode (*phidget_get_bool_func)(PhidgetHandle, int *);
typedef PhidgetReturnCode (*phidget_get_double_func)(PhidgetHandle, double *);
typedef PhidgetReturnCode (*phidget_get_string_func)(PhidgetHandle, const char **);

VALUE ph_get_int(PhidgetHandle handle, phidget_get_int_func func);
VALUE ph_get_uint(PhidgetHandle handle, phidget_get_uint_func func);
VALUE ph_get_int64(PhidgetHandle handle, phidget_get_int64_func func);
VALUE ph_get_uint64(PhidgetHandle handle, phidget_get_uint64_func func);
VALUE ph_get_bool(PhidgetHandle handle, phidget_get_bool_func func);
VALUE ph_get_double(PhidgetHandle handle, phidget_get_double_func func);
VALUE ph_get_string(PhidgetHandle handle, phidget_get_string_func func);

#endif

