#include "TrialController_Initial.h"

#include "../TrialController.h"

void TrialController_Initial::configure(const mc_rtc::Configuration & config)
{
}

void TrialController_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<TrialController &>(ctl_);
}

bool TrialController_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<TrialController &>(ctl_);
  output("OK");
  return true;
}

void TrialController_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<TrialController &>(ctl_);
}

EXPORT_SINGLE_STATE("TrialController_Initial", TrialController_Initial)
