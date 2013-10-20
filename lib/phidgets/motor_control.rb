

module Phidgets
  class MotorControl < Common

    unless RUBY_VERSION < '1.9.0'

      # call-seq:
      #   setOnVelocityChangeHandler(proc=nil, &block)
      #
      # Sets a velocity change event handler. This is called when the velocity changes.
      #
      def setOnVelocityChangeHandler(cb_proc = nil, &cb_block)
        @on_velocity_change_thread.kill if defined? @on_velocity_change_thread
        callback = cb_proc || cb_block
        @on_velocity_change_thread = Thread.new {ext_setOnVelocityChangeHandler(callback)}
      end

      # call-seq:
      #   setOnCurrentChangeHandler(proc=nil, &block)
      #
      # Sets a current change event handler. This is called when the current draw changes.
      #
      def setOnCurrentChangeHandler(cb_proc = nil, &cb_block)
        @on_current_change_thread.kill if defined? @on_current_change_thread
        callback = cb_proc || cb_block
        @on_current_change_thread = Thread.new {ext_setOnCurrentChangeHandler(callback)}
      end

      # call-seq:
      #   setOnCurrentUpdateHandler(proc=nil, &block)
      #
      # Set a current update handler. This is called at a constant rate; every 8ms.
      #
      def setOnCurrentUpdateHandler(cb_proc = nil, &cb_block)
        @on_current_update_thread.kill if defined? @on_current_update_thread
        callback = cb_proc || cb_block
        @on_current_update_thread = Thread.new {ext_setOnCurrentUpdateHandler(callback)}
      end

      # call-seq:
      #   setOnInputChangeHandler(proc=nil, &block)
      #
      # Set a digital input change handler. This is called when a digital input changes.
      #
      def setOnInputChangeHandler(cb_proc = nil, &cb_block)
        @on_input_change_thread.kill if defined? @on_input_change_thread
        callback = cb_proc || cb_block
        @on_input_change_thread = Thread.new {ext_setOnInputChangeHandler(callback)}
      end

      # call-seq:
      #   setOnEncoderPositionChangeHandler(proc=nil, &block)
      #
      # Set an encoder position change handler. This is called when the encoder position changes.
      #
      def setOnEncoderPositionChangeHandler(cb_proc = nil, &cb_block)
        @on_encoder_position_change_thread.kill if defined? @on_encoder_position_change_thread
        callback = cb_proc || cb_block
        @on_encoder_position_change_thread = Thread.new {ext_setOnEncoderPositionChangeHandler(callback)}
      end

      # call-seq:
      #   setOnEncoderPositionUpdateHandler(proc=nil, &block)
      #
      # Set an encoder position update handler. This is called at a constant rate; every 8ms, whether the encoder
      # position has changed or not.
      #
      def setOnEncoderPositionUpdateHandler(cb_proc = nil, &cb_block)
        @on_encoder_position_update_thread.kill if defined? @on_encoder_position_update_thread
        callback = cb_proc || cb_block
        @on_encoder_position_update_thread = Thread.new {ext_setOnEncoderPositionUpdateHandler(callback)}
      end

      # call-seq:
      #   setOnBackEMFUpdateHandler(proc=nil, &block)
      #
      # Set a back EMF update handler. This is called at a constant rate; every 16ms, when back EMF sensing is enabled for that motor.
      #
      def setOnBackEMFUpdateHandler(cb_proc = nil, &cb_block)
        @on_back_emf_update_thread.kill if defined? @on_back_emf_update_thread
        callback = cb_proc || cb_block
        @on_back_emf_update_thread = Thread.new {ext_setOnBackEMFUpdateHandler(callback)}
      end

      # call-seq:
      #   setOnSensorUpdateHandler(proc=nil, &block)
      #
      # Set a sensor update handler. This is called at a constant rate; every 8ms.
      #
      def setOnSensorUpdateHandler(cb_proc = nil, &cb_block)
        @on_sensor_update_thread.kill if defined? @on_sensor_update_thread
        callback = cb_proc || cb_block
        @on_sensor_update_thread = Thread.new {ext_setOnSensorUpdateHandler(callback)}
      end

      alias :on_velocity_change :setOnVelocityChangeHandler
      alias :on_current_change :setOnCurrentChangeHandler
      alias :on_current_update :setOnCurrentUpdateHandler
      alias :on_input_change :setOnInputChangeHandler
      alias :on_encoder_position_change :setOnEncoderPositionChangeHandler
      alias :on_encoder_position_update :setOnEncoderPositionUpdateHandler
      alias :on_back_emf_update :setOnBackEMFUpdateHandler
      alias :on_sensor_update :setOnSensorUpdateHandler

    end

  end
end

