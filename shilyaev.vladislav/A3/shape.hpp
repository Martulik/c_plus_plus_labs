#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <memory>
#include "base-types.hpp"

namespace shilyaev {
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual std::unique_ptr<Shape> clone() const = 0;
    virtual void move(const point_t &pos) = 0;
    virtual void move(double dx, double dy) = 0;
    void scale(double factor);
  private:
    virtual void scaleInternal(double factor) = 0;
  };
}

#endif
