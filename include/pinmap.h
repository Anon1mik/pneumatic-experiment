#pragma once

#define PIN_ANGLE_HIP   A0 // ДУП бедренного шарнира
#define PIN_ANGLE_KNEE  A1 // ДУП коленного шарнира

#define PIN_SWITCH_LEFT_UP    2   // Левый тумблер ПУ (пульт управления), верхнее положение
#define PIN_SWITCH_LEFT_DOWN  13  // Левый тумблер ПУ, нижнее положение
#define PIN_SWITCH_RIGHT_UP   3   // Правый тумблер ПУ, верхнее положение
#define PIN_SWITCH_RIGHT_DOWN 4   // Правый тумблер ПУ, нижнее положение

// ***тут переименуй
#define PIN_CYLIN_HIP_UP 12   // Верхний цилиндр бедренного привода L2 тут получре распиши
#define PIN_CYLIN_HIP_DOWM 11   // L1
#define PIN_CYLIN_KNEE2 10  // K2
#define PIN_CYLIN_KNEE1 9   // K1

// ***неправильное название pin button mode switch
#define BUTTON A3 // Кнопка переключения состояния 

// Настраиваем пины ввода-вывода
void setupPins(){
  pinMode(PIN_CYLIN_KNEE2, OUTPUT);
  pinMode(PIN_CYLIN_KNEE1, OUTPUT);
  pinMode(PIN_CYLIN_HIP_UP, OUTPUT);
  pinMode(PIN_CYLIN_HIP_DOWM, OUTPUT);
  pinMode(BUTTON, INPUT);
}
