

module Phidgets
  class InterfaceKit < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnInputChangeHandler(proc=nil, &block)
      #
      # Set a digital input change handler. This is called when a digital input changes.
      #
      def setOnInputChangeHandler(cb_proc = nil, &cb_block)
        @on_input_change_thread.kill if defined? @on_input_change_thread
        callback = cb_proc || cb_block
        @on_input_change_thread = Thread.new {ext_setOnInputChangeHandler(callback)}
      end

      # call-seq:
      #   setOnOutputChangeHandler(proc=nil, &block)
      #
      # Set a digital output change handler. This is called when a digital output changes.
      #
      def setOnOutputChangeHandler(cb_proc = nil, &cb_block)
        @on_output_change_thread.kill if defined? @on_output_change_thread
        callback = cb_proc || cb_block
        @on_output_change_thread = Thread.new {ext_setOnOutputChangeHandler(callback)}
      end

      # call-seq:
      #   setOnSensorChangeHandler(proc=nil, &block)
      #
      # Set a sensor change handler. This is called when a sensor value changes by more then the change trigger.
      #
      def setOnSensorChangeHandler(cb_proc = nil, &cb_block)
        @on_sensor_change_thread.kill if defined? @on_sensor_change_thread
        callback = cb_proc || cb_block
        @on_sensor_change_thread = Thread.new {ext_setOnSensorChangeHandler(callback)}
      end

      alias :on_input_change :setOnInputChangeHandler
      alias :on_output_change :setOnOutputChangeHandler
      alias :on_sensor_change :setOnSensorChangeHandler

    end

  end
end

