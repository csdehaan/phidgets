

module Phidgets

  extern "int CPhidgetAdvancedServo_create(void *)"

  class AdvancedServo < Common

    # Create a new AdvancedServo object.
    # === Parameters
    # * _serial_number_ = Serial number of the phidget board to open. Specify -1 to open any.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not call open.
    def initialize(serial_number=-1, timeout=0)
      super()
      create
      open(serial_number, timeout) if timeout > 0
    end


    private

    # Creates a Phidget AdvancedServo handle.
    def create
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetAdvancedServo_create', @handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

  end

end

