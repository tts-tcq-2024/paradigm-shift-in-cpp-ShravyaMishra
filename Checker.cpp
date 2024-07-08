#include <iostream>
#include <unordered_map>
#include <string>
#include <cassert>

struct MeasureLimits {
    float lowerLimit;
    float upperLimit;
};

std::unordered_map<std::string, MeasureLimits> measureLimits = {
    {"Temperature", {0, 45}},
    {"State of Charge", {20, 80}},
    {"Charge Rate", {0, 0.8f}}
};

bool batteryIsOk(float temperature, float soc, float chargeRate);

std::unordered_map<std::string, bool> checkMeasure(const std::string& measureName, float measureValue) {
    std::unordered_map<std::string, bool> results;
    bool status = true;
    float lowerLimit = measureLimits[measureName].lowerLimit;
    float upperLimit = measureLimits[measureName].upperLimit;

    if (measureValue < lowerLimit) {
        std::cout << measureName << " is too low!" << std::endl;
        status = false;
    } else if (measureValue > upperLimit) {
        std::cout << measureName << " is too high!" << std::endl;
        status = false;
    }

    results["status"] = status;
    return results;
}

bool batteryIsOk(float temperature, float soc, float chargeRate) {
    auto tempResults = checkMeasure("Temperature", temperature);
    auto socResults = checkMeasure("State of Charge", soc);
    auto chargeResults = checkMeasure("Charge Rate", chargeRate);
    return tempResults["status"] && socResults["status"] && chargeResults["status"];
}

int main() {
    // Test cases
    assert(batteryIsOk(25, 70, 0.7f) == true);
    assert(batteryIsOk(50, 85, 0.0f) == false);
    assert(batteryIsOk(-1, 70, 0.7f) == false);
    assert(batteryIsOk(25, 10, 0.7f) == false);
    assert(batteryIsOk(25, 70, 0.9f) == false);
    std::cout << "Some more tests needed" << std::endl;
    return 0;
}
