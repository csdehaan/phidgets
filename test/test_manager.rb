require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgetsManager < Test::Unit::TestCase

  def setup
    @phidget = Phidgets::Manager.new
  end

  def test_open
    assert_nothing_raised do
      @phidget.open
      @phidget.close
    end
  end

  def test_set_on_attach
    assert_nothing_raised {@phidget.on_attach {puts 'phidget_attached'}}
  end

  def test_set_on_detach
    assert_nothing_raised {@phidget.on_detach {puts 'phidget_detached'}}
  end

end

