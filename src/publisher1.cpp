#include <chrono>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

/* We do not recommend this style anymore, because composition of multiple
 * nodes in the same executable is not possible. Please see one of the subclass
 * examples for the "new" recommended styles. This example is only included
 * for completeness because it is similar to "classic" standalone ROS nodes. */

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("minimal_publisher");
  auto publisher = node->create_publisher<std_msgs::msg::String>("topic", 10);
  std_msgs::msg::String message;
  auto publish_count = 0;
  rclcpp::WallRate loop_rate(20ms);

  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();

  double diff = 1.0;

  while (diff < 3000.0) {
    std::chrono::duration<double> elapsed_seconds = end - start;
    double diff = elapsed_seconds.count() * 1000;
    publish_count++;
    end = std::chrono::system_clock::now();
    loop_rate.sleep();
    std::cout<<"publish_count : "<<publish_count<<std::endl;
  }
  rclcpp::shutdown();
  return 0;
}