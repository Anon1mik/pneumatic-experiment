#pragma once

#define PIN_ANGLE_HIP   A0 // ДУП бедренного шарнира
#define PIN_ANGLE_KNEE  A1 // ДУП коленного шарнира

#define PIN_SWITCH_LEFT_UP    2   // Левый тумблер ПУ (пульт управления), верхнее положение
#define PIN_SWITCH_LEFT_DOWN  13  // Левый тумблер ПУ, нижнее положение
#define PIN_SWITCH_RIGHT_UP   3   // Правый тумблер ПУ, верхнее положение
#define PIN_SWITCH_RIGHT_DOWN 4   // Правый тумблер ПУ, нижнее положение

#define PIN_CYLIN_HIP_UP 12   // Верхний пин цилиндра бедренного привода L2 тут получре распиши
#define PIN_CYLIN_HIP_DOWN 11   // Нижний пин цилиндра бедренного привода L1
#define PIN_CYLIN_KNEE_UP 10   // Верхний пин цилиндра коленного привода K2
#define PIN_CYLIN_KNEE_DOWN 9   // Нижний пин цилиндра коленного привода K1

#define PIN_BUTTON_MODE_SWITCH A3 // Кнопка переключения состояния 

// Настраиваем пины ввода-вывода
void setupPins(){
  pinMode(PIN_CYLIN_KNEE_UP, OUTPUT);
  pinMode(PIN_CYLIN_KNEE_DOWN, OUTPUT);
  pinMode(PIN_CYLIN_HIP_UP, OUTPUT);
  pinMode(PIN_CYLIN_HIP_DOWN, OUTPUT);
  pinMode(PIN_BUTTON_MODE_SWITCH, INPUT);
}
