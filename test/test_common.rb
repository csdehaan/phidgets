require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsCommon < Test::Unit::TestCase

  def test_open
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open 12345}
    ik.close
  end

  def test_open_with_hash_1
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open :serial_number => 12345}
    ik.close
  end

  def test_open_with_hash_2
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open :label => 'test', :server_id => 'localhost', :password => ''}
    ik.close
  end

  def test_open_with_hash_3
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open :label => 'test', :address => 'localhost', :port => 25000, :password => ''}
    ik.close
  end

  def test_open_with_hash_4
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::InvalidArg) {ik.open :address => 'localhost', :port => 25000, :password => ''}
    ik.close
  end
  
  def test_open_label
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open_label 'test'}
    ik.close
  end

  def test_open_remote
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open_remote 12345, 'localhost', 'password'}
    ik.close
  end

  def test_open_label_remote
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open_label_remote 'test', 'localhost', 'password'}
    ik.close
  end

  def test_open_remote_ip
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open_remote_ip 12345, 'localhost', 25000, 'password'}
    ik.close
  end

  def test_open_label_remote_ip
    ik = Phidgets::InterfaceKit.new
    assert_nothing_raised {ik.open_label_remote_ip 'test', 'localhost', 25000, 'password'}
    ik.close
  end

  def test_wait_for_attachment
    ik = Phidgets::InterfaceKit.new
    ik.open 12345
    assert_raise(Phidgets::Error::Timeout) {ik.wait_for_attachment 1}
    ik.close
  end

  def test_close
    ik = Phidgets::InterfaceKit.new
    ik.open 12345
    assert_nothing_raised {ik.close}
  end

  def test_get_serial_number
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.serial_number}
  end

  def test_get_device_class
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.device_class}
  end

  def test_get_device_id
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.device_id}
  end

  def test_get_device_type
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.device_type}
  end

  def test_get_device_name
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.device_name}
  end

  def test_get_device_version
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.device_version}
  end

  def test_get_device_status
    ik = Phidgets::InterfaceKit.new
    assert_equal(Phidgets::NOTATTACHED, ik.device_status)
  end

  def test_get_device_label
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.device_label}
  end

  def test_set_device_label
    ik = Phidgets::InterfaceKit.new
    assert_raise(Phidgets::Error::NotAttached) {ik.device_label = 'test'}
  end

  def test_get_server_id
    ik = Phidgets::InterfaceKit.new
    ik.open_remote 12345, 'localhost', 'password'
    assert_equal('localhost', ik.server_id)
    ik.close
  end

  def test_get_server_address
    ik = Phidgets::InterfaceKit.new
    ik.open_remote_ip 12345, 'localhost', 25000, 'password'
    assert_equal(['localhost',25000], ik.server_address)
    ik.close
  end

  def test_get_server_status
    ik = Phidgets::InterfaceKit.new
    ik.open_remote 12345, 'localhost', 'password'
    assert_equal(Phidgets::NOTATTACHED, ik.server_status)
    ik.close
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_attach
      ik = Phidgets::InterfaceKit.new
      assert_nothing_raised {ik.on_attach {puts 'hello'}}
    end

    def test_set_on_detach
      ik = Phidgets::InterfaceKit.new
      assert_nothing_raised {ik.on_detach {puts 'goodbye'}}
    end

    def test_set_on_server_connect
      ik = Phidgets::InterfaceKit.new
      assert_nothing_raised {ik.on_server_connect {puts 'hello'}}
    end

    def test_set_on_server_disconnect
      ik = Phidgets::InterfaceKit.new
      assert_nothing_raised {ik.on_server_disconnect {puts 'goodbye'}}
    end
  end

end

