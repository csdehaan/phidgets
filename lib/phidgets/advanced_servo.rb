

module Phidgets
  class AdvancedServo < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnVelocityChangeHandler(proc=nil, &block)
      #
      # Sets a velocity change event handler. This is called when the velocity changes.
      #
      def setOnVelocityChangeHandler(cb_proc = nil, &cb_block)
        @on_velocity_change_thread.kill if defined? @on_velocity_change_thread
        callback = cb_proc || cb_block
        @on_velocity_change_thread = Thread.new {ext_setOnVelocityChangeHandler(callback)}
      end

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

      # call-seq:
      #   setOnCurrentChangeHandler(proc=nil, &block)
      #
      # Sets a current change event handler. This is called when the current draw changes.
      #
      def setOnCurrentChangeHandler(cb_proc = nil, &cb_block)
        @on_current_change_thread.kill if defined? @on_current_change_thread
        callback = cb_proc || cb_block
        @on_current_change_thread = Thread.new {ext_setOnCurrentChangeHandler(callback)}
      end

      alias :on_velocity_change :setOnVelocityChangeHandler
      alias :on_position_change :setOnPositionChangeHandler
      alias :on_current_change :setOnCurrentChangeHandler

    end

  end
end

