#pragma once

typedef enum {
  PASSIVE_COOLING =0u,
  HI_ACTIVE_COOLING =1u,
  MED_ACTIVE_COOLING =2u,
  COOLING_MAX =3u
} CoolingType;

typedef enum {
  NORMAL =0u,
  TOO_LOW =1u,
  TOO_HIGH =2u,
  BREACHTYPE_MAX =3u,
} BreachType;

typedef struct {
  int lowerLimit;
  int upperLimit;
} TempLimit;


BreachType inferBreach(double value, double lowerLimit, double upperLimit);
BreachType classifyTemperatureBreach(CoolingType coolingType, double temperatureInC);

typedef enum {
  TO_CONTROLLER,
  TO_EMAIL
} AlertTarget;

typedef struct {
  CoolingType coolingType;
  char brand[48];
} BatteryCharacter;

void checkAndAlert(
  AlertTarget alertTarget, BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
