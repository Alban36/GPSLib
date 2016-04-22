#include "gpslib_latitude.h"

/**
* a constructor
* @param t_degrees degrees of the latitude
* @param t_minutes minutes of the latitude
* @param t_seconds seconds of the latitude
* @param t_cardinal_point cardinal point of the latitude
*/
GPSLib::Latitude::Latitude(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point): m_degrees(t_degrees),
                                                                                                m_minutes(t_minutes),
                                                                                                m_seconds(t_seconds),
                                                                                                m_cardinal_point(t_cardinal_point)
{
    m_validity = m_validate();
}

/**
* a constructor
* @param t_decimal_value a decimal value representing a latitude
*/
GPSLib::Latitude::Latitude(float t_decimal_value){m_validity = m_convertFromDecimal(t_decimal_value);}

GPSLib::Latitude::~Latitude(){}

//getters

/**
* Get the degrees of the latitude
* @return the degrees of the latitude
*/
int8_t GPSLib::Latitude::getDegrees(){return m_degrees;}

/**
* Get the minutes of the latitude
* @return the minutes of the latitude
*/
int8_t GPSLib::Latitude::getMinutes(){return m_minutes;}

/**
* Get the seconds of the latitude
* @return the seconds of the latitude
*/
int8_t GPSLib::Latitude::getSeconds(){return m_seconds;}

/**
* Get the cardinal point of the latitude
* @return the cardinal point of the latitude
*/
GPSLib::CardinalPoint GPSLib::Latitude::getCardinalPoint(){return m_cardinal_point;}

/**
* return the decimal value of the latitude
* @return the latitude as a decimal value
*/
float GPSLib::Latitude::asDecimal()
{
    return 0.0;
}

/**
* Indicate if the current latitude is valid
* @return true if valid, false otherwise
*/
bool GPSLib::Latitude::isValid(){return m_validity;}


bool GPSLib::Latitude::m_convertFromDecimal(float t_decimal_coordinate)
{
    m_degrees = (int8_t)trunc(t_decimal_coordinate);
    float temp_minutes = (t_decimal_coordinate - (float)m_degrees) * 60;
    m_minutes = (int8_t)trunc(temp_minutes);
    float temp_seconds = (t_decimal_coordinate - (float)m_minutes) * 60;
    m_seconds = (int8_t)trunc(temp_seconds);

    if(t_decimal_coordinate > 0)
    {
        m_cardinal_point = GPSLib::NORTH;
    }
    else
    {
        m_cardinal_point = GPSLib::SOUTH;
    }

    return m_validate();
}

bool GPSLib::Latitude::m_validate()
{
    bool isValid = false;
    float angle = m_degrees + (m_minutes / 60) + (m_seconds / 3600);

    if((angle <= 90.0)&&((m_cardinal_point == GPSLib::NORTH)||(m_cardinal_point == GPSLib::SOUTH)))
    {
        isValid = true;
    }
    return isValid;
}
