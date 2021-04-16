#ifndef TEST_FUNCTION_HPP
#define TEST_FUNCTION_HPP

#include "composite-shape.hpp"
#include <boost/test/unit_test.hpp>

namespace pozdnyakov
{
  const double delta = 0.5;
  pozdnyakov::UniqueShape makeRect();
  pozdnyakov::UniqueShape makeCircle();
  pozdnyakov::UniqueShape makeCompositeShape();
}

#endif
