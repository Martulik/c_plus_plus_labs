#include "helpFunctionalObjects.h"

#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

namespace lysenko
{
  static int getDeltaFromFirstPoint(bool abscissa, const lysenko::Shape& obj, size_t pointNumber)
  {
    if (pointNumber < obj.size())
    {
      if (abscissa)
      {
        return obj[pointNumber].x - obj[0].x;
      }
      return obj[pointNumber].y - obj[0].y;
    }
    throw std::out_of_range("Invalid parameters");
  }

  static double getDistanceFromFirstPoint(const lysenko::Shape& obj, int pointNumber)
  {
    return std::sqrt(pow(getDeltaFromFirstPoint(0, obj, pointNumber), 2) + pow(getDeltaFromFirstPoint(1, obj, pointNumber), 2));
  }

  static std::vector< double > getSortedVectOfDistancesFromFirstPoint(const lysenko::Shape& obj)
  {
    double distance01 = getDistanceFromFirstPoint(obj, 1);
    double distance02 = getDistanceFromFirstPoint(obj, 2);
    double distance03 = getDistanceFromFirstPoint(obj, 3);

    std::vector< double > distances{ distance01, distance02, distance03 };
    std::sort(distances.begin(), distances.end());

    return distances;
  }
}

bool lysenko::isTriangle(const lysenko::Shape& obj)
{
  return  (obj.size() == 3);
}

bool lysenko::isRectangle(const lysenko::Shape& obj)
{
  if (obj.size() == 4)
  {
    if ((obj[0] == obj[1]) && (obj[0] == obj[2]) && (obj[0] == obj[3]))
    {
      return 1;
    }

    std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);

    return (distances[2] == std::sqrt(std::pow(distances[0], 2) + std::pow(distances[1], 2)));
  }
  return 0;
}

bool lysenko::isSquare(const lysenko::Shape& obj)
{
  if (isRectangle(obj))
  {
    std::vector< double > distances = getSortedVectOfDistancesFromFirstPoint(obj);

    return (distances[0] == distances[1]);
  }
  return 0;
}

bool lysenko::isNotTriangleOrSquareOrRectangle(const Shape& obj)
{
  return (!((isTriangle(obj)) || (isRectangle(obj)) || (isSquare(obj))));
}

void lysenko::shapeSort(std::vector< Shape >& vect)
{
  std::vector< Shape > sortedOne(vect);
  std::vector< Shape >::iterator typicalShape = std::remove_if(sortedOne.begin(), sortedOne.end(), isNotTriangleOrSquareOrRectangle);
  sortedOne.erase(typicalShape, sortedOne.end());
  int numbOfTriSqAndRect = sortedOne.size();

  std::sort(sortedOne.begin(), sortedOne.end());
  sortedOne.resize(vect.size());

  auto addIfTypical = std::bind(addTypicalShapes, sortedOne.begin(), sortedOne.end(), numbOfTriSqAndRect, std::placeholders::_1);
  std::for_each(vect.begin(), vect.end(), addIfTypical);
  std::swap(sortedOne, vect);
}

void lysenko::addTypicalShapes(std::vector< Shape >::iterator& begin, std::vector< Shape >::iterator& end, int numb, const Shape& obj)
{
  static int number = numb;
  if (isNotTriangleOrSquareOrRectangle(obj))
  {
    std::vector< Shape >::iterator iterFind = std::find(begin, end, obj);
    if (iterFind == end)
    {
      *(begin + number) = obj;
      number++;
    }
  }
}
