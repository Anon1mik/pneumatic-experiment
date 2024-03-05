#pragma once 
#include "Arduino.h"
class SwitchLibrary {
public:
    SwitchLibrary(int pin, unsigned long debounceDelay = 50);
    bool getSwitchState();

private:
    int _switchPin;
    unsigned long _debounceDelay;
    unsigned long _lastDebounceTime;
    bool _switchState;
    bool _lastSwitchState;
    bool _readSwitch();
};

SwitchLibrary::SwitchLibrary(int pin, unsigned long debounceDelay) {
    _switchPin = pin;
    pinMode(_switchPin, INPUT_PULLUP);
    _debounceDelay = debounceDelay;
    _lastDebounceTime = 0;
    _switchState = false;
    _lastSwitchState = false;
}

bool SwitchLibrary::_readSwitch() {
    return !digitalRead(_switchPin);
}

bool SwitchLibrary::getSwitchState() {
    bool reading = _readSwitch();
    if (reading != _lastSwitchState) {
        _lastDebounceTime = millis();
    }
    if ((millis() - _lastDebounceTime) > _debounceDelay) {
        if (reading != _switchState) {
            _switchState = reading;
        }
    }
    _lastSwitchState = reading;
    return _switchState;
}

