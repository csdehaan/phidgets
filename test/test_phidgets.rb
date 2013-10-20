require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgets < Test::Unit::TestCase
  
  def test_library_version
    lib_ver = ""
    assert_nothing_raised {lib_ver = Phidgets.getLibraryVersion}
    assert lib_ver.split[0] == "Phidget21"
  end
  
  def test_enable_logging
    assert_nothing_raised {Phidgets.enableLogging Phidgets::LOG_ERROR, 'test.log'}
  end
  
  def test_disable_logging
    assert_nothing_raised {Phidgets.disableLogging}
  end
  
  def test_log
    assert_nothing_raised {Phidgets.log Phidgets::LOG_INFO, 'TEST', 'This is a test'}
  end

end
