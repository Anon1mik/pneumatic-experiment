#include "Arduino.h"
#include "DFilters.h"
#include "pinmap.h"
#include "switchstate.h"
#include "sensors.h"

void setup(){
  Serial.begin(9600); 
  initPins();
}

void loop(){

  // Вывод значений в порт
 int tumblerOneValue = TUMBLER_ONE();
 int tumblerTwoValue = TUMBLER_TWO();
 int potentsiometr1 = getAngleHip();
 int potentsiometr2 = getAngleHip1();

 Serial.print(potentsiometr1);
 Serial.print(",");
 Serial.print(potentsiometr2);
 Serial.print(",");
 Serial.print(tumblerOneValue);
 Serial.print(",");
 Serial.println(tumblerTwoValue);
}
