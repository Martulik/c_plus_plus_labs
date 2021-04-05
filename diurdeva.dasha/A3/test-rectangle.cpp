#include <boost/test/unit_test.hpp>
#include <stdexcept>
#include "test-function.hpp"
#include "rectangle.hpp"

std::unique_ptr< diurdeva::Rectangle > makeRectangle()
{
  return std::make_unique< diurdeva::Rectangle >(width, height, pointCenter);
}

BOOST_AUTO_TEST_SUITE(testRectangle)

BOOST_AUTO_TEST_CASE(invalidOptionsRectangle)
{
  BOOST_CHECK_THROW(diurdeva::Rectangle(width, negativeOptions, pointCenter), std::invalid_argument);
  BOOST_CHECK_THROW(diurdeva::Rectangle(negativeOptions, height, pointCenter), std::invalid_argument);
  BOOST_CHECK_THROW(diurdeva::Rectangle(width, height, pointCenter).scale(negativeOptions), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(moveRectangle)
{
  checkConstOptionsBeforeMoving(*makeRectangle());
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  checkAreaBeforeScale(*makeRectangle());
}

BOOST_AUTO_TEST_SUITE_END()
