

module Phidgets

  extern "int CPhidgetInterfaceKit_create(void *)"
  extern "int CPhidgetInterfaceKit_getInputCount(void *, int *)"
  extern "int CPhidgetInterfaceKit_getInputState(void *, int, int *)"
  extern "int CPhidgetInterfaceKit_getOutputCount(void *, int *)"
  extern "int CPhidgetInterfaceKit_getOutputState(void *, int, int *)"
  extern "int CPhidgetInterfaceKit_setOutputState(void *, int, int)"
  extern "int CPhidgetInterfaceKit_getSensorCount(void *, int *)"
  extern "int CPhidgetInterfaceKit_getSensorValue(void *, int, int *)"
  extern "int CPhidgetInterfaceKit_getSensorRawValue(void *, int, int *)"
  extern "int CPhidgetInterfaceKit_getRatiometric(void *, int *)"
  extern "int CPhidgetInterfaceKit_setRatiometric(void *, int)"
  begin
    extern "int CPhidgetInterfaceKit_getDataRate(void *, int, int *)"
    extern "int CPhidgetInterfaceKit_setDataRate(void *, int, int)"
    extern "int CPhidgetInterfaceKit_getDataRateMax(void *, int, int *)"
    extern "int CPhidgetInterfaceKit_getDataRateMin(void *, int, int *)"
  rescue
    $stderr.puts "Warning: Installed phidget library does not support InterfaceKit Data Rates."
  end
  
  
  class InterfaceKit < Common

    # Create a new InterfaceKit object.
    # === Parameters
    # * _serial_number_ = Serial number of the phidget board to open. Specify -1 to open any.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not call open.
    def initialize(serial_number=-1, timeout=0)
      super()
      create
      open(serial_number, timeout) if timeout > 0
    end

    # Gets the number of digital inputs supported by this board.
    def getInputCount
      cnt = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getInputCount', @handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets the state of a digital input.
    # === Parameters
    # * _index_ = The input index.
    def getInputState(index)
      state = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getInputState', @handle, index.to_i, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Gets the number of digital outputs supported by this board.
    def getOutputCount
      cnt = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getOutputCount', @handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets the state of a digital output.
    # === Parameters
    # * _index_ = The output index.
    def getOutputState(index)
      state = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getOutputState', @handle, index.to_i, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Sets the state of a digital output.
    # === Parameters
    # * _index_ = The output index.
    # * _state_ = The output state. Possible values are PTRUE and PFALSE.
    def setOutputState(index, state)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_setOutputState', @handle, index.to_i, state.to_i)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the number of sensor (analog) inputs supported by this board.
    def getSensorCount
      cnt = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getSensorCount', @handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets a sensor value (0-1000).
    # === Parameters
    # * _index_ = The sensor index.
    def getSensorValue(index)
      state = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getSensorValue', @handle, index.to_i, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Gets a sensor raw value (12-bit).
    # === Parameters
    # * _index_ = The sensor index.
    def getSensorRawValue(index)
      state = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getSensorRawValue', @handle, index.to_i, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Gets the ratiometric state for this board.
    def getRatiometric
      ratio = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getRatiometric', @handle, ratio.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ratio.free = nil
      ratio.to_i
    end

    # Sets the ratiometric state for this board.
    # === Parameters
    # * _ratiometric_ = The ratiometric state. Possible values are PTRUE  and PFALSE.
    def setRatiometric(ratiometric)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_setRatiometric', @handle, ratiometric.to_i)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the data rate in milliseconds for an analog input.
    # === Parameters
    # * _index_ = The sensor index.
    def getDataRate(index)
      rate = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getDataRate', @handle, index.to_i, rate.ref)
      raise Phidgets::Exception.new(r) if r != 0
      rate.free = nil
      rate.to_i
    end

    # Sets the data rate for an analog input.
    # === Parameters
    # * _index_ = The sensor index.
    # * _rate_  = The rate in milliseconds.
    def setDataRate(index, rate)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_setDataRate', @handle, index.to_i, rate.to_i)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the maximum supported data rate for an analog input.
    # === Parameters
    # * _index_ = The sensor index.
    def getDataRateMax(index)
      rate = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getDataRateMax', @handle, index.to_i, rate.ref)
      raise Phidgets::Exception.new(r) if r != 0
      rate.free = nil
      rate.to_i
    end

    # Gets the minimum supported data rate for an analog input.
    # === Parameters
    # * _index_ = The sensor index.
    def getDataRateMin(index)
      rate = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_getDataRateMin', @handle, index.to_i, rate.ref)
      raise Phidgets::Exception.new(r) if r != 0
      rate.free = nil
      rate.to_i
    end


    private
    
    # Creates a Phidget InterfaceKit handle.
    def create
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetInterfaceKit_create', @handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

  end

end

