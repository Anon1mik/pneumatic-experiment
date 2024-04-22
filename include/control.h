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
// Принимает на вход частоту, амплитуду, нижнию позицию
int getSaw(float _freq, float _amp, float _down_position)
{ //          Частота,разброс волны, нижняя позиция.
  // Например:    5.0        100.0         50.0

  static float _value;  // Переменная для расчёта
  static int _vect = 1; // Переменная для определения движения волны

  // Таймер
  static unsigned long _loop_timer1;
  unsigned long _delta_timer = millis() - _loop_timer1;
  _loop_timer1 = millis();
  static float _time;
  // Переменная, которая увеличивается или уменьшается относительно времени
  _time += ((float)_delta_timer * _vect) / 1000.0;
  // Формула построения графика
  _value = 2.8 * _amp * _time * _freq + _down_position;
  // Логика направления графика
  if (_value > _amp + _down_position)
    _vect = -1;
  else if (_value < _down_position)
    _vect = 1;

  return _value;
}
// Функция для генерации синуса
int sinus(float _freqsin, float _amp, int _down_position)
{
  // Таймер
  static unsigned long _loop_timer1;
  unsigned long _delta_timer = millis() - _loop_timer1;
  _loop_timer1 = millis();
  static float _time;
  _time += (float)_delta_timer / 1000.0;
  

  float _output = _down_position + _amp * sin(6.28 * _time * _freqsin); // Расчёт позиции

  return (int)_output;
}
// Функция для генерации полинома волны
int polinom3(unsigned long _up_time, int _downPosition, int _upperPosition)
{
  // Создание объекта полинома
  Polynomial_3 _polynomial;
  static int state = 0; // Переменная для направления графика

    // 1-е действие, выполняется при запуске МК
  if (state == 0){
    _polynomial.calculate(_downPosition, _upperPosition, _up_time);
    state = 1;
  }
  // 1-й цикл, спуск
  if (state == 1){
    if (_polynomial.isFinished() == 1)
    {
      _polynomial.calculate(_upperPosition, _downPosition, _up_time);
      state = 2;
    }
  }
  // 2-й цикл, подъем 
  else if (state == 2){
    if (_polynomial.isFinished() == 1)
    {
      _polynomial.calculate(_downPosition, _upperPosition, _up_time);
      state = 1;
    }
  }
  // Возвращаем ошибку в функцию
  return _polynomial.getPosition();
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