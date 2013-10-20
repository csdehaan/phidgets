require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsTextLED < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::TextLED.new}
  end

  def test_get_row_count
    led = Phidgets::TextLED.new
    assert_raise(Phidgets::Error::NotAttached) {led.row_count}
  end

  def test_get_column_count
    led = Phidgets::TextLED.new
    assert_raise(Phidgets::Error::NotAttached) {led.column_count}
  end

  def test_get_brightness
    led = Phidgets::TextLED.new
    assert_raise(Phidgets::Error::NotAttached) {led.brightness}
  end

  def test_set_brightness
    led = Phidgets::TextLED.new
    assert_raise(Phidgets::Error::NotAttached) {led.brightness = 57}
  end

  def test_set_display_string
    led = Phidgets::TextLED.new
    assert_raise(Phidgets::Error::NotAttached) {led.display_string 10, 'Hello'}
  end

end

