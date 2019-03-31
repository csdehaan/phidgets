require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsDictionary < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Dictionary.new
  end

  def test_add
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.add('some_key', 'some_value')}
  end

  def test_get
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.get('some_key')}
  end

  def test_remove
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.remove('some_key')}
  end

  def test_remove_all
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.remove_all}
  end

  def test_scan
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.scan('some_key')}
  end

  def test_set
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.set('some_key', 'some_value')}
  end

  def test_update
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.update('some_key', 'some_value')}
  end

  def test_set_on_add
    assert_nothing_raised {@phidget.on_add {puts 'key_added'}}
  end

  def test_set_on_remove
    assert_nothing_raised {@phidget.on_remove {puts 'key_removed'}}
  end

  def test_set_on_update
    assert_nothing_raised {@phidget.on_update {puts 'key_updated'}}
  end

end

