/** SYNC_NODE*/

/** This node is a subscriber to Baxter JointState and Motion Capture. It takes information about joints position of baxter and
  coordinates of the human arm. The output is a txt file well organised in order to have a matrix with baxter joint value and
  human arm coordinate*/




#include "ros/ros.h"
#include <tf/transform_listener.h>
#include <rosbag/bag.h>
#include "std_msgs/String.h"
#include "std_msgs/Int32.h"
#include "std_msgs/Float32.h"
#include "std_msgs/Float32MultiArray.h"
#include "geometry_msgs/Point.h"
#include <geometry_msgs/PoseStamped.h>
#include "sensor_msgs/Imu.h"
#include "sensor_msgs/JointState.h"

#include <sstream>
#include <string>
#include <iostream>
#include <fstream>


/** Message Specification
*geometry_msgs are the messages from the four Motion capture topic. Each one give information about the coordinate position
*of  a rigid body trasmitted in the topic created by the modification of mocap.yaml file.
*
*Sensor_msgs are the messages that give information about the baxter joint state in terms of position, velocity and effort.
*We use only the information about joint name and position value.
*We store the information messages in different array.*/

geometry_msgs::PoseStamped posture1;
geometry_msgs::PoseStamped posture2;
geometry_msgs::PoseStamped posture3;
geometry_msgs::PoseStamped posture4;
sensor_msgs::JointState baxterPose;


/** Define the the vector for double joint value and for string joint name*/
std::vector<double> joints; // valori joint
std::vector<std::string> names; // stringa names per i nomi dei joint

/** Set flag to false */
bool flagMotion1 = false;
bool flagMotion2 = false;
bool flagMotion3 = false;
bool flagMotion4 = false;
bool flagBaxterPose = false;


using namespace std;


/** Callback to different publisher : four for the Motion Capture and one for JointState baxter. */
void coordinates_callback_1(const geometry_msgs::PoseStamped::ConstPtr& msg)
{

        posture1.pose.position = msg->pose.position; // pointer to position information
        flagMotion1 = true;
}
void coordinates_callback_2(const geometry_msgs::PoseStamped::ConstPtr& msg)
{

        posture2.pose.position = msg->pose.position;// pointer to position information
        flagMotion2 = true;
}
void coordinates_callback_3(const geometry_msgs::PoseStamped::ConstPtr& msg)
{

        posture3.pose.position = msg->pose.position;// pointer to position information
        flagMotion3 = true;
}
void coordinates_callback_4(const geometry_msgs::PoseStamped::ConstPtr& msg)
{

        posture4.pose.position = msg->pose.position;// pointer to position information
        flagMotion4 = true;
}


void baxter_joint_callback(const sensor_msgs::JointState::ConstPtr& msg)
{
 /*       ROS_INFO("callback");
        std::string temp;
        temp.append(msg->name[0]);
        baxterPose.name = temp;


        float temp_joint;
        temp_joint.append(msg-> position[0]);
        baxterPose.position = temp_joint; */

        joints.clear(); //clear joint string every time new data are available
        names.clear(); // clear name string every time new data are availabl
        joints = msg->position; //pointer to position information inside msgs
        names = msg->name; //pointer to joint name information

        /** set flag true only if the end effector values does not compare in the string in the first two position */
        if (names[0] == "r_gripper_l_finger_joint" || names[1] == "l_gripper_l_finger_joint"){
        flagBaxterPose = false;
        }
        else
        {
         flagBaxterPose = true;
        }
}


