#include "task2.hpp"
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include "shape.hpp"

namespace lab = ezerinia;

void lab::task2(std::istream &in, std::ostream &out)
{
  if (!in) {
    throw std::runtime_error("Read fail");
  }
  std::vector< Shape > shapes((std::istream_iterator< Shape >(in)), std::istream_iterator< Shape >());
  std::sort(shapes.begin(), shapes.end());

  int vertices = std::accumulate(shapes.begin(), shapes.end(), 0,
                                 [](int vertices_, const Shape &shape) {
                                   return vertices_ + shape.size();
                                 });

  auto itTriangle = std::find_if(shapes.begin(), shapes.end(),
                                 [](const Shape &shape) {
                                   return shape.size() == 3;
                                 });
  auto itSquares = std::find_if(shapes.begin(), shapes.end(),
                                [](const Shape &shape) {
                                  return shape.size() == 4 && isSideEqual(shape);
                                });
  auto itRectangles = std::find_if(shapes.begin(), shapes.end(),
                                   [](const Shape &shape) {
                                     return shape.size() == 4 && !isSideEqual(shape);
                                   });
  auto itPentagons = std::find_if(shapes.begin(), shapes.end(),
                                  [](const Shape &shape) {
                                    return shape.size() == 5;
                                  });
  auto itHexagon = std::find_if(shapes.begin(), shapes.end(),
                                [](const Shape &shape) {
                                  return shape.size() == 6;
                                });
  int triangles = 0;
  if (itTriangle != shapes.end()) {
    triangles = itSquares - itTriangle;
  }
  int squares = 0;
  if (itSquares != shapes.end()) {
    squares = itRectangles - itSquares;
  }
  int rectangles = 0;
  if (itRectangles != shapes.end()) {
    rectangles = itPentagons - itSquares;
  }
  if (itPentagons != shapes.end()) {
    shapes.erase(itPentagons, itHexagon);
  }
  
  std::vector< Point > points;
  points.reserve(shapes.size());
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points),
                 [](const Shape &shape) {
                   return shape.front();
                 });

  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << triangles << "\n";
  out << "Squares: " << squares << "\n";
  out << "Rectangles: " << rectangles << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}
