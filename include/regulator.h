#pragma once

// Регуляция состояния бедра
void regulatorHip(){

static int legError; // Переменная для расчёта ошибки
static int ifState1; // Переменная для определения графика расчёта

const int deathZone = 10; // Мёртвая зона
const int downDeathZone = deathZone *(-1);


if (buttonState == 1){
    // Если выключатель включен, то расчитываем ошибку через соответсвующий график
    switch (getTumblerLeft())
    {
        // Выключение пневмоциллиндра
    case 1:
        ifState1 = 1;
        break;
        // Отработка линейного графика
    case 2:
        ifState1 = 2;
        break;
    }
        switch (getTumlerRight())
    {
        // Отработка синусоидального графика
    case 1:
        ifState1 = 3;
        break;
        // Отработка полиномного графика
    case 2:
        ifState1 = 4;
        break;
    }
    // Логика расчёта ошибки
    if (ifState1 == 1)      LegSTOP();
    else if (ifState1 == 2) legError = getAngleHip() - getSaw(1.0, 500, 100);   // Линейный график
    else if( ifState1 == 3) legError = getAngleHip() - sinus(1.0, 500, 100);    // Синусоидальный график
    else if( ifState1 == 3) legError = getAngleHip() - polinom3(5000, 500, 100);// График полинома

    // Включаем циллинрды с соответсвием мёртвой зоны
    if     (legError > deathZone) LegDOWN();
    else if(legError < downDeathZone) LegUP();
    else                          LegSTOP();
}

}