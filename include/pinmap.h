#pragma once

// Потенциометры к A0 A1
#define PIN_ANGLE_HIP A0 // <-------------------------------
#define POT2_PIN A1

#define SWITCH_PIN11 3 // Тумблер первый
#define SWITCH_PIN12 4

#define SWITCH_PIN21 13 // Тумблер второй
#define SWITCH_PIN22 2

#define CYLINDER_PIN1 -1 // Подключение цилиндры
#define CYLINDER_PIN2 -1

void initPins(){
  // ПЕРЕНЕСТИ В ПИНМАМ
  // Выводы циллиндров
  pinMode(CYLINDER_PIN1, OUTPUT);
  pinMode(CYLINDER_PIN2, OUTPUT);

  // Подтягивающие резисторы на пины
  pinMode(SWITCH_PIN11, INPUT_PULLUP);
  pinMode(SWITCH_PIN12, INPUT_PULLUP);
  pinMode(SWITCH_PIN21, INPUT_PULLUP);
  pinMode(SWITCH_PIN22, INPUT_PULLUP);
}