#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.hpp"
#include <string>
#include <cassert>

class Rectangle: public Shape
{
public:
  Rectangle(double width, double height, point_t pos_);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(const point_t& point);
  void move(double x, double y);
  std::string getName() const;
private:
  double width_;
  double height_;
  point_t pos_;
};

#endif
