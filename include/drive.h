#pragma once

int poly3;

// Функции управления пневматическими цилиндрами в зависимости от положения тумблеров
void moveHipUp(){
  digitalWrite(PIN_CYLIN_HIP_UP, HIGH);
  digitalWrite(PIN_CYLIN_HIP_DOWN, LOW);
}
void moveHipDown(){
  digitalWrite(PIN_CYLIN_HIP_UP, LOW);
  digitalWrite(PIN_CYLIN_HIP_DOWN, HIGH);
}
void HipStop(){
  digitalWrite(PIN_CYLIN_HIP_UP, LOW);
  digitalWrite(PIN_CYLIN_HIP_DOWN, LOW);
}
void moveKneeUp(){
  digitalWrite(PIN_CYLIN_KNEE_UP, HIGH);
  digitalWrite(PIN_CYLIN_KNEE_DOWN, LOW);
}
void moveKneeDown(){
  digitalWrite(PIN_CYLIN_KNEE_UP, LOW);
  digitalWrite(PIN_CYLIN_KNEE_DOWN, HIGH);
}
void kneeStop(){
  digitalWrite(PIN_CYLIN_KNEE_UP, LOW);
  digitalWrite(PIN_CYLIN_KNEE_DOWN, LOW);
}

// Регуляция состояния бедра хуя
// *** в отчетe
int regulatorHip(){

    const int _deathZone = 20;
    poly3 = polinom3(9000, 100, 920);
    static int _error; // Ошибка позиционирования

    // Рассчитаем ошибку
    _error = poly3 - getAngleHip();

    // Включаем циллинрды с соответсвием мёртвой зоны, так же защищаем цилиндр от упора в одну сторону LegUP();
    if (_error > _deathZone)           moveHipDown();
    else if (_error < _deathZone * -1) moveHipUp();
    else                               HipStop();
    return poly3;
}
int regulatorKnee(){
    const int  _deathZone = 20;
    static int _error; // Ошибка позиционирования

      // Рассчитаем ошибку
    _error = poly3 - getAngleKnee();

         // Включаем циллинрды с соответсвием мёртвой зоны, так же защищаем цилиндр от упора в одну сторону
    if (_error > _deathZone)           moveKneeDown();
    else if (_error < _deathZone * -1) moveKneeUp();
    else                               kneeStop();

    return poly3;
}

// Ручное управление
void manualControl(){
  // Управление цилиндром левой ноги в зависимости от положения левого тумблера
  if(getTumblerLeft() == 2)        moveHipUp();
  else if(getTumblerLeft() == 1)   moveHipDown();
  else                             HipStop();

  // Управление цилиндром правого колена в зависимости от положения правого тумблера
  if(getTumblerRight() == 2)       moveKneeUp();
  else if (getTumblerRight() == 1) moveKneeDown();
  else                             kneeStop();
}
