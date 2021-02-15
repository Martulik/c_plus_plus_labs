#include "rectangle.hpp"

#include <iostream>
#include <iomanip>

Rectangle::Rectangle(const double width, const double height):
  figure_({width, height, 0.0, 0.0})
{}

Rectangle::Rectangle(const double width, const double height, const point_t& pos):
  figure_({width, height, pos})
{}

double Rectangle::getArea() const
{
  return figure_.width * figure_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return figure_;
}

void Rectangle::move(const point_t& destination)
{
  figure_.pos = destination;
}

void Rectangle::move(const double dx, const double dy)
{
  figure_.pos.x += dx;
  figure_.pos.y += dy;
}
