#include "gpslib_coordinate.h"

/**
* a constructor
* @param t_latitude a Coordinate class corresponding to a latitude
* @param t_longitude a Coordinate class corresponding to a longitude
*/
GPSLib::Coordinate::Coordinate(Latitude t_latitude, Longitude t_longitude): m_latitude(t_latitude), m_longitude(t_longitude){}

/**
* a constructor
* @param t_latitude a decimal corresponding to the latitude
* @param t_longitude a decimal class corresponding to the longitude
*/
GPSLib::Coordinate::Coordinate(float t_latitude, float t_longitude): m_latitude(t_latitude), m_longitude(t_longitude){}

/**
* copy constructor
* @param t_coordinate_point a CoordinatePoint class to copy
*/
GPSLib::Coordinate::Coordinate(const Coordinate* t_coordinate_point){
    m_latitude = t_coordinate_point->getLatitude();
    m_longitude = t_coordinate_point->getLongitude();
}

/**
* copy operator
* @param t_coordinate_point a CoordinatePoint class to copy
*/
Latitude GPSLib::Coordinate::operator=(const Coordinate* t_coordinate_point){
    m_latitude = t_coordinate_point->getLatitude();
    m_longitude = t_coordinate_point->getLongitude();
}

/**
* set the latitude of the coordinate point
* @param t_latitude a Coordinate class corresponding to a latitude
*/
void GPSLib::Coordinate::setLatitude(Latitude t_latitude){m_latitude = t_latitude;}

/**
* set the longitude of the coordinate point
* @param t_longitude a Coordinate class corresponding to a longitude
*/
void GPSLib::Coordinate::setLongitude(Longitude t_longitude){m_lonfitude = t_longitude;}

/**
* get the latitude of the coordinate point
* @preturn  the Coordinate class corresponding to the latitude
*/
GPSLib::Latitude GPSLib::Coordinate::getLatitude(){return m_latitude;}

/**
* get the longitude of the coordinate point
* @preturn  the Coordinate class corresponding to the longitude
*/
GPSLib::Longitude GPSLib::Coordinate::getLongitude(){return m_longitude;}

/**
* check if the coordinate is a valid. Meaning, longitude AND latitude must be valid.
* @return Wether the coordinate point is valid or not.
*/
bool GPSLib::Coordinate::isValid(){return true;}
