#include "mgos.h"
#include "mgos_m5stack.h"
#include "AXP192.h"
#include "RTC.h"

AXP192* axp = nullptr;
RTC* rtc = nullptr;

bool mgos_m5stack_init(void) {
  axp = new AXP192();
  axp->begin();
  if(mgos_sys_config_get_m5_bus_power()){
    axp->SetBusPowerMode(1);
  }else{
    axp->SetBusPowerMode(0);
  }
  rtc = new RTC();
  RTC_TimeTypeDef timeobj;
  rtc->GetTime(& timeobj);
  LOG(LL_INFO, ("RTC Hours:%d Minutes: %d Seconds: %d", timeobj.Hours, timeobj.Minutes, timeobj.Seconds));
  return true;
}
