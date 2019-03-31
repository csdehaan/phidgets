require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsAccelerometer < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Accelerometer.new
  end

  def test_get_axis_count
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.axis_count}
  end

  def test_get_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration}
  end

  def test_get_min_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_acceleration}
  end

  def test_get_max_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_acceleration}
  end

  def test_get_acceleration_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration_change_trigger}
  end

  def test_set_acceleration_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration_change_trigger = 2.5}
  end

  def test_get_min_acceleration_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_acceleration_change_trigger}
  end

  def test_get_max_acceleration_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_acceleration_change_trigger}
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

  def test_get_timestamp
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.timestamp}
  end

  def test_set_on_acceleration_change
    assert_nothing_raised {@phidget.on_acceleration_change {puts 'acceleration_changed'}}
  end

end

