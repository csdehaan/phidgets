
module Phidgets

  extern "int CPhidgetManager_create(void *)"
  extern "int CPhidgetManager_open(void *)"
  extern "int CPhidgetManager_close(void *)"
  extern "int CPhidgetManager_delete(void *)"
  extern "int CPhidgetManager_getAttachedDevices(void *, void *, int *)"
  extern "int CPhidgetManager_freeAttachedDevicesArray(void *)"
  extern "int CPhidgetManager_openRemote(void *, void *, void *)"
  extern "int CPhidgetManager_openRemoteIP(void *, char *, int, void *)"


  class Manager

    # Creates a new Manager object.
    def initialize
      @server = nil
      @port = nil
      @password = nil
      @handle = Phidgets.malloc(SIZEOF_VOIDP)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_create', @handle.ref)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Opens a Manager.
    def open
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_open', @handle)
      raise Phidgets::Exception.new(r) if r != 0

      # a delay is required between the time the manager is opened and when it is used, otherwise it will report that no phidgets are attached. there really should be a better way.
      sleep 1
    end

    # Opens a Manager remotely by ServerID. Note that this requires Bonjour (mDNS) to be running on both the host and the server.
    # === Parameters
    # * _server_        = Server ID. Specify nil to open any.
    # * _password_      = Password. Can be nil if the server is running unsecured.
    def openRemote(server=nil, password=nil)
      @server = server
      @password = password
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_openRemote', @handle, server, password)
      raise Phidgets::Exception.new(r) if r != 0

      # a delay is required between the time the manager is opened and when it is used, otherwise it will report that no phidgets are attached. there really should be a better way.
      sleep 2
    end

    # Opens a Manager remotely by address and port.
    # === Parameters
    # * _address_       = Address. This can be a hostname or IP address.
    # * _port_          = Port number. Default is 5001.
    # * _password_      = Password. Can be nil if the server is running unsecured.
    def openRemoteIP(address, port=5001, password=nil)
      @server = address
      @port = port.to_i
      @password = password
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_openRemoteIP', @handle, address, port.to_i, password)
      raise Phidgets::Exception.new(r) if r != 0

      # a delay is required between the time the manager is opened and when it is used, otherwise it will report that no phidgets are attached. there really should be a better way.
      sleep 2
    end

    # Closes a Manager.
    def close
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_close', @handle)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Frees a Manager handle.
    def delete
      @handle.free = nil
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_delete', @handle)
      raise Phidgets::Exception.new(r) if r != 0
    end

    # Gets a hash of all currently attached Phidgets. The indices into the hash are the serial numbers of the Phidgets.
    def getAttachedDevices
      handles = Phidgets.malloc(SIZEOF_VOIDP)
      count = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_getAttachedDevices', @handle, handles.ref, count.ref)
      raise Phidgets::Exception.new(r) if r != 0
      count.free = nil

      devices = {}
      count.to_i.times { |i|
        handle = handles + (i * SIZEOF_VOIDP)
        serial = getSerialNumber(handle)

        devices[serial] = case getDeviceClass(handle)
        when CLASS_INTERFACEKIT
          InterfaceKit.new
        when CLASS_RFID
          RFID.new
        when CLASS_SERVO
          Servo.new
        end

        devices[serial].open(serial, 3000) unless @server
        devices[serial].openRemote(serial, @server, @password, 4000) if @server and !@port
        devices[serial].openRemoteIP(serial, @server, @port, @password, 4000) if @server and @port
      }

      r = Phidgets.send(FUNCTION_PREFIX + 'PhidgetManager_freeAttachedDevicesArray', handles)
      raise Phidgets::Exception.new(r) if r != 0
      
      devices
    end

    private
  
    def getDeviceClass handle
      dev_class = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getDeviceClass', handle.ptr, dev_class.ref)
      raise Phidgets::Exception.new(r) if r != 0
      dev_class.free = nil
      dev_class.to_i
    end
  
    def getSerialNumber handle
      sn = Phidgets.malloc(SIZEOF_INT)
      r = Phidgets.send(FUNCTION_PREFIX + 'Phidget_getSerialNumber', handle.ptr, sn.ref)
      raise Phidgets::Exception.new(r) if r != 0
      sn.free = nil
      sn.to_i
    end
  
  end

end

