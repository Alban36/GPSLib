#include <cstdint>
#include "gpslib_data_types.h"


#ifndef GPSLIB_LONGITUDE_H
#define GPSLIB_LONGITUDE_H

namespace GPSLib{

/**
* a class that represent a longitude.
*/
class Longitude{
    public:
        Longitude(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point);
        Longitude(float t_decimal_value);

        ~Longitude();

        //getters
        int8_t getDegrees();
        int8_t getMinutes();
        int8_t getSeconds();
        CardinalPoint getCardinalPoint();

        //converter
        float asDecimal();

        //checker
        bool isValid();

    private:
        //Methods
        bool m_convertFromDecimal(float t_decimal_coordinate);
        bool m_validate();

        //Attributes
        int8_t m_degrees;
        int8_t m_minutes;
        int8_t m_seconds;
        CardinalPoint m_cardinal_point;

        bool m_validity;
};

}

#endif // GPSLIB_LONGITUDE_H
