#pragma once
#include <cmath>
#include <iostream>
#include <string>
using namespace std;

struct Point {
   double x;
   double y;
   Point() : x(0), y(0) {}
   ~Point() = default;

   std::string Get() 
   { 
	std::string sx = std::to_string(this->x) ;
	std::string sy = std::to_string(this->y);
	std::string s;
	s.append(sx).append(" ").append(sy);
	return s;
   }

  protected:
   friend std::ostream& operator<<(std::ostream& output, const Point& pt) {
      output << "(" << round(pt.x * 100) / 100 << ", "
             << round(pt.y * 100) / 100 << ")";
      return output;
   }
};
