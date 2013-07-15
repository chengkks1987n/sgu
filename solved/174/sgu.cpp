/**
   @file
   @brief hashtable version.
   @date 2013-07-11
   @version 1.0
   @author ck

   @section Description

   */

#include <iostream>
#include <map>
using namespace std;

int m;
int n;
map<pair<int,int>, int> p;
int setNO = 0;

int main()
{
  cin >> m;
  for (n=1; n<=m; ++n) {
    pair<pair<int,int>,int> p1, p2;
    cin >> p1.first.first >> p1.first.second ;
    cin >> p2.first.first >> p2.first.second;
    //    p1.second = p2.second = 0;
    pair<map<pair<int,int>,int>::iterator,bool> r1, r2;
    r1 = p.insert(p1);
    r2 = p.insert(p2);
    if (r1.second) {  // p1 is in a set
      if (r2.second) { // p2 is in a set
	if(r1.first->second == r2.first->second) {// p1, p2 are in the same set
	  cout << n << endl;
	  return 0;
	}
	else { // p1, p2 are in different sets
	  int s1 = r1.first->second;
	  int s2 = r2.first->second;
	  map<pair<int,int>, int>::iterator it = p.begin();
	  while (it != p.end()) {
	    if (it->second == s1) {
	      it->second = s2;
	    }
	    ++it;
	  }	    
	}	
      }
      else { // p1 is in a set, p2 is not in a set
	r2.first->second = r1.first->second;
      }
    }
    else { // p1 is not in a set
      if (r2.second) { // p2 is in a set
	r1.first->second = r2.first->second;
      }
      else { // p1 and p2 are not in any sets
	++setNO;
	r1.first->second = setNO;
	r2.first->second = setNO;
      }
    }
  }

  cout << 0 << endl;
  return 0;
}
