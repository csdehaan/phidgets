require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsManager < Test::Unit::TestCase

  def test_open
    manager = Phidgets::Manager.new
    assert_nothing_raised {manager.open}
    manager.close
  end

  def test_open_with_hash_1
    manager = Phidgets::Manager.new
    assert_nothing_raised {manager.open :server_id => 'localhost', :password => ''}
    manager.close
  end

  def test_open_with_hash_2
    manager = Phidgets::Manager.new
    assert_nothing_raised {manager.open :address => 'localhost', :port => 25000, :password => ''}
    manager.close
  end

  def test_open_remote
    manager = Phidgets::Manager.new
    assert_nothing_raised {manager.open_remote 'localhost', 'password'}
    manager.close
  end

  def test_open_remote_ip
    manager = Phidgets::Manager.new
    assert_nothing_raised {manager.open_remote_ip 'localhost', 25000, 'password'}
    manager.close
  end

  def test_close
    manager = Phidgets::Manager.new
    manager.open
    assert_nothing_raised {manager.close}
  end

  def test_get_server_id
    manager = Phidgets::Manager.new
    manager.open_remote 'localhost', 'password'
    assert_equal('localhost', manager.server_id)
    manager.close
  end

  def test_get_server_address
    manager = Phidgets::Manager.new
    manager.open_remote_ip 'localhost', 25000, 'password'
    assert_equal(['localhost',25000], manager.server_address)
    manager.close
  end

  def test_get_server_status
    manager = Phidgets::Manager.new
    manager.open_remote 'localhost', 'password'
    assert_equal(Phidgets::NOTATTACHED, manager.server_status)
    manager.close
  end

  def test_get_attached_devices
    manager = Phidgets::Manager.new
    assert_nothing_raised do
      devices = manager.attached_devices
      assert_equal(0, devices.count)
    end
    manager.close
  end

  unless RUBY_VERSION < '1.9.0'
    def test_set_on_attach
      manager = Phidgets::Manager.new
      assert_nothing_raised {manager.on_attach {puts 'hello'}}
    end

    def test_set_on_detach
      manager = Phidgets::Manager.new
      assert_nothing_raised {manager.on_detach {puts 'goodbye'}}
    end

    def test_set_on_server_connect
      manager = Phidgets::Manager.new
      assert_nothing_raised {manager.on_server_connect {puts 'hello'}}
    end

    def test_set_on_server_disconnect
      manager = Phidgets::Manager.new
      assert_nothing_raised {manager.on_server_disconnect {puts 'goodbye'}}
    end
  end

end

