#include <cmath>

#ifndef GPS_DATA_TYPES_H
#define GPS_DATA_TYPES_H

namespace GPSLib{

/**
* @brief enum type corresponding to the 4 cardinal point.
*/
enum CardinalPoint{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

/**
* a class that represent a latitude.
*/
class Latitude{
    public:
        /**
        * a constructor
        * @param t_degrees degrees of the latitude
        * @param t_minutes minutes of the latitude
        * @param t_seconds seconds of the latitude
        * @param t_cardinal_point cardinal point of the latitude
        */
        Latitude(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point): m_degrees(t_degrees),
                                                                                                        m_minutes(t_minutes),
                                                                                                        m_seconds(t_seconds),
                                                                                                        m_cardinal_point(t_cardinal_point)
        {
            m_validity = m_validate();
        }

        /**
        * a constructor
        * @param t_degrees degrees of the latitude
        * @param t_minutes minutes of the latitude
        * @param t_seconds seconds of the latitude
        * @param t_cardinal_point cardinal point of the latitude
        */
        Latitude(float t_decimal_value){m_validity = m_convertFromDecimal(t_decimal_value);}

        ~Latitude(){}

        //getters

        /**
        * Get the degrees of the latitude
        * @return the degrees of the latitude
        */
        int8_t getDegrees(){return m_degrees;}

        /**
        * Get the minutes of the latitude
        * @return the minutes of the latitude
        */
        int8_t getMinutes(){return m_minutes;}

        /**
        * Get the seconds of the latitude
        * @return the seconds of the latitude
        */
        int8_t getSeconds(){return m_seconds;}

        /**
        * Get the cardinal point of the latitude
        * @return the cardinal point of the latitude
        */
        CardinalPoint getCardinalPoint(){return m_cardinal_point;}

        /**
        * return the decimal value of the latitude
        * @return the latitude as a decimal value
        */
        float asDecimal();

        /**
        * Indicate if the current latitude is valid
        * @return true if valid, false otherwise
        */
        bool isValid(){return m_validity;}

    private:
        //Methods
        bool m_convertFromDecimal(float t_decimal_coordinate)
        {
            m_degrees = (int8_t)trunc(t_decimal_coordinate);
            temp_minutes = (t_decimal_coordinate % m_degrees) * 60;
            m_minutes = (int8_t)trunc(temp_minutes);
            temp_seconds = (t_decimal_coordinate % m_minutes) * 60;
            m_seconds = (int8_t)trunc(temp_seconds);

            if(t_decimal_coordinate > 0)
            {
                m_cardinal_point = CardinalPoint.NORTH;
            }
            else
            {
                m_cardinal_point = CardinalPoint.SOUTH;
            }

            return m_validate();
        }

        bool m_validate()
        {
            bool isValid = false;
            float angle = m_degrees + (m_minutes / 60) + (m_seconds / 3600);

            if((angle <= 90.0)&&((m_cardinal_point == CardinalPoint.NORTH)||(m_cardinal_point == CardinalPoint.SOUTH)))
            {
                isValid = true;
            }
            return isValid;
        }
        //Attributes
        int8_t m_degrees;
        int8_t m_minutes;
        int8_t m_seconds;
        CardinalPoint m_cardinal_point;

        bool m_validity;
};

/**
* a class that represent a longitude.
*/
class Longitude{
    public:
        /**
        * a constructor
        * @param t_degrees degrees of the longitude
        * @param t_minutes minutes of the longitude
        * @param t_seconds seconds of the longitude
        * @param t_cardinal_point cardinal point of the longitude
        */
        Longitude(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point): m_degrees(t_degrees),
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
        Longitude(float t_decimal_value){m_validity = m_convertFromDecimal(t_decimal_value);}

        ~Longitude(){}

        //getters

        /**
        * Get the degrees of the longitude
        * @return the degrees of the longitude
        */
        int8_t getDegrees(){return m_degrees;}

        /**
        * Get the minutes of the longitude
        * @return the minutes of the longitude
        */
        int8_t getMinutes(){return m_minutes;}

        /**
        * Get the seconds of the longitude
        * @return the seconds of the longitude
        */
        int8_t getSeconds(){return m_seconds;}

