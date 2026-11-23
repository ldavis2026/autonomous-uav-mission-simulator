# Autonomous UAV Mission Simulator

An autonomous UAV simulation project using PX4, Gazebo, ROS 2, C++, and Python.

## Overview

The goal of this project is to develop an autonomous UAV mission simulator capable of receiving a mission, taking off, navigating through a series of waypoints, responding to simulated environmental disturbances and sensor degradation, and safely completing or aborting its mission.

The project uses PX4 for flight control, Gazebo for simulation, and ROS 2 for communication between the flight stack and custom software.

## Technology Stack

- **PX4 Autopilot** – Flight control and vehicle management.
- **Gazebo Sim** – 3D vehicle and environment simulation.
- **ROS 2 Humble** – Communication middleware.
- **C++** – Mission management and telemetry processing.
- **Python** – Planned telemetry visualization and analysis.
- **QGroundControl** – Vehicle monitoring and ground station interface.
- **Micro XRCE-DDS** – Communication between PX4 and ROS 2.

## Current Development Environment

- Ubuntu 22.04
- ROS 2 Humble
- PX4 v1.18.0 development version
- Gazebo Sim 8
- Quadrotor SITL simulation (`gz_x500`)

## Current Project Progress

### Completed

- Installed and built QGroundControl.
- Started PX4 SITL with the Gazebo x500 quadrotor.
- Connected QGroundControl to the simulated vehicle.
- Built and launched the Micro XRCE-DDS Agent.
- Established communication between PX4 and ROS 2.
- Configured and built the `px4_msgs` package.
- Verified live PX4 local-position telemetry through ROS 2.
- Created and successfully ran a read-only C++ telemetry monitor.

### In Progress

- Developing the autonomous mission management architecture.
- Designing mission-state tracking and waypoint management.
- Planning simulated sensor degradation and environmental disturbance scenarios.

### Planned

- Implement a C++ autonomous mission manager.
- Add waypoint-based mission execution.
- Develop fault detection and response logic.
- Simulate wind disturbances and sensor degradation.
- Implement safe mission continuation and abort decisions.
- Develop a Python telemetry visualization application.
- Evaluate mission performance and safety behavior.

## ROS 2 Workspace Structure

```text
ros2_ws/
└── src/
    ├── px4_msgs/
    ├── px4_msgs_old/
    ├── telemetry_monitor/
    └── translation_node/
```

## Running the Telemetry Monitor

Start PX4 SITL:

```bash
cd ~/PX4-Autopilot
make px4_sitl gz_x500
```

In another terminal, start the Micro XRCE-DDS Agent:

```bash
source /opt/ros/humble/setup.bash
source ~/px4_ros_uxrce_dds_ws/install/local_setup.bash
MicroXRCEAgent udp4 -p 8888
```

In another terminal, build the ROS 2 workspace:

```bash
source /opt/ros/humble/setup.bash
cd ~/autonomous_uav_project/ros2_ws
colcon build
source install/setup.bash
```

Run the telemetry monitor:

```bash
ros2 run telemetry_monitor telemetry_monitor
```

The monitor subscribes to PX4 local-position telemetry and reports position, velocity, and validity information.

## Safety and Testing

Development and testing are initially performed in simulation.

PX4 remains responsible for low-level flight stabilization and native failsafe functions. Custom mission-management software is intended to operate at a higher level rather than directly controlling motor outputs.

## Project Status

This project is under active development. The current milestone is establishing reliable PX4-to-ROS 2 communication and building the software foundation for autonomous mission management.
