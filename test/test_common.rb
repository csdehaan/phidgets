require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsCommon < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::CapacitiveTouch.new
  end

  def test_open
    assert_nothing_raised {@phidget.open}
    @phidget.close
  end

  def test_open_wait_for_attachment
    assert_raise(Phidgets::Error::TimedOut) {@phidget.open_wait_for_attachment(1)}
    @phidget.close
  end

  def test_get_attached
    @phidget.open
    assert_false @phidget.attached?
    @phidget.close
  end

  def test_get_device_channel_count
    # There seems to be a bug in the Phidgets Library, calling this before opening the device causes a SEGFAULT
    #assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_channel_count(Phidgets::CHCLASS_NOTHING)}
  end

  def test_get_device_class
    # There seems to be a bug in the Phidgets Library, calling this before opening the device causes a SEGFAULT
    #assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_class}
  end

  def test_get_device_class_name
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_class_name}
  end

  def test_get_device_id
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_id}
  end

  def test_get_device_name
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_name}
  end

  def test_get_device_serial_number
    assert_equal(-1, @phidget.device_serial_number)
  end

  def test_set_device_serial_number
    assert_nothing_raised {@phidget.device_serial_number = 12345}
  end

  def test_get_device_sku
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_sku}
  end

  def test_get_device_version
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_version}
  end

  def test_get_device_label
    assert_nil(@phidget.device_label)
  end

  def test_set_device_label
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.device_label = 'test'}
  end

  def test_write_device_label
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.write_device_label('test')}
  end

  def test_get_channel
    assert_equal(0, @phidget.channel)
  end

  def test_set_channel
    assert_nothing_raised {@phidget.channel = 1}
  end

  def test_get_channel_name
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.channel_name}
  end

  def test_get_channel_class
    assert_equal(Phidgets::CHCLASS_CAPACITIVETOUCH, @phidget.channel_class)
  end

  def test_get_channel_class_name
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.channel_class_name}
  end

  def test_get_channel_subclass
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.channel_subclass}
  end

  def test_get_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval}
  end

  def test_set_data_interval
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.data_interval = 2}
  end

  def test_get_hub_port
    assert_equal(-1, @phidget.hub_port)
  end

  def test_set_hub_port
    assert_nothing_raised {@phidget.hub_port = 2}
  end

  def test_get_hub_port_count
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.hub_port_count}
  end

  def test_get_is_channel
    assert(@phidget.is_channel?)
  end

  def test_get_is_hub_port_device
    assert_false(@phidget.is_hub_port_device?)
  end

  def test_set_is_hub_port_device
    assert_raise(Phidgets::Error::InvalidArg) {@phidget.is_hub_port_device = true}
  end

  def test_get_is_local
    assert_false(@phidget.is_local?)
  end

  def test_set_is_local
    assert_nothing_raised {@phidget.is_local = true}
  end

  def test_get_is_remote
    assert_false(@phidget.is_remote?)
  end

  def test_set_is_remote
    assert_nothing_raised {@phidget.is_remote = true}
  end

  def test_get_server_hostname
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.server_hostname}
  end

  def test_get_server_name
    assert_nil(@phidget.server_name)
  end

  def test_set_server_name
    assert_nothing_raised {@phidget.server_name = 'hostname'}
  end

  def test_get_server_peer_name
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.server_peer_name}
  end

  def test_get_server_unique_name
    assert_raise(Phidgets::Error::DeviceNotAttached) {@phidget.server_unique_name}
  end
  
  def test_set_on_attach
    assert_nothing_raised {@phidget.on_attach {puts 'attached'}}
  end

  def test_set_on_detach
    assert_nothing_raised {@phidget.on_detach {puts 'detached'}}
  end

  def test_set_on_error
    assert_nothing_raised {@phidget.on_error {puts 'error'}}
  end

  def test_set_on_property_change
    assert_nothing_raised {@phidget.on_property_change {puts 'property_changed'}}
  end

end

