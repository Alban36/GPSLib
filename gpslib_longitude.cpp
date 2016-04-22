#include "gpslib_longitude.h"
#include "gpslib_data_types.h"

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
GPSLib::Longitude::Longitude(float t_decimal_value){m_validity = m_convertFromDecimal(t_decimal_value);}

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
int8_t GPSLib::Longitude::getSeconds(){return m_seconds;}

/**
* Get the cardinal point of the longitude
* @return the cardinal point of the longitude
*/
GPSLib::CardinalPoint GPSLib::Longitude::getCardinalPoint(){return m_cardinal_point;}

/**
* return the decimal value of the longitude
* @return the longitude as a decimal value
*/
float GPSLib::Longitude::asDecimal()
{
    float decimal_value = m_degrees + (m_minutes / 60) + (m_seconds / 3600);
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


bool GPSLib::Longitude::m_convertFromDecimal(float t_decimal_coordinate)
{
    m_degrees = (int8_t)trunc(t_decimal_coordinate);
    float temp_minutes = (t_decimal_coordinate - m_degrees) * 60;
    m_minutes = (int8_t)trunc(temp_minutes);
    float temp_seconds = (t_decimal_coordinate - m_minutes) * 60;
    m_seconds = (int8_t)trunc(temp_seconds);

    if(t_decimal_coordinate > 0)
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
    float angle = m_degrees + (m_minutes / 60) + (m_seconds / 3600);

    if((angle <= 180.0)&&((m_cardinal_point == GPSLib::WEST)||(m_cardinal_point == GPSLib::EAST)))
    {
        isValid = true;
    }
    return isValid;
}

