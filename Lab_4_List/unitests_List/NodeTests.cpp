#include "gtest/gtest.h"
#include ".\Node.h"

TEST(Node, can_create1)
{
  EXPECT_NO_THROW(Node<int>a);
}

TEST(Node, can_create2)
{
  EXPECT_NO_THROW(Node<int>a(10));
}

TEST(Node, can_get_data)
{
  Node<int>a(10);
  EXPECT_EQ(10, a.Data);
}

TEST(Node, compare_equal_Node_is_true)
{
  Node<int>a(10),b(10);
  EXPECT_EQ(a, b);
}

TEST(Node, compare_not_equal_Node_is_false)
{
  Node<int>a(10), b(5);
  EXPECT_NE(a, b);
}