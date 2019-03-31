

module Phidgets
  class VoltageOutput < Common

    # call-seq:
    #   setVoltage_async(voltage, proc=nil, &block)
    #
    # The voltage value that the channel will output.
    # The Voltage value is bounded by MinVoltage and MaxVoltage.
    # The voltage value will not be output until Enabled is set to true.
    #
    def setVoltage_async(voltage, cb_proc = nil, &cb_block)
      @voltage_async_thread.kill if defined? @voltage_async_thread and @voltage_async_thread.alive?
      callback = cb_proc || cb_block
      @voltage_async_thread = Thread.new {ext_setVoltage_async(voltage, callback)}
    end

    alias :set_voltage_async :setVoltage_async

  end
end

