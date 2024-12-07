#ifndef ENVIRONMENTMANAGER_H
#define ENVIRONMENTMANAGER_H

#include "HeartRateManager.h"

class EnvironmentManager {
public:
    EnvironmentManager();
    void updateEnvironment();
    float getTemperature();
    float getLightIntensity();
    float getSoundIntensity();
    float getHeartRate();

private:
    float _temperature;
    float _lightIntensity;
    float _soundIntensity;
    float _heartRate;
    HeartRateManager _heartRateManager;
};

#endif