require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsCurrentInput < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::CurrentInput.new
  end

  def test_get_current
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.current}
  end

  def test_get_min_current
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_current}
  end

  def test_get_max_current
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_current}
  end

  def test_get_current_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.current_change_trigger}
  end

  def test_set_current_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.current_change_trigger = 2.5}
  end

  def test_get_min_current_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_current_change_trigger}
  end

  def test_get_max_current_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_current_change_trigger}
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

end

