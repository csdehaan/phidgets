require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsPHSensor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::PHSensor.new
  end

  def test_get_correction_temperature
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.correction_temperature}
  end

  def test_set_correction_temperature
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.correction_temperature = 26.5}
  end

  def test_get_min_correction_temperature
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_correction_temperature}
  end

  def test_get_max_correction_temperature
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_correction_temperature}
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

  def test_get_ph
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.ph}
  end

  def test_get_min_ph
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_ph}
  end

  def test_get_max_ph
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_ph}
  end

  def test_get_ph_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.ph_change_trigger}
  end

  def test_set_ph_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.ph_change_trigger = 0.50}
  end

  def test_get_min_ph_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_ph_change_trigger}
  end

  def test_get_max_ph_change_trigger
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_ph_change_trigger}
  end

  def test_set_on_ph_change
    assert_nothing_raised {@phidget.on_ph_change {puts 'ph_changed'}}
  end

end

