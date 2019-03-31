

module Phidgets
  class RFID < Common

    # call-seq:
    #   setOnTagHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the Tag event occurs.
    #
    def setOnTagHandler(cb_proc = nil, &cb_block)
      @on_tag_thread.kill if defined? @on_tag_thread and @on_tag_thread.alive?
      callback = cb_proc || cb_block
      @on_tag_thread = Thread.new {ext_setOnTagHandler(callback)}
    end

    # call-seq:
    #   setOnTagLostHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the TagLost event occurs.
    #
    def setOnTagLostHandler(cb_proc = nil, &cb_block)
      @on_tag_lost_thread.kill if defined? @on_tag_lost_thread and @on_tag_lost_thread.alive?
      callback = cb_proc || cb_block
      @on_tag_lost_thread = Thread.new {ext_setOnTagLostHandler(callback)}
    end

    alias :on_tag :setOnTagHandler
    alias :on_tag_lost :setOnTagLostHandler

  end
end

