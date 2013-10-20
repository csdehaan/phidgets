

module Phidgets
  class FrequencyCounter < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnCountHandler(proc=nil, &block)
      #
      # Sets a count event handler. This is called when ticks have been counted on an input, or when the timeout has passed.
      #
      def setOnCountHandler(cb_proc = nil, &cb_block)
        @on_count_thread.kill if defined? @on_count_thread
        callback = cb_proc || cb_block
        @on_count_thread = Thread.new {ext_setOnCountHandler(callback)}
      end

      alias :on_count :setOnCountHandler

    end

  end
end

