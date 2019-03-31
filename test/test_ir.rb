require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsIR < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::IR.new
  end

  def test_get_last_code
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.last_code}
  end

  def test_get_last_learned_code
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.last_learned_code}
  end

  def test_transmit
    code_info = {
      'bitCount' => 256,
      'encoding' => Phidgets::IR::ENCODING_PULSE,
      'length' => Phidgets::IR::LENGTH_CONSTANT,
      'gap' => 10,
      'trail' => 15,
      'header' => [10,20],
      'one' => [30,40],
      'zero' => [50,60],
      'repeat' => [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26],
      'minRepeat' => 30,
      'dutyCycle' => 2.5,
      'carrierFrequency' => 500,
      'toggleMask' => [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33]
    }
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.transmit('123456', code_info)}
  end

  def test_transmit_repeat
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.transmit_repeat}
  end

  def test_transmit_raw
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.transmit_raw([1,2,3], 33000, 50, 100)}
  end

  def test_set_on_code
    assert_nothing_raised {@phidget.on_code {puts 'ir_code'}}
  end

  def test_set_on_learn
    assert_nothing_raised {@phidget.on_learn {puts 'ir_learn'}}
  end

  def test_set_on_raw_data
    assert_nothing_raised {@phidget.on_raw_data {puts 'raw_data'}}
  end

end

