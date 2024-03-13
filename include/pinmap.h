#pragma once

// Потенциометры к A0 A1
#define PIN_ANGLE_HIP A0 // ДУП бедренного шарнира
#define PIN_ANGLE_KNEE A1 // ДУП коленного шарнира

#define PIN_SWITCH_LEFT_UP 2 // Левый тумблер ПУ (пульт управления), верхнее положение
#define PIN_SWITCH_LEFT_DOWN 13 // Левый тумблер ПУ (пульт управления), нижнее положение
#define PIN_SWITCH_RIGHT_UP 4 // Правый тумблер ПУ (пульт управления), верхнее положение
#define PIN_SWITCH_RIGHT_DOWN 3 //Правый тумблер ПУ (пульт управления), нижнее положение

#define PIN_CYLIN_HIP -1 // Пин цилиндра бедра
#define PIN_CYLIN_KNEE -1 // Пин илиндра колена

void initPins(){
  // Инициализируем пины ввода-вывода
  pinMode(PIN_CYLIN_HIP, OUTPUT); // Инициализация пина цилиндра бедра
  pinMode(PIN_CYLIN_KNEE, OUTPUT); // Инициализация пина цилиндра бедра
}