#pragma once
#include<iostream>
#include"Node.h"
#include"IteratorList.h"
template<typename DataType>
class IteratorList;

template<typename DataType>
class List
{
  Node<DataType>* pHead;
 // Node<DataType>* pEnd;
  bool check_end(const Node<DataType>* node)
  {
    if (node != nullptr)
      //if(!isEmpty())
      return node->pNext == nullptr;
    return true; 
  }
public:
  List();
  List(const List<DataType>& list);
  DataType Get(IteratorList<DataType>& id);
  bool isEmpty();
  void push_front(const DataType& Data);
  void push_back(const DataType& Data);
  void insert(const IteratorList<DataType>& index, const DataType& Data);
  void pop_front();
  void pop_back();
  void Delete(const IteratorList<DataType>& index);
  void Delete(const IteratorList<DataType> start, const IteratorList<DataType> finish);
  void Clean();
  void Merge(const IteratorList<DataType>& start, List<DataType>& list2);
  void reverse();
  IteratorList<DataType> Search(const DataType& d);
  void Only_unique_elements();
  IteratorList<DataType> Split_the_list(IteratorList<DataType> left, IteratorList<DataType> right);
  void sortUP();
  void sortLow();
 // List<DataType> Merge_sort(IteratorList<DataType> left, IteratorList<DataType> right);
  IteratorList<DataType> begin();
  IteratorList<DataType> end();
  ~List();
  template<typename DataType>
  friend std::ostream& operator<<(std::ostream& ostr, const List<DataType>& list);
};



