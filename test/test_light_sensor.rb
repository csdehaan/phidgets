require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsLightSensor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::LightSensor.new
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

  def test_get_illuminance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.illuminance}
  end

  def test_get_min_illuminance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_illuminance}
  end

  def test_get_max_illuminance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_illuminance}
  end

  def test_get_illuminance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.illuminance_change_trigger}
  end

  def test_set_illuminance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.illuminance_change_trigger = 2.5}
  end

  def test_get_min_illuminance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_illuminance_change_trigger}
  end

  def test_get_max_illuminance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_illuminance_change_trigger}
  end

  def test_set_on_illuminance_change
    assert_nothing_raised {@phidget.on_illuminance_change {puts 'illuminance_changed'}}
  end

end

