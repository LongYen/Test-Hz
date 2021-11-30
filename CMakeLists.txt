cmake_minimum_required(VERSION 3.5)
project(test_package)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_BUILD_TYPE "Debug")
#set(CMAKE_BUILD_TYPE "Debug")

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
 src
 include
)

find_path(HEADERS NAMES tic_toc.h HINTS ${AMENT_PREFIX_PATH})

add_executable(publisher1 src/publisher1.cpp)
ament_target_dependencies(publisher1 rclcpp std_msgs)

add_executable(publisher src/publisher.cpp)
ament_target_dependencies(publisher rclcpp std_msgs)

add_executable(subscriber src/subscriber.cpp)
ament_target_dependencies(subscriber rclcpp std_msgs)

add_executable(subscriberModify 
src/subscriberModify.cpp
src/tic_toc.cpp
)
ament_target_dependencies(subscriberModify rclcpp std_msgs)

install(TARGETS publisher
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS publisher1
DESTINATION lib/${PROJECT_NAME})

install(TARGETS subscriber
DESTINATION lib/${PROJECT_NAME})

install(TARGETS subscriberModify
DESTINATION lib/${PROJECT_NAME})

install(
  DIRECTORY include/
  DESTINATION include
)

ament_package()
