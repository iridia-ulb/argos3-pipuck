# system test
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_system.argos.in
  ${CMAKE_BINARY_DIR}/testing/test_system.argos)
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_system.lua
  ${CMAKE_BINARY_DIR}/testing/test_system.lua)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_system.lua DESTINATION share/argos3/testing)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_system.argos DESTINATION share/argos3/testing)
# leds test
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_leds.argos.in
  ${CMAKE_BINARY_DIR}/testing/test_leds.argos)
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_leds.lua
  ${CMAKE_BINARY_DIR}/testing/test_leds.lua)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_leds.lua DESTINATION share/argos3/testing)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_leds.argos DESTINATION share/argos3/testing)
# differential drive test
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_differential_drive.argos.in
  ${CMAKE_BINARY_DIR}/testing/test_differential_drive.argos)
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_differential_drive.lua
  ${CMAKE_BINARY_DIR}/testing/test_differential_drive.lua)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_differential_drive.lua DESTINATION share/argos3/testing)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_differential_drive.argos DESTINATION share/argos3/testing)
# rangefinders test
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_rangefinders.argos.in
  ${CMAKE_BINARY_DIR}/testing/test_rangefinders.argos)
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_rangefinders.lua
  ${CMAKE_BINARY_DIR}/testing/test_rangefinders.lua)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_rangefinders.lua DESTINATION share/argos3/testing)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_rangefinders.argos DESTINATION share/argos3/testing)
# ground sensors test
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_ground_sensors.argos.in
  ${CMAKE_BINARY_DIR}/testing/test_ground_sensors.argos)
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_ground_sensors.lua
  ${CMAKE_BINARY_DIR}/testing/test_ground_sensors.lua)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_ground_sensors.lua DESTINATION share/argos3/testing)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_ground_sensors.argos DESTINATION share/argos3/testing)
# cameras test
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_cameras.argos.in
  ${CMAKE_BINARY_DIR}/testing/test_cameras.argos)
configure_file(
  ${CMAKE_SOURCE_DIR}/testing/test_cameras.lua
  ${CMAKE_BINARY_DIR}/testing/test_cameras.lua)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_cameras.lua DESTINATION share/argos3/testing)
  install(FILES ${CMAKE_BINARY_DIR}/testing/test_cameras.argos DESTINATION share/argos3/testing)

