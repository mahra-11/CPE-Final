#ifndef HEART_RATEMANAGER_H
#define HEART_RATEMANAGER_H

#include <Adafruit_CircuitPlayground.h>

const int HEART_RATE_PIN = 10;
const int PEAK_THRESHOLD = 512;
const int BUFFER_SIZE = 500;

class HeartRateManager {
public:
    HeartRateManager(int pin);
    void updateHeartRate();                  // Method to update the heart rate data
    float getHeartRate();                    // Method to get the calculated heart rate
    void printHeartRate();                   // Method to print heart rate to serial monitor

private:
    int _pin;                               // Pin connected to the heart rate sensor
    long _currentIndex;
    float _buffer[BUFFER_SIZE];             // Buffer to store the sensor readings
    unsigned long _lastPeakTime;            // Last time a peak was detected
    float _heartRate;                       // Calculated heart rate (BPM)

    bool isPeak(int value);                 // Method to check if the current reading is a peak
    void detectPeak();                      // Method to detect peaks and calculate BPM
};

#endif