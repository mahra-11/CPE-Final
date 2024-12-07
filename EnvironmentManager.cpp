#include <Adafruit_CircuitPlayground.h>
#include "EnvironmentManager.h"

EnvironmentManager::EnvironmentManager() :
    _temperature(0.0), _lightIntensity(0.0), _soundIntensity(0.0), _heartRate(0.0),
    _heartRateManager(HEART_RATE_PIN) 
    {}

void EnvironmentManager::updateEnvironment() {
    _temperature = CircuitPlayground.temperature();
    _lightIntensity = CircuitPlayground.lightSensor();
    _soundIntensity = CircuitPlayground.mic.soundPressureLevel(10);

    // Update the heart rate data
    _heartRateManager.updateHeartRate();
    _heartRate = _heartRateManager.getHeartRate();
}

float EnvironmentManager::getTemperature() {
    return _temperature;
}

float EnvironmentManager::getLightIntensity() {
    return _lightIntensity;
}

float EnvironmentManager::getSoundIntensity() {
    return _soundIntensity;
}

float EnvironmentManager::getHeartRate() {
    return _heartRate;
}