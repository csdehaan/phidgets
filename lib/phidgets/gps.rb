

module Phidgets
  class GPS < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnPositionChangeHandler(proc=nil, &block)
      #
      # Sets a position change event handler. This is called when any of latitude, longitude, or altitude change.
      #
      def setOnPositionChangeHandler(cb_proc = nil, &cb_block)
        @on_position_change_thread.kill if defined? @on_position_change_thread
        callback = cb_proc || cb_block
        @on_position_change_thread = Thread.new {ext_setOnPositionChangeHandler(callback)}
      end

      # call-seq:
      #   setOnPositionFixStatusChangeHandler(proc=nil, &block)
      #
      # Sets a position fix status change event handler. This is called when a position fix is aquired or lost.
      #
      def setOnPositionFixStatusChangeHandler(cb_proc = nil, &cb_block)
        @on_position_fix_status_change_thread.kill if defined? @on_position_fix_status_change_thread
        callback = cb_proc || cb_block
        @on_position_fix_status_change_thread = Thread.new {ext_setOnPositionFixStatusChangeHandler(callback)}
      end

      alias :on_position_change :setOnPositionChangeHandler
      alias :on_position_fix_status_change :setOnPositionFixStatusChangeHandler

    end

  end
end

