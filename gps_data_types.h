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
* a class that represent a coordinate that can be a latitude or a longitude or neither of those two. If that the case, the coordinate is considered as invalid.
*/
class Coordinate{
	public:
		/**
		* a constructor
		* @param t_degrees degrees of the coordinate
		* @param t_minutes minutes of the coordinate
		* @param t_seconds seconds of the coordinate
		* @param t_cardinal_point cardinal point of the coordinate
		*/
		Coordinate(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point):m_degrees(t_degrees),
														 m_minutes(t_minutes),
			 											 m_seconds(t_seconds),
														 m_cardinal_point(t_cardinal_point){}

		/**
		* a constructor
		* @param t_degrees degrees of the coordinate
		* @param t_minutes minutes of the coordinate
		* @param t_seconds seconds of the coordinate
		* @param t_cardinal_point cardinal point of the coordinate
		*/
		Coordinate(float t_decimal_value, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point):m_degrees(t_degrees),
														 m_minutes(t_minutes),
			 											 m_seconds(t_seconds),
														 m_cardinal_point(t_cardinal_point){}
		int8_t getDegrees();
		int8_t getMinutes();
		int8_t getSeconds();
		CardinalPoint getCardinalPoint();
		void setDegrees(int8_t t_degrees);
		void setMinutes(int8_t t_minutes);
		void setSeconds(int8_t t_seconds);
		void setCardinalPoint(CardinalPoint t_cardinal_point);

		float asDecimal();
		bool isValidLatitude();
		bool isValidLongitude();
	private:
		bool m_convertFromDecimal(float t_decimal_coordinate);
		int8_t m_degrees;
		int8_t m_minutes;
		int8_t m_seconds;
		CardinalPoint m_cardinal_point;
};

/**
* a class that define a coordinate point which consist of a latitude and a longitude
*/
class CoordinatePoint{
	public:
		/**
		* a constructor
		* @param t_latitude a Coordinate class corresponding to a latitude
		* @param t_longitude a Coordinate class corresponding to a longitude	
		*/
		CoordinatePoint(Coordinate t_latitude, Coordinate t_longitude): m_latitude(t_latitude), m_longitude(t_longitude){}
		
		/**
		* a constructor
		* @param t_latitude a decimal corresponding to the latitude
		* @param t_longitude a decimal class corresponding to the longitude	
		*/
		CoordinatePoint(float t_latitude, float t_longitude): m_latitude(t_latitude), m_longitude(t_longitude){}

		/**
		* copy constructor
		* @param t_coordinate_point a CoordinatePoint class to copy
		*/
		CoordinatePoint(const CoordinatePoint* t_coordinate_point){
			m_latitude = CoordinatPoint->getLatitude();
			m_longitude = CoordinatPoint->getLongitude();
		}
		
		/**
		* copy operator
		* @param t_coordinate_point a CoordinatePoint class to copy
		*/
		operator=(const CoordinatePoint* t_coordinate_point){
			m_latitude = CoordinatPoint->getLatitude();
			m_longitude = CoordinatPoint->getLongitude();
		}

		/**
		* set the latitude of the coordinate point
		* @param t_latitude a Coordinate class corresponding to a latitude	
		*/
		void setLatitude(Coordinate t_latitude){m_latitude = t_latitude;}

		/**
		* set the longitude of the coordinate point
		* @param t_longitude a Coordinate class corresponding to a longitude	
		*/
		void setLongitude(Coordinate t_longitude){m_lonfitude = t_longitude};

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
		Coordinate m_latitude;
		Coordinate m_longitude;
};

}; 
