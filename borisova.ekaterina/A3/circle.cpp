#include "circle.hpp"
#include <stdexcept>

borisova::Circle::Circle(const point_t& pos, const double radius):
  position_(pos),
  radius_(radius)
{
  if (radius <= 0)
  {
    throw (std::invalid_argument("Negative radius"));
  }
}

borisova::Circle::Circle(const double x, const double y, const double radius):
  position_{x, y},
  radius_(radius)
{
  if (radius <= 0)
  {
    throw (std::invalid_argument("Negative radius"));
  }
}

double borisova::Circle::getArea() const
{
  const double PI = 3.14;
  return PI * radius_ * radius_;
}

borisova::rectangle_t borisova::Circle::getFrameRect() const
{
  return {radius_ * 2, radius_ * 2, position_};
}

void borisova::Circle::scale(double k)
{
  radius_ *= k;
}

void borisova::Circle::move(const double dx, const double dy)
{
  position_.x += dx;
  position_.y += dy;
}
void borisova::Circle::move(const point_t& dpos)
{
  position_ = dpos;
}

std::string borisova::Circle::getName() const
{
  return "Circle";
}
