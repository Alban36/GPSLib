#include <cmath>
#include <cstdint>
#include "gpslib_data_types.h"

#ifndef GPSLIB_LATITUDE_H
#define GPSLIB_LATITUDE_H

namespace GPSLib{

/**
* a class that represent a latitude.
*/
class Latitude{
    public:
        Latitude(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point);
        Latitude(double t_decimal_value);

        ~Latitude();

        //getters
        int8_t getDegrees();
        int8_t getMinutes();
        double getSeconds();
        CardinalPoint getCardinalPoint();

        //converter
        double asDecimal();

        //validity check
        bool isValid();

    private:
        //Methods
        bool m_convertFromDecimal(double t_decimal_coordinate);
        bool m_validate();
        //Attributes
        int8_t m_degrees;
        int8_t m_minutes;
        double m_seconds;
        CardinalPoint m_cardinal_point;

        bool m_validity;
};
}

#endif // GPSLIB_LATITUDE_H
