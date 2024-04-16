#pragma once

// Регуляция состояния бедра
void regulatorHip(int deathZone)
{

    static int legError; // Переменная для расчёта ошибки

    // Использование полинома
    legError = polinom3(1000, 0, 900);

    const int _deathZone = deathZone / 2; // Мёртвая зона
    const int _downDeathZone = _deathZone * (-1);

    // Если выключатель включен, то расчитываем ошибку через соответсвующий график
    if (buttonState == 1)
    {
        // Включаем циллинрды с соответсвием мёртвой зоны
        if      (legError > _deathZone)     LegDOWN();
        else if (legError < _downDeathZone) LegUP();
        else                                LegSTOP();
    }
}
// Ручное управление, если кнопка не нажата
void pneumaticCulyndr()
{
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