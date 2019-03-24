

module Phidgets
  class PressureSensor < Common

    # call-seq:
    #   setOnPressureChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the PressureChange event occurs.
    #
    def setOnPressureChangeHandler(cb_proc = nil, &cb_block)
      @on_pressure_change_thread.kill if defined? @on_pressure_change_thread and @on_pressure_change_thread.alive?
      callback = cb_proc || cb_block
      @on_pressure_change_thread = Thread.new {ext_setOnPressureChangeHandler(callback)}
    end

    alias :on_pressure_change :setOnPressureChangeHandler

  end
end

