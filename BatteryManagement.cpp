#include "BatteryManagement.h"

BatteryManagement::BatteryManagement(const ParameterCheck& tempCheck,
                                                 const ParameterCheck& socCheck,
                                                 const ParameterCheck& chargeCheck)
    : temperatureCheck(tempCheck), socCheck(socCheck), chargeRateCheck(chargeCheck) {}

bool BatteryManagement::batteryIsOk(float temperature, float soc, float chargeRate) const {
    return temperatureCheck.check(temperature) &&
           socCheck.check(soc) &&
           chargeRateCheck.check(chargeRate);
}
