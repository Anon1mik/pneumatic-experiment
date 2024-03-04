#include "Arduino.h"
#include "DFilters.h"
// Потенцометры к A0 A1
#define POT1_PIN A0
#define POT2_PIN A1

#define SWITCH_PIN11 3 // Тумблер первый
#define SWITCH_PIN12 4

#define SWITCH_PIN21 13 // Тумблер второй
#define SWITCH_PIN22 2

#define CYLINDER_PIN1 -1 // Подключение цилиндры
#define CYLINDER_PIN2 -1

ERA_filter<float> potFilter(0.1); // Фильтр
char value;
// Тумблеры
bool switchState11 = 0;
bool switchState12 = 0;
bool switchState21 = 0;
bool switchState22 = 0;
// Тумблеры ласт состояние
bool lastSwitchState11 = 0;
bool lastSwitchState12 = 0;
bool lastSwitchState21 = 0;
bool lastSwitchState22 = 0;
// Время дребезга
unsigned long debounceDelay = 50;
// Время последнего изменения состояния тумблиров
unsigned long lastDebounceTime11 = 0;
unsigned long lastDebounceTime12 = 0;
unsigned long lastDebounceTime21 = 0;
unsigned long lastDebounceTime22 = 0;

void setup()
{

  Serial.begin(9600);

  // Выводы циллиндров
  pinMode(CYLINDER_PIN1, OUTPUT);
  pinMode(CYLINDER_PIN2, OUTPUT);

  // Подтягивающие резисторы на пины
  pinMode(SWITCH_PIN11, INPUT_PULLUP);
  pinMode(SWITCH_PIN12, INPUT_PULLUP);
  pinMode(SWITCH_PIN21, INPUT_PULLUP);
  pinMode(SWITCH_PIN22, INPUT_PULLUP);
}

void loop()
{
  // чтение значения с потинциометра и фильтрация
  int potValue1 = potFilter.filtered(analogRead(POT1_PIN));
  int potValue2 = potFilter.filtered(analogRead(POT2_PIN));
  // защита от дребезга
  bool reading11 = !digitalRead(SWITCH_PIN11);
  bool reading12 = !digitalRead(SWITCH_PIN12);
  bool reading21 = !digitalRead(SWITCH_PIN21);
  bool reading22 = !digitalRead(SWITCH_PIN22);
  if (reading11 != lastSwitchState11)
  {
    lastDebounceTime11 = millis();
  }

  if (reading12 != lastSwitchState12)
  {
    lastDebounceTime12 = millis();
  }

  if ((millis() - lastDebounceTime11) > debounceDelay)
  {
    if (reading11 != switchState11)
    {
      switchState11 = reading11;
    }
  }

  if ((millis() - lastDebounceTime12) > debounceDelay)
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

  if ((millis() - lastDebounceTime21) > debounceDelay)
  {
    if (reading21 != switchState21)
    {
      switchState21 = reading21;
    }
  }

  if ((millis() - lastDebounceTime22) > debounceDelay)
  {
    if (reading22 != switchState22)
    {
      switchState22 = reading22;
    }
  }
  lastSwitchState11 = reading11;
  lastSwitchState12 = reading12;
  lastSwitchState21 = reading21;
  lastSwitchState22 = reading22;
  // Включение циллиндров от тумблеров
  digitalWrite(CYLINDER_PIN1, switchState11);
  digitalWrite(CYLINDER_PIN2, switchState12);

  // Вывод значения фильтрованого в порт

  Serial.print(switchState11);
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
