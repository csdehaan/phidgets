

module Phidgets

  extern "int CPhidgetRFID_create(void *)"
  extern "int CPhidgetRFID_getOutputCount(void *, int *)"
  extern "int CPhidgetRFID_getOutputState(void *, int, int *)"
  extern "int CPhidgetRFID_setOutputState(void *, int *)"
  extern "int CPhidgetRFID_getAntennaOn(void *, int, int *)"
  extern "int CPhidgetRFID_setAntennaOn(void *, int, int)"
  extern "int CPhidgetRFID_getLEDOn(void *, int *)"
  extern "int CPhidgetRFID_setLEDOn(void *, int, int *)"
  extern "int CPhidgetRFID_getLastTag(void *, int, int *)"
  extern "int CPhidgetRFID_getTagStatus(void *, int *)"
  extern "int CPhidgetRFID_set_OnTag_Handler(void *, int)"
  extern "int CPhidgetRFID_set_OnTagLost_Handler(void *, int)"
  
  
  class RFID < Common

    # Create a new rfid object.
    # === Parameters
    # * _serial_number_ = Serial number of the phidget board to open. Specify -1 to open any.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not call open.
    def initialize(serial_number=-1, timeout=0)
      super()
      create
      open(serial_number, timeout) if timeout > 0
    end

    # Gets the number of outputs supported by this board.
    def getOutputCount
      cnt = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetRFID_getOutputCount(@handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets the state of an output.
    # === Parameters
    # * _index_ = The output index.
    def getOutputState(index)
      state = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetRFID_getOutputState(@handle, index, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Sets the state of an output.
    # === Parameters
    # * _index_ = The output index.
    # * _state_ = The output state. Possible values are PTRUE  and PFALSE.
    def setOutputState(index, state)
      r = Phidgets.cPhidgetRFID_setOutputState(@handle, index, state)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the state of the antenna.
    def getAntennaOn
      state = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetRFID_getAntennaOn(@handle, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Sets the state of the antenna. Note that the antenna must be enabled before tags will be read.
    # === Parameters
    # * _state_ = The antenna state. Possible values are PTRUE  and PFALSE.
    def setAntennaOn(state)
      r = Phidgets.cPhidgetRFID_setAntennaOn(@handle, state)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the state of the onboard LED.
    def getLedOn
      state = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetRFID_getLEDOn(@handle, state.ref)
      raise Phidgets::Exception.new(r) if r != 0
      state.free = nil
      state.to_i
    end

    # Sets the state of the onboard LED.
    # === Parameters
    # * _state_ = The LED state. Possible values are PTRUE  and PFALSE.
    def setLedOn(state)
      r = Phidgets.cPhidgetRFID_setLEDOn(@handle, state)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the last tag read by the reader. This tag may or may not still be on the reader.
    def getLastTag
      tag = DL.malloc(5)
      r = Phidgets.cPhidgetRFID_getLastTag(@handle, tag)
      raise Phidgets::Exception.new(r) if r != 0
      tag
    end

    # Gets the tag present status. This is whether or not a tag is being read by the reader.
    def getTagStatus
      stat = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetRFID_getTagStatus(@handle, stat.ref)
      raise Phidgets::Exception.new(r) if r != 0
      stat.free = nil
      stat.to_i
    end


    private

    # Creates a Phidget RFID handle.
    def create
      r = Phidgets.cPhidgetRFID_create(@handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

  end

end

