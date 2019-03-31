require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsFrequencyCounter < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::FrequencyCounter.new
  end

  def test_get_count
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.count}
  end

  def test_get_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.enabled?}
  end

  def test_set_enabled
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.enabled = true}
  end

  def test_get_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval}
  end

  def test_set_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval = 2}
  end

  def test_get_min_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_data_interval}
  end

  def test_get_max_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_data_interval}
  end

  def test_get_filter_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.filter_type}
  end

  def test_set_filter_type
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.filter_type = Phidgets::FrequencyCounter::FILTER_TYPE_ZERO_CROSSING}
  end

  def test_get_frequency
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.frequency}
  end

  def test_get_max_frequency
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_frequency}
  end

  def test_get_frequency_cutoff
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.frequency_cutoff}
  end

  def test_set_frequency_cutoff
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.frequency_cutoff = 2.5}
  end

  def test_get_min_frequency_cutoff
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.min_frequency_cutoff}
  end

  def test_get_max_frequency_cutoff
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.max_frequency_cutoff}
  end

  def test_get_input_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.input_mode}
  end

  def test_set_input_mode
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.input_mode = Phidgets::INPUT_MODE_PNP}
  end

  def test_get_power_supply
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_supply}
  end

  def test_set_power_supply
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.power_supply = Phidgets::POWER_SUPPLY_12V}
  end

  def test_reset
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.reset}
  end

  def test_get_time_elapsed
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.time_elapsed}
  end

  def test_set_on_count_change
    assert_nothing_raised {@phidget.on_count_change {puts 'count_changed'}}
  end

  def test_set_on_frequency_change
    assert_nothing_raised {@phidget.on_frequency_change {puts 'frequency_changed'}}
  end

end

