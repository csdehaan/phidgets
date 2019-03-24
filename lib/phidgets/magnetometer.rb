

module Phidgets
  class Magnetometer < Common

    # call-seq:
    #   setOnMagneticFieldChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the MagneticFieldChange event occurs.
    #
    def setOnMagneticFieldChangeHandler(cb_proc = nil, &cb_block)
      @on_magnetic_field_change_thread.kill if defined? @on_magnetic_field_change_thread and @on_magnetic_field_change_thread.alive?
      callback = cb_proc || cb_block
      @on_magnetic_field_change_thread = Thread.new {ext_setOnMagneticFieldChangeHandler(callback)}
    end

    alias :on_magnetic_field_change :setOnMagneticFieldChangeHandler

  end
end

