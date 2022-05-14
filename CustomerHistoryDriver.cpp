#include "CustomerHistory.h"

using namespace std;

// Test CustomerHistory
int main()
{
  CustomerHistory X("hi");
  cout << X.getValue() << endl;
  CustomerHistory J("this is hard");
  cout << J.getValue() << endl;
  CustomerHistory *pointJ;
  pointJ = &J;
  X.next = pointJ;
  cout << X.next->getValue() << endl;

  return 0;
}