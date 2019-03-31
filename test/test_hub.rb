require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsHub < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Hub.new
  end

  def test_set_port_power
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.set_port_power(0, true)}
  end

end

