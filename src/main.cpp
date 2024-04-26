#include "Arduino.h"

#include "DFilters.h"
#include "DPolynomial.h"
#include "debounce.h"

#include "pinmap.h"
#include "sensors.h"
#include "trajectories.h"
#include "data.h"
#include "drive.h"

void setup(){
  Serial.begin(9600); 
  setupPins();
}

void loop(){
  // // Если кнопка нажата, переводим систему в ручной режим
  if(buttonState()) manualControl();
   // Иначе используем автоматическое управление
   else{
  //   // Перемещение приводов согласно полиному 3-го порядка   
     regulatorHip(); 
     regulatorKnee();
  }
   printData(); // Отправка данных
   Serial.println(poly3);
}
