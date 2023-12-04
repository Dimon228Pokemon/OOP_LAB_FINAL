#include <gtest/gtest.h>
#include "F3.h"
#include "F6.h"
#include "F8.h"
#include "Point.h"
#include "ArrayFigure.h"


TEST(Method, getSquare_F3)
{
    F3 f3(0.0, 0.0, 6.0, 0.0, 3.0, 5.2);
    double s = f3.getSquare();
    std::string triangle_s = std::to_string(s);
    std::string result_s = "15.588457";
    ASSERT_EQ(triangle_s, result_s);
}
TEST(Method, getSquare_F6)
{
    F6 f6(0.0, 0.0, 1.0, 0.0, 1.5, 0.866, 1.0, 1.732, 0.0, 1.732, -0.5, 0.866);
    double s = f6.getSquare();
    std::string hexagon_s = std::to_string(s);
    std::string result_s = "2.598076";
    ASSERT_EQ(hexagon_s, result_s);
}
TEST(Method, getSquare_F8)
{
    F8 f8(-1.0, 0.0, -0.707, 0.707, 0.0, 1.0,
     0.707, 0.707, 1.0, 0.0, 0.707, -0.707, 0.0, -1.0, -0.707, -0.707);
    double s = f8.getSquare();
    std::string octagon_s = std::to_string(s);
    std::string result_s = "2.828000";
    ASSERT_EQ(octagon_s, result_s);
}
TEST(Method, getCentr_F3)
{
    F3 f3(0.0, 0.0, 6.0, 0.0, 3.0, 5.2);
    Point p = f3.getCentr();
    std::string point  = p.Get();
    std::string result_p = "3.000000 1.733333";
    ASSERT_EQ(point, result_p);
}
TEST(Method, getCentr_F6)
{
    F6 f6(0.0, 0.0, 1.0, 0.0, 1.5, 0.866, 1.0, 1.732, 0.0, 1.732, -0.5, 0.866);
    Point p = f6.getCentr();
    std::string point  = p.Get();
    std::string result_p = "0.500000 0.866000";
    ASSERT_EQ(point, result_p);
}
TEST(Method, getCentr_F8)
{
    F8 f8(-1.0, 0.0, -0.707, 0.707, 0.0, 1.0,
     0.707, 0.707, 1.0, 0.0, 0.707, -0.707, 0.0, -1.0, -0.707, -0.707);
    Point p = f8.getCentr();
    std::string point  = p.Get();
    std::string result_p = "0.000000 -0.000000";
    ASSERT_EQ(point, result_p);
}
TEST(Method, double_cast_F3)
{
    F3 f3(0.0, 0.0, 6.0, 0.0, 3.0, 5.2);
    double s = static_cast<double>(f3);
    std::string triangle_s = std::to_string(s);
    std::string result_s = "15.588457";
    ASSERT_EQ(triangle_s, result_s);
}
TEST(Method, double_cast_F6)
{
    F6 f6(0.0, 0.0, 1.0, 0.0, 1.5, 0.866, 1.0, 1.732, 0.0, 1.732, -0.5, 0.866);
    double s = static_cast<double>(f6);
    std::string hexagon_s = std::to_string(s);
    std::string result_s = "2.598076";
    ASSERT_EQ(hexagon_s, result_s);
}
TEST(Method, double_cast_F8)
{
    F8 f8(-1.0, 0.0, -0.707, 0.707, 0.0, 1.0,
     0.707, 0.707, 1.0, 0.0, 0.707, -0.707, 0.0, -1.0, -0.707, -0.707);
    double s = static_cast<double>(f8);
    std::string octagon_s = std::to_string(s);
    std::string result_s = "2.828000";
    ASSERT_EQ(octagon_s, result_s);
}
TEST(Method, Copy_1)
{
    F3 f3(0.0, 0.0, 6.0, 0.0, 3.0, 5.2);
    F3 f3_1(f3);
    EXPECT_TRUE(f3==f3_1);
}
TEST(Operator, Copy_2)
{
    F3 f3(0.0, 0.0, 6.0, 0.0, 3.0, 5.2);
    F3 f3_1(5.0, 5.0, 0.0, 7.0, 0.0, 9.0);
    f3_1=f3;
    EXPECT_TRUE(f3==f3_1);
}
TEST(Class, totalSquare)
{
    ArrayFigure arrF;
    arrF.add(new F3(0, 0, 3, 3, 4, 2));
    arrF.add(new F6(0.0, 0.0, 1.0, 0.0, 1.5, 0.866, 1.0, 1.732, 0.0, 1.732, -0.5, 0.866));
    arrF.add(new F8 (-1.0, 0.0, -0.707, 0.707, 0.0, 1.0,
     0.707, 0.707, 1.0, 0.0, 0.707, -0.707, 0.0, -1.0, -0.707, -0.707));
    double s = arrF.getTotalSquare();
    double result_s = 13.220305;
    ASSERT_EQ(std::to_string(s), std::to_string(result_s));
}
