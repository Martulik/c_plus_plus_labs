#include "tasks.hpp"

#include <fstream>
#include <list>
#include <memory>

#include "tools.hpp"

namespace lab = ezerinia;

int task1(const int sort_mode)
{
  std::vector< int > collection_numbers;
  int number = 0;
  while (std::cin && !(std::cin >> number).eof()) {
    if (std::cin.fail() || std::cin.bad()) {
      std::cerr << "Wrong input\n";
      return 1;
    }
    collection_numbers.push_back(number);
  }

  std::vector< int > index(collection_numbers);
  lab::do_sort< lab::indexVec< int > >(index, sort_mode);

  std::vector< int > at(collection_numbers);
  lab::do_sort< lab::atVec< int > >(at, sort_mode);

  std::list< int > iter(collection_numbers.begin(), collection_numbers.end());
  lab::do_sort< lab::iteratorList< int > >(iter, sort_mode);

  return 0;
}

int task2(const char *input)
{
  std::ifstream file;
  file.open(input);
  if (!file) {
    std::cerr << "File does not exist \n";
    return 1;
  }
  file.seekg(0, std::ios_base::end);
  file.clear();
  int length = file.tellg();
  file.seekg(0);

  if (!length) {
    return 0;
  }
  if (length == -1) {
    std::cerr << "Fail get length\n";
    return 1;
  }

  std::unique_ptr< char[] > array(new char[length]);
  int j = 0;
  while (j != length && !file.eof() && file) {
    file >> std::noskipws >> array[j];
    ++j;
  }
  if ((file.eof() && (j + 1 < length)) || (!file.eof() && (j + 1 == length))) {
    std::cerr << "File was changed\n";
    return 1;
  }
  file.close();

  std::vector< char > vec(&array[0], &array.get()[length]);

  for (int i = 0; i < length; i++) {
    std::cout << vec[i];
  }
  std::cout << "\n";
  return 0;
}

int task3()
{
  std::vector< int > vec;
  int n = 1;
  while (std::cin && !(std::cin >> n).eof()) {
    if (std::cin.fail() || std::cin.bad()) {
      std::cerr << "Error input\n";
      return 1;
    }
    if (n == 0) {
      break;
    }
    vec.push_back(n);
  }
  if (vec.empty()) {
    return 0;
  }
  if (n != 0) {
    std::cerr << "Zero not found\n";
    return 1;
  }
  if (!vec.empty()) {
    std::vector< int >::iterator iter = vec.begin();
    if (vec.back() == 1) {
      while (iter != vec.end()) {
        if (*iter % 2) {
          iter++;
        } else {
          vec.erase(iter);
        }
      }
    } else if (vec.back() == 2) {
      while (iter != vec.end()) {
        if (!(*iter % 3)) {
          iter = vec.insert(++iter, 3, 1);
          iter += 2;
        }
        iter++;
      }
    }
    lab::print(vec, std::cout);
  }
  return 0;
}

int task4(const int sort_mode, const int size)
{
  std::vector< double > vec(size);
  fillRandom(&vec[0], size);
  lab::print(vec, std::cout);
  lab::do_sort< lab::indexVec< double > >(vec, sort_mode);
  return 0;
}
