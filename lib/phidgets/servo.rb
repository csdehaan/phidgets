
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

    # Create a new servo object.
    # === Parameters
    # * _serial_number_ = Serial number of the phidget board to open. Specify -1 to open any.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not call open.
    def initialize(serial_number=-1, timeout=0)
      super()
      create
      open(serial_number, timeout) if timeout > 0
    end

    # Gets the number of motors supported by this controller.
    def getMotorCount
      cnt = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_getMotorCount', @handle, cnt.ref)
      raise Phidgets::Exception.new(r) if r != 0
      cnt.free = nil
      cnt.to_i
    end

    # Gets the current position of a motor.
    # === Parameters
    # * _index_ = The motor index.
    def getPosition(index)
      pos = Phidgets.malloc(SIZEOF_DOUBLE)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_getPosition', @handle, index, pos.ref)
      raise Phidgets::Exception.new(r) if r != 0
      pos.free = nil
      pos.to_f
    end
    
    # Sets the current position of a motor.
    # === Parameters
    # * _index_   = The motor index.
    # * _position = The motor position.
    def setPosition(index, position)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_setPosition', @handle, index, position)
      raise Phidgets::Exception.new(r) if r != 0
    end
    
    # Gets the maximum position that a motor can be set to.
    # === Parameters
    # * _index_ = The motor index.
    def getPositionMax(index)
      pos = Phidgets.malloc(SIZEOF_DOUBLE)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_getPositionMax', @handle, index, pos.ref)
      raise Phidgets::Exception.new(r) if r != 0
      pos.free = nil
      pos.to_f
    end
    
    # Gets the minimum position that a motor can be set to.
    # === Parameters
    # * _index_ = The motor index.
    def getPositionMin(index)
      pos = Phidgets.malloc(SIZEOF_DOUBLE)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_getPositionMin', @handle, index, pos.ref)
      raise Phidgets::Exception.new(r) if r != 0
      pos.free = nil
      pos.to_f
    end
    
    # Gets the engaged state of a motor. This is whether the motor is powered or not.
    # === Parameters
    # * _index_ = The motor index.
    def getEngaged(index)
      eng = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_getEngaged', @handle, index, eng.ref)
      raise Phidgets::Exception.new(r) if r != 0
      eng.free = nil
      eng.to_i
    end

    # Sets the engaged state of a motor. This is whether the motor is powered or not.
    # === Parameters
    # * _index_ = The motor index.
    # * _state_ = The engaged state. Possible values are PTRUE  and PFALSE.
    def setEngaged(index, state)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_setEngaged', @handle, index, state)
      raise Phidgets::Exception.new(r) if r != 0
    end

    private

    # Creates a Phidget Servo handle.
    def create
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetServo_create', @handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

  end

end
