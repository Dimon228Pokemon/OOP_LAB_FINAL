#include <gtest/gtest.h>
#include "lib.h"

TEST(Try_to_calculate, String_InputRows) {
  string rows = "abc";
  string cols = "5";
  int result = Try_to_calculate(rows,cols);
  ASSERT_EQ(0,result);
}
TEST(Try_to_calculate, String_InputCols) {
  string rows = "10";
  string cols = "abc";
  int result = Try_to_calculate(rows,cols);
  ASSERT_EQ(0,result);
}
TEST(Try_to_calculate, Double_InputRows) {
  string rows = "7.34";
  string cols = "5";
  int result = Try_to_calculate(rows,cols);
  ASSERT_EQ(0,result);
}
TEST(Try_to_calculate, Double_InputCals) {
  string rows = "5";
  string cols = "7.34";
  int result = Try_to_calculate(rows,cols);
  ASSERT_EQ(0,result);
}
TEST(Try_to_calculate, True_Result) {
  string rows = "5";
  string cols = "5";
  int result = Try_to_calculate(rows,cols);
  ASSERT_EQ(24,result);
}
TEST(Try_to_calculate, True_Result_ExoticExample) {
  string rows = "1";
  string cols = "1";
  int result = Try_to_calculate(rows,cols);
  ASSERT_EQ(0,result);
}
TEST(Try_to_calculate, True_Result_Example_WithZero) {
  string rows = "0";
  string cols = "0";
  int result = Try_to_calculate(rows,cols);
  ASSERT_EQ(0,result);
}