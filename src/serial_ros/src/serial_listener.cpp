#include <ros/ros.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <serial/serial.h>
#include "std_msgs/String.h"

void doMsg(const std_msgs::String::ConstPtr& msg_p)
{    
    const char* msg_string = msg_p->data.c_str();

    char msg_index[3];
    msg_index[0] = msg_string[1];
    msg_index[1] = msg_string[2];

    int msg_index_int = atoi(msg_index);//将字符串转换为整型数据

    int size = strlen(msg_string);//包括'\0'
    char msg_range[size-4];
    for (int i = 0; i <= size-6; i++)
    {
        msg_range[i] = msg_string[4+i];
    }

    char* msg_category[18];//不能通过char**直接赋值
    switch (msg_index_int)
    {
    case 0:
        msg_category[0] = (char*)"1";
        break;

    case 1:
        msg_category[1] = msg_range;
        break;

    case 2:
        msg_category[2] = msg_range;
        break;

    case 3:
        msg_category[3] = msg_range;
        break;

    case 4:
        msg_category[4] = msg_range;
        break;

    case 5:
        msg_category[5] = msg_range;
        break;

    case 6:
        msg_category[6] = msg_range;
        break;

    case 7:
        msg_category[7] = msg_range;
        break;

    case 8:
        msg_category[8] = msg_range;
        break;

    case 9:
        msg_category[9] = msg_range;
        break;

    case 10:
        msg_category[10] = msg_range;
        break;

    case 11:
        msg_category[11] = msg_range;
        break;

    case 12:
        msg_category[12] = msg_range;
        break;

    case 13:
        msg_category[13] = msg_range;
        break;

    case 14:
        msg_category[14] = msg_range;
        break;

    case 15:
        msg_category[15] = msg_range;
        break;

    case 16:
        msg_category[16] = msg_range;
        break;

    default:
        break;
    }

    // std::cout << msg_p->data.c_str() << std::endl;
    // std::cout << msg_string << std::endl;
    // std::cout << msg_string[1] << msg_string[2] <<std::endl;
    // std::cout << msg_string << size <<std::endl;

    int msg_16 = atoi(msg_category[16]);//将字符串转换为整型数据
    std::cout << msg_16 << std::endl;
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
