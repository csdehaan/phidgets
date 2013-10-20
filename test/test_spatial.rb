require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsSpatial < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Spatial.new}
  end

  def test_get_acceleration_axis_count
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.acceleration_axis_count}
  end

  def test_get_gyro_axis_count
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.gyro_axis_count}
  end

  def test_get_compass_axis_count
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.compass_axis_count}
  end

  def test_get_acceleration
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.acceleration 1}
  end

  def test_get_acceleration_min
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.acceleration_min 1}
  end

  def test_get_acceleration_max
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.acceleration_max 1}
  end

  def test_get_angular_rate
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.angular_rate 1}
  end

  def test_get_angular_rate_min
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.angular_rate_min 1}
  end

  def test_get_angular_rate_max
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.angular_rate_max 1}
  end

  def test_get_magnetic_field
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.magnetic_field 1}
  end

  def test_get_magnetic_field_min
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.magnetic_field_min 1}
  end

  def test_get_magnetic_field_max
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.magnetic_field_max 1}
  end

  def test_get_data_rate
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.data_rate}
  end

  def test_get_data_rate_min
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.data_rate_min}
  end

  def test_get_data_rate_max
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.data_rate_max}
  end

  def test_set_data_rate
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.data_rate = 1000}
  end

  def test_zero_gyro
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.zero_gyro}
  end

  def test_set_compass_correction_parameters
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.set_compass_correction_parameters 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0, 1.1, 1.2, 1.3}
  end

  def test_reset_compass_correction_parameters
    spatial = Phidgets::Spatial.new
    assert_raise(Phidgets::Error::NotAttached) {spatial.reset_compass_correction_parameters}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_spatial_data
      spatial = Phidgets::Spatial.new
      assert_nothing_raised {spatial.on_spatial_data {puts 'hello'}}
    end
  end

end

