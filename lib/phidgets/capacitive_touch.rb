

module Phidgets
  class CapacitiveTouch < Common

    # call-seq:
    #   setOnTouchEndHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the TouchEnd event occurs.
    #
    def setOnTouchEndHandler(cb_proc = nil, &cb_block)
      @on_touch_end_thread.kill if defined? @on_touch_end_thread and @on_touch_end_thread.alive?
      callback = cb_proc || cb_block
      @on_touch_end_thread = Thread.new {ext_setOnTouchEndHandler(callback)}
    end

    # call-seq:
    #   setOnTouchHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the PositionChange event occurs.
    #
    def setOnTouchHandler(cb_proc = nil, &cb_block)
      @on_touch_thread.kill if defined? @on_touch_thread and @on_touch_thread.alive?
      callback = cb_proc || cb_block
      @on_touch_thread = Thread.new {ext_setOnTouchHandler(callback)}
    end

    alias :on_touch_end :setOnTouchEndHandler
    alias :on_touch :setOnTouchHandler

  end
end

