#include <memory>
#include <time.h>
#include <thread>
#include <cstdlib>
#include <chrono>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
using std::placeholders::_1;

class MinimalSubscriber : public rclcpp::Node
{
  public:
    MinimalSubscriber()
    : Node("minimal_subscriber")
    {
      subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
      start = std::chrono::system_clock::now();
    }

    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
      //RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      count++;
      //std::cout<<"count: "<<count<<std::endl;

      end = std::chrono::system_clock::now();
      std::chrono::duration<double> elapsed_seconds = end - start;
      double diff = elapsed_seconds.count() * 1000;
      if(diff > 1000){
        std::cout<<"count: "<<count<<std::endl;
        start = std::chrono::system_clock::now();
      }

    }
      
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    int count;
    std::chrono::time_point<std::chrono::system_clock> start, end;
};



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}