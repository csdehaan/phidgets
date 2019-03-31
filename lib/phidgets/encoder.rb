

module Phidgets
  class Encoder < Common

      # call-seq:
      #   setOnPositionChangeHandler(proc=nil, &block)
      #
      # Sets an encoder position change handler. This is called when an encoder position changes.
      #
      def setOnPositionChangeHandler(cb_proc = nil, &cb_block)
        @on_position_change_thread.kill if defined? @on_position_change_thread and @on_position_change_thread.alive?
        callback = cb_proc || cb_block
        @on_position_change_thread = Thread.new {ext_setOnPositionChangeHandler(callback)}
      end

      alias :on_position_change :setOnPositionChangeHandler

  end
end

