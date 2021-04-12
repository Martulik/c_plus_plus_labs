#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>
#include <string.h>

namespace pochernin
{
  template < typename Container >
  void print (const Container& container)
  {
    using Iterator = typename Container::const_iterator;

    Iterator end = container.end();
    for (Iterator current = container.begin(); current != end; current++)
    {
      std::cout << *current << " ";
    }
    std::cout << "\n";
  }

  template < typename Access >
  void sort(typename Access::Container& container, const char* sortingDirection)
  {
    if (sortingDirection == nullptr)
    {
      throw(std::invalid_argument("Incorrect sorting direction"));
    }
    bool isAscending = true;
    if (!strcmp(sortingDirection, "ascending"))
    {
      isAscending = true;
    }
    else if (!strcmp(sortingDirection, "descending"))
    {
      isAscending = false;
    }
    else
    {
      throw(std::invalid_argument("Incorrect sorting direction"));
    }

    typename Access::Iterator begin = Access::begin(container);
    typename Access::Iterator end = Access::end(container);
    for (typename Access::Iterator i = begin; i != end; i++)
    {
      typename Access::ItemType critical = Access::get(container, i);
      typename Access::Iterator criticalIterator = i;
      for (typename Access::Iterator j = i; j != end; j++)
      {
        typename Access::ItemType x = Access::get(container, j);
        if ((isAscending && (x < critical)) || (!isAscending && (x > critical)))
        {
          critical = x;
          criticalIterator = j;
        }
      }
      std::swap(Access::get(container, i), Access::get(container, criticalIterator));
    }
  }
}

#endif
