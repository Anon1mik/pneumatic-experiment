#pragma once

unsigned long prevMillis = 0;
const unsigned long interval = 1; 

int pila(int freq, int amp) {
  static int potentLEG = 0;
  static int _state = 0;
  const int _upperPosition = 800;
  const int _lowerPosition = 200;
  const int _koef = 10;
  unsigned long currentMillis;

  if (_state == 0) {
    if (potentLEG < _upperPosition) {
      potentLEG += (millis() - currentMillis) / _koef;
      currentMillis = millis();
    } else{
      _state = 1;
      
    }
  } else{
    if (potentLEG > _lowerPosition) {
      potentLEG -= (millis() - currentMillis) / _koef;
      currentMillis = millis();
    } else{
      _state = 0;
    }
  }
  // Ограничение

  return potentLEG;
}
  

int sinus(){
#define PI 3.14159  // Define pi for sine calculation
  static int _state = 0;
  static int potentLEG = 0;
  const int _upperPosition = 800;
  const int _lowerPosition = 200;
  const int amplitude = (_upperPosition - _lowerPosition) / 2;  // Half the range for sine wave
  const int center = (_upperPosition + _lowerPosition) / 2;  // Center position for sine wave

  unsigned long currentMillis = millis();  // Use current time for calculations

  // Define a variable for time-based angle (in milliseconds)
  static unsigned long timeAngle = 0;
  const unsigned long period = 2000;  // Adjust for desired cycle duration (in milliseconds)

  // Update timeAngle based on elapsed time and period
  timeAngle += (currentMillis - prevMillis);
  prevMillis = currentMillis;

  // Calculate sine value based on timeAngle and scale it to fit the servo range
  double sineValue = sin(2 * PI * timeAngle / period);  // Convert milliseconds to radians
  potentLEG = int(amplitude * sineValue + center);

  // Handle reaching limits (optional)
  if (potentLEG > _upperPosition) {
    potentLEG = _upperPosition;
    _state = 1;  // Can be used to trigger additional actions if needed
  } else if (potentLEG < _lowerPosition) {
    potentLEG = _lowerPosition;
    _state = 0;
  }

  return potentLEG;
}
void polinom(){

}


// Функция управления пневматическими цилиндрами в зависимости от положения тумблеров
void pneumaticCulyndr()
{
    // Управление цилиндром левой ноги в зависимости от положения левого тумблера

        if (getTumblerLeft() == 2)
        {
            digitalWrite(PIN_CYLIN_LEG2, HIGH);
            digitalWrite(PIN_CYLIN_LEG1, LOW);
        }
        else if (getTumblerLeft() == 1)
        {
            digitalWrite(PIN_CYLIN_LEG2, LOW);
            digitalWrite(PIN_CYLIN_LEG1, HIGH);
        }
        else
        {
            digitalWrite(PIN_CYLIN_LEG2, LOW);
            digitalWrite(PIN_CYLIN_LEG1, LOW);
        }

        // Управление цилиндром правого колена в зависимости от положения правого тумблера
        if (getTumlerRight() == 2)
        {
            digitalWrite(PIN_CYLIN_KNEE2, HIGH);
            digitalWrite(PIN_CYLIN_KNEE1, LOW);
        }
        else if (getTumlerRight() == 1)
        {
            digitalWrite(PIN_CYLIN_KNEE2, LOW);
            digitalWrite(PIN_CYLIN_KNEE1, HIGH);
        }
        else
        {
            digitalWrite(PIN_CYLIN_KNEE2, LOW);
            digitalWrite(PIN_CYLIN_KNEE1, LOW);
        }
    }
   /* else{
          Serial.println(pila());
        // sinus();
        // polinom();
    } */
