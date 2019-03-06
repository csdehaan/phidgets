

module Phidgets
  class FrequencyCounter < Common

    # call-seq:
    #   setOnCountChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the CountChange event occurs.
    #
    def setOnCountChangeHandler(cb_proc = nil, &cb_block)
      @on_count_change_thread.kill if defined? @on_count_change_thread and @on_count_change_thread.alive?
      callback = cb_proc || cb_block
      @on_count_change_thread = Thread.new {ext_setOnCountChangeHandler(callback)}
    end

    alias :on_count_change :setOnCountChangeHandler

    # call-seq:
    #   setOnFrequencyChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the CountChange event occurs.
    #
    def setOnFrequencyChangeHandler(cb_proc = nil, &cb_block)
      @on_frequency_change_thread.kill if defined? @on_frequency_change_thread and @on_frequency_change_thread.alive?
      callback = cb_proc || cb_block
      @on_frequency_change_thread = Thread.new {ext_setOnFrequencyChangeHandler(callback)}
    end

    alias :on_frequency_change :setOnFrequencyChangeHandler

  end
end

