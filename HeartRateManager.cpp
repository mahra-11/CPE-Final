#include "HeartRateManager.h"
#include <Arduino.h>

// Constructor to initialize pin and variables
HeartRateManager::HeartRateManager(int pin)
    : _pin(pin), _currentIndex(0), _lastPeakTime(0), _heartRate(0.0) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        _buffer[i] = 0.0;
    }
}

// Update the heart rate by reading the sensor and checking for peaks
void HeartRateManager::updateHeartRate() {
    int rawValue = analogRead(_pin);

    // Store the new reading in the buffer
    _buffer[_currentIndex % BUFFER_SIZE] = rawValue;
    _currentIndex++;

    // Detect if the current value is a peak and update heart rate accordingly
    detectPeak();
}

// Detect peaks in the signal and calculate BPM based on peak intervals
void HeartRateManager::detectPeak() {
    int currentValue = _buffer[_currentIndex % BUFFER_SIZE];
    
    // Check if the current reading is a peak
    if (isPeak(currentValue)) {
        unsigned long currentTime = millis();  // Get the current time

        if (_lastPeakTime > 0) {
            // Calculate BPM as the inverse of the time between peaks
            float timeBetweenPeaks = (currentTime - _lastPeakTime) / 1000.0;  // Time in seconds
            _heartRate = 60.0 / timeBetweenPeaks;  // Convert to BPM
        }

        // Update the time of the last detected peak
        _lastPeakTime = currentTime;
    }
}

// Check if the current value is a peak by comparing it to neighbors
bool HeartRateManager::isPeak(int value) {
    const int WINDOW_SIZE = 50;
    for (int i = 1; i <= WINDOW_SIZE; i++) {
        int prevValue = _buffer[(_currentIndex - i + BUFFER_SIZE) % BUFFER_SIZE];
        int nextValue = _buffer[(_currentIndex + i) % BUFFER_SIZE];
        if (value <= prevValue || value <= nextValue) {
            return false;
        }
    }
    return value >= PEAK_THRESHOLD;
}

// Return the current heart rate in BPM
float HeartRateManager::getHeartRate() {
    return _heartRate;
}