        /**
        * Get the cardinal point of the longitude
        * @return the cardinal point of the longitude
        */
        CardinalPoint getCardinalPoint(){return m_cardinal_point;}

        /**
        * return the decimal value of the longitude
        * @return the longitude as a decimal value
        */
        float asDecimal()
        {
            float decimal_value = m_degrees + (m_minutes / 60) + (m_seconds / 3600);
            if(m_cardinal_point == CardinalPoint.WEST)
            {
                decimal_value = decimal_value * -1;
            }
            return decimal_value;
        }

        /**
        * Indicate if the current longitude is valid
        * @return true if valid, false otherwise
        */
        bool isValid(){return m_validity;}

    private:
        //Methods
        bool m_convertFromDecimal(float t_decimal_coordinate)
        {
            m_degrees = (int8_t)trunc(t_decimal_coordinate);
            temp_minutes = (t_decimal_coordinate % m_degrees) * 60;
            m_minutes = (int8_t)trunc(temp_minutes);
            temp_seconds = (t_decimal_coordinate % m_minutes) * 60;
            m_seconds = (int8_t)trunc(temp_seconds);

            if(t_decimal_coordinate > 0)
            {
                m_cardinal_point = CardinalPoint.EAST;
            }
            else
            {
                m_cardinal_point = CardinalPoint.WEST;
            }

            return m_validate();
        }

        bool m_validate()
        {
            bool isValid = false;
            float angle = m_degrees + (m_minutes / 60) + (m_seconds / 3600);

            if((angle <= 180.0)&&((m_cardinal_point == CardinalPoint.WEST)||(m_cardinal_point == CardinalPoint.EAST)))
            {
                isValid = true;
            }
            return isValid;
        }

        //Attributes
        int8_t m_degrees;
        int8_t m_minutes;
        int8_t m_seconds;
        CardinalPoint m_cardinal_point;

        bool m_validity;
};


/**
* a class that define a coordinate which consist of a latitude and a longitude
*/
class Coordinate{
	public:
		/**
		* a constructor
		* @param t_latitude a Coordinate class corresponding to a latitude
		* @param t_longitude a Coordinate class corresponding to a longitude	
		*/
        Coordinate(Latitude t_latitude, Longitude t_longitude): m_latitude(t_latitude), m_longitude(t_longitude){}
		
		/**
		* a constructor
		* @param t_latitude a decimal corresponding to the latitude
		* @param t_longitude a decimal class corresponding to the longitude	
		*/
        Coordinate(float t_latitude, float t_longitude): m_latitude(t_latitude), m_longitude(t_longitude){}

		/**
		* copy constructor
		* @param t_coordinate_point a CoordinatePoint class to copy
		*/
        Coordinate(const Coordinate* t_coordinate_point){
            m_latitude = t_coordinate_point->getLatitude();
            m_longitude = t_coordinate_point->getLongitude();
		}
		
		/**
		* copy operator
		* @param t_coordinate_point a CoordinatePoint class to copy
		*/
        operator=(const Coordinate* t_coordinate_point){
            m_latitude = t_coordinate_point->getLatitude();
            m_longitude = t_coordinate_point->getLongitude();
		}

		/**
		* set the latitude of the coordinate point
		* @param t_latitude a Coordinate class corresponding to a latitude	
		*/
        void setLatitude(Latitude t_latitude){m_latitude = t_latitude;}

		/**
		* set the longitude of the coordinate point
		* @param t_longitude a Coordinate class corresponding to a longitude	
		*/
        void setLongitude(Longitude t_longitude){m_lonfitude = t_longitude;}

		/**
		* get the latitude of the coordinate point
		* @preturn  the Coordinate class corresponding to the latitude	
		*/
		Coordinate getLatitude(){return m_latitude;}

		/**
		* get the longitude of the coordinate point
		* @preturn  the Coordinate class corresponding to the longitude	
		*/
		Coordinate getLongitude(){return m_longitude;}

		/**
		* check if the coordinate is a valid. Meaning, longitude AND latitude must be valid.
		* @return Wether the coordinate point is valid or not.
		*/
		bool isValid();

	private:
        Latitude m_latitude;
        Longitude m_longitude;
};

}

#endif //GPS_DATA_TYPES_H
