require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsBLDCMotor < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::BLDCMotor.new
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

  def test_get_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.braking_strength}
  end

  def test_get_min_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_braking_strength}
  end

  def test_get_max_braking_strength
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_braking_strength}
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
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.add_position_offset(2.5)}
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
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.stall_velocity = 2.5}
  end

  def test_get_min_stall_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_stall_velocity}
  end

  def test_get_max_stall_velocity
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_stall_velocity}
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

  def test_set_on_braking_strength_change
    assert_nothing_raised {@phidget.on_braking_strength_change {puts 'braking_strength_changed'}}
  end

  def test_set_on_position_change
    assert_nothing_raised {@phidget.on_position_change {puts 'position_changed'}}
  end

  def test_set_on_velocity_update
    assert_nothing_raised {@phidget.on_velocity_update {puts 'velocity_updated'}}
  end

end