int main(int argc, char **argv)
{
        ros::init(argc, argv, "sync_node"); //define node name
        ros::NodeHandle nh;

        /** call to subscriber*/
        ros::Subscriber coordinates_1 = nh.subscribe("/Robot_1/pose",1, coordinates_callback_1);
        ros::Subscriber coordinates_2 = nh.subscribe("/Robot_2/pose",1,coordinates_callback_2);
        ros::Subscriber coordinates_3 = nh.subscribe("/Robot_3/pose",1,coordinates_callback_3);
        ros::Subscriber coordinates_4 = nh.subscribe("/Robot_4/pose",1,coordinates_callback_4);
        ros::Subscriber baxter_joint = nh.subscribe("/robot/joint_states",1,baxter_joint_callback);

        rosbag::Bag bag;

        /** text file creation*/
        std::string file_name;
        cout << "Nome file: "<<endl;
        cin >> file_name;
        file_name.append(".txt");
        bag.open(file_name, rosbag::bagmode::Write);
        std::ofstream file(file_name.c_str());

       /** main loop rate*/
       ros::Rate r(60);
       int count = 0;

       /** main loop*/
       while(ros::ok()){
            count ++;


        if(flagMotion1 & flagMotion2 & flagMotion3 & flagMotion4 & flagBaxterPose){
        r.sleep();


        ros::Time current = ros::Time::now();
        ostringstream Xos;

        /** write on file in the correct order. First the seven Joint of the baxter left arm and then the 12 coordinates of the four
        *human arm section: shoulder,elbow,wrist,hand. */
        if (count < 5)
           {
           cout<<names[2] << ","<<names[3]<<","<<names[4]<<","<<names[5]<<","<<names[6]<<","<<names[7]<<","<<names[8]<<","<<"right_shoulder_X"<<","<<"right_shoulder_Y"<<","<<"right_shoulder_Z"<<","<<"right_elbow_X"<<","<<"right_elbow_Y"<<","<<"right_elbow_Z"<<","<<"right_wrist_X"<<","<<"rright_wrist_Y"<<","<<"right_wrist_Z"<<","<<"right_hand_X"<<","<<"right_hand_Y"<<","<<"right_hand_Z"<<"\n";
           cout<<joints[2] << ","<<joints[3]<< ","<< joints[4]<< ","<< joints[5]<< ","<< joints[6]<< ","<< joints[7]<< ","<< joints[8]<<","<<posture1.pose.position.x<<"," <<posture1.pose.position.y<<","<<posture1.pose.position.z<<","<< posture2.pose.position.x<<","<<posture2.pose.position.y<<","<<posture2.pose.position.z<<","<<posture3.pose.position.x<<","<<posture3.pose.position.y<<","<<posture3.pose.position.z<<","<<posture4.pose.position.x<<","<<posture4.pose.position.y<<","<<posture4.pose.position.z<<"\n";
           file<<names[2] << ","<<names[3]<<","<<names[4]<<","<<names[5]<<","<<names[6]<<","<<names[7]<<","<<names[8]<<","<<"right_shoulder_X"<<","<<"right_shoulder_Y"<<","<<"right_shoulder_Z"<<","<<"right_elbow_X"<<","<<"right_elbow_Y"<<","<<"right_elbow_Z"<<","<<"right_wrist_X"<<","<<"rright_wrist_Y"<<","<<"right_wrist_Z"<<","<<"right_hand_X"<<","<<"right_hand_Y"<<","<<"right_hand_Z"<<"\n";
           file<<joints[2] << ","<<joints[3]<< ","<< joints[4]<< ","<< joints[5]<< ","<< joints[6]<< ","<< joints[7]<< ","<< joints[8]<<","<<posture1.pose.position.x<<"," <<posture1.pose.position.y<<","<<posture1.pose.position.z<<","<< posture2.pose.position.x<<","<<posture2.pose.position.y<<","<<posture2.pose.position.z<<","<<posture3.pose.position.x<<","<<posture3.pose.position.y<<","<<posture3.pose.position.z<<","<<posture4.pose.position.x<<","<<posture4.pose.position.y<<","<<posture4.pose.position.z<<"\n";
           }
           else
           {
           cout<<joints[2] << ","<<joints[3]<< ","<< joints[4]<< ","<< joints[5]<< ","<< joints[6]<< ","<< joints[7]<< ","<< joints[8]<<","<<posture1.pose.position.x<<"," <<posture1.pose.position.y<<","<<posture1.pose.position.z<<","<< posture2.pose.position.x<<","<<posture2.pose.position.y<<","<<posture2.pose.position.z<<","<<posture3.pose.position.x<<","<<posture3.pose.position.y<<","<<posture3.pose.position.z<<","<<posture4.pose.position.x<<","<<posture4.pose.position.y<<","<<posture4.pose.position.z<<"\n";
           file<<joints[2] << ","<<joints[3]<< ","<< joints[4]<< ","<< joints[5]<< ","<< joints[6]<< ","<< joints[7]<< ","<< joints[8]<<","<<posture1.pose.position.x<<"," <<posture1.pose.position.y<<","<<posture1.pose.position.z<<","<< posture2.pose.position.x<<","<<posture2.pose.position.y<<","<<posture2.pose.position.z<<","<<posture3.pose.position.x<<","<<posture3.pose.position.y<<","<<posture3.pose.position.z<<","<<posture4.pose.position.x<<","<<posture4.pose.position.y<<","<<posture4.pose.position.z<<"\n";

           }


           flagMotion1 = false;
           flagMotion2 = false;
           flagMotion3 = false;
           flagMotion4 = false;
           flagBaxterPose = false;

           }

           ros::spinOnce();
           r.sleep();
           count ++;
        }

     bag.close();
     file.close();

     return 0;
}
