#include "SessionManager.h"
#include <Arduino.h>

// Thresholds for light, temperature, and sound
const float TEMP_LOW = 20.0;
const float TEMP_HIGH = 25.0;
const float LIGHT_LOW = 300.0;
const float LIGHT_HIGH = 700.0;
const float SOUND_LOW = 40.0;
const float SOUND_HIGH = 60.0;

SessionManager::SessionManager() {
    _environmentManager = EnvironmentManager();
    _flashLight = FlashLight();
    for (int i = 0; i < 10; i++) {
        _leds[i] = 0;
    }
}

// Helper function to update LED state
void SessionManager::updateLED(int idx, float value, float lowThreshold, float highThreshold) {
    if (value < lowThreshold) {
        _leds[idx] = -1;  // Low
    } else if (value > highThreshold) {
        _leds[idx] = 1;   // High
    } else {
        _leds[idx] = 0;   // Optimal
    }
}

void SessionManager::updateBoard() {
    // Update environmental readings
    _environmentManager.updateEnvironment();

    // Get sensor values
    float temperature = _environmentManager.getTemperature();
    float lightIntensity = _environmentManager.getLightIntensity();
    float soundIntensity = _environmentManager.getSoundIntensity();
    float heartRate = _environmentManager.getHeartRate();

    // Update LED states based on sensor thresholds
    updateLED(0, lightIntensity, LIGHT_LOW, LIGHT_HIGH);
    updateLED(1, lightIntensity, LIGHT_LOW, LIGHT_HIGH);
    updateLED(3, temperature, TEMP_LOW, TEMP_HIGH);
    updateLED(4, temperature, TEMP_LOW, TEMP_HIGH);
    updateLED(5, soundIntensity, SOUND_LOW, SOUND_HIGH);
    updateLED(6, soundIntensity, SOUND_LOW, SOUND_HIGH);

    // Check if any of the LED states are suboptimal
    bool suboptimal = false;
    for (int i = 0; i < 10; i++) {
        if (_leds[i] != 0) {
            suboptimal = true;
            break;
        }
    }

    // Update the LED lights based on suboptimal conditions
    if (suboptimal) {
        _flashLight.subOptimal(_leds);
    } else {
        _flashLight.optimal();
    }

    // Print board status
    printBoardStatus(temperature, lightIntensity, soundIntensity, heartRate);
}

// Print the sensor values in a tabular format to the serial monitor
void SessionManager::printBoardStatus(float& temperature, float& lightIntensity, float& soundIntensity, float& heartRate) {
    // Clear the Serial monitor
    Serial.flush();

    // Print a formatted table header
    Serial.println("----------------------------------------------------------------------");
    Serial.println("|  Temperature  |  Light Intensity  |  Sound Intensity  |  Heart Rate  |");
    Serial.println("----------------------------------------------------------------------");

    // Print the sensor readings in a tabular format
    Serial.print("|   ");
    Serial.print(temperature, 2);  // Print temperature with 2 decimal places
    Serial.print("   |    ");
    Serial.print(lightIntensity, 2);  // Print light intensity with 2 decimal places
    Serial.print("         |       ");
    Serial.print(soundIntensity, 2);  // Print sound intensity with 2 decimal places
    Serial.print("       |    ");
    Serial.print(heartRate, 2);  // Print heart rate with 2 decimal places
    Serial.println("     |");

    Serial.println("----------------------------------------------------------------------");
}
