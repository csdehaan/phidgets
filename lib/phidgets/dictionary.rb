
module Phidgets
  class Dictionary < Common

    # call-seq:
    #   setOnAddHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Add event occurs.
    #
    def setOnAddHandler(cb_proc = nil, &cb_block)
      @on_add_thread.kill if defined? @on_add_thread and @on_add_thread.alive?
      callback = cb_proc || cb_block
      @on_add_thread = Thread.new {ext_setOnAddHandler(callback)}
    end

    # call-seq:
    #   setOnRemoveHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Remove event occurs.
    #
    def setOnRemoveHandler(cb_proc = nil, &cb_block)
      @on_remove_thread.kill if defined? @on_remove_thread and @on_remove_thread.alive?
      callback = cb_proc || cb_block
      @on_remove_thread = Thread.new {ext_setOnRemoveHandler(callback)}
    end

    # call-seq:
    #   setOnUpdateHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Update event occurs.
    #
    def setOnUpdateHandler(cb_proc = nil, &cb_block)
      @on_update_thread.kill if defined? @on_update_thread and @on_update_thread.alive?
      callback = cb_proc || cb_block
      @on_update_thread = Thread.new {ext_setOnUpdateHandler(callback)}
    end

    alias :on_add :setOnAddHandler
    alias :on_remove :setOnRemoveHandler
    alias :on_update :setOnUpdateHandler

  end
end

