#pragma once
#include"Node.h"
#include"List.h"
template<typename DataType>
class List;

template<typename DataType>
class IteratorList
{

public:
  Node<DataType>* p;
  IteratorList(Node<DataType>* el) :p(el) {}
  IteratorList& operator++()
  {
    if (p == nullptr)
      throw::std::logic_error("Nowhere further");
    p = p->pNext;
    return *this;
  }
  //IteratorList& operator--()
  //{
  //  p = p->pBack;
  //  return *this;
  //}
  friend class List<DataType>;
};