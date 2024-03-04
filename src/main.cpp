#include "Arduino.h"
#include "DFilters.h"

#include "pinmap.h"


ERA_filter<float> potFilter(0.1); // Фильтр
char value;
// Тумблеры
bool _switchState = 0;
bool switchState12 = 0;
bool switchState21 = 0;
bool switchState22 = 0;
// Тумблеры ласт состояние

bool lastSwitchState12 = 0;
bool lastSwitchState21 = 0;
bool lastSwitchState22 = 0;
// Время дребезга
const int DEBOUNCE_DELAY = 50;
// Время последнего изменения состояния тумблиров
unsigned long _lastDebounceTime = 0;
unsigned long lastDebounceTime12 = 0;
unsigned long lastDebounceTime21 = 0;
unsigned long lastDebounceTime22 = 0;

// Пример функции !!!!!!!!!!!!!!!!!!
int getAngleHip(){
  static ERA_filter<float> _era(0.1); // Фильтр
  return _era.filtered(analogRead(PIN_ANGLE_HIP));
}



void setup(){
  Serial.begin(9600); 
  initPins();
}

// Функция опроса тумблера
bool getSwitchState(){
  bool _reading = !digitalRead(SWITCH_PIN11);
  static bool _lastSwitchState = 0;

  if (_reading != _lastSwitchState){
    _lastDebounceTime = millis();
  }

  if ((millis() - _lastDebounceTime) > DEBOUNCE_DELAY){
    if (_reading != _switchState){
      _switchState = _reading;
    }
  }

  _lastSwitchState = _reading;
}


void loop(){
  // чтение значения с потинциометра и фильтрация
  int potValue1 = potFilter.filtered(analogRead(PIN_ANGLE_HIP));
  int potValue2 = potFilter.filtered(analogRead(POT2_PIN));
  // защита от дребезга
  
  bool reading12 = !digitalRead(SWITCH_PIN12);
  bool reading21 = !digitalRead(SWITCH_PIN21);
  bool reading22 = !digitalRead(SWITCH_PIN22);

  if (reading12 != lastSwitchState12){
    lastDebounceTime12 = millis();
  }

  

  if ((millis() - lastDebounceTime12) > DEBOUNCE_DELAY)
  {
    if (reading12 != switchState12)
    {
      switchState12 = reading12;
    }
  }
if (reading21 != lastSwitchState21) // 2 тумблер
  {
    lastDebounceTime21 = millis();
  }

  if (reading22 != lastSwitchState22)
  {
    lastDebounceTime22 = millis();
  }

  if ((millis() - lastDebounceTime21) > DEBOUNCE_DELAY)
  {
    if (reading21 != switchState21)
    {
      switchState21 = reading21;
    }
  }

  if ((millis() - lastDebounceTime22) > DEBOUNCE_DELAY)
  {
    if (reading22 != switchState22)
    {
      switchState22 = reading22;
    }
  }

  lastSwitchState12 = reading12;
  lastSwitchState21 = reading21;
  lastSwitchState22 = reading22;
  // Включение циллиндров от тумблеров
  digitalWrite(CYLINDER_PIN1, _switchState);
  digitalWrite(CYLINDER_PIN2, switchState12);

  // Вывод значения фильтрованого в порт

  Serial.print(_switchState);
  Serial.print(",");
  Serial.print(switchState12);
  Serial.print(",");
  Serial.print(switchState21);
  Serial.print(",");
  Serial.print(switchState22);
  Serial.print(",");
  Serial.print(potValue1);
  Serial.print(",");
  Serial.println(potValue2);
}
