require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsFrequencyCounter < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::FrequencyCounter.new}
  end

  def test_get_frequency_input_count
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.frequency_input_count}
  end

  def test_get_frequency
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.frequency 1}
  end

  def test_get_total_time
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.total_time 1}
  end

  def test_get_total_count
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.total_count 1}
  end

  def test_timeout
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.timeout 1}
  end

  def test_set_timeout
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.set_timeout 1, 100}
  end

  def test_get_enabled
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.enabled? 1}
  end

  def test_set_enabled
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.set_enabled 1, true}
  end

  def test_get_filter
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.filter 1}
  end

  def test_set_filter
    freq = Phidgets::FrequencyCounter.new
    assert_raise(Phidgets::Error::NotAttached) {freq.set_filter 1, Phidgets::FrequencyCounter::FILTERTYPE_ZERO_CROSSING}
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_count
      freq = Phidgets::FrequencyCounter.new
      assert_nothing_raised {freq.on_count {puts 'hello'}}
    end
  end

end

