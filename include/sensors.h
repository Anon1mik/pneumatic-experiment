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

DebounceButton ModeSwich (PIN_BUTTON_MODE_SWITCH);

bool buttonState(){
 if (ModeSwich.getSwitchState()) return 1;
 else return 0;

}
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

float polinom3(unsigned long _up_time, int _down_position, int _upper_position){
  // Создание объекта полинома
  Polynomial_3 _polynomial;
  static int _state = 0; // Переменная для направления графика

    // 1-е действие, выполняется при запуске функции
  if (_state == 0){
    _polynomial.calculate(_down_position, _upper_position, _up_time);
    _state = 1;
  }
  // 1-й цикл, спуск
  if (_state == 1){
    if (_polynomial.isFinished()){
      _polynomial.calculate(_upper_position, _down_position, _up_time);
      _state = 2;
    }
  }
  // 2-й цикл, подъем 
  else if (_state == 2){
    if (_polynomial.isFinished()){
      _polynomial.calculate(_down_position, _upper_position, _up_time);
      _state = 1;
    }
  }
  // Возвращаем ошибку в функцию
  return _polynomial.getPosition();
}
float polinom31(unsigned long _up_time, int _down_position, int _upper_position){
  // Создание объекта полинома
  Polynomial_3 _polynomial31;
  static int _state = 0; // Переменная для направления графика

    // 1-е действие, выполняется при запуске функции
  if (_state == 0){
    _polynomial31.calculate(_down_position, _upper_position, _up_time);
    _state = 1;
  }
  // 1-й цикл, спуск
  if (_state == 1){
    if (_polynomial31.isFinished()){
      _polynomial31.calculate(_upper_position, _down_position, _up_time);
      _state = 2;
    }
  }
  // 2-й цикл, подъем 
  else if (_state == 2){
    if (_polynomial31.isFinished()){
      _polynomial31.calculate(_down_position, _upper_position, _up_time);
      _state = 1;
    }
  }
  // Возвращаем ошибку в функцию
  return _polynomial31.getPosition();
}

