#pragma once 

#include "Arduino.h"

// Класс для работы с тумблером (с защитой от дребезга)
class DebounceButton{
    public:
        // Передаем только номер пина 
        DebounceButton(int pin){
            _pin = pin;
            pinMode(_pin, INPUT_PULLUP);
        }

        // Передаем номер пина и задержку между срабатываниями
        DebounceButton(int pin, int delay){
            _pin = pin;
            _debounce_delay = delay;
            pinMode(_pin, INPUT_PULLUP);
        }

        // Возвращает состояние кнопки
        bool getSwitchState(){
            // Опрашиваем пин
            bool _new_state = !digitalRead(_pin);
            // Если значение поменялось, запоминаем время
            if (_new_state != _last_state) _debounce_time = millis();

            // Если прошло больше времени, чем задано
            if ((millis() - _debounce_time) > _debounce_delay){
                // Если значение изменилось, запоминаем его
                if (_new_state != _switch_state) _switch_state = _new_state;
            }
            // Запоминаем предыдущее значение
            _last_state = _new_state;
            
            // Возвращаем состояние кнопки
            return _switch_state;
        }

    private:
    int _pin;                       // Контакт подключения кнопки
    int _debounce_delay = 50;       // Минимальное время между срабатываниями
    bool _switch_state = LOW;       // Текущее состояние кнопки
    bool _last_state = LOW;         // Предыдущее состояние кнопки
    bool _debounce_time = 0;   // Время между срабатываниями кнопки
};