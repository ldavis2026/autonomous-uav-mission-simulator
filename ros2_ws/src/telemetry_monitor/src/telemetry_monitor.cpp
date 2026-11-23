#include <rclcpp/rclcpp.hpp>
#include <px4_msgs/msg/vehicle_local_position.hpp>

using px4_msgs::msg::VehicleLocalPosition;

class TelemetryMonitor : public rclcpp::Node
{
public:
	TelemetryMonitor(): Node("telemetry_monitor")
	{
		auto qos = rclcpp::QoS(rclcpp::SensorDataQoS());

		position_subscriber_ = 
			this->create_subscription<VehicleLocalPosition>("/fmu/out/vehicle_local_position_v1", qos, [this](const VehicleLocalPosition::SharedPtr msg)
		{
			RCLCPP_INFO(this->get_logger(), "Position NED [m]: X=%.2f Y=%.2f Z=%.2f | " "Velocity [m/s]: VX=%.2f VY=%.2f VZ=%.2f | " "XY Valid =%d Z Valid=%d", msg->x, msg->y, msg->z, msg->vx, msg->vy, msg->vz, msg->xy_valid, msg->z_valid);
		});

		RCLCPP_INFO(this->get_logger(), "Telemetry Monitor started. Waiting for PX4 data...");
	}

private:
	rclcpp::Subscription<VehicleLocalPosition>::SharedPtr position_subscriber_;
};

int main(int argc, char *argv[])
{
	rclcpp::init(argc, argv);
	
	rclcpp::spin(std::make_shared<TelemetryMonitor>());

	rclcpp::shutdown();

	return 0;
}
