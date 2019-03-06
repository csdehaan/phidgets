

module Phidgets
  class DigitalOutput < Common

    # call-seq:
    #   setDutyCycle_async(duty_cycle, proc=nil, &block)
    #
    # The DutyCycle represents the fraction of time the output is on (high).
    # This will override the State setting on the channel.
    # A DutyCycle of 1.0 translates to a high output, a DutyCycle of 0 translates to a low output.
    # This is equivalent to setting a State of TRUE and FALSE respectively.
    # A DutyCycle of 0.5 translates to an output that is high half the time, which results in an average output voltage of (output voltage x 0.5)
    # You can use the DutyCycle to create a dimming effect on LEDs.
    # If the DigitalOutput channel you are using does not support PWM, then this value may only be set to 1.0 or 0.0.
    #
    def setDutyCycle_async(duty_cycle, cb_proc = nil, &cb_block)
      @duty_cycle_async_thread.kill if defined? @duty_cycle_async_thread and @duty_cycle_async_thread.alive?
      callback = cb_proc || cb_block
      @duty_cycle_async_thread = Thread.new {ext_setDutyCycle_async(duty_cycle, callback)}
    end

    alias :set_duty_cycle_async :setDutyCycle_async

    # call-seq:
    #   setLEDCurrentLimit_async(duty_cycle, proc=nil, &block)
    #
    # The LEDCurrentLimit is the maximum amount of current that the controller will provide to the output.
    # Reference the data sheet of the LED you are using before setting this value.
    #
    def setLEDCurrentLimit_async(current_limit, cb_proc = nil, &cb_block)
      @led_current_limit_async_thread.kill if defined? @led_current_limit_async_thread and @led_current_limit_async_thread.alive?
      callback = cb_proc || cb_block
      @led_current_limit_async_thread = Thread.new {ext_setLEDCurrentLimit_async(current_limit, callback)}
    end

    alias :set_led_current_limit_async :setLEDCurrentLimit_async

    # call-seq:
    #   setState_async(state, proc=nil, &block)
    #
    # The State will dictate whether the output is constantly high (TRUE) or low (FALSE).
    # This will override any DutyCycle that may have been set on the channel.
    # Setting the State to TRUE is the same as setting DutyCycle to 1.0, and setting the State to FALSE is the same as setting a DutyCycle of 0.0.
    #
    def setState_async(state, cb_proc = nil, &cb_block)
      @state_async_thread.kill if defined? @state_async_thread and @state_async_thread.alive?
      callback = cb_proc || cb_block
      @state_async_thread = Thread.new {ext_setState_async(state, callback)}
    end

    alias :set_state_async :setState_async

  end
end

