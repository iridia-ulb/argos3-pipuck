--[[ This function is executed every time you press the 'execute' button ]]
function init()
   reset()
end

--[[ This function is executed at each time step
     It must contain the logic of your controller ]]
function step()
   if robot.debug ~= nil then
      robot.debug.draw("arrow(red)(0.125,0,0.05)(0.25,0,0.05)")
      robot.debug.draw("arrow(green)(0,0.125,0.05)(0,0.25,0.05)")
      robot.debug.draw("arrow(blue)(0,0,0.25)(0,0,0.50)")
   end
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
   -- put your code here
end
