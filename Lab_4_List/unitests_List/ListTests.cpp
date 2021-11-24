#include "gtest/gtest.h"
#include ".\List.h"

TEST(List, can_create_empty_List)
{
  EXPECT_NO_THROW(List<int>list);
}

TEST(List, can_push_front1)
{
  List<int>list;
  EXPECT_NO_THROW(list.push_front(1));
}

TEST(List, can_push_front2)
{
  List<int>list;
  EXPECT_NO_THROW(list.push_front(1));
  EXPECT_NO_THROW(list.push_front(35));
}

TEST(List, can_pop_front)
{
  List<int>list;
  list.push_back(1);
  EXPECT_NO_THROW(list.pop_front());
}


TEST(List, can_push_back1)
{
  List<int>list;
  EXPECT_NO_THROW(list.push_back(1));
}

TEST(List, can_push_back2)
{
  List<int>list;
  EXPECT_NO_THROW(list.push_back(1));
  EXPECT_NO_THROW(list.push_back(35));
}

TEST(List, can_pop_back)
{
  List<int>list;
  list.push_back(1);
  EXPECT_NO_THROW(list.pop_back());
}

TEST(List, is_Empty_List_if_is_empty_true)
{
  List<int>list;
  EXPECT_EQ(list.isEmpty(), true);
}

TEST(List, is_Empty_List_if_is_not_empty_false)
{
  List<int>list;
  list.push_front(1);
  EXPECT_EQ(list.isEmpty(), false);
}

TEST(List, can_get_data)
{
  List<int>list;
  for (size_t i = 1; i < 10; i++)
  {
    list.push_back(i);
  }
  IteratorList<int>it = list.begin();
  ++it;
  ++it;
  EXPECT_EQ(3, list.Get(it));
}

TEST(List, can_insert_after1)
{
  List<int>list;
  for (size_t i = 0; i < 3; i++)
  {
    list.push_back(i+1);
  }
  IteratorList<int>it1 = list.begin();
  list.insert(it1, 10);

  IteratorList<int>it2 = list.begin();
  EXPECT_EQ(1, list.Get(it2));
  ++it2;
  EXPECT_EQ(10, list.Get(it2));
  ++it2;
  EXPECT_EQ(2, list.Get(it2));
  ++it2;
  EXPECT_EQ(3, list.Get(it2));
}

TEST(List, can_insert_after2)
{
  List<int>list;
  for (size_t i = 0; i < 3; i++)
  {
    list.push_back(i + 1);
  }
  IteratorList<int>it1 = list.begin();
  ++it1;
  list.insert(it1, 10);

  IteratorList<int>it2 = list.begin();
  EXPECT_EQ(1, list.Get(it2));
  ++it2;
  EXPECT_EQ(2, list.Get(it2));
  ++it2;
  EXPECT_EQ(10, list.Get(it2));
  ++it2;
  EXPECT_EQ(3, list.Get(it2));
}

TEST(List, push_front_is_correct)
{
  List<int>list;
  int k = 1;
  for (size_t i = 0; i < 3; i++)
  {
    list.push_front(k);//front
    k++;
    list.push_back(k);//back
    k++;
  }
  EXPECT_EQ(5, list.begin().p->Data);
}

TEST(List, push_back_is_correct)
{
  List<int>list;
  int k = 1;
  for (size_t i = 0; i < 3; i++)
  {
    list.push_back(k);//back 
    k++;
    list.push_front(k);//front
    k++;
  }
  IteratorList<int>it = list.begin();
  ++it;
  list.insert(it, 777);
  EXPECT_EQ(5, list.end().p->Data);
}

TEST(List, pop_front_is_correct)
{
  List<int>list;
  for (size_t i = 0; i < 10; i++)
  {
    list.push_front(i);
  }
  list.pop_front();
  EXPECT_EQ(8, list.begin().p->Data);
}

TEST(List, pop_back_is_correct)
{
  List<int>list;
  for (size_t i = 0; i < 10; i++)
  {
    list.push_front(i);
  }
  list.pop_back();
  EXPECT_EQ(1, list.end().p->Data);
}

