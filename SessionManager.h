#ifndef SESSION_MANAGER_H
#define SESSION_MANAGER_H

#include "FlashLight.h"
#include "EnvironmentManager.h"

class SessionManager {
public:
    SessionManager();
    void updateBoard();
    void printBoardStatus(float&, float&, float&, float&);

private:
    EnvironmentManager _environmentManager;
    FlashLight _flashLight;
    int _leds[10];

    void updateLED(int idx, float value, float lowThreshold, float highThreshold);
};

#endif