//////////////////////////////////////////////////////////
template<typename DataType>
inline List<DataType>::List()
{
  pHead = nullptr;
 // pEnd = nullptr;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline List<DataType>::List(const List<DataType>& list)
{
  pHead = nullptr;
  IteratorList<DataType>it(list.pHead);

  while (!check_end(it.p))
  {
    push_front(it.p->Data);
    ++it;
  }
  if (it.p != nullptr)
    push_front(it.p->Data);
  this->reverse();
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline DataType List<DataType>::Get(IteratorList<DataType>& id)
{
  if (id.p != nullptr)
    return id.p->Data;
  else
    throw std::exception();

}
//////////////////////////////////////////////////////////
template<typename DataType>
inline bool List<DataType>::isEmpty()
{
  return pHead == nullptr;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::push_front(const DataType& Data)
{
  if (isEmpty())
  {
    pHead = new Node<DataType>(Data, nullptr);
  //  pEnd = pHead;
  }
  else
    pHead = new Node<DataType>(Data, pHead);
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::push_back(const DataType& Data)
{
  if (isEmpty())
  {
    pHead = new Node<DataType>(Data, nullptr);
  }
  else
  {
    IteratorList<DataType> tmp = this->end();
    tmp.p->pNext = new Node<DataType>(Data, nullptr);
  }
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::insert(const IteratorList<DataType>& index, const DataType& Data)//InsertAfter
{
  index.p->pNext = new Node<DataType>(Data, index.p->pNext);
}
//////////////////////////////////////////////////////////
template<typename DataType>
void List<DataType>::pop_front()
{
  if (!isEmpty())
  {
    Node<DataType>* temp = pHead->pNext;
    delete pHead;
    pHead = temp;
  }
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::pop_back()
{
  reverse();
  pop_front();
  reverse();
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::Delete(const IteratorList<DataType>& index)
{
  IteratorList<DataType> it2 = index;
  Node<DataType>* tmp = index.p->pNext->pNext;
  delete it2.p->pNext;
  it2.p->pNext = tmp;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::Delete(const IteratorList<DataType> start, const IteratorList<DataType> finish)
{
  IteratorList<DataType> it = start;
  if (start.p != nullptr)
  {
    while (!check_end(it.p) && it.p->pNext != finish.p/*->pNext*/ && it.p->pNext != finish.p->pNext)
      Delete(it);
  }
  ++it;
}
template<typename DataType>
inline void List<DataType>::Clean()
{
  while (!check_end(pHead))
    pop_front();
  if (pHead != nullptr)
    delete pHead;
  pHead = nullptr;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::Merge(const IteratorList<DataType>& start, List<DataType>& list2)
{
  IteratorList<DataType> it2 = start;
  ++it2;
  start.p->pNext = list2.pHead;
  IteratorList<DataType> tmp(list2.pHead);
  while (!check_end(tmp.p))
    tmp.operator++();
  tmp.p->pNext = it2.p;
  list2.pHead = nullptr;

}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::reverse()
{
  IteratorList<DataType>it(pHead);
  Node<DataType>* tmp;
  while (!check_end(it.p))
  {
    this->push_front(it.p->pNext->Data);
    tmp = it.p->pNext->pNext;
    delete it.p->pNext;
    it.p->pNext = tmp;
  }
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline IteratorList<DataType> List<DataType>::begin()
{
  return pHead;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline IteratorList<DataType> List<DataType>::end()
{
  IteratorList<DataType> tmp(pHead);
  while (!check_end(tmp.p))
    ++tmp;
  return tmp;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline List<DataType>::~List()
{
  if (isEmpty())
    return;
  Node<DataType>* tmp;
  while (pHead->pNext != nullptr)
  {
    tmp = pHead->pNext;
    pHead->pNext = tmp->pNext;
    delete tmp;
  }
  delete pHead;
  pHead = nullptr;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline IteratorList<DataType> List<DataType>::Search(const DataType& d)
{
  IteratorList<DataType>find(pHead);
  while (!check_end(find.p)&& find.p->Data != d)
    ++find;
  return find;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::Only_unique_elements()
{
  Node<DataType>* tmp = pHead->pNext;
  Node<DataType>* prev = pHead;
  while (tmp != nullptr)
  {
    Node<DataType>* tmp2 = pHead;
    bool find = false;
    while (tmp2 != tmp && !find)
    {
      if (tmp2->Data == tmp->Data)
        find = true;
      else
        tmp2 = tmp2->pNext;
    }
    if (find)
    {
      prev->pNext = tmp->pNext;
      Node<DataType>* tmp3 = tmp->pNext;
      delete tmp;
      tmp = tmp3;
    }
    else
    {
      tmp = tmp->pNext;
      prev = prev->pNext;
    }
  }
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline IteratorList<DataType> List<DataType>::Split_the_list(IteratorList<DataType> left, IteratorList<DataType> right)
{
  //IteratorList<DataType>it = left;
  //while (it.p != right.p->pNext)
  //{
  //  ++it;
  //  if (it.p != right.p->pNext)
  //  {
  //    ++it;
  //    ++left;
  //  }

  //}
  //return left;
  IteratorList<DataType>it1(pHead),it2(pHead);
  while (!check_end(it2.p))
  {
    ++it2;
    if (!check_end(it2.p))
    {
      ++it2;
      ++it1;
    }
  }
  return it1;
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::sortUP()
{
  IteratorList<int>it(pHead), it2(pHead);
  while (it.p != nullptr)
  {
    it2 = pHead;
    while (!check_end(it2.p))
    {
      if (it.p->Data > it2.p->Data)
        std::swap(it.p->Data, it2.p->Data);
      ++it2;
    }
    ++it;
  }
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::sortLow()
{
  IteratorList<int>it(pHead), it2(pHead);
  while (it.p != nullptr)
  {
    it2 = pHead;
    while (!check_end(it2.p))
    {
      if (it.p->Data < it2.p->Data)
        std::swap(it.p->Data, it2.p->Data);
      ++it2;
    }
    ++it;
  }
}
//////////////////////////////////////////////////////////
//template<typename DataType>
//inline List<DataType> List<DataType>::Merge_sort(IteratorList<DataType> left, IteratorList<DataType> right)
//{
//  List<DataType>temp(*this);
//  Delete(right.p, end());
//  Delete(begin(), left.p);
//  if (!check_end(left.p))
//  {
//    ///////////////////////////////////
//    if (left.p != nullptr && left.p->pNext != nullptr && left.p->pNext->pNext == nullptr)
//    {
//      if (left.p->Data > right.p->Data)
//      {
//        std::swap(left.p->Data, right.p->Data);
//      }
//    }
//    ///////////////////////////////////
//    else
//    {
//      right = Split_the_list(left,right);
//      std::cout << "\n" << right.p->Data << "\n";
//      temp = Merge_sort(left, right);
//     // Merge_sort(it2, temp.end());
//      while (!check_end(left.p) && !check_end(right.p))
//      {
//        if (left.p->Data > right.p->Data)
//        {
//          Node<DataType>*save = left.p;
//          push_front(save->Data);
//          left.p = left.p->pNext;
//        }
//        else
//        {
//          Node<DataType>*save = right.p;
//          push_front(save->Data);
//          right.p = right.p->pNext;
//        }
//      }
//      while (!check_end(left.p))
//      {
//        Node<DataType>*save = left.p;
//        push_front(save->Data);
//        left.p = left.p->pNext;
//      }
//      while (!check_end(right.p))
//      {
//        Node<DataType>*save = right.p;
//        push_front(save->Data);
//        right.p = right.p->pNext;
//      }
//    }
//  }
// // reverse();
//  //*this = temp;
//  return temp;
//}
//////////////////////////////////////////////////////////
 template<typename DataType>
inline std::ostream & operator<<(std::ostream & ostr, const List<DataType> & list)
{
  IteratorList<DataType>tmp(list.pHead);
  if (tmp.p != nullptr)
  {
    while (tmp.p->pNext != nullptr)
    {
      ostr << tmp.p->Data << "\n";
      ++tmp;
    }
    ostr<< tmp.p->Data << "\n";
  }
  else
    ostr << "list is empty\n";
  return ostr;
}
//////////////////////////////////////////////////////////