# honors-project-arduino

This repository is part of an Honors Project for Fall 2018, created by Christopher Gibbs and advised by Dr. Holly Yanco. This contains code for an Arduino Uno wired with a single servo motor. ROS libraries are used to subscribe to a std_msgs/Float32 message topic. When a message is received from the topic, it will write the data value to the servo motor, turning it to the desired position. This assumes that the servo motor has a 180-degree radius of motion and that the motor is plugged into port 9. An external power supply may be needed for the Arduino Uno.
