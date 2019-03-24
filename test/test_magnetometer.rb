require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsMagnetometer < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Magnetometer.new
  end

  def test_get_axis_count
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.axis_count}
  end

  def test_set_correction_parameters
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.set_correction_parameters(0,0,0,0,0,0,0,0,0,0,0,0,0)}
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

  def test_get_magnetic_field
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.magnetic_field}
  end

  def test_get_min_magnetic_field
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_magnetic_field}
  end

  def test_get_max_magnetic_field
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_magnetic_field}
  end

  def test_get_magnetic_field_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.magnetic_field_change_trigger}
  end

  def test_set_magnetic_field_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.magnetic_field_change_trigger = 2.5}
  end

  def test_get_min_magnetic_field_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_magnetic_field_change_trigger}
  end

  def test_get_max_magnetic_field_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_magnetic_field_change_trigger}
  end

  def test_reset_correction_parameters
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.reset_correction_parameters}
  end

  def test_save_correction_parameters
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.save_correction_parameters}
  end

  def test_get_timestamp
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.timestamp}
  end

  def test_set_on_magnetic_field_change
    assert_nothing_raised {@phidget.on_magnetic_field_change {puts 'magnetic_field_changed'}}
  end

end

