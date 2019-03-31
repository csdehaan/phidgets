require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsVoltageRatioInput < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::VoltageRatioInput.new
  end

  def test_get_bridge_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.bridge_enabled?}
  end

  def test_set_bridge_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.bridge_enabled = true}
  end

  def test_get_bridge_gain
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.bridge_gain}
  end

  def test_set_bridge_gain
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.bridge_gain = Phidgets::VoltageRatioInput::BRIDGE_GAIN_1}
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

  def test_get_sensor_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_type}
  end

  def test_set_sensor_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensor_type = Phidgets::VoltageRatioInput::SENSOR_TYPE_1107}
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

  def test_get_voltage_ratio
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_ratio}
  end

  def test_get_min_voltage_ratio
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_voltage_ratio}
  end

  def test_get_max_voltage_ratio
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_voltage_ratio}
  end

  def test_get_voltage_ratio_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_ratio_change_trigger}
  end

  def test_set_voltage_ratio_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage_ratio_change_trigger = 2.5}
  end

  def test_get_min_voltage_ratio_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_voltage_ratio_change_trigger}
  end

  def test_get_max_voltage_ratio_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_voltage_ratio_change_trigger}
  end

  def test_set_on_sensor_change
    assert_nothing_raised {@phidget.on_sensor_change {puts 'sensor_changed'}}
  end

  def test_set_on_voltage_ratio_change
    assert_nothing_raised {@phidget.on_voltage_ratio_change {puts 'voltage_ratio_changed'}}
  end

end

