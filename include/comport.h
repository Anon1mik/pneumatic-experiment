#pragma once

void com() {
    int tumblerOneValue = TUMBLER_ONE(); // Получение значения переключателя 1
    int tumblerTwoValue = TUMBLER_TWO(); // Получение значения переключателя 2
    int potentsiometrhip = getAngleHip(); // Получение значения угла потенциометра  (бедро)
    int potentsiometrknee = getAngleKnee(); // Получение значения угла потенциометра  (голень)

    Serial.print(potentsiometrhip); // Вывод значения угла потенциометра бедра в последовательный порт
    Serial.print(","); // Вывод разделителя
    Serial.print(potentsiometrknee); // Вывод значения угла потенциометра голени в последовательный порт
    Serial.print(","); // Вывод разделителя
    Serial.print(tumblerOneValue); // Вывод значения переключателя 1 в последовательный порт
    Serial.print(","); // Вывод разделителя
    Serial.print(tumblerTwoValue); // Вывод значения переключателя 2 в последовательный порт
    Serial.print(","); // Вывод разделителя

    // Проверка условия и вывод соответствующего сообщения в последовательный порт
    if (potentsiometrhip > 500 && potentsiometrknee < 500) {
        Serial.println("Тестовое включение");
    } else {
        Serial.println("Тестовое выключение");
    }
}
