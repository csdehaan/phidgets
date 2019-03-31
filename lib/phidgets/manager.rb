
module Phidgets
  class Manager

    # call-seq:
    #   setOnAttachHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Attach event occurs.
    #
    def setOnAttachHandler(cb_proc = nil, &cb_block)
      @on_attach_thread.kill if defined? @on_attach_thread and @on_attach_thread.alive?
      callback = cb_proc || cb_block
      @on_attach_thread = Thread.new {ext_setOnAttachHandler(callback)}
    end

    # call-seq:
    #   setOnDetachHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Detach event occurs.
    #
    def setOnDetachHandler(cb_proc = nil, &cb_block)
      @on_detach_thread.kill if defined? @on_detach_thread and @on_detach_thread.alive?
      callback = cb_proc || cb_block
      @on_detach_thread = Thread.new {ext_setOnDetachHandler(callback)}
    end

    alias :on_attach :setOnAttachHandler
    alias :on_detach :setOnDetachHandler

  end
end

