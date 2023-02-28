#include <ros/ros.h>
#include <sstream>
#include <iostream>
#include <serial/serial.h>
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p)
{    
    std::cout << msg_p->data << std::endl;
}

int main(int argc, char *argv[])
{
    /* code */
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter",10, doMsg);
    ros::spin();

    return 0;
}
