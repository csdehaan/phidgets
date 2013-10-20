
module Phidgets
  class Common

    # call-seq:
    #   open(args)
    #
    # Opens a Phidget. Will attempt to make the correct open call (openLabel, openRemote, openRemoteIP, etc)
    # based on the arguments passed in. Args can either be a serial number or a hash of arguments. If it is a
    # hash, the following keys may be used: :serial_number, :label, :server_id, :address, :port, :password.
    #
    def open(args)
      args = {:serial_number => args.to_i} unless args.is_a? Hash
      if args.key? :server_id
        return open_remote(args[:serial_number], args[:server_id], args[:password]) if args.key? :serial_number
        return open_label_remote(args[:label], args[:server_id], args[:password]) if args.key? :label
      elsif args.key? :address
        return open_remote_ip(args[:serial_number], args[:address], args[:port], args[:password]) if args.key? :serial_number
        return open_label_remote_ip(args[:label], args[:address], args[:port], args[:password]) if args.key? :label
      else
        return ext_open(args[:serial_number]) if args.key? :serial_number
        return open_label(args[:label]) if args.key? :label
      end
      raise Phidgets::Error::InvalidArg.new
    end


    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnAttachHandler(proc=nil, &block)
      #
      # Sets an attach handler callback function. This is called when this Phidget is plugged into the system, and is ready for use.
      #
      def setOnAttachHandler(cb_proc = nil, &cb_block)
        @on_attach_thread.kill if defined? @on_attach_thread
        callback = cb_proc || cb_block
        @on_attach_thread = Thread.new {ext_setOnAttachHandler(callback)}
      end

      # call-seq:
      #   setOnDetachHandler(proc=nil, &block)
      #
      # Sets a detach handler callback function. This is called when this Phidget is unplugged from the system.
      #
      def setOnDetachHandler(cb_proc = nil, &cb_block)
        @on_detach_thread.kill if defined? @on_detach_thread
        callback = cb_proc || cb_block
        @on_detach_thread = Thread.new {ext_setOnDetachHandler(callback)}
      end

      # call-seq:
      #   setOnServerConnectHandler(proc=nil, &block)
      #
      # Sets a server connect handler callback function. This is used for opening Phidgets remotely,
      # and is called when a connection to the sever has been made.
      #
      def setOnServerConnectHandler(cb_proc = nil, &cb_block)
        @on_server_connect_thread.kill if defined? @on_server_connect_thread
        callback = cb_proc || cb_block
        @on_server_connect_thread = Thread.new {ext_setOnServerConnectHandler(callback)}
      end

      # call-seq:
      #   setOnServerDisconnectHandler(proc=nil, &block)
      #
      # Sets a server disconnect handler callback function. This is used for opening Phidgets remotely,
      # and is called when a connection to the server has been lost.
      #
      def setOnServerDisconnectHandler(cb_proc = nil, &cb_block)
        @on_server_disconnect_thread.kill if defined? @on_server_disconnect_thread
        callback = cb_proc || cb_block
        @on_server_disconnect_thread = Thread.new {ext_setOnServerDisconnectHandler(callback)}
      end

      alias :on_attach :setOnAttachHandler
      alias :on_detach :setOnDetachHandler
      alias :on_server_connect :setOnServerConnectHandler
      alias :on_server_disconnect :setOnServerDisconnectHandler

    end

  end
end

