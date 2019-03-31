

module Phidgets
  class ResistanceInput < Common

    # call-seq:
    #   setOnResistanceChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the ResistanceChange event occurs.
    #
    def setOnResistanceChangeHandler(cb_proc = nil, &cb_block)
      @on_resistance_change_thread.kill if defined? @on_resistance_change_thread and @on_resistance_change_thread.alive?
      callback = cb_proc || cb_block
      @on_resistance_change_thread = Thread.new {ext_setOnResistanceChangeHandler(callback)}
    end

    alias :on_resistance_change :setOnResistanceChangeHandler

  end
end

