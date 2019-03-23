

module Phidgets
  class LightSensor < Common

    # call-seq:
    #   setOnIlluminanceChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the IlluminanceChange event occurs.
    #
    def setOnIlluminanceChangeHandler(cb_proc = nil, &cb_block)
      @on_illuminance_change_thread.kill if defined? @on_illuminance_change_thread and @on_illuminance_change_thread.alive?
      callback = cb_proc || cb_block
      @on_illuminance_change_thread = Thread.new {ext_setOnIlluminanceChangeHandler(callback)}
    end

    alias :on_illuminance_change :setOnIlluminanceChangeHandler

  end
end

