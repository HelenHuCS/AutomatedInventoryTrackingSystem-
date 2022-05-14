#include "CustomerInfo.h"

using namespace std;


// Test CustomerInfo
int main()
{
  CustomerInfo X(0000, "Kevin", "Huang");
  X.addToHistory("first");
  X.addToHistory("second");
  X.addToHistory("third");
  X.displayHistory();

  bool test = X == X;
  cout << "Kevin == Kevin?: " << test << endl;

  CustomerInfo Y(1111, "Helen", "Hu");
  test = X == Y;
  cout << "Kevin == Helen?: " << test << endl;
  
  return 0;
}