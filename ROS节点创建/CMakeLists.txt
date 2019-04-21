include_directories( 
   include 
   ${catkin_INCLUDE_DIRS} 
   ${Boost_INCLUDE_DIRS} 
) 
#This will create executables of the nodes 
add_executable(demo_topic_publisher src/demo_topic_publisher.cpp) 
add_executable(demo_topic_subscriber src/demo_topic_subscriber.cpp) 
 
#This will generate message header file before building the target 
add_dependencies(demo_topic_publisher mastering_ros_demo_pkg_generate_messages_cpp) 
add_dependencies(demo_topic_subscriber mastering_ros_demo_pkg_generate_messages_cpp) 
 
#This will link executables to the appropriate libraries  
target_link_libraries(demo_topic_publisher ${catkin_LIBRARIES}) 
target_link_libraries(demo_topic_subscriber ${catkin_LIBRARIES}) 