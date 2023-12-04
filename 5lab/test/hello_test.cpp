#include <gtest/gtest.h>
#include "DequeAllocator.h"
#include "Stack.h"
#include <map>
#include <stack>

TEST(Map_Deque_Allocator,factorial)
{
    std::map<int, int, std::less<int>, DequeAllocator< std::pair<const int, int>, 10> > my_map;
    my_map[5] = 120;
    my_map[9] = 362880;
    int Fac5 = my_map[5];
    int Fac9 = my_map[9];
    int res1 = 120;
    int res2 = 362880;
    ASSERT_EQ(Fac5,res1);
    ASSERT_EQ(Fac9,res2);
}

TEST(StackTest, Push_Size) 
{
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);

  ASSERT_EQ(stack.size(), 3);
}
TEST(StackTest, Top) 
{
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  int Top = stack.top();
  int res = 3;
  ASSERT_EQ(Top, res);
}
TEST(StackTest, Pop) 
{
  Stack<int> stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  stack.pop();
  int top_pop = stack.top();
  int res = 2;
  ASSERT_EQ(top_pop, res);
}
TEST(Map_Deque_Allocator_double,factorial)
{
    std::map<double, double, std::less<double>, DequeAllocator< std::pair<const double, double>, 10> > my_map;
    my_map[5.0] = 120.0;
    my_map[9.0] = 362880.0;
    double Fac5 = my_map[5.0];
    double Fac9 = my_map[9.0];
    double res1 = 120.0;
    double res2 = 362880.0;
    ASSERT_EQ(Fac5,res1);
    ASSERT_EQ(Fac9,res2);
}

TEST(StackTest_double, Push_Size) 
{
  Stack<double> stack;
  stack.push(1.0);
  stack.push(2.0);
  stack.push(3.0);

  ASSERT_EQ(stack.size(), 3);
}
TEST(StackTest_double, Top) 
{
  Stack<double> stack;
  stack.push(1.0);
  stack.push(2.0);
  stack.push(3.0);
  double Top = stack.top();
  double res = 3.0;
  ASSERT_EQ(Top, res);
}
TEST(StackTest_double, Pop) 
{
  Stack<double> stack;
  stack.push(1.0);
  stack.push(2.0);
  stack.push(3.0);
  stack.pop();
  double top_pop = stack.top();
  double res = 2.0;
  ASSERT_EQ(top_pop, res);
}
