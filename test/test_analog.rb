require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsAnalog < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Analog.new}
  end

  def test_get_output_count
    analog = Phidgets::Analog.new
    assert_raise(Phidgets::Error::NotAttached) {analog.output_count}
  end

  def test_get_voltage
    analog = Phidgets::Analog.new
    assert_raise(Phidgets::Error::NotAttached) {analog.voltage 1}
  end

  def test_get_voltage_min
    analog = Phidgets::Analog.new
    assert_raise(Phidgets::Error::NotAttached) {analog.voltage_min 1}
  end

  def test_get_voltage_max
    analog = Phidgets::Analog.new
    assert_raise(Phidgets::Error::NotAttached) {analog.voltage_max 1}
  end

  def test_set_voltage
    analog = Phidgets::Analog.new
    assert_raise(Phidgets::Error::NotAttached) {analog.set_voltage 1, 3.3}
  end

  def test_get_enabled
    analog = Phidgets::Analog.new
    assert_raise(Phidgets::Error::NotAttached) {analog.enabled? 1}
  end

  def test_set_enabled
    analog = Phidgets::Analog.new
    assert_raise(Phidgets::Error::NotAttached) {analog.set_enabled 1, true}
  end

end

