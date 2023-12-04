#include <gtest/gtest.h>
#include "sixarray.h"

TEST(Constructor, Default) {
   Six object;
   size_t result_size = 0;
   unsigned char *result_array = nullptr;
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.get_array(), result_array);
}

TEST(Constructor, Fill_in_the_repeat) {
   Six object(5, 0);
   size_t result_size = 5;
   string result_array = "00000";
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.getValue(), result_array);
}

TEST(Constructor, Initializer_list) {
   Six object({5, 0, 1});
   size_t result_size = 3;
   string result_array = "501";
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.getValue(), result_array);
}

TEST(Constructor, Initializer_list_Exeption) {
   char exeption[]{"ERROR. The diger of number is greater than 6."};
   try {
      Six object({6, 0, 1});
   } catch (const char *errStr) {
      ASSERT_STREQ(exeption, errStr);
   }
}

TEST(Constructor, String) {
   Six object("25");
   size_t result_size = 2;
   string result_array = "25";
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.getValue(), result_array);
}

TEST(Constructor, String_input_zeros_in_front) {
   Six object("001");
   size_t result_size = 1;
   string result_array = "1";
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.getValue(), result_array);
}

TEST(Constructor, String_Exemption) {
   char exeption[]{"ERROR. The diger of number is greater than 6."};
   try {
      Six object("27");
   } catch (const char *errStr) {
      ASSERT_STREQ(exeption, errStr);
   }
}

TEST(Constructor, Other_object_list) {
   Six other({5, 0, 1});
   Six object(other);
   size_t result_size = 3;
   string result_array = "501";
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.getValue(), result_array);
}

TEST(Constructor, Other_object_string) {
   Six other("501");
   Six object(other);
   size_t result_size = 3;
   string result_array = "501";
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.getValue(), result_array);
}

TEST(Constructor, Other_object_rvalue) {
   Six other("501");
   Six object(move(other));
   size_t result_size = 3;
   string result_array = "501";
   ASSERT_EQ(object.get_size(), result_size);
   ASSERT_EQ(object.getValue(), result_array);
}

TEST(Operators, Equality) {
   Six origin("5");
   Six copy = origin;
   string result_copy = "5";
   ASSERT_EQ(copy.getValue(), result_copy);
}

TEST(Operators, Plus_Default) {
   Six a("500");
   Six b("25");
   Six sum_object = a + b;
   string sum_result = "525";
   ASSERT_EQ(sum_object.getValue(), sum_result);
}

TEST(Operators, Plus_Changing_the_digits) {
   Six a("501");
   Six b("25");
   Six sum_object = a + b;
   string sum_result = "530";
   ASSERT_EQ(sum_object.getValue(), sum_result);
}

TEST(Operators, Plus_with_zero) {
   Six a("0000001");
   Six b("02");
   Six sum_object = a + b;
   string sum_result = "3";
   ASSERT_EQ(sum_object.getValue(), sum_result);
}

TEST(Operators, Minus_Default) {
   Six a("525");
   Six b("25");
   Six difference_object = a - b;
   string difference_result = "500";
   ASSERT_EQ(difference_object.getValue(), difference_result);
}

TEST(Operators, Minus_with_zero) {
   Six a("0000525");
   Six b("0025");
   Six difference_object = a - b;
   string difference_result = "500";
   ASSERT_EQ(difference_object.getValue(), difference_result);
}

TEST(Operators, Zero) {
   Six a("525");
   Six b("525");
   Six difference_object = a - b;
   string difference_result = "0";
   ASSERT_EQ(difference_object.getValue(), difference_result);
}

TEST(Operators, Negative_exeption) {
   char exeption[]{"ERROR. The result of the operation is a negative number"};
   try {
      Six a("4");
      Six b("5");
      Six difference_object = a - b;
   } catch (const char *errStr) {
      ASSERT_STREQ(exeption, errStr);
   }
}

TEST(Operators, Identical_equality_T) {
   Six a("525");
   Six b("525");
   bool flag = a == b;
   bool result_flag = true;
   ASSERT_EQ(flag, result_flag);
}

TEST(Operators, Identical_equality_F) {
   Six a("524");
   Six b("525");
   bool flag = a == b;
   bool result_flag = false;
   ASSERT_EQ(flag, result_flag);
}

TEST(Operators, Less_T) {
   Six a("524");
   Six b("525");
   bool flag = a < b;
   bool result_flag = true;
   ASSERT_EQ(flag, result_flag);
}

TEST(Operators, Less_equality_F) {
   Six a("525");
   Six b("525");
   bool flag = a < b;
   bool result_flag = false;
   ASSERT_EQ(flag, result_flag);
}

TEST(Operators, Less_F) {
   Six a("524");
   Six b("525");
   bool flag = b < a;
   bool result_flag = false;
   ASSERT_EQ(flag, result_flag);
}

TEST(Operators, More_T) {
   Six a("524");
   Six b("525");
   bool flag = b > a;
   bool result_flag = true;
   ASSERT_EQ(flag, result_flag);
}

TEST(Operators, More_equality_F) {
   Six a("525");
   Six b("525");
   bool flag = a > b;
   bool result_flag = false;
   ASSERT_EQ(flag, result_flag);
}

TEST(Operators, More_F) {
   Six a("524");
   Six b("525");
   bool flag = a > b;
   bool result_flag = false;
   ASSERT_EQ(flag, result_flag);
}

TEST(File_work, serialize_and_desserialize)
{
   Six object("1200");
   object.serialize("object.txt");
   Six tmp_obj = Six::fromFile("object.txt");
   string answer = tmp_obj.getValue();
   string result_answer = "1200";
   ASSERT_EQ(answer, result_answer);
}
