require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsSoundSensor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::SoundSensor.new
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

  def test_get_db
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.db}
  end

  def test_get_max_db
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_db}
  end

  def test_get_dba
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.dba}
  end

  def test_get_dbc
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.dbc}
  end

  def test_get_noise_floor
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.noise_floor}
  end

  def test_get_octaves
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.octaves}
  end

  def test_get_spl_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.spl_change_trigger}
  end

  def test_set_spl_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.spl_change_trigger = 2.5}
  end

  def test_get_min_spl_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_spl_change_trigger}
  end

  def test_get_max_spl_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_spl_change_trigger}
  end

  def test_get_spl_range
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.spl_range}
  end

  def test_set_spl_range
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.spl_range = Phidgets::SoundSensor::SPL_RANGE_102dB}
  end

  def test_set_on_spl_change
    assert_nothing_raised {@phidget.on_spl_change {puts 'spl_changed'}}
  end

end

