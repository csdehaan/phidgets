

module Phidgets
  class Spatial < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnSpatialDataHandler(proc=nil, &block)
      #
      # Set a Data event handler. This is called at getDataRate, up to 8ms.
      #
      def setOnSpatialDataHandler(cb_proc = nil, &cb_block)
        @on_spatial_data_thread.kill if defined? @on_spatial_data_thread
        callback = cb_proc || cb_block
        @on_spatial_data_thread = Thread.new {ext_setOnSpatialDataHandler(callback)}
      end

      alias :on_spatial_data :setOnSpatialDataHandler

    end

  end
end

