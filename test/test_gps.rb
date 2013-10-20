require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsGPS < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::GPS.new}
  end

  def test_get_latitude
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.latitude}
  end

  def test_get_longitude
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.longitude}
  end

  def test_get_altitude
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.altitude}
  end

  def test_get_heading
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.heading}
  end

  def test_get_velocity
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.velocity}
  end

  def test_get_time
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.time}
  end

  def test_get_date
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.date}
  end

  def test_get_position_fix_status
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotAttached) {gps.position_fix_status}
  end

  def test_get_nmea_data
    gps = Phidgets::GPS.new
    assert_raise(Phidgets::Error::NotImplemented) {gps.nmea_data}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_position_change
      gps = Phidgets::GPS.new
      assert_nothing_raised {gps.on_position_change {puts 'hello'}}
    end

    def test_set_on_position_fix_status_change
      gps = Phidgets::GPS.new
      assert_nothing_raised {gps.on_position_fix_status_change {puts 'hello'}}
    end
  end

end

