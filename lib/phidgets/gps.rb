

module Phidgets
  class GPS < Common

    # call-seq:
    #   setOnHeadingChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the HeadingChange event occurs.
    #
    def setOnHeadingChangeHandler(cb_proc = nil, &cb_block)
      @on_heading_change_thread.kill if defined? @on_heading_change_thread and @on_heading_change_thread.alive?
      callback = cb_proc || cb_block
      @on_heading_change_thread = Thread.new {ext_setOnHeadingChangeHandler(callback)}
    end

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
    #   setOnPositionFixStateChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the PositionFixStateChange event occurs.
    #
    def setOnPositionFixStateChangeHandler(cb_proc = nil, &cb_block)
      @on_position_fix_state_change_thread.kill if defined? @on_position_fix_state_change_thread and @on_position_fix_state_change_thread.alive?
      callback = cb_proc || cb_block
      @on_position_fix_state_change_thread = Thread.new {ext_setOnPositionFixStateChangeHandler(callback)}
    end

    alias :on_heading_change :setOnHeadingChangeHandler
    alias :on_position_change :setOnPositionChangeHandler
    alias :on_position_fix_state_change :setOnPositionFixStateChangeHandler

  end
end

