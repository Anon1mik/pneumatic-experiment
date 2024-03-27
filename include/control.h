#pragma once

unsigned long prevMillis = 0;
const unsigned long interval = 1;

// Функция для генерации пилообразной волны
// Принимает на вход частоту, минимальное и максимальное значения.
int pila(const float FREQUENCY, const int MIN_VALUE, const int MAX_VALUE)
{

  // Статическая переменная для хранения предыдущего времени.
  static unsigned long prev_time = 0;

  // Статическая переменная для хранения текущего значения волны.
  // Это значение будет обновляться между вызовами функции.
  static int value = MIN_VALUE;

  unsigned long current_time = millis();

  // Вычислить период волны в миллисекундах.
  // Делим 1000 (количество миллисекунд в секунде) на заданную частоту.
  const int period = int(1000 / FREQUENCY);

  // Проверка времени:
  // Если прошло достаточно времени для следующего шага волны
  if (current_time - prev_time >= period)
  {

    prev_time = current_time;

    value = (value + 1) % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
  }

  // Вернуть текущее значение волны.
  return value;
}

// функция для генерации синуса
int sinus(float _freqsin, float _amp, int _midle)
{
  static unsigned long _loop_timer1;
  unsigned long _delta_timer = millis() - _loop_timer1;
  _loop_timer1 = millis();

  static float _time;
  _time += (float)_delta_timer / 1000.0;
  float _output_pos_lhr = _midle + _amp * sin(6.28 * _time * _freqsin);

  return (int)_output_pos_lhr;
}

// Функция для генерации полинома волны

int polinom(unsigned long _takeoff_time, int _down_position, int upper_position)
{

  Polynomial_3 polynomial_3;
  static unsigned long _loop_timer = 0;  // Время в микросекундах
  static unsigned long _delta_timer = 0; // Период цикла в микросекундах
  static unsigned long _plan_time = 0;   // Плановое время
 
  _delta_timer = micros() - _loop_timer;
  _loop_timer = micros();

  _plan_time += _delta_timer;

  if (_plan_time > _takeoff_time)
    _plan_time = 0;

  if (_plan_time <= _takeoff_time / 2)
  {
    polynomial_3.calcCoef(_down_position, upper_position, 0, 0, 0, _takeoff_time / 2);
  }
  else
  {
    polynomial_3.calcCoef(upper_position, _down_position, 0, 0, _takeoff_time / 2, _takeoff_time);
  }
  double result = polynomial_3.getPosition(_plan_time);
  return (int)result;
}
// Функция управления пневматическими цилиндрами в зависимости от положения тумблеров
void pneumaticCulyndr()
{
  // Управление цилиндром левой ноги в зависимости от положения левого тумблера

  if (getTumblerLeft() == 2)
  {
    digitalWrite(PIN_CYLIN_LEG2, HIGH);
    digitalWrite(PIN_CYLIN_LEG1, LOW);
  }
  else if (getTumblerLeft() == 1)
  {
    digitalWrite(PIN_CYLIN_LEG2, LOW);
    digitalWrite(PIN_CYLIN_LEG1, HIGH);
  }
  else
  {
    digitalWrite(PIN_CYLIN_LEG2, LOW);
    digitalWrite(PIN_CYLIN_LEG1, LOW);
  }

  // Управление цилиндром правого колена в зависимости от положения правого тумблера
  if (getTumlerRight() == 2)
  {
    digitalWrite(PIN_CYLIN_KNEE2, HIGH);
    digitalWrite(PIN_CYLIN_KNEE1, LOW);
  }
  else if (getTumlerRight() == 1)
  {
    digitalWrite(PIN_CYLIN_KNEE2, LOW);
    digitalWrite(PIN_CYLIN_KNEE1, HIGH);
  }
  else
  {
    digitalWrite(PIN_CYLIN_KNEE2, LOW);
    digitalWrite(PIN_CYLIN_KNEE1, LOW);
  }
}
/* else{
       Serial.println(pila());
     // sinus();
     // polinom();
 } */