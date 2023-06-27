#include "typewise-alert.h"
#include <stdio.h>

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  BreachType retval = NORMAL;
  if(value < lowerLimit) {
    retval = TOO_LOW;
  }
  if(value > upperLimit) {
    retval = TOO_HIGH;
  }
  return retval;
}

BreachType classifyTemperatureBreach(
    CoolingType coolingType, double temperatureInC) {

BreachType retval = TOO_HIGH;
TempLimit limit_Table[COOLING_MAX];
limit_Table[PASSIVE_COOLING].lowerLimit =0;
limit_Table[PASSIVE_COOLING].upperLimit =35;
limit_Table[HI_ACTIVE_COOLING].lowerLimit =0;
limit_Table[HI_ACTIVE_COOLING].upperLimit =45;
limit_Table[MED_ACTIVE_COOLING].lowerLimit =0;
limit_Table[MED_ACTIVE_COOLING].upperLimit =40;

if (COOLING_MAX > coolingType)
  retval = inferBreach(temperatureInC,limit_Table [coolingType].lowerLimit, limit_Table [coolingType].upperLimit);
else
  retval = TOO_HIGH; //assume worst case

return retval;

}

void checkAndAlert(
    AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC) {

  BreachType breachType = classifyTemperatureBreach(
    batteryChar.coolingType, temperatureInC
  );

  if(TO_CONTROLLER == alertTarget)
  {
    sendToController(breachType);
  }
  else
  {
    sendToEmail(breachType);
  }

}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  printf("%x : %x\n", header, breachType);
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
if(TOO_LOW == breachType)
{
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too low\n");
}
else if (TOO_HIGH == breachType)
{
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is too high\n");
}
else
{
  //do nothing
}

}

