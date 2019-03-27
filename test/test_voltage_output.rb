require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsVoltageOutput < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::VoltageOutput.new
  end

  def test_get_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.enabled?}
  end

  def test_set_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.enabled = true}
  end

  def test_get_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage}
  end

  def test_set_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage = 3.3}
  end

  def test_set_voltage_async
    assert_nothing_raised {@phidget.set_voltage_async(3.3) {puts 'voltage_set'}}
  end

  def test_get_min_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_voltage}
  end

  def test_get_max_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_voltage}
  end

  def test_get_voltage_output_range
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_output_range}
  end

  def test_set_voltage_output_range
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_output_range = Phidgets::VoltageOutput::VOLTAGE_OUTPUT_RANGE_5V}
  end

end

