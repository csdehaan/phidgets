

module Phidgets
  class Gyroscope < Common

    # call-seq:
    #   setOnAngularRateUpdateHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the AngularRateUpdate event occurs.
    #
    def setOnAngularRateUpdateHandler(cb_proc = nil, &cb_block)
      @on_angular_rate_update_thread.kill if defined? @on_angular_rate_update_thread and @on_angular_rate_update_thread.alive?
      callback = cb_proc || cb_block
      @on_angular_rate_update_thread = Thread.new {ext_setOnAngularRateUpdateHandler(callback)}
    end

    alias :on_angular_rate_update :setOnAngularRateUpdateHandler

  end
end

