require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsTemperatureSensor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::TemperatureSensor.new
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

  def test_get_rtd_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rtd_type}
  end

  def test_set_rtd_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rtd_type = Phidgets::TemperatureSensor::RTD_TYPE_PT1000_3850}
  end

  def test_get_rtd_wire_setup
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rtd_wire_setup}
  end

  def test_set_rtd_wire_setup
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rtd_wire_setup = Phidgets::RTD_WIRE_SETUP_3WIRE}
  end

  def test_get_temperature
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.temperature}
  end

  def test_get_min_temperature
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_temperature}
  end

  def test_get_max_temperature
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_temperature}
  end

  def test_get_temperature_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.temperature_change_trigger}
  end

  def test_set_temperature_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.temperature_change_trigger = 1.5}
  end

  def test_get_min_temperature_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_temperature_change_trigger}
  end

  def test_get_max_temperature_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_temperature_change_trigger}
  end

  def test_get_thermocouple_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.thermocouple_type}
  end

  def test_set_thermocouple_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.thermocouple_type = Phidgets::TemperatureSensor::THERMOCOUPLE_TYPE_K}
  end

  def test_set_on_temperature_change
    assert_nothing_raised {@phidget.on_temperature_change {puts 'temperature_changed'}}
  end

end

