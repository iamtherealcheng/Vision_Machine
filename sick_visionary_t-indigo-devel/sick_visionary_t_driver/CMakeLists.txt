cmake_minimum_required(VERSION 2.8.3)// phiên bản tối thiểu của cmake
project(sick_visionary_t_driver)// sử dụng project() lệnh đặt tên dự án

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  roslaunch
)

find_package(Boost REQUIRED COMPONENTS system)
find_package(OpenCV REQUIRED)

catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp
)

### BUILD ###
include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

add_executable(sick_visionary_t_driver_node src/node.cpp src/driver.cpp)// thêm tệp thực thi

target_link_libraries(sick_visionary_t_driver_node
  ${catkin_LIBRARIES}
  ${OpenCV_LIBS}
)// thêm vào đườn dẫn cho các tệp thư viện

### TEST ###
if(CATKIN_ENABLE_TESTING)
  roslaunch_add_file_check(launch)
endif()

### INSTALL ###
install(TARGETS sick_visionary_t_driver_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)
