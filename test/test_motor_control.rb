require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsMotorPositionController < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::MotorPositionController.new
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

  def test_get_dead_band
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.dead_band}
  end

  def test_set_dead_band
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.dead_band = 2.5}
  end

  def test_get_duty_cycle
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.duty_cycle}
  end

  def test_get_engaged
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.engaged?}
  end

  def test_set_engaged
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.engaged = true}
  end

  def test_get_fan_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.fan_mode}
  end

  def test_set_fan_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.fan_mode = Phidgets::FAN_MODE_AUTO}
  end

  def test_get_io_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.io_mode}
  end

  def test_set_io_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.io_mode = Phidgets::Encoder::IO_MODE_LINE_DRIVER_10K}
  end

  def test_get_kd
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.kd}
  end

  def test_set_kd
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.kd = 2.5}
  end

  def test_get_ki
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.ki}
  end

  def test_set_ki
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.ki = 2.5}
  end

  def test_get_kp
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.kp}
  end

  def test_set_kp
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.kp = 2.5}
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

  def test_get_stall_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.stall_velocity}
  end

  def test_set_stall_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.stall_velocity = 33.5}
  end

  def test_get_min_stall_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_stall_velocity}
  end

  def test_get_max_stall_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_stall_velocity}
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

  def test_set_on_duty_cycle_update
    assert_nothing_raised {@phidget.on_duty_cycle_update {puts 'duty_cycle_updated'}}
  end

  def test_set_on_position_change
    assert_nothing_raised {@phidget.on_position_change {puts 'position_changed'}}
  end

end

