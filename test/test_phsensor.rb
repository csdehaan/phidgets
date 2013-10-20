require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsPHSensor < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::PHSensor.new}
  end

  def test_get_ph
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ph}
  end

  def test_get_ph_min
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ph_min}
  end

  def test_get_ph_max
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ph_max}
  end

  def test_get_ph_change_trigger
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ph_change_trigger}
  end

  def test_set_ph_change_trigger
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ph_change_trigger = 0.50}
  end

  def test_get_potential
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.potential}
  end

  def test_get_potential_min
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.potential_min}
  end

  def test_get_potential_max
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.potential_max}
  end

  def test_set_temperature
    sensor = Phidgets::PHSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.temperature = 26.5}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_ph_change
      sensor = Phidgets::PHSensor.new
      assert_nothing_raised {sensor.on_ph_change {puts 'hello'}}
    end
  end

end

