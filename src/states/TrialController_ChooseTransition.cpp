#include "TrialController_ChooseTransition.h"

#include <mc_control/fsm/Controller.h>

#include <mc_rtc/gui/Button.h>
#include <mc_rtc/version.h>

void ChooseTransition::configure(const mc_rtc::Configuration & config)
{
  config("category", category_);
  config("actions", actions_);
}

void ChooseTransition::start(mc_control::fsm::Controller & ctl)
{
#if MC_RTC_VERSION_MAJOR < 2
  auto & gui = *ctl.gui();
#else
  auto & gui = ctl.gui();
#endif
  output("");
  using namespace mc_rtc::gui;
  for(const auto & action : actions_)
  {
    gui.addElement(category_, Button(action.first, [this, action]() {
                     mc_rtc::log::info("[{}] Action {} chosen, triggering output {}", name(), action.first,
                                       action.second);
                     output(action.second);
                   }));
  }
}

bool ChooseTransition::run(mc_control::fsm::Controller &)
{
  if(output().empty())
  {
    return false;
  }
  return true;
}

void ChooseTransition::teardown(mc_control::fsm::Controller & ctl)
{
#if MC_RTC_VERSION_MAJOR < 2
  auto & gui = *ctl.gui();
#else
  auto & gui = ctl.gui();
#endif
  for(const auto & action : actions_)
  {
    gui.removeElement(category_, action.first);
  }
}

EXPORT_SINGLE_STATE("TrialController_ChooseTransition", ChooseTransition)