TEST(List, can_delete_multiple_items)
{
  List<int>list;
  //0 1 2 3 4
  for (size_t i = 0; i < 5; i++)
  {
    list.push_back(i);
  }
  IteratorList<int>it1 = list.begin(), it2 = list.begin();
  ++it1;
  ++it2;
  ++it2;
  ++it2;
  ++it2;
  //it1 = 1 , it2 = 4
  list.Delete(it1, it2);
  IteratorList<int>it = list.begin();
  EXPECT_EQ(0, list.Get(it));
  ++it;
  EXPECT_EQ(1, list.Get(it));
  ++it;
  EXPECT_EQ(4, list.Get(it));
}

TEST(List, can_clean_List)
{
  List<int>list;
  for (size_t i = 0; i < 100; i++)
  {
    list.push_front(i);
  }
  list.Clean();
  EXPECT_EQ(true, list.isEmpty());
}

TEST(List, can_reverse_not_empty_List1)
{
  List<int>list;
  for (size_t i = 0; i < 10; i++)
  {
    list.push_front(i);
  }
  EXPECT_NO_THROW(list.reverse());
}

TEST(List, can_reverse_not_empty_List2)
{
  List<int>list;
  list.push_front(0);
  EXPECT_NO_THROW(list.reverse());
}

TEST(List, no_throw_if_reverve_empty_List)
{
  List<int>list;
  EXPECT_NO_THROW(list.reverse());
}

TEST(List, reverse_not_empty_List_with_one_el_is_correct)
{
  List<int>list;
  list.push_back(5);
  list.reverse();
  EXPECT_EQ(5, list.begin().p->Data);
}

TEST(List, reverse_not_empty_List_with_two_el_is_correct)
{
  List<int>list;
  list.push_back(5);
  list.push_back(10);
  list.reverse();
  IteratorList<int>it = list.begin();
  EXPECT_EQ(10, list.Get(it));
  ++it;
  EXPECT_EQ(5, list.Get(it));
}

TEST(List, reverse_not_empty_List_with_three_el_is_correct)
{
  List<int>list;
  list.push_back(5);
  list.push_back(10);
  list.push_back(82);
  list.reverse();
  IteratorList<int>it = list.begin();
  EXPECT_EQ(82, list.Get(it));
  ++it;
  EXPECT_EQ(10, list.Get(it));
  ++it;
  EXPECT_EQ(5, list.Get(it));
}

TEST(List, can_search_an_el_if_there_is_one)
{
  List<int>list;
  for (size_t i = 0; i < 10; i++)
  {
    list.push_back(i*2);
  }
  IteratorList<int>it = list.Search(6);
  EXPECT_EQ(6, list.Get(it));
  ++it;
  EXPECT_EQ(8, list.Get(it));
}

TEST(List, search_is_equal_last_el_if_there_is_none)
{
  List<int>list;
  for (size_t i = 0; i < 10; i++)
  {
    list.push_front(i * 2);
  }
  IteratorList<int>it = list.Search(5);
  EXPECT_EQ(list.Get(it), list.end().p->Data);
}

TEST(List, Only_unique_elements_is_correct)
{
  List<int>list;
  for (size_t i = 0; i < 20; i++)
  {
    list.push_back(i % 5);
  }
  list.Only_unique_elements();
  IteratorList<int>it = list.begin();
  EXPECT_EQ(0, list.Get(it));
  ++it;
  EXPECT_EQ(1, list.Get(it));
  ++it;
  EXPECT_EQ(2, list.Get(it));
  ++it;
  EXPECT_EQ(3, list.Get(it));
  ++it;
  EXPECT_EQ(4, list.Get(it));
  ++it;
  EXPECT_EQ(nullptr, it.p);
}

TEST(List, can_merge_two_Lists)
{
  List<int>list1, list2;
  for (int i = 0; i < 3; i++)
  {
    list1.push_back(i);//0 1 2
    list2.push_back((i + 1) * 4);//4 8 12
  }
  IteratorList<int>it = list1.Search(1);
  list1.Merge(it, list2);
  it = list1.begin();
  EXPECT_EQ(0, list1.Get(it));
  ++it;
  EXPECT_EQ(1, list1.Get(it));
  ++it;
  EXPECT_EQ(4, list1.Get(it));
  ++it;
  EXPECT_EQ(8, list1.Get(it));
  ++it;
  EXPECT_EQ(12, list1.Get(it));
  ++it;
  EXPECT_EQ(2, list1.Get(it));
  ++it;
  EXPECT_EQ(nullptr, it.p);
}