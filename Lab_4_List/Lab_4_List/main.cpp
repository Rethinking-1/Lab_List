#include"List.h"
#include<iostream>
using namespace std;
int main()
{
  //List<int> mylist_test;
  //for (size_t i = 0; i < 10; i++)
  //{
  //  mylist_test.push_back(rand()%100);
  //}
  //mylist_test.Only_unique_elements();
  //cout << mylist_test << "\n";

  List<int> mylist, mylist2;
  cout << mylist;
  for (size_t i = 0; i < 10; i++)
  {
    mylist.push_front(rand() % 10);
  }
  cout << "mylist with repeating elements\n" << mylist;
  mylist.Only_unique_elements();
  cout << "\n" << "only unique elements\n" << mylist;
  mylist.sortUP();
  cout << "mylist after sortUP\n" << mylist;
  mylist.sortLow();
  cout << "mylist after sortLow\n" << mylist;
  mylist.Clean();
  for (int i = 0; i < 5; i++)
  {
    mylist.push_back(i);
    mylist2.push_back((i + 1) * 4);
  }
  IteratorList<int>it = mylist.begin();
  ++it;
  ++it;
  cout <<"mylist:\n" << mylist << "\n";
  cout << "mylist2:\n" << mylist2 << "\n";
  mylist.Merge(it, mylist2);
  cout << "mylist after Merge after el " << mylist.Get(it) << ":\n" << mylist << "\n";
  cout << "mylist2 after Merge:\n" << mylist2 << "\n";
  ++it;
  ++it;
  cout << "mylist after delete " << it.p->pNext->Data << "\n";
  mylist.Delete(it); 
  cout << mylist << "\n";
  mylist.Clean();
  cout << "list,after clean\n" << mylist << "\n";
  return 0;
}