require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgets < Test::Unit::TestCase

  def setup
  end
  
  def test_library_version
    lib_ver = ""
    assert_nothing_raised {
      lib_ver = Phidgets.getLibraryVersion
    }
    assert lib_ver.split[0] == "Phidget21"
  end
end
