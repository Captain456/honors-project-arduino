#include <ros.h>
#include <Servo.h>
#include <std_msgs/Float32.h>

Servo servoMotor;
ros::NodeHandle nh;
float previousAngle = 90;

/*
 * The callback function when a Float32 message is received
 */
void messageCallback(const std_msgs::Float32& ori_msg)
{
  // Get the bearing angle from the message
  float bearing_angle = ori_msg.data;

  // Enforce the rotation limits of the servo motor
  if (bearing_angle < 0)
  {
    bearing_angle = 0;
  }
  else if (bearing_angle > 180)
  {
    bearing_angle = 180;
  }

  // Turn the motor if the new angle is 4+ degrees away from the prev. angle
  if (abs(previousAngle - bearing_angle) >= 4)
  {
    servoMotor.write((int) bearing_angle);
    delay(15);
    previousAngle = bearing_angle;
  }
}

ros::Subscriber<std_msgs::Float32> sub("orientation", &messageCallback);

/*
 * Setup code that will run once when the reset button is pressed
 */
void setup() {
  // Attach the Servo object to the servo motor on pin 9
  servoMotor.attach(9);
  // Set up the ROS node and start the subscriber
  nh.initNode();
  nh.subscribe(sub);
}

/*
 * Main code that will be run repeatedly
 */
void loop() {
  // Constantly spin to receive new messages
  nh.spinOnce();
  delay(15);
}
