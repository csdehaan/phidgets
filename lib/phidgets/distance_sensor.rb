

module Phidgets
  class DistanceSensor < Common

    # call-seq:
    #   setOnDistanceChangeHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the DistanceChange event occurs.
    #
    def setOnDistanceChangeHandler(cb_proc = nil, &cb_block)
      @on_distance_change_thread.kill if defined? @on_distance_change_thread and @on_distance_change_thread.alive?
      callback = cb_proc || cb_block
      @on_distance_change_thread = Thread.new {ext_setOnDistanceChangeHandler(callback)}
    end

    # call-seq:
    #   setOnSonarReflectionsUpdateHandler(proc=nil, &block)
    #
    # Assigns a handler that will be called when the SonarReflectionsUpdate event occurs.
    #
    def setOnSonarReflectionsUpdateHandler(cb_proc = nil, &cb_block)
      @on_reflections_update_thread.kill if defined? @on_reflections_update_thread and @on_reflections_update_thread.alive?
      callback = cb_proc || cb_block
      @on_reflections_update_thread = Thread.new {ext_setOnSonarReflectionsUpdateHandler(callback)}
    end

    alias :on_distance_change :setOnDistanceChangeHandler
    alias :on_sonar_reflections_update :setOnSonarReflectionsUpdateHandler

  end
end

