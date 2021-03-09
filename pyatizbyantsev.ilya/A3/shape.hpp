#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace pyatizbyantsev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& newPos) = 0;
    virtual void move(double abscissa, double ordinate) = 0;
    virtual void scale(double scaleCoefficient) = 0;
  };
}

#endif
