#include "tools.hpp"

#include <random>
#include <ctime>

void murzakanov::fillRandom(double* array, int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    array[i] = double(rand()) / RAND_MAX * 2 - 1;
  }
}

bool murzakanov::checkIsNumber(std::string& str)
{
  for (int i = 0; i < int(str.length()); i++)
  {
    if (str[i] < '0' || str[i] > '9')
    {
      return false;
    }
  }
  return true;
}

bool murzakanov::checkForSpaces(std::string& str)
{
  if ((str.find(' ') != std::string::npos))
  {
    return true;
  }
  return false;
}
