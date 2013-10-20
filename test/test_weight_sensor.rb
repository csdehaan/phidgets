require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsWeightSensor < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::WeightSensor.new}
  end

  def test_get_weight
    sensor = Phidgets::WeightSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.weight}
  end

  def test_get_weight_change_trigger
    sensor = Phidgets::WeightSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.weight_change_trigger}
  end

  def test_set_weight_change_trigger
    sensor = Phidgets::WeightSensor.new
    assert_raise(Phidgets::Error::NotAttached) {sensor.weight_change_trigger = 2.2}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_weight_change
      encoder = Phidgets::WeightSensor.new
      assert_nothing_raised {encoder.on_weight_change {puts 'hello'}}
    end
  end

end

