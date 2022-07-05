#include <ros/ros.h>
#include <std_msgs/Float64MultiArray.h>

std_msgs::Float64MultiArray cmd;
ros::Publisher command_pub;

const double c_chest_yaw_amplitude = 1.0;
const double c_head_yaw_amplitude = 1.5;

const double c_chest_yaw_freq = 0.5;
const double c_head_yaw_freq = 1.0;

int main(int argc, char** argv){
    ros::init(argc, argv, "choreonoid_ros_khr3_control_group");
    ros::NodeHandle nh("khr3_001");   // set namespace
    ros::Rate loop_rate(50);

    command_pub = nh.advertise<std_msgs::Float64MultiArray>("joint_group_position_controller/command", 1);

    ros::Time t_start = ros::Time::now();

    while(ros::ok()){
        double current_time = (ros::Time::now() - t_start).toSec();

        cmd.data.resize(22);
        cmd.data[0] = c_chest_yaw_amplitude * sin(2 * M_PI * c_chest_yaw_freq * current_time);
        cmd.data[1] = 0;
        cmd.data[2] = 0;
        cmd.data[3] = 0;
        cmd.data[4] = 0;
        cmd.data[5] = 0;
        cmd.data[6] = 0;
        cmd.data[7] = 0;
        cmd.data[8] = 0;
        cmd.data[10] = 0;
        cmd.data[11] = c_head_yaw_amplitude * sin(2 * M_PI * c_head_yaw_freq * current_time);
        cmd.data[12] = 0;
        cmd.data[13] = 0;
        cmd.data[14] = 0;
        cmd.data[15] = 0;
        cmd.data[16] = 0;
        cmd.data[17] = 0;
        cmd.data[18] = 0;
        cmd.data[19] = 0;
        cmd.data[20] = 0;
        cmd.data[21] = 0;

        command_pub.publish(cmd);

        loop_rate.sleep();
    }
    return 0;
}
