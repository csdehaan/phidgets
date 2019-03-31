require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsDistanceSensor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::DistanceSensor.new
  end

  def test_get_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval}
  end

  def test_set_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval = 2}
  end

  def test_get_min_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_data_interval}
  end

  def test_get_max_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_data_interval}
  end

  def test_get_distance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.distance}
  end

  def test_get_min_distance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_distance}
  end

  def test_get_max_distance
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_distance}
  end

  def test_get_distance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.distance_change_trigger}
  end

  def test_set_distance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.distance_change_trigger = 2.5}
  end

  def test_get_min_distance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_distance_change_trigger}
  end

  def test_get_max_distance_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_distance_change_trigger}
  end

  def test_get_sonar_quiet_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sonar_quiet_mode}
  end

  def test_set_sonar_quiet_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.sonar_quiet_mode = true}
  end

  def test_get_sonar_reflections
    reflections = @phidget.sonar_reflections
    assert_equal([], reflections['distances'])
    assert_equal([], reflections['amplitudes'])
  end

  def test_set_on_distance_change
    assert_nothing_raised {@phidget.on_distance_change {puts 'distance_changed'}}
  end

  def test_set_on_sonar_reflections_update
    assert_nothing_raised {@phidget.on_sonar_reflections_update {puts 'sonar_reflections_updated'}}
  end

end

