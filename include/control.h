#pragma once

// Режимы работы экзоскелета
enum PNEUMO_STATES
{
  PS_LEG_UP,    // Подъем бедра
  PS_LEG_DOWN,  // Спуск бедра
  PS_KNEE_UP,   // Подъем колена
  PS_KNEE_DOWN, // Спуск колена
};

PNEUMO_STATES pneumo_state = PS_LEG_UP;

// Функция для генерации пилообразной волны
// Принимает на вход частоту, минимальное и максимальное значения.
int getSaw(float _freq, float _amp, float _midle)
{ //          Частота,разброс волны, центр волны.
  // Например:    5.0        100.0         50.0

  static float _value;  // Значение, которое мы будем выводить
  static int _vect = 1; // Переменная для определения движения волны

  // Таймер
  static unsigned long _loop_timer1;
  unsigned long _delta_timer = millis() - _loop_timer1;
  _loop_timer1 = millis();
  static float _time;
  // Переменная, которая увеличивается или уменьшается относительно времени
  _time += ((float)_delta_timer * _vect) / 1000.0;
  // Формула построения графика
  _value = 2.8 * _amp * _time * _freq + _midle;
  // Логика направления графика
  if (_value > _amp + _midle)
    _vect = -1;
  else if (_value < _midle - (_amp / 2))
    _vect = 1;

  return _value;
}
// Функция для генерации синуса
int sinus(float _freqsin, float _amp, int _down_position)
{
  static unsigned long _loop_timer1;
  unsigned long _delta_timer = millis() - _loop_timer1;
  _loop_timer1 = millis();

  static float _time;
  _time += (float)_delta_timer / 1000.0;
  float _output_pos_lhr = _down_position + _amp * sin(6.28 * _time * _freqsin);

  return (int)_output_pos_lhr;
}

// Функция для генерации полинома волны
int polinom3(unsigned long _up_time, int _amp, int _downPosition)
{
  // Создание объекта полинома
  Polynomial_3 polynomial_3;

  // Переменная для отработки полинома ровно один раз
  static int _last_state = -1;   
  // Логика направления полинома
  if (_last_state == -1)
  {
    if (pneumo_state == PS_LEG_UP)
    {
      polynomial_3.calculate(_downPosition, _downPosition + _amp, _up_time / 2);
      _last_state = 1;
    }
    else if (pneumo_state == PS_LEG_DOWN) {
        polynomial_3.calculate(_downPosition + _amp, _downPosition, _up_time);
      _last_state = 1;
    }
  } 
// Переменная для отправки значения в функцию
  static int _poly_value = polynomial_3.getPosition();
  
  // Логика расчёта верхней и нижней позиции
  if (_poly_value > _downPosition + _amp)
  {
    pneumo_state = PS_LEG_DOWN;
    _last_state = -1;
  }
  else if(_poly_value < _downPosition){
    pneumo_state = PS_LEG_UP;
    _last_state = -1;
  }

  return _poly_value;
}
// Функция управления пневматическими цилиндрами в зависимости от положения тумблеров

void LegUP(){
    digitalWrite(PIN_CYLIN_LEG2, HIGH);
    digitalWrite(PIN_CYLIN_LEG1, LOW);
}
void LegDOWN(){
    digitalWrite(PIN_CYLIN_LEG2, LOW);
    digitalWrite(PIN_CYLIN_LEG1, HIGH); 
}
void LegSTOP(){
    digitalWrite(PIN_CYLIN_LEG2, LOW);
    digitalWrite(PIN_CYLIN_LEG1, LOW);
}
void KneeUP(){
    digitalWrite(PIN_CYLIN_KNEE2, HIGH);
    digitalWrite(PIN_CYLIN_KNEE1, LOW);
}
void KneeDOWN(){
    digitalWrite(PIN_CYLIN_KNEE2, LOW);
    digitalWrite(PIN_CYLIN_KNEE1, HIGH);
}
void KneeSTOP(){
    digitalWrite(PIN_CYLIN_KNEE2, LOW);
    digitalWrite(PIN_CYLIN_KNEE1, LOW);
}
// Ручное управление, если кнопка не нажата
void pneumaticCulyndr()
{
  // Управление цилиндром левой ноги в зависимости от положения левого тумблера
if (buttonState == 0){
  if      (getTumblerLeft() == 2) LegUP();
  else if (getTumblerLeft() == 1) LegDOWN();
  else                            LegSTOP();


  // Управление цилиндром правого колена в зависимости от положения правого тумблера
  if      (getTumlerRight() == 2) KneeUP();
  else if (getTumlerRight() == 1) KneeDOWN();
  else                            KneeSTOP();
}
}