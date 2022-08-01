#include "TrialController.h"

TrialController::TrialController(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config)
{
  #if MC_RTC_VERSION_MAJOR < 2
  datastore().make_call("KinematicAnchorFrame::" + robot().name(), [this](const mc_rbdyn::Robot & robot) {
    return sva::interpolate(robot.surfacePose("LeftFoot"), robot.surfacePose("RightFoot"), 0.5);
  });
  #else
    datastore().make_call("KinematicAnchorFrame::" + robot().name(), [this](const mc_rbdyn::Robot & robot) {
      return sva::interpolate(robot.frame("LeftFoot").position(), robot.frame("RightFoot").position(), 0.5);
    });
  #endif
  mc_rtc::log::success("TrialController init done ");
}

bool TrialController::run()
{
  return mc_control::fsm::Controller::run();
}

void TrialController::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::fsm::Controller::reset(reset_data);
}
