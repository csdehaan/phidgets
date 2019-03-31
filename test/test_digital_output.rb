require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsDigitalOutput < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::DigitalOutput.new
  end

  def test_get_duty_cycle
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.duty_cycle}
  end

  def test_set_duty_cycle
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.duty_cycle = 2.5}
  end

  def test_set_duty_cycle_async
    assert_nothing_raised {@phidget.set_duty_cycle_async(2.5) {puts 'duty_cycle_set'}}
  end

  def test_get_min_duty_cycle
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_duty_cycle}
  end

  def test_get_max_duty_cycle
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_duty_cycle}
  end

  def test_get_led_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.led_current_limit}
  end

  def test_set_led_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.led_current_limit = 2.5}
  end

  def test_set_led_current_limit_async
    assert_nothing_raised {@phidget.set_led_current_limit_async(2.5) {puts 'led_current_limit_set'}}
  end

  def test_get_min_led_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_led_current_limit}
  end

  def test_get_max_led_current_limit
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_led_current_limit}
  end

  def test_get_led_forward_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.led_forward_voltage}
  end

  def test_set_led_forward_voltage
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.led_forward_voltage = Phidgets::DigitalOutput::LED_FORWARD_VOLTAGE_2_75V}
  end

  def test_get_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.state}
  end

  def test_set_state
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.state = true}
  end

  def test_set_state_async
    assert_nothing_raised {@phidget.set_state_async(true) {puts 'state_set'}}
  end

end

