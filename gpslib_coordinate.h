#include "gpslib_latitude.h"
#include "gpslib_longitude.h"
#include <memory>

#ifndef GPSLIB_COORDINATE_H
#define GPSLIB_COORDINATE_H

namespace GPSLib{

/**
* a class that define a coordinate which consist of a latitude and a longitude
*/
class Coordinate{
    public:
        Coordinate(Latitude* const t_latitude, Longitude* const t_longitude);
        Coordinate(double t_latitude, double t_longitude);
        Coordinate(Coordinate* const t_coordinate_point);

        //Latitude operator=(const Coordinate* t_coordinate_point);

        //setters
        void setLatitude(Latitude* const t_latitude);
        void setLongitude(Longitude* const t_longitude);

        //getters
        Latitude* getLatitude();
        Longitude* getLongitude();

        //checker
        bool isValid();

    private:
        //Attributes
        std::shared_ptr<Latitude> m_latitude;
        std::shared_ptr<Longitude> m_longitude;
};

}

#endif // GPSLIB_COORDINATE_H
