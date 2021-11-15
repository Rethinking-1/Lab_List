#pragma once
#include<iostream>
template<typename DataType>
class List;

template<typename DataType>
class Node
{
public:
  DataType Data;
  Node* pNext;
  Node(DataType _Data = DataType(), Node<DataType>* Next = nullptr) :Data(_Data), pNext(Next) {}
  Node(const Node<DataType>& node2) { Data = node2.Data; pNext = node2; }
  bool operator==(const Node<DataType>& node2) const { return Data == node2.Data; }
  bool operator!=(const Node<DataType>& node2) const { return !(*this == node2); }
  //Node* pBack;
  // Node(DataType _Data = DataType(), Node* Next = nullptr, Node* Back = nullptr) : Data(_Data), pNext(Next), pBack(Back){}
};



template<typename DataType>
class IteratorList
{
  Node<DataType>* p;
public:
  IteratorList(Node<DataType>* el) :p(el){}
  IteratorList& operator++()
  {
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



template<typename DataType>
class List
{
  Node<DataType>* pHead;
 // Node<DataType>* pEnd;
  //int index;
  bool check_end(const Node<DataType>* node)
  {
    if(!isEmpty())
      return node->pNext == nullptr;
    return true; 
  }
public:
  List();
  List(const List<DataType>& list);
  bool isEmpty();
  void push_front(const DataType& Data);
  void push_back(const DataType& Data);
  void pop_front();
  void pop_back();
  void insert(const IteratorList<DataType>&index, const DataType& Data);
  void Merge(const IteratorList<DataType>& start, List<DataType>& list2);
  void reverse();
  IteratorList<DataType> begin();
  IteratorList<DataType> end();
  void print();
  ~List();
  ////////////////////////////
  IteratorList<DataType> Search(const DataType& d);
 // friend std:: ostream& operator<<(std::ostream& os, const List<DataType>& l);
  //void Delete(const IteratorList<DataType> start, const IteratorList<DataType> finish);
  //friend std::ostream& operator<<(std::ostream& ostr, const List<DataType>& list);
  //void Clean();
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
  this->reverse();
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
  //  pEnd = pHead;
  }
  else
  {
    IteratorList<DataType> tmp = this->end();
    tmp.p->pNext = new Node<DataType>(Data, nullptr);
  }
}
//////////////////////////////////////////////////////////
template<typename DataType>
void List<DataType>::pop_front()
{
  //
  if (!isEmpty())
  {
    Node<DataType>* t = pHead;
    pHead = pHead->pNext;
    t->~Node();
  }
}
template<typename DataType>
inline void List<DataType>::pop_back()
{
  reverse();
  pop_front();
  reverse();
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::insert(const IteratorList<DataType>& index, const DataType& Data)//InsertAfter
{
  index.p->pNext = new Node<DataType>(Data, index.p->pNext);
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
{//memory leak
  IteratorList<DataType>it(pHead);
  while (!check_end(it.p))
  {
    this->push_front(it.p->pNext->Data);
    it.p->pNext = it.p->pNext->pNext;
  }
}
//////////////////////////////////////////////////////////
template<typename DataType>
inline void List<DataType>::print()
{
  IteratorList<DataType> tmp(pHead);
  while (!check_end(tmp.p))
  {
    std::cout << tmp.p->Data << "\n";
    tmp.operator++();
  }
  if(!isEmpty())
    std::cout << tmp.p->Data << "\n";
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
template<typename DataType>
inline IteratorList<DataType> List<DataType>::Search(const DataType& d)
{
  IteratorList<DataType>find(pHead);
  while (!check_end(find.p)&& find.p->Data != d)
    ++find;
  return find;
}
//////////////////////////////////////////////////////////
//template<typename DataType>
//std::ostream& operator<<(std::ostream& ostr,const List<DataType>&list)
//{
//  IteratorList<DataType>tmp(list.pHead);
//  while (!End(tmp.p))
//  {
//    ostr << tmp.p->Data << "\n";
//    tmp++;
//  }
//  return ostr;
//}
//////////////////////////////////////////////////////////


