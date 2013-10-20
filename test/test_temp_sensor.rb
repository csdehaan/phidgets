require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsTemperatureSensor < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::TemperatureSensor.new}
  end

  def test_get_temperature_input_count
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.temperature_input_count}
  end

  def test_get_temperature
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.temperature 1}
  end

  def test_get_temperature_min
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.temperature_min 1}
  end

  def test_get_temperature_max
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.temperature_max 1}
  end

  def test_get_temperature_change_trigger
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.temperature_change_trigger 1}
  end

  def test_set_temperature_change_trigger
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.set_temperature_change_trigger 1, 1.5}
  end

  def test_get_potential
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.potential 1}
  end

  def test_get_potential_min
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.potential_min 1}
  end

  def test_get_potential_max
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.potential_max 1}
  end

  def test_get_ambient_temperature
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ambient_temperature}
  end

  def test_get_ambient_temperature_min
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ambient_temperature_min}
  end

  def test_get_ambient_temperature_max
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.ambient_temperature_max}
  end

  def test_get_thermocouple_type
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.thermocouple_type 1}
  end

  def test_set_thermocouple_type
    sensor = Phidgets::TemperatureSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.set_thermocouple_type 1, Phidgets::TemperatureSensor::J_TYPE}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_temperature_change
      sensor = Phidgets::TemperatureSensor.new
      assert_nothing_raised {sensor.on_temperature_change {puts 'hello'}}
    end
  end

end

