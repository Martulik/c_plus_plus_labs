#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void print(std::ostream & out, const Shape& shp)
{
  out << "Shape:\n" <<"::Position: " << "(" << shp.getFrameRect().pos.x
      << ", " << shp.getFrameRect().pos.y << ")";
  out << "\nSpecific: " << shp.getName() << "\n\n";
}


int main(){
  Shape* polyRectangle = new Rectangle(1, 2, { 3, 5 });
  Shape* polyCircle = new Circle(5.25, { 13, -12 });
  print(std::cout, *polyRectangle);
  print(std::cout, *polyCircle);

  delete polyRectangle;
  delete polyCircle;
  return 0;
}
