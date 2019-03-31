require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsDCMotor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::DCMotor.new
  end

  def test_get_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration}
  end

  def test_set_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration = 2.5}
  end

  def test_get_min_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_acceleration}
  end

  def test_get_max_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_acceleration}
  end

  def test_get_back_emf
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.back_emf}
  end

  def test_get_back_emf_sensing_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.back_emf_sensing_state}
  end

  def test_set_back_emf_sensing_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.back_emf_sensing_state = true}
  end

  def test_get_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.braking_strength}
  end

  def test_get_min_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_braking_strength}
  end

  def test_get_max_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_braking_strength}
  end

  def test_get_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.current_limit}
  end

  def test_set_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.current_limit = 2.5}
  end

  def test_get_min_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_current_limit}
  end

  def test_get_max_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_current_limit}
  end

  def test_get_current_regulator_gain
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.current_regulator_gain}
  end

  def test_set_current_regulator_gain
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.current_regulator_gain = 2.5}
  end

  def test_get_min_current_regulator_gain
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_current_regulator_gain}
  end

  def test_get_max_current_regulator_gain
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_current_regulator_gain}
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

  def test_get_fan_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.fan_mode}
  end

  def test_set_fan_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.fan_mode = Phidgets::FAN_MODE_OFF}
  end

  def test_get_target_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.target_braking_strength}
  end

  def test_set_target_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.target_braking_strength = 2.5}
  end

  def test_get_target_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.target_velocity}
  end

  def test_set_target_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.target_velocity = 2.5}
  end

  def test_get_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.velocity}
  end

  def test_get_min_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_velocity}
  end

  def test_get_max_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_velocity}
  end

  def test_set_on_back_emf_change
    assert_nothing_raised {@phidget.on_back_emf_change {puts 'back_emf_changed'}}
  end

  def test_set_on_braking_strength_change
    assert_nothing_raised {@phidget.on_braking_strength_change {puts 'braking_strength_changed'}}
  end

  def test_set_on_velocity_update
    assert_nothing_raised {@phidget.on_velocity_update {puts 'velocity_updated'}}
  end

end

