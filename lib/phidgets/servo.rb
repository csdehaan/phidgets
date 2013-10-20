
module Phidgets
  class Servo < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnPositionChangeHandler(proc=nil, &block)
      #
      # Sets a position change event handler. This is called when the position changes.
      #
      def setOnPositionChangeHandler(cb_proc = nil, &cb_block)
        @on_position_change_thread.kill if defined? @on_position_change_thread
        callback = cb_proc || cb_block
        @on_position_change_thread = Thread.new {ext_setOnPositionChangeHandler(callback)}
      end

      alias :on_position_change :setOnPositionChangeHandler

    end

  end
end
