#include <Adafruit_CircuitPlayground.h>
#include "SessionManager.h"

SessionManager sessionManager;

void setup() {
    Serial.begin(9600);
    CircuitPlayground.begin();
    sessionManager = SessionManager();
}

void loop() {
    sessionManager.updateBoard();
}