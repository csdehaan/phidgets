require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsMotorControl < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::MotorControl.new}
  end

  def test_get_motor_count
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.motor_count}
  end

  def test_get_velocity
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.velocity 1}
  end

  def test_set_velocity
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.set_velocity 1, 33.5}
  end

  def test_get_acceleration
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.acceleration 1}
  end

  def test_get_acceleration_min
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.acceleration_min 1}
  end

  def test_get_acceleration_max
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.acceleration_max 1}
  end

  def test_set_acceleration
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.set_acceleration 1, 58.9}
  end

  def test_get_current
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.current 1}
  end

  def test_get_input_count
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.input_count}
  end

  def test_get_input_state
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.input_state 1}
  end

  def test_get_encoder_count
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.encoder_count}
  end

  def test_get_encoder_position
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.encoder_position 1}
  end

  def test_set_encoder_position
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.set_encoder_position 1, 1500}
  end

  def test_get_back_emf
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.back_emf 1}
  end

  def test_get_back_emf_sensing_state
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.back_emf_sensing_state 1}
  end

  def test_set_back_emf_sensing_state
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.set_back_emf_sensing_state 1, true}
  end

  def test_get_supply_voltage
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.supply_voltage}
  end

  def test_get_braking
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.braking 1}
  end

  def test_set_braking
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.set_braking 1, 34.5}
  end

  def test_get_sensor_count
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.sensor_count}
  end

  def test_get_sensor_value
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.sensor_value 1}
  end

  def test_get_sensor_raw_value
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.sensor_raw_value 1}
  end

  def test_get_ratiometric
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.ratiometric?}
  end

  def test_set_ratiometric
    motor = Phidgets::MotorControl.new
    assert_raise(Phidgets::Error::NotAttached) {motor.ratiometric = true}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_velocity_change
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_velocity_change {puts 'hello'}}
    end

    def test_set_on_current_change
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_current_change {puts 'hello'}}
    end

    def test_set_on_current_update
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_current_update {puts 'hello'}}
    end

    def test_set_on_input_change
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_input_change {puts 'hello'}}
    end

    def test_set_on_encoder_position_change
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_encoder_position_change {puts 'hello'}}
    end

    def test_set_on_encoder_position_update
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_encoder_position_update {puts 'hello'}}
    end

    def test_set_on_back_emf_update
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_back_emf_update {puts 'hello'}}
    end

    def test_set_on_sensor_update
      motor = Phidgets::MotorControl.new
      assert_nothing_raised {motor.on_sensor_update {puts 'hello'}}
    end
  end

end

