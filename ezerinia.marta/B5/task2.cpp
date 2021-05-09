#include "task2.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

#include "shape.hpp"

void ezerinia::task2()
{
  if (!std::cin) {
    throw std::runtime_error("Read fail");
  }
  std::vector< Shape > shapes((std::istream_iterator< Shape >(std::cin)), std::istream_iterator< Shape >());
  int vertices = 0;
  int triangles = 0;
  int squares = 0;
  int rectangles = 0;

  std::vector< Point > points;
//  for (auto && shape : shapes) {
  for (auto & shape : shapes) {
    vertices += shape.size();
    if (shape.size() == 3) {
      triangles++;
    } else if (shape.size() == 4) {
      rectangles++;
      if (isSideEqual(shape)) {
        squares++;
      }
    }
    if (shape.size() != 5) {
      points.push_back(shape.front());
    }
  }

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
                              [](const Shape &shape) {
                                return shape.size() == 5;
                              }), shapes.end());

  std::sort(shapes.begin(), shapes.end(), compare);
  std::cout << "Vertices: " << vertices << "\n";
  std::cout << "Triangles: " << triangles << "\n";
  std::cout << "Squares: " << squares << "\n";
  std::cout << "Rectangles: " << rectangles << "\n";
  std::cout << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(std::cout, "\n"));
  std::cout << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(std::cout, "\n"));
}
