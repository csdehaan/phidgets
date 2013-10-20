require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsStepper < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Stepper.new}
  end

  def test_get_input_count
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.input_count}
  end

  def test_get_input_state
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.input_state 1}
  end

  def test_get_motor_count
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.motor_count}
  end

  def test_get_acceleration
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.acceleration 1}
  end

  def test_get_acceleration_min
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.acceleration_min 1}
  end

  def test_get_acceleration_max
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.acceleration_max 1}
  end

  def test_set_acceleration
    stepper = Phidgets::Stepper.new
    # ?? assert_raise(Phidgets::Error::NotAttached) {stepper.set_acceleration 1, 0.14}
    assert_raise(Phidgets::Error::OutOfBounds) {stepper.set_acceleration 1, 0.14}
  end

  def test_get_velocity_limit
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.velocity_limit 1}
  end

  def test_set_velocity_limit
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.set_velocity_limit 1, 2.14}
  end

  def test_get_velocity
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.velocity 1}
  end

  def test_get_velocity_min
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.velocity_min 1}
  end

  def test_get_velocity_max
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.velocity_max 1}
  end

  def test_get_target_position
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.target_position 1}
  end

  def test_set_target_position
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.set_target_position 1, 500}
  end

  def test_get_current_position
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.current_position 1}
  end

  def test_set_current_position
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.set_current_position 1, 500}
  end

  def test_get_position_min
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.position_min 1}
  end

  def test_get_position_max
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.position_max 1}
  end

  def test_get_current_limit
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.current_limit 1}
  end

  def test_set_current_limit
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.set_current_limit 1, 10.7}
  end

  def test_get_current
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.current 1}
  end

  def test_get_current_min
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.current_min 1}
  end

  def test_get_current_max
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.current_max 1}
  end

  def test_get_engaged
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.engaged? 1}
  end

  def test_set_engaged
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.set_engaged 1, true}
  end

  def test_get_stopped
    stepper = Phidgets::Stepper.new
    assert_raise(Phidgets::Error::NotAttached) {stepper.stopped? 1}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_input_change
      stepper = Phidgets::Stepper.new
      assert_nothing_raised {stepper.on_input_change {puts 'hello'}}
    end

    def test_set_on_velocity_change
      stepper = Phidgets::Stepper.new
      assert_nothing_raised {stepper.on_velocity_change {puts 'hello'}}
    end

    def test_set_on_position_change
      stepper = Phidgets::Stepper.new
      assert_nothing_raised {stepper.on_position_change {puts 'hello'}}
    end

    def test_set_on_current_change
      stepper = Phidgets::Stepper.new
      assert_nothing_raised {stepper.on_current_change {puts 'hello'}}
    end
  end

end

