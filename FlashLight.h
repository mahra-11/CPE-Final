#ifndef FLASHLIGHT_H
#define FLASHLIGHT_H

class FlashLight {
public:
    FlashLight();
    void clear();
    void set(int idx, int r, int g, int b);
    void optimal();
    void subOptimal(const int lights[10]);
private:
    unsigned long _lastUpdate;
    int _state;
    static const int FLASH_INTERVAL = 1000;
};

#endif