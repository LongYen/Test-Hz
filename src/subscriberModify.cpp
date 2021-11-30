#include <memory>
#include "test_package/tic_toc.hpp"

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
      time.tic();
    }

    void topic_callback(const std_msgs::msg::String::SharedPtr msg)
    {
      //RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
      count++;
      //std::cout<<"count: "<<count<<std::endl;

      double diff = time.toc();
      if(diff > 1000){
       
      }

    }
      
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
    int count;

    TicToc time;
};


int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}