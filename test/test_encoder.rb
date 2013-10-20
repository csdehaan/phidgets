require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsEncoder < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Encoder.new}
  end

  def test_get_input_count
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.input_count}
  end

  def test_get_input_state
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.input_state 1}
  end

  def test_get_encoder_count
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.encoder_count}
  end

  def test_get_position
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.position 1}
  end

  def test_set_position
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.set_position 1, 1500}
  end

  def test_get_index_position
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.index_position 1}
  end

  def test_get_enabled
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.enabled? 1}
  end

  def test_set_enabled
    encoder = Phidgets::Encoder.new
    assert_raise(Phidgets::Error::NotAttached) {encoder.set_enabled 1, true}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_input_change
      encoder = Phidgets::Encoder.new
      assert_nothing_raised {encoder.on_input_change {puts 'hello'}}
    end

    def test_set_on_position_change
      encoder = Phidgets::Encoder.new
      assert_nothing_raised {encoder.on_position_change {puts 'hello'}}
    end

    def test_set_on_index
      encoder = Phidgets::Encoder.new
      assert_nothing_raised {encoder.on_index {puts 'hello'}}
    end
  end

end

