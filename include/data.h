#pragma once

void printData() {
     Serial.print(getTumblerLeft()); // Вывод значения угла потенциометра бедра в последовательный порт
     Serial.print(","); // Вывод разделителя
     Serial.print(getTumlerRight()); // Вывод значения угла потенциометра голени в последовательный порт
     Serial.print(","); // Вывод разделителя
     Serial.print(getAngleHip()); // Вывод значения переключателя 1 в последовательный порт
     Serial.print(",");
     Serial.print(pila(60.0,100,1100)); // частота, нижняя позиция, верхняя позиция
     Serial.print(","); // Вывод разделителя
     Serial.print(sinus(1.0, 1100, 1100)); // частота, амплитуда, центр 
     Serial.print(","); // Вывод разделителя
     Serial.print(polinom(10 * 1000000, 0, 1100)); // время цикла, нижняя позиция, верхняя позиция.
     Serial.print(","); // Вывод разделителя
     Serial.print(buttonState);
     Serial.print(",");
     Serial.println(getAngleKnee()); // Вывод значения переключателя 2 в последовательный порт
}
