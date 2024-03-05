#pragma once

#include "pinmap.h"
#include "DFilters.h"
#include "switchstate.h"

int getAngleHip(){
  static ERA_filter<float> _era(0.1); // Фильтр
  return _era.filtered(analogRead(PIN_ANGLE_HIP));
}

int getAngleHip1(){
  static ERA_filter<float> _era1(0.1); // Фильтр
  return _era1.filtered(analogRead(PIN_ANGLE_KNEE));
}

SwitchLibrary mySwitch11(PIN_SWITCH11);
SwitchLibrary mySwitch12(PIN_SWITCH12);
SwitchLibrary mySwitch21(PIN_SWITCH21);
SwitchLibrary mySwitch22(PIN_SWITCH22);

// Первый тумблер, в нижнем положении 1, в верхнем 2, в среднем 0
int TUMBLER_ONE() { 
  bool switchState1 = mySwitch11.getSwitchState();
  bool switchState2 = mySwitch12.getSwitchState();
  if (switchState1 == 1){
    return 1;
  }
  else if (switchState2 == 1){
    return 2;
  }
  return 0;
}

// Второй тумблер, в нижнем положении 1, в верхнем 2, в среднем 0
int TUMBLER_TWO(){
  bool switchState1 = mySwitch21.getSwitchState();
  bool switchState2 = mySwitch22.getSwitchState();
  if (switchState1 == 1){
    return 2;
  }
  else if (switchState2 == 1){
    return 1;
  }
  return 0;
}