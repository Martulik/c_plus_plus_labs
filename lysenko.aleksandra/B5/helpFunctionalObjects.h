#ifndef HELP_FUNCTIONAL_OBJECTS_H
#define HELP_FUNCTIONAL_OBJECTS_H

#include <vector>
#include <functional>

#include "Shape.h"

namespace lysenko
{
  bool isTriangle(const Shape& obj);
  bool isRectangle(const Shape& obj);
  bool isSquare(const Shape& obj);

  struct getNumberOfVertices
  {
    size_t operator()(const lysenko::Shape& obj) const
    {
      return obj.size();
    }
  };

  void deletePentagons(std::vector< Shape >& vect, const lysenko::Shape& obj);

  struct addPoint
  {
    std::vector< Point > operator()(std::vector< Point >& firstPoitsofShapes, const Shape& obj)
    {
      firstPoitsofShapes.push_back(obj[0]);
      return firstPoitsofShapes;
    }
  };

 /* struct doSort
  {
    void operator()(std::vector< Shape >& myShp, const Shape& obj, bool (*sortType)(const Shape&))
    {
      if (sortType(obj))
      {
        myShp.push_back(obj);
      }
    }
  };*/
}

#endif
