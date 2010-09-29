
module Phidgets

  extern "int CPhidget_open(void *, int)"
  extern "int CPhidget_openRemote(void *, int, void *, void *)"
  extern "int CPhidget_openRemoteIP(void *, int, void *, int, void *)"
  extern "int CPhidget_close(void *)"
  extern "int CPhidget_delete(void *)"
  extern "int CPhidget_getDeviceName(void *, void *)"
  extern "int CPhidget_getSerialNumber(void *, int *)"
  extern "int CPhidget_getDeviceVersion(void *, int *)"
  extern "int CPhidget_getDeviceStatus(void *, int *)"
  extern "int CPhidget_getDeviceType(void *, void *)"
  extern "int CPhidget_getDeviceLabel(void *, void *)"
  extern "int CPhidget_setDeviceLabel(void *, void *)"
  extern "int CPhidget_waitForAttachment(void *, int)"
  extern "int CPhidget_getServerID(void *, void *)"
  extern "int CPhidget_getServerAddress(void *, void *, int *)"
  extern "int CPhidget_getServerStatus(void *, int *)"
  extern "int CPhidget_getDeviceID(void *, int *)"
  extern "int CPhidget_getDeviceClass(void *, int *)"

  class Common

    # Opens a Phidget.
    # === Parameters
    # * _serial_number_ = Serial number. Specify -1 to open any.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not wait.
    def open(serial_number=-1, timeout=0)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_open', @handle, serial_number.to_i)
      raise Phidgets::Exception.new(r) if r != 0
      waitForAttachment(timeout) if timeout > 0
    end

    # Opens a Phidget remotely by ServerID. Note that this requires Bonjour (mDNS) to be running on both the host and the server.
    # === Parameters
    # * _serial_number_ = Serial number. Specify -1 to open any.
    # * _server_        = Server ID. Specify nil to open any.
    # * _password_      = Password. Can be nil if the server is running unsecured.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not wait.
    def openRemote(serial_number=-1, server=nil, password=nil, timeout=0)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_openRemote', @handle, serial_number.to_i, server, password)
      raise Phidgets::Exception.new(r) if r != 0
      waitForAttachment(timeout) if timeout > 0
    end

    # Opens a Phidget remotely by address and port.
    # === Parameters
    # * _serial_number_ = Serial number. Specify -1 to open any.
    # * _address_       = Address. This can be a hostname or IP address.
    # * _port_          = Port number. Default is 5001.
    # * _password_      = Password. Can be nil if the server is running unsecured.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not wait.
    def openRemoteIP(serial_number, address, port=5001, password=nil, timeout=0)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_openRemoteIP', @handle, serial_number.to_i, address, port.to_i, password)
      raise Phidgets::Exception.new(r) if r != 0
      waitForAttachment(timeout) if timeout > 0
    end

    # Closes a Phidget.
    def close
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_close', @handle)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Frees a Phidget handle.
    def delete
      @handle.free = nil
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_delete', @handle)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the specific name of a Phidget.
    def getDeviceName
      ptr = Phidgets.malloc(SIZEOF_VOIDP)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceName', @handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Gets the serial number of a Phidget.
    def getSerialNumber
      sn = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getSerialNumber', @handle, sn.ref)
      raise Phidgets::Exception.new(r) if r != 0
      sn.free = nil
      sn.to_i
    end

    # Gets the firmware version of a Phidget.
    def getDeviceVersion
      ver = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceVersion', @handle, ver.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ver.free = nil
      ver.to_i
    end

    # Gets the attached status of a Phidget.
    def getDeviceStatus
      stat = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceStatus', @handle, stat.ref)
      raise Phidgets::Exception.new(r) if r != 0
      stat.free = nil
      stat.to_i
    end

    # Gets the type (class) of a Phidget.
    def getDeviceType
      ptr = Phidgets.malloc(SIZEOF_VOIDP)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceType', @handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Gets the label of a Phidget.
    def getDeviceLabel
      ptr = Phidgets.malloc(SIZEOF_VOIDP)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceLabel', @handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Sets the label of a Phidget. Note that this is not supported on very old Phidgets, and not yet supported in Windows.
    # === Parameters
    # * _label_ = A string containing the label to be set.
    def setDeviceLabel(label)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_setDeviceLabel', @handle, label)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Waits for attachment to happen. This can be called right after calling open, as an alternative to using the attach handler.
    # === Parameters
    # * _timeout_ = Time to wait for the attachment. Specify 0 to wait forever.
    def waitForAttachment(timeout)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_waitForAttachment', @handle, timeout.to_i)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the server ID of a remotely opened Phidget. This will fail if the Phidget was opened locally.
    def getServerID
      ptr = Phidgets.malloc(SIZEOF_VOIDP)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getServerID', @handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Gets the address and port of a remotely opened Phidget. This will fail if the Phidget was opened locally.
    def getServerAddress
      ptr = Phidgets.malloc(SIZEOF_VOIDP)
      port = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getServerAddress', @handle, ptr.ref, port.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      port.free = nil
      [ptr.to_s, port.to_i]
    end

    # Gets the connected to server status of a remotely opened Phidget. This will fail if the Phidget was opened locally.
    def getServerStatus
      stat = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getServerStatus', @handle, stat.ref)
      raise Phidgets::Exception.new(r) if r != 0
      stat.free = nil
      stat.to_i
    end

    # Gets the device ID of a Phidget.
    def getDeviceID
      dev = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceID', @handle, dev.ref)
      raise Phidgets::Exception.new(r) if r != 0
      dev.free = nil
      dev.to_i
    end

    # Gets the class of a Phidget.
    def getDeviceClass
      dev = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceClass', @handle, dev.ref)
      raise Phidgets::Exception.new(r) if r != 0
      dev.free = nil
      dev.to_i
    end


    private

    def initialize
      @handle = Phidgets.malloc(SIZEOF_VOIDP)
    end

  end

end

