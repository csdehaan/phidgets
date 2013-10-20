require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsTextLCD < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::TextLCD.new}
  end

  def test_get_row_count
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.row_count}
  end

  def test_get_column_count
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.column_count}
  end

  def test_get_backlight
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.backlight?}
  end

  def test_set_backlight
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.backlight = true}
  end

  def test_get_brightness
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.brightness}
  end

  def test_set_brightness
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.brightness = 55}
  end

  def test_get_contrast
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.contrast}
  end

  def test_set_contrast
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.contrast = 87}
  end

  def test_get_cursor_on
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.cursor_on?}
  end

  def test_set_cursor_on
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.cursor_on = true}
  end

  def test_get_cursor_blink
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.cursor_blink?}
  end

  def test_set_cursor_blink
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.cursor_blink = true}
  end

  def test_set_custom_character
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.custom_character 2, 31, 32}
  end

  def test_set_display_character
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.display_character 5, 10, 'P'}
  end

  def test_set_display_string
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.display_string 10, 'Hello'}
  end

  def test_get_screen_count
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.screen_count}
  end

  def test_get_screen
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.screen}
  end

  def test_set_screen
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.screen = 1}
  end

  def test_get_screen_size
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.screen_size}
  end

  def test_set_screen_size
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.screen_size = 86}
  end

  def test_init_screen
    lcd = Phidgets::TextLCD.new
    assert_raise(Phidgets::Error::NotAttached) {lcd.init_screen}
  end

end

