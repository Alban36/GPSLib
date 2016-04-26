#include "gtest/gtest.h"
#include "gpslib_latitude.h"

using namespace GPSLib;

/*constructor_test_1
  Check the constructor with signature Latitude(int8_t t_degrees, int8_t t_minutes, int8_t t_seconds, CardinalPoint t_cardinal_point)
*/
TEST(LatitudeTest, constructor_test_1){
    //nominal case
    //AC : is it useful might be more pertinent to test the validity of the whole range of valid data.
    Latitude latitude_test_object(0, 0, 0, NORTH);
    EXPECT_EQ(0, latitude_test_object.getDegrees()) << "The m_degrees attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object.getMinutes()) << "The m_minutes attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object.getSeconds()) << "The m_seconds attribute has not been set correctly by the constructor";
    EXPECT_EQ(NORTH, latitude_test_object.getCardinalPoint()) << "The m_cardinal_point attribute has not been set correctly by the constructor";
    EXPECT_TRUE(latitude_test_object.isValid()) << "This latitude is not valid even thought it should be";

    //limit values of validity
    Latitude latitude_test_object_max(90, 0, 0, NORTH);
    EXPECT_EQ(90, latitude_test_object_max.getDegrees()) << "The m_degrees attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object_max.getMinutes()) << "The m_minutes attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object_max.getSeconds()) << "The m_seconds attribute has not been set correctly by the constructor";
    EXPECT_EQ(NORTH, latitude_test_object_max.getCardinalPoint()) << "The m_cardinal_point attribute has not been set correctly by the constructor";
    EXPECT_TRUE(latitude_test_object_max.isValid()) << "This latitude is not valid even thought it should be";

    Latitude latitude_test_object_min(90, 0, 0, SOUTH);
    EXPECT_EQ(90, latitude_test_object_min.getDegrees()) << "The m_degrees attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object_min.getMinutes()) << "The m_minutes attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object_min.getSeconds()) << "The m_seconds attribute has not been set correctly by the constructor";
    EXPECT_EQ(SOUTH, latitude_test_object_min.getCardinalPoint()) << "The m_cardinal_point attribute has not been set correctly by the constructor";
    EXPECT_TRUE(latitude_test_object_min.isValid()) << "This latitude is not valid even thought it should be";

    //over limit values of validity
    Latitude latitude_test_object_over_max(90, 0, 1, NORTH);
    EXPECT_EQ(90, latitude_test_object_over_max.getDegrees()) << "The m_degrees attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object_over_max.getMinutes()) << "The m_minutes attribute has not been set correctly by the constructor";
    EXPECT_EQ(1, latitude_test_object_over_max.getSeconds()) << "The m_seconds attribute has not been set correctly by the constructor";
    EXPECT_EQ(NORTH, latitude_test_object_over_max.getCardinalPoint()) << "The m_cardinal_point attribute has not been set correctly by the constructor";
    EXPECT_FALSE(latitude_test_object_over_max.isValid()) << "This latitude is not valid even thought it should be";

    Latitude latitude_test_object_below_min(90, 0, 1, SOUTH);
    EXPECT_EQ(90, latitude_test_object_below_min.getDegrees()) << "The m_degrees attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object_below_min.getMinutes()) << "The m_minutes attribute has not been set correctly by the constructor";
    EXPECT_EQ(1, latitude_test_object_below_min.getSeconds()) << "The m_seconds attribute has not been set correctly by the constructor";
    EXPECT_EQ(SOUTH, latitude_test_object_below_min.getCardinalPoint()) << "The m_cardinal_point attribute has not been set correctly by the constructor";
    EXPECT_FALSE(latitude_test_object_below_min.isValid()) << "This latitude is not valid even thought it should be";
}


/*constructor_test_2
  Check the constructor with signature Latitude(float t_decimal_value)
*/
TEST(LatitudeTest, constructor_test_2){
    //nominal case
    Latitude latitude_test_object(0.0);
    EXPECT_EQ(0, latitude_test_object.getDegrees()) << "The m_degrees attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object.getMinutes()) << "The m_minutes attribute has not been set correctly by the constructor";
    EXPECT_EQ(0, latitude_test_object.getSeconds()) << "The m_seconds attribute has not been set correctly by the constructor";
    EXPECT_EQ(NORTH, latitude_test_object.getCardinalPoint()) << "The m_cardinal_point attribute has not been set correctly by the constructor";
    EXPECT_TRUE(latitude_test_object.isValid()) << "This latitude is not valid even thought it should be";
}
