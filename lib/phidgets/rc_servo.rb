
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

    # call-seq:
    #   setTargetPosition_async(proc=nil, &block)
    #
    # If the controller is configured and the TargetPosition is set, the motor will try to reach the TargetPostiion.
    #
    def setTargetPosition_async(position, cb_proc = nil, &cb_block)
      @target_position_async_thread.kill if defined? @target_position_async_thread and @target_position_async_thread.alive?
      callback = cb_proc || cb_block
      @target_position_async_thread = Thread.new {ext_setTargetPosition_async(position, callback)}
    end


    alias :on_position_change :setOnPositionChangeHandler
    alias :on_target_position_reached :setOnTargetPositionReachedHandler
    alias :on_velocity_change :setOnVelocityChangeHandler
    alias :set_target_position_async :setTargetPosition_async

  end
end
