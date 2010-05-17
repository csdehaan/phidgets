
module Phidgets

  extern "int CPhidgetServo_create(void *)"
  extern "int CPhidgetServo_getMotorCount(void *, int *)"
  extern "int CPhidgetServo_getPosition(void *, int, double *)"
  extern "int CPhidgetServo_setPosition(void *, int, double)"
  extern "int CPhidgetServo_getPositionMax(void *, int, double *)"
  extern "int CPhidgetServo_getPositionMin(void *, int, double *)"
  extern "int CPhidgetServo_getEngaged(void *, int, int *)"
  extern "int CPhidgetServo_setEngaged(void *, int, int)"

  class Servo < Common

    def initialize(serial_number=-1, timeout=0)
      super()
      create
      open(serial_number, timeout) if timeout > 0
    end

    # Gets the number of motors supported by this controller.
    def getMotorCount
      cnt = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetServo_getMotorCount(@handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets the current position of a motor.
    # === Parameters
    # * _index_ = The motor index.
    def getPosition(index)
      pos = DL.malloc(DL.sizeof('D'))
      r = Phidgets.cPhidgetServo_getPosition(@handle, index, pos.ref)
      raise Phidgets::Exception.new(r) if r != 0
      pos.free = nil
      pos.to_f
    end
    
    # Sets the current position of a motor.
    # === Parameters
    # * _index_   = The motor index.
    # * _position = The motor position.
    def setPosition(index, position)
      r = Phidgets.cPhidgetServo_setPosition(@handle, index, position)
      raise Phidgets::Exception.new(r) if r != 0
    end
    
    # Gets the maximum position that a motor can be set to.
    # === Parameters
    # * _index_ = The motor index.
    def getPositionMax(index)
      pos = DL.malloc(DL.sizeof('D'))
      r = Phidgets.cPhidgetServo_getPositionMax(@handle, index, pos.ref)
      raise Phidgets::Exception.new(r) if r != 0
      pos.free = nil
      pos.to_f
    end
    
    # Gets the minimum position that a motor can be set to.
    # === Parameters
    # * _index_ = The motor index.
    def getPositionMin(index)
      pos = DL.malloc(DL.sizeof('D'))
      r = Phidgets.cPhidgetServo_getPositionMin(@handle, index, pos.ref)
      raise Phidgets::Exception.new(r) if r != 0
      pos.free = nil
      pos.to_f
    end
    
    # Gets the engaged state of a motor. This is whether the motor is powered or not.
    # === Parameters
    # * _index_ = The motor index.
    def getEngaged(index)
      eng = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidgetServo_getEngaged(@handle, index, eng.ref)
      raise Phidgets::Exception.new(r) if r != 0
      eng.free = nil
      eng.to_i
    end

    # Sets the engaged state of a motor. This is whether the motor is powered or not.
    # === Parameters
    # * _index_ = The motor index.
    # * _state_ = The engaged state. Possible values are PTRUE  and PFALSE.
    def setEngaged(index, state)
      r = Phidgets.cPhidgetServo_setEngaged(@handle, index, state)
      raise Phidgets::Exception.new(r) if r != 0
    end

    private

    # Creates a Phidget Servo handle.
    def create
      r = Phidgets.cPhidgetServo_create(@handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

  end

end
