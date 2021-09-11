#include<iostream>
#include"company.hpp"

using namespace std;

int main(){
  //Test 1 Standard Case
  cout << "Welcome to Test 1" << endl;
  CompanyTracker *Test1 = new CompanyTracker(5);
  Test1->merge(0,1);
  Test1->merge(2,3);
  Test1->merge(0,3);
  Test1->split(2);
  Test1->split(2);
  Test1->merge(2,4);
  Test1->split(0);
  for(int i=0;i<4;i++)
    for(int j=i+1;j<5;j++)
      cout << Test1->inSameCompany(i,j) << " ";
  cout << endl;
  Test1->~CompanyTracker();

  //Test 2 One company split
  cout << "Welcome to Test 2" << endl;
  CompanyTracker *Test2 = new CompanyTracker(1);
  Test2->split(1);

  //Test 3 All merge and All split
  cout << "Welcome to Test 3" << endl;
  CompanyTracker *Test3 = new CompanyTracker(8);
  Test3->merge(0,1);
  Test3->merge(2,3);
  Test3->merge(4,5);
  Test3->merge(6,7);
  Test3->merge(0,3);
  Test3->merge(4,7);
  Test3->merge(0,7);
  for(int i=0;i<7;i++)
    for(int j=i+1;j<8;j++)
      cout << Test3->inSameCompany(i,j) << " ";
  cout << endl;
  Test3->split(0);
  Test3->split(0);
  Test3->split(0);
  Test3->split(2);
  Test3->split(4);
  Test3->split(4);
  Test3->split(6);
  for(int i=0;i<7;i++)
    for(int j=i+1;j<8;j++)
      cout << Test3->inSameCompany(i,j) << " ";
  cout << endl;
  //delete Test3;
  Test3->~CompanyTracker();

  //Test 4 Self Spilt or Self Merge or Self Contains
  cout << "Welcome to Test 4" << endl;
  CompanyTracker *Test4 = new CompanyTracker(20);
  Test4->merge(1,1);
  Test4->merge(2,2);
  Test4->merge(3,4);
  Test4->merge(3,4);
  cout << Test4->inSameCompany(3,4) << endl;
  Test4->split(5);
  Test4->split(3);
  Test4->split(3);
  Test4->split(4);
  cout << Test4->inSameCompany(3,4) << endl;
  cout << Test4->inSameCompany(1,1) << endl;
  cout << Test4->inSameCompany(2,2) << endl;
  cout << Test4->inSameCompany(1,2) << endl;
  cout << Test4->inSameCompany(5,5) << endl;
  cout << Test4->inSameCompany(6,6) << endl;
  //delete Test4;
  Test4->~CompanyTracker();

  //Test 5 Out of Range Data
  cout << "Welcome to Test 5" << endl;
  CompanyTracker *Test5 = new CompanyTracker(5);
  Test5->merge(-1,0);
  Test5->merge(5,0);
  Test5->split(-1);
  Test5->split(5);
  cout << Test5->inSameCompany(-1,1) << endl;
  cout << Test5->inSameCompany(5,1) << endl;
  //delete Test5;
  Test5->~CompanyTracker();
	return 0;
}