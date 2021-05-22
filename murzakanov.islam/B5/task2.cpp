#include "tasks.hpp"

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>

#include "tools.hpp"
#include "shape.hpp"

size_t returnSize(const murzakanov::Shape shp)
{
  return shp.size();
}

int murzakanov::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< murzakanov::Shape > firstIterator(in);
  std::istream_iterator< murzakanov::Shape > lastIterator;
  if (in.fail())
  {
    std::cerr << "Invalid input\n";
    return 1;
  }
  std::vector< murzakanov::Shape > shapes(firstIterator, lastIterator);
  if (shapes.size() == 0)
  {
    return 0;
  }
  int vertices = murzakanov::calculateVertices(shapes);
  int rectangles = std::count_if(shapes.begin(), shapes.end(), murzakanov::isSquare) + std::count_if(shapes.begin(), shapes.end(), murzakanov::isRectangle);
  int squares = std::count_if(shapes.begin(), shapes.end(), murzakanov::isSquare);
  int triangles = std::count_if(shapes.begin(), shapes.end(), murzakanov::isTriangle);
  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), murzakanov::isPentagon), shapes.end());
  std::vector< murzakanov::Point > points;
  for (size_t i = 0; i < shapes.size(); i++)
  {
    points.push_back(shapes[i][0]);
  }
  std::sort(shapes.begin(), shapes.end());
  out << "Vertices: " << vertices << "\n";
  out << "Triangles: " << triangles << "\n";
  out << "Squares: " << squares << "\n";
  out << "Rectangles: " << rectangles << "\n";
  out << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator< murzakanov::Point >(out, " "));
  out << "\n";
  out << "Shapes:" << "\n";
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator< murzakanov::Shape >(out, "\n"));
  return 0;
}
