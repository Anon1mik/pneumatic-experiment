#pragma once 

// Функция для получения значения ДУП бедренного шарнира
int getAngleHip(){
  static ERA_filter<float> _era(0.1);               // Создаём фильтр с коэффициентом 0.1
  return _era.filtered(analogRead(PIN_ANGLE_HIP));  // Возвращаем отфильтрованное значение ДУП бедра
}

// Функция для получения угла колена
int getAngleKnee(){
  static ERA_filter<float> _era(0.1); // Создаём фильтр с коэффициентом 0.1
  return _era.filtered(analogRead(PIN_ANGLE_KNEE)); // Возвращаем отфильтрованное значение угла колена
}

// Создаём объекты класса Debounce для работы с переключателями
DebounceButton SwitchLeftUp   (PIN_SWITCH_LEFT_UP);
DebounceButton SwitchLeftDown (PIN_SWITCH_LEFT_DOWN);
DebounceButton SwitchRightUp  (PIN_SWITCH_RIGHT_UP);
DebounceButton SwitchRightDown(PIN_SWITCH_RIGHT_DOWN);

bool buttonState = digitalRead(BUTTON);
// Функция для определения положения первого тумблера
// В нижнем положении возвращает 1, в верхнем - 2, в среднем - 0

int getTumblerLeft() {
  if      (SwitchLeftUp.getSwitchState())   return 1;  // если нижняя кнопка включена, возвращаем 1
  else if (SwitchLeftDown.getSwitchState()) return 2;  // если верхняя кнопка включена, возвращаем 2
  else                                      return 0;  // если обе кнопки выдают 0, то возвращаем 0
}

// Функция для определения положения второго тумблера
// В нижнем положении возвращает 1, в верхнем - 2, в среднем - 0
int getTumblerRight(){
  if      (SwitchRightDown.getSwitchState()) return 2; // если нижняя кнопка включена, возвращаем 1
  else if (SwitchRightUp.getSwitchState())   return 1; // если верхняя кнопка включена, возвращаем 2
  else                                       return 0; // если обе кнопки выдают 0, то возвращаем 0
}