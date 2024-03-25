#pragma once

unsigned long prevMillis = 0;
const unsigned long interval = 1;

// Функция для генерации пилообразной волны
// Принимает на вход частоту, минимальное и максимальное значения.
int pila(const float FREQUENCY, const int MIN_VALUE, const int MAX_VALUE) {

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
  if (current_time - prev_time >= period) {

    prev_time = current_time;

    value = (value + 1) % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE;
  }

  // Вернуть текущее значение волны.
  return value;
}

// Функция для генерации синусоидальной волны

int sinus(int frequency, int amplitude, int min_value, int max_value) {
   for (float i = 0; i < 360; i += 1) {
    static float Sine1 = 100 * sin(i * M_PI / 180);
    return Sine1;
}
}
void polinom()
{

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
