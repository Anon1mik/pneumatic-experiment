#pragma once

int poly3;

// Регуляция состояния бедра
// ***Зачем передаешь дедзону? убрать внутря функции
// *** в отчет
void regulatorHip(int deathZone){
    poly3 = polinom3(3000, 100, 1000);
    static int _error; // Ошибка позиционирования

    // Рассчитаем ошибку
    _error = poly3 - getAngleHip();

    // *** переименовать
    const int _upper_death_zone = deathZone / 2; // Мёртвая зона
    const int _downDeathZone = _upper_death_zone * -1;

    // *** защиту нужно в полиноме делать, а не тут
    // Включаем циллинрды с соответсвием мёртвой зоны, так же защищаем цилиндр от упора в одну сторону LegUP();
    if (_error > _upper_death_zone) LegDOWN();
    else if (_error < _upper_death_zone) moveHipUp();
    else LegSTOP();
}

//*** сделать по примеру верхнего
void regulatorKnee(int deathZone){
  // ОПЯТЬ ЖЕ НА БУДУЮЩЕЕ КОНТР С V ДЛЯ КОЛЕНА
    static int KneeError; // Переменная для расчёта ошибки
  
    KneeError = poly3 - getAngleKnee();

    // Использование полинома

    const int _upper_death_zone     = deathZone / 2; // Мёртвая зона
    const int _downDeathZone = _upper_death_zone * (-1);

    // Если выключатель включен, то расчитываем ошибку через соответсвующий график
    if (buttonState == 0)
    {
         // Включаем циллинрды с соответсвием мёртвой зоны, так же защищаем цилиндр от упора в одну сторону
        if      (getAngleKnee() > 900)                                                       KneeDOWN();
        else if (getAngleKnee() < 100)                                                       KneeUP();
        else if (KneeError > _upper_death_zone && getAngleKnee() < 900 && getAngleKnee() > 100)     KneeDOWN();
        else if (KneeError < _downDeathZone && getAngleKnee() < 900 && getAngleKnee() > 100) KneeUP();
        else                                                                                 KneeSTOP();
    }
}

// Ручное управление
// ***Форматирование по примеру
void manualControl(){
  // Управление цилиндром левой ноги в зависимости от положения левого тумблера
  if(getTumblerLeft() == 2) moveHipUp();
  else if (getTumblerLeft() == 1) LegDOWN();
  else LegSTOP();

  // Управление цилиндром правого колена в зависимости от положения правого тумблера
  if (getTumblerRight() == 2)
    KneeUP();
  else if (getTumblerRight() == 1)
    KneeDOWN();
  else
    KneeSTOP();
}
