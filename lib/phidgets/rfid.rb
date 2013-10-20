

module Phidgets
  class RFID < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnTagHandler(proc=nil, &block)
      #
      # Set a tag handler. This is called when a tag is first detected by the reader.
      #
      def setOnTagHandler(cb_proc = nil, &cb_block)
        @on_tag_thread.kill if defined? @on_tag_thread
        callback = cb_proc || cb_block
        @on_tag_thread = Thread.new {ext_setOnTagHandler(callback)}
      end

      # call-seq:
      #   setOnTagLostHandler(proc=nil, &block)
      #
      # Set a tag lost handler. This is called when a tag is no longer detected by the reader.
      #
      def setOnTagLostHandler(cb_proc = nil, &cb_block)
        @on_tag_lost_thread.kill if defined? @on_tag_lost_thread
        callback = cb_proc || cb_block
        @on_tag_lost_thread = Thread.new {ext_setOnTagLostHandler(callback)}
      end

      # call-seq:
      #   setOnOutputChangeHandler(proc=nil, &block)
      #
      # Set an output change handler. This is called when an output changes.
      #
      def setOnOutputChangeHandler(cb_proc = nil, &cb_block)
        @on_output_change_thread.kill if defined? @on_output_change_thread
        callback = cb_proc || cb_block
        @on_output_change_thread = Thread.new {ext_setOnOutputChangeHandler(callback)}
      end

      alias :on_tag :setOnTagHandler
      alias :on_tag_lost :setOnTagLostHandler
      alias :on_output_change :setOnOutputChangeHandler

    end

  end
end

