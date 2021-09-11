#include "company.hpp"
#include <iostream>

CompanyTracker::CompanyTracker(int n)
{
  numCompanies = n;
  companies = new Company* [numCompanies];
  for (int i = 0; i < numCompanies; ++i)
      companies[i] = new Company ();
}

// Deallocates all dynamically allocated memory.
CompanyTracker::~CompanyTracker()
{
  //deallocate the small companies
  for (int i = 0; i < numOfCompanies(); i++)
  {
    //deallocate the big companies
    while(companies[i]->parent!=nullptr)split(i);
    delete companies[i];
  }
  //complete delete the companies
  delete [] companies;
}

int CompanyTracker::numOfCompanies()
{
  return numCompanies;
}

void CompanyTracker::merge(int i, int j)
{
  // dealing with invalid indexes
  int n = numOfCompanies();
  if(i>=n || j>=n || i<0 || j<0) return;
  //get the 2 companies
  Company *companyA = companies[i];
  Company *companyB = companies[j];
  //loop to the top of the companies
  while(companyA->parent!= nullptr)
	  companyA = companyA->parent;
  while(companyB->parent!= nullptr)
	  companyB = companyB->parent;
  //deal with same companies
  if(companyA == companyB)return;
  //create a new company
  Company *companyC = new Company(companyA,companyB);
  companyA->parent = companyC;
  companyB->parent = companyC;
}

void CompanyTracker::split(int i)
{
  //deal with invalid indexes
  int n = numOfCompanies();
  if(i>=n || i<0) return;
  //get the company of the index
  Company *companyA = companies[i];
  //make sure it is not the base company
  if(companyA->parent == nullptr)
    return;
  //loop towards the top of the companies
  while(companyA->parent != nullptr)
	  companyA = companyA->parent;
  //dealing with split
  Company *companyB = companyA->merge1;
  companyB->parent = nullptr;
  Company *companyC = companyA->merge2;
  companyC->parent = nullptr;
  //deallocate the memory
  delete companyA;
}

bool CompanyTracker::inSameCompany(int i, int j)
{
  //dealing with invalid cases;
  int n = numOfCompanies();
  if(i>=n || j>=n || i<0 || j<0) return false;
  //get the actual companies
  Company *companyA = companies[i];
  Company *companyB = companies[j];
  //get the parent companies
  while(companyA->parent != nullptr)
	  companyA = companyA->parent;
  while(companyB->parent != nullptr)
	  companyB = companyB->parent;
  //compare the two companies
  if(companyA == companyB)
    return true;
  else
    return false;
}