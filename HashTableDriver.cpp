#include "HashTable.h"

using namespace std;

// g++ CustomerInfo.cpp CustomerHistory.cpp HashTable.cpp HashTableDriver.cpp 
// Test for HashTable class
int main()
{
  CustomerInfo X(0000, "Kevin", "Huang");
  CustomerInfo Y(0001, "Tyson", "Heo");
  CustomerInfo Z(0002, "Helen", "Hu");

  HashTable T;
  cout << "insert successful(expect true): "  << T.insertIntoTable(X) << endl;
  cout << "insert successful(expect false): " << T.insertIntoTable(X) << endl;
  cout << "insert successful(expect true): "  << T.insertIntoTable(Y) << endl;
  cout << "insert successful(expect true): "  << T.insertIntoTable(Z) << endl;

  CustomerInfo * read1 = NULL;
  CustomerInfo * read2 = NULL;
  CustomerInfo * read3 = NULL;

  read1 = T.retrieveCustomer(X.getCustomerId());
  read2 = T.retrieveCustomer(Y.getCustomerId());
  read3 = T.retrieveCustomer(Z.getCustomerId());
  cout << "id: " << read1->getCustomerId() << " firstName: " << read1->getFirstName() << " lastName: " << read1->getLastName() << endl;
  cout << "id: " << read2->getCustomerId() << " firstName: " << read2->getFirstName() << " lastName: " << read2->getLastName() << endl;
  cout << "id: " << read3->getCustomerId() << " firstName: " << read3->getFirstName() << " lastName: " << read3->getLastName() << endl;
  cout<<"Contains id "<<X.getCustomerId()<<" :"<<T.contains(X.getCustomerId())<<endl;
  cout<<"Contains id "<<Y.getCustomerId()<<" :"<<T.contains(Y.getCustomerId())<<endl;
  cout<<"Contains id "<<Z.getCustomerId()<<" :"<<T.contains(Z.getCustomerId())<<endl;
  cout<<"Contains id 12 :"<<T.contains(12)<<endl;
  
  return 0;
}