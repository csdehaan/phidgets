

module Phidgets
  class DigitalInput < Common

    # call-seq:
    #   setOnStateChangeHandler(proc=nil, &block)
    #
    # Set a digital input change handler. This is called when a digital input changes.
    #
    def setOnStateChangeHandler(cb_proc = nil, &cb_block)
      @on_state_change_thread.kill if defined? @on_state_change_thread
      callback = cb_proc || cb_block
      @on_state_change_thread = Thread.new {ext_setOnStateChangeHandler(callback)}
    end

    alias :on_state_change :setOnStateChangeHandler

  end
end

