

module Phidgets
  class WeightSensor < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnWeightChangeHandler(proc=nil, &block)
      #
      # Set a weight change handler. This is called when the weight changes by more then the change trigger.
      #
      def setOnWeightChangeHandler(cb_proc = nil, &cb_block)
        @on_weight_change_thread.kill if defined? @on_weight_change_thread
        callback = cb_proc || cb_block
        @on_weight_change_thread = Thread.new {ext_setOnWeightChangeHandler(callback)}
      end

      alias :on_weight_change :setOnWeightChangeHandler

    end

  end
end

