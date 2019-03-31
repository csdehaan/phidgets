require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsRCServo < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::RCServo.new
  end

  def test_get_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration}
  end

  def test_set_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.acceleration = 58.9}
  end

  def test_get_min_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_acceleration}
  end

  def test_get_max_acceleration
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_acceleration}
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

  def test_get_is_moving
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.is_moving?}
  end

  def test_get_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.position}
  end

  def test_get_min_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_position}
  end

  def test_set_min_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_position = 2.14}
  end

  def test_get_max_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_position}
  end

  def test_set_max_position
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_position = 12.14}
  end

  def test_get_min_pulse_width
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_pulse_width}
  end

  def test_set_min_pulse_width
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_pulse_width = 2.5}
  end

  def test_get_max_pulse_width
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_pulse_width}
  end

  def test_set_max_pulse_width
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_pulse_width = 2.5}
  end

  def test_get_min_pulse_width_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_pulse_width_limit}
  end

  def test_get_max_pulse_width_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_pulse_width_limit}
  end

  def test_get_speed_ramping_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.speed_ramping_state}
  end

  def test_set_speed_ramping_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.speed_ramping_state = true}
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

  def test_get_torque
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.torque}
  end

  def test_set_torque
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.torque = 2.5}
  end

  def test_get_min_torque
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_torque}
  end

  def test_get_max_torque
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_torque}
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

  def test_get_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage}
  end

  def test_set_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.voltage = 2.5}
  end

  def test_set_on_position_change
    assert_nothing_raised {@phidget.on_position_change {puts 'position_changed'}}
  end

  def test_set_on_target_position_reached
    assert_nothing_raised {@phidget.on_target_position_reached {puts 'target_position_reached'}}
  end

  def test_set_on_velocity_change
    assert_nothing_raised {@phidget.on_velocity_change {puts 'velocity_changed'}}
  end

end

