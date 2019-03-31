

module Phidgets
  class Accelerometer < Common

    # call-seq:
    #   setOnAccelerationChangeHandler(proc=nil, &block)
    #
    # Sets an acceleration change event handler. This is called when the acceleration changes by more then the change trigger.
    #
    def setOnAccelerationChangeHandler(cb_proc = nil, &cb_block)
      @on_acceleration_change_thread.kill if defined? @on_acceleration_change_thread and @on_acceleration_change_thread.alive?
      callback = cb_proc || cb_block
      @on_acceleration_change_thread = Thread.new {ext_setOnAccelerationChangeHandler(callback)}
    end

    alias :on_acceleration_change :setOnAccelerationChangeHandler

  end
end

