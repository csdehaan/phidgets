

module Phidgets
  class Spatial < Common

    # call-seq:
    #   setOnSpatialDataHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the SpatialData event occurs.
    #
    def setOnSpatialDataHandler(cb_proc = nil, &cb_block)
      @on_spatial_data_thread.kill if defined? @on_spatial_data_thread and @on_spatial_data_thread.alive?
      callback = cb_proc || cb_block
      @on_spatial_data_thread = Thread.new {ext_setOnSpatialDataHandler(callback)}
    end

    alias :on_spatial_data :setOnSpatialDataHandler

  end
end

