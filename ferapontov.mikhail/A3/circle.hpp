#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace ferapontov
{
  class Circle: public Shape
  {
  public:
    Circle(double radius, const point_t& pos);

    virtual ~Circle() = default;

    std::string getName() const override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& pos) override;
    void move(double dx, double dy) override;
    virtual std::unique_ptr< Shape > clone() const override;
  private:
    double radius_;
    point_t pos_;

    void doScale(double k) override;
  };
}
#endif
