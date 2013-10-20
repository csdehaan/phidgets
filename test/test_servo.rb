require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsServo < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Servo.new}
  end

  def test_get_motor_count
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.motor_count}
  end

  def test_get_position
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.position 1}
  end

  def test_get_position_min
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.position_min 1}
  end

  def test_get_position_max
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.position_max 1}
  end

  def test_set_position
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_position 1, 2.14}
  end

  def test_get_engaged
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.engaged? 1}
  end

  def test_set_engaged
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_engaged 1, true}
  end

  def test_get_servo_type
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.servo_type 1}
  end

  def test_set_servo_type
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_servo_type 1, Phidgets::Servo::TOWERPRO_MG90}
  end

  def test_set_servo_parameters
    servo = Phidgets::Servo.new
    assert_raise(Phidgets::Error::NotAttached) {servo.set_servo_parameters 1, 0.1, 1.5, 98.5}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_position_change
      servo = Phidgets::Servo.new
      assert_nothing_raised {servo.on_position_change {puts 'hello'}}
    end
  end

end

