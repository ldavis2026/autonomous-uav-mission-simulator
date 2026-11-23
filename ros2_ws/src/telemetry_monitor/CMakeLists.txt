cmake_minimum_required(VERSION 3.8)
project(telemetry_monitor)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(px4_msgs REQUIRED)

add_executable(telemetry_monitor src/telemetry_monitor.cpp)

ament_target_dependencies(telemetry_monitor rclcpp px4_msgs)

install(TARGETS telemetry_monitor DESTINATION lib/${PROJECT_NAME})

ament_package()
