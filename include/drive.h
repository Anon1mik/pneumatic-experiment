#pragma once

int poly3;

// Регуляция состояния бедра
void regulatorHip(int deathZone)
{
    poly3 = polinom3(3000, 100, 1000);
    static int legError; // Переменная для расчёта ошибки

    // Использование полинома
    legError = poly3 - getAngleHip();

    const int _deathZone = deathZone / 2; // Мёртвая зона
    const int _downDeathZone = _deathZone * (-1);

    // Если выключатель включен, то расчитываем ошибку через соответсвующий график
    if (buttonState == 0)
    {
        // Включаем циллинрды с соответсвием мёртвой зоны, так же защищаем цилиндр от упора в одну сторону
        if      (getAngleHip() > 900)                                                     LegDOWN();
        else if (getAngleHip() < 100)                                                     LegUP();
        else if (legError > _deathZone && getAngleHip() < 900 && getAngleHip() > 100)     LegDOWN();
        else if (legError < _downDeathZone && getAngleHip() < 900 && getAngleHip() > 100) LegUP();
        else                                                                              LegSTOP();
    }
         Serial.println(poly3);
}
void regulatorKnee(int deathZone){
  // ОПЯТЬ ЖЕ НА БУДУЮЩЕЕ КОНТР С V ДЛЯ КОЛЕНА
    static int KneeError; // Переменная для расчёта ошибки
  
    KneeError = poly3 - getAngleKnee();

    // Использование полинома

    const int _deathZone     = deathZone / 2; // Мёртвая зона
    const int _downDeathZone = _deathZone * (-1);

    // Если выключатель включен, то расчитываем ошибку через соответсвующий график
    if (buttonState == 0)
    {
         // Включаем циллинрды с соответсвием мёртвой зоны, так же защищаем цилиндр от упора в одну сторону
        if      (getAngleKnee() > 900)                                                       KneeDOWN();
        else if (getAngleKnee() < 100)                                                       KneeUP();
        else if (KneeError > _deathZone && getAngleKnee() < 900 && getAngleKnee() > 100)     KneeDOWN();
        else if (KneeError < _downDeathZone && getAngleKnee() < 900 && getAngleKnee() > 100) KneeUP();
        else                                                                                 KneeSTOP();
    }
}

// Ручное управление, если кнопка не нажата
void pneumaticCulyndr(){
  // Управление цилиндром левой ноги в зависимости от положения левого тумблера
  if (buttonState == 0)
  {
    if (getTumblerLeft() == 2)
      LegUP();
    else if (getTumblerLeft() == 1)
      LegDOWN();
    else
      LegSTOP();

    // Управление цилиндром правого колена в зависимости от положения правого тумблера
    if (getTumlerRight() == 2)
      KneeUP();
    else if (getTumlerRight() == 1)
      KneeDOWN();
    else
      KneeSTOP();
  }
}
