

module Phidgets
  class Accelerometer < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnAccelerationChangeHandler(proc=nil, &block)
      #
      # Sets an acceleration change event handler. This is called when the acceleration changes by more then the change trigger.
      #
      def setOnAccelerationChangeHandler(cb_proc = nil, &cb_block)
        @on_acceleration_change_thread.kill if defined? @on_acceleration_change_thread
        callback = cb_proc || cb_block
        @on_acceleration_change_thread = Thread.new {ext_setOnAccelerationChangeHandler(callback)}
      end

      alias :on_acceleration_change :setOnAccelerationChangeHandler

    end

  end
end

