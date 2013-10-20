

module Phidgets
  class TemperatureSensor < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnTemperatureChangeHandler(proc=nil, &block)
      #
      # Set a temperature change handler. This is called when the temperature changes by more then the change trigger.
      #
      def setOnTemperatureChangeHandler(cb_proc = nil, &cb_block)
        @on_temperature_change_thread.kill if defined? @on_temperature_change_thread
        callback = cb_proc || cb_block
        @on_temperature_change_thread = Thread.new {ext_setOnTemperatureChangeHandler(callback)}
      end

      alias :on_temperature_change :setOnTemperatureChangeHandler

    end

  end
end

