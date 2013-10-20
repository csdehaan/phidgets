require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsAccelerometer < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Accelerometer.new}
  end

  def test_get_axis_count
    accel = Phidgets::Accelerometer.new
    assert_raise(Phidgets::Error::NotAttached) {accel.axis_count}
  end

  def test_get_acceleration
    accel = Phidgets::Accelerometer.new
    assert_raise(Phidgets::Error::NotAttached) {accel.acceleration 1}
  end

  def test_get_acceleration_min
    accel = Phidgets::Accelerometer.new
    assert_raise(Phidgets::Error::NotAttached) {accel.acceleration_min 1}
  end

  def test_get_acceleration_max
    accel = Phidgets::Accelerometer.new
    assert_raise(Phidgets::Error::NotAttached) {accel.acceleration_max 1}
  end

  def test_get_acceleration_change_trigger
    accel = Phidgets::Accelerometer.new
    assert_raise(Phidgets::Error::NotAttached) {accel.acceleration_change_trigger 1}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_acceleration_change_trigger
      accel = Phidgets::Accelerometer.new
      assert_raise(Phidgets::Error::NotAttached) {accel.set_acceleration_change_trigger 1, 2.5}
    end

    def test_set_on_acceleration_change
      accel = Phidgets::Accelerometer.new
      assert_nothing_raised {accel.on_acceleration_change {puts 'hello'}}
    end
  end

end

