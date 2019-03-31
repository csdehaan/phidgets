

module Phidgets
  class TemperatureSensor < Common

    # call-seq:
    #   setOnTemperatureChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the TemperatureChange event occurs.
    #
    def setOnTemperatureChangeHandler(cb_proc = nil, &cb_block)
      @on_temperature_change_thread.kill if defined? @on_temperature_change_thread and @on_temperature_change_thread.alive?
      callback = cb_proc || cb_block
      @on_temperature_change_thread = Thread.new {ext_setOnTemperatureChangeHandler(callback)}
    end

    alias :on_temperature_change :setOnTemperatureChangeHandler

  end
end

