

module Phidgets
  class PHSensor < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnPHChangeHandler(proc=nil, &block)
      #
      # Set a PH change handler. This is called when the PH changes by more then the change trigger.
      #
      def setOnPHChangeHandler(cb_proc = nil, &cb_block)
        @on_ph_change_thread.kill if defined? @on_ph_change_thread
        callback = cb_proc || cb_block
        @on_ph_change_thread = Thread.new {ext_setOnPHChangeHandler(callback)}
      end

      alias :on_ph_change :setOnPHChangeHandler

    end

  end
end

