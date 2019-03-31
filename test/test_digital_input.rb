require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsDigitalInput < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::DigitalInput.new
  end

  def test_get_input_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.input_mode}
  end

  def test_set_input_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.input_mode = Phidgets::INPUT_MODE_NPN}
  end

  def test_get_power_supply
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_supply}
  end

  def test_set_power_supply
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_supply = Phidgets::POWER_SUPPLY_12V}
  end

  def test_get_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.state}
  end

end

