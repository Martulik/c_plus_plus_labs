#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include "data-struct.hpp"

namespace lab = borisova;

int main()
{
  using unInt = unsigned int;
  std::vector< lab::DataStruct > vector;
  lab::DataStruct value;
  std::string line;
  while (std::getline(std::cin, line) && !line.empty())
  {
    std::istringstream in(line);
    try
    {
      in >> value;
    }
    catch (const std::invalid_argument& ex)
    {
      std::cerr << ex.what() << "\n";
      return -1;
    }
    vector.push_back(value);
  }
  std::sort(vector.begin(), vector.end());
  for (unInt i = 0; i < vector.size(); i++)
  {
    std::cout << vector.at(i);
  }
  return 0;
}
