
require 'dl'
require 'dl/import'
require 'rbconfig'


module Phidgets

  if RUBY_VERSION < "1.9"
    extend DL::Importable
    SIZEOF_INT      = DL.sizeof('I')
    SIZEOF_VOIDP    = DL.sizeof('P')
    SIZEOF_DOUBLE   = DL.sizeof('D')
    FUNCTION_PREFIX = 'c'
    def Phidgets.malloc size
      DL.malloc(size)
    end
  else
    extend DL::Importer
    SIZEOF_INT      = DL::SIZEOF_INT
    SIZEOF_VOIDP    = DL::SIZEOF_VOIDP
    SIZEOF_DOUBLE   = DL::SIZEOF_DOUBLE
    FUNCTION_PREFIX = 'C'
    def Phidgets.malloc size
      DL::CPtr.malloc(size)
    end
  end

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
          super("Webservice and Client protocol versions don't match. Update to newest release.")
      end
    end

  end

  begin
    case Config::CONFIG['target_os']
      when /linux/
        dlload 'libphidget21.so'
      when /mswin/, /mingw/
        dlload 'phidget21.dll'
      when /darwin/
        dlload '/Library/Frameworks/Phidget21.framework/Versions/Current/Phidget21'
      else
        raise Phidgets::Exception.new(Exception::EPHIDGET_LIBNAME)
    end
  rescue
    raise Phidgets::Exception.new(Exception::EPHIDGET_LOAD_LIB_FAIL)
  end

  extern "int CPhidget_getLibraryVersion(void *)"
  extern "int CPhidget_getErrorDescription(int, void *)"
  extern "int CPhidget_enableLogging(int, char *)"
  extern "int CPhidget_disableLogging()"

  # Gets the library version. This contains a version number and a build date.
  def Phidgets.getLibraryVersion
    ptr = malloc(SIZEOF_VOIDP)
    r = self.send(FUNCTION_PREFIX + 'Phidget_getLibraryVersion', ptr.ref)
    raise Phidgets::Exception.new(r) if r != 0
    ptr.free = nil
    ptr.to_s
  end

  # Gets the description for an error code.
  def Phidgets.getErrorDescription(error_code)
    ptr = malloc(SIZEOF_VOIDP)
    r = self.send(FUNCTION_PREFIX + 'Phidget_getErrorDescription', error_code.to_i, ptr.ref)
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
    r = self.send(FUNCTION_PREFIX + 'Phidget_enableLogging', level.to_i, file)
    raise Phidgets::Exception.new(r) if r != 0
  end

  # Disables logging.
  def Phidgets.disableLogging
    r = self.send(FUNCTION_PREFIX + 'Phidget_disableLogging')
    raise Phidgets::Exception.new(r) if r != 0
  end

end

