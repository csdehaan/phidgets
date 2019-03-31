require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsEncoder < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Encoder.new
  end

  def test_get_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.enabled?}
  end

  def test_set_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.enabled = true}
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

  def test_get_index_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.index_position}
  end

  def test_get_io_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.io_mode}
  end

  def test_set_io_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.io_mode = Phidgets::Encoder::IO_MODE_LINE_DRIVER_2K2}
  end

  def test_get_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.position}
  end

  def test_set_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.position = 1500}
  end

  def test_get_position_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.position_change_trigger}
  end

  def test_set_position_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.position_change_trigger = 500}
  end

  def test_get_min_position_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_position_change_trigger}
  end

  def test_get_max_position_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_position_change_trigger}
  end

  def test_on_position_change
    assert_nothing_raised {@phidget.on_position_change {puts 'position_changed'}}
  end

end

