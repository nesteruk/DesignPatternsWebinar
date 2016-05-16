#pragma once
#include <string>
using namespace std;
using namespace std::string_literals;
#include <boost/lexical_cast.hpp>
class PersonBuilder;

class Person
{
  // address
  string street_address, post_code, city;

  // employment
  string company_name, position;
  int annual_income = 0;

  Person() {}
public:
  static PersonBuilder create();

  Person(Person&& other)
    : street_address{move(other.street_address)},
      post_code{move(other.post_code)},
      city{move(other.city)},
      company_name{move(other.company_name)},
      position{move(other.position)},
      annual_income{other.annual_income}
  {
  }

  Person& operator=(Person&& other)
  {
    if (this == &other)
      return *this;
    street_address = move(other.street_address);
    post_code = move(other.post_code);
    city = move(other.city);
    company_name = move(other.company_name);
    position = move(other.position);
    annual_income = other.annual_income;
    return *this;
  }

  friend ostream& operator<<(ostream& os, const Person& obj)
  {
    return os
      << "street_address: "s << obj.street_address
      << " post_code: "s << obj.post_code
      << " city: "s << obj.city
      << " company_name: "s << obj.company_name
      << " position: "s << obj.position
      << " annual_income: "s << boost::lexical_cast<string>(obj.annual_income);
  }

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};
