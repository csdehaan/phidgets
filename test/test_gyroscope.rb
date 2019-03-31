require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsGyroscope < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Gyroscope.new
  end

  def test_get_angular_rate
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.angular_rate}
  end

  def test_get_min_angular_rate
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_angular_rate}
  end

  def test_get_max_angular_rate
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_angular_rate}
  end

  def test_get_axis_count
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.axis_count}
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

  def test_zero
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.zero}
  end

  def test_set_on_angular_rate_update
    assert_nothing_raised {@phidget.on_angular_rate_update {puts 'angular_rate_updated'}}
  end

end

