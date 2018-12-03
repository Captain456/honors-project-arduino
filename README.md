# honors-project-arduino

This repository is part of an Honors Project for Fall 2018, created by Christopher Gibbs and advised by Dr. Holly Yanco. This contains code for an Arduino Uno wired with a single servo motor. ROS libraries are used to subscribe to a std_msgs/Float32 message topic. When a message is received from the topic, it will write the data value to the servo motor, turning it to the desired position. This assumes that the servo motor has a 180-degree radius of motion and that the motor is plugged into pin 9. An external power supply may be needed for the Arduino Uno. For more information on wiring a servo to the Arduino Uno, please refer to this tutorial: https://www.arduino.cc/en/Tutorial/Sweep.

# How To Run

1) Clone this repository and copy the rosserial_arduino_servo_orientation_subscriber.ino file into an Arduino IDE sketchbook directory.
2) Plug in an Arduino Uno that is properly set up to control a servo (see above). Take note of what serial port the Arduino is connected to. For example, it could be "/dev/ttyUSB0" or "/dev/ttyACM0". This will be used in step 6.
3) Use the Arduino IDE to upload the program to the Uno board.
4) Make sure that the host machine has ROS and the Rosserial package installed.
5) Open up the terminal and run 'roscore' to start the ROS master node.
6) In a separate terminal, run 'rosrun rosserial_python serial_node.py <serial port>', which will start a serial node. This will pass along any std_msgs/Float32 messages that are published to the "/orientation" topic.
