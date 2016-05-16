#pragma once
#include "Person.h"

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilder
{
  Person p;
protected:
  Person& person;
  explicit PersonBuilder(Person& person)
    : person{ person }
  {
  }
public:
  PersonBuilder() :
    person{p}
  {
    
  }

  operator Person()
  {
    return std::move(person);
  }

  // builder facets

  PersonAddressBuilder lives();
  PersonJobBuilder works();
};
