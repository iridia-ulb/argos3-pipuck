function init()
end

function step()
   log("time = " .. string.format("%.1f", robot.system.time) .. " seconds");
   log("temperature = " .. string.format("%.1f", robot.system.temperature) .. " degrees");
   log("random integer = " .. string.format("%.0f", robot.random.uniform_int(0,20)));
end

function reset()
end

function destroy()
end
