

module Phidgets
  class IR < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnCodeHandler(proc=nil, &block)
      #
      # Set a Code handler. This is called when a code has been received that could be
      # automatically decoded.
      #
      def setOnCodeHandler(cb_proc = nil, &cb_block)
        @on_code_thread.kill if defined? @on_code_thread
        callback = cb_proc || cb_block
        @on_code_thread = Thread.new {ext_setOnCodeHandler(callback)}
      end

      # call-seq:
      #   setOnLearnHandler(proc=nil, &block)
      #
      # Set a Learn handler. This is called when a code has been received for long enough to be learned.
      #
      def setOnLearnHandler(cb_proc = nil, &cb_block)
        @on_learn_thread.kill if defined? @on_learn_thread
        callback = cb_proc || cb_block
        @on_learn_thread = Thread.new {ext_setOnLearnHandler(callback)}
      end

      # call-seq:
      #   setOnRawDataHandler(proc=nil, &block)
      #
      # Set a Raw Data handler. This is called when raw data has been read from the device.
      #
      def setOnRawDataHandler(cb_proc = nil, &cb_block)
        @on_raw_data_thread.kill if defined? @on_raw_data_thread
        callback = cb_proc || cb_block
        @on_raw_data_thread = Thread.new {ext_setOnRawDataHandler(callback)}
      end

      alias :on_code :setOnCodeHandler
      alias :on_learn :setOnLearnHandler
      alias :on_raw_data :setOnRawDataHandler

    end

  end
end

