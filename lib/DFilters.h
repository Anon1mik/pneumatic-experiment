#pragma once

// Класс фильтра "Экспоненциальное бегущее среднее"
// Фильтрованное значение += (новое - фильтрованное) * коэффициент
template < typename VAR_TYPES >
class ERA_filter{
    public:
        ERA_filter(VAR_TYPES coef){
            _coef = coef;
        }

        VAR_TYPES filtered (VAR_TYPES value){
            _value = value;
            _output += (_value - _output) * _coef;
            return _output;
        }

    private:
        VAR_TYPES _coef;
        VAR_TYPES _value;
        VAR_TYPES _output;    
};

// Класс фильтра "Бегущее среднее арифметическое"
// Рассчитывается как среднее от буфера размером SIZE
template < typename VAR_TYPES, int SIZE >
class RA_filter{
    public: 
        VAR_TYPES filtered(VAR_TYPES value){
            if(++_counter >= SIZE) _counter = 0;
            _avarage -= _values[_counter];
            _avarage += value;
            _values[_counter] = value;
            return _avarage / SIZE;
        }

    private:
        VAR_TYPES _values[SIZE];
        int _counter = 0;
        VAR_TYPES _avarage = 0;
};

// Класс фильтра "Медиана заданного порядка"
// Выбирает среднее среди SIZE числа элементов
template < typename VAR_TYPES, int SIZE >
class Median_filter{
    public:
        VAR_TYPES filtered(VAR_TYPES value) {
            buffer[_count] = value;
            if((_count < _order - 1) && (buffer[_count] > buffer[_count + 1])){
                for(int i = _count; i < _order - 1; i++){
                    if(buffer[i] > buffer[i + 1]){
                        VAR_TYPES buff = buffer[i];
                        buffer[i] = buffer[i + 1];
                        buffer[i + 1] = buff;
                    }
                }
            } 
            else{
                if((_count > 0) and (buffer[_count - 1] > buffer[_count])){
                    for(int i = _count; i > 0; i--){
                        if(buffer[i] < buffer[i - 1]){
                            VAR_TYPES buff = buffer[i];
                            buffer[i] = buffer[i - 1];
                            buffer[i - 1] = buff;
                        }
                    }
                }
            }
            if (++_count >= _order) _count = 0;
            return buffer[(int)_order / 2];
        }
    private:
        VAR_TYPES buffer[SIZE];
        byte _count = 0;
        byte _order = SIZE;
};

// Класс фильтра Калмана
template < typename VAR_TYPES >
class Kalman_filter{
    public:
        Kalman_filter(VAR_TYPES spread, VAR_TYPES rate){
            _spread = spread;
            _rate = rate;
        }

        VAR_TYPES filtered(VAR_TYPES value){
            VAR_TYPES _kalman_gain, _current_estimate;
            static VAR_TYPES _error_estimate = _spread;
            static VAR_TYPES _last_estimate;

            _kalman_gain = (VAR_TYPES)_error_estimate / (_error_estimate + _spread);
            _current_estimate = _last_estimate + (VAR_TYPES)_kalman_gain * (value - _last_estimate);
            _error_estimate =  (1.0 - _kalman_gain) * _error_estimate + fabs(_last_estimate - _current_estimate) * _rate;
            _last_estimate = _current_estimate;
            return _current_estimate;
        }

    private:
        VAR_TYPES _spread;
        VAR_TYPES _rate;
};