#include "Arduino.h"

#include "DFilters.h"
#include "DTimer.h"
#include "DPolynomial.h"

#include "pinmap.h"
#include "debounce.h"
#include "sensors.h"
#include "control.h"
#include "data.h"
#include "drive.h"

void setup(){
  Serial.begin(9600); 
  setupPins();
}

void loop(){
  // // Если кнопка нажата, переводим систему в ручной режим
  // if(buttonState) manualControl();
  // // Иначе используем автоматическое управление
  // else{     
  //   // Перемещение приводов согласно полиному 3-го порядка   
  //   regulatorHip(20); 
  //   regulatorKnee(20);
  // }
  // printData(); // Отправка данных
}
