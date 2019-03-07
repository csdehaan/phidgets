
module Phidgets
  class RCServo < Common

    # call-seq:
    #   setOnPositionChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the PositionChange event occurs.
    #
    def setOnPositionChangeHandler(cb_proc = nil, &cb_block)
      @on_position_change_thread.kill if defined? @on_position_change_thread and @on_position_change_thread.alive?
      callback = cb_proc || cb_block
      @on_position_change_thread = Thread.new {ext_setOnPositionChangeHandler(callback)}
    end


    # call-seq:
    #   setOnTargetPositionReachedHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the TargetPositionReached event occurs.
    #
    def setOnTargetPositionReachedHandler(cb_proc = nil, &cb_block)
      @on_target_position_reached_thread.kill if defined? @on_target_position_reached_thread and @on_target_position_reached_thread.alive?
      callback = cb_proc || cb_block
      @on_target_position_reached_thread = Thread.new {ext_setOnTargetPositionReachedHandler(callback)}
    end


    # call-seq:
    #   setOnVelocityChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the PositionChange event occurs.
    #
    def setOnVelocityChangeHandler(cb_proc = nil, &cb_block)
      @on_velocity_change_thread.kill if defined? @on_velocity_change_thread and @on_velocity_change_thread.alive?
      callback = cb_proc || cb_block
      @on_velocity_change_thread = Thread.new {ext_setOnVelocityChangeHandler(callback)}
    end


    alias :on_position_change :setOnPositionChangeHandler
    alias :on_target_position_reached :setOnTargetPositionReachedHandler
    alias :on_velocity_change :setOnVelocityChangeHandler

  end
end
