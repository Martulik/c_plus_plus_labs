#include <forward_list>
#include <fstream>
#include <functional>
#include <iostream>

#include <vector>

#include "tasks.hpp"
#include "functions.hpp"

void task1(std::function<bool(const int&, const int&)> comparator)
{
  std::vector<int> vector;
  int element = 0;
  while (std::cin >> element)
  {
    vector.push_back(element);
  }
  if (!std::cin.eof())
  {
    throw std::runtime_error("Incorrect input");
  }
  if (vector.empty())
  {
    return;
  }
  std::vector<int> vector1 = vector;
  std::forward_list<int> list(vector.begin(), vector.end());
  sort<Brackets>(vector, comparator);
  sort<Iterator>(list, comparator);
  sort<At>(vector1, comparator);
  print(vector, " ");
  std::cout << std::endl;
  print(vector1, " ");
  std::cout << std::endl;
  print(list, " ");
}
