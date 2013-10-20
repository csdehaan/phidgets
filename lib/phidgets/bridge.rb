

module Phidgets
  class Bridge < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnBridgeDataHandler(proc=nil, &block)
      #
      # Sets a bridge data event handler. This is called at a set rate as defined by data rate.
      #
      def setOnBridgeDataHandler(cb_proc = nil, &cb_block)
        @on_bridge_data_thread.kill if defined? @on_bridge_data_thread
        callback = cb_proc || cb_block
        @on_bridge_data_thread = Thread.new {ext_setOnBridgeDataHandler(callback)}
      end

      alias :on_bridge_data :setOnBridgeDataHandler

    end

  end
end

