require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsPowerGuard < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::PowerGuard.new
  end

  def test_get_fan_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.fan_mode}
  end

  def test_set_fan_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.fan_mode = Phidgets::FAN_MODE_AUTO}
  end

  def test_get_over_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.over_voltage}
  end

  def test_set_over_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.over_voltage = 12}
  end

  def test_get_min_over_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_over_voltage}
  end

  def test_get_max_over_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_over_voltage}
  end

  def test_get_power_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_enabled}
  end

  def test_set_power_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_enabled = false}
  end

end

