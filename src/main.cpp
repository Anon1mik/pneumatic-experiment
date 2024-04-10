#include "Arduino.h"

#include "DFilters.h"
#include "DTimer.h"
#include "DPolynomial.h"

#include "pinmap.h"
#include "debounce.h"
#include "sensors.h"
#include "control.h"
#include "data.h"
#include "regulator.h"

void setup(){
  Serial.begin(9600); 
  setupPins();
}

void loop(){
  printData();
  pneumaticCulyndr();
  regulatorHip();
}
