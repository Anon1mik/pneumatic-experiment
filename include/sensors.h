#pragma once 

// Функция для получения угла бедра
int getAngleHip(){
  static ERA_filter<float> _era(0.1); // Создаём статический фильтр с коэффициентом 0.1
  return _era.filtered(analogRead(PIN_ANGLE_HIP)); // Возвращаем отфильтрованное значение угла бедра
}

// Функция для получения угла колена
int getAngleKnee(){
  static ERA_filter<float> _era1(0.1); // Создаём фильтр с коэффициентом 0.1
  return _era1.filtered(analogRead(PIN_ANGLE_KNEE)); // Возвращаем отфильтрованное значение угла колена
}

// Создаём объекты класса Debounce для работы с переключателями
DebounceButton SwitchLeftUp(PIN_SWITCH_LEFT_UP);
DebounceButton SwitchLeftDown(PIN_SWITCH_LEFT_DOWN);
DebounceButton SwitchRightUp(PIN_SWITCH_RIGHT_UP);
DebounceButton SwitchRightDown(PIN_SWITCH_RIGHT_DOWN);

// Функция для определения положения первого тумблера
// В нижнем положении возвращает 1, в верхнем - 2, в среднем - 0
int TUMBLER_ONE() {
  bool switchState1 = SwitchLeftUp.getSwitchState(); // Получаем состояние первого переключателя тумблера
  bool switchState2 = SwitchLeftDown.getSwitchState(); // Получаем состояние второго переключателя тумблера

  if (switchState1 == 1){
    return 1;
  }
  else if (switchState2 == 1){
    return 2;
  }
  return 0;
}

// Функция для определения положения второго тумблера
// В нижнем положении возвращает 1, в верхнем - 2, в среднем - 0
int TUMBLER_TWO(){
  bool switchState1 = SwitchRightUp.getSwitchState(); // Получаем состояние первого переключателя тумблера
  bool switchState2 = SwitchRightDown.getSwitchState(); // Получаем состояние второго переключателя тумблера

  if (switchState1 == 1){
    return 2;
  }
  else if (switchState2 == 1){
    return 1;
  }
  return 0;
}