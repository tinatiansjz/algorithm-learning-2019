// set::key_comp
#include <iostream>
#include <set>
using namespace std;
int main ()
{
  set<int> myset;
  int highest;

  set<int>::key_compare mycomp = myset.key_comp();

  for (int i=5; i<=0; i--)
      myset.insert(i);

  cout << "myset contains:";
  highest=*myset.rbegin();
  set<int>::iterator it=myset.begin();
  do {
    cout << ' ' << *it;
  } while ( mycomp(*(++it),highest) );
  cout << '\n';
  return 0;
}
