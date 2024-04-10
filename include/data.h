#pragma once

void printData() {
     Serial.print(getTumblerLeft()); // Вывод значения угла потенциометра бедра в последовательный порт
     Serial.print(","); // Вывод разделителя
     Serial.print(getTumlerRight()); // Вывод значения угла потенциометра голени в последовательный порт
     Serial.print(","); // Вывод разделителя
     Serial.print(getAngleHip()); // Вывод значения переключателя 1 в последовательный порт
     Serial.print(","); // Вывод разделителя
     Serial.print(buttonState); // Вывод состояние кнопки
     Serial.print(","); // Вывод разделителя
     Serial.print(getSaw(1.0, 100.0, 50.0)); // частота, нижняя позиция, в ерхняя позиция
     Serial.print(","); // Вывод разделителя
     Serial.print(sinus(1.0, 1100, 1100)); // частота, амплитуда, центр 
     Serial.print(","); // Вывод разделителя
     Serial.println(polinom3(5000, 1000, 0)); // время цикла, нижняя позиция, верхняя позиция.
     Serial.print(","); // Вывод разделителя
     Serial.print(buttonState);
     Serial.print(","); // Вывод разделителя
     Serial.println(getAngleKnee()); // Вывод значения переключателя 2 в последовательный порт
}
