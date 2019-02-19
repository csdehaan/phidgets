
module Phidgets
  class Common

    # call-seq:
    #   setOnAttachHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Attach event occurs.
    #
    def setOnAttachHandler(cb_proc = nil, &cb_block)
      @on_attach_thread.kill if defined? @on_attach_thread
      callback = cb_proc || cb_block
      @on_attach_thread = Thread.new {ext_setOnAttachHandler(callback)}
    end

    # call-seq:
    #   setOnDetachHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Detach event occurs.
    #
    def setOnDetachHandler(cb_proc = nil, &cb_block)
      @on_detach_thread.kill if defined? @on_detach_thread
      callback = cb_proc || cb_block
      @on_detach_thread = Thread.new {ext_setOnDetachHandler(callback)}
    end

    # call-seq:
    #   setOnErrorHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Error event occurs.
    #
    def setOnErrorHandler(cb_proc = nil, &cb_block)
      @on_error_thread.kill if defined? @on_error_thread
      callback = cb_proc || cb_block
      @on_error_thread = Thread.new {ext_setOnErrorHandler(callback)}
    end

    # call-seq:
    #   setOnPropertyChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the PropertyChange event occurs.
    #
    def setOnPropertyChangeHandler(cb_proc = nil, &cb_block)
      @on_property_change_thread.kill if defined? @on_property_change_thread
      callback = cb_proc || cb_block
      @on_property_change_thread = Thread.new {ext_setOnPropertyChangeHandler(callback)}
    end

    alias :on_attach :setOnAttachHandler
    alias :on_detach :setOnDetachHandler
    alias :on_error :setOnErrorHandler
    alias :on_property_change :setOnPropertyChangeHandler

  end
end

