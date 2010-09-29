$:.unshift(File.dirname(__FILE__)) unless
  $:.include?(File.dirname(__FILE__)) || $:.include?(File.expand_path(File.dirname(__FILE__)))

require File.dirname(__FILE__) + '/phidgets/phidgets.rb'
require File.dirname(__FILE__) + '/phidgets/common.rb'
require File.dirname(__FILE__) + '/phidgets/interfacekit.rb'
require File.dirname(__FILE__) + '/phidgets/rfid.rb'
require File.dirname(__FILE__) + '/phidgets/servo.rb'
require File.dirname(__FILE__) + '/phidgets/manager.rb'

module Phidgets
  VERSION = '0.0.5'
end
