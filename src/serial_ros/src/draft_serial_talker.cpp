#include "ros/ros.h"
#include "std_msgs/UInt8.h"
#include <sstream>

int main(int argc, char *argv[])
{
    /* code */
    ros::init(argc, argv, "talker");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::UInt8>("chatter", 10);
    
    std_msgs::UInt8 msg;
    msg.data = "Hello";
    ros::Rate r(10);//10Hz

    while(ros::ok())
    {
        pub.publish(msg);
        r.sleep();
        ros::spinOnce();
    }
    return 0;
}
