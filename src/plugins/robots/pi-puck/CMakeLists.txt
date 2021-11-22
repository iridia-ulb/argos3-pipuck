#
# Pi-Puck headers
#
# argos3/plugins/robots/pi-puck/hardware
set(ARGOS3_HEADERS_PLUGINS_ROBOTS_PIPUCK_HARDWARE
  hardware/actuator.h
#   hardware/pipuck_camera_system_default_sensor.h
  hardware/pipuck_differential_drive_default_actuator.h
  hardware/pipuck_differential_drive_default_sensor.h
  hardware/pipuck_ground_default_sensor.h
  hardware/pipuck_leds_default_actuator.h
  hardware/pipuck_system_default_sensor.h
  hardware/pipuck_rangefinders_default_sensor.h
  hardware/radios_default_actuator.h
  hardware/radios_default_sensor.h
  hardware/robot.h
  hardware/sensor.h)

#
# Pi-Puck sources
#
# argos3/plugins/robots/pi-puck/hardware
set(ARGOS3_SOURCES_PLUGINS_ROBOTS_PIPUCK
  ${ARGOS3_SOURCES_PLUGINS_ROBOTS_PIPUCK}
  ${ARGOS3_HEADERS_PLUGINS_ROBOTS_PIPUCK_HARDWARE}
  hardware/main.cpp
#   hardware/pipuck_camera_system_default_sensor.cpp
  hardware/pipuck_differential_drive_default_actuator.cpp
  hardware/pipuck_differential_drive_default_sensor.cpp
  hardware/pipuck_ground_default_sensor.cpp
  hardware/pipuck_leds_default_actuator.cpp
  hardware/pipuck_system_default_sensor.cpp
  hardware/pipuck_rangefinders_default_sensor.cpp
  hardware/radios_default_actuator.cpp
  hardware/radios_default_sensor.cpp
  hardware/robot.cpp)

# Create an executable for the robot
add_executable(argos3 ${ARGOS3_SOURCES_PLUGINS_ROBOTS_PIPUCK})
target_link_libraries(argos3 stdc++fs
  argos3core_${ARGOS_BUILD_FOR}
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot
  argos3plugin_${ARGOS_BUILD_FOR}_pipuck
  ${APRILTAG_LIBRARY}
  ${IIO_LIBRARY}
  ${V4L2SUBDEV_LIBRARY})
  
# Install executable and header files
install(TARGETS argos3
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib/argos3
  ARCHIVE DESTINATION lib/argos3)
install(FILES ${ARGOS3_HEADERS_PLUGINS_ROBOTS_PIPUCK_HARDWARE} DESTINATION include/argos3/plugins/robots/pi-puck/hardware)
