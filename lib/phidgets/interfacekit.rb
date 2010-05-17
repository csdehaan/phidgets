

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
  
  
  class InterfaceKit < Common

    def initialize(serial_number=-1, timeout=0)
      super()
      create
      open(serial_number, timeout) if timeout > 0
    end

    # Gets the number of digital inputs supported by this board.
    def getInputCount
      cnt = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getInputCount(@handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets the state of a digital input.
    # === Parameters
    # * _index_ = The input index.
    def getInputState(index)
      state = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getInputState(@handle, index, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Gets the number of digital outputs supported by this board.
    def getOutputCount
      cnt = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getOutputCount(@handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets the state of a digital output.
    # === Parameters
    # * _index_ = The output index.
    def getOutputState(index)
      state = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getOutputState(@handle, index, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Sets the state of a digital output.
    # === Parameters
    # * _index_ = The output index.
    # * _state_ = The output state. Possible values are PTRUE  and PFALSE.
    def setOutputState(index, state)
      r = Phidgets.cPhidgetInterfaceKit_setOutputState(@handle, index, state)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the number of sensor (analog) inputs supported by this board.
    def getSensorCount
      cnt = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getSensorCount(@handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets a sensor value (0-1000).
    # === Parameters
    # * _index_ = The sensor index.
    def getSensorValue(index)
      state = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getSensorValue(@handle, index, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Gets a sensor raw value (12-bit).
    # === Parameters
    # * _index_ = The sensor index.
    def getSensorRawValue(index)
      state = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getSensorRawValue(@handle, index, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Gets the ratiometric state for this board.
    def getRatiometric
      ratio = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetInterfaceKit_getRatiometric(@handle, ratio.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ratio.free = nil
      ratio.to_i
    end

    # Sets the ratiometric state for this board.
    # === Parameters
    # * _ratiometric_ = The ratiometric state. Possible values are PTRUE  and PFALSE.
    def setRatiometric(ratiometric)
      r = Phidgets.cPhidgetInterfaceKit_setRatiometric(@handle, ratiometric)
      raise Phidgets::Exception.new(r) if r != 0
    end


    private
    
    # Creates a Phidget InterfaceKit handle.
    def create
      r = Phidgets.cPhidgetInterfaceKit_create(@handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

  end

end

