#pragma once 

// класс для защиты тумблера от дребезга
class DebounceButton{
    public:
        DebounceButton(int pin){
            _switchPin = pin;
            pinMode(_switchPin, INPUT_PULLUP);
            _lastDebounceTime = 0;
            _switchState = false;
            _lastSwitchState = false;
        }
        bool getSwitchState(){
            bool reading = !digitalRead(_switchPin);
            if (reading != _lastSwitchState){
                _lastDebounceTime = millis();
            }
            if ((millis() - _lastDebounceTime) > _debounceDelay){
                if (reading != _switchState){
                    _switchState = reading;
                }
            }
            _lastSwitchState = reading;
            return _switchState;
        }

    private:
    int _switchPin;
    int _debounceDelay = 50;
    bool _lastSwitchState;
    bool _lastDebounceTime;
    bool _switchState;
};