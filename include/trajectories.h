#pragma once


// *** в отчет
// Функция для генерации пилообразной волны
// Принимает на вход частоту[Гц], амплитуду[град.], крайнюю нижнею позицию[град.]
float getSawWave(float _freq, float _amp, float _down_position){
  static float _output;  // Выходной сигнал
  static int _vect = 1; // Переменная для определения направления движения волны

  // Рассчитываем период цикла
  static unsigned long _loop_timer;
  unsigned long _delta_timer = millis() - _loop_timer;
  _loop_timer = millis();

  // Счетчик времени
  static float _time;
  // Обновляем счетчик времени
  _time += ((float)_delta_timer * _vect) / 1000.0;

  // Расчет выходного сигнала
  _output = 2.0 * _amp * _time * _freq + _down_position;

  // Переключаем вектор
  if (_output > _amp + _down_position) _vect = -1;
  else if (_output < _down_position)   _vect = 1;

  // Возвращаем выходной сигнал
  return _output;
}

// *** в отчет алгоритм, описание параметров скрин
// Функция для генерации синуса
float getSineWave(float _freq, float _amp, int _down_position){
   // Рассчитываем период цикла
  static unsigned long _loop_timer;
  unsigned long _delta_timer = millis() - _loop_timer;
  _loop_timer = millis();
  
  // Счетчик времени
  static float _time;
  // Обновляем счетчик времени
  _time += (float)_delta_timer / 1000.0;
  // Расчет выходного сигнала
  float _output = _down_position + _amp * sin(6.28 * _time * _freq);
  // Возвращаем выходной сигнал
  return _output;
}

// Функция для генерации полинома волны
// ***название и описать параметры
// ***сделать класс наследник на будущее

// class PolynomialTrajectory : Polynomial_3{
//   public:
//     PolynomialTrajectory(){

//     };
// };

