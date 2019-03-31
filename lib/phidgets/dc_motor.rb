

module Phidgets
  class DCMotor < Common

    # call-seq:
    #   setOnBackEMFChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the BackEMFChange event occurs.
    #
    def setOnBackEMFChangeHandler(cb_proc = nil, &cb_block)
      @on_back_emf_change_thread.kill if defined? @on_back_emf_change_thread and @on_back_emf_change_thread.alive?
      callback = cb_proc || cb_block
      @on_back_emf_change_thread = Thread.new {ext_setOnBackEMFChangeHandler(callback)}
    end

    # call-seq:
    #   setOnBrakingStrengthChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Stopped event occurs.
    #
    def setOnBrakingStrengthChangeHandler(cb_proc = nil, &cb_block)
      @on_braking_strength_change_thread.kill if defined? @on_braking_strength_change_thread and @on_braking_strength_change_thread.alive?
      callback = cb_proc || cb_block
      @on_braking_strength_change_thread = Thread.new {ext_setOnBrakingStrengthChangeHandler(callback)}
    end

    # call-seq:
    #   setOnVelocityUpdateHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the VelocityChange event occurs.
    #
    def setOnVelocityUpdateHandler(cb_proc = nil, &cb_block)
      @on_velocity_update_thread.kill if defined? @on_velocity_update_thread and @on_velocity_update_thread.alive?
      callback = cb_proc || cb_block
      @on_velocity_update_thread = Thread.new {ext_setOnVelocityUpdateHandler(callback)}
    end

    alias :on_back_emf_change :setOnBackEMFChangeHandler
    alias :on_braking_strength_change :setOnBrakingStrengthChangeHandler
    alias :on_velocity_update :setOnVelocityUpdateHandler

  end
end

