require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsLED < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::LED.new}
  end

  def test_get_led_count
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.led_count}
  end

  def test_get_current_limit
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.current_limit}
  end

  def test_set_current_limit
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.current_limit = Phidgets::LED::CURRENT_LIMIT_40mA}
  end

  def test_get_voltage
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.voltage}
  end

  def test_set_voltage
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.voltage = Phidgets::LED::VOLTAGE_5_0V}
  end

  def test_get_brightness
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.brightness 1}
  end

  def test_set_brightness
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.set_brightness 1, 100.0}
  end

  def test_get_current_limit_indexed
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.current_limit_indexed 1}
  end

  def test_set_current_limit_indexed
    led = Phidgets::LED.new
    assert_raise(Phidgets::Error::NotAttached) {led.set_current_limit_indexed 1, 50.0}
  end

end

