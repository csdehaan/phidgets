require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsPressureSensor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::PressureSensor.new
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

  def test_get_pressure
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.pressure}
  end

  def test_get_min_pressure
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_pressure}
  end

  def test_get_max_pressure
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_pressure}
  end

  def test_get_pressure_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.pressure_change_trigger}
  end

  def test_set_pressure_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.pressure_change_trigger = 2.5}
  end

  def test_get_min_pressure_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_pressure_change_trigger}
  end

  def test_get_max_pressure_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_pressure_change_trigger}
  end

  def test_set_on_pressure_change
    assert_nothing_raised {@phidget.on_pressure_change {puts 'pressure_changed'}}
  end

end

