require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsResistanceInput < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::ResistanceInput.new
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

  def test_get_resistance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.resistance}
  end

  def test_get_min_resistance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_resistance}
  end

  def test_get_max_resistance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_resistance}
  end

  def test_get_resistance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.resistance_change_trigger}
  end

  def test_set_resistance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.resistance_change_trigger = 2.5}
  end

  def test_get_min_resistance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_resistance_change_trigger}
  end

  def test_get_max_resistance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_resistance_change_trigger}
  end

  def test_get_rtd_wire_setup
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rtd_wire_setup}
  end

  def test_set_rtd_wire_setup
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rtd_wire_setup = Phidgets::RTD_WIRE_SETUP_3WIRE}
  end

  def test_set_on_resistance_change
    assert_nothing_raised {@phidget.on_resistance_change {puts 'resistance_changed'}}
  end

end

