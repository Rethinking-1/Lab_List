#include"List.h"
#include<iostream>
//#include<Windows.h>
using namespace std;
int main()
{
  List<int> mylist, mylist2;
  for (int i = 0; i < 5; i++)
  {
    mylist.push_back(i);
    mylist2.push_back(i * 4);
  }
  mylist.print();
  //while (true)
  //{
  //  mylist.reverse();
  //  cout << "--------------\n";
  //  mylist.print();

  //}
  mylist.Search(3);
  IteratorList<int> it2 = mylist.begin();
  ++it2;
  ++it2;
  List<int>mylist3(mylist);
 // mylist.Merge(it2, mylist2);
  //insert
 // mylist.push_front(34);
  mylist.push_back(75);
  IteratorList<int> it = mylist.begin();
  it.operator++();
  mylist.insert(it, 230);



  cout << "l1\n";
  mylist.print();
  cout << "\nl2\n";
  mylist2.print();
  cout << "\nl3\n";
  mylist3.print();
  return 0;
}