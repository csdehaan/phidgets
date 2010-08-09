
require 'dl'
require 'dl/import'
require 'rbconfig'


module Phidgets
  extend DL::Importable

  PFALSE                           = 0
  PTRUE                            = 1

  NOTATTACHED                      = 0
  ATTACHED                         = 1

  CLASS_NOTHING                    = 1
  CLASS_ACCELEROMETER              = 2
  CLASS_ADVANCEDSERVO              = 3
  CLASS_ENCODER                    = 4
  CLASS_GPS                        = 5
  CLASS_GYROSCOPE                  = 6
  CLASS_INTERFACEKIT               = 7
  CLASS_LED                        = 8
  CLASS_MOTORCONTROL               = 9
  CLASS_PHSENSOR                   = 10
  CLASS_RFID                       = 11
  CLASS_SERVO                      = 12
  CLASS_STEPPER                    = 13
  CLASS_TEMPERATURESENSOR          = 14 
  CLASS_TEXTLCD                    = 15
  CLASS_TEXTLED                    = 16
  CLASS_WEIGHTSENSOR               = 17

  ID_ACCELEROMETER_2AXIS           = 0x071
  ID_ACCELEROMETER_3AXIS           = 0x07E
  ID_ADVANCEDSERVO_8MOTOR          = 0x03A
  ID_BIPOLAR_STEPPER_1MOTOR        = 0x07B
  ID_ENCODER_1ENCODER_1INPUT       = 0x04B
  ID_ENCODER_HS_1ENCODER           = 0x080
  ID_INTERFACEKIT_0_0_4            = 0x040
  ID_INTERFACEKIT_0_0_8            = 0x081
  ID_INTERFACEKIT_0_16_16          = 0x044
  ID_INTERFACEKIT_8_8_8            = 0x045
  ID_INTERFACEKIT_8_8_8_w_LCD      = 0x07D
  ID_LED_64                        = 0x04A
  ID_LINEAR_TOUCH                  = 0x076
  ID_MOTORCONTROL_HC_2MOTOR        = 0x059
  ID_MOTORCONTROL_LV_2MOTOR_4INPUT = 0x058
  ID_PHSENSOR                      = 0x074
  ID_RFID_2OUTPUT                  = 0x031
  ID_ROTARY_TOUCH                  = 0x077
  ID_SERVO_1MOTOR                  = 0x039
  ID_TEMPERATURESENSOR             = 0x070
  ID_TEXTLCD_2x20_w_8_8_8          = 0x17D
  ID_UNIPOLAR_STEPPER_4MOTOR       = 0x07A
  ID_INTERFACEKIT_0_8_8_w_LCD      = 0x053
  ID_INTERFACEKIT_4_8_8            = 0x004
  ID_RFID                          = 0x030
  ID_SERVO_1MOTOR_OLD              = 0x002
  ID_SERVO_4MOTOR                  = 0x038
  ID_SERVO_4MOTOR_OLD              = 0x003
  ID_TEXTLCD_2x20                  = 0x052
  ID_TEXTLCD_2x20_w_0_8_8          = 0x153
  ID_TEXTLED_1x8                   = 0x049
  ID_TEXTLED_4x8                   = 0x048
  ID_WEIGHTSENSOR                  = 0x072

  PHIDGET_LOG_CRITICAL             = 1
  PHIDGET_LOG_ERROR                = 2
  PHIDGET_LOG_WARNING              = 3
  PHIDGET_LOG_DEBUG                = 4
  PHIDGET_LOG_INFO                 = 5
  PHIDGET_LOG_VERBOSE              = 6

  class Exception < RuntimeError
    attr_reader :code

    EPHIDGET_LOAD_LIB_FAIL         = -2
    EPHIDGET_LIBNAME               = -1
    EPHIDGET_NOTFOUND              = 1
    EPHIDGET_NOMEMORY              = 2
    EPHIDGET_UNEXPECTED            = 3
    EPHIDGET_INVALIDARG            = 4
    EPHIDGET_NOTATTACHED           = 5
    EPHIDGET_INTERRUPTED           = 6
    EPHIDGET_INVALID               = 7
    EPHIDGET_NETWORK               = 8
    EPHIDGET_UNKNOWNVAL            = 9
    EPHIDGET_BADPASSWORD           = 10
    EPHIDGET_UNSUPPORTED           = 11
    EPHIDGET_DUPLICATE             = 12
    EPHIDGET_TIMEOUT               = 13
    EPHIDGET_OUTOFBOUNDS           = 14
    EPHIDGET_EVENT                 = 15
    EPHIDGET_NETWORK_NOTCONNECTED  = 16
    EPHIDGET_WRONGDEVICE           = 17
    EPHIDGET_CLOSED                = 18
    EPHIDGET_BADVERSION            = 19

    def initialize(code)
      @code = code
      case code
        when EPHIDGET_LOAD_LIB_FAIL
          super('Failed to load Phidgets Library')
        when EPHIDGET_LIBNAME
          super('Unable to determine Phidgets Library name.')
        when EPHIDGET_NOTFOUND
          super('A Phidget matching the type and or serial number could not be found.')
        when EPHIDGET_NOMEMORY
          super('Memory could not be allocated.')
        when EPHIDGET_UNEXPECTED
          super('Unexpected Error. Contact Phidgets Inc. for support.')
        when EPHIDGET_INVALIDARG
          super('Invalid argument passed to function.')
        when EPHIDGET_NOTATTACHED
          super('Phidget not physically attached.')
        when EPHIDGET_INTERRUPTED
          super('Read/Write operation was interrupted.')
        when EPHIDGET_INVALID
          super('The Error Code is not defined.')
        when EPHIDGET_NETWORK
          super('Network Error.')
        when EPHIDGET_UNKNOWNVAL
          super('Value is Unknown (State not yet received from device, or not yet set by user).')
        when EPHIDGET_BADPASSWORD
          super('Authorization Failed.')
        when EPHIDGET_UNSUPPORTED
          super('Not Supported.')
        when EPHIDGET_DUPLICATE
          super('Duplicated request.')
        when EPHIDGET_TIMEOUT
          super('Given timeout has been exceeded.')
        when EPHIDGET_OUTOFBOUNDS
          super('Index out of Bounds.')
        when EPHIDGET_EVENT
          super('A non-null error code was returned from an event handler.')
        when EPHIDGET_NETWORK_NOTCONNECTED
          super('A connection to the server does not exist.')
        when EPHIDGET_WRONGDEVICE
          super('Function is not applicable for this device.')
        when EPHIDGET_CLOSED
          super('Phidget handle was closed.')
        when EPHIDGET_BADVERSION
          super('Webservice and Client protocol versions don’t match. Update to newest release.')
      end
    end

  end

  begin
    case Config::CONFIG['target_os']
      when /linux/
        dlload 'libphidget21.so'
      when /mswin/
        dlload 'phidget21.dll'
      when /darwin/
        dlload '/Library/Frameworks/Phidget21.framework/Versions/Current/Phidget21'
      else
        raise Phidgets::Exception.new(Exception::EPHIDGET_LIBNAME)
    end
  rescue
    raise Phidgets::Exception.new(Exception::EPHIDGET_LOAD_LIB_FAIL)
  end

  extern "int CPhidget_openRemote(void *, int, void *, void *)"
  extern "int CPhidget_openRemoteIP(void *, int, void *, int, void *)"
  extern "int CPhidget_open(void *, int)"
  extern "int CPhidget_close(void *)"
  extern "int CPhidget_delete(void *)"
  extern "int CPhidget_set_OnDetach_Handler(void *, void *, void *)"
  extern "int CPhidget_set_OnAttach_Handler(void *, void *, void *)"
  extern "int CPhidget_set_OnServerConnect_Handler(void *, void *, void *)"
  extern "int CPhidget_set_OnServerDisconnect_Handler(void *, void *, void *)"
  extern "int CPhidget_set_OnError_Handler(void *, void *, void *)"
  extern "int CPhidget_getDeviceName(void *, void *)"
  extern "int CPhidget_getSerialNumber(void *, int *)"
  extern "int CPhidget_getDeviceVersion(void *, int *)"
  extern "int CPhidget_getDeviceStatus(void *, int *)"
  extern "int CPhidget_getLibraryVersion(void *)"
  extern "int CPhidget_getDeviceType(void *, void *)"
  extern "int CPhidget_getDeviceLabel(void *, void *)"
  extern "int CPhidget_setDeviceLabel(void *, void *)"
  extern "int CPhidget_getErrorDescription(int, void *)"
  extern "int CPhidget_waitForAttachment(void *, int)"
  extern "int CPhidget_getServerID(void *, void *)"
  extern "int CPhidget_getServerAddress(void *, void *, int *)"
  extern "int CPhidget_getServerStatus(void *, int *)"
  extern "int CPhidget_getDeviceID(void *, int *)"
  extern "int CPhidget_getDeviceClass(void *, int *)"
  extern "int CPhidget_enableLogging(int, char *)"
  extern "int CPhidget_disableLogging()"

  # Gets the library version. This contains a version number and a build date.
  def Phidgets.getLibraryVersion
    ptr = DL.malloc(DL.sizeof('P'))
    r = cPhidget_getLibraryVersion(ptr.ref)
    raise Phidgets::Exception.new(r) if r != 0
    ptr.free = nil
    ptr.to_s
  end

  # Gets the description for an error code.
  def Phidgets.getErrorDescription(error_code)
    ptr = DL.malloc(DL.sizeof('P'))
    r = cPhidget_getErrorDescription(error_code, ptr.ref)
    raise Phidgets::Exception.new(r) if r != 0
    ptr.free = nil
    ptr.to_s
  end

  # Enables logging. Logging is provided mainly for debugging purposes. Enabling logging will output internal library
  # information that can be used to find bugs with the help of Phidgetd Inc. Alternatively, the user can enable
  # and write to the log for their own uses.
  # === Parameters
  # * _level_ = The highest level of logging to output. All lower levels will also be output.
  # * _file_  = File to output log to. This should be a full pathname, not a relative pathname.
  def Phidgets.enableLogging(level, file)
    r = cPhidget_enableLogging(level, file)
    raise Phidgets::Exception.new(r) if r != 0
  end

  # Disables logging.
  def Phidgets.disableLogging
    r = cPhidget_disableLogging
    raise Phidgets::Exception.new(r) if r != 0
  end


  class Common

    # Opens a Phidget remotely by ServerID. Note that this requires Bonjour (mDNS) to be running on both the host and the server.
    # === Parameters
    # * _serial_number_ = Serial number. Specify -1 to open any.
    # * _server_        = Server ID. Specify nil to open any.
    # * _password_      = Password. Can be nil if the server is running unsecured.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not wait.
    def openRemote(serial_number=-1, server=nil, password=nil, timeout=0)
      r = Phidgets.cPhidget_openRemote(@handle, serial_number, server, password)
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
      r = Phidgets.cPhidget_openRemoteIP(@handle, serial_number, address, port, password)
      raise Phidgets::Exception.new(r) if r != 0
      waitForAttachment(timeout) if timeout > 0
    end

    # Opens a Phidget.
    # === Parameters
    # * _serial_number_ = Serial number. Specify -1 to open any.
    # * _timeout_       = Time to wait for attachment. Specify 0 to not wait.
    def open(serial_number=-1, timeout=0)
      r = Phidgets.cPhidget_open(@handle, serial_number)
      raise Phidgets::Exception.new(r) if r != 0
      waitForAttachment(timeout) if timeout > 0
    end

    # Closes a Phidget.
    def close
      r = Phidgets.cPhidget_close(@handle)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Frees a Phidget handle.
    def delete
      @handle.free = nil
      r = Phidgets.cPhidget_delete(@handle)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Sets a detach handler callback function. This is called when this Phidget is unplugged from the system.
    # === Parameters
    # * _callback_func_ = Callback function.
    # * _data_          = Data for use by the user - this object is passed back into the callback function.
    def setOnDetachHandler(callback_func, data)
      r = Phidgets.cPhidget_set_OnDetach_Handler(@handle, Phidgets.callback("int #{callback_func}(void *, void *)"), DL::PtrData.new(data.object_id))
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Sets an attach handler callback function. This is called when this Phidget is plugged into the system, and is ready for use.
    # === Parameters
    # * _callback_func_ = Callback function.
    # * _data_          = Data for use by the user - this object is passed back into the callback function.
    def setOnAttachHandler(callback_func, data)
      r = Phidgets.cPhidget_set_OnAttach_Handler(@handle, Phidgets.callback("int #{callback_func}(void *, void *)"), DL::PtrData.new(data.object_id))
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Sets a server connect handler callback function. This is used for opening Phidgets remotely, and is called when a connection to the sever has been made.
    # === Parameters
    # * _callback_func_ = Callback function.
    # * _data_          = Data for use by the user - this object is passed back into the callback function.
    def setOnConnectHandler(callback_func, data)
      r = Phidgets.cPhidget_set_OnServerConnect_Handler(@handle, Phidgets.callback("int #{callback_func}(void *, void *)"), DL::PtrData.new(data.object_id))
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Sets a server disconnect handler callback function. This is used for opening Phidgets remotely, and is called when a connection to the server has been lost.
    # === Parameters
    # * _callback_func_ = Callback function.
    # * _data_          = Data for use by the user - this object is passed back into the callback function.
    def setOnDisconnectHandler(callback_func, data)
      r = Phidgets.cPhidget_set_OnServerDisconnect_Handler(@handle, Phidgets.callback("int #{callback_func}(void *, void *)"), DL::PtrData.new(data.object_id))
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Sets the error handler callback function. This is called when an asynchronous error occurs.
    # === Parameters
    # * _callback_func_ = Callback function.
    # * _data_          = Data for use by the user - this object is passed back into the callback function.
    def setOnErrorHandler(callback_func, data)
      r = Phidgets.cPhidget_set_OnError_Handler(@handle, Phidgets.callback("int #{callback_func}(void *, void *, int, const char *)"), DL::PtrData.new(data.object_id))
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the specific name of a Phidget.
    def getDeviceName
      ptr = DL.malloc(DL.sizeof('P'))
      r = Phidgets.cPhidget_getDeviceName(@handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Gets the serial number of a Phidget.
    def getSerialNumber
      sn = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidget_getSerialNumber(@handle, sn.ref)
      raise Phidgets::Exception.new(r) if r != 0
      sn.free = nil
      sn.to_i
    end

    # Gets the firmware version of a Phidget.
    def getDeviceVersion
      ver = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidget_getDeviceVersion(@handle, ver.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ver.free = nil
      ver.to_i
    end

    # Gets the attached status of a Phidget.
    def getDeviceStatus
      stat = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidget_getDeviceStatus(@handle, stat.ref)
      raise Phidgets::Exception.new(r) if r != 0
      stat.free = nil
      stat.to_i
    end

    # Gets the type (class) of a Phidget.
    def getDeviceType
      ptr = DL.malloc(DL.sizeof('P'))
      r = Phidgets.cPhidget_getDeviceType(@handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Gets the label of a Phidget.
    def getDeviceLabel
      ptr = DL.malloc(DL.sizeof('P'))
      r = Phidgets.cPhidget_getDeviceLabel(@handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Sets the label of a Phidget. Note that this is not supported on very old Phidgets, and not yet supported in Windows.
    # === Parameters
    # * _label_ = A string containing the label to be set.
    def setDeviceLabel(label)
      r = Phidgets.cPhidget_setDeviceLabel(@handle, label)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Waits for attachment to happen. This can be called right after calling open, as an alternative to using the attach handler.
    # === Parameters
    # * _timeout_ = Time to wait for the attachment. Specify 0 to wait forever.
    def waitForAttachment(timeout)
      r = Phidgets.cPhidget_waitForAttachment(@handle, timeout)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets the server ID of a remotely opened Phidget. This will fail if the Phidget was opened locally.
    def getServerID
      ptr = DL.malloc(DL.sizeof('P'))
      r = Phidgets.cPhidget_getServerID(@handle, ptr.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      ptr.to_s
    end

    # Gets the address and port of a remotely opened Phidget. This will fail if the Phidget was opened locally.
    def getServerAddress
      ptr = DL.malloc(DL.sizeof('P'))
      port = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidget_getServerAddress(@handle, ptr.ref, port.ref)
      raise Phidgets::Exception.new(r) if r != 0
      ptr.free = nil
      port.free = nil
      [ptr.to_s, port.to_i]
    end

    # Gets the connected to server status of a remotely opened Phidget. This will fail if the Phidget was opened locally.
    def getServerStatus
      stat = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidget_getServerStatus(@handle, stat.ref)
      raise Phidgets::Exception.new(r) if r != 0
      stat.free = nil
      stat.to_i
    end

    # Gets the device ID of a Phidget.
    def getDeviceID
      dev = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidget_getDeviceID(@handle, dev.ref)
      raise Phidgets::Exception.new(r) if r != 0
      dev.free = nil
      dev.to_i
    end

    # Gets the class of a Phidget.
    def getDeviceClass
      dev = DL.malloc(DL.sizeof('I'))
      r = Phidgets.cPhidget_getDeviceClass(@handle, dev.ref)
      raise Phidgets::Exception.new(r) if r != 0
      dev.free = nil
      dev.to_i
    end


    private

    def initialize
      @handle = DL.malloc(DL.sizeof('P'))
    end

  end

end

