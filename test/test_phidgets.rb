require File.dirname(__FILE__) + '/test_helper.rb'

class TestPhidgets < Test::Unit::TestCase
  
  def test_library_version
    lib_ver = ""
    assert_nothing_raised {lib_ver = Phidgets.library_version}
    assert lib_ver.split[0] == "Phidget22"
  end

end
