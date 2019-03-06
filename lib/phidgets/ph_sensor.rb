

module Phidgets
  class PHSensor < Common

      # call-seq:
      #   setOnPHChangeHandler(proc=nil, &block)
      #
      # Assigns a handler that will be called when the PHChange event occurs.
      #
      def setOnPHChangeHandler(cb_proc = nil, &cb_block)
        @on_ph_change_thread.kill if defined? @on_ph_change_thread and @on_ph_change_thread.alive?
        callback = cb_proc || cb_block
        @on_ph_change_thread = Thread.new {ext_setOnPHChangeHandler(callback)}
      end

      alias :on_ph_change :setOnPHChangeHandler

  end
end

