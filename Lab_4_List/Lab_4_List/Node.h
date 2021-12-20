#pragma once
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
};