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

  int vertices = std::accumulate(shapes.begin(), shapes.end(), 0,
                                 [](int vertices_, const Shape &shape) {
                                   return vertices_ + shape.size();
                                 });

//  auto itPentagons = std::find_if(shapes.begin(), shapes.end(),
//                                  [](const Shape &shape) {
//                                    return shape.size() == 5;
//                                  });
//  auto firstNotPentagon = std::find_if(std::next(itPentagons), shapes.end(),
//                                       [](const Shape &shape) {
//                                         return shape.size() != 5;
//                                       });

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(),
                              [](const Shape &shape) {
                                return shape.size() == 5;
                              }), shapes.end());
  std::vector< Point > points;
  points.reserve(shapes.size());
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points),
                 [](const Shape &shape) {
                   return shape.front();
                 });
  std::sort(shapes.begin(), shapes.end());
  auto itMoreThenPentagons = std::find_if(shapes.begin(), shapes.end(),
                                          [](const Shape &shape) {
                                            return shape.size() > 5;
                                          });
  auto itRectangles = std::find_if(shapes.begin(), itMoreThenPentagons,
                                   [](const Shape &shape) {
                                     return shape.size() == 4 && !isSideEqual(shape);
                                   });
  auto itSquares = std::find_if(shapes.begin(), itRectangles,
                                [](const Shape &shape) {
                                  return shape.size() == 4 && isSideEqual(shape);
                                });
  auto itTriangle = std::find_if(shapes.begin(), itSquares,
                                 [](const Shape &shape) {
                                   return shape.size() == 3;
                                 });

  int triangles = 0;
  if (itTriangle != shapes.end()) {
    if (itSquares != shapes.end()) {
      triangles = itSquares - itTriangle;
    } else {
      auto firstNotTriangle = std::find_if(itTriangle, shapes.end(),
                                           [](const Shape &shape) {
                                             return shape.size() != 3;
                                           });
      triangles = firstNotTriangle - itTriangle;
    }
  }
  int squares = 0;
  if (itSquares != shapes.end()) {
    if (itRectangles != shapes.end()) {
      squares = itRectangles - itSquares;
    } else {
      auto firstNotSquare = std::find_if(std::next(itSquares), shapes.end(),
                                         [](const Shape &shape) {
                                           return shape.size() != 4;
                                         });
      squares = firstNotSquare - itSquares;
    }
  }
  int rectangles = squares;
  if (itRectangles != shapes.end()) {
    if (itMoreThenPentagons != shapes.end()) {
      rectangles += itMoreThenPentagons - itRectangles;
    } else {
      auto firstNotRectangle = std::find_if(std::next(itRectangles), shapes.end(),
                                            [](const Shape &shape) {
                                              return shape.size() != 4;
                                            });
      rectangles += firstNotRectangle - itRectangles;
    }
  }

//  if (itPentagons != shapes.end()) {
//    shapes.erase(itPentagons, firstNotPentagon);
//  }



  out << "Vertices: " << vertices << "\n"
      << "Triangles: " << triangles << "\n"
      << "Squares: " << squares << "\n"
      << "Rectangles: " << rectangles << "\n"
      << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< Shape >(out, "\n"));
}
