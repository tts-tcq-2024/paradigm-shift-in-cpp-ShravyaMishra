#ifndef BATTERY_MANAGEMENT_SYSTEM_H
#define BATTERY_MANAGEMENT_SYSTEM_H

#include "ParameterCheck.h"

class BatteryManagement {
    // Member variables are now references to the respective ParameterCheck objects
    const ParameterCheck& temperatureCheck;
    const ParameterCheck& socCheck;
    const ParameterCheck& chargeRateCheck;

public:
    // Constructor now correctly initializes the member references
    BatteryManagement(const ParameterCheck& tempCheck,
                            const ParameterCheck& socCheck,
                            const ParameterCheck& chargeCheck);

    bool batteryIsOk(float temperature, float soc, float chargeRate) const;
};

#endif // BATTERY_MANAGEMENT_SYSTEM_H
