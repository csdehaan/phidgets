require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsInterfaceKit < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::InterfaceKit.new}
  end

  def test_get_input_count
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.input_count}
  end

  def test_get_input_state
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.input_state 1}
  end

  def test_get_output_count
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.output_count}
  end

  def test_get_output_state
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.output_state 1}
  end

  def test_set_output_state
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.set_output_state 1, true}
  end

  def test_get_sensor_count
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.sensor_count}
  end

  def test_get_sensor_value
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.sensor_value 1}
  end

  def test_get_sensor_raw_value
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.sensor_raw_value 1}
  end

  def test_get_ratiometric
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.ratiometric?}
  end

  def test_set_ratiometric
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.ratiometric = true}
  end

  def test_get_data_rate
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.data_rate 1}
  end

  def test_get_data_rate_min
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.data_rate_min 1}
  end

  def test_get_data_rate_max
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.data_rate_max 1}
  end

  def test_set_data_rate
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.set_data_rate 1, 5}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_input_change
      ik = Phidgets::InterfaceKit.new
      assert_nothing_raised {ik.on_input_change {puts 'hello'}}
    end

    def test_set_on_output_change
      ik = Phidgets::InterfaceKit.new
      assert_nothing_raised {ik.on_output_change {puts 'hello'}}
    end

    def test_set_on_sensor_change
      ik = Phidgets::InterfaceKit.new
      assert_nothing_raised {ik.on_sensor_change {puts 'hello'}}
    end
  end

end

