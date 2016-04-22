#include "gpslib_latitude.h"
#include "gpslib_longitude.h"

#ifndef GPSLIB_COORDINATE_H
#define GPSLIB_COORDINATE_H

namespace GPSLib{

/**
* a class that define a coordinate which consist of a latitude and a longitude
*/
class Coordinate{
    public:
        Coordinate(Latitude t_latitude, Longitude t_longitude);
        Coordinate(float t_latitude, float t_longitude);
        Coordinate(const Coordinate* t_coordinate_point);

        Latitude operator=(const Coordinate* t_coordinate_point);

        //setters
        void setLatitude(Latitude t_latitude);
        void setLongitude(Longitude t_longitude);

        //getters
        Latitude getLatitude();
        Longitude getLongitude();

        //checker
        bool isValid();

    private:
        //Attributes
        Latitude m_latitude;
        Longitude m_longitude;
};

}

#endif // GPSLIB_COORDINATE_H
