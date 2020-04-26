/*
 * Copyright 2016-2019 CNRS-UM LIRMM, CNRS-AIST JRL
 */

#pragma once

#include <mc_control/mc_global_controller.h>

#include <ros/ros.h>
#include <visualization_msgs/MarkerArray.h>

#include <thread>

namespace mc_naoqi
{
struct ContactForcePublisher
{
public:
  ContactForcePublisher(ros::NodeHandle & nh, mc_control::MCGlobalController & gc);

  void stop();

  void update();

private:
  ros::NodeHandle & nh;
  mc_control::MCGlobalController & gc;
  bool running = true;
  std::thread update_th;

  std::map<std::string, ros::Publisher> force_markers_publisher;
  std::map<std::string, visualization_msgs::MarkerArray> force_markers;
  std::map<std::string, ros::Publisher> force_norm_markers_publisher;
  std::map<std::string, visualization_msgs::MarkerArray> force_norm_markers;

  bool update_ready = false;
  unsigned int rate = 0;
  unsigned int iter = 0;
  unsigned int skip = 0;
};
} // namespace mc_naoqi
