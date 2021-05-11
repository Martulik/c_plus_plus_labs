#include <boost/test/unit_test.hpp>
#include "container.hpp"

namespace poz = pozdnyakov;

BOOST_AUTO_TEST_CASE(test_factorial)
{
  poz::FactorialContainer cont;
  poz::FactorialContainer::iterator begin = cont.begin();
  size_t factor = 1;
  for (size_t i = 1; i < 11; i++)
  {
    factor *= i;
    BOOST_CHECK_REQUIRE(factor == *begin);
    begin++;
  }
}
