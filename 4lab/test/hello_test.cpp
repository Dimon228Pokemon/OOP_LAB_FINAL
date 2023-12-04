#include <gtest/gtest.h>
#include "Array.h"
#include "Figure.h"

TEST(setPoints, Triangle_Figure) {
   Triangle<double> f3;
   f3.setPoints({{1, 2}, {3, 2}, {4, 5}});
   std::pair<double, double> result[]{{1.0, 2.0}, {3.0, 2.0}, {4.0, 5.0}};
   for (int i = 0; i < 3; i++) {
      ASSERT_EQ(f3.points[i], result[i]);
   }
}
TEST(setPoints, Hexagon_Figure) {
   Hexagon<double> f6;
   f6.setPoints({{61, 2}, {36, 24}, {47, 75}, {36, 24}, {47, 75}, {36, 24}});
   std::pair<double, double> result[]{{61.0, 2.0},  {36.0, 24.0}, {47.0, 75.0},
                                      {36.0, 24.0}, {47.0, 75.0}, {36.0, 24.0}};
   for (int i = 0; i < 6; i++) {
      ASSERT_EQ(f6.points[i], result[i]);
   }
}
TEST(setPoints, Octagon_Figure) {
   Octagon<double> f8;
   f8.setPoints({{1, 2},
                 {3, 2},
                 {61, 2},
                 {36, 24},
                 {47, 75},
                 {36, 24},
                 {47, 75},
                 {36, 24}});
   std::pair<double, double> result[]{{1.0, 2.0},   {3.0, 2.0},   {61.0, 2.0},
                                      {36.0, 24.0}, {47.0, 75.0}, {36.0, 24.0},
                                      {47.0, 75.0}, {36.0, 24.0}};
   for (int i = 0; i < 8; i++) {
      ASSERT_EQ(f8.points[i], result[i]);
   }
}
TEST(getSquare, Triangle_Figure) {
   Triangle<double> f3;
   f3.setPoints({{1, 2}, {3, 2}, {4, 5}});
   double S = f3.getSquare();
   double result = 1.7320508123552678;
   ASSERT_EQ(S, result);
}
TEST(getSquare, Hexagon_Figure) {
   Hexagon<double> f6;
   f6.setPoints({{61, 2}, {36, 24}, {47, 75}, {36, 24}, {47, 75}, {36, 24}});
   double S = f6.getSquare();
   double result = 2881.2665223719073;
   ASSERT_EQ(S, result);
}
TEST(getSquare, Octagon_Figure) {
   Octagon<double> f8;
   f8.setPoints({{1, 2},
                 {3, 2},
                 {61, 2},
                 {36, 24},
                 {47, 75},
                 {36, 24},
                 {47, 75},
                 {36, 24}});
   double S = f8.getSquare();
   double result = 19.3137085234974;
   ASSERT_EQ(S, result);
}
TEST(getCenter, Triangle_Figure) {
   Triangle<double> f3;
   f3.setPoints({{1, 2}, {3, 2}, {4, 5}});
   std::pair<double, double> C = f3.getCenter();
   double result1 = 2.6666666666666665;
   double result2 = 3.0;
   ASSERT_EQ(C.first, result1);
   ASSERT_EQ(C.second, result2);
}
TEST(getCenter, Hexagon_Figure) {
   Hexagon<double> f6;
   f6.setPoints({{61, 2}, {36, 24}, {47, 75}, {36, 24}, {47, 75}, {36, 24}});
   std::pair<double, double> C = f6.getCenter();
   double result1 = 43.833333333333329;
   double result2 = 37.333333333333329;
   ASSERT_EQ(C.first, result1);
   ASSERT_EQ(C.second, result2);
}
TEST(getCenter, Octagon_Figure) {
   Octagon<double> f8;
   f8.setPoints({{1, 2},
                 {3, 2},
                 {61, 2},
                 {36, 24},
                 {47, 75},
                 {36, 24},
                 {47, 75},
                 {36, 24}});
   std::pair<double, double> C = f8.getCenter();
   double result1 = 33.375;
   double result2 = 28.5;
   ASSERT_EQ(C.first, result1);
   ASSERT_EQ(C.second, result2);
}