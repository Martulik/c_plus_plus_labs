#include "functions.hpp"

#include <ctime>

bool pochernin::isAscending(const char* sortingDirection)
{
  if (sortingDirection == nullptr)
  {
    throw(std::invalid_argument("Incorrect sorting direction"));
  }
  if (!strcmp(sortingDirection, "ascending"))
  {
    return true;
  }
  else if (!strcmp(sortingDirection, "descending"))
  {
    return false;
  }
  else
  {
    throw(std::invalid_argument("Incorrect sorting direction"));
  }
}

void pochernin::fillRandom(double* array, int size)
{
  if (size <= 0)
  {
    throw(std::invalid_argument("Incorrect array size"));
  }
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    array[i] = (static_cast< double >(rand()) / RAND_MAX) * 2 - 1;
  }
}
