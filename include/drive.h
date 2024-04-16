#pragma once

// Регуляция состояния бедра
void regulatorHip(int deathZone)
{

    static int legError; // Переменная для расчёта ошибки

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