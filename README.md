# Baxter-Teleoperation
SOFAR AA 2017/2018

This software was developed during a group project, it's aim is to teleoperate two-armed robot Baxter by [Rethink-Robotics(http://www.rethinkrobotics.com)]. For reach this objective it was necessary two software archictectures : one for data collection, another one for MATLAB Neural Network training and ON-LINE Robot Teleoperation. 
The necessary equipment is:

1.Motion Capture system
2.Baxter manipulator robot 


# Installation
For what regards packages "mocap_optitrack" and "sync"  is sufficient to copy them in a catkin workspace and compile them using catkin_make. 
For "Baxter Teleoperation" package it is necessary MATLAB 2017b or following. It can be edit in every OS (in my case i use macOS 10.13) because matlab is Ros compliant.  

All the ROS package were developed for ROS Kinetic.

# Usage
Here follows instructions to use the code :
On the mocap pc:
Open Motive application and enable streaming data by open the stream menu, set the streaming IP of your computer and tick "Broadcast Frame Data". 
Create four rigid body, each one for arm section and start to create it from shoulder. 
On your pc:
Starting to connect your pc to baxter network by use the command ". baxter.sh". Select the directory /ros_ws/src/mocap_otitrack/config. Lunch the ros node of mocap . Here you can find all the detailed passage [EmaroLab Motion Capture(https://github.com/EmaroLab/docs/wiki/Motion-Capture-Instructions-%28Optitrack-Motive%29)].
In Matlab use the command rosinit(IP adress) to connect to baxter network and setup the workspace properly. Then launch the script.
The function for neural network must have the dataset available in work space.

# Increase dataset
For a better knowledge of human movement for baxter, we suggest to increase the dataset of human movement and baxter posture.
We have used only 23 movements for baxter. 
For doing this:
1. Record baxter movements with rethink command "rosrun baxter_examples joint_recorder.py -f <nome file>.txt
2. In a New terminal launch the interface by "rosrun baxter_interface joint_trajectory_action_serve.py --mode velocity
3. For replaying the movement: "rosrun baxter_examples Joint_trajectory_file_playback.py -f <nomefile>.txt
4.launch mocap node 
5.launch sync_node.cpp in a new terminal with command "rosrun sync sync_node".
6. export the dataset on MATLAB workspace and transform the txt file in matrix of value with import tools. 
7.Use Preprocessing_neural.m for setting  shoulder as referred frame for each arm section.
8.Training the Neural Network with human_coordinate as input and Joint position value of baxter as output. 
  The neural network script is inside the folder Neural Network (for more information see report attached to this github     project)
 9. Use Robot_Teleoperation.m in order to see the result!
 
 # Credit
 Author: Luca Morando, Valetina Pericu
 
 # Lincense 
 Gpl


