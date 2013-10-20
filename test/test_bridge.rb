require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsBridge < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Bridge.new}
  end

  def test_get_input_count
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.input_count}
  end

  def test_get_bridge_value
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.bridge_value 1}
  end

  def test_get_bridge_min
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.bridge_min 1}
  end

  def test_get_bridge_max
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.bridge_max 1}
  end

  def test_get_enabled
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.enabled? 1}
  end

  def test_set_enabled
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.set_enabled 1, true}
  end

  def test_get_gain
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.gain 1}
  end

  def test_set_gain
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.set_gain 1, Phidgets::Bridge::GAIN_8}
  end

  def test_get_data_rate
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.data_rate}
  end

  def test_get_data_rate_min
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.data_rate_min}
  end

  def test_get_data_rate_max
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.data_rate_max}
  end

  def test_set_data_rate
    bridge = Phidgets::Bridge.new
    assert_raise(Phidgets::Error::NotAttached) {bridge.data_rate = 200}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_bridge_data
      bridge = Phidgets::Bridge.new
      assert_nothing_raised {bridge.on_bridge_data {puts 'hello'}}
    end
  end

end

