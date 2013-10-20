require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsDictionary < Test::Unit::TestCase

  def test_create
    assert_nothing_raised {Phidgets::Dictionary.new}
  end

  def test_open_with_hash_1
    dict = Phidgets::Dictionary.new
    assert_nothing_raised {dict.open :server_id => 'localhost', :password => 'password'}
    dict.close
  end

  def test_open_with_hash_2
    dict = Phidgets::Dictionary.new
    assert_nothing_raised {dict.open :address => 'localhost', :port => 25000, :password => 'password'}
    dict.close
  end

  def test_open_with_hash_3
    dict = Phidgets::Dictionary.new
    assert_raise(Phidgets::Error::InvalidArg) {dict.open({})}
    dict.close
  end

  def test_open_remote
    dict = Phidgets::Dictionary.new
    assert_nothing_raised {dict.open_remote 'localhost', 'password'}
    dict.close
  end

  def test_open_remote_ip
    dict = Phidgets::Dictionary.new
    assert_nothing_raised {dict.open_remote_ip 'localhost', 25000, 'password'}
    dict.close
  end

  def test_close
    dict = Phidgets::Dictionary.new
    dict.open_remote 'localhost', 'password'
    assert_nothing_raised {dict.close}
  end

  def test_get_key
    dict = Phidgets::Dictionary.new
    assert_raise(Phidgets::Error::NetworkNotConnected) {dict.get_key 'random_key'}
  end

  def test_add_key
    dict = Phidgets::Dictionary.new
    assert_raise(Phidgets::Error::NetworkNotConnected) {dict.add_key 'random_key', 'random_value', false}
  end

  def test_remove_key
    dict = Phidgets::Dictionary.new
    assert_raise(Phidgets::Error::NetworkNotConnected) {dict.remove_key 'random_key'}
  end

  def test_get_server_id
    dict = Phidgets::Dictionary.new
    dict.open_remote 'localhost', 'password'
    assert_equal('localhost', dict.server_id)
    dict.close
  end

  def test_get_server_address
    dict = Phidgets::Dictionary.new
    dict.open_remote_ip 'localhost', 25000, 'password'
    assert_equal(['localhost',25000], dict.server_address)
    dict.close
  end

  def test_get_server_status
    dict = Phidgets::Dictionary.new
    dict.open_remote 'localhost', 'password'
    assert_equal(Phidgets::NOTATTACHED, dict.server_status)
    dict.close
  end

end

