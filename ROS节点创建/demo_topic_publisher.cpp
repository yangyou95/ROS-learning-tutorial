#include "ros/ros.h" 
#include "std_msgs/Int32.h"
#include <iostream> 
int main(int argc, char **argv) 
{ 
 //初始化一个叫“demo_topic_publisher”的ROS节点
 ros::init(argc, argv,"demo_topic_publisher"); 
 //创建一个Nodehandle对象，用来与ROS进行通信
 ros::NodeHandle node_obj; 
 //创建一个topic发布节点，节点是number_publisher，发布的topic的名称是"/numbers",发布的数据类型是Int32。第二项是buffer size参数。
 ros::Publisher number_publisher =  node_obj.advertise<std_msgs::Int32>("/numbers",10); 
 //定义发送数据频率，如果频率高的话注意同时调高上一个buffer size
 ros::Rate loop_rate(10); 
 //初始化一个int变量
 int number_count = 0; 
 //当按Ctrl+C时，ros::ok()会返回0，退出该while循环，。
 while (ros::ok()) 
 { 
  //创建Int32类型的ROS message
  std_msgs::Int32 msg; 
  //将整数变量值赋给Message的data。data是msg对象的一个field。
  msg.data = number_count; 
  //Print出msg.data的值，同时也会存储在ROS的log系统里。
  ROS_INFO("%d",msg.data); 
  //节点发布message数据到topic，注意这里是msg。
  number_publisher.publish(msg); 
  //读取和更新ROS topics，如果没有spinonce()或spin()，节点不会发布消息。
  ros::spinOnce(); 
  //为了达到之前定义的发送频率，需要一个delay时间。
  loop_rate.sleep(); 
  //整数变量自加1
  ++number_count; 
 } 
 return 0; 
} 