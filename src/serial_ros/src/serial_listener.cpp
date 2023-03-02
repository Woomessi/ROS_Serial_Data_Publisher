#include <ros/ros.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <serial/serial.h>
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr &msg_p)
{
    const char *msg_string = msg_p->data.c_str();

    int msg_index;
    int msg_range;
    int msg_category[18];

    size_t length = strlen(msg_string);
    for (size_t i = 0; i < length - 1; i++)
    {
        int j;
        int k;
        char char_now = msg_string[i];
        switch (char_now)
        {
        case 's':
        {
            j = i;
            char msg_index_string[3] = {msg_string[j + 1], msg_string[j + 2]};
            msg_index = atoi(msg_index_string);
            break;
        }
        case 'r':
        {
            j = i;
            char msg_range_string[4] = {msg_string[j + 1], msg_string[j + 2], msg_string[j + 3]};
            msg_range = atoi(msg_range_string);
            msg_category[msg_index] = msg_range;
            break;
        }
        default:
            break;
        }
    }

    for (int i = 1; i < 16; i++)
    {
        std::cout << 's' << i << 'r' << msg_category[i];
    }
    std::cout << 's' << 16 << 'r' << msg_category[16] << std::endl;

    std::cout << msg_string << std::endl;
}

int main(int argc, char *argv[])
{
    /* code */
    ros::init(argc, argv, "listener");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe<std_msgs::String>("chatter", 10, doMsg);
    ros::spin();

    return 0;
}
