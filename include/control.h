#pragma once

// *** оставить тут только траектории, переименовать заголовочник

// Режимы работы стенда
enum PNEUMA_STATES{
  PS_LEG_UP,    // Подъем бедра
  PS_LEG_DOWN,  // Спуск бедра
  PS_KNEE_UP,   // Подъем колена
  PS_KNEE_DOWN, // Спуск колена
};
PNEUMA_STATES pneuma_state = PS_LEG_UP;

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
// *** подписать комментарии из примера выше
float getSineWave(float _freq, float _amp, int _down_position){
  // Таймер
  static unsigned long _loop_timer;
  unsigned long _delta_timer = millis() - _loop_timer;
  _loop_timer = millis();

  static float _time;
  _time += (float)_delta_timer / 1000.0;
  
  float _output = _down_position + _amp * sin(6.28 * _time * _freq); // Расчёт позиции

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

// *** в отчет
float polinom3(unsigned long _up_time, int _down_position, int _upper_position){
  // Создание объекта полинома
  Polynomial_3 _polynomial;
  static int state = 0; // Переменная для направления графика

    // *** не правильно
    // 1-е действие, выполняется при запуске МК
  if (state == 0){
    _polynomial.calculate(_down_position, _upper_position, _up_time);
    state = 1;
  }
  // 1-й цикл, спуск
  if (state == 1){
    if (_polynomial.isFinished()){
      _polynomial.calculate(_upper_position, _down_position, _up_time);
      state = 2;
    }
  }
  // 2-й цикл, подъем 
  else if (state == 2){
    if (_polynomial.isFinished()){
      _polynomial.calculate(_down_position, _upper_position, _up_time);
      state = 1;
    }
  }
  // Возвращаем ошибку в функцию
  return _polynomial.getPosition();
}

// Функции управления пневматическими цилиндрами в зависимости от положения тумблеров
// ***ПЕРЕИМЕНУЙ
void moveHipUp(){
  digitalWrite(PIN_CYLIN_HIP_UP, HIGH);
  digitalWrite(PIN_CYLIN_HIP_DOWM, LOW);
}
void LegDOWN(){
  digitalWrite(PIN_CYLIN_HIP_UP, LOW);
  digitalWrite(PIN_CYLIN_HIP_DOWM, HIGH);
}
void LegSTOP(){
  digitalWrite(PIN_CYLIN_HIP_UP, LOW);
  digitalWrite(PIN_CYLIN_HIP_DOWM, LOW);
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