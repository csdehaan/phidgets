require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsVoltageInput < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::VoltageInput.new
  end

  def test_get_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval}
  end

  def test_set_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval = 2}
  end

  def test_get_min_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_data_interval}
  end

  def test_get_max_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_data_interval}
  end

  def test_get_power_supply
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_supply}
  end

  def test_set_power_supply
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_supply = Phidgets::POWER_SUPPLY_12V}
  end

  def test_get_sensor_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_type}
  end

  def test_set_sensor_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_type = Phidgets::VoltageInput::SENSOR_TYPE_1114}
  end

  def test_get_sensor_unit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_unit}
  end

  def test_get_sensor_value
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_value}
  end

  def test_get_sensor_value_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_value_change_trigger}
  end

  def test_set_sensor_value_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_value_change_trigger = 2.5}
  end

  def test_get_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage}
  end

  def test_get_min_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_voltage}
  end

  def test_get_max_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_voltage}
  end

  def test_get_voltage_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_change_trigger}
  end

  def test_set_voltage_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_change_trigger = 2.5}
  end

  def test_get_min_voltage_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_voltage_change_trigger}
  end

  def test_get_max_voltage_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_voltage_change_trigger}
  end

  def test_get_voltage_range
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_range}
  end

  def test_set_voltage_range
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_range = Phidgets::VoltageInput::VOLTAGE_RANGE_AUTO}
  end

  def test_set_on_sensor_change
    assert_nothing_raised {@phidget.on_sensor_change {puts 'sensor_changed'}}
  end

  def test_set_on_voltage_change
    assert_nothing_raised {@phidget.on_voltage_change {puts 'voltage_changed'}}
  end

end

