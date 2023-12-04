#pragma once

#include <algorithm>
#include <cstring>
#include <fstream>
#include <initializer_list>
#include <iostream>
#include <string>

using namespace std;

class Six {
  public:
   Six();

   Six(const size_t& n, unsigned char t = 0);

   Six(const std::initializer_list<unsigned char>& t);

   Six(const std::string& t);

   Six(const Six& other);

   Six(Six&& other) noexcept;

   Six operator+(const Six& array) const;

   Six operator-(const Six& array);

   void one_in_mind(unsigned char* arr1, unsigned char* arr2, size_t n,
                    size_t position);

   Six& operator=(const Six& array);

   bool operator==(const Six& array) const;

   bool operator<(const Six& array) const;

   bool operator>(const Six& array) const;

   static Six fromFile(const char* name);

   void serialize(const char* name);

   void print();

   unsigned char* get_array();

   size_t get_size();

   string getValue();

   virtual ~Six() noexcept;

  private:
   size_t _size;
   unsigned char* _array;
};