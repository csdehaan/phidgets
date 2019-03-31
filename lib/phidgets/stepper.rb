

module Phidgets
  class Stepper < Common

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
    #   setOnStoppedHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Stopped event occurs.
    #
    def setOnStoppedHandler(cb_proc = nil, &cb_block)
      @on_stopped_thread.kill if defined? @on_stopped_thread and @on_stopped_thread.alive?
      callback = cb_proc || cb_block
      @on_stopped_thread = Thread.new {ext_setOnStoppedHandler(callback)}
    end

    # call-seq:
    #   setOnVelocityChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the VelocityChange event occurs.
    #
    def setOnVelocityChangeHandler(cb_proc = nil, &cb_block)
      @on_velocity_change_thread.kill if defined? @on_velocity_change_thread and @on_velocity_change_thread.alive?
      callback = cb_proc || cb_block
      @on_velocity_change_thread = Thread.new {ext_setOnVelocityChangeHandler(callback)}
    end

    # call-seq:
    #   setTargetPosition_async(proc=nil, &block)
    #
    # If the controller is configured and the TargetPosition is set, the Stepper motor will move towards the TargetPosition at the specified Acceleration and Velocity.
    # TargetPosition is only used when the ControlMode is set to step mode.
    # Units for Position, Velocity, and Acceleration can be set by the user through the RescaleFactor. The RescaleFactor allows you to use more intuitive units such as rotations, or degrees.
    #
    def setTargetPosition_async(position, cb_proc = nil, &cb_block)
      @target_position_async_thread.kill if defined? @target_position_async_thread and @target_position_async_thread.alive?
      callback = cb_proc || cb_block
      @target_position_async_thread = Thread.new {ext_setTargetPosition_async(position, callback)}
    end

    alias :on_position_change :setOnPositionChangeHandler
    alias :on_stopped :setOnStoppedHandler
    alias :on_velocity_change :setOnVelocityChangeHandler
    alias :set_target_position_async :setTargetPosition_async

  end
end

