require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsStepper < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Stepper.new
  end

  def test_get_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration}
  end

  def test_set_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration = 0.14}
  end

  def test_get_min_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_acceleration}
  end

  def test_get_max_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_acceleration}
  end

  def test_get_control_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.control_mode}
  end

  def test_set_control_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.control_mode = Phidgets::Stepper::CONTROL_MODE_STEP}
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

  def test_get_engaged
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.engaged?}
  end

  def test_set_engaged
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.engaged = true}
  end

  def test_get_holding_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.holding_current_limit}
  end

  def test_set_holding_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.holding_current_limit = 2.5}
  end

  def test_get_is_moving
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.is_moving?}
  end

  def test_get_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.position}
  end

  def test_get_min_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_position}
  end

  def test_get_max_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_position}
  end

  def test_add_position_offset
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.add_position_offset(5.2)}
  end

  def test_get_rescale_factor
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rescale_factor}
  end

  def test_set_rescale_factor
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.rescale_factor = 2.5}
  end

  def test_get_target_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.target_position}
  end

  def test_set_target_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.target_position = 2.5}
  end

  def test_set_target_position_async
    assert_nothing_raised {@phidget.set_target_position_async(3.3) {puts 'target_position_set'}}
  end

  def test_get_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.velocity}
  end

  def test_get_velocity_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.velocity_limit}
  end

  def test_set_velocity_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.velocity_limit = 2.5}
  end

  def test_get_min_velocity_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_velocity_limit}
  end

  def test_get_max_velocity_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_velocity_limit}
  end

  def test_set_on_position_change
    assert_nothing_raised {@phidget.on_position_change {puts 'position_changed'}}
  end

  def test_set_on_stopped
    assert_nothing_raised {@phidget.on_stopped {puts 'stopped'}}
  end

  def test_set_on_velocity_change
    assert_nothing_raised {@phidget.on_velocity_change {puts 'velocity_changed'}}
  end

end

