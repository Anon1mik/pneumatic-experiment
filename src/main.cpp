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

  // Если кнопка не нажата, переводим управление в автоматический режим
  if (buttonState == 1) pneumaticCulyndr();
  // При нажатии на кпо
  else{     
    // Физическое включение пневмоциллиндров от показания полинома    
    regulatorHip(20); 
    regulatorKnee(20);
  }
  printData(); // Отправка данных 
}
