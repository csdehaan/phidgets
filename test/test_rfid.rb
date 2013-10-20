require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsRFID < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::RFID.new}
  end

  def test_get_output_count
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.output_count}
  end

  def test_get_output_state
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.output_state 1}
  end

  def test_set_output_state
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.set_output_state 1, true}
  end

  def test_get_antenna_on
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.antenna_on?}
  end

  def test_set_antenna_on
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.antenna_on = true}
  end

  def test_get_led_on
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.led_on?}
  end

  def test_set_led_on
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.led_on = true}
  end

  def test_get_last_tag
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.last_tag}
  end

  def test_get_tag_status
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.tag_status}
  end

  def test_write
    rfid = Phidgets::RFID.new
    assert_raise(Phidgets::Error::NotAttached) {rfid.write 'new_tag', Phidgets::RFID::PROTOCOL_EM4100, false}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_tag
      rfid = Phidgets::RFID.new
      assert_nothing_raised {rfid.on_tag {puts 'hello'}}
    end

    def test_set_on_tag_lost
      rfid = Phidgets::RFID.new
      assert_nothing_raised {rfid.on_tag_lost {puts 'goodbye'}}
    end

    def test_set_on_output_change
      rfid = Phidgets::RFID.new
      assert_nothing_raised {rfid.on_output_change {puts 'hello'}}
    end
  end

end

