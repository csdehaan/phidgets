

module Phidgets
  class HumiditySensor < Common

    # call-seq:
    #   setOnHumidityChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the HumidityChange event occurs.
    #
    def setOnHumidityChangeHandler(cb_proc = nil, &cb_block)
      @on_humidity_change_thread.kill if defined? @on_humidity_change_thread and @on_humidity_change_thread.alive?
      callback = cb_proc || cb_block
      @on_humidity_change_thread = Thread.new {ext_setOnHumidityChangeHandler(callback)}
    end

    alias :on_humidity_change :setOnHumidityChangeHandler

  end
end

