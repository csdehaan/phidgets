

module Phidgets
  class CurrentInput < Common

    # call-seq:
    #   setOnCurrentChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the CurrentChange event occurs.
    #
    def setOnCurrentChangeHandler(cb_proc = nil, &cb_block)
      @on_current_change_thread.kill if defined? @on_current_change_thread and @on_current_change_thread.alive?
      callback = cb_proc || cb_block
      @on_current_change_thread = Thread.new {ext_setOnCurrentChangeHandler(callback)}
    end

    alias :on_current_change :setOnCurrentChangeHandler

  end
end

