require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsGPS < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::GPS.new
  end

  def test_get_altitude
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.altitude}
  end

  def test_get_date
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.date}
  end

  def test_get_heading
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.heading}
  end

  def test_get_latitude
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.latitude}
  end

  def test_get_longitude
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.longitude}
  end

  def test_get_nmea_data
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.nmea_data}
  end

  def test_get_position_fix_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.position_fix?}
  end

  def test_get_time
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.time}
  end

  def test_get_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.velocity}
  end

  def test_set_on_heading_change
    assert_nothing_raised {@phidget.on_position_change {puts 'heading_changed'}}
  end

  def test_set_on_position_change
    assert_nothing_raised {@phidget.on_position_change {puts 'position_changed'}}
  end

  def test_set_on_position_fix_state_change
    assert_nothing_raised {@phidget.on_position_fix_state_change {puts 'position_fix_state_changed'}}
  end

end

