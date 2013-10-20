require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsAdvancedServo < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::AdvancedServo.new}
  end

  def test_get_motor_count
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.motor_count}
  end

  def test_get_acceleration
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.acceleration 1}
  end

  def test_get_acceleration_min
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.acceleration_min 1}
  end

  def test_get_acceleration_max
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.acceleration_max 1}
  end

  def test_set_acceleration
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_acceleration 1, 2.14}
  end

  def test_get_velocity
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.velocity 1}
  end

  def test_get_velocity_min
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.velocity_min 1}
  end

  def test_get_velocity_max
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.velocity_max 1}
  end

  def test_get_velocity_limit
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.velocity_limit 1}
  end

  def test_set_velocity_limit
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_velocity_limit 1, 2.14}
  end

  def test_get_position
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.position 1}
  end

  def test_get_position_min
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.position_min 1}
  end

  def test_get_position_max
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.position_max 1}
  end

  def test_set_position
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_position 1, 2.14}
  end

  def test_set_position_min
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_position_min 1, 2.14}
  end

  def test_set_position_max
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_position_max 1, 2.14}
  end

  def test_get_current
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.current 1}
  end

  def test_get_speed_ramping_on
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.speed_ramping_on? 1}
  end

  def test_set_speed_ramping_on
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_speed_ramping_on 1, true}
  end

  def test_get_engaged
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.engaged? 1}
  end

  def test_set_engaged
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_engaged 1, true}
  end

  def test_get_stopped
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.stopped? 1}
  end

  def test_get_servo_type
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.servo_type 1}
  end

  def test_set_servo_type
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_servo_type 1, Phidgets::AdvancedServo::TOWERPRO_MG90}
  end

  def test_set_servo_parameters
    servo = Phidgets::AdvancedServo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_servo_parameters 1, 0.1, 1.5, 98.5, 5.5}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_velocity_change
      servo = Phidgets::AdvancedServo.new
      assert_nothing_raised {servo.on_velocity_change {puts 'hello'}}
    end

    def test_set_on_position_change
      servo = Phidgets::AdvancedServo.new
      assert_nothing_raised {servo.on_position_change {puts 'hello'}}
    end

    def test_set_on_current_change
      servo = Phidgets::AdvancedServo.new
      assert_nothing_raised {servo.on_current_change {puts 'hello'}}
    end
  end

end

