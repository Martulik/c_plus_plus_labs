#ifndef SHAPE
#define SHAPE

#include "base-types.hpp"

class Shape
{
public:
  virtual ~Shape() = default;

  virtual double getArea() const= 0;
  virtual rectangle_t getFrameRect() const = 0;
  virtual void move(const point_t &newPos) = 0;
  virtual void move(const double dx, const double dy) = 0;
};

#endif
