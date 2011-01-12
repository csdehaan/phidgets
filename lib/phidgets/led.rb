

module Phidgets

  extern "int CPhidgetLED_create(void *)"

  class LED < Common

    # Create a new LED object.
    # === Parameters
    # * _serial_number_ = Serial number of the phidget board to open. Specify -1 to open any.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not call open.
    def initialize(serial_number=-1, timeout=0)
      super()
      create
      open(serial_number, timeout) if timeout > 0
    end


    private

    # Creates a Phidget LED handle.
    def create
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetLED_create', @handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

  end

end

