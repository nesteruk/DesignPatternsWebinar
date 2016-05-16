#include "PersonBuilder.h"
#include "PersonAddressBuilder.h"
#include "PersonJobBuilder.h"

PersonAddressBuilder PersonBuilder::lives()
{
  return PersonAddressBuilder{ person };
}

PersonJobBuilder PersonBuilder::works()
{
  return PersonJobBuilder{ person };
}