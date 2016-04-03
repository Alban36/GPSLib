namespace GPSLib{

enum CardinalPoint{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class Coordinate{
	public:
	int8_t getDegrees();
	int8_t getMinutes();
	int8_t getSeconds();
	CardinalPoint getCardinalPoint();
	float asDecimal();
	private:
	int8_t m_degrees;
	int8_t m_minutes;
	int8_t m_seconds;
	CardinalPoint m_cardinal_point;
};

class CoordinatePoint{
	public:
	CoordinatePoint(Coordinate t_latitude, Coordinate t_longitude);
	CoordinatePoint(float t_latitude, float t_longitude);
	CoordinatePoint(const CoordinatePoint* t_coordinate_point);
	
	operator=(const CoordinatePoint* t_coordinate_point);

	Coordinate getLatitude();
	Coordinate getLongitude();

	private:
	Coordinate m_latitude;
	Coordinate m_longitude;
};

}; 
