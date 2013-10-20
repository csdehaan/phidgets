require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsIR < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::IR.new}
  end

  def test_transmit
    ir = Phidgets::IR.new
    assert_raise(Phidgets::Error::NotImplemented) {ir.transmit(:data, :info)}
  end

  def test_transmit_repeat
    ir = Phidgets::IR.new
    assert_raise(Phidgets::Error::NotAttached) {ir.transmit_repeat}
  end

  def test_transmit_raw
    ir = Phidgets::IR.new
    assert_raise(Phidgets::Error::NotAttached) {ir.transmit_raw([1,2,3], 33000, 50, 100)}
  end

  def test_get_raw_data
    ir = Phidgets::IR.new
    assert_raise(Phidgets::Error::NotAttached) {ir.raw_data 100}
  end

  def test_get_last_code
    ir = Phidgets::IR.new
    assert_raise(Phidgets::Error::NotImplemented) {ir.last_code}
  end

  def test_get_last_learned_code
    ir = Phidgets::IR.new
    assert_raise(Phidgets::Error::NotImplemented) {ir.last_learned_code}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_code
      ir = Phidgets::IR.new
      assert_nothing_raised {ir.on_code {puts 'hello'}}
    end

    def test_set_on_learn
      ir = Phidgets::IR.new
      assert_nothing_raised {ir.on_learn {puts 'hello'}}
    end

    def test_set_on_raw_data
      ir = Phidgets::IR.new
      assert_nothing_raised {ir.on_raw_data {puts 'hello'}}
    end
  end

end

