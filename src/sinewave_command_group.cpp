#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>

std_msgs::Float64MultiArray cmd;
ros::Publisher command_pub;

const double l_shouluder_pitch_amplitude = 1.0;
const double l_shouluder_roll_amplitude = 1.5;
const double l_shouluder_pitch_freq = 0.5;
const double l_shouluder_roll_freq = 1.0;

int main(int argc, char** argv){
    ros::init(argc, argv, "choreonoid_ros_khr3_control_group");
    ros::NodeHandle nh("KHR3_001_description");   // set namespace
    ros::Rate loop_rate(50);

    command_pub = nh.advertise<std_msgs::Float64MultiArray>("joint_group_position_controller/command", 1);

    ros::Time t_start = ros::Time::now();

    while(ros::ok()){
        double current_time = (ros::Time::now() - t_start).toSec();

        cmd.data.resize(2);
        cmd.data[0] = l_shouluder_pitch_amplitude * sin(2 * M_PI * l_shouluder_pitch_freq * current_time);
        cmd.data[1] = l_shouluder_roll_amplitude * sin(2 * M_PI * l_shouluder_roll_freq * current_time);

        command_pub.publish(cmd);

        loop_rate.sleep();
    }
    return 0;
}
