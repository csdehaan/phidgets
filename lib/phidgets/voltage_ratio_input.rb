

module Phidgets
  class VoltageRatioInput < Common

    # call-seq:
    #   setOnSensorChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the SensorChange event occurs.
    #
    def setOnSensorChangeHandler(cb_proc = nil, &cb_block)
      @on_sensor_change_thread.kill if defined? @on_sensor_change_thread and @on_sensor_change_thread.alive?
      callback = cb_proc || cb_block
      @on_sensor_change_thread = Thread.new {ext_setOnSensorChangeHandler(callback)}
    end

    alias :on_sensor_change :setOnSensorChangeHandler

    # call-seq:
    #   setOnVoltageRatioChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the VoltageRatioChange event occurs.
    #
    def setOnVoltageRatioChangeHandler(cb_proc = nil, &cb_block)
      @on_voltage_ratio_change_thread.kill if defined? @on_voltage_ratio_change_thread and @on_voltage_ratio_change_thread.alive?
      callback = cb_proc || cb_block
      @on_voltage_ratio_change_thread = Thread.new {ext_setOnVoltageRatioChangeHandler(callback)}
    end

    alias :on_voltage_ratio_change :setOnVoltageRatioChangeHandler

  end
end

