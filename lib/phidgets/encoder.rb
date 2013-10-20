

module Phidgets
  class Encoder < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnInputChangeHandler(proc=nil, &block)
      #
      # Sets an input change handler. This is called when a digital input changes.
      #
      def setOnInputChangeHandler(cb_proc = nil, &cb_block)
        @on_input_change_thread.kill if defined? @on_input_change_thread
        callback = cb_proc || cb_block
        @on_input_change_thread = Thread.new {ext_setOnInputChangeHandler(callback)}
      end

      # call-seq:
      #   setOnPositionChangeHandler(proc=nil, &block)
      #
      # Sets an encoder position change handler. This is called when an encoder position changes.
      #
      def setOnPositionChangeHandler(cb_proc = nil, &cb_block)
        @on_position_change_thread.kill if defined? @on_position_change_thread
        callback = cb_proc || cb_block
        @on_position_change_thread = Thread.new {ext_setOnPositionChangeHandler(callback)}
      end

      # call-seq:
      #   setOnIndexHandler(proc=nil, &block)
      #
      # Sets an encoder index handler. This is called when there is a pulse on the index pin.
      #
      def setOnIndexHandler(cb_proc = nil, &cb_block)
        @on_index_thread.kill if defined? @on_index_thread
        callback = cb_proc || cb_block
        @on_index_thread = Thread.new {ext_setOnIndexHandler(callback)}
      end

      alias :on_input_change :setOnInputChangeHandler
      alias :on_position_change :setOnPositionChangeHandler
      alias :on_index :setOnIndexHandler

    end

  end
end

