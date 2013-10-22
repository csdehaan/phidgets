$:.unshift(File.dirname(__FILE__)) unless
  $:.include?(File.dirname(__FILE__)) || $:.include?(File.expand_path(File.dirname(__FILE__)))

require File.dirname(__FILE__) + '/phidgets.so' if FileTest.exists? "#{File.dirname(__FILE__)}/phidgets.so"

require File.dirname(__FILE__) + '/phidgets/dictionary.rb'
require File.dirname(__FILE__) + '/phidgets/manager.rb'
require File.dirname(__FILE__) + '/phidgets/common.rb'
require File.dirname(__FILE__) + '/phidgets/accelerometer.rb'
require File.dirname(__FILE__) + '/phidgets/advanced_servo.rb'
require File.dirname(__FILE__) + '/phidgets/analog.rb'
require File.dirname(__FILE__) + '/phidgets/bridge.rb'
require File.dirname(__FILE__) + '/phidgets/encoder.rb'
require File.dirname(__FILE__) + '/phidgets/frequency_counter.rb'
require File.dirname(__FILE__) + '/phidgets/gps.rb'
require File.dirname(__FILE__) + '/phidgets/interfacekit.rb'
require File.dirname(__FILE__) + '/phidgets/ir.rb'
require File.dirname(__FILE__) + '/phidgets/led.rb'
require File.dirname(__FILE__) + '/phidgets/motor_control.rb'
require File.dirname(__FILE__) + '/phidgets/ph_sensor.rb'
require File.dirname(__FILE__) + '/phidgets/rfid.rb'
require File.dirname(__FILE__) + '/phidgets/servo.rb'
require File.dirname(__FILE__) + '/phidgets/spatial.rb'
require File.dirname(__FILE__) + '/phidgets/stepper.rb'
require File.dirname(__FILE__) + '/phidgets/temperature_sensor.rb'
require File.dirname(__FILE__) + '/phidgets/text_lcd.rb'
require File.dirname(__FILE__) + '/phidgets/text_led.rb'
require File.dirname(__FILE__) + '/phidgets/weight_sensor.rb'

module Phidgets
  VERSION = '0.1.2'
end
