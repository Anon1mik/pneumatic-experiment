#pragma once

// Потенциометры к A0 A1
#define PIN_ANGLE_HIP A0 
#define PIN_ANGLE_KNEE A1

#define PIN_SWITCH11 2 // Тумблер первый
#define PIN_SWITCH12 13
#define PIN_SWITCH21 4 // Тумблер второй
#define PIN_SWITCH22 3

#define CYLINDER_PIN1 -1 // Подключение цилиндров
#define CYLINDER_PIN2 -1

void initPins(){
  // Выводы циллиндров
  pinMode(CYLINDER_PIN1, OUTPUT);
  pinMode(CYLINDER_PIN2, OUTPUT);
}