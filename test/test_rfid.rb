require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsRFID < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::RFID.new
  end

  def test_get_antenna_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.antenna_enabled?}
  end

  def test_set_antenna_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.antenna_enabled = true}
  end

  def test_get_last_tag
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.last_tag}
  end

  def test_get_tag_present
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.tag_present?}
  end

  def test_write
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.write 'new_tag', Phidgets::RFID::PROTOCOL_EM4100, false}
  end

  def test_set_on_tag
    assert_nothing_raised {@phidget.on_tag {puts 'tag_found'}}
  end

  def test_set_on_tag_lost
    assert_nothing_raised {@phidget.on_tag_lost {puts 'tag_lost'}}
  end

end

