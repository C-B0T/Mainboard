#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

#include <sstream>

int main(int argc, char **argv)
{

    ros::init(argc, argv, "cbot_main");

    ros::NodeHandle n;

    //ros::Publisher pub = n.advertise<std_msgs::String>("pub", 1000);
    ros::Publisher pub_cmd_vel = n.advertise<geometry_msgs::Twist>("/botB/cmd_vel", 1);

    //ros::Rate loop_rate(10);
    ros::Rate loop_rate(1);

    int count = 0;

    while(ros::ok())
    {
        //std_msgs::String msg;
	geometry_msgs::Twist msg;

        //std::stringstream ss;
        //ss << "hello" << count;
        //msg.data = ss.str();
        //ROS_INFO("%s", msg.data.c_str());

	// RUN
	msg.linear.x = 1;
        pub_cmd_vel.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        count++;

	// STOP
	msg.linear.x = 0;
        pub_cmd_vel.publish(msg);

        ros::spinOnce();

        loop_rate.sleep();
        count++;
    }

    return 0;
}
