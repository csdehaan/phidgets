

module Phidgets
  class SoundSensor < Common

    # call-seq:
    #   setOnSPLChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the SPLChange event occurs.
    #
    def setOnSPLChangeHandler(cb_proc = nil, &cb_block)
      @on_spl_change_thread.kill if defined? @on_spl_change_thread and @on_spl_change_thread.alive?
      callback = cb_proc || cb_block
      @on_spl_change_thread = Thread.new {ext_setOnSPLChangeHandler(callback)}
    end

    alias :on_spl_change :setOnSPLChangeHandler

  end
end

