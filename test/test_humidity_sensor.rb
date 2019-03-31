require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsHumiditySensor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::HumiditySensor.new
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

  def test_get_humidity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.humidity}
  end

  def test_get_min_humidity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_humidity}
  end

  def test_get_max_humidity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_humidity}
  end

  def test_get_humidity_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.humidity_change_trigger}
  end

  def test_set_humidity_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.humidity_change_trigger = 2.5}
  end

  def test_get_min_humidity_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_humidity_change_trigger}
  end

  def test_get_max_humidity_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_humidity_change_trigger}
  end

  def test_set_on_humidity_change
    assert_nothing_raised {@phidget.on_humidity_change {puts 'humidity_changed'}}
  end

end

