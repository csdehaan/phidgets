require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsLCD < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::LCD.new
  end

  def test_get_backlight
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.backlight}
  end

  def test_set_backlight
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.backlight = 2.5}
  end

  def test_get_min_backlight
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_backlight}
  end

  def test_get_max_backlight
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_backlight}
  end

  def test_set_character_bitmap
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.set_character_bitmap(Phidgets::LCD::FONT_User2, 'A', [0,0,0,1,1,1,0,0,0])}
  end

  def test_get_max_characters
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_characters(Phidgets::LCD::FONT_6x10)}
  end

  def test_clear
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.clear}
  end

  def test_get_contrast
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.contrast}
  end

  def test_set_contrast
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.contrast = 2.5}
  end

  def test_get_min_contrast
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_contrast}
  end

  def test_get_max_contrast
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_contrast}
  end

  def test_copy
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.copy(0, 1, 0, 0, 10, 10, 5, 5, false)}
  end

  def test_get_cursor_blink
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.cursor_blink?}
  end

  def test_set_cursor_blink
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.cursor_blink = true}
  end

  def test_get_cursor_on
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.cursor_on?}
  end

  def test_set_cursor_on
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.cursor_on = true}
  end

  def test_draw_line
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.draw_line(0, 0, 10, 10)}
  end

  def test_draw_pixel
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.draw_pixel(10, 10, Phidgets::LCD::PIXEL_STATE_ON)}
  end

  def test_draw_rect
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.draw_rect(0, 0, 10, 10, true, false)}
  end

  def test_flush
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.flush}
  end

  def test_get_font_size
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.font_size(Phidgets::LCD::FONT_6x10)}
  end

  def test_set_font_size
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.set_font_size(Phidgets::LCD::FONT_6x10, 6, 10)}
  end

  def test_get_frame_buffer
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.frame_buffer}
  end

  def test_set_frame_buffer
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.frame_buffer = 1}
  end

  def test_get_height
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.height}
  end

  def test_init
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.init}
  end

  def test_save_frame_buffer
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.save_frame_buffer(1)}
  end

  def test_get_screen_size
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.screen_size}
  end

  def test_set_screen_size
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.screen_size = Phidgets::LCD::SCREEN_SIZE_4x20}
  end

  def test_get_sleeping
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sleeping?}
  end

  def test_set_sleeping
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sleeping = true}
  end

  def test_get_width
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.width}
  end

  def test_write_bitmap
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.write_bitmap(0, 0, 3, 3, [0,0,0,1,1,1,0,0,0])}
  end

  def test_write_text
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.write_text(Phidgets::LCD::FONT_6x10, 5, 5, "This is a test")}
  end

end

