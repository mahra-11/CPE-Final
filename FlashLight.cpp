#include "FlashLight.h"
#include <Adafruit_CircuitPlayground.h>

// Constructor
FlashLight::FlashLight() : _lastUpdate(0), _state(0) {}

void FlashLight::clear() {
    CircuitPlayground.clearPixels();
}

void FlashLight::set(int idx, int r, int g, int b) {
    CircuitPlayground.setPixelColor(idx, r, g, b);
}

void FlashLight::optimal() {
    // Ensure no flashing occurs during optimal mode
    clear();
    for (int i = 0; i < 10; i++) {
        set(i, 0, 30, 0);  // Dim green for optimal
    }
}

void FlashLight::subOptimal(const int lights[10]) {
    unsigned long currentMillis = millis();

    // Alternate between flashing red and displaying suboptimal indicators
    if (currentMillis - _lastUpdate >= FLASH_INTERVAL) {
        _lastUpdate = currentMillis;

        // Flashing logic
        if (_state == 0) {
            clear();
            for (int i = 0; i < 10; i++) {
                set(i, 255, 0, 0);  // Red for flashing
            }
            _state = 1; // Switch to suboptimal display next
        } else {
            clear();
            for (int i = 0; i < 10; i++) {
                if (lights[i] == -1) {
                    set(i, 0, 0, 255);  // Blue for critically low
                } else if (lights[i] == 1) {
                    set(i, 255, 0, 0);  // Red for critically high
                }
            }
            _state = 0; // Switch back to flashing next
        }
    }
}