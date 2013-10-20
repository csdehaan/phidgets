
module Phidgets
  class Manager

    # call-seq:
    #   open(args)
    #
    # Opens a Manager. Will attempt to make the correct open call (open, openRemote, openRemoteIP) based
    # on the arguments passed in. Args is a hash and the following keys may be used:
    # :server_id, :address, :port, :password.
    #
    def open(args={})
      if args.key? :server_id
        open_remote(args[:server_id], args[:password])
      elsif args.key? :address
        open_remote_ip(args[:address], args[:port], args[:password])
      else
        ext_open
      end
    end


    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnAttachHandler(proc=nil, &block)
      #
      # Sets an attach handler callback function. This is called when a Phidget is plugged into the system.
      #
      def setOnAttachHandler(cb_proc = nil, &cb_block)
        @on_attach_thread.kill if defined? @on_attach_thread
        callback = cb_proc || cb_block
        @on_attach_thread = Thread.new {ext_setOnAttachHandler(callback)}
      end

      # call-seq:
      #   setOnDetachHandler(proc=nil, &block)
      #
      # Sets a detach handler callback function. This is called when a Phidget is unplugged from the system.
      #
      def setOnDetachHandler(cb_proc = nil, &cb_block)
        @on_detach_thread.kill if defined? @on_detach_thread
        callback = cb_proc || cb_block
        @on_detach_thread = Thread.new {ext_setOnDetachHandler(callback)}
      end

      # call-seq:
      #   setOnServerConnectHandler(proc=nil, &block)
      #
      # Sets a server connect handler callback function. This is used for opening Phidget Managers remotely,
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
      # Sets a server disconnect handler callback function. This is used for opening Phidget Managers remotely,
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

