--[[ This function is executed every time you press the 'execute' button ]]
function init()
   robot.front_camera.enable()
end

--[[ This function is executed at each time step
     It must contain the logic of your controller ]]
function step()
   for index, tag in ipairs(robot.front_camera.tags) do
      print("tag " .. index .. ": " .. tostring(tag.center))
   end
   print("---")
end

--[[ This function is executed every time you press the 'reset'
     button in the GUI. It is supposed to restore the state
     of the controller to whatever it was right after init() was
     called. The state of sensors and actuators is reset
     automatically by ARGoS. ]]
function reset()
end

--[[ This function is executed only once, when the robot is removed
     from the simulation ]]
function destroy()
   robot.front_camera.disable()
end
