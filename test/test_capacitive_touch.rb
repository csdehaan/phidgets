require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsCapacitiveTouch < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::CapacitiveTouch.new
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

  def test_get_is_touched
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.is_touched?}
  end

  def test_get_sensitivity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensitivity}
  end

  def test_set_sensitivity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sensitivity = 2.5}
  end

  def test_get_min_sensitivity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_sensitivity}
  end

  def test_get_max_sensitivity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_sensitivity}
  end

  def test_get_touch_value
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.touch_value}
  end

  def test_get_min_touch_value
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_touch_value}
  end

  def test_get_max_touch_value
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_touch_value}
  end

  def test_get_touch_value_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.touch_value_change_trigger}
  end

  def test_set_touch_value_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.touch_value_change_trigger = 2.5}
  end

  def test_get_min_touch_value_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_touch_value_change_trigger}
  end

  def test_get_max_touch_value_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_touch_value_change_trigger}
  end

  def test_set_on_touch_end
    assert_nothing_raised {@phidget.on_touch_end {puts 'touch_ended'}}
  end

  def test_set_on_touch
    assert_nothing_raised {@phidget.on_touch {puts 'touched'}}
  end

end

