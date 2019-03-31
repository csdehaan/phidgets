require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsSpatial < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Spatial.new
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

  def test_set_magnetometer_correction_parameters
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.set_magnetometer_correction_parameters( 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3 )}
  end

  def test_reset_magnetometer_correction_parameters
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.reset_magnetometer_correction_parameters}
  end

  def test_save_magnetometer_correction_parameters
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.save_magnetometer_correction_parameters}
  end

  def test_zero_gyro
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.zero_gyro}
  end

  def test_set_on_spatial_data
    assert_nothing_raised {@phidget.on_spatial_data {puts 'spatial_data_received'}}
  end

end

