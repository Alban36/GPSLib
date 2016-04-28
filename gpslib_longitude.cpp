#include <cmath>
#include "gpslib_longitude.h"

/**
* a constructor
* @param t_degrees degrees of the longitude
* @param t_minutes minutes of the longitude
* @param t_seconds seconds of the longitude
* @param t_cardinal_point cardinal point of the longitude
*/
GPSLib::Longitude::Longitude(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point): m_degrees(t_degrees),
                                                                                                m_minutes(t_minutes),
                                                                                                m_seconds(t_seconds),
                                                                                                m_cardinal_point(t_cardinal_point)
{
    m_validity = m_validate();
}

/**
* a constructor
* @param t_degrees degrees of the longitude
* @param t_minutes minutes of the longitude
* @param t_seconds seconds of the longitude
* @param t_cardinal_point cardinal point of the longitude
*/
GPSLib::Longitude::Longitude(double t_decimal_value){m_validity = m_convertFromDecimal(t_decimal_value);}

GPSLib::Longitude::~Longitude(){}

//getters

/**
* Get the degrees of the longitude
* @return the degrees of the longitude
*/
int8_t GPSLib::Longitude::getDegrees(){return m_degrees;}

/**
* Get the minutes of the longitude
* @return the minutes of the longitude
*/
int8_t GPSLib::Longitude::getMinutes(){return m_minutes;}

/**
* Get the seconds of the longitude
* @return the seconds of the longitude
*/
double GPSLib::Longitude::getSeconds(){return m_seconds;}

/**
* Get the cardinal point of the longitude
* @return the cardinal point of the longitude
*/
GPSLib::CardinalPoint GPSLib::Longitude::getCardinalPoint(){return m_cardinal_point;}

/**
* return the decimal value of the longitude
* @return the longitude as a decimal value
*/
double GPSLib::Longitude::asDecimal()
{
    double decimal_value = (double)m_degrees + ((double)m_minutes / 60.0) + (m_seconds / 3600.0);
    if(m_cardinal_point == GPSLib::WEST)
    {
        decimal_value = decimal_value * -1;
    }
    return decimal_value;
}

/**
* Indicate if the current longitude is valid
* @return true if valid, false otherwise
*/
bool GPSLib::Longitude::isValid(){return m_validity;}


bool GPSLib::Longitude::m_convertFromDecimal(double t_decimal_coordinate)
{
    double abs_decimal_coordinate = std::abs(t_decimal_coordinate);

    m_degrees = (int8_t)trunc(abs_decimal_coordinate);
    abs_decimal_coordinate -= (double)m_degrees;
    double temp_minutes = abs_decimal_coordinate * 60.0;
    m_minutes = (int8_t)trunc(temp_minutes);
    abs_decimal_coordinate -= (double)m_minutes / 60.0;
    m_seconds = abs_decimal_coordinate * 3600.0;

    if(t_decimal_coordinate >= 0)
    {
        m_cardinal_point = GPSLib::EAST;
    }
    else
    {
        m_cardinal_point = GPSLib::WEST;
    }

    return m_validate();
}

bool GPSLib::Longitude::m_validate()
{
    bool isValid = false;
    double angle = m_degrees + (m_minutes / 60) + (m_seconds / 3600);

    if((angle <= 180.0)&&((m_cardinal_point == GPSLib::WEST)||(m_cardinal_point == GPSLib::EAST)))
    {
        isValid = true;
    }
    return isValid;
}

