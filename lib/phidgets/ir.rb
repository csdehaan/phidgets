

module Phidgets
  class IR < Common

    # call-seq:
    #   setOnCodeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Code event occurs.
    #
    def setOnCodeHandler(cb_proc = nil, &cb_block)
      @on_code_thread.kill if defined? @on_code_thread and @on_code_thread.alive?
      callback = cb_proc || cb_block
      @on_code_thread = Thread.new {ext_setOnCodeHandler(callback)}
    end

    # call-seq:
    #   setOnLearnHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Learn event occurs.
    #
    def setOnLearnHandler(cb_proc = nil, &cb_block)
      @on_learn_thread.kill if defined? @on_learn_thread and @on_learn_thread.alive?
      callback = cb_proc || cb_block
      @on_learn_thread = Thread.new {ext_setOnLearnHandler(callback)}
    end

    # call-seq:
    #   setOnRawDataHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the RawData event occurs.
    #
    def setOnRawDataHandler(cb_proc = nil, &cb_block)
      @on_raw_data_thread.kill if defined? @on_raw_data_thread and @on_raw_data_thread.alive?
      callback = cb_proc || cb_block
      @on_raw_data_thread = Thread.new {ext_setOnRawDataHandler(callback)}
    end

    alias :on_code :setOnCodeHandler
    alias :on_learn :setOnLearnHandler
    alias :on_raw_data :setOnRawDataHandler

  end
end

