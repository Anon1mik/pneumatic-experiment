#include "Arduino.h"
#include "pinmap.h"
#include "DFilters.h"
#include "debounce.h"
#include "sensors.h"
#include "comport.h"

void setup(){
  Serial.begin(9600); 
  initPins();
}

void loop(){
  // Вывод значений в порт
com();
}
