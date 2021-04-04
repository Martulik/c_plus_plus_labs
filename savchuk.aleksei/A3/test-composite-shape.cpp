#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"
#include "test-utility.hpp"
#include "test-values.hpp"

namespace lab = savchuk;

lab::CompositeShape makeComposite(const lab::Rectangle& r, const lab::Circle& c)
{
  return lab::CompositeShape({ &r, &c });
}

BOOST_AUTO_TEST_SUITE(composite_shape)

BOOST_AUTO_TEST_CASE(move_invariant)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkMoveInvariant(comp, { -1.6, 13.5 });
  checkMoveInvariant(comp, 2.3, -12.6);
}

BOOST_AUTO_TEST_CASE(scale_frame_rectangle)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkScaleFrameRect(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_area)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkScaleArea(comp, CORRECT_SCALE_FACTOR);
}

BOOST_AUTO_TEST_CASE(scale_invalid_argument)
{
  lab::Rectangle r = makeRect(RECT_POS, WIDTH, HEIGHT);
  lab::Circle c = makeCirc(CIRC_POS, RADIUS);
  lab::CompositeShape comp = makeComposite(r, c);
  checkScaleInvalidArgument(comp, WRONG_SCALE_FACTOR);
}

BOOST_AUTO_TEST_SUITE_END()
