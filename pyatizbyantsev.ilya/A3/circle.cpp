#include "circle.hpp"
#include <cassert>

const double PI = 3.1415926535;

pyatizbyantsev::Circle::Circle(const double valueRadius, const point_t& valuePos):
  radius_(valueRadius),
  pos_(valuePos)
{
  assert(valueRadius > 0);
}

double pyatizbyantsev::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

pyatizbyantsev::rectangle_t pyatizbyantsev::Circle::getFrameRect() const
{
  return{radius_ * 2, radius_ * 2, pos_};
}

void pyatizbyantsev::Circle::move(const point_t& newPos)
{
  pos_ = newPos;
}

void pyatizbyantsev::Circle::move(const double abscissa, const double ordinate)
{
  pos_.x += abscissa;
  pos_.y += ordinate;
}

void pyatizbyantsev::Circle::scale(double scaleCoefficient)
{
  radius_ *= scaleCoefficient;
